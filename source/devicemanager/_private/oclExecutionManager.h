/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclExecutionManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef OPENCL_EXEC_MANAGER
#define OPENCL_EXEC_MANAGER

#include "oclDefines.h"
#include "oclDevice.h"


namespace opencl
{
	/*
	* #improvement - add more after benchmarking.
	*/
	enum class WorkItemDistribution : uint32_t
	{
		eUndefined = 0x0,
		eIncremental = 0x1,
		eUniform = 0x2
	};


	class ExecutionManager
	{
	public:
		explicit ExecutionManager(Manager* mgr);
		~ExecutionManager()
		{}

		inline Manager* getManager() const
		{
			return p_mgr;
		}
		
		inline Buffer* getBuffer(size_t key) const
		{
			return p_buffers.at(key).get();
		}

		inline Image* getImage(size_t key) const
		{
			return p_images.at(key).get();
		}

		inline ExecutionNode* getExecNode(size_t key) const
		{
			return p_execNodes.at(key).get();
		}

		cl_int initAppComputePipeline(compute::AppComputePipelineHandle& appComputePipeline);

		cl_int dispatch(compute::DispatchPayload const& payload);

	protected:
		cl_int pAddBufferResource(compute::BufferDescription const& bufDesc);
		cl_int pAddImageResource(compute::ImageDescription const& imgDesc);
		cl_int pAddExecutionNodes(compute::DispatchDescription const& dispatchDesc);

		template<DeviceProfile __PROFILE, WorkItemDistribution __DISTRIBUTION>
		cl_int pDispatch(ExecutionNode* node, compute::DispatchPayload const& payload);

	protected:
		Manager * p_mgr;
		compute::AppComputePipelineHandle p_appComputePipeline;

		std::map < size_t, BufferHandle > p_buffers;
		std::map < size_t, ImageHandle > p_images;

		/* this will be replaced by the ExecGraph */
		std::map < size_t, ExecNodeHandle > p_execNodes;
	};

	
	/**
	* @name DISTRIBUTE_WORKITEMS
	*-------------------------------
	* @param dimensions -	Work dimensions (1:3)
	* @param totalItems -	Total work items to distribute.
	* @param seedGroupSize -	Seeds in each dimension.
	*							Final distribution will be a multiple of seeds in each dimension.
	* @param finalGroupLimit -	Max limits in each dimension for the final distribution.
	* @param finalGroupDist -	Final work group distribution.
	*-------------------------------
	*/
	template<WorkItemDistribution dist>
	void static __forceinline DISTRIBUTE_WORKITEMS(uint64_t dimensions, uint64_t totalItems, const uint64_t seedGroupSize[], const uint64_t finalGroupLimit[], uint64_t finalGroupDist[]);

	template<>
	void static __forceinline DISTRIBUTE_WORKITEMS<WorkItemDistribution::eIncremental>(uint64_t dimensions, uint64_t totalItems, const uint64_t seedGroupSize[], const uint64_t finalGroupLimit[], uint64_t finalGroupDist[])
	{
		if (dimensions < 1 || dimensions > 3)
			return;
		
		uint64_t xyz_workgroupsize = 1, yz_workgroupsize = 1, z_workgroupsize = 1;
		for (int i=0;i<dimensions;++i)
		{
			xyz_workgroupsize *= seedGroupSize[i];
			if (i>0) yz_workgroupsize *= seedGroupSize[i];
			if (i>1) z_workgroupsize *= seedGroupSize[i];
			finalGroupDist[i] = 1;
		}
		
		if (totalItems % (xyz_workgroupsize))
			return;

		finalGroupDist[0] = totalItems / yz_workgroupsize;
		while (finalGroupDist[0] > finalGroupLimit[0])
		{
			finalGroupDist[0] /= 2;
		}

		if (dimensions < 2)
			return;

		finalGroupDist[1] = (totalItems / finalGroupDist[0]) / z_workgroupsize;
		while (finalGroupDist[1] > finalGroupLimit[1])
		{
			finalGroupDist[1] /= 2;
		}

		if (dimensions < 3)
			return;

		finalGroupDist[2] = (totalItems / finalGroupDist[0]) / finalGroupDist[1];

		assert(finalGroupDist[2] < finalGroupLimit[2]); // this should never happen
	}

} // end namespace opencl


#endif // !OPENCL_EXEC_MANAGER
