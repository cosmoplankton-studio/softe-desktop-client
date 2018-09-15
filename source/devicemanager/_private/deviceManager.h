/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/


/**
* @file			deviceManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef DEVICE_MANAGER
#define DEVICE_MANAGER


#include "vkDefines.h"
#include "oclDefines.h"


namespace graphics_compute
{
	
	class DeviceManager
	{
	public:

		template < device::DeviceApiType api_type >
		static GraphicsManagerHandle createGraphicsDeviceManager(I_GraphicsAppManager* gAppManager, device::HostPtr hostPtr);

		template < device::DeviceApiType api_type >
		static ComputeManagerHandle	createComputeDeviceManager(I_ComputeAppManager* cAppManager, device::HostPtr hostPtr);

	protected:
		static std::map< std::string, vulkan::ManagerHandle >		s_vkManagers;
		static std::map< std::string, opencl::ManagerHandle >		s_oclManagers;
	};

} // end namespace graphics_compute


#endif // !DEVICE_MANAGER
