/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclResourceManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef OPENCL_RESOURCE_MANAGER
#define OPENCL_RESOURCE_MANAGER

#include "oclDefines.h"
#include "oclDevice.h"


namespace opencl
{

	class ResourceManager
	{
	public:
		explicit ResourceManager(Manager* mgr)
			: p_mgr(mgr)
		{}

		~ResourceManager()
		{}

		inline Manager* getManager()
		{
			return p_mgr;
		}

		/**
		* @name	createBuffer
		* @purpose	create a new buffer from the buffer description and allocate standalone memory.
		*/
		cl_int createBuffer(Buffer* buffer, compute::BufferDescription const& bufDesc);

		/**
		* @name	allocateBuffer
		* @purpose	create a new buffer from the buffer description and assign memory(pointer & offset) from a managed memory (no standalone memory).
		*/
		cl_int allocateBuffer(Buffer* buffer, compute::BufferDescription const& bufDesc);

		/* read, write, and copy */
		cl_int readBuffer(const Buffer* buffer, void* dstPtr, size_t dataSize, size_t offset);
		cl_int writeBuffer(Buffer* buffer, const void* srcPtr, size_t dataSize, size_t offset);
		cl_int copyBuffer(const Buffer* srcbuffer, Buffer* dstbuffer, size_t dataSize, size_t srcOffset, size_t dstOffset);


		/**
		* @name	createImage
		* @purpose	create a new image from the image description and allocate standalone memory.
		*/
		cl_int createImage(Image* image, compute::ImageDescription const& imgDesc);

		/**
		* @name	allocateImage
		* @purpose	create a new image from the image description and assign memory(pointer & offset) from a managed memory (no standalone memory).
		*/
		cl_int allocateImage(Image* image, compute::ImageDescription const& imgDesc);

		/* read, write, and copy */
		cl_int readImage(const Image* image, void* dstPtr, const size_t region[3], const size_t origin[3]);
		cl_int writeImage(Image* image, const void* dstPtr, const size_t region[3], const size_t origin[3]);
		cl_int copyImage(const Image* srcimage, Image* dstimage, const size_t region[3], const size_t srcOrigin[3], const size_t dstOrigin[3]);

	protected:
		Manager * p_mgr;
		// ManagedResourceHandle p_managedResurce;
	};

}

#endif // !OPENCL_RESOURCE_MANAGER