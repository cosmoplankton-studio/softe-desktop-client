/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclProgram.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef OPENCL_PROGRAM
#define OPENCL_PROGRAM


#include "oclDefines.h"

namespace opencl
{

	class Program
	{
	public:

		Program(Device* device)
			: p_Device(device)
		{}

		inline cl::Kernel getKernel(std::string const& kernelName) const
		{
			return p_clKernels.at(std::hash<std::string>{}(kernelName));
		}

		void initProgram(std::vector< std::pair<char const*, size_t> > const& sources);
		
		cl_int build
		(
			const char* options = nullptr,
			void(__stdcall * notifyFptr)(cl_program, void *) = nullptr,
			void* data = nullptr
		);

		cl_int createKernels();

	protected:
		Device*			p_Device;
		cl::Program		p_clProgram;
		std::map<size_t, cl::Kernel> p_clKernels;
	};



} // end namespace opencl



#endif // !OPENCL_PROGRAM