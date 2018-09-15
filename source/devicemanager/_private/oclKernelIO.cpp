/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclKernelIO.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "oclDataIO.h"
#include "oclKernelIO.h"
#include "oclDevice.h"
#include "oclProgram.h"
#include "oclResources.h"
#include "oclManager.h"
#include "oclExecutionNode.h"
#include "oclExecutionManager.h"
#include "oclResourceManager.h"


namespace opencl
{
	Manager* ArgSlot::s_MGR = nullptr;
	bool ArgSlot::s_globalLOCK = true;


	int ArgSlot::argSet(compute::ArgPayload const& payload)
	{
		ExecutionNode* node = getManager()->getExecManager()->getExecNode(p_execNodeKEY);
		return node->setArg(p_argIdx, payload.size, payload.data.get());
	}

	int ArgSlot::argBindBuffer(std::string const& bufferTag)
	{
		ExecutionNode* node = getManager()->getExecManager()->getExecNode(p_execNodeKEY);
		size_t bufKEY = GET_RESOURCEKEY<device::ResourceType::eBuffer>(bufferTag);

		Buffer* resource = getManager()->getExecManager()->getBuffer(bufKEY);
		cl_mem memPtr = resource->getResource()();

		return node->setArg(p_argIdx, sizeof(cl_mem), memPtr);
	}

	int ArgSlot::argBindImage(std::string const& imageTag)
	{
		ExecutionNode* node = getManager()->getExecManager()->getExecNode(p_execNodeKEY);
		size_t imgKEY = GET_RESOURCEKEY<device::ResourceType::eImage>(imageTag);

		Image* resource = getManager()->getExecManager()->getImage(imgKEY);
		cl_mem memPtr = (*resource->getResource())();

		return node->setArg(p_argIdx, sizeof(cl_mem), memPtr);
	}

}
