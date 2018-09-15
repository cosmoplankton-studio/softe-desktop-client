/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			computeManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "deviceManager.h"
#include "vkManager.h"
#include "oclManager.h"


namespace graphics_compute
{

	ComputeManagerHandle IComputeManager::createComputeManager(I_ComputeAppManager* appManager, device::DeviceApiType apiType, device::HostPtr hostPtr)
	{
		if (device::DeviceApiType::eVULKAN == apiType)
		{
			return DeviceManager::createComputeDeviceManager<device::DeviceApiType::eVULKAN>(appManager, hostPtr);
		}
		else if (device::DeviceApiType::eOPENCL == apiType)
		{
			return DeviceManager::createComputeDeviceManager<device::DeviceApiType::eOPENCL>(appManager, hostPtr);
		}
		else
		{
			throw device::init_error("Unsupported device api type.");
		}

		return ComputeManagerHandle(nullptr);
	}

}