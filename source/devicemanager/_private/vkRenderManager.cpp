/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkRenderManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#include "vkDevice.h"
#include "vkManager.h"
#include "vkResourceManager.h"
#include "vkCmdBufferManager.h"
#include "vkRenderPass.h"
#include "vkRenderManager.h"



namespace vulkan
{
	/*
	***************************************************
	class VkRenderManager
	***************************************************
	*/
	
	RenderManager::RenderManager(Manager* vkManager)
		: p_manager(vkManager)
	{}


	RenderManager::~RenderManager()
	{}


	vk::Image RenderManager::getSwapchainImage(uint32_t Idx)
	{
		assert(Idx < getSwapchainImageCount());

		return p_swapchainData.swapchainImages[Idx];
	}

	
	RenderPassBase &RenderManager::getRenderPassData(graphics::StageType passTag)
	{
		auto passIter = p_renderPasses.find(passTag);
		assert(passIter != p_renderPasses.end());

		return *passIter->second;
	}

	vk::Result RenderManager::initRenderResources()
	{
		auto vkResult = vk::Result::eSuccess;

		vkResult = pInitCamera2d();
		vkResult = pInitializeSwapchain();
		vkResult = pInitSwapchainSyncs();

		return vkResult;
	}


	vk::Result RenderManager::initRenderPipeline(graphics::AppGraphicsPipelineHandle& appGraphicsPipeline)
	{
		auto vkResult = vk::Result::eSuccess;

		getManager().getAppManager()->setFrameWidth(getSwapchainImageExtend().width);
		getManager().getAppManager()->setFrameHeight(getSwapchainImageExtend().height);

		p_appGraphicsPipeline = appGraphicsPipeline;
		auto const& stageMap = appGraphicsPipeline->getStages();

		RenderPassBase *prevPass = nullptr;
		/* create stages */
		for (auto const& stage : stageMap)
		{
			graphics::StageType stageType = stage.first;
			p_renderPasses[stageType] = RenderPassBase::createRenderPass(p_manager, prevPass, stageType);
			prevPass = p_renderPasses[stageType].get();
			p_activeRenderChain.push_back(std::shared_ptr< RenderPassBase >(p_renderPasses[stageType]));

			/* setup stages */
			p_renderPasses[stageType]->initialize();

			/* #todo - interstage compatibility check */
		}

		vkResult = getManager().getCommandManager().RecordDefaultApplicationFrameCmdBuf();

		p_renderPipelineReady = true;

		return vkResult;
	}

	
	vk::Result RenderManager::frameDraw()
	{
		auto vkResult = vk::Result::eSuccess;

		if (!p_renderPipelineReady)
		{
			return vkResult;
		}

		getGraphicsDevice().getLogicalDevice().waitForFences(1, &p_swapchainSyncs.drawFences[p_swapchainSyncs.frameIndex], VK_TRUE, UINT64_MAX);
		getGraphicsDevice().getLogicalDevice().resetFences(1, &p_swapchainSyncs.drawFences[p_swapchainSyncs.frameIndex]);

		do
		{
			vkResult = getGraphicsDevice().getLogicalDevice().acquireNextImageKHR(
				p_swapchainData.swapchain,
				UINT64_MAX,
				p_swapchainSyncs.imageAquiredSemaphores[p_swapchainSyncs.frameIndex],
				vk::Fence(),
				&p_swapchainData.swapchainCurrentIndex
			);

			if (vkResult == vk::Result::eErrorOutOfDateKHR)
			{
				resizeResources();
			}
			else if (vkResult == vk::Result::eSuboptimalKHR)
			{
				break;
			}
			else
			{
				assert(vkResult == vk::Result::eSuccess);
			}
		} while (vkResult != vk::Result::eSuccess);

		/* wait for resources to be updated */
		pFrameStageResourceWait();

		vk::PipelineStageFlags const pipelineStageFlags = vk::PipelineStageFlagBits::eColorAttachmentOutput;

		SwapChainCmdBuffers &cmdBufs = getManager().getCommandManager().GetSwapchainCmds(p_swapchainData.swapchainCurrentIndex);

		auto const submitInfo = vk::SubmitInfo()
			.setPWaitDstStageMask(&pipelineStageFlags)
			.setWaitSemaphoreCount(1)
			.setPWaitSemaphores(&(p_swapchainSyncs.imageAquiredSemaphores[p_swapchainSyncs.frameIndex]))
			.setCommandBufferCount(1)
			.setPCommandBuffers(&cmdBufs.graphicsCmdBuf)
			.setSignalSemaphoreCount(1)
			.setPSignalSemaphores(&(p_swapchainSyncs.drawCompleteSemaphores[p_swapchainSyncs.frameIndex]));

		vkResult = getGraphicsDevice().getDeviceResources().graphicsQueue.submit(1, &submitInfo, p_swapchainSyncs.drawFences[p_swapchainSyncs.frameIndex]);
		assert(vkResult == vk::Result::eSuccess);

		if (getGraphicsDevice().getDeviceProps().separatePresentQueue)
		{
			auto const presentSubmitInfo = vk::SubmitInfo()
				.setPWaitDstStageMask(&pipelineStageFlags)
				.setWaitSemaphoreCount(1)
				.setPWaitSemaphores(&(p_swapchainSyncs.drawCompleteSemaphores[p_swapchainSyncs.frameIndex]))
				.setCommandBufferCount(1)
				.setPCommandBuffers(&cmdBufs.presentCmdBuf)
				.setSignalSemaphoreCount(1)
				.setPSignalSemaphores(&(p_swapchainSyncs.imageOwnershipSemaphores[p_swapchainSyncs.frameIndex]));

			vkResult = getGraphicsDevice().getDeviceResources().presentQueue.submit(1, &presentSubmitInfo, vk::Fence());
			assert(vkResult == vk::Result::eSuccess);
		}

		auto const presentInfo = vk::PresentInfoKHR()
			.setWaitSemaphoreCount(1)
			.setPWaitSemaphores(getGraphicsDevice().getDeviceProps().separatePresentQueue ?
				&(p_swapchainSyncs.imageOwnershipSemaphores[p_swapchainSyncs.frameIndex]) :
				&(p_swapchainSyncs.drawCompleteSemaphores[p_swapchainSyncs.frameIndex]))
			.setSwapchainCount(1)
			.setPSwapchains(&p_swapchainData.swapchain)
			.setPImageIndices(&p_swapchainData.swapchainCurrentIndex);

		vkResult = getGraphicsDevice().getDeviceResources().presentQueue.presentKHR(&presentInfo);
		p_swapchainSyncs.frameIndex += 1;
		p_swapchainSyncs.frameIndex %= p_swapchainSyncs.frameLag;

		if (vkResult == vk::Result::eErrorOutOfDateKHR)
		{
			resizeResources();
		}
		else if (vkResult == vk::Result::eSuboptimalKHR)
		{
			// no need to handle anything for now.
		}
		else
		{
			assert(vkResult == vk::Result::eSuccess);
		}


		return vkResult;
	}


