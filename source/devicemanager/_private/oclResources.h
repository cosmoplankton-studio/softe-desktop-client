/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclResources.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef OPENCL_RESOURCES
#define OPENCL_RESOURCES


#include "oclDefines.h"
#include "oclDevice.h"

namespace opencl
{
	
	class DataLayout
	{
	public:
		DataLayout()
		{}

		explicit DataLayout(device::DataAttributeList const& attributes)
			: p_atrributes(attributes)
		{}

		DataLayout& operator = (device::DataAttributeList const& attributes)
		{
			p_atrributes = attributes;
			return *this;
		}

		inline size_t getAttributesCount() const
		{
			return p_atrributes.size();
		}

		inline size_t getDataStride()
		{
			size_t _size = 0;
			for (auto &attribute : p_atrributes)
			{
				_size += GET_SIZE_FROM_DATAFORMAT(attribute.getFormat());
			}
			return _size;
		}

	protected:
		device::DataAttributeList p_atrributes;
	};


	class Buffer
	{
	public:
		Buffer(Device* device)
			: p_device(device)
		{}

		~Buffer()
		{}

		inline cl::Buffer getResource() const
		{
			return p_clResource;
		}

		inline Device* getDevice() const
		{
			return p_device;
		}

		inline size_t getResourceOffset() const
		{
			return p_resourceOffset;
		}

		void* map()
		{
			return nullptr;
		}

		void unmap()
		{
			
		}

		cl_int create(DataLayout const& layout, cl_mem_flags flags, size_t maxUnitCount, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			p_dataLayout = layout;
			p_maxUnitCount = maxUnitCount;
			size_t bufferSize = p_dataLayout.getDataStride() * p_maxUnitCount;
			p_clResource = cl::Buffer(p_device->getContext(), flags, bufferSize, hostPtr);

			return clResult;
		}

		cl_int allocate(cl::Buffer resource, size_t resourceOffset, DataLayout const& layout, size_t maxUnitCount)
		{
			cl_int clResult = CL_SUCCESS;

			p_dataLayout = layout;
			p_maxUnitCount = maxUnitCount;
			p_clResource = resource;
			p_resourceOffset = resourceOffset;
			return clResult;
		}

	protected:
		Device*			p_device{ nullptr };
		DataLayout		p_dataLayout;
		size_t			p_maxUnitCount{ 0 };
		cl::Buffer		p_clResource;
		size_t			p_resourceOffset{ 0 };
	};


	class Image
	{
	public:
		Image(Device* device)
			: p_device(device)
		{}

		~Image()
		{
			delete p_clResource;
		}

		inline cl::Image* getResource() const
		{
			return p_clResource;
		}

		inline Device* getDevice() const
		{
			return p_device;
		}

		void* map()
		{
			return nullptr;
		}

		void unmap()
		{

		}


		cl_int create1D(cl::ImageFormat format, cl_mem_flags flags, size_t width, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			delete p_clResource;
			p_clResource = new cl::Image1D(p_device->getContext(), flags, format, width, hostPtr);

			return clResult;
		}

		cl_int create1DArray(cl::ImageFormat format, cl_mem_flags flags, size_t arraysize, size_t width, size_t rowpitch, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			delete p_clResource;
			p_clResource = new cl::Image1DArray(p_device->getContext(), flags, format, arraysize, width, rowpitch, hostPtr);

			return clResult;
		}

		cl_int create2D(cl::ImageFormat format, cl_mem_flags flags, size_t width, size_t height, size_t rowpitch = 0, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			delete p_clResource;
			p_clResource = new cl::Image2D(p_device->getContext(), flags, format, width, height, rowpitch, hostPtr);

			return clResult;
		}

		cl_int create2DArray(cl::ImageFormat format, cl_mem_flags flags, size_t arraysize, size_t width, size_t height, size_t rowpitch, size_t slicepitch, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			delete p_clResource;
			p_clResource = new cl::Image2DArray(p_device->getContext(), flags, format, arraysize, width, height, rowpitch, slicepitch, hostPtr);

			return clResult;
		}

		cl_int create3D(cl::ImageFormat format, cl_mem_flags flags, size_t width, size_t height, size_t depth, size_t rowpitch, size_t slicepitch, void* hostPtr = nullptr)
		{
			cl_int clResult = CL_SUCCESS;

			delete p_clResource;
			p_clResource = new cl::Image3D(p_device->getContext(), flags, format, width, height, depth, rowpitch, slicepitch, hostPtr);

			return clResult;
		}


	protected:
		Device*		p_device{ nullptr };
		cl::Image*	p_clResource;
	};

	
	/*
	*-------------------------------
	* currently the application is not using pipes
	*-------------------------------
	class Pipe {};
	*/


} // end namespace opencl


#endif // !OPENCL_RESOURCES
