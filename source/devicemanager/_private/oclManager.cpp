/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include <CL/cl_platform.h>
#include "oclManager.h"
#include "oclExecutionManager.h"
#include "oclResourceManager.h"


namespace opencl
{
	uint32_t Manager::s_deviceIdxCounter = 0;

	
	Manager::Manager(compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr)
		: p_cAppManager(cAppManager)
		, p_hostPtr(hostPtr)
		, p_execMgr(std::make_shared<ExecutionManager>(this))
		, p_resourceMgr(std::make_shared<ResourceManager>(this))
	{}

	int Manager::getDeviceCount(size_t& count) const
	{
		return static_cast<int>(p_devicePool.size()); // #safecast
	}

	int Manager::initContextandDevices()
	{
		cl_int clResult = 0;

		// get the first available platform
		clResult = cl::Platform::get(&p_clPlatform);
		CHECK_STATUS(clResult, CL_SUCCESS);

		// get the devicelist
		std::vector< cl::Device > devices;
		clResult = p_clPlatform.getDevices(CL_DEVICE_TYPE_GPU, &devices);
		CHECK_STATUS(clResult, CL_SUCCESS);

		if (!devices.size())
		{
			std::string _logInfo_ = LOG_HEADER() + " NO OPENCL COMPATIBLE GPU FOUND.";
			LOG_ERROR(_logInfo_);
			THROW_EXCEPTION(device::init_error("NO OPENCL COMPATIBLE GPU FOUND."));
		}

		// create a single primary context and command queue per device
		for (auto &pDevice : devices)
		{
			if (pCheckDeviceMinRequirements(&pDevice, DeviceProfile::eGPGPU))
			{
				p_devicePool.push_back(std::make_shared< Device >(s_deviceIdxCounter, device::DeviceType::eGPU, pDevice, DeviceProfile::eGPGPU));
				++s_deviceIdxCounter;
				cl_context_properties contextProps[] = { CL_CONTEXT_PLATFORM, (cl_context_properties)p_clPlatform(), 0 };
				p_devicePool.back()->createContext(contextProps);

				cl_command_queue_properties cmdProps = 0;
				p_devicePool.back()->createCmdQueue(cmdProps);
			}
		}

		return clResult;
	}

	int Manager::initKernelsFromSource(std::vector< char const* > const& sources, std::string const& kernelnamespace /*= "global"*/)
	{
		cl_int clResult = CL_SUCCESS;
		
		std::vector< std::pair<char const*, size_t> > progSources;

		for (auto pSource : sources)
		{
			progSources.push_back(std::pair<char const*, size_t>(pSource, strlen(pSource)));
		}

		p_devicePool.back()->createProgram(kernelnamespace, progSources);

		/*
		---------------------------------------------
		available options
		---------------------------------------------
		-cl-opt-disable -cl-strict-aliasing -cl-mad-enable -cl-no-signed-zeros
		-cl-unsafe-math-optimizations -cl-finite-math-only -cl-fast-relaxed-math
		---------------------------------------------
		*/
		std::string buildOptions = "-cl-mad-enable";
		clResult = p_devicePool.back()->buildProgram(kernelnamespace, buildOptions.c_str());

		p_devicePool.back()->createKernels(kernelnamespace);

		return clResult;
	}

	int Manager::initKernel(std::string const& kernelCode, std::string const& kernelName)
	{
		return 0; // this is required for vulkan compute shader, not critical for OpenCL
	}

	int Manager::initApplicationComputePipeline(compute::AppComputePipelineHandle& appComputePipeline)
	{
		return p_execMgr->initAppComputePipeline(appComputePipeline);
	}

	int Manager::dispatch(compute::DispatchPayload const& payload)
	{
		return p_execMgr->dispatch(payload);
	}

	bool Manager::pCheckDeviceMinRequirements(cl::Device* oclDevice, DeviceProfile profile /*= DeviceProfile::eGPGPU*/)
	{
		bool reqAvailable = true;

		switch (profile)
		{
		case DeviceProfile::eGPGPU:
		{
			std::string profile = oclDevice->getInfo<CL_DEVICE_PROFILE>();
			if (strcmp(profile.c_str(), "FULL_PROFILE"))
				return false;

			if (!oclDevice->getInfo<CL_DEVICE_IMAGE_SUPPORT>())
				return false;

			uint64_t addressbit = oclDevice->getInfo<CL_DEVICE_ADDRESS_BITS>();
			if (addressbit != 64)
				return false;
		}
		break;
		default:
			assert(0);
		}

		return reqAvailable;
	}

} // end namespace opencl