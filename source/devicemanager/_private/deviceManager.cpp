/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			deviceManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include <exception>

#include "deviceManager.h"
#include "vkManager.h"
#include "oclManager.h"


namespace graphics_compute
{
	
	std::map< std::string, vulkan::ManagerHandle > DeviceManager::s_vkManagers;
	std::map< std::string, opencl::ManagerHandle > DeviceManager::s_oclManagers;

	template <>
	GraphicsManagerHandle DeviceManager::createGraphicsDeviceManager<device::DeviceApiType::eVULKAN>(I_GraphicsAppManager* gAppManager, device::HostPtr hostPtr)
	{
		vulkan::ManagerHandle &handle = s_vkManagers["master"];

		if (handle)
		{
			if (handle->getHost()->GetId() != hostPtr->GetId())
			{
				throw device::init_error("Host Different"); // #imprvement - throw app specific error e.g. app::error_xxx.
			}
			handle->resetGraphicsAppManager(gAppManager);
		}
		else
		{
			handle = std::make_shared<vulkan::Manager>(gAppManager, hostPtr);
		}

		return GraphicsManagerHandle(reinterpret_cast<IGraphicsManager*>(handle.get()));
	}

	template <>
	ComputeManagerHandle DeviceManager::createComputeDeviceManager<device::DeviceApiType::eVULKAN>(I_ComputeAppManager* cAppManager, device::HostPtr hostPtr)
	{
		return nullptr; // not yet implemented
		
		vulkan::ManagerHandle &handle = s_vkManagers["master"];
		if (handle)
		{
			if (hostPtr->GetId() != handle->getHost()->GetId())
			{
				throw device::init_error("Host Different"); // #imprvement - throw app specific error e.g. app::error_xxx.
			}
			handle->resetComputeAppManager(cAppManager);
		}
		else
		{
			handle = std::make_shared<vulkan::Manager>(cAppManager, hostPtr);
		}

		return ComputeManagerHandle(reinterpret_cast<IComputeManager*>(handle.get()));
	}

	template <>
	ComputeManagerHandle DeviceManager::createComputeDeviceManager<device::DeviceApiType::eOPENCL>(I_ComputeAppManager* cAppManager, device::HostPtr hostPtr)
	{
		opencl::ManagerHandle handle = std::make_shared<opencl::Manager>(cAppManager, hostPtr);
		s_oclManagers["master"] = handle;

		return ComputeManagerHandle(reinterpret_cast<IComputeManager*>(handle.get()));
	}


} // end namespace graphics_compute
