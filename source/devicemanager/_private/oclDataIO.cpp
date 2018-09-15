/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclDataIO.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "oclDataIO.h"
#include "oclManager.h"
#include "oclExecutionManager.h"
#include "oclResourceManager.h"


namespace opencl
{
	Manager* ResourceIO::s_MGR = nullptr;
	bool ResourceIO::s_globalLOCK = true;


	/*
	*************************************
	* BufferIO (BufferSlots)
	*************************************
	*/
	int BufferIO::writeData(const void* srcPtr, size_t dataSize, size_t offset)
	{
		Buffer* buffer = getMgr()->getExecManager()->getBuffer(p_KEY);

		return getMgr()->getResourceManager()->writeBuffer(buffer, srcPtr, dataSize, offset);
	}

	int BufferIO::readData(void* dstPtr, size_t dataSize, size_t offset)
	{
		Buffer* buffer = getMgr()->getExecManager()->getBuffer(p_KEY);

		return getMgr()->getResourceManager()->readBuffer(buffer, dstPtr, dataSize, offset);
	}

	int BufferIO::copyDataTo(const void* srcSlot, size_t dataSize, size_t srcOffset, size_t dstOffset)
	{
		Buffer* srcBuffer = getMgr()->getExecManager()->getBuffer(reinterpret_cast< const BufferIO* >(srcSlot)->getKEY());
		Buffer* dstBuffer = getMgr()->getExecManager()->getBuffer(p_KEY);

		return getMgr()->getResourceManager()->copyBuffer(srcBuffer, dstBuffer, dataSize, srcOffset, dstOffset);
	}

	int BufferIO::copyDataFrom(void* dstSlot, size_t dataSize, size_t srcOffset, size_t dstOffset)
	{
		Buffer* dstBuffer = getMgr()->getExecManager()->getBuffer(reinterpret_cast< BufferIO* >(dstSlot)->getKEY());
		Buffer* srcBuffer = getMgr()->getExecManager()->getBuffer(p_KEY);

		return getMgr()->getResourceManager()->copyBuffer(srcBuffer, dstBuffer, dataSize, srcOffset, dstOffset);
	}


	/*
	*************************************
	* ImageIO (ImageSlots)
	*************************************
	*/
	int ImageIO::writeData(const void* srcPtr, const size_t region[3], const size_t origin[3])
	{
		Image* img = getMgr()->getExecManager()->getImage(p_KEY);

		return getMgr()->getResourceManager()->writeImage(img, srcPtr, region, origin);
	}

	int ImageIO::readData(void* dstPtr, const size_t region[3], const size_t origin[3])
	{
		Image* img = getMgr()->getExecManager()->getImage(p_KEY);

		return getMgr()->getResourceManager()->writeImage(img, dstPtr, region, origin);
	}

	int ImageIO::copyDataTo(const void* srcSlot, const size_t region[3], const size_t srcOrigin[3], const size_t dstOrigin[3])
	{
		Image* srcImg = getMgr()->getExecManager()->getImage(reinterpret_cast< const ImageIO* >(srcSlot)->getKEY());
		Image* dstImg = getMgr()->getExecManager()->getImage(p_KEY);

		return getMgr()->getResourceManager()->copyImage(srcImg, dstImg, region, srcOrigin, dstOrigin);
	}

	int ImageIO::copyDataFrom(void* dstSlot, const size_t region[3], const size_t srcOrigin[3], const size_t dstOrigin[3])
	{
		Image* srcImg = getMgr()->getExecManager()->getImage(reinterpret_cast< ImageIO* >(dstSlot)->getKEY());
		Image* dstImg = getMgr()->getExecManager()->getImage(p_KEY);

		return getMgr()->getResourceManager()->copyImage(srcImg, dstImg, region, srcOrigin, dstOrigin);
	}

} // end namespace opencl
