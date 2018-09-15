/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclDevice.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "oclDevice.h"
#include "oclProgram.h"


namespace opencl
{

	ProgramHandle Device::createProgram(std::string const& kernelnamespace, std::vector< std::pair<char const*, size_t> > const& sources)
	{
		size_t _progHash = std::hash<std::string>{}(kernelnamespace); // #improvement - move Hash() to utils.
		p_programs[_progHash] = std::make_shared<Program>(this);
		p_programs[_progHash]->initProgram(sources);

		return p_programs[_progHash];
	}

	cl_int Device::buildProgram
	(
		std::string const& kernelnamespace,
		const char* options,
		void(__stdcall * notifyFptr)(cl_program, void *),
		void* data
	)
	{
		cl_int clResult = CL_BUILD_SUCCESS;

		size_t _progHash = std::hash<std::string>{}(kernelnamespace);
		if (p_programs.find(_progHash) != p_programs.end())
		{
			clResult = p_programs[_progHash]->build(options, notifyFptr, data);
		}

		return clResult;
	}

	cl_int Device::createKernels(std::string const& kernelnamespace)
	{
		cl_int clResult = CL_SUCCESS;

		size_t _progHash = std::hash<std::string>{}(kernelnamespace);
		if (p_programs.find(_progHash) != p_programs.end())
		{
			clResult = p_programs[_progHash]->createKernels();
		}

		return clResult;
	}

} // end namespace opencl