	vk::Result RenderManager::resizeResources()
	{
		auto vkResult = vk::Result::eSuccess;

		if (!p_renderPipelineReady)
		{
			return vkResult;
		}

		vkResult = pInitCamera2d();
		vkResult = pResizeSwapchain();
		vkResult = pResizeRenderPasses();
		vkResult = getManager().getCommandManager().FreeSwapchainCmdBuffers();
		vkResult = getManager().getCommandManager().AllocateSwapchainCmdBuffers();
		vkResult = getManager().getCommandManager().RecordDefaultApplicationFrameCmdBuf();

		return vkResult;
	}

	
	vk::Result RenderManager::pFrameStageResourceWait()
	{
		auto vkResult = vk::Result::eSuccess;

		auto &activePasses = getActiveRenderPasses();
		for (auto &pPassHandle : activePasses)
		{
			pPassHandle->inputSlotWait(); /* #todo - multithread stages */
		}

		return vkResult;
	}

	/* #todo - move this from here once we have appViewport */
	vk::Result RenderManager::pInitCamera2d()
	{
		auto vkResult = vk::Result::eSuccess;

		// Prepare the projection, view, and model matrix.
		p_camera2d.eye[0] = 0.0f;		p_camera2d.eye[1] = 3.0f;		p_camera2d.eye[2] = -5.0f;
		p_camera2d.origin[0] = 0.0f;	p_camera2d.origin[1] = 0.0f;	p_camera2d.origin[2] = 0.0f;
		p_camera2d.up[0] = 0.0f;		p_camera2d.up[1] = 1.0f;		p_camera2d.up[2] = 0.0f;

		float appWidth = getManager().getAppManager()->getFrameWidth();
		float appHeight = getManager().getAppManager()->getFrameHeight();
		float screenAspect = appWidth / appHeight;

		/* todo - multi viewport support */
		mat4x4_perspective(p_camera2d.projectionMatrix, _degreesToRadians(90.0f), screenAspect, 0.1f, 100.0f);

		mat4x4_look_at(p_camera2d.viewMatrix, p_camera2d.eye, p_camera2d.origin, p_camera2d.up);
		mat4x4_identity(p_camera2d.modelMatrix);

		p_camera2d.projectionMatrix[1][1] *= -1;  // flip projection matrix from GL to Vulkan orientation.

		return vkResult;
	}


