/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclDevice.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef OPENCL_DEVICE
#define OPENCL_DEVICE


#include "oclDefines.h"


namespace opencl
{
	enum class DeviceProfile : uint32_t
	{
		eGeneral		= 0x0,
		eGPGPU			= 0x1
	};



	class Device
		: public device::IDevice
	{
	public:
		Device(size_t id, device::DeviceType type, cl::Device &clDevice, DeviceProfile profile)
			: IDevice(id, type)
			, p_clDevice(clDevice)
			, p_deviceProfile(profile)
		{}

		virtual ~Device()
		{}

		inline DeviceProfile getProfile() const
		{
			return p_deviceProfile;
		}

		inline cl::Device getLogicalDevice() const
		{
			return p_clDevice;
		}

		inline cl::Context getContext() const
		{
			return p_clContext;
		}

		inline cl::CommandQueue getCmdQueue() const
		{
			return p_clCmdQueue;
		}

		inline ProgramHandle getProgram(std::string const& kernelnamespace) const
		{
			return p_programs.at(std::hash<std::string>{}(kernelnamespace));
		}
		
		inline void createContext(cl_context_properties* properties = nullptr)
		{
			p_clContext = cl::Context(p_clDevice, properties);
		}

		inline void createCmdQueue(cl_command_queue_properties properties = 0)
		{
			p_clCmdQueue = cl::CommandQueue(p_clContext, p_clDevice, properties);
		}

		ProgramHandle createProgram(std::string const& kernelnamespace, std::vector< std::pair<char const*, size_t> > const& sources);

		cl_int buildProgram
		(
			std::string const& kernelnamespace,
			const char* options = nullptr,
			void(__stdcall * notifyFptr)(cl_program, void *) = nullptr,
			void* data = nullptr
		);

		cl_int createKernels(std::string const& kernelnamespace);


	protected:
		DeviceProfile			p_deviceProfile{ DeviceProfile::eGPGPU };
		cl::Device				p_clDevice;
		cl::CommandQueue		p_clCmdQueue;
		cl::Context				p_clContext; /* one primary context per device, similar to cuda */

		std::map
			<
			size_t,
			ProgramHandle
			>					p_programs;

	};

} // end namespace opencl


#endif // !OPENCL_DEVICE