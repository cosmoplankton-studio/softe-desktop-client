/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkStageIO.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_STAGE_IO
#define VULKAN_STAGE_IO


#include "vkDefines.h"

namespace graphics_compute
{
	/*
	Input Slot Mutex Lock for multiple thread access.
	*/
	struct InputSlotLock
	{
		std::mutex mutexLock;
		std::condition_variable condVar;
		std::atomic< bool > waitFlag;
	};

	class InputSlotWriteLock
	{
	public:
		InputSlotWriteLock(graphics::IStageInputSlotBase *slot)
			: pSlot(slot)
		{
			pSlot->putFence();
		}

		~InputSlotWriteLock()
		{
			pSlot->removeFence();
		}
	private:
		graphics::IStageInputSlotBase *pSlot;
	};
}


namespace vulkan
{
	
	template
		<
		device::DataDescription dataDescription,
		graphics::DataUpdateScheme dataUpdateScheme
		>
	class VkStageInputSlot : public graphics::IStageInputSlotBase
	{
	public:

		VkStageInputSlot(std::string const& tag, void* stage)
			: p_dataTag(tag)
			, p_stage(stage)
		{}

		virtual ~VkStageInputSlot()
		{}

		inline RenderPassBase* getStage()
		{
			return static_cast<RenderPassBase*>(p_stage);
		}

		virtual int writeData(void* inputData, uint32_t dataSize);
		virtual int appendData(void* inputData, uint32_t dataSize) { return 0; } /* #todo */

	protected:
		std::string		p_dataTag;
		void*			p_stage;
	};


} // end namespace vulkan



#endif // VULKAN_STAGE_IO

