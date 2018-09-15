/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkCmdBufferManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "vkDevice.h"
#include "vkManager.h"
#include "vkRenderPass.h"
#include "vkRenderManager.h"
#include "vkCmdBufferManager.h"
#include "vkDrawDescription.h"


namespace vulkan
{

	CmdBufferManager::~CmdBufferManager()
	{
		if (p_graphicsCmdBuf)
		{
			getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_graphicsCmdPool, 1, &p_graphicsCmdBuf);
		}

		if (p_presentCmdBuf)
		{
			getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_presentCmdPool, 1, &p_presentCmdBuf);
		}

		if (p_computeCmdBuf)
		{
			getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_computeCmdPool, 1, &p_computeCmdBuf);
		}

		if (p_graphicsCmdPool)
		{
			getManager().getGraphicsDevice().getLogicalDevice().destroyCommandPool(p_graphicsCmdPool);
		}
			
		if (p_presentCmdPool)
		{
			getManager().getGraphicsDevice().getLogicalDevice().destroyCommandPool(p_presentCmdPool);
		}

		if (p_computeCmdPool)
		{
			getManager().getGraphicsDevice().getLogicalDevice().destroyCommandPool(p_computeCmdPool);
		}

	}

	vk::Result CmdBufferManager::initGraphicsCmdPool()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const cmdPoolInfo = vk::CommandPoolCreateInfo()
			.setQueueFamilyIndex(getManager().getGraphicsDevice().getDeviceProps().graphicsQueueFamilyIndex);

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().createCommandPool(&cmdPoolInfo, nullptr, &p_graphicsCmdPool);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}

	
	vk::Result CmdBufferManager::InitPresentCmdPool()
	{
		auto vkResult = vk::Result::eSuccess;

		if (getManager().getGraphicsDevice().getDeviceProps().separatePresentQueue)
		{
			auto const cmdPoolInfo = vk::CommandPoolCreateInfo()
				.setQueueFamilyIndex(getManager().getGraphicsDevice().getDeviceProps().presentQueueFamilyIndex);

			vkResult = getManager().getGraphicsDevice().getLogicalDevice().createCommandPool(&cmdPoolInfo, nullptr, &p_presentCmdPool);
			assert(vkResult == vk::Result::eSuccess);
		}

		return vkResult;
	}

	
	vk::Result CmdBufferManager::InitComputeCmdPool()
	{
		auto vkResult = vk::Result::eSuccess;

		return vkResult;
	}

	
	vk::Result CmdBufferManager::InitPrimaryGraphicsCmdBuf()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const cmdBufAllocInfo = vk::CommandBufferAllocateInfo()
			.setCommandPool(p_graphicsCmdPool)
			.setLevel(vk::CommandBufferLevel::ePrimary)
			.setCommandBufferCount(1);

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateCommandBuffers(&cmdBufAllocInfo, &p_graphicsCmdBuf);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}

	
	vk::Result CmdBufferManager::InitPrimaryPresentCmdBuf()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const cmdBufAllocInfo = vk::CommandBufferAllocateInfo()
			.setCommandPool(p_presentCmdPool)
			.setLevel(vk::CommandBufferLevel::ePrimary)
			.setCommandBufferCount(1);

		if (getManager().getGraphicsDevice().getDeviceProps().separatePresentQueue)
		{
			vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateCommandBuffers(&cmdBufAllocInfo, &p_presentCmdBuf);
			assert(vkResult == vk::Result::eSuccess);
		}

		return vkResult;
	}

	
	vk::Result CmdBufferManager::InitPrimaryComputeCmdBuf()
	{
		auto vkResult = vk::Result::eSuccess;

		return vkResult;
	}

	
	vk::Result CmdBufferManager::AllocateSwapchainCmdBuffers()
	{
		auto vkResult = vk::Result::eSuccess;

		auto separatePresent = getManager().getGraphicsDevice().getDeviceProps().separatePresentQueue;

		auto const graphicsCmdBufAllocInfo = vk::CommandBufferAllocateInfo()
			.setCommandPool(p_graphicsCmdPool)
			.setLevel(vk::CommandBufferLevel::ePrimary)
			.setCommandBufferCount(1);

		auto const presentCmdBufAllocInfo = vk::CommandBufferAllocateInfo()
			.setCommandPool(p_presentCmdPool)
			.setLevel(vk::CommandBufferLevel::ePrimary)
			.setCommandBufferCount(1);

		auto swapchainImageCount = getManager().getRenderManager().getSwapchainImageCount();

		for (auto i = 0; i < swapchainImageCount; ++i)
		{
			p_swapchainCmds.push_back(SwapChainCmdBuffers());
			vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateCommandBuffers(&graphicsCmdBufAllocInfo, &p_swapchainCmds[i].graphicsCmdBuf);
			assert(vkResult == vk::Result::eSuccess);

			if (separatePresent)
			{
				vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateCommandBuffers(&presentCmdBufAllocInfo, &p_swapchainCmds[i].presentCmdBuf);
				assert(vkResult == vk::Result::eSuccess);
			}
			else
			{
				p_swapchainCmds[i].presentCmdBuf = p_swapchainCmds[i].graphicsCmdBuf;
			}

		}

		return vkResult;
	}

	vk::Result CmdBufferManager::FreeSwapchainCmdBuffers()
	{
		auto vkResult = vk::Result::eSuccess;

		auto separatePresent = getManager().getGraphicsDevice().getDeviceProps().separatePresentQueue;
		auto swapchainImageCount = getManager().getRenderManager().getSwapchainImageCount();

		std::vector< vk::CommandBuffer > graphicsCmdBufs, presentCmdBufs;

		for (auto i = 0; i < swapchainImageCount; ++i)
		{
			graphicsCmdBufs.push_back(p_swapchainCmds[i].graphicsCmdBuf);
			if (separatePresent)
			{
				presentCmdBufs.push_back(p_swapchainCmds[i].presentCmdBuf);
			}
		}

		getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_graphicsCmdPool, swapchainImageCount, graphicsCmdBufs.data());
		if (separatePresent)
		{
			getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_presentCmdPool, swapchainImageCount, presentCmdBufs.data());
		}

		return vkResult;
	}

	
	vk::Result CmdBufferManager::AllocateSecondaryCmdBuffer(vk::CommandBuffer* passCmdBuffer)
	{
		auto vkResult = vk::Result::eSuccess;

		auto const graphicsCmdBufAllocInfo = vk::CommandBufferAllocateInfo()
			.setCommandPool(p_graphicsCmdPool)
			.setLevel(vk::CommandBufferLevel::eSecondary)
			.setCommandBufferCount(1);

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateCommandBuffers(&graphicsCmdBufAllocInfo, passCmdBuffer);
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}


	vk::Result CmdBufferManager::FreeSecondaryCmdBuffer(vk::CommandBuffer* passCmdBuffer)
	{
		auto vkResult = vk::Result::eSuccess;

		getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_graphicsCmdPool, 1, passCmdBuffer);

		return vkResult;
	}


	vk::Result CmdBufferManager::RecordPresentBarrierCmds(vk::CommandBuffer &cmdBuffer, uint32_t swapchainIdx)
	{
		auto vkResult = vk::Result::eSuccess;

		auto const imageMemoryBarrier = vk::ImageMemoryBarrier()
			.setSrcAccessMask(vk::AccessFlags())
			.setDstAccessMask(vk::AccessFlagBits::eColorAttachmentWrite)
			.setOldLayout(vk::ImageLayout::ePresentSrcKHR)
			.setNewLayout(vk::ImageLayout::ePresentSrcKHR)
			.setSrcQueueFamilyIndex(getManager().getGraphicsDevice().getDeviceProps().graphicsQueueFamilyIndex)
			.setDstQueueFamilyIndex(getManager().getGraphicsDevice().getDeviceProps().presentQueueFamilyIndex)
			.setImage(getManager().getRenderManager().getSwapchainImage(swapchainIdx))
			.setSubresourceRange(vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1));

		cmdBuffer.pipelineBarrier(
			vk::PipelineStageFlagBits::eColorAttachmentOutput, vk::PipelineStageFlagBits::eColorAttachmentOutput,
			vk::DependencyFlagBits(), 0, nullptr, 0, nullptr, 1, &imageMemoryBarrier
		);

		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}

	
	vk::Result CmdBufferManager::RecordDeviceInitializationCmds()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const cmdBufBeginInfo = vk::CommandBufferBeginInfo()
			.setPInheritanceInfo(nullptr);

		vkResult = p_graphicsCmdBuf.begin(&cmdBufBeginInfo);
		assert(vkResult == vk::Result::eSuccess);

		/* prepare pipeline initialization commands here - start */

		// e.g. device local data transfer

		/* prepare pipeline initialization commands here - end */

		vkResult = p_graphicsCmdBuf.end();
		assert(vkResult == vk::Result::eSuccess);

		return vkResult;
	}

	
	vk::Result CmdBufferManager::SubmitDeviceInitializationCmds()
	{
		auto vkResult = vk::Result::eSuccess;

		auto const fenceInfo = vk::FenceCreateInfo();
		vk::Fence submitFence;
		vkResult = getManager().getGraphicsDevice().getLogicalDevice().createFence(&fenceInfo, nullptr, &submitFence);
		assert(vkResult == vk::Result::eSuccess);

		auto const submitInfo = vk::SubmitInfo()
			.setCommandBufferCount(1)
			.setPCommandBuffers(&p_graphicsCmdBuf);
		vkResult = getManager().getGraphicsDevice().getDeviceResources().graphicsQueue.submit(1, &submitInfo, submitFence);
		assert(vkResult == vk::Result::eSuccess);

		vkResult = getManager().getGraphicsDevice().getLogicalDevice().waitForFences(1, &submitFence, VK_TRUE, UINT64_MAX);
		assert(vkResult == vk::Result::eSuccess);

		getManager().getGraphicsDevice().getLogicalDevice().freeCommandBuffers(p_graphicsCmdPool, 1, &p_graphicsCmdBuf);
		getManager().getGraphicsDevice().getLogicalDevice().destroyFence(submitFence, nullptr);
		p_graphicsCmdBuf = nullptr;

		return vkResult;
	}

	
	vk::Result CmdBufferManager::RecordDefaultApplicationFrameCmdBuf()
	{
		auto vkResult = vk::Result::eSuccess;

		auto frameWidth = getManager().getAppManager()->getFrameWidth();
		auto frameHeight = getManager().getAppManager()->getFrameHeight();
		vk::ClearValue const clearValues[2] = {
			vk::ClearColorValue(std::array< float, 4 >({ { 0.1f, 0.1f, 0.1f, 0.1f } })),
			vk::ClearDepthStencilValue(1.0f, 0u)
		};

		auto swapchainImageCount = getManager().getRenderManager().getSwapchainImageCount();
		for (auto i = 0; i < swapchainImageCount; ++i)
		{
			vk::CommandBuffer graphicsCmdBuf = p_swapchainCmds[i].graphicsCmdBuf;

			auto const cmdBufBeginInfo = vk::CommandBufferBeginInfo()
				.setFlags(vk::CommandBufferUsageFlagBits::eRenderPassContinue);

			vkResult = graphicsCmdBuf.begin(&cmdBufBeginInfo);
			assert(vkResult == vk::Result::eSuccess);

			/* record renderpass */ /* #todo - multithreading passes */
			auto &activePasses = getManager().getRenderManager().getActiveRenderPasses();
			for (auto &pPassHandle : activePasses)
			{
				auto const renderPassBeginInfo = vk::RenderPassBeginInfo()
					.setRenderPass(pPassHandle->getRenderPass())
					.setFramebuffer(pPassHandle->getFramebuffer(i))
					.setRenderArea(vk::Rect2D(vk::Offset2D(0, 0), vk::Extent2D(frameWidth, frameHeight))) /* #todo - multiple viewport */
					.setClearValueCount(2)
					.setPClearValues(clearValues);

				graphicsCmdBuf.beginRenderPass(&renderPassBeginInfo, vk::SubpassContents::eSecondaryCommandBuffers);

				for (auto &drawDescription : pPassHandle->getDrawDescriptions())
				{
					graphicsCmdBuf.executeCommands(1, drawDescription.second->getCommandBuffer(i));
				}

				graphicsCmdBuf.endRenderPass();
			}

			/* ownership transfer of swapchain image*/
			if (getManager().getGraphicsDevice().getDeviceProps().separatePresentQueue)
			{
				RecordPresentBarrierCmds(graphicsCmdBuf, i);
			}

			vkResult = graphicsCmdBuf.end();
			assert(vkResult == vk::Result::eSuccess);
		}


		return vkResult;
	}


} // end namespace vulkan