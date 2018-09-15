/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclResourceManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "oclResources.h"
#include "oclResourceManager.h"


namespace opencl
{
	
	cl_int ResourceManager::createBuffer(Buffer* buffer, compute::BufferDescription const& bufDesc)
	{
		cl_int clResult = CL_SUCCESS;

		DataLayout datalayout(bufDesc.getDataAttributes());
		cl_mem_flags memFlags = 0;
		SET_CL_MEMFLAGS_FROM_DATA_ACCESS_QUALIFIER(bufDesc.getDataAccessQualifier(), memFlags);

		clResult = buffer->create(datalayout, memFlags, bufDesc.getMaxUnitCount(), nullptr);

		return clResult;
	}

	cl_int ResourceManager::allocateBuffer(Buffer* buffer, compute::BufferDescription const& bufDesc)
	{
		cl_int clResult = CL_SUCCESS;
		return clResult;

		DataLayout datalayout(bufDesc.getDataAttributes());
		cl_mem_flags memFlags = 0;
		SET_CL_MEMFLAGS_FROM_DATA_ACCESS_QUALIFIER(bufDesc.getDataAccessQualifier(), memFlags);
		size_t bufferSize = bufDesc.getMaxUnitCount() * datalayout.getDataStride();
		cl::Buffer resource;
		size_t resourceOffset = 0;

		// pAllocateBufferFromManaged(resource, resourceOffset, memFlags, bufferSize);
		clResult = buffer->allocate(resource, resourceOffset, datalayout, bufDesc.getMaxUnitCount());

		return clResult;
	}

	cl_int ResourceManager::readBuffer(const Buffer* buffer, void* dstPtr, size_t dataSize, size_t offset)
	{
		cl_int clResult = CL_SUCCESS;

		bool blocking = true;
		size_t dataOffset = buffer->getResourceOffset() + offset;
		cl::CommandQueue cmdQueue = buffer->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueReadBuffer(buffer->getResource(), blocking, dataOffset, dataSize, dstPtr);

		return clResult;
	}

	cl_int ResourceManager::writeBuffer(Buffer* buffer, const void* srcPtr, size_t dataSize, size_t offset)
	{
		cl_int clResult = CL_SUCCESS;

		bool blocking = true;
		size_t dataOffset = buffer->getResourceOffset() + offset;
		cl::CommandQueue cmdQueue = buffer->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueWriteBuffer(buffer->getResource(), blocking, dataOffset, dataSize, srcPtr);

		return clResult;
	}

	cl_int ResourceManager::copyBuffer(const Buffer* srcbuffer, Buffer* dstbuffer, size_t dataSize, size_t srcOffset, size_t dstOffset)
	{
		cl_int clResult = CL_SUCCESS;

		if (srcbuffer->getDevice()->GetId() != dstbuffer->getDevice()->GetId())
			return clResult; // #improvement - cross device copy

		size_t srcDataOffset = srcbuffer->getResourceOffset() + srcOffset;
		size_t dstDataOffset = dstbuffer->getResourceOffset() + dstOffset;

		cl::CommandQueue cmdQueue = srcbuffer->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueCopyBuffer(srcbuffer->getResource(), dstbuffer->getResource(), srcDataOffset, dstDataOffset, dataSize);

		return clResult;
	}

	cl_int ResourceManager::createImage(Image* image, compute::ImageDescription const& imgDesc)
	{
		cl_int clResult = CL_SUCCESS;

		cl::ImageFormat format = GET_CL_IMAGEFORMAT_FROM_DATAFORMAT(imgDesc.getDataFormat());
		cl_mem_flags memFlags = 0;
		SET_CL_MEMFLAGS_FROM_DATA_ACCESS_QUALIFIER(imgDesc.getDataAccessQualifier(), memFlags);

		switch (imgDesc.getResourceType())
		{
		case compute::ImageViewType::e1D:
			clResult = image->create1D
			(
				format,
				memFlags,
				imgDesc.getWidth(),
				nullptr
			);
			break;
		case compute::ImageViewType::e1DArray:
			clResult = image->create1DArray
			(
				format,
				memFlags,
				imgDesc.getArraySize(),
				imgDesc.getWidth(),
				imgDesc.getRowPitch(),
				nullptr
			);
			break;
		case compute::ImageViewType::e2D:
			clResult = image->create2D
			(
				format,
				memFlags,
				imgDesc.getWidth(),
				imgDesc.getHeight(),
				imgDesc.getRowPitch(),
				nullptr
			);
			break;
		case compute::ImageViewType::e2DArray:
			clResult = image->create2DArray
			(
				format,
				memFlags,
				imgDesc.getArraySize(),
				imgDesc.getWidth(),
				imgDesc.getHeight(),
				imgDesc.getRowPitch(),
				imgDesc.getSlicePitch(),
				nullptr
			);
			break;
		case compute::ImageViewType::e3D:
			clResult = image->create3D
			(
				format,
				memFlags,
				imgDesc.getWidth(),
				imgDesc.getHeight(),
				imgDesc.getDepth(),
				imgDesc.getRowPitch(),
				imgDesc.getSlicePitch(),
				nullptr
			);
			break;
		default:
			break;
		}

		return clResult;
	}

	cl_int ResourceManager::allocateImage(Image* image, compute::ImageDescription const& imgDesc)
	{
		cl_int clResult = CL_SUCCESS;
		return clResult;
	}

	cl_int ResourceManager::readImage(const Image* image, void* dstPtr, const size_t region[3], const size_t origin[3])
	{
		cl_int clResult = CL_SUCCESS;

		bool blocking = true;
		size_t rowPitch = 0;
		size_t slicePitch = 0;
		cl::size_t<3> _region, _origin;
		for (int i = 0; i < 3; ++i)
		{
			_region[i] = region[i];
			_origin[i] = origin[i];
		}

		cl::CommandQueue cmdQueue = image->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueReadImage(*image->getResource(), blocking, _origin, _region, rowPitch, slicePitch, dstPtr);

		return clResult;
	}

	cl_int ResourceManager::writeImage(Image* image, const void* srcPtr, const size_t region[3], const size_t origin[3])
	{
		cl_int clResult = CL_SUCCESS;

		bool blocking = true;
		size_t rowPitch = 0;
		size_t slicePitch = 0;
		cl::size_t<3> _region, _origin;
		for (int i = 0; i < 3; ++i)
		{
			_region[i] = region[i];
			_origin[i] = origin[i];
		}

		cl::CommandQueue cmdQueue = image->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueWriteImage(*image->getResource(), blocking, _origin, _region, rowPitch, slicePitch, const_cast<void*>(srcPtr));

		return clResult;
	}

	cl_int ResourceManager::copyImage(const Image* srcimage, Image* dstimage, const size_t region[3], const size_t srcOrigin[3], const size_t dstOrigin[3])
	{
		cl_int clResult = CL_SUCCESS;

		if (srcimage->getDevice()->GetId() != dstimage->getDevice()->GetId())
			return clResult; // #improvement - cross device copy

		size_t rowPitch = 0;
		size_t slicePitch = 0;
		cl::size_t<3> _region, _srcOrigin, _dstOrigin;
		for (int i = 0; i < 3; ++i)
		{
			_region[i] = region[i];
			_srcOrigin[i] = srcOrigin[i];
			_dstOrigin[i] = dstOrigin[i];
		}

		cl::CommandQueue cmdQueue = srcimage->getDevice()->getCmdQueue();
		clResult = cmdQueue.enqueueCopyImage(*srcimage->getResource(), *dstimage->getResource(), _srcOrigin, _dstOrigin, _region);

		return clResult;
	}


} // end namespace opencl