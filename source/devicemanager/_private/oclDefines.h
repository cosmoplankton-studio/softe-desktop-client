/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclDefines.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef OPENCL_DEFINES
#define OPENCL_DEFINES


/* Min Requirement OpenCL 1.2 | NVIDIA(R) doesn't support OpenCL 2.x yet | So for most cases we would use the Cuda Pipeline.
   | Feature parity of OpenCL and Cuda Pipelines is not possible at this point. */
/* Currently I don't have access to RADEON(R) Devices | So can't test OpenCL 2.x | Have to set up a remote workspace */

/* This implementation uses the OpenCL 1.2 C++ Wrapper API | see cl.hpp for details and specification doc link */
#define CL_VERSION_1_2
#define CL_HPP_CL_1_2_DEFAULT_BUILD
// #define __CL_ENABLE_EXCEPTIONS

#include <CL/cl.hpp>


/* standard library */
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <unordered_map>
#include <atomic>
#include <mutex>
#include <memory>
#include <condition_variable>
#include <assert.h>


/* application */
#include "../Idevice.h"
#include "../IcomputeAppManager.h"
#include "../computeManager.h"
#include "oclDEBUG.h"


namespace compute = graphics_compute;

#define COMPUTE_WARP_SIZE 32
#define COMPUTE_GLOBAL_WORK_SIZES 65535

namespace opencl
{
	/* oclDevice.h */
	class Device;
	using DeviceHandle = std::shared_ptr<Device>;
	using DevicePool = std::vector<DeviceHandle>;

	/* oclProgram.h */
	class Program;
	using ProgramHandle = std::shared_ptr<Program>;

	/* oclResources.h */
	class Buffer;
	using BufferHandle = std::shared_ptr<Buffer>;

	class Image;
	using ImageHandle = std::shared_ptr<Image>;

	/* oclExecutionNode */
	class ExecutionNode;
	using ExecNodeHandle = std::shared_ptr<ExecutionNode>;

	/* oclManager.h */
	class Manager;
	using ManagerHandle = std::shared_ptr<Manager>;

	/* oclExecutionmanager.h */
	class ExecutionManager;
	using ExecMgrHandle = std::shared_ptr<ExecutionManager>;

	/* oclResourceManager.h */
	class ResourceManager;
	using ResourceMgrHandle = std::shared_ptr<ResourceManager>;


	/*
	*-------------------------------------------------------------
	* macro definitions
	*-------------------------------------------------------------
	*/
#define LOG_HEADER []() { std::string _header_("FILE: "); _header_ = _header_ +  __FILE__ + " LINE: " + std::to_string(__LINE__) + " FUNCTION: " + __FUNCTION__; return _header_; }																														\

#define THROW_EXCEPTION(e)				\
	/*add internal handler call here */	\
	throw e;


	/*
	*-------------------------------------------------------------
	* inline static helpers
	*-------------------------------------------------------------
	*/
	#define CHECK_STATUS(result, success)					\
		if (result != success)								\
		{													\
			assert(0);										\
		}

	#define CHECK_ERRORSTATUS(result, success)				\
		if (result != success)								\
		{													\
			assert(0);										\
			throw device::runtime_error("OPENCL ERROR");	\
		}

	static inline size_t GET_EXECNODEKEY(std::string const& dispatchKEY)
	{
		return std::hash<std::string>{}(dispatchKEY);
	}

	static inline size_t GET_KERNELKEY(std::string const& name, std::string const& kernelnamespace)
	{
		return std::hash<std::string>{}(kernelnamespace + "__kernel__" + name);
	}

	template<device::ResourceType RsrcT>
	size_t inline GET_RESOURCEKEY(std::string const& str);

	template<>
	size_t inline GET_RESOURCEKEY<device::ResourceType::eBuffer>(std::string const& str)
	{
		return std::hash<std::string>{}("__buffer__" + str);
	}

	template<>
	size_t inline GET_RESOURCEKEY<device::ResourceType::eImage>(std::string const& str)
	{
		return std::hash<std::string>{}("__image__" + str);
	}

	static inline cl::ImageFormat GET_CL_IMAGEFORMAT_FROM_DATAFORMAT(device::DataFormat dataFormat)
	{
		/*
		***********************************************
		* cl_channel_type        * cl_channel_order   *
		*------------------------*--------------------*
		* CL_FLOAT               * CL_A				  *
		* CL_HALF_FLOAT          * CL_R				  *
		* CL_SIGNED_INT16        * CL_RG			  *
		* CL_SIGNED_INT32        * CL_RA			  *
		* CL_SIGNED_INT8		 * CL_RGB			  *
		* CL_SNORM_INT8			 * CL_RGBA			  *
		* CL_SNORM_INT16		 * CL_BGRA			  *
		* CL_UNORM_INT_101010	 * CL_ARGB			  *
		* CL_UNORM_INT16		 * CL_INTENSITY		  *
		* CL_UNORM_INT8			 * CL_LUMINANCE		  *
		* CL_UNORM_SHORT_555	 *					  *
		* CL_UNORM_SHORT_565	 *					  *
		* CL_UNSIGNED_INT16		 *					  *
		* CL_UNSIGNED_INT32		 *					  *
		* CL_UNSIGNED_INT8		 *					  *
		***********************************************
		*/
		
		cl::ImageFormat imageFormat;

		// #improvement - add all the formats
		switch (dataFormat)
		{
		case device::DataFormat::eA8:
			imageFormat.image_channel_data_type = CL_UNSIGNED_INT8;
			imageFormat.image_channel_order = CL_R;
			break;
		case device::DataFormat::eRGBA32:
			imageFormat.image_channel_data_type = CL_UNSIGNED_INT8;
			imageFormat.image_channel_order = CL_RGBA;
			break;
		case device::DataFormat::eR32G32Float:
			imageFormat.image_channel_data_type = CL_FLOAT;
			imageFormat.image_channel_order = CL_RG;
			break;
		case device::DataFormat::eR32G32B32A32Float:
			imageFormat.image_channel_data_type = CL_FLOAT;
			imageFormat.image_channel_order = CL_RGBA;
			break;
		default:
			assert(0);
		}

		return imageFormat;
	}

	static inline void SET_CL_MEMFLAGS_FROM_DATA_ACCESS_QUALIFIER(device::DataAccessQualifier dataaccessQ, cl_mem_flags memflags)
	{
		/*
		******************************
		* cl_mem_flags               *
		******************************
		* CL_MEM_READ_WRITE			 *
		* CL_MEM_WRITE_ONLY			 *
		* CL_MEM_READ_ONLY			 *
		* CL_MEM_USE_HOST_PTR		 *
		* CL_MEM_ALLOC_HOST_PTR		 *
		* CL_MEM_COPY_HOST_PTR		 *
		******************************
		*/
		switch (dataaccessQ)
		{
		case device::DataAccessQualifier::eHostToDevice:
			memflags |= CL_MEM_READ_WRITE;
			break;
		case device::DataAccessQualifier::eDeviceLocal:
			memflags |= CL_MEM_READ_WRITE;
			break;
		case device::DataAccessQualifier::eHostLocal:
			memflags |= CL_MEM_USE_HOST_PTR;
			break;
		default:
			assert(0);
		}
	}

	static inline size_t GET_SIZE_FROM_DATAFORMAT(device::DataFormat dataFormat)
	{
		// #improvement - add all the formats
		switch (dataFormat)
		{
		case device::DataFormat::eDouble32:
		case device::DataFormat::eInt32:
		case device::DataFormat::eUint32:
			return 32 * sizeof(char);
		case device::DataFormat::eFloat16:
		case device::DataFormat::eInt16:
		case device::DataFormat::eUint16:
			return 16 * sizeof(char);
		default:
			assert(0);
		}

		return 0;
	}

} // end namespace opencl



#endif // !OPENCL_DEFINES