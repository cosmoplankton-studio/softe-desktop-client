/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkRenderManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_RENDERMANAGER
#define VULKAN_RENDERMANAGER


#include "vkDefines.h"



namespace vulkan
{
	
	/* #improvement - implement appViewport */
	struct Camera2d
	{
		vec3 eye;
		vec3 origin;
		vec3 up;

		mat4x4 projectionMatrix;
		mat4x4 viewMatrix;
		mat4x4 modelMatrix;
	};


	struct SwapchainData
	{
		vk::SwapchainKHR swapchain;
		std::unique_ptr< vk::Image[] > swapchainImages;

		uint32_t swapchainImageCount{ 3 };
		uint32_t swapchainCurrentIndex{ 0 };
	};

	
	struct SwapchainSynchronization
	{
		std::vector< vk::Fence > drawFences;
		std::vector< vk::Semaphore > imageAquiredSemaphores;
		std::vector< vk::Semaphore > drawCompleteSemaphores;
		std::vector< vk::Semaphore > imageOwnershipSemaphores;

		uint32_t frameLag;
		uint32_t frameIndex;
	};

	
	
	class RenderManager
	{
	public:

		RenderManager(Manager* vkManager);

		virtual ~RenderManager();

		inline Manager &getManager()
		{
			return *p_manager;
		}

		inline Device &getGraphicsDevice()
		{
			return p_manager->getGraphicsDevice();
		}

		inline uint32_t getSwapchainImageCount()
		{
			return p_swapchainData.swapchainImageCount;
		}

		inline uint32_t getSwapchainCurrentIndex()
		{
			return p_swapchainData.swapchainCurrentIndex;
		}

		inline graphics::StageDescription & getStageDescription(graphics::StageType passTag)
		{
			return p_appGraphicsPipeline->getStageDescription(passTag);
		}

		inline graphics::StageIO & getStageIO(graphics::StageType passTag)
		{
			return p_appGraphicsPipeline->stageIO(passTag);
		}

		inline vk::Extent2D const& getSwapchainImageExtend()
		{
			return p_swapchainImageExtend;
		}

		inline void setSwapchainImageExtend(vk::Extent2D const& extend)
		{
			p_swapchainImageExtend = extend;
		}

		virtual vk::Image getSwapchainImage(uint32_t Idx);
		virtual SwapchainSynchronization &getSwapchainSyncs() { return p_swapchainSyncs; }
		virtual RenderPassBase &getRenderPassData(graphics::StageType passTag);

		virtual vec_renderpass &getActiveRenderPasses() { return p_activeRenderChain; }
		virtual uint32_t getMaxTextureCount() { return 100; } /* #improvement - make dynamic */
		virtual uint32_t getMaxUniformCount() { return 100; } /* #improvement - make dynamic */

		virtual vk::Result initRenderResources();
		virtual vk::Result initRenderPipeline(graphics::AppGraphicsPipelineHandle& appGraphicsPipeline);
		virtual vk::Result frameDraw();
		virtual vk::Result resizeResources();

	protected:

		virtual vk::Result pFrameStageResourceWait();
		virtual vk::Result pInitCamera2d();
		virtual vk::Result pInitializeSwapchain();
		virtual vk::Result pInitSwapchainSyncs();

		virtual vk::Result pResizeSwapchain();
		virtual vk::Result pResizeRenderPasses();

	protected:

		Manager*					p_manager;
		vk::Extent2D				p_swapchainImageExtend{ 1,1 };

		graphics::AppGraphicsPipelineHandle	p_appGraphicsPipeline;

		Camera2d					p_camera2d; /* #improvement - multiple viewports */

		map_renderpass				p_renderPasses;
		vec_renderpass				p_activeRenderChain;

		SwapchainData				p_swapchainData;
		SwapchainSynchronization	p_swapchainSyncs;

		bool						p_renderPipelineReady;
	};


} // end namespace vulkan


#endif // VULKAN_RENDERMANAGER