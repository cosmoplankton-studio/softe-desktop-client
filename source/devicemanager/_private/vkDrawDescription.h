/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkDrawDescription.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef VULKAN_DRAW_DESCRIPTIONS
#define VULKAN_DRAW_DESCRIPTIONS


#include "vkDefines.h"


namespace vulkan
{

	struct DrawSwapchainData
	{
		vk::DescriptorSet descriptorSet;
		vk::CommandBuffer commandBuffer;
		DrawCmdIndirectInfoHandle drawCmdIndirectInfo;
	};


	struct DrawPipelineData
	{
		std::vector< vk::VertexInputBindingDescription >		vertexInputBindingDesc;
		std::vector< vk::VertexInputAttributeDescription >		vertexInputAttributeDesc;
		std::vector< vk::PipelineColorBlendAttachmentState >	pipelineColorBlendAttachmentStates;
		std::vector< vk::PipelineShaderStageCreateInfo >		pipelineShaderStages;
		std::vector< vk::DynamicState > dynamicStates;
	};



	class DrawDescription
	{
	public:

		DrawDescription(RenderPassBase* stage, std::string const& tag)
			: p_stage(stage)
			, p_drawTag(tag)
		{}

		~DrawDescription()
		{}

		inline RenderPassBase* getStage() { return p_stage; }

		inline vk::CommandBuffer const* getCommandBuffer(uint32_t swapchainIdx) { return &p_swapchainData[swapchainIdx].commandBuffer; }

		inline bool isIndexedDraw() { return p_isIndexedDraw; }

		virtual vk::Result initialize();

		virtual vk::Result resizeResources()
		{
			return pInitCommandBuffer();
		}

		virtual vk::Result updateIndirectDrawCommand(uint32_t swapchainIdx, void* inputData, uint32_t dataSize);

	protected:

		vk::Result pInitDescriptorSetLayout();
		vk::Result pInitPipelineLayout();
		vk::Result pInitShaderModules();
		vk::Result pInitPipeline();
		vk::Result pInitDescriptorSets();
		vk::Result pInitIndirectDrawCmdInfo();
		vk::Result pInitCommandBuffer();

		vk::Result pUpdateBufferDescriptorSet(uint32_t swapchainIdx, uint32_t bindingIdx, graphics::StageLayoutBindingDescription & description);
		vk::Result pUpdateImageDescriptorSet(uint32_t swapchainIdx, uint32_t bindingIdx, graphics::StageLayoutBindingDescription & description);
		vk::Result pCreateShaderModule(char const *shaderFile, vk::ShaderModule *shaderModule);

		/* pipeline helpers */
		vk::PipelineInputAssemblyStateCreateInfo pGetPipelineInputAssemblyStateCreateInfo();
		vk::PipelineVertexInputStateCreateInfo pGetPipelineVertexInputStateCreateInfo(VertexData const* vertexData);
		vk::PipelineColorBlendStateCreateInfo pGetPipelineColorBlendStateCreateInfo();
		vk::PipelineDynamicStateCreateInfo pGetPipelineDynamicStateCreateInfo();
		vk::PipelineShaderStageCreateInfo pGetShaderStageCreateInfo(graphics::ShaderStage stage);
		vk::PipelineViewportStateCreateInfo pGetPipelineViewportStateCreateInfo();
		vk::PipelineRasterizationStateCreateInfo pGetPipelineRasterizationStateCreateInfo();
		vk::PipelineMultisampleStateCreateInfo pGetPipelineMultisampleStateCreateInfo();
		vk::PipelineDepthStencilStateCreateInfo pGetPipelineDepthStencilStateCreateInfo();

	protected:
		RenderPassBase * p_stage;
		std::string p_drawTag;

		vk::DescriptorSetLayout				p_descLayout;
		vk::PipelineLayout					p_pipelineLayout;
		vk::Pipeline						p_pipeline;
		vk::PipelineCache					p_pipelineCache; /* #improvement - share pipelinecache with multiple drawdescriptions */
		DrawPipelineData					p_pipelineData;

		std::map
			<
			graphics::ShaderStage,
			vk::ShaderModule
			>								p_shaderData;

		std::vector<DrawSwapchainData>		p_swapchainData;

		std::string p_vertexTag;
		std::string p_indexTag;
		bool p_isIndexedDraw{ true };
	};


} // end namespace vulkan


#endif // !VULKAN_DRAW_DESCRIPTIONS