/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			computeManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef COMPUTE_MANAGER
#define COMPUTE_MANAGER


#ifdef SHAREDLIB_EXPORTS
#define COMPUTE_API __declspec(dllexport)
#else
#define COMPUTE_API __declspec(dllimport)
#endif
// IMPORTANT - Add COMPUTE_API exports to private impl. Here these additions are for documenting purposes only.



namespace graphics_compute
{

    class IComputeManager
    {
    public:

        /**
        * @brief	Create the appropriate Graphics manager e.g. VulkanManager or OpenglManager.
        *
        * @param
        *
        * @return	Handle to the Graphics Manager.
        */
        COMPUTE_API static ComputeManagerHandle createComputeManager(I_ComputeAppManager* appManager, device::DeviceApiType apiType, device::HostPtr hostPtr);


        COMPUTE_API virtual int getDeviceCount(size_t& count) const = 0;
        
        
        /**
        * @brief Initialize the compute instance(vulkan)/context(opencl) and devices.
        *
        * @param
        *
        * @return Error code, any non-zero value specifies an error.
        */
        COMPUTE_API virtual int initContextandDevices() = 0;


        /**
        * @brief	Initialize(Build the Program Executable) the compute kernels(opencl). This creates a compute kernels table.
        *			Separate Compiling, Linking, and Program Library creation are not exposed to the application (#improvement #todo)
        *
        * @param	tag - unique tag of the program (to avoid rebuilding/loading)
        * @param	source - source of the program.
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        COMPUTE_API virtual int initKernelsFromSource(std::vector< char const* > const& sources, std::string const& kernelnamespace = "global") = 0;


        /**
        * @brief	Initialize(Build the Program Executable) compute kernels(opencl)/shaders(vulkan) individually. This adds the kernel/shader to compute kernels table.
        *			Separate Compiling, Linking, and Program Library creation are not exposed to the application (#improvement #todo)
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        COMPUTE_API virtual int initKernel(std::string const& kernelCode, std::string const& kernelName) = 0;

        // #improvement - Add the binary versions.

        
        /**
        * @brief Initialize the compute pipeline with the specified kernels(opencl)/shaders(vulkan) and resources(buffers/images).
        *
        * @param AppComputePipelineHandle	Object providing definitions for program(s)/kernel(s)/shader(s) of
        *									the compute pipeline. Object will also get initilized with
        *									IO and SYNC handles for data transfer and synchronization.
        *
        * @return Error code, any non-zero value specifies an error.
        */
        COMPUTE_API virtual int initApplicationComputePipeline(AppComputePipelineHandle& appComputePipeline) = 0;


        /**
        * @brief Dispatch a compute task to the backend.
        *
        * @param DispatchPayload	Information about the compute tasks (kernels/offsets/workitems).
        *							Currently supports only one ExecutionNode(single kernel). Adding support for the ExecutionGraph.
        *
        * @return Error code, any non-zero value specifies an error.
        */
        COMPUTE_API virtual int dispatch(DispatchPayload const& payload) = 0;
    };
}


#endif // !COMPUTE_MANAGER
