/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkDrawDescription.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "vkDevice.h"
#include "vkManager.h"
#include "vkResourceManager.h"
#include "vkCmdBufferManager.h"
#include "vkStageIO.h"
#include "vkRenderPass.h"
#include "vkRenderManager.h"
#include "vkDrawDescription.h"



namespace vulkan
{

	vk::Result DrawDescription::initialize()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getStage()->getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData.push_back(DrawSwapchainData());
		}

		pInitDescriptorSetLayout();
		pInitPipelineLayout();
		pInitShaderModules();
		pInitPipeline();
		pInitDescriptorSets();
		pInitIndirectDrawCmdInfo();
		pInitCommandBuffer();

		return vkResult;
	}


	vk::Result DrawDescription::updateIndirectDrawCommand(uint32_t swapchainIdx, void* inputData, uint32_t dataSize)
	{
		auto vkResult = vk::Result::eSuccess;

		assert(dataSize == 3 * sizeof(uint32_t));

		uint32_t* dataInput = static_cast<uint32_t*>(inputData);
		uint32_t indexCount = dataInput[0];
		uint32_t indexFirst = dataInput[1];
		uint32_t vertexOffset = dataInput[2];

		if (isIndexedDraw())
		{
			auto drawInfoIndirect = vk::DrawIndexedIndirectCommand()
				.setIndexCount(indexCount)
				.setFirstIndex(indexFirst)
				.setInstanceCount(1)
				.setFirstInstance(0)
				.setVertexOffset(vertexOffset);
			vkResult = getStage()->getManager().getResourceManager().loadBufferData(p_swapchainData[swapchainIdx].drawCmdIndirectInfo->datawrite(), static_cast< void* >(&drawInfoIndirect), sizeof(vk::DrawIndexedIndirectCommand));
		}
		else
		{
			assert(0); // not supported yet			
			uint32_t vertexCount = 0;
			auto drawInfoStruct = vk::DrawIndirectCommand()
				.setFirstVertex(0)
				.setVertexCount(vertexCount)
				.setFirstInstance(0)
				.setInstanceCount(1);
			vkResult = getStage()->getManager().getResourceManager().loadBufferData(p_swapchainData[swapchainIdx].drawCmdIndirectInfo->datawrite(), static_cast< void* >(&drawInfoStruct), sizeof(vk::DrawIndirectCommand));
		}

		return vkResult;
	}

	
	vk::Result DrawDescription::pInitDescriptorSetLayout()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getStage()->getManager().getRenderManager().getStageDescription(getStage()->getType());
		auto & drawDescriptions = stageDescription.getDescriptions<device::DataDescription::eDraw>()[p_drawTag];
		auto & layoutBindingsInfo = drawDescriptions.getLayoutBindings();

		std::vector< vk::DescriptorSetLayoutBinding > layoutBindings;
		for (auto &pBinding : layoutBindingsInfo)
		{
			auto bindingIdx = pBinding.first;
			auto &bindingDescription = pBinding.second;

			layoutBindings.push_back(
				vk::DescriptorSetLayoutBinding()
				.setBinding(bindingIdx)
				.setDescriptorType(utils::GET_VKDESCRIPTOR_FROM_DATADESCRIPTOR(bindingDescription.getDataDescription()))
				.setDescriptorCount(bindingDescription.getDataTags().size())
				.setStageFlags(utils::GET_VKSTAGE_FROM_SHADERSTAGE(bindingDescription.getShaderStage()))
				.setPImmutableSamplers(nullptr)
			);
		}

		auto const descLayoutCreateInfo = vk::DescriptorSetLayoutCreateInfo()
			.setBindingCount(layoutBindings.size())
			.setPBindings(layoutBindings.data());

		vkResult = getStage()->getManager().getGraphicsDevice().getLogicalDevice().createDescriptorSetLayout(&descLayoutCreateInfo, nullptr, &p_descLayout);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::Result DrawDescription::pInitPipelineLayout()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const pipelineLayoutCreateInfo = vk::PipelineLayoutCreateInfo()
			.setSetLayoutCount(1)
			.setPSetLayouts(&p_descLayout);

		vkResult = getStage()->getManager().getGraphicsDevice().getLogicalDevice().createPipelineLayout(&pipelineLayoutCreateInfo, nullptr, &p_pipelineLayout);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::Result DrawDescription::pInitShaderModules()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getStage()->getManager().getRenderManager().getStageDescription(getStage()->getType());
		auto & drawDescriptions = stageDescription.getDescriptions<device::DataDescription::eDraw>()[p_drawTag];
		auto shaderDescription = drawDescriptions.getShaderDescription();
		auto shaders = shaderDescription.getShaders();

		vkResult = pCreateShaderModule((shaders[graphics::ShaderStage::eVertex]).c_str(), &p_shaderData[graphics::ShaderStage::eVertex]);
		assert(vkResult == vk::Result::eSuccess);

		vkResult = pCreateShaderModule(shaders[graphics::ShaderStage::eFragment].c_str(), &p_shaderData[graphics::ShaderStage::eFragment]);
		assert(vkResult == vk::Result::eSuccess);

		DEBUG_markObject(debug::getShaderModuleRef(p_shaderData[graphics::ShaderStage::eVertex]), "vert shader", vk::DebugReportObjectTypeEXT::eShaderModule, debug::getDeviceRef(getStage()->getManager().getGraphicsDevice().getLogicalDevice()));
		DEBUG_markObject(debug::getShaderModuleRef(p_shaderData[graphics::ShaderStage::eFragment]), "frag shader", vk::DebugReportObjectTypeEXT::eShaderModule, debug::getDeviceRef(getStage()->getManager().getGraphicsDevice().getLogicalDevice()));

		return vkResult;
	}


	vk::Result DrawDescription::pInitPipeline()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getStage()->getManager().getRenderManager().getStageDescription(getStage()->getType());
		auto & drawDescriptions = stageDescription.getDescriptions<device::DataDescription::eDraw>()[p_drawTag];

		auto vertexTag = drawDescriptions.getVertexTag();
		auto indexTag = drawDescriptions.getIndexTag();
		auto* vertexData = getStage()->getData<device::DataDescription::eVertex>(vertexTag, 0);

		auto const vertexInputInfo = pGetPipelineVertexInputStateCreateInfo(vertexData);
		auto const colorBlendCreateInfo = pGetPipelineColorBlendStateCreateInfo();
		auto const dynamicStateCreateInfo = pGetPipelineDynamicStateCreateInfo();
		auto const inputAssemblyCreateInfo = pGetPipelineInputAssemblyStateCreateInfo();

		/* todo - currently, these structures are default initialized, make them customizable and pipeline specific */
		auto const viewportCreateInfo = pGetPipelineViewportStateCreateInfo();
		auto const rasterizationCreateInfo = pGetPipelineRasterizationStateCreateInfo();
		auto const multisampleCreateInfo = pGetPipelineMultisampleStateCreateInfo();
		auto const depthStencilCreateInfo = pGetPipelineDepthStencilStateCreateInfo();


		vk::PipelineCacheCreateInfo const pipelineCacheInfo;
		vkResult = getStage()->getManager().getGraphicsDevice().getLogicalDevice().createPipelineCache(&pipelineCacheInfo, nullptr, &p_pipelineCache);
		assert(vkResult == vk::Result::eSuccess);

		std::vector< vk::PipelineShaderStageCreateInfo > shaderStages = {
			pGetShaderStageCreateInfo(graphics::ShaderStage::eVertex),
			pGetShaderStageCreateInfo(graphics::ShaderStage::eFragment)
		};

		auto const pipelineCreateInfo = vk::GraphicsPipelineCreateInfo()
			.setStageCount(shaderStages.size())
			.setPStages(shaderStages.data())
			.setPVertexInputState(&vertexInputInfo)
			.setPInputAssemblyState(&inputAssemblyCreateInfo)
			.setPViewportState(&viewportCreateInfo)
			.setPRasterizationState(&rasterizationCreateInfo)
			.setPMultisampleState(&multisampleCreateInfo)
			.setPDepthStencilState(&depthStencilCreateInfo)
			.setPColorBlendState(&colorBlendCreateInfo)
			.setPDynamicState(&dynamicStateCreateInfo)
			.setLayout(p_pipelineLayout)
			.setRenderPass(getStage()->getRenderPass());

		vkResult = getStage()->getManager().getGraphicsDevice().getLogicalDevice().createGraphicsPipelines(p_pipelineCache, 1, &pipelineCreateInfo, nullptr, &p_pipeline);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::Result DrawDescription::pInitDescriptorSets()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getStage()->getManager().getRenderManager().getSwapchainImageCount();

		graphics::StageDescription & stageDescription = getStage()->getManager().getRenderManager().getStageDescription(getStage()->getType());
		auto & drawDescriptions = stageDescription.getDescriptions<device::DataDescription::eDraw>()[p_drawTag];
		auto layoutBindings = drawDescriptions.getLayoutBindings();

		for (auto i = 0; i < swapchainCount; ++i)
		{
			vkResult = getStage()->getManager().getResourceManager().allocateDescriptorSet(&p_descLayout, &p_swapchainData[i].descriptorSet);
			for (auto &pBinding : layoutBindings)
			{
				auto bindingIdx = pBinding.first;
				auto &bindingDescription = pBinding.second;

				switch (bindingDescription.getDataDescription())
				{
				case device::DataDescription::eUniform: pUpdateBufferDescriptorSet(i, bindingIdx, bindingDescription);
					break;
				case device::DataDescription::eTexture: pUpdateImageDescriptorSet(i, bindingIdx, bindingDescription);
					break;
				default:assert(0);
				}
			}
		}

		return vkResult;
	}


	vk::Result DrawDescription::pUpdateBufferDescriptorSet(uint32_t swapchainIdx, uint32_t bindingIdx, graphics::StageLayoutBindingDescription & description)
	{
		auto vkResult = vk::Result::eSuccess;

		auto &dataTags = description.getDataTags();
		std::vector< vk::WriteDescriptorSet > writes;

		for (auto &pDataTag : dataTags)
		{
			auto* uniformData = getStage()->getData<device::DataDescription::eUniform>(pDataTag, swapchainIdx);
			vk::DescriptorBufferInfo info = uniformData->getDescriptorBufferInfo();
			writes.push_back(
				vk::WriteDescriptorSet()
				.setDstBinding(bindingIdx)
				.setDescriptorCount(1)
				.setDescriptorType(utils::GET_VKDESCRIPTOR_FROM_DATADESCRIPTOR(description.getDataDescription()))
				.setPBufferInfo(&info)
				.setDstSet(p_swapchainData[swapchainIdx].descriptorSet)
			);
		}		

		getStage()->getManager().getGraphicsDevice().getLogicalDevice().updateDescriptorSets(writes.size(), writes.data(), 0, nullptr);

		return vkResult;
	}


	vk::Result DrawDescription::pUpdateImageDescriptorSet(uint32_t swapchainIdx, uint32_t bindingIdx, graphics::StageLayoutBindingDescription & description)
	{
		auto vkResult = vk::Result::eSuccess;

		auto &dataTags = description.getDataTags();
		std::vector< vk::WriteDescriptorSet > writes;

		for (auto &pDataTag : dataTags)
		{
			auto* textureData = getStage()->getData<device::DataDescription::eTexture>(pDataTag);
			vk::DescriptorImageInfo info = textureData->getDescriptorImageInfo();
			writes.push_back(
				vk::WriteDescriptorSet()
				.setDstBinding(bindingIdx)
				.setDescriptorCount(1)
				.setDescriptorType(utils::GET_VKDESCRIPTOR_FROM_DATADESCRIPTOR(description.getDataDescription()))
				.setPImageInfo(&info)
				.setDstSet(p_swapchainData[swapchainIdx].descriptorSet)
			);
		}

		getStage()->getManager().getGraphicsDevice().getLogicalDevice().updateDescriptorSets(writes.size(), writes.data(), 0, nullptr);

		return vkResult;
	}


	vk::Result DrawDescription::pInitIndirectDrawCmdInfo()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getStage()->getManager().getRenderManager().getSwapchainImageCount();
		for (uint32_t i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i].drawCmdIndirectInfo = std::make_unique< DrawCmdIndirectInfo >("indirectdrawinfo", i);
			p_swapchainData[i].drawCmdIndirectInfo->isIndexed = isIndexedDraw();
			vkResult = getStage()->getManager().getResourceManager().allocateIndirectDrawCmd(p_swapchainData[i].drawCmdIndirectInfo.get());
		}

		return vkResult;
	}


	vk::Result DrawDescription::pInitCommandBuffer()
	{
		auto vkResult = vk::Result::eSuccess;

		auto frameWidth = getStage()->getManager().getAppManager()->getFrameWidth();
		auto frameHeight = getStage()->getManager().getAppManager()->getFrameHeight();

		graphics::StageDescription & stageDescription = getStage()->getManager().getRenderManager().getStageDescription(getStage()->getType());
		auto & drawDescriptions = stageDescription.getDescriptions<device::DataDescription::eDraw>()[p_drawTag];
		auto vertexTag = drawDescriptions.getVertexTag();
		auto indexTag = drawDescriptions.getIndexTag();

		auto swapchainCount = getStage()->getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			if (p_swapchainData[i].commandBuffer)
			{
				getStage()->getManager().getCommandManager().FreeSecondaryCmdBuffer(&p_swapchainData[i].commandBuffer);
			}

			getStage()->getManager().getCommandManager().AllocateSecondaryCmdBuffer(&p_swapchainData[i].commandBuffer);

			auto const inherintanceInfo = vk::CommandBufferInheritanceInfo()
				.setRenderPass(getStage()->getRenderPass())
				.setFramebuffer(getStage()->getFramebuffer(i))
				.setSubpass(0);

			auto const cmdBufBeginInfo = vk::CommandBufferBeginInfo()
				.setFlags(vk::CommandBufferUsageFlagBits::eRenderPassContinue)
				.setPInheritanceInfo(&inherintanceInfo);

			p_swapchainData[i].commandBuffer.begin(cmdBufBeginInfo);

			p_swapchainData[i].commandBuffer.bindPipeline(vk::PipelineBindPoint::eGraphics, p_pipeline);
			p_swapchainData[i].commandBuffer.bindDescriptorSets(vk::PipelineBindPoint::eGraphics, p_pipelineLayout, 0, 1, &p_swapchainData[i].descriptorSet, 0, nullptr);

			auto* vertexData = getStage()->getData<device::DataDescription::eVertex>(vertexTag, i);
			auto* indexData = getStage()->getData<device::DataDescription::eIndex>(indexTag, i);
			vk::DeviceSize offsets[1] = { vertexData->data()->getBufferOffset() };

			p_swapchainData[i].commandBuffer.bindVertexBuffers(0, 1, &vertexData->data()->getBuffer(), offsets);
			p_swapchainData[i].commandBuffer.bindIndexBuffer(indexData->data()->getBuffer(), 0, indexData->getIndexType());

			auto const primaryViewport = vk::Viewport()
				.setWidth((float)frameWidth)
				.setHeight((float)frameHeight)
				.setMinDepth((float)0.0f)
				.setMaxDepth((float)1.0f);
			p_swapchainData[i].commandBuffer.setViewport(0, 1, &primaryViewport);

			vk::Rect2D const scissor = vk::Rect2D(vk::Offset2D(0, 0), vk::Extent2D(frameWidth, frameHeight));
			p_swapchainData[i].commandBuffer.setScissor(0, 1, &scissor);

			uint32_t offset = 0, drawCount = 1, stride = 0;
			p_swapchainData[i].commandBuffer.drawIndexedIndirect(p_swapchainData[i].drawCmdIndirectInfo->data()->getBuffer(), p_swapchainData[i].drawCmdIndirectInfo->data()->getBufferOffset(), drawCount, stride);

			// p_swapchainData[i].commandBuffer.draw(3, 1, 0, 0); // DEBUG

			p_swapchainData[i].commandBuffer.end();
		}


		return vkResult;
	}


	vk::Result DrawDescription::pCreateShaderModule(char const *shaderFile, vk::ShaderModule *shaderModule)
	{
		std::ifstream fileStream(shaderFile, std::ios::ate | std::ios::binary);

		if (!fileStream.is_open())
		{
			throw std::runtime_error("Failure During Loading Shader File - " + std::string(shaderFile));
		}

		size_t fileSize = (size_t)fileStream.tellg();
		std::vector< char > shaderCode(fileSize);
		fileStream.seekg(0);
		fileStream.read(shaderCode.data(), fileSize);
		fileStream.close();

		auto const moduleCreateInfo = vk::ShaderModuleCreateInfo()
			.setCodeSize(fileSize)
			.setPCode(reinterpret_cast< uint32_t const * >(shaderCode.data()));

		auto vkResult = getStage()->getManager().getGraphicsDevice().getLogicalDevice().createShaderModule(&moduleCreateInfo, nullptr, shaderModule);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::PipelineInputAssemblyStateCreateInfo DrawDescription::pGetPipelineInputAssemblyStateCreateInfo()
	{
		return vk::PipelineInputAssemblyStateCreateInfo()
			.setTopology(vk::PrimitiveTopology::eTriangleList);
	}


	vk::PipelineVertexInputStateCreateInfo DrawDescription::pGetPipelineVertexInputStateCreateInfo(VertexData const* vertexData)
	{
		uint32_t bindingIdx = 0;

		p_pipelineData.vertexInputBindingDesc.push_back(vertexData->getVertexInputBindingDescription(bindingIdx));
		vertexData->getVertexInputAttributeDescription(bindingIdx, p_pipelineData.vertexInputAttributeDesc);

		return vk::PipelineVertexInputStateCreateInfo()
			.setVertexBindingDescriptionCount(p_pipelineData.vertexInputBindingDesc.size())
			.setPVertexBindingDescriptions(p_pipelineData.vertexInputBindingDesc.data())
			.setVertexAttributeDescriptionCount(p_pipelineData.vertexInputAttributeDesc.size())
			.setPVertexAttributeDescriptions(p_pipelineData.vertexInputAttributeDesc.data());
	}


	vk::PipelineColorBlendStateCreateInfo DrawDescription::pGetPipelineColorBlendStateCreateInfo()
	{
		p_pipelineData.pipelineColorBlendAttachmentStates.push_back(
			vk::PipelineColorBlendAttachmentState()
			.setColorWriteMask(
				vk::ColorComponentFlagBits::eR |
				vk::ColorComponentFlagBits::eG |
				vk::ColorComponentFlagBits::eB |
				vk::ColorComponentFlagBits::eA
			)
			.setSrcColorBlendFactor(vk::BlendFactor::eSrcAlpha)
			.setDstColorBlendFactor(vk::BlendFactor::eOneMinusSrcAlpha)
			.setColorBlendOp(vk::BlendOp::eAdd)
			.setSrcAlphaBlendFactor(vk::BlendFactor::eOne)
			.setDstAlphaBlendFactor(vk::BlendFactor::eZero)
			.setAlphaBlendOp(vk::BlendOp::eAdd)
			.setBlendEnable(VK_TRUE)
		);

		return vk::PipelineColorBlendStateCreateInfo()
			.setAttachmentCount(p_pipelineData.pipelineColorBlendAttachmentStates.size())
			.setPAttachments(p_pipelineData.pipelineColorBlendAttachmentStates.data());
	}


	vk::PipelineDynamicStateCreateInfo DrawDescription::pGetPipelineDynamicStateCreateInfo()
	{
		p_pipelineData.dynamicStates = {
			vk::DynamicState::eViewport,
			vk::DynamicState::eScissor,
			vk::DynamicState::eLineWidth
		};

		return vk::PipelineDynamicStateCreateInfo()
			.setPDynamicStates(p_pipelineData.dynamicStates.data())
			.setDynamicStateCount(p_pipelineData.dynamicStates.size());
	}


	vk::PipelineShaderStageCreateInfo DrawDescription::pGetShaderStageCreateInfo(graphics::ShaderStage stage)
	{
		return vk::PipelineShaderStageCreateInfo()
			.setStage(utils::GET_VKSTAGE_FROM_SHADERSTAGE(stage))
			.setModule(p_shaderData[stage])
			.setPName("main");
	}




	vk::PipelineViewportStateCreateInfo DrawDescription::pGetPipelineViewportStateCreateInfo()
	{
		return vk::PipelineViewportStateCreateInfo()
			.setViewportCount(1)
			.setScissorCount(1);
	}


	vk::PipelineRasterizationStateCreateInfo DrawDescription::pGetPipelineRasterizationStateCreateInfo()
	{
		return vk::PipelineRasterizationStateCreateInfo()
			.setDepthClampEnable(VK_FALSE)
			.setRasterizerDiscardEnable(VK_FALSE)
			.setPolygonMode(vk::PolygonMode::eFill)
			.setCullMode(vk::CullModeFlagBits::eNone)
			.setFrontFace(vk::FrontFace::eCounterClockwise)
			.setDepthBiasEnable(VK_FALSE)
			.setLineWidth(1.0f);
	}


	vk::PipelineMultisampleStateCreateInfo DrawDescription::pGetPipelineMultisampleStateCreateInfo()
	{
		return vk::PipelineMultisampleStateCreateInfo();
	}


	vk::PipelineDepthStencilStateCreateInfo DrawDescription::pGetPipelineDepthStencilStateCreateInfo()
	{
		auto const stencilOp = vk::StencilOpState()
			.setFailOp(vk::StencilOp::eKeep)
			.setPassOp(vk::StencilOp::eKeep)
			.setCompareOp(vk::CompareOp::eAlways);

		return vk::PipelineDepthStencilStateCreateInfo()
			.setDepthTestEnable(VK_TRUE)
			.setDepthWriteEnable(VK_TRUE)
			.setDepthCompareOp(vk::CompareOp::eLessOrEqual)
			.setDepthBoundsTestEnable(VK_FALSE)
			.setStencilTestEnable(VK_FALSE)
			.setFront(stencilOp)
			.setBack(stencilOp);
	}

} // end namespace vulkan