/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkDevice.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_DEVICE
#define VULKAN_DEVICE

#include "vkDefines.h"


namespace vulkan
{

	struct DeviceResources
	{
		vk::Queue graphicsQueue;
		vk::Queue presentQueue;
	};

	
	struct DeviceProperties
	{
		uint32_t enabledDeviceExtensionCount;
		uint32_t queueFamilyCount;
		uint32_t graphicsQueueFamilyIndex;
		uint32_t presentQueueFamilyIndex;

		bool separatePresentQueue;
		std::vector< vk::QueueFamilyProperties > queueProps;

		vk::PhysicalDeviceProperties physDevProps;
		vk::PhysicalDeviceMemoryProperties memoryProps;
		vk::PhysicalDeviceFeatures physDevFeatures;
		vk::Format surfaceFormat;
		vk::ColorSpaceKHR surfaceColorSpace;
		vk::PresentModeKHR presentMode{ vk::PresentModeKHR::eFifo };

		std::vector< std::string > enabledDeviceExtensionNames;
		std::unique_ptr< char const *[] > enabledExtensions;
		char const *const *getEnabledExtensionNames()
		{
			enabledExtensions.reset(new char const *[enabledDeviceExtensionNames.size()]);
			for (auto i = 0; i < enabledDeviceExtensionNames.size(); ++i)
			{
				enabledExtensions[i] = enabledDeviceExtensionNames[i].c_str();
			}
			return enabledExtensions.get();
		}
	};



	/**
	* @class	Device
	* @brief	Implementation for the accelerated devices.
	*/
	class Device
		: public device::IDevice
	{
	public:
		explicit Device(size_t id, device::DeviceType type)
			: IDevice(id, type)
		{}
		virtual ~Device() {}

		inline DeviceProperties &getDeviceProps()
		{
			return p_deviceProperties;
		}

		inline DeviceResources &getDeviceResources() 
		{
			return p_deviceResources;
		}

		inline vk::PhysicalDevice getPhysicalDevice()
		{
			return p_physicalDevice;
		}

		inline void setPhysicalDevice(vk::PhysicalDevice physDevice)
		{
			p_physicalDevice = physDevice;
		}

		inline vk::Device getLogicalDevice() const
		{
			return p_logicalDevice;
		}

		inline void setLogicalDevice(vk::Device vkDevice)
		{
			p_logicalDevice = vkDevice;
		}

		inline VraAllocator getAllocator()
		{
			return p_vraAllocator;
		}

		inline void setAllocator(VraAllocator allocator)
		{
			p_vraAllocator = allocator;
		}

	protected:
		DeviceProperties		p_deviceProperties;
		DeviceResources			p_deviceResources;

		vk::PhysicalDevice		p_physicalDevice;
		vk::Device				p_logicalDevice;
		VraAllocator			p_vraAllocator;
	};


} // end namespace vulkan

#endif // VULKAN_DEVICE
