
#ifndef VULKAN_RESOURCE_ALLOCATOR_H
#define VULKAN_RESOURCE_ALLOCATOR_H


/**
*******************************************************************
* vra - Vulkan Resource Allocator
*******************************************************************
* vra and vma together would allow for a resource allocation strategy mentioned here:
* https://developer.nvidia.com/vulkan-memory-management
*******************************************************************
* Creating this as a separate library to manage resource allocation.
* Internally it uses vma and accepts all the vma-structures as input.
* No extra layer of createInfo-structures or enums added.
*******************************************************************
*/

#include "vma/vk_mem_alloc.h"

#ifdef __cplusplus
extern "C" {
#endif

	// Description of a Allocator to be created.
	typedef struct VraAllocatorCreateInfo
		: public VmaAllocatorCreateInfo
	{

	} VraAllocatorCreateInfo;


	typedef struct VraAllocationCreateInfo
		: public VmaAllocationCreateInfo
	{

	} VraAllocationCreateInfo;

	// Buffer blocks of different buffer usage types.
	struct VraBufferBlock
	{
		VmaAllocation m_allocation;
		VkBuffer m_Buffer;
	};

	// Buffer blocks of different image usage types.
	struct VraImageBlock
	{
		VmaAllocation m_allocation;
		VkImage m_Image;
	};


	// Base structure for unit resources (buffer/image)
	// Resources could be dedicated or be allocated from blocks.
	struct VraResourceBase
	{
		enum RESOURCE_TYPE
		{
			RESOURCE_TYPE_NONE,
			RESOURCE_TYPE_BLOCK,
			RESOURCE_TYPE_DEDICATED
		};

	protected:
		uint8_t m_Type{ RESOURCE_TYPE_DEDICATED }; // RESOURCE_TYPE
	};


	// Structure for unit buffer resource.
	struct VraBufferResource_T
		: public VraResourceBase
	{

		inline VkBuffer getBuffer() const
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return m_DedicatedAllocation.m_Buffer;

			return m_BlockAllocation.m_Block->m_Buffer;
		}

		inline VkBuffer* bufferPTR()
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return &m_DedicatedAllocation.m_Buffer;

			return &m_BlockAllocation.m_Block->m_Buffer;
		}

		inline VkDeviceSize getOffset() const
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return 0;

			return m_BlockAllocation.m_Offset;
		}

		inline VmaAllocation getAllocation() const
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return m_DedicatedAllocation.m_allocation;

			return m_BlockAllocation.m_Block->m_allocation;
		}

		inline VmaAllocation* allocationPTR()
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return &m_DedicatedAllocation.m_allocation;

			return &m_BlockAllocation.m_Block->m_allocation;
		}

	protected:

		// Resource out of VraBufferBlock.
		struct BlockBuffer
		{
			VraBufferBlock* m_Block;
			VkDeviceSize m_Offset;
		};

		// Resource for an object that has its own private VkBuffer.
		struct DedicatedBuffer
		{
			VkBuffer m_Buffer;
			VmaAllocation m_allocation;
		};

		union
		{
			// Resource out of VraBufferBlock.
			BlockBuffer m_BlockAllocation;
			// Resource for an object that has its own private VkBuffer.
			DedicatedBuffer m_DedicatedAllocation;
		};
	};
	VK_DEFINE_HANDLE(VraBufferResource)


	// Structure for unnit image resource
	struct VraImageResource_T
		: public VraResourceBase
	{

		inline VkImage getImage() const
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return m_DedicatedAllocation.m_Image;

			return m_BlockAllocation.m_Block->m_Image;
		}

		inline VkImage* imagePTR()
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return &m_DedicatedAllocation.m_Image;

			return &m_BlockAllocation.m_Block->m_Image;
		}

		inline VmaAllocation getAllocation() const
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return m_DedicatedAllocation.m_allocation;

			return m_BlockAllocation.m_Block->m_allocation;
		}

		inline VmaAllocation* allocationPTR()
		{
			if (m_Type == RESOURCE_TYPE_DEDICATED)
				return &m_DedicatedAllocation.m_allocation;

			return &m_BlockAllocation.m_Block->m_allocation;
		}

	protected:

		// Resource out of VraImageBlock.
		struct BlockImage
		{
			VraImageBlock* m_Block;
			VkExtent3D m_Offset;
		};

		// Resource for an object that has its own private VkImage.
		struct DedicatedBuffer
		{
			VkImage m_Image;
			VmaAllocation m_allocation;
		};

		union
		{
			// Resource out of VraImageBlock.
			BlockImage m_BlockAllocation;
			// Resource for an object that has its own private VkImage.
			DedicatedBuffer m_DedicatedAllocation;
		};
	};
	VK_DEFINE_HANDLE(VraImageResource)

	VK_DEFINE_HANDLE(VraAllocator)

	// create the allocator
	VkResult vraCreateAllocator(
		const VraAllocatorCreateInfo* pCreateInfo,
		VraAllocator* pAllocator);

	// create a unit buffer
	VkResult vraCreateBuffer(
		VraAllocator allocator,
		const VkBufferCreateInfo* pBufferCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraBufferResource* pBufferResource);

	// create a unit image
	VkResult vraCreateImage(
		VraAllocator allocator,
		const VkImageCreateInfo* pImageCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraImageResource* pBufferResource);

	// map memory to host for the buffer resource
	VkResult vraMapBufferMemory(
		VraAllocator allocator,
		VraBufferResource resource,
		void** ppData);

	// map memory to host for the  image resource
	VkResult vraMapImageMemory(
		VraAllocator allocator,
		VraImageResource resource,
		void** ppData);

	// unmap memory for buffer resource
	void vraUnmapBufferMemory(
		VraAllocator allocator,
		VraBufferResource resource);
	
	// unmap memory for image resource
	void vraUnmapImageMemory(
		VraAllocator allocator,
		VraImageResource resource);

#ifdef __cplusplus
}
#endif

#endif // !VULKAN_RESOURCE_ALLOCATOR_H

	/*
	*----------------------------------------
	* Implementation
	*----------------------------------------
	*/

	// For Visual Studio IntelliSense.
#ifdef __INTELLISENSE__
#define VRA_IMPLEMENTATION
#endif

#ifdef VRA_IMPLEMENTATION
#undef VRA_IMPLEMENTATION

	// Main allocator object.
	struct VraAllocator_T
	{
		VraAllocator_T(const VraAllocatorCreateInfo* pCreateInfo)
		{
			vmaCreateAllocator(pCreateInfo, &m_vmaAllocator);
		}

		~VraAllocator_T()
		{
			vmaDestroyAllocator(m_vmaAllocator);
		}

		VkResult createBuffer(
			const VkBufferCreateInfo* pBufferCreateInfo,
			const VraAllocationCreateInfo* pAllocationCreateInfo,
			VraBufferResource* pBufferResource);
		VkResult createImage(
			const VkImageCreateInfo* pImageCreateInfo,
			const VraAllocationCreateInfo* pAllocationCreateInfo,
			VraImageResource* pImageResource);

		void destroyBuffer(VraBufferResource pBufferResource);
		void destroyImage(VraImageResource pImageResource);

		VkResult map(VraBufferResource resource, void** ppData);
		VkResult map(VraImageResource resource, void** ppData);

		void unmap(VraBufferResource resource);
		void unmap(VraImageResource resource);

	private:
		VmaAllocator m_vmaAllocator;
	};


	VkResult VraAllocator_T::createBuffer(
		const VkBufferCreateInfo* pBufferCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraBufferResource* pBufferResource)
	{
		VmaAllocationInfo pAllocationInfo;
		*pBufferResource = new VraBufferResource_T;
		return vmaCreateBuffer(m_vmaAllocator, pBufferCreateInfo, pAllocationCreateInfo, (*pBufferResource)->bufferPTR(), (*pBufferResource)->allocationPTR(), &pAllocationInfo);
	}
	
	VkResult VraAllocator_T::createImage(
		const VkImageCreateInfo* pImageCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraImageResource* pImageResource)
	{
		VmaAllocationInfo pAllocationInfo;
		*pImageResource = new VraImageResource_T;
		return vmaCreateImage(m_vmaAllocator, pImageCreateInfo, pAllocationCreateInfo, (*pImageResource)->imagePTR(), (*pImageResource)->allocationPTR(), &pAllocationInfo);
	}

	void VraAllocator_T::destroyBuffer(
		VraBufferResource pBufferResource)
	{
		vmaDestroyBuffer(m_vmaAllocator, pBufferResource->getBuffer(), pBufferResource->getAllocation());
	}

	void VraAllocator_T::destroyImage(
		VraImageResource pImageResource)
	{
		vmaDestroyImage(m_vmaAllocator, pImageResource->getImage(), pImageResource->getAllocation());
	}

	VkResult VraAllocator_T::map(
		VraBufferResource resource,
		void** ppData)
	{
		char* pData = NULL;
		VkResult result = vmaMapMemory(m_vmaAllocator, resource->getAllocation(), (void**)&pData);
		*ppData = pData + (ptrdiff_t)resource->getOffset();
		return result;
	}

	VkResult VraAllocator_T::map(
		VraImageResource resource,
		void** ppData)
	{
		VmaAllocation allocation = resource->getAllocation();
		return vmaMapMemory(m_vmaAllocator, allocation, ppData);
	}

	void VraAllocator_T::unmap(VraBufferResource resource)
	{
		vmaUnmapMemory(m_vmaAllocator, resource->getAllocation());
	}

	void VraAllocator_T::unmap(VraImageResource resource)
	{
		vmaUnmapMemory(m_vmaAllocator, resource->getAllocation());
	}

	VkResult vraCreateAllocator(
		const VraAllocatorCreateInfo* pCreateInfo,
		VraAllocator* pAllocator)
	{
		*pAllocator = new VraAllocator_T(pCreateInfo);
		return VK_SUCCESS;
	}

	VkResult vraCreateBuffer(
		VraAllocator allocator,
		const VkBufferCreateInfo* pBufferCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraBufferResource* pBufferResource)
	{
		return allocator->createBuffer(pBufferCreateInfo, pAllocationCreateInfo, pBufferResource);
	}

	VkResult vraCreateImage(
		VraAllocator allocator,
		const VkImageCreateInfo* pImageCreateInfo,
		const VraAllocationCreateInfo* pAllocationCreateInfo,
		VraImageResource* pImageResource)
	{
		return allocator->createImage(pImageCreateInfo, pAllocationCreateInfo, pImageResource);
	}

	VkResult vraMapBufferMemory(
		VraAllocator allocator,
		VraBufferResource resource,
		void** ppData)
	{
		return allocator->map(resource, ppData);
	}

	VkResult vraMapImageMemory(
		VraAllocator allocator,
		VraImageResource resource,
		void** ppData)
	{
		return allocator->map(resource, ppData);
	}

	void vraUnmapBufferMemory(
		VraAllocator allocator,
		VraBufferResource resource)
	{
		allocator->unmap(resource);
	}

	void vraUnmapImageMemory(
		VraAllocator allocator,
		VraImageResource resource)
	{
		allocator->unmap(resource);
	}


#endif // !VRA_IMPLEMENTATION

