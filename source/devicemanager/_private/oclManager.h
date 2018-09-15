/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef OPENCL_MANAGER
#define OPENCL_MANAGER

#include "oclDefines.h"
#include "oclDevice.h"


namespace opencl
{

	/**
	* @class   Manager
	* @brief   Implementation of the Compute Manager for OpenCL API.
	*
	*/
	class Manager final
		: public compute::IComputeManager
	{
	public:
		Manager(compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr);

		virtual ~Manager()
		{}

        COMPUTE_API virtual int getDeviceCount(size_t& count) const override;

        COMPUTE_API virtual int initContextandDevices() override;

        COMPUTE_API virtual int initKernelsFromSource(std::vector< char const* > const& sources, std::string const& kernelnamespace = "global") override;

        COMPUTE_API virtual int initKernel(std::string const& kernelCode, std::string const& kernelName) override;

        COMPUTE_API virtual int initApplicationComputePipeline(compute::AppComputePipelineHandle& appComputePipeline) override;

        COMPUTE_API virtual int dispatch(compute::DispatchPayload const& payload) override;

		inline ExecutionManager* getExecManager() const
		{
			return p_execMgr.get();
		}

		inline ResourceManager* getResourceManager() const
		{
			return p_resourceMgr.get();
		}

		inline Device* getPrimaryDevice() const
		{
			return p_devicePool.at(p_primaryDeviceIdx).get();
		}

		inline void LOG_ERROR(std::string const& trace)
		{
			p_cAppManager->COMPUTE_LOGERROR(trace);
		}

		inline void LOG_MESSAGE(std::string const& trace)
		{
			p_cAppManager->COMPUTE_LOGMESSAGE(trace);
		}

	protected:

		bool pCheckDeviceMinRequirements(cl::Device* oclDevice, DeviceProfile profile = DeviceProfile::eGPGPU);

	protected:
		compute::I_ComputeAppManager*	p_cAppManager;
		device::HostPtr				p_hostPtr;
		device::DeviceApiType			p_apiType{ device::DeviceApiType::eOPENCL };

		ExecMgrHandle					p_execMgr;
		ResourceMgrHandle				p_resourceMgr;

		cl::Platform					p_clPlatform;

		static uint32_t					s_deviceIdxCounter;
		uint32_t						p_primaryDeviceIdx{ 0 };
		DevicePool						p_devicePool;
	};


} // end namespace opencl




#endif // !OPENCL_MANAGER