/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclExecutionManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#include "oclDevice.h"
#include "oclProgram.h"
#include "oclResources.h"
#include "oclDataIO.h"
#include "oclKernelIO.h"
#include "oclManager.h"
#include "oclResourceManager.h"
#include "oclExecutionNode.h"
#include "oclExecutionManager.h"



namespace opencl
{

	ExecutionManager::ExecutionManager(Manager* mgr)
		: p_mgr(mgr)
	{
		ResourceIO::s_MGR = mgr;
		ArgSlot::s_MGR = mgr;
	}

	cl_int ExecutionManager::initAppComputePipeline(compute::AppComputePipelineHandle& appComputePipeline)
	{
		cl_int clResult = CL_SUCCESS;

		p_appComputePipeline = appComputePipeline;
		p_appComputePipeline->initDataIO(std::make_shared<compute::DataIO>(new DataSlot()));
		p_appComputePipeline->initDispatchIO(std::make_shared<compute::DispatchIO>(new DispatchSlot()));

		auto const& bufferData = p_appComputePipeline->getBufferDescriptions();
		auto const& imageData = p_appComputePipeline->getImageDescriptions();
		auto const& dispatchData = p_appComputePipeline->getDispatchDescriptions();

		for (auto &pDesc: bufferData)
		{
			clResult = pAddBufferResource(pDesc);
		}

		for (auto &pDesc : imageData)
		{
			clResult = pAddImageResource(pDesc);
		}

		for (auto &pDesc : dispatchData)
		{
			clResult = pAddExecutionNodes(pDesc);
		}

		ResourceIO::setGLock(false);
		ArgSlot::setGLock(false);

		return clResult;
	}

	/*
	******************************
	* protected methods
	******************************
	*/
	cl_int ExecutionManager::pAddBufferResource(compute::BufferDescription const& bufDesc)
	{
		cl_int clResult = CL_SUCCESS;

		// unique resource key
		size_t bufKEY = GET_RESOURCEKEY<device::ResourceType::eBuffer>(bufDesc.getTag());

		// create buffer
		p_buffers[bufKEY] = std::make_shared< Buffer >(getManager()->getPrimaryDevice());		
		clResult = getManager()->getResourceManager()->createBuffer(p_buffers[bufKEY].get(), bufDesc);

		// create buffer io slot
		DataSlot* dataslot = reinterpret_cast<DataSlot*>(p_appComputePipeline->getDataIO()->getImpl());
		dataslot->addSlot<device::ResourceType::eBuffer>(bufKEY, std::make_shared<BufferIO>(bufKEY));

		return clResult;
	}

	cl_int ExecutionManager::pAddImageResource(compute::ImageDescription const& imgDesc)
	{
		cl_int clResult = CL_SUCCESS;

		// unique resource key
		size_t imgKEY = GET_RESOURCEKEY<device::ResourceType::eImage>(imgDesc.getTag());

		// create image
		p_images[imgKEY] = std::make_shared< Image >(getManager()->getPrimaryDevice());
		clResult = getManager()->getResourceManager()->createImage(p_images[imgKEY].get(), imgDesc);

		// create image io slot
		DataSlot* dataslot = reinterpret_cast<DataSlot*>(p_appComputePipeline->getDataIO()->getImpl());
		dataslot->addSlot<device::ResourceType::eImage>(imgKEY, std::make_shared<ImageIO>(imgKEY));

		return clResult;
	}

	cl_int ExecutionManager::pAddExecutionNodes(compute::DispatchDescription const& dispatchDesc)
	{
		cl_int clResult = CL_SUCCESS;

		// create execution node
		Device* device = getManager()->getPrimaryDevice();
		size_t execNodeKEY = GET_EXECNODEKEY(dispatchDesc.getTag());
		auto& kernelName = dispatchDesc.getKernelName();
		auto& kernelNamespace = dispatchDesc.getKernelNamespace();
		p_execNodes[execNodeKEY] = std::make_shared<ExecutionNode>(device, kernelName, kernelNamespace);

		// create kernel io slots
		DispatchSlot* dispatchSlot = reinterpret_cast<DispatchSlot*>(p_appComputePipeline->getDispatchIO()->getImpl());
		size_t kernelKEY = GET_KERNELKEY(kernelName, kernelNamespace);
		compute::KernelIOHandle kernelIO = std::make_shared<compute::KernelIO>(new KernelSlot());
		dispatchSlot->addKernelIO(kernelKEY, kernelIO);

		KernelSlot* slotData = reinterpret_cast<KernelSlot*>(kernelIO->getImpl());
		auto prgramHandle = device->getProgram(kernelNamespace);
		cl::Kernel kernelObj = prgramHandle->getKernel(kernelName);
		int argCount = kernelObj.getInfo<CL_KERNEL_NUM_ARGS>();
		
		// create arg io slots
		for(int argIdx = 0; argIdx <argCount; ++argIdx)
		{
			std::string argName = kernelObj.getArgInfo<CL_KERNEL_ARG_NAME>(argIdx);
			compute::ArgIOHandle argIO = std::make_shared<compute::ArgIO>(new ArgSlot(argIdx, execNodeKEY));
			slotData->addArgIO(argName, argIO);
		}

		return clResult;
	}

	template<>
	cl_int ExecutionManager::pDispatch<DeviceProfile::eGPGPU, WorkItemDistribution::eIncremental>
		(ExecutionNode* node, compute::DispatchPayload const& payload)
	{
		cl_int clResult = CL_SUCCESS;

		uint64_t globalworksize = payload.globalworksize;
		// set conservative global limits (there is no such restriction)
		std::array<uint64_t, 3> globalWorkgroupLimit;		
		globalWorkgroupLimit[0] = COMPUTE_GLOBAL_WORK_SIZES; globalWorkgroupLimit[1] = COMPUTE_GLOBAL_WORK_SIZES; globalWorkgroupLimit[2] = COMPUTE_GLOBAL_WORK_SIZES;

		cl::NDRange offset(0, 0, 0);
		std::array<uint64_t, 3> compileWorkGroupSize;

		if (node->hasCompileWorkGroup(compileWorkGroupSize.data()))
		{
			uint64_t localWorkitems = compileWorkGroupSize[0] * compileWorkGroupSize[1] * compileWorkGroupSize[2];
			if (globalworksize % localWorkitems)
			{
				/*
				* globalitemsize incompatible with __kernel workgroupsize
				* #improvemnt - use idle padding to match localworkgroup size.
				* This will impose a restruction on __kernels to return immediately if global_id is more than globalworksize.
				* Else this will unnecessarily stall the idle threads.
				*/

				// return CL_INVALID_GLOBAL_WORK_SIZE;

				// add idle padding.
				globalworksize += globalworksize % localWorkitems;
			}

			/* Distribute the work globally. For this no need for local distribution as local distribution is imposed by the __kernel using __attribute__ */
			std::array<uint64_t, 3> globalWorkDist;

			DISTRIBUTE_WORKITEMS<WorkItemDistribution::eIncremental>
				(
					3,
					payload.globalworksize,
					compileWorkGroupSize.data(),
					globalWorkgroupLimit.data(),
					globalWorkDist.data()
				);
			cl::NDRange local(compileWorkGroupSize[0], compileWorkGroupSize[1], compileWorkGroupSize[2]);
			cl::NDRange global(globalWorkDist[0], globalWorkDist[1], globalWorkDist[2]);

			return node->dispatch(offset, global, local);
		}
		else
		{
			/* set dimensions and max work size per dimension */
			cl_uint maxDimensions = node->getDevice()->getLogicalDevice().getInfo<CL_DEVICE_MAX_WORK_ITEM_DIMENSIONS>();
			std::vector<uint64_t> localWorkgroupLimit;
			localWorkgroupLimit.resize(maxDimensions);
			localWorkgroupLimit = node->getDevice()->getLogicalDevice().getInfo<CL_DEVICE_MAX_WORK_ITEM_SIZES>();
			if (maxDimensions > 3)
			{
				maxDimensions = 3;
				localWorkgroupLimit.resize(maxDimensions);
			}

			/* set warp and local work size */
			uint64_t maxWorkGroupSizeDEVICE = node->getDevice()->getLogicalDevice().getInfo<CL_DEVICE_MAX_WORK_GROUP_SIZE>();
			uint64_t maxWorkGroupSizeKERNEL = node->getKernelWorkGroupSize(); // maxWorkGroupSizeKERNEL will always be less than maxWorkGroupSizeDEVICE
			uint64_t prefWorkGroupMultipleKERNEL = node->getKernelPreferredWorkGroupMultiple();

			if (globalworksize % prefWorkGroupMultipleKERNEL)
			{
				// return CL_INVALID_GLOBAL_WORK_SIZE;
				// add idle padding.
				globalworksize += globalworksize % prefWorkGroupMultipleKERNEL;
			}

			/* distribute local work size */
			std::array<uint64_t, 3> seedDist = { 1 };
			std::array<uint64_t, 3> localWorkDist;
			DISTRIBUTE_WORKITEMS<WorkItemDistribution::eIncremental>
				(
					maxDimensions,
					prefWorkGroupMultipleKERNEL,
					seedDist.data(),
					localWorkgroupLimit.data(),
					localWorkDist.data()
				);

			/* distribute global work size */
			std::array<uint64_t, 3> globalWorkDist;
			DISTRIBUTE_WORKITEMS<WorkItemDistribution::eIncremental>
				(
					maxDimensions,
					payload.globalworksize,
					localWorkDist.data(),
					globalWorkgroupLimit.data(),
					globalWorkDist.data()
				);
			cl::NDRange local(localWorkDist[0], localWorkDist[1], localWorkDist[2]);
			cl::NDRange global(globalWorkDist[0], globalWorkDist[1], globalWorkDist[2]);

			return node->dispatch(offset, global, local);
		}

		return clResult;
	}

	template<>
	cl_int ExecutionManager::pDispatch<DeviceProfile::eGeneral, WorkItemDistribution::eIncremental>(ExecutionNode* node, compute::DispatchPayload const& payload)
	{
		return CL_SUCCESS;
	}



	/*
	* This has to be at the end after the pDispatch explicit specializations.
	*/
	cl_int ExecutionManager::dispatch(compute::DispatchPayload const& payload)
	{
		cl_int clResult = CL_SUCCESS;

		size_t execNodeKEY = GET_EXECNODEKEY(payload.tag);
		ExecutionNode* node = p_execNodes[execNodeKEY].get(); // for now single __kernel
		switch (node->getDevice()->getProfile())
		{
		case DeviceProfile::eGPGPU:
			clResult = pDispatch<DeviceProfile::eGPGPU, WorkItemDistribution::eIncremental>(node, payload);
		default:
			assert(0);
		}

		return clResult;
	}

} // end namespace opencl


