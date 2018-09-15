/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			oclDataIO.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef OPENCL_DATAIO
#define OPENCL_DATAIO

#include "oclDefines.h"


namespace opencl
{

	class ResourceIO
	{
	public:
		ResourceIO(size_t key)
			: p_KEY(key)
		{}

		friend class ExecutionManager;

		static inline Manager* getMgr()
		{
			return s_MGR;
		}

		static inline void setGLock(bool lock)
		{
			s_globalLOCK = lock;
		}

		inline size_t getKEY() const
		{
			return p_KEY;
		}

	protected:
		inline void pSetIsBlocking(bool isBlocking)
		{
			p_BLOCKING = isBlocking;
		}

		size_t p_KEY;
		bool p_BLOCKING{ true };

	private:
		static Manager* s_MGR;
		static bool s_globalLOCK;
	};


	class BufferIO
		: public ResourceIO
		, public compute::BufferSlot
	{
	public:
		BufferIO(size_t key)
			: ResourceIO(key)
		{}

		virtual ~BufferIO()
		{}

		virtual void setIsBlocking(bool isBlocking)
		{
			pSetIsBlocking(isBlocking);
		}

		virtual int writeData(const void* srcPtr, size_t dataSize, size_t offset = 0) override;
		virtual int readData(void* dstPtr, size_t dataSize, size_t offset = 0) override;
		virtual int copyDataTo(const void* srcSlot, size_t dataSize, size_t srcOffset = 0, size_t dstOffset = 0) override;
		virtual int copyDataFrom(void* dstSlot, size_t dataSize, size_t srcOffset = 0, size_t dstOffset = 0) override;
	};

	using BufferIOHandle = std::shared_ptr<BufferIO>;


	class ImageIO
		: public ResourceIO
		, public compute::ImageSlot
	{
	public:
		ImageIO(size_t key)
			: ResourceIO(key)
		{}

		virtual ~ImageIO()
		{}

		virtual void setIsBlocking(bool isBlocking)
		{
			pSetIsBlocking(isBlocking);
		}

		virtual int writeData(const void* srcPtr, const size_t region[3], const size_t origin[3] = { 0 }) override;
		virtual int readData(void* dstPtr, const size_t region[3], const size_t origin[3] = { 0 }) override;
		virtual int copyDataTo(const void* srcSlot, const size_t region[3], const size_t srcOrigin[3] = { 0 }, const size_t dstOrigin[3] = { 0 }) override;
		virtual int copyDataFrom(void* dstSlot, const size_t region[3], const size_t srcOrigin[3] = { 0 }, const size_t dstOrigin[3] = { 0 }) override;
	};

	using ImageIOHandle = std::shared_ptr<ImageIO>;



	class DataSlot final
		: public compute::IDataSlot
	{
	public:

		virtual compute::BufferSlot* getBufferSlot(std::string const& tag) const override
		{
			size_t slotKEY = GET_RESOURCEKEY<device::ResourceType::eBuffer>(tag);
			return p_bufferResourceSlots.at(slotKEY).get();
		}

		virtual compute::ImageSlot* getImageSlot(std::string const& tag) const override
		{
			size_t slotKEY = GET_RESOURCEKEY<device::ResourceType::eImage>(tag);
			return p_imageResourceSlots.at(slotKEY).get();
		}

		template<device::ResourceType RsrcT>
		void addSlot(size_t slotKEY, std::shared_ptr<void> handle);

		template<>
		void addSlot<device::ResourceType::eBuffer>(size_t slotKEY, std::shared_ptr<void> handle)
		{
			p_bufferResourceSlots[slotKEY].reset(reinterpret_cast<BufferIO*>(handle.get()));
			handle.reset();
		}

		template<>
		void addSlot<device::ResourceType::eImage>(size_t slotKEY, std::shared_ptr<void> handle)
		{
			p_imageResourceSlots[slotKEY].reset(reinterpret_cast<ImageIO*>(handle.get()));
			handle.reset();
		}

	protected:
		std::map< size_t, BufferIOHandle > p_bufferResourceSlots;
		std::map< size_t, ImageIOHandle > p_imageResourceSlots;
	};

} // end namespace opencl

#endif // !OPENCL_DATAIO