	vk::Result RenderManager::pInitializeSwapchain()
	{
		auto vkResult = vk::Result::eSuccess;
		
		vk::SwapchainKHR prevSwapchain = p_swapchainData.swapchain;

		vk::SurfaceCapabilitiesKHR surfCapabilities;
		vkResult = getGraphicsDevice().getPhysicalDevice().getSurfaceCapabilitiesKHR(getManager().getRenderSurface(), &surfCapabilities);
		assert(vkResult == vk::Result::eSuccess);

		uint32_t presentModeCount;
		vkResult = getGraphicsDevice().getPhysicalDevice().getSurfacePresentModesKHR(getManager().getRenderSurface(), &presentModeCount, nullptr);
		assert(vkResult == vk::Result::eSuccess);

		std::unique_ptr< vk::PresentModeKHR[] > presentModes(new vk::PresentModeKHR[presentModeCount]);
		vkResult = getGraphicsDevice().getPhysicalDevice().getSurfacePresentModesKHR(getManager().getRenderSurface(), &presentModeCount, presentModes.get());
		assert(vkResult == vk::Result::eSuccess);

		vk::Extent2D swapchainExtent;
		if (surfCapabilities.currentExtent.width == (uint32_t)-1)
		{
			std::string _logInfo_ = LOG_HEADER() + " Pltaform surface is reset to application dimensions.";
		}

		setSwapchainImageExtend(surfCapabilities.currentExtent);
		getManager().getAppManager()->setFrameWidth(getSwapchainImageExtend().width);
		getManager().getAppManager()->setFrameHeight(getSwapchainImageExtend().height);


		if (getGraphicsDevice().getDeviceProps().presentMode != vk::PresentModeKHR::eFifo)
		{
			std::string _logInfo_ = LOG_HEADER() + " Application only supports eFifo present mode.";
			throw std::runtime_error("Application present mode not supported on platform.");
		}

		p_swapchainData.swapchainImageCount = 3;
		if (p_swapchainData.swapchainImageCount < surfCapabilities.minImageCount)
		{
			p_swapchainData.swapchainImageCount = surfCapabilities.minImageCount;
		}

		if ((surfCapabilities.maxImageCount > 0) && (p_swapchainData.swapchainImageCount > surfCapabilities.maxImageCount))
		{
			p_swapchainData.swapchainImageCount = surfCapabilities.maxImageCount;
		}

		vk::SurfaceTransformFlagBitsKHR preTransform;
		if (surfCapabilities.supportedTransforms & vk::SurfaceTransformFlagBitsKHR::eIdentity)
		{
			preTransform = vk::SurfaceTransformFlagBitsKHR::eIdentity;
		}
		else
		{
			preTransform = surfCapabilities.currentTransform;
		}

		vk::CompositeAlphaFlagBitsKHR compositeAlpha = vk::CompositeAlphaFlagBitsKHR::eOpaque;
		std::array < vk::CompositeAlphaFlagBitsKHR, 4 > compositeAlphaFlags = {
			vk::CompositeAlphaFlagBitsKHR::eOpaque,
			vk::CompositeAlphaFlagBitsKHR::ePreMultiplied,
			vk::CompositeAlphaFlagBitsKHR::ePostMultiplied,
			vk::CompositeAlphaFlagBitsKHR::eInherit,
		};
		for (uint32_t i = 0; i < compositeAlphaFlags.size(); ++i)
		{
			if (surfCapabilities.supportedCompositeAlpha & compositeAlphaFlags[i])
			{
				compositeAlpha = compositeAlphaFlags[i];
				break;
			}
		}

		auto const swapchainCreateInfo = vk::SwapchainCreateInfoKHR()
			.setSurface(getManager().getRenderSurface())
			.setMinImageCount(p_swapchainData.swapchainImageCount)
			.setImageFormat(getGraphicsDevice().getDeviceProps().surfaceFormat)
			.setImageColorSpace(getGraphicsDevice().getDeviceProps().surfaceColorSpace)
			.setImageExtent(getSwapchainImageExtend())
			.setImageArrayLayers(1)
			.setImageUsage(vk::ImageUsageFlagBits::eColorAttachment)
			.setImageSharingMode(vk::SharingMode::eExclusive)
			.setQueueFamilyIndexCount(0)
			.setPQueueFamilyIndices(nullptr)
			.setPreTransform(preTransform)
			.setCompositeAlpha(compositeAlpha)
			.setPresentMode(getGraphicsDevice().getDeviceProps().presentMode)
			.setClipped(true)
			.setOldSwapchain(prevSwapchain);


		vkResult = getGraphicsDevice().getLogicalDevice().createSwapchainKHR(&swapchainCreateInfo, nullptr, &(p_swapchainData.swapchain));
		assert(vkResult == vk::Result::eSuccess);

		if (prevSwapchain)
		{
			getGraphicsDevice().getLogicalDevice().destroySwapchainKHR(prevSwapchain, nullptr);
		}

		vkResult = getGraphicsDevice().getLogicalDevice().getSwapchainImagesKHR(p_swapchainData.swapchain, &p_swapchainData.swapchainImageCount, nullptr);
		assert(vkResult == vk::Result::eSuccess);

		p_swapchainData.swapchainImages.reset(new vk::Image[p_swapchainData.swapchainImageCount]);
		vkResult = getGraphicsDevice().getLogicalDevice().getSwapchainImagesKHR(p_swapchainData.swapchain, &p_swapchainData.swapchainImageCount, p_swapchainData.swapchainImages.get());
		assert(vkResult == vk::Result::eSuccess);
		
		vkResult = pInitSwapchainSyncs();
		assert(vkResult == vk::Result::eSuccess);

		p_swapchainData.swapchainCurrentIndex = 0;

		return vkResult;
	}


	vk::Result RenderManager::pInitSwapchainSyncs()
	{
		auto vkResult = vk::Result::eSuccess;
		
		p_swapchainData.swapchainCurrentIndex = 0;
		p_swapchainSyncs.frameLag = 2;
		p_swapchainSyncs.frameIndex = 0;
		p_swapchainSyncs.drawFences.resize(p_swapchainSyncs.frameLag);
		p_swapchainSyncs.drawCompleteSemaphores.resize(p_swapchainSyncs.frameLag);
		p_swapchainSyncs.imageAquiredSemaphores.resize(p_swapchainSyncs.frameLag);
		p_swapchainSyncs.imageOwnershipSemaphores.resize(p_swapchainSyncs.frameLag);

		auto const semaphoreCreateInfo = vk::SemaphoreCreateInfo();
		auto const fenceCreateInfo = vk::FenceCreateInfo().setFlags(vk::FenceCreateFlagBits::eSignaled);
		auto logicalDevice = getGraphicsDevice().getLogicalDevice();

		for (uint32_t i = 0; i < p_swapchainSyncs.frameLag; ++i)
		{
			vkResult = logicalDevice.createFence(&fenceCreateInfo, nullptr, &(p_swapchainSyncs.drawFences[i]));
			assert(vkResult == vk::Result::eSuccess);

			vkResult = logicalDevice.createSemaphore(&semaphoreCreateInfo, nullptr, &(p_swapchainSyncs.imageAquiredSemaphores[i]));
			assert(vkResult == vk::Result::eSuccess);

			vkResult = logicalDevice.createSemaphore(&semaphoreCreateInfo, nullptr, &(p_swapchainSyncs.drawCompleteSemaphores[i]));
			assert(vkResult == vk::Result::eSuccess);

			if (getGraphicsDevice().getDeviceProps().separatePresentQueue)
			{
				vkResult = logicalDevice.createSemaphore(&semaphoreCreateInfo, nullptr, &(p_swapchainSyncs.imageOwnershipSemaphores[i]));
				assert(vkResult == vk::Result::eSuccess);
			}
		}

		return vkResult;
	}
	

	vk::Result RenderManager::pResizeSwapchain()
	{
		auto vkResult = vk::Result::eSuccess;

		vkResult = pInitializeSwapchain();

		return vkResult;
	}


	vk::Result RenderManager::pResizeRenderPasses()
	{
		auto vkResult = vk::Result::eSuccess;

		for (auto &pPassHandle : p_activeRenderChain)
		{
			vkResult = pPassHandle->resizeResources();
			assert(vkResult == vk::Result::eSuccess);
		}

		return vkResult;
	}

	
} // end namespace vulkan
