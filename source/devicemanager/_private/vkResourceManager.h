/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkResourceManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VULKAN_BUFFERMMANAGER
#define VULKAN_BUFFERMMANAGER


#include "vkDefines.h"
#include "vkDevice.h"
#include "vkResources.h"


namespace vulkan
{
	
	/**
	* @class   vkResourceManager
	* @brief   Device Buffer Manager for VULKAN API.
	*
	*/
	class ResourceManager
	{
		public:

			ResourceManager(Manager* manager);

			virtual ~ResourceManager()
			{}

			inline Manager &getManager() const
			{
				return *p_manager;
			}

			/* resource helpers */
			vk::Result initResourcePools();

			template<typename T>
			inline T* getResource(size_t dataKEY);

			template<>
			inline typename ResourceBuffer* getResource<ResourceBuffer>(size_t dataKEY)
			{
				return p_bufferResources[dataKEY].get();
			}

			template<>
			inline typename ResourceImage* getResource<ResourceImage>(size_t dataKEY)
			{
				return p_imageResources[dataKEY].get();
			}

			template<typename T>
			inline T* getResource(std::string const& tag)
			{
				size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(tag);
				return getResource<T>(dataKEY);
			}

			template<typename T>
			inline T* getResource(std::string const& tag, uint32_t swapchainIdx)
			{
				size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(tag, swapchainIdx);
				return getResource<T>(dataKEY);
			}

			/* special buffers and attachment helpers */
			vk::Result attachSwapchainColorAttachment(RenderTarget* rendertarget, uint32_t swapchainIdx);
			vk::Result allocateColorAttachment(RenderTarget* rendertarget);
			vk::Result allocateDepthAttachment(DepthData* depthData);
			vk::Result allocateIndirectDrawCmd(DrawCmdIndirectInfo* drawCmd);

			/* uniform helpers */
			vk::Result loadBufferData(ResourceBuffer *uniformData, void *inputData, uint32_t bufSize);
			
			template<device::DataDescription T>
			vk::Result createResource(typename data_alias_traits<T>::descriptiontype const& dataDescription, bool forceCreate = false)
			{
				auto vkResult = vk::Result::eSuccess;

				auto& dataTag = dataDescription.getTag();
				switch (dataDescription.getDataUpdateScheme())
				{
				case graphics::DataUpdateScheme::eFrameStatic:
				{
					size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(dataTag);
					vkResult = pAllocateResource(dataKEY, dataDescription, data_alias_traits<T>::usage);
				}
				break;

				case graphics::DataUpdateScheme::eFrameDynamic:
				{
					uint32_t swapchainCount = getManager().getRenderManager().getSwapchainImageCount();
					for (uint32_t idx = 0; idx < swapchainCount; ++idx)
					{
						size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(dataTag, idx);
						vkResult = pAllocateResource(dataKEY, dataDescription, data_alias_traits<T>::usage);
					}
				}
				break;

				default:VERIFY(0);
				}

				return vkResult;
			}

			/* texture helpers */
			vk::Result loadImageData(ResourceImage *textureData, void *inputData);
			vk::Result allocateResourceImage(TextureData* resourceImage);
			vk::Result createImageView(ImageDataAlias* imageData);
			vk::Result createImageSampler(ImageDataAlias* textureData);

			/* descriptor helpers */
			vk::Result createDescriptorPool();
			vk::Result allocateDescriptorSet(vk::DescriptorSetLayout const *descLayout, vk::DescriptorSet *descSet);

			/* common helpers */
			vk::Result getMemTypeIndexFromProperties(uint32_t typeBits, vk::MemoryPropertyFlags propFlags, uint32_t *typeIndex);

		protected:
			vk::Result pAllocateResource(size_t dataKEY, graphics::StageBufferDataDescription const& dataDescription, vk::BufferUsageFlags usage, bool forceCreate = false);
			vk::Result pAllocateResource(size_t dataKEY, graphics::StageImageDataDescription const& dataDescription, vk::ImageUsageFlags usage, bool forceCreate = false);


			vk::ResultValueType<void*>::type pMapBufferMemory(ResourceBuffer* resource)
			{
				void* pData;
				vk::Result result = static_cast<vk::Result>(vraMapBufferMemory(resource->getDevice()->getAllocator(), resource->resource(), &pData));
				return vk::createResultValue(result, pData, "vulkan::ResourceManager::pMapBufferMemory");
			}

			vk::ResultValueType<void*>::type pMapImageMemory(ResourceImage* resource)
			{
				void* pData;
				vk::Result result = static_cast<vk::Result>(vraMapImageMemory(resource->getDevice()->getAllocator(), resource->resource(), &pData));
				return vk::createResultValue(result, pData, "vulkan::ResourceManager::pMapImageMemory");
			}

			void pUnmapBufferMemory(ResourceBuffer* resource)
			{
				vraUnmapBufferMemory(resource->getDevice()->getAllocator(), resource->resource());
			}

			void pUnmapImageMemory(ResourceImage* resource)
			{
				vraUnmapImageMemory(resource->getDevice()->getAllocator(), resource->resource());
			}

			void pInitAllocationInfo(VraAllocationCreateInfo &info)
			{
				info.flags = 0;
				info.memoryTypeBits = 0;
				info.pool = VK_NULL_HANDLE;
				info.preferredFlags = 0;
				info.pUserData = NULL;
				info.requiredFlags = 0;
				info.usage = VMA_MEMORY_USAGE_UNKNOWN;
			}

		protected:
			Manager*				p_manager;
			vk::DescriptorPool		p_DescPool;

			std::unordered_map<size_t, ResourceImageHandle> p_imageResources;
			std::unordered_map<size_t, ResourceBufferHandle> p_bufferResources;
	};


} // end namespace vulkan


#endif // !VULKAN_BUFFERMMANAGER
