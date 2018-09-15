/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclExecutionNode.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef OPENCL_EXEC_NODE
#define OPENCL_EXEC_NODE

#include <array>

#include "oclDefines.h"


namespace opencl
{

	class ExecutionNode
	{
	public:
		ExecutionNode(Device* device, std::string const& kernel, std::string const& kernelnamespace)
			: p_device(device)
			, p_kernelName(kernel)
			, p_kernelNamespace(kernelnamespace)
		{
			initKernelWorkGroupInfo();
		}

		inline void initKernelWorkGroupInfo()
		{
			cl::Kernel kernelObj = p_device->getProgram(p_kernelNamespace)->getKernel(p_kernelName);

			p_kernelWorkGroupSize = kernelObj.getWorkGroupInfo<CL_KERNEL_WORK_GROUP_SIZE>(p_device->getLogicalDevice());
			p_KernelPreferredWorkGroupMultiple = kernelObj.getWorkGroupInfo<CL_KERNEL_PREFERRED_WORK_GROUP_SIZE_MULTIPLE>(p_device->getLogicalDevice());			
			cl::size_t<3> wgSizes = kernelObj.getWorkGroupInfo<CL_KERNEL_COMPILE_WORK_GROUP_SIZE>(p_device->getLogicalDevice());
			p_kernelCompileWorkGroupSize[0] = wgSizes[0];
			p_kernelCompileWorkGroupSize[1] = wgSizes[1];
			p_kernelCompileWorkGroupSize[2] = wgSizes[2];
		}

		inline Device* getDevice() const
		{
			return p_device;
		}

		inline bool hasCompileWorkGroup(uint64_t wrkGrp[] = nullptr) const
		{
			if (p_kernelCompileWorkGroupSize[0] && p_kernelCompileWorkGroupSize[1] && p_kernelCompileWorkGroupSize[2])
			{
				if (wrkGrp)
				{
					wrkGrp[0] = p_kernelCompileWorkGroupSize[0];
					wrkGrp[1] = p_kernelCompileWorkGroupSize[1];
					wrkGrp[2] = p_kernelCompileWorkGroupSize[2];
				}
				return true;
			}

			return false;
		}

		inline uint64_t getKernelWorkGroupSize()
		{
			return p_kernelWorkGroupSize;
		}

		inline uint64_t getKernelPreferredWorkGroupMultiple()
		{
			return p_KernelPreferredWorkGroupMultiple;
		}

		template<typename T>
		inline cl_int setArg(cl_uint argIdx, const T &argVal)
		{
			cl::Kernel kernelObj = p_device->getProgram(p_kernelNamespace)->getKernel(p_kernelName);
			return kernelObj.setArg<T>(argIdx, argVal);
		}

		inline cl_int setArg(cl_uint argIdx, size_t argSize, void* argValPtr)
		{
			cl::Kernel kernelObj = p_device->getProgram(p_kernelNamespace)->getKernel(p_kernelName);
			return kernelObj.setArg(argIdx, argSize, argValPtr);
		}

		inline cl_int dispatch(cl::NDRange const& offset, cl::NDRange const& global, cl::NDRange const& local = cl::NullRange)
		{
			cl::CommandQueue cmdQueueObj = p_device->getCmdQueue();
			cl::Kernel kernelObj = p_device->getProgram(p_kernelNamespace)->getKernel(p_kernelName);

			/* #improvement - add the synchronization slots */
			return cmdQueueObj.enqueueNDRangeKernel(kernelObj, offset, global, local);
		}

	protected:
		Device * p_device;
		std::string p_kernelName;
		std::string p_kernelNamespace;

		uint64_t p_kernelWorkGroupSize;
		uint64_t p_KernelPreferredWorkGroupMultiple;
		std::array<uint64_t, 3> p_kernelCompileWorkGroupSize = { 0 };
	};

}

#endif // !OPENCL_EXEC_NODE