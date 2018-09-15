/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkStageIO.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "vkStageIO.h"
#include "vkRenderPass.h"
#include "vkResourceManager.h"
#include "vkManager.h"
#include "vkRenderManager.h"
#include "vkDrawDescription.h"

namespace graphics_compute
{
	
	/*
	***************************************************
	class IStageInputSlotBase
	***************************************************
	*/

	IStageInputSlotBase::IStageInputSlotBase()
	{
		m_lock = new InputSlotLock();
	}

	IStageInputSlotBase::~IStageInputSlotBase()
	{
		delete m_lock;
	}

	int IStageInputSlotBase::putFence()
	{
		static_cast< InputSlotLock* >(m_lock)->waitFlag.store(true, std::memory_order_release);

		return 0;
	}

	int IStageInputSlotBase::removeFence()
	{
		std::lock_guard< std::mutex > mLock(static_cast< InputSlotLock* >(m_lock)->mutexLock);
		static_cast< InputSlotLock* >(m_lock)->waitFlag.store(false, std::memory_order_release);
		static_cast< InputSlotLock* >(m_lock)->condVar.notify_all();

		return 0;
	}

	int IStageInputSlotBase::waitFence()
	{
		std::unique_lock< std::mutex > mLock(static_cast< InputSlotLock* >(m_lock)->mutexLock);
		if (static_cast< InputSlotLock* >(m_lock)->waitFlag.load(std::memory_order_acquire))
		{
			auto callback = [&]() {
				return (!(static_cast< InputSlotLock* >(m_lock)->waitFlag.load(std::memory_order_acquire)));
			};
			static_cast< InputSlotLock* >(m_lock)->condVar.wait(mLock, callback);
		}

		return 0;
	}
}



namespace vulkan
{
	/*
	***************************************************
	class VkStageInputSlot
	***************************************************
	*/

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eVertex,
		graphics::DataUpdateScheme::eFrameDynamic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		uint32_t swapchainIdx = getStage()->getManager().getRenderManager().getSwapchainCurrentIndex();
		auto* pData = getStage()->getData<device::DataDescription::eVertex>(p_dataTag, swapchainIdx);

		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eVertex,
		graphics::DataUpdateScheme::eFrameStatic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		auto* pData = getStage()->getData<device::DataDescription::eVertex>(p_dataTag);
		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eIndex,
		graphics::DataUpdateScheme::eFrameDynamic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		uint32_t swapchainIdx = getStage()->getManager().getRenderManager().getSwapchainCurrentIndex();
		auto* pData = getStage()->getData<device::DataDescription::eIndex>(p_dataTag, swapchainIdx);

		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eIndex,
		graphics::DataUpdateScheme::eFrameStatic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		auto* pData = getStage()->getData<device::DataDescription::eIndex>(p_dataTag);
		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eUniform,
		graphics::DataUpdateScheme::eFrameDynamic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		uint32_t swapchainIdx = getStage()->getManager().getRenderManager().getSwapchainCurrentIndex();
		auto* pData = getStage()->getData<device::DataDescription::eUniform>(p_dataTag, swapchainIdx);

		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eUniform,
		graphics::DataUpdateScheme::eFrameStatic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		auto* pData = getStage()->getData<device::DataDescription::eUniform>(p_dataTag);
		getStage()->getManager().getResourceManager().loadBufferData(pData->datawrite(), inputData, dataSize);
		VERIFY(dataSize % pData->data()->getUnitDataSize() == 0);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eTexture,
		graphics::DataUpdateScheme::eFrameDynamic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		uint32_t swapchainIdx = getStage()->getManager().getRenderManager().getSwapchainCurrentIndex();
		auto* pData = getStage()->getData<device::DataDescription::eTexture>(p_dataTag, swapchainIdx);
		getStage()->getManager().getResourceManager().loadImageData(pData->datawrite(), inputData);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eTexture,
		graphics::DataUpdateScheme::eFrameStatic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		auto* pData = getStage()->getData<device::DataDescription::eTexture>(p_dataTag);
		getStage()->getManager().getResourceManager().loadImageData(pData->datawrite(), inputData);

		return 0;
	}


	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eDraw,
		graphics::DataUpdateScheme::eFrameDynamic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		uint32_t swapchainIdx = getStage()->getManager().getRenderManager().getSwapchainCurrentIndex();
		auto drawData = getStage()->getDrawDescriptions();
		drawData[p_dataTag]->updateIndirectDrawCommand(swapchainIdx, inputData, dataSize);

		return 0;
	}

	template<>
	int VkStageInputSlot
		<
		device::DataDescription::eDraw,
		graphics::DataUpdateScheme::eFrameStatic
		>
		::writeData(void* inputData, uint32_t dataSize)
	{
		graphics::InputSlotWriteLock _lock(this);

		// not supported.

		return 0;
	}


} // end namespace vulkan