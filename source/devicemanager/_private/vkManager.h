/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_MANAGER
#define VULKAN_MANAGER

#include "vkDefines.h"


namespace vulkan
{

	struct InstanceProperties
	{
		bool validationLayers;

		uint32_t enabledExtensionCount;
		uint32_t enabledLayerCount;

		std::vector< std::string > enabledValidationLayers;
		std::vector< std::string > enabledExtensionNames;

		std::unique_ptr< char const *[] > enabledLayers;
		std::unique_ptr< char const *[] > enabledExtensions;

		char const *const *getEnabledValidationLayers()
		{
			enabledLayers.reset(new char const *[enabledValidationLayers.size()]);
			for (auto i = 0; i < enabledValidationLayers.size(); ++i)
			{
				enabledLayers[i] = enabledValidationLayers[i].c_str();
			}
			return enabledLayers.get();
		}

		char const *const *getEnabledExtensionNames()
		{
			enabledExtensions.reset(new char const *[enabledExtensionNames.size()]);
			for (auto i = 0; i < enabledExtensionNames.size(); ++i)
			{
				enabledExtensions[i] = enabledExtensionNames[i].c_str();
			}
			return enabledExtensions.get();
		}

	};



	/**
	* @class   Manager
	* @brief   Implementation of the Graphics and Compute Manager for Vulkan API.
	*
	*/
	class Manager final
		: public graphics::IGraphicsManager
	{
	public:

		explicit Manager(graphics::I_GraphicsAppManager* gAppManager, device::HostPtr hostPtr);

		explicit Manager(compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr);

		explicit Manager(graphics::I_GraphicsAppManager* gAppManager, compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr);

		virtual ~Manager();

        GRAPHICS_API virtual int getDeviceCount(size_t& count) const override
		{
			return p_devicePool.size();
		}

        GRAPHICS_API virtual int initInstanceAndDevices() override;

        GRAPHICS_API virtual int initApplicationGraphicsPipeline(graphics::AppGraphicsPipelineHandle& appGraphicsPipeline) override;

        GRAPHICS_API virtual int frameDraw() override;

        GRAPHICS_API virtual int resizeGraphicsResources() override;

		inline void resetGraphicsAppManager(graphics::I_GraphicsAppManager* gAppManager)
		{
			p_gAppManager = gAppManager;
		}

		inline void resetComputeAppManager(compute::I_ComputeAppManager* cAppManager)
		{
			p_cAppManager = cAppManager;
		}

		/* get methods */
		inline graphics::I_GraphicsAppManager *getAppManager()
		{
			return p_gAppManager;
		}

		inline device::HostPtr getHost() const
		{
			return p_hostPtr;
		}

		inline compute::I_ComputeAppManager *getComputeAppManager()
		{
			return p_cAppManager;
		}

		inline vk::SurfaceKHR getRenderSurface() { return p_vkSurface; }

		inline Device &getDevice(uint32_t deviceId)
		{
			assert(deviceId < p_devicePool.size());
			if (deviceId >= p_devicePool.size())
			{
				throw std::runtime_error("Vulkan Device Not Available");
			}
			return *p_devicePool[deviceId];
		}

		inline Device &getGraphicsDevice() const
		{
			return *p_devicePool.at(p_graphicsDeviceIdx);
		}

		inline ResourceManager &getResourceManager()
		{
			return *p_bufferManager;
		}

		inline RenderManager &getRenderManager()
		{
			return *p_renderManager;
		}

		inline CmdBufferManager &getCommandManager()
		{
			return *p_cmdBufferManager;
		}


	protected:

		vk::Result pInitManagers();

		vk::Result pInitInstance();

		vk::Result pInitDevices();

		vk::Result pInitValidationLayers();

		vk::Result pInitInstanceExtensions();

		vk::Result pInitDeviceQueueFamily(uint32_t deviceId);

		vk::Result pInitSurfaceFormat(uint32_t deviceId);

		vk::Result pCreateLogicalDevice(uint32_t deviceId);

		vk::Result pCreateDeviceMemoryAllocator(uint32_t deviceId);

		vk::Bool32 pCheckDeviceMinRequirements(Device* vkDevice);

	protected:

		graphics::I_GraphicsAppManager*	p_gAppManager;
		compute::I_ComputeAppManager*	p_cAppManager;
		device::HostPtr					p_hostPtr;
		device::DeviceApiType			p_apiType;

		vk::Instance			p_vkInstance;
		vk::SurfaceKHR			p_vkSurface; // move to vkDevice class once heterogenous device support is complete.
		InstanceProperties		p_instanceProps;
		DevicePool				p_devicePool;
		uint32_t				p_graphicsDeviceIdx;
		uint32_t				p_computeDeviceIdx;

		ResourceManager*		p_bufferManager;
		RenderManager*			p_renderManager;
		CmdBufferManager*		p_cmdBufferManager;
	};


} // end namespace vulkan

#endif // !VULKAN_MANAGER