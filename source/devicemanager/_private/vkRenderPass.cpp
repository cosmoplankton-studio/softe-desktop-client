/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkRenderPass.cpp
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

	/*
	*************************************
	class RenderPassBase
	*************************************
	*/
	RenderPassHandle RenderPassBase::createRenderPass(Manager *mgr, RenderPassBase *prev, graphics::StageType passType)
	{
		switch (passType)
		{
		case graphics::StageType::eUI:
			return std::make_shared<RenderPassUI>(mgr, passType, prev);
		case graphics::StageType::eMultiMaterial:
			return std::make_shared<RenderPassMultiMaterial>(mgr, passType, prev);
		case graphics::StageType::eWireframe:
			return std::make_shared<RenderPassWireframe>(mgr, passType, prev);
		case graphics::StageType::eOffScreen:
			return std::make_shared<RenderPassOffscreen>(mgr, passType, prev);
		case graphics::StageType::eOffScreenConsume:
			return std::make_shared<RenderPassOffscreenConsume>(mgr, passType, prev);
		default:
			assert(0);
		}
		return nullptr;
	}


	RenderPassBase::RenderPassBase(Manager* mgr, graphics::StageType passType)
		: p_manager(mgr)
		, p_stageType(passType)
		, p_prevPass(nullptr)
		, p_nextPass(nullptr)
	{}


	RenderPassBase::RenderPassBase(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
		: p_manager(mgr)
		, p_stageType(passType)
		, p_prevPass(prev)
		, p_nextPass(nullptr)
	{
		if (prev) prev->SetNext(this);
	}

	
	RenderPassBase::~RenderPassBase()
	{

	}

	
	Manager &RenderPassBase::getManager()
	{
		return *p_manager;
	}

	/*
	********************************************************
	* Template Specilizations of PROTECTED METHODS - START
	********************************************************
	*/
	template<>
	vk::Result RenderPassBase::pInitData<device::DataDescription::eRenderTarget>()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto & renderTargetDescriptions = stageDescription.getDescriptions<device::DataDescription::eRenderTarget>();

		for (auto &pRenderTargetDescription : renderTargetDescriptions)
		{
			switch (pRenderTargetDescription.second.getTargetType())
			{
			case graphics::RenderTargetType::ePresent:
				vkResult = pCreatePresentFramebufferAttachments();
				break;
				// case RenderTargetType::eOffScreen:
				//	vkResult = pCreateOffscreenFramebufferAttachments(pRenderTargetDescription); // todo
			default:VERIFY(0);
			}
		}

		return vkResult;
	}

	template<>
	vk::Result RenderPassBase::pInitData<device::DataDescription::eDraw>()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto const& drawDescritions = stageDescription.getDescriptions<device::DataDescription::eDraw>();

		for (auto &pDescription : drawDescritions)
		{
			auto& drawTag = pDescription.first;
			p_drawDescriptions[drawTag] = std::make_shared< DrawDescription >(this, drawTag);
			p_drawDescriptions[drawTag]->initialize();
			pCreateDataSlot<device::DataDescription::eDraw>(pDescription.second);
		}

		return vkResult;
	}

	template<>
	vk::Result RenderPassBase::pinitDataAlias<ResourceBuffer>(DataAliasBase<ResourceBuffer>* pData)
	{
		auto vkResult = vk::Result::eSuccess;

		auto* resource = getManager().getResourceManager().getResource<ResourceBuffer>(pData->getDataKEY());
		pData->initAlias(resource);

		return vkResult;
	}

	template<>
	vk::Result RenderPassBase::pinitDataAlias<ResourceImage>(DataAliasBase<ResourceImage>* pData)
	{
		auto vkResult = vk::Result::eSuccess;

		auto* ppData = reinterpret_cast<ImageDataAlias*>(pData);
		auto* resource = getManager().getResourceManager().getResource<ResourceImage>(ppData->getDataKEY());
		ppData->initAlias(resource);
		ppData->setSubresourceRange(vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1));
		getManager().getResourceManager().createImageView(ppData);
		getManager().getResourceManager().createImageSampler(ppData);

		return vkResult;
	}

	template<device::DataDescription T>
	vk::Result RenderPassBase::pCreateDataAlias(typename data_alias_traits<T>::descriptiontype const& dataDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		auto& dataTag = dataDescription.getTag();
		switch (dataDescription.getDataUpdateScheme())
		{
		case graphics::DataUpdateScheme::eFrameStatic:
		{
			pinitDataAlias<typename data_alias_traits<T>::resourcetype>(p_staticData->getData<T>(dataTag));
		}
		break;

		case graphics::DataUpdateScheme::eFrameDynamic:
		{
			uint32_t swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
			for (uint32_t idx = 0; idx < swapchainCount; ++idx)
			{
				pinitDataAlias<typename data_alias_traits<T>::resourcetype>(p_dynamicData->getData<T>(dataTag, idx));
			}
		}
		break;

		default:VERIFY(0);
		}

		return vkResult;
	}

	template<device::DataDescription T>
	vk::Result RenderPassBase::pCreateDataSlot(typename data_alias_traits<T>::descriptiontype const& dataDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		auto& stageIO = getManager().getRenderManager().getStageIO(p_stageType);
		auto& dataTag = dataDescription.getTag();
		switch (dataDescription.getDataUpdateScheme())
		{
		case graphics::DataUpdateScheme::eFrameStatic:
			stageIO.createSlot
			(
				T, dataTag,
				std::make_shared< VkStageInputSlot<T, graphics::DataUpdateScheme::eFrameStatic> >(dataTag, this)
			);
			break;

		case graphics::DataUpdateScheme::eFrameDynamic:
			stageIO.createSlot
			(
				T, dataTag,
				std::make_shared< VkStageInputSlot<T, graphics::DataUpdateScheme::eFrameDynamic> >(dataTag, this)
			);
			break;

		default:VERIFY(0);
		}

		return vkResult;
	}

	template<device::DataDescription T>
	vk::Result RenderPassBase::pInitData()
	{
		auto vkResult = vk::Result::eSuccess;

		auto& stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto& dataDescriptions = stageDescription.getDescriptions<T>();

		for (auto &pDescriptionData : dataDescriptions)
		{
			auto& description = pDescriptionData.second;
			vkResult = getManager().getResourceManager().createResource<T>(description);
			vkResult = pCreateDataAlias<T>(description);
			vkResult = pCreateDataSlot<T>(description);
		}

		return vkResult;
	}

	/*
	********************************************************
	* Template Specilizations of PROTECTED METHODS - END
	********************************************************
	*/



	vk::Result RenderPassBase::initialize()
	{
		auto vkResult = vk::Result::eSuccess;
		
		vkResult = pInitSwapchainData();
		//vkResult = pInitInputVertexData();
		//vkResult = pInitIndexData();
		//vkResult = pInitUniformData();
		//vkResult = pInitTextureData();
		//vkResult = pInitRenderTargets();

		vkResult = pInitData<device::DataDescription::eVertex>();
		vkResult = pInitData<device::DataDescription::eIndex>();
		vkResult = pInitData<device::DataDescription::eUniform>();
		vkResult = pInitData<device::DataDescription::eTexture>();
		vkResult = pInitData<device::DataDescription::eRenderTarget>();

		vkResult = pInitFrameBufferAttachments();
		vkResult = pInitSubpass();
		vkResult = pInitRenderPass();
		vkResult = pInitFrameBuffer();
		//vkResult = pInitStageDrawDescriptions();
		//vkResult = pInitStageInputSlots();
		vkResult = pInitData<device::DataDescription::eDraw>();

		return vkResult;
	}


	vk::Result RenderPassBase::resizeResources()
	{
		auto vkResult = vk::Result::eSuccess;

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().waitIdle();
		assert(vkResult == vk::Result::eSuccess);

		vkResult = pInitFrameBufferAttachments();
		vkResult = pInitSubpass();
		vkResult = pInitRenderPass();
		vkResult = pInitFrameBuffer();

		for (auto &pDrawData : p_drawDescriptions)
		{
			pDrawData.second->resizeResources();
		}

		return vkResult;
	}

	
	vk::Result RenderPassBase::inputSlotWait()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageIO &stageIO = getManager().getRenderManager().getStageIO(p_stageType);
		stageIO.waitForAll();

		return vkResult;
	}

	
	vk::Result RenderPassBase::pInitSwapchainData()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData.push_back(std::make_shared<PassSwapchainData>());
			//p_swapchainData.back()->getDynamicData().reset(new DataTable);
			p_swapchainData.back()->getFramebufferData().reset(new FrameBufferData);
		}

		p_staticData.reset(new DataTable());
		p_dynamicData.reset(new DataTable());

		return vkResult;
	}

	/*
	vk::Result RenderPassBase::pInitInputVertexData()
	{
	auto vkResult = vk::Result::eSuccess;

	graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
	auto & vertexDescritions = stageDescription.getDescription<device::DataDescription::eVertex>();

	for (auto &pVertexDescription : vertexDescritions)
	{
	switch (pVertexDescription.getDataUpdateScheme())
	{
	case graphics::DataUpdateScheme::eFrameStatic: vkResult = pCreateStaticVertexData(pVertexDescription);
	break;
	case graphics::DataUpdateScheme::eFrameDynamic: vkResult = pCreateDynamicVertexData(pVertexDescription);
	break;
	default:assert(0);
	}
	}

	return vkResult;
	}


	vk::Result RenderPassBase::pCreateStaticVertexData(graphics::StageBufferDataDescription& vertexDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		p_staticData->getVertexData(vertexDescription.getTag()).reset(new VertexData(vertexDescription.getTag()));

		p_staticData->getVertexData(vertexDescription.getTag())->datawrite()->
			setLayout(DataLayout(vertexDescription.getDataAttributes()))
			.setMaxUnitCount(vertexDescription.getMaxCount())
			.setUsage(vk::BufferUsageFlagBits::eVertexBuffer);

		vkResult = getManager().getResourceManager().allocateResourceBuffer(p_staticData->getVertexData(vertexDescription.getTag())->datawrite());

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateDynamicVertexData(graphics::StageBufferDataDescription& vertexDescription)
	{
		auto vkResult = vk::Result::eSuccess;
		
		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i]->getDynamicData()->getVertexData(vertexDescription.getTag()).reset(new VertexData(vertexDescription.getTag(), i));
			p_swapchainData[i]->getDynamicData()->getVertexData(vertexDescription.getTag())->datawrite()->
				setLayout(DataLayout(vertexDescription.getDataAttributes()))
				.setMaxUnitCount(vertexDescription.getMaxCount())
				.setUsage(vk::BufferUsageFlagBits::eVertexBuffer);

			vkResult = getManager().getResourceManager().allocateResourceBuffer(p_swapchainData[i]->getDynamicData()->getVertexData(vertexDescription.getTag())->datawrite());
		}

		return vkResult;
	}


	vk::Result RenderPassBase::pInitIndexData()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto & indexDescritions = stageDescription.getDescription<device::DataDescription::eIndex>();

		for (auto &pIndexDescription : indexDescritions)
		{
			switch (pIndexDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic: vkResult = pCreateStaticIndexData(pIndexDescription);
				break;
			case graphics::DataUpdateScheme::eFrameDynamic: vkResult = pCreateDynamicIndexData(pIndexDescription);
				break;
			default:VERIFY(0);
			}
		}

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateStaticIndexData(graphics::StageBufferDataDescription& indexDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		p_staticData->getIndexData(indexDescription.getTag()).reset(new IndexData(indexDescription.getTag()));
		p_staticData->getIndexData(indexDescription.getTag())->datawrite()->
			setLayout(DataLayout(indexDescription.getDataAttributes()))
			.setMaxUnitCount(indexDescription.getMaxCount())
			.setUsage(vk::BufferUsageFlagBits::eIndexBuffer);

		vkResult = getManager().getResourceManager().allocateResourceBuffer(p_staticData->getIndexData(indexDescription.getTag())->datawrite());

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateDynamicIndexData(graphics::StageBufferDataDescription& indexDescription)
	{
		auto vkResult = vk::Result::eSuccess;
		
		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i]->getDynamicData()->getIndexData(indexDescription.getTag()).reset(new IndexData(indexDescription.getTag(), i));
			p_swapchainData[i]->getDynamicData()->getIndexData(indexDescription.getTag())->
				 setTag(indexDescription.getTag())
				.setLayout(DataLayout(indexDescription.getDataAttributes()))
				.setUpdateScheme(indexDescription.getDataUpdateScheme())
				.setMaxUnitCount(indexDescription.getMaxCount());

			vkResult = getManager().getResourceManager().allocateResourceBuffer(p_swapchainData[i]->getDynamicData()->getIndexData(indexDescription.getTag()).get(), vk::BufferUsageFlagBits::eIndexBuffer);
		}

		return vkResult;
	}


	vk::Result RenderPassBase::pInitUniformData()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto & uniformDescritions = stageDescription.getDescription<device::DataDescription::eUniform>();

		for (auto &pUniformDescription : uniformDescritions)
		{
			switch (pUniformDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic: vkResult = pCreateStaticUniformData(pUniformDescription);
				break;
			case graphics::DataUpdateScheme::eFrameDynamic: vkResult = pCreateDynamicUniformData(pUniformDescription);
				break;
			default:assert(0);
			}
		}

		return vkResult;
	}


	vk::Result RenderPassBase::pCreateStaticUniformData(graphics::StageBufferDataDescription& uniformDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		p_staticData->getUniformData(uniformDescription.getTag()).reset(new UniformData());
		p_staticData->getUniformData(uniformDescription.getTag())->
			 setTag(uniformDescription.getTag())
			.setLayout(DataLayout(uniformDescription.getDataAttributes()))
			.setUpdateScheme(uniformDescription.getDataUpdateScheme())
			.setMaxUnitCount(uniformDescription.getMaxCount());

		vkResult = getManager().getResourceManager().allocateUniformData(p_staticData->getUniformData(uniformDescription.getTag()).get(), vk::BufferUsageFlagBits::eUniformBuffer);

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateDynamicUniformData(graphics::StageBufferDataDescription& uniformDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i]->getDynamicData()->getUniformData(uniformDescription.getTag()).reset(new UniformData());
			p_swapchainData[i]->getDynamicData()->getUniformData(uniformDescription.getTag())->
				 setTag(uniformDescription.getTag())
				.setLayout(DataLayout(uniformDescription.getDataAttributes()))
				.setUpdateScheme(uniformDescription.getDataUpdateScheme())
				.setMaxUnitCount(uniformDescription.getMaxCount());

			vkResult = getManager().getResourceManager().allocateUniformData(p_swapchainData[i]->getDynamicData()->getUniformData(uniformDescription.getTag()).get(), vk::BufferUsageFlagBits::eUniformBuffer);
		}

		return vkResult;
	}


	vk::Result RenderPassBase::pInitTextureData()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);
		auto & textureDescritions = stageDescription.getDescription<device::DataDescription::eTexture>();

		for (auto &pTextureDescription : textureDescritions)
		{
			switch (pTextureDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic: vkResult = pCreateStaticTextureData(pTextureDescription);
				break;
			case graphics::DataUpdateScheme::eFrameDynamic: vkResult = pCreateDynamicTextureData(pTextureDescription);
				break;
			default:assert(0);
			}
		}

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateStaticTextureData(graphics::StageImageDataDescription& textureDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		p_staticData->getTextureData(textureDescription.getTag()).reset(new TextureData());
		p_staticData->getTextureData(textureDescription.getTag())->
			 setTag(textureDescription.getTag())
			.setFormat(utils::GET_VKFORMAT_FROM_DATAFORMAT(textureDescription.getDataFormat()))
			.setWidth(textureDescription.getWidth())
			.setHeight(textureDescription.getHeight());

		vkResult = getManager().getResourceManager().createTextureBuffer(p_staticData->getTextureData(textureDescription.getTag()).get());

		return vkResult;
	}

	vk::Result RenderPassBase::pCreateDynamicTextureData(graphics::StageImageDataDescription& textureDescription)
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i]->getDynamicData()->getTextureData(textureDescription.getTag()).reset(new TextureData());
			p_swapchainData[i]->getDynamicData()->getTextureData(textureDescription.getTag())->
				 setTag(textureDescription.getTag())
				.setFormat(utils::GET_VKFORMAT_FROM_DATAFORMAT(textureDescription.getDataFormat()))
				.setWidth(textureDescription.getWidth())
				.setHeight(textureDescription.getHeight());

			vkResult = getManager().getResourceManager().createTextureBuffer(p_swapchainData[i]->getDynamicData()->getTextureData(textureDescription.getTag()).get());
		}

		return vkResult;
	}
	*/


	vk::Result RenderPassBase::pInitSubpass()
	{
		auto vkResult = vk::Result::eSuccess;
		
		p_subpassData.clear();

		/* only one subpass and all the renderpass attachments are available */
		p_subpassData.push_back(SubpassData());
		for (auto i = 0; i < p_swapchainData[0]->getFramebufferData()->getColorAttachments().size(); ++i)
		{
			p_subpassData.back().attachmentRefs.push_back(
				vk::AttachmentReference()
				.setAttachment(i)
				.setLayout(vk::ImageLayout::eColorAttachmentOptimal)
			);
		}

		if (p_swapchainData[0]->getFramebufferData()->getDepthAttachment().get())
		{
			p_subpassData.back().depthRef =
				vk::AttachmentReference()
				.setAttachment(p_subpassData.back().attachmentRefs.size())
				.setLayout(vk::ImageLayout::eDepthStencilAttachmentOptimal);
		}
		
		p_subpassData.back().description = vk::SubpassDescription()
			.setPipelineBindPoint(vk::PipelineBindPoint::eGraphics)
			.setInputAttachmentCount(0)
			.setPInputAttachments(nullptr)
			.setColorAttachmentCount(p_subpassData.back().attachmentRefs.size())
			.setPColorAttachments(p_subpassData.back().attachmentRefs.data())
			.setPResolveAttachments(nullptr)
			.setPDepthStencilAttachment(&p_subpassData.back().depthRef)
			.setPreserveAttachmentCount(0)
			.setPPreserveAttachments(nullptr);

		return vkResult;
	}


	vk::Result RenderPassBase::pInitRenderPass()
	{
		auto vkResult = vk::Result::eSuccess;

		/* attachments */
		std::vector< vk::AttachmentDescription > attachmentDesc;
		for (auto i = 0; i < p_swapchainData[0]->getFramebufferData()->getColorAttachments().size(); ++i)
		{
			attachmentDesc.push_back(
				vk::AttachmentDescription()
				.setFormat(p_swapchainData[0]->getFramebufferData()->getColorAttachments()[i]->getFormat())
				.setSamples(vk::SampleCountFlagBits::e1)
				.setLoadOp(vk::AttachmentLoadOp::eClear)
				.setStoreOp(vk::AttachmentStoreOp::eStore)
				.setStencilLoadOp(vk::AttachmentLoadOp::eDontCare)
				.setStencilStoreOp(vk::AttachmentStoreOp::eDontCare)
				.setInitialLayout(vk::ImageLayout::eUndefined)
				.setFinalLayout(vk::ImageLayout::ePresentSrcKHR));
		}

		if (p_swapchainData[0]->getFramebufferData()->getDepthAttachment().get())
		{
			attachmentDesc.push_back(vk::AttachmentDescription()
				.setFormat(p_swapchainData[0]->getFramebufferData()->getDepthAttachment()->data()->getFormat())
				.setSamples(vk::SampleCountFlagBits::e1)
				.setLoadOp(vk::AttachmentLoadOp::eClear)
				.setStoreOp(vk::AttachmentStoreOp::eDontCare)
				.setStencilLoadOp(vk::AttachmentLoadOp::eDontCare)
				.setStencilStoreOp(vk::AttachmentStoreOp::eDontCare)
				.setInitialLayout(vk::ImageLayout::eUndefined)
				.setFinalLayout(vk::ImageLayout::eDepthStencilAttachmentOptimal));
		}

		/* subpasses */
		std::vector< vk::SubpassDescription > subpassDesc;
		for (auto &pSubpass : p_subpassData)
		{
			subpassDesc.push_back(pSubpass.description);
		}

		/* #todo - subpass dependencies */
		std::vector< vk::SubpassDependency > subpassDep;

		/* renderpass */
		auto const renderpassCreateInfo = vk::RenderPassCreateInfo()
			.setAttachmentCount(attachmentDesc.size())
			.setPAttachments(attachmentDesc.data())
			.setSubpassCount(subpassDesc.size())
			.setPSubpasses(subpassDesc.data())
			.setDependencyCount(subpassDep.size())
			.setPDependencies(subpassDep.data());

		if (p_renderpass)
		{
			getManager().getGraphicsDevice().getLogicalDevice().destroyRenderPass(p_renderpass, nullptr);
		}

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().createRenderPass(&renderpassCreateInfo, nullptr, &p_renderpass);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::Result RenderPassBase::pInitFrameBuffer()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();

		uint32_t width = getManager().getAppManager()->getFrameWidth();
		uint32_t height = getManager().getAppManager()->getFrameHeight();

		for (auto i = 0; i < swapchainCount; ++i)
		{
			std::vector< vk::ImageView > attachments;
			for (auto &frameAttach : p_swapchainData[i]->getFramebufferData()->getColorAttachments())
			{
				attachments.push_back(frameAttach->getImageView());
			}

			if (p_swapchainData[i]->getFramebufferData()->getDepthAttachment().get())
			{
				attachments.push_back(p_swapchainData[i]->getFramebufferData()->getDepthAttachment()->getImageView());
			}

			auto const fbCreateInfo = vk::FramebufferCreateInfo()
				.setRenderPass(p_renderpass)
				.setAttachmentCount(attachments.size())
				.setPAttachments(attachments.data())
				.setWidth(width)
				.setHeight(height)
				.setLayers(1); /* use layers */

			if (p_swapchainData[i]->getFramebufferData()->getFramebuffer())
			{
				getManager().getGraphicsDevice().getLogicalDevice().destroyFramebuffer(p_swapchainData[i]->getFramebufferData()->getFramebuffer());
			}

			vkResult = getManager().getGraphicsDevice().getLogicalDevice().createFramebuffer(&fbCreateInfo, nullptr, p_swapchainData[i]->getFramebufferData()->framebufferPTR());
			assert(vkResult == vk::Result::eSuccess);

			// DEBUG_markObject(debug::getFramebufferRef(p_swapchainData[i]->frameBuffer->frameBuf), "framebuffer", vk::DebugReportObjectTypeEXT::eFramebuffer, debug::getDeviceRef(getManager().getGraphicsDevice().getLogicalDevice()));
		}

		return vkResult;
	}


	/*
	vk::Result RenderPassBase::pInitStageInputSlots()
	{
		auto vkResult = vk::Result::eSuccess;

		graphics::StageDescription & stageDescription = getManager().getRenderManager().getStageDescription(p_stageType);

		auto & vertexDescritions = stageDescription.getDescription<device::DataDescription::eVertex>();
		auto & indexDescritions = stageDescription.getDescription<device::DataDescription::eIndex>();
		auto & uniformDescritions = stageDescription.getDescription<device::DataDescription::eUniform>();
		auto & textureDescritions = stageDescription.getDescription<device::DataDescription::eTexture>();
		auto & drawDescritions = stageDescription.getDescription<device::DataDescription::eDraw>();

		graphics::StageIO & stageIO = getManager().getRenderManager().getStageIO(p_stageType);

		for (auto &pDescription : vertexDescritions)
		{
			switch (pDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic:
				stageIO.createSlot(
					device::DataDescription::eVertex,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eVertex, graphics::DataUpdateScheme::eFrameStatic> >(pDescription.getTag(), this));
				break;
			case graphics::DataUpdateScheme::eFrameDynamic:
				stageIO.createSlot(
					device::DataDescription::eVertex,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eVertex, graphics::DataUpdateScheme::eFrameDynamic> >(pDescription.getTag(), this));
				break;
			default:assert(0);
			}
		}

		for (auto &pDescription : indexDescritions)
		{
			switch (pDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic:
				stageIO.createSlot(
					device::DataDescription::eIndex,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eIndex, graphics::DataUpdateScheme::eFrameStatic> >(pDescription.getTag(), this));
				break;
			case graphics::DataUpdateScheme::eFrameDynamic:
				stageIO.createSlot(
					device::DataDescription::eIndex,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eIndex, graphics::DataUpdateScheme::eFrameDynamic> >(pDescription.getTag(), this));
				break;
			default:assert(0);
			}
		}

		for (auto &pDescription : uniformDescritions)
		{
			switch (pDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic:
				stageIO.createSlot(
					device::DataDescription::eUniform,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eUniform, graphics::DataUpdateScheme::eFrameStatic> >(pDescription.getTag(), this));
				break;
			case graphics::DataUpdateScheme::eFrameDynamic:
				stageIO.createSlot(
					device::DataDescription::eUniform,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eUniform, graphics::DataUpdateScheme::eFrameDynamic> >(pDescription.getTag(), this));
				break;
			default:assert(0);
			}
		}

		for (auto &pDescription : textureDescritions)
		{
			switch (pDescription.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic:
				stageIO.createSlot(
					device::DataDescription::eTexture,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eTexture, graphics::DataUpdateScheme::eFrameStatic> >(pDescription.getTag(), this));
				break;
			case graphics::DataUpdateScheme::eFrameDynamic:
				stageIO.createSlot(
					device::DataDescription::eTexture,
					pDescription.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eTexture, graphics::DataUpdateScheme::eFrameDynamic> >(pDescription.getTag(), this));
				break;
			default:assert(0);
			}
		}


		for (auto &pDescription : drawDescritions)
		{
			switch (pDescription.second.getDataUpdateScheme())
			{
			case graphics::DataUpdateScheme::eFrameStatic:
				stageIO.createSlot(
					device::DataDescription::eDraw,
					pDescription.second.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eDraw, graphics::DataUpdateScheme::eFrameStatic> >(pDescription.second.getTag(), this));
				break;
			case graphics::DataUpdateScheme::eFrameDynamic:
				stageIO.createSlot(
					device::DataDescription::eDraw,
					pDescription.second.getTag(),
					std::make_shared< VkStageInputSlot<device::DataDescription::eDraw, graphics::DataUpdateScheme::eFrameDynamic> >(pDescription.second.getTag(), this));
				break;
			default:assert(0);
			}
		}

		return vkResult;
	}
	*/



	vk::Result RenderPassBase::pInitFrameBufferAttachments()
	{
		auto vkResult = vk::Result::eSuccess;

		vkResult = pCreatePresentFramebufferAttachments();

		return vkResult;
	}

	
	vk::Result RenderPassBase::pCreatePresentFramebufferAttachments()
	{
		auto vkResult = vk::Result::eSuccess;

		auto swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainCount; ++i)
		{
			p_swapchainData[i]->getFramebufferData().reset(new FrameBufferData());
			p_swapchainData[i]->getFramebufferData()->getColorAttachments().push_back(std::make_shared< RenderTarget >("present", i));
			p_swapchainData[i]->getFramebufferData()->getColorAttachments().back()->setBindingIdx(0);
			getManager().getResourceManager().attachSwapchainColorAttachment(p_swapchainData[i]->getFramebufferData()->getColorAttachments().back().get(), i);
		
			// image
			p_swapchainData[i]->getFramebufferData()->getDepthAttachment().reset(new DepthData("present", i));
			getManager().getResourceManager().allocateDepthAttachment(p_swapchainData[i]->getFramebufferData()->getDepthAttachment().get());

			// imageview
			p_swapchainData[i]->getFramebufferData()->getDepthAttachment()->setSubresourceRange(vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eDepth, 0, 1, 0, 1));
			getManager().getResourceManager().createImageView(p_swapchainData[i]->getFramebufferData()->getDepthAttachment().get());

			p_swapchainData[i]->getFramebufferData()->getDepthAttachment()->setBindingIdx(1);
		}

		return vkResult;
	}


} // end namespace vulkan