/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkCmdBufferManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_CMDBUFFERMANAGER
#define VULKAN_CMDBUFFERMANAGER


#include "vkDefines.h"


namespace vulkan
{

	struct SwapChainCmdBuffers
	{
		vk::CommandBuffer	graphicsCmdBuf;
		vk::CommandBuffer	presentCmdBuf;
	};


	class CmdBufferManager
	{
	public:

		CmdBufferManager(Manager* manager)
			: p_manager(manager)
		{}

		virtual ~CmdBufferManager();

		inline Manager &getManager()
		{
			return *p_manager;
		}

		/* primary queue command buffers */
		virtual vk::CommandBuffer &GetPrimaryGraphicsCmdBuf()
		{
			return p_graphicsCmdBuf;
		}

		virtual vk::CommandBuffer &GetPrimaryPresentCmdBuf()
		{
			return p_presentCmdBuf;
		}

		virtual vk::CommandBuffer &GetPrimaryComputeCmdBuf()
		{
			return p_computeCmdBuf;
		}
			
		virtual SwapChainCmdBuffers &GetSwapchainCmds(uint32_t idx)
		{
			return p_swapchainCmds[idx];
		}

		/* queue command pools */
		virtual vk::Result initGraphicsCmdPool();

		virtual vk::Result InitPresentCmdPool();

		virtual vk::Result InitComputeCmdPool();

		/* primary command buffers */
		virtual vk::Result InitPrimaryGraphicsCmdBuf();

		virtual vk::Result InitPrimaryPresentCmdBuf();

		virtual vk::Result InitPrimaryComputeCmdBuf();

		/* renderpass command buffers */
		virtual vk::Result AllocateSwapchainCmdBuffers();

		virtual vk::Result FreeSwapchainCmdBuffers();

		virtual vk::Result AllocateSecondaryCmdBuffer(vk::CommandBuffer* passCmdBuffer);

		virtual vk::Result FreeSecondaryCmdBuffer(vk::CommandBuffer* passCmdBuffer);

		/* command buffer record helper */
		virtual vk::Result RecordDeviceInitializationCmds();

		virtual vk::Result SubmitDeviceInitializationCmds();

		virtual vk::Result RecordPresentBarrierCmds(vk::CommandBuffer &cmdBuffer, uint32_t swapchainIdx);

		virtual vk::Result RecordDefaultApplicationFrameCmdBuf();

		
	protected:
		Manager* p_manager;

		vk::CommandPool p_graphicsCmdPool;
		vk::CommandPool p_presentCmdPool;
		vk::CommandPool p_computeCmdPool;

		vk::CommandBuffer p_graphicsCmdBuf;
		vk::CommandBuffer p_presentCmdBuf;
		vk::CommandBuffer p_computeCmdBuf;

		std::vector< SwapChainCmdBuffers > p_swapchainCmds;
	};


} // end namespace vulkan


#endif // VULKAN_CMDBUFFERMANAGER