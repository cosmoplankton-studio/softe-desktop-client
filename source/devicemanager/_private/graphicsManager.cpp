/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			graphicsManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "deviceManager.h"
#include "vkManager.h"


namespace graphics_compute
{
	
	GraphicsManagerHandle IGraphicsManager::createGraphicsManager(I_GraphicsAppManager* appManager, device::DeviceApiType apiType, device::HostPtr hostPtr)
	{
		if (device::DeviceApiType::eVULKAN == apiType)
		{
			return DeviceManager::createGraphicsDeviceManager<device::DeviceApiType::eVULKAN>(appManager, hostPtr);
		}
		else
		{
			throw device::init_error("Unsupported device api type.");
		}

		return GraphicsManagerHandle(nullptr);
	}

}
