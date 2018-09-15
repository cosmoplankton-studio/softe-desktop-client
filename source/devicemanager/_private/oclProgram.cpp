/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclProgram.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "oclDevice.h"
#include "oclProgram.h"


namespace opencl
{
	void Program::initProgram(std::vector< std::pair<char const*, size_t> > const& sources)
	{
		p_clProgram = cl::Program(p_Device->getContext(), sources);
	}


	cl_int Program::build
	(
		const char* options,
		void(__stdcall * notifyFptr)(cl_program, void *),
		void* data
	)
	{
		cl_int clResult = CL_BUILD_SUCCESS;

		clResult = p_clProgram.build(options, notifyFptr, data);

		return clResult;
	}

	cl_int Program::createKernels()
	{
		cl_int clResult = CL_SUCCESS;

		std::vector<cl::Kernel> kernels;
		clResult = p_clProgram.createKernels(&kernels);

		for (auto &pKernel : kernels)
		{
			size_t _kernelHash = std::hash<std::string>{}(pKernel.getInfo<CL_KERNEL_FUNCTION_NAME>());
			p_clKernels[_kernelHash] = pKernel;
		}

		return clResult;
	}

} // end namespace opencl