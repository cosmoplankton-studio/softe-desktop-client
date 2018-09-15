/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkResourceManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


// internal
#include "vkDevice.h"
#include "vkManager.h"
#include "vkRenderManager.h"
#include "vkResourceManager.h"



namespace vulkan
{
    /*
    ***************************************************
    class VkBufferManager
    ***************************************************
    */

    ResourceManager::ResourceManager(Manager* manager)
        : p_manager(manager)
    {}

    vk::Result ResourceManager::initResourcePools()
    {
        auto vkResult = vk::Result::eSuccess;

        return vkResult;
    }


    vk::Result ResourceManager::attachSwapchainColorAttachment(RenderTarget* rendertarget, uint32_t swapchainIdx)
    {
        auto vkResult = vk::Result::eSuccess;

        auto imageViewCreateInfo = vk::ImageViewCreateInfo()
            .setImage(getManager().getRenderManager().getSwapchainImage(swapchainIdx))
            .setViewType(vk::ImageViewType::e2D)
            .setFormat(getManager().getGraphicsDevice().getDeviceProps().surfaceFormat)
            .setSubresourceRange(vk::ImageSubresourceRange(vk::ImageAspectFlagBits::eColor, 0, 1, 0, 1));

        // rendertarget->setImage(getManager().getRenderManager().getSwapchainImage(swapchainIdx));

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().createImageView(&imageViewCreateInfo, nullptr, rendertarget->imageviewPTR());
        assert(vkResult == vk::Result::eSuccess);

        rendertarget->setFormat(getManager().getGraphicsDevice().getDeviceProps().surfaceFormat);
        // rendertarget->setWidth(getManager().getAppManager()->getFrameWidth());
        // rendertarget->setHeight(getManager().getAppManager()->getFrameHeight());

        return vkResult;
    }


    vk::Result ResourceManager::allocateColorAttachment(RenderTarget* rendertarget)
    {
        auto vkResult = vk::Result::eSuccess;

        Device& device = getManager().getGraphicsDevice();
        VraAllocator allocator = device.getAllocator();
        
        /* initialization */
        size_t dataKEY = rendertarget->getDataKEY();
        p_imageResources[dataKEY].reset(new ResourceImage(&device));
        p_imageResources[dataKEY]->setFormat(getManager().getGraphicsDevice().getDeviceProps().surfaceFormat);
        p_imageResources[dataKEY]->setWidth(getManager().getAppManager()->getFrameWidth());
        p_imageResources[dataKEY]->setHeight(getManager().getAppManager()->getFrameHeight());

        auto const imageCreateInfo = vk::ImageCreateInfo()
            .setImageType(vk::ImageType::e2D)
            .setFormat(p_imageResources[dataKEY]->getFormat())
            .setExtent(p_imageResources[dataKEY]->getExtent())
            .setMipLevels(1)
            .setArrayLayers(1)
            .setSamples(vk::SampleCountFlagBits::e1)
            .setTiling(vk::ImageTiling::eOptimal)
            .setUsage(vk::ImageUsageFlagBits::eColorAttachment)
            .setSharingMode(vk::SharingMode::eExclusive)
            .setQueueFamilyIndexCount(0)
            .setPQueueFamilyIndices(nullptr)
            .setInitialLayout(vk::ImageLayout::eUndefined);

        VraAllocationCreateInfo allocationCreateInfo;
        pInitAllocationInfo(allocationCreateInfo);
        allocationCreateInfo.usage = utils::GET_VMAMEMORY_FROM_ACCESSQUALIFIER(device::DataAccessQualifier::eDeviceLocal);
        VraImageResource imageResource;
        vraCreateImage(allocator, reinterpret_cast<const VkImageCreateInfo*>(&imageCreateInfo), &allocationCreateInfo, &imageResource);
        p_imageResources[dataKEY]->init(imageResource);

        rendertarget->initAlias(p_imageResources[dataKEY].get());

        return vkResult;
    }


    vk::Result ResourceManager::allocateDepthAttachment(DepthData* depthData)
    {
        auto vkResult = vk::Result::eSuccess;

        Device& device = getManager().getGraphicsDevice();
        VraAllocator allocator = device.getAllocator();

        /* initialization */
        size_t dataKEY = depthData->getDataKEY();
        p_imageResources[dataKEY].reset(new ResourceImage(&device));		
        p_imageResources[dataKEY]->setFormat(vk::Format::eD16Unorm)
            .setWidth(getManager().getAppManager()->getFrameWidth())
            .setHeight(getManager().getAppManager()->getFrameHeight());

        auto const imageCreateInfo = vk::ImageCreateInfo()
            .setImageType(vk::ImageType::e2D)
            .setFormat(p_imageResources[dataKEY]->getFormat())
            .setExtent(p_imageResources[dataKEY]->getExtent())
            .setMipLevels(1)
            .setArrayLayers(1)
            .setSamples(vk::SampleCountFlagBits::e1)
            .setTiling(vk::ImageTiling::eOptimal)
            .setUsage(vk::ImageUsageFlagBits::eDepthStencilAttachment)
            .setSharingMode(vk::SharingMode::eExclusive)
            .setQueueFamilyIndexCount(0)
            .setPQueueFamilyIndices(nullptr)
            .setInitialLayout(vk::ImageLayout::eUndefined);

        VraAllocationCreateInfo allocationCreateInfo;
        pInitAllocationInfo(allocationCreateInfo);
        allocationCreateInfo.usage = utils::GET_VMAMEMORY_FROM_ACCESSQUALIFIER(device::DataAccessQualifier::eDeviceLocal);

        VraImageResource imageResource;
        vraCreateImage(allocator, reinterpret_cast<const VkImageCreateInfo*>(&imageCreateInfo), &allocationCreateInfo, &imageResource);

        p_imageResources[dataKEY]->init(imageResource);
        depthData->initAlias(p_imageResources[dataKEY].get());

        return vkResult;
    }

    vk::Result ResourceManager::allocateIndirectDrawCmd(DrawCmdIndirectInfo* drawCmd)
    {
        auto vkResult = vk::Result::eSuccess;

        /* #improvement - allow drawCount customization */
        uint32_t drawCount = 1;
        uint32_t dataStride = drawCmd->isIndexed ? sizeof(vk::DrawIndexedIndirectCommand) : sizeof(vk::DrawIndirectCommand);
        Device& device = getManager().getGraphicsDevice();
        VraAllocator allocator = device.getAllocator();

        /* initialization */
        size_t dataKEY = drawCmd->getDataKEY();
        p_bufferResources[dataKEY].reset(new ResourceBuffer(&device));
        p_bufferResources[dataKEY]->setLayout(DataLayout(dataStride))
            .setMaxUnitCount(drawCount)
            .setUsage(vk::BufferUsageFlagBits::eIndirectBuffer);

        /* allocation */
        auto const bufferCreateInfo = vk::BufferCreateInfo()
            .setUsage(p_bufferResources[dataKEY]->getUsage())
            .setSize(p_bufferResources[dataKEY]->getDataSize());

        //VkBufferCreateInfo bufferCreateInfo;
        //bufferCreateInfo.usage = ;
        //bufferCreateInfo.size = p_bufferResources[dataKEY]->getDataSize();

        VraAllocationCreateInfo allocationCreateInfo;
        pInitAllocationInfo(allocationCreateInfo);
        allocationCreateInfo.usage = utils::GET_VMAMEMORY_FROM_ACCESSQUALIFIER(device::DataAccessQualifier::eHostToDevice);

        VraBufferResource bufferResource;
        vraCreateBuffer(allocator, reinterpret_cast< const VkBufferCreateInfo*>(&bufferCreateInfo), &allocationCreateInfo, &bufferResource);

        p_bufferResources[dataKEY]->init(bufferResource);
        drawCmd->initAlias(p_bufferResources[dataKEY].get());

        return vkResult;
    }

    /*
    vk::Result ResourceManager::createResourceBuffer(ResourceBuffer *resourceBuffer)
    {
        auto vkResult = vk::Result::eSuccess;

        auto const bufCreateInfo = vk::BufferCreateInfo()
            .setSize(resourceBuffer->getSize())
            .setUsage(resourceBuffer->getUsage());

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().createBuffer(&bufCreateInfo, nullptr, resourceBuffer->createHere());
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }

    // #critical #todo - request memory from vkMemoryPoolManager 
    vk::Result ResourceManager::allocateResourceBuffer(ResourceBuffer *resourceBuffer)
    {
        auto vkResult = vk::Result::eSuccess;

        vk::MemoryRequirements memReqs;
        getManager().getGraphicsDevice().getLogicalDevice().getBufferMemoryRequirements(resourceBuffer->getBuffer(), &memReqs);
        auto memAlloc = vk::MemoryAllocateInfo().setAllocationSize(memReqs.size).setMemoryTypeIndex(0);

        resourceBuffer->setAllocationSize(memReqs.size);
        vkResult = getMemTypeIndexFromProperties(memReqs.memoryTypeBits, resourceBuffer->getMemoryProperty(), &memAlloc.memoryTypeIndex);
        assert(vkResult == vk::Result::eSuccess);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateMemory(&memAlloc, nullptr, resourceBuffer->allocateHere());
        assert(vkResult == vk::Result::eSuccess);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().bindBufferMemory(resourceBuffer->getBuffer(), resourceBuffer->getMemory(), resourceBuffer->getMemoryOffset());
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }
    */
    
    /*
    vk::Result ResourceManager::allocateUniformData(UniformData *uniformData, vk::BufferUsageFlagBits usage)
    {
        auto vkResult = vk::Result::eSuccess;

        // #critical #todo - request memory from vkBufferPool
        auto resource = new ResourceBuffer();
        resource->setTag(uniformData->getTag());
        resource->setSize(uniformData->getDataSize());
        resource->setUsage(usage);
        createResourceBuffer(resource);
        allocateResourceBuffer(resource);

        uniformData->setResourceBuffer(resource);
        uniformData->setBufferOffset(0);

        return vkResult;
    }
    */

    vk::Result ResourceManager::loadBufferData(ResourceBuffer *bufferData, void *inputData, uint32_t bufSize)
    {
        auto vkResult = vk::Result::eSuccess;

        auto memData = pMapBufferMemory(bufferData);
        VERIFY(memData.result == vk::Result::eSuccess);
        vkResult = memData.result;

        memcpy(memData.value, inputData, bufSize);

        pUnmapBufferMemory(bufferData);

        return vkResult;
    }

    /* #critical #todo - request memory from vkMemoryPoolManager
    vk::Result ResourceManager::allocateResourceImage(TextureData* resourceImage)
    {
        auto vkResult = vk::Result::eSuccess;

        vk::MemoryRequirements memReqs;
        getManager().getGraphicsDevice().getLogicalDevice().getImageMemoryRequirements(resourceImage->getImage(), &memReqs);
        auto memAlloc = vk::MemoryAllocateInfo().setAllocationSize(memReqs.size).setMemoryTypeIndex(0);

        resourceImage->setAllocationSize(memReqs.size);
        vkResult = getMemTypeIndexFromProperties(memReqs.memoryTypeBits, resourceImage->getMemoryProperty(), &memAlloc.memoryTypeIndex);
        assert(vkResult == vk::Result::eSuccess);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateMemory(&memAlloc, nullptr, resourceImage->allocateHere());
        assert(vkResult == vk::Result::eSuccess);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().bindImageMemory(resourceImage->getImage(), resourceImage->getMemory(), resourceImage->getMemoryOffset());
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }
    */

    vk::Result ResourceManager::loadImageData(ResourceImage *imageData, void *inputData)
    {
        auto vkResult = vk::Result::eSuccess;

        auto const imageSubResource = vk::ImageSubresource()
            .setAspectMask(vk::ImageAspectFlagBits::eColor)
            .setMipLevel(0)
            .setArrayLayer(0);
        vk::SubresourceLayout subResLayout;
        imageData->getDevice()->getLogicalDevice().getImageSubresourceLayout(imageData->getImage(), &imageSubResource, &subResLayout);

        auto memData = pMapImageMemory(imageData);
        VERIFY(memData.result == vk::Result::eSuccess);
        vkResult = memData.result;

        uint8_t *inputPtr = static_cast<uint8_t*>(inputData);
        uint8_t *rgbaData = static_cast<uint8_t*>(memData.value);
        uint32_t stride = utils::GET_SIZE_FROM_VKFORMAT(imageData->getFormat());

        // #todo - add the depth loop
        for (uint32_t y = 0; y < imageData->getExtent().height; ++y)
        {
            uint8_t *rowPtr = rgbaData;

            for (uint32_t x = 0; x < imageData->getExtent().width; ++x)
            {
                memcpy(rowPtr, inputPtr, stride);
                inputPtr += stride;
                rowPtr += stride;
            }

            rgbaData += subResLayout.rowPitch;
        }

        pUnmapImageMemory(imageData);

        return vkResult;
    }

    /*
    vk::Result ResourceManager::createTextureImage(TextureData* textureData)
    {
        auto vkResult = vk::Result::eSuccess;

        vk::FormatProperties formatProps;
        getManager().getGraphicsDevice().getPhysicalDevice().getFormatProperties(textureData->getFormat(), &formatProps);

        if (formatProps.linearTilingFeatures & vk::FormatFeatureFlagBits::eSampledImage)
        {
            auto const imageCreateInfo = vk::ImageCreateInfo()
                .setImageType(vk::ImageType::e2D)
                .setFormat(textureData->getFormat())
                .setExtent({ textureData->getWidth(), textureData->getHeight(), 1 })
                .setMipLevels(1)
                .setArrayLayers(1)
                .setSamples(vk::SampleCountFlagBits::e1)
                .setTiling(textureData->getTiling())
                .setUsage(textureData->getUsage())
                .setSharingMode(vk::SharingMode::eExclusive)
                .setQueueFamilyIndexCount(0)
                .setPQueueFamilyIndices(nullptr)
                .setInitialLayout(vk::ImageLayout::ePreinitialized);

            vkResult = getManager().getGraphicsDevice().getLogicalDevice().createImage(&imageCreateInfo, nullptr, textureData->createImageHere());
            assert(vkResult == vk::Result::eSuccess);

            DEBUG_markObject(debug::getImageRef(textureData->getImage()), textureData->getTag().c_str(), vk::DebugReportObjectTypeEXT::eImage, debug::getDeviceRef(getManager().getGraphicsDevice().getLogicalDevice()));
        }

        return vkResult;
    }
    */

    vk::Result ResourceManager::createImageSampler(ImageDataAlias* imageData)
    {
        auto vkResult = vk::Result::eSuccess;

        auto const samplerInfo = vk::SamplerCreateInfo()
            .setMagFilter(vk::Filter::eNearest)
            .setMinFilter(vk::Filter::eNearest)
            .setMipmapMode(vk::SamplerMipmapMode::eLinear)
            .setAddressModeU(vk::SamplerAddressMode::eClampToEdge)
            .setAddressModeV(vk::SamplerAddressMode::eClampToEdge)
            .setAddressModeW(vk::SamplerAddressMode::eClampToEdge)
            .setMipLodBias(0.0f)
            .setAnisotropyEnable(VK_FALSE)
            .setMaxAnisotropy(1.0)
            .setCompareEnable(VK_FALSE)
            .setCompareOp(vk::CompareOp::eNever)
            .setMinLod(0.0f)
            .setMaxLod(0.0f)
            .setBorderColor(vk::BorderColor::eFloatOpaqueWhite)
            .setUnnormalizedCoordinates(VK_FALSE);

        vkResult = imageData->data()->getDevice()->getLogicalDevice().createSampler(&samplerInfo, nullptr, imageData->samplerPTR());
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }

    vk::Result ResourceManager::createImageView(ImageDataAlias* imageData)
    {
        auto vkResult = vk::Result::eSuccess;

        auto const viewInfo = vk::ImageViewCreateInfo()
            .setImage(imageData->data()->getImage())
            .setViewType(imageData->getImageViewType())
            .setFormat(imageData->data()->getFormat())
            .setSubresourceRange(imageData->getSubresourceRange());

        vkResult = imageData->data()->getDevice()->getLogicalDevice().createImageView(&viewInfo, nullptr, imageData->imageviewPTR());
        assert(vkResult == vk::Result::eSuccess);

        // DEBUG_markObject(debug::getImageViewRef(imageData->getImageView()), "imageview", vk::DebugReportObjectTypeEXT::eImageView, debug::getDeviceRef(getManager().getGraphicsDevice().getLogicalDevice()));

        return vkResult;
    }

    vk::Result ResourceManager::createDescriptorPool()
    {
        auto vkResult = vk::Result::eSuccess;
        
        auto texCount = getManager().getRenderManager().getMaxTextureCount();
        auto uniformCount = getManager().getRenderManager().getMaxUniformCount();
        auto swapchainImageCount = getManager().getRenderManager().getSwapchainImageCount();

        vk::DescriptorPoolSize const poolSizes[2] = {
            vk::DescriptorPoolSize().setType(vk::DescriptorType::eUniformBuffer).setDescriptorCount(swapchainImageCount * uniformCount),
            vk::DescriptorPoolSize().setType(vk::DescriptorType::eCombinedImageSampler).setDescriptorCount(swapchainImageCount * texCount)
        };

        auto const descPoolCreateInfo = vk::DescriptorPoolCreateInfo()
            .setMaxSets(swapchainImageCount)
            .setPoolSizeCount(2)
            .setPPoolSizes(poolSizes);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().createDescriptorPool(&descPoolCreateInfo, nullptr, &p_DescPool);
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }

    vk::Result ResourceManager::allocateDescriptorSet(vk::DescriptorSetLayout const *descLayout, vk::DescriptorSet *descSet)
    {
        auto vkResult = vk::Result::eSuccess;

        auto const descSetAllocInfo = vk::DescriptorSetAllocateInfo()
            .setDescriptorPool(p_DescPool)
            .setDescriptorSetCount(1)
            .setPSetLayouts(descLayout);

        vkResult = getManager().getGraphicsDevice().getLogicalDevice().allocateDescriptorSets(&descSetAllocInfo, descSet);
        assert(vkResult == vk::Result::eSuccess);

        return vkResult;
    }

    vk::Result ResourceManager::getMemTypeIndexFromProperties(uint32_t typeBits, vk::MemoryPropertyFlags propFlags, uint32_t *typeIndex)
    {
        vk::Result vkResult = vk::Result::eSuccess;
        
        for (uint32_t i = 0; i < VK_MAX_MEMORY_TYPES; ++i)
        {
            if ((typeBits & 1) == 1)
            {
                if ((getManager().getGraphicsDevice().getDeviceProps().memoryProps.memoryTypes[i].propertyFlags & propFlags) == propFlags)
                {
                    *typeIndex = i;
                    return vkResult;
                }
            }

            typeBits >>= 1;
        }

        return vkResult;
    }


    /*
    *********************************
    * protected methods
    *********************************
    */
    vk::Result ResourceManager::pAllocateResource(
        size_t dataKEY,
        graphics::StageBufferDataDescription const& dataDescription,
        vk::BufferUsageFlags usage,
        bool forceCreate /*= false*/)
    {
        vk::Result vkResult = vk::Result::eSuccess;
        
        if (!forceCreate && p_bufferResources.find(dataKEY) != p_bufferResources.end())
            return vkResult;

        Device& device = getManager().getGraphicsDevice();
        VraAllocator allocator = device.getAllocator();

        p_bufferResources[dataKEY].reset(new ResourceBuffer(&device));
        p_bufferResources[dataKEY]->setUsage(usage)
            .setLayout(DataLayout(dataDescription.getDataAttributes()))
            .setMaxUnitCount(dataDescription.getMaxCount());

        auto const bufferCreateInfo = vk::BufferCreateInfo()
            .setUsage(p_bufferResources[dataKEY]->getUsage())
            .setSize(p_bufferResources[dataKEY]->getDataSize());
        
        //VkBufferCreateInfo bufferCreateInfo;
        //bufferCreateInfo.usage = static_cast<VkBufferUsageFlags>(p_bufferResources[dataKEY]->getUsage());
        //bufferCreateInfo.size = p_bufferResources[dataKEY]->getDataSize();

        VraAllocationCreateInfo allocationCreateInfo;
        pInitAllocationInfo(allocationCreateInfo);
        allocationCreateInfo.usage = utils::GET_VMAMEMORY_FROM_ACCESSQUALIFIER(dataDescription.getDataAccessQualifier());

        VraBufferResource bufferResource;
        vraCreateBuffer(allocator, reinterpret_cast<const VkBufferCreateInfo*>(&bufferCreateInfo), &allocationCreateInfo, &bufferResource);

        p_bufferResources[dataKEY]->init(bufferResource);

        return vkResult;
    }

    vk::Result ResourceManager::pAllocateResource(
        size_t dataKEY,
        graphics::StageImageDataDescription const& dataDescription,
        vk::ImageUsageFlags usage,
        bool forceCreate /*= false*/)
    {
        vk::Result vkResult = vk::Result::eSuccess;
        
        if (!forceCreate && p_imageResources.find(dataKEY) != p_imageResources.end())
            return vkResult;

        Device& device = getManager().getGraphicsDevice();
        VraAllocator allocator = device.getAllocator();

        p_imageResources[dataKEY].reset(new ResourceImage(&device));

        p_imageResources[dataKEY]->setFormat(utils::GET_VKFORMAT_FROM_DATAFORMAT(dataDescription.getDataFormat()))
            .setExtent({ dataDescription.getWidth(), dataDescription.getHeight(), dataDescription.getDepth() })
            .setUsage(usage);

        vk::FormatProperties formatProps;
        getManager().getGraphicsDevice().getPhysicalDevice().getFormatProperties(p_imageResources[dataKEY]->getFormat(), &formatProps);

        if (formatProps.linearTilingFeatures & vk::FormatFeatureFlagBits::eSampledImage)
        {
            auto const imageCreateInfo = vk::ImageCreateInfo()
                .setImageType(vk::ImageType::e2D)
                .setFormat(p_imageResources[dataKEY]->getFormat())
                .setExtent(p_imageResources[dataKEY]->getExtent())
                .setMipLevels(1)
                .setArrayLayers(1)
                .setSamples(vk::SampleCountFlagBits::e1)
                .setTiling(p_imageResources[dataKEY]->getTiling())
                .setUsage(p_imageResources[dataKEY]->getUsage())
                .setSharingMode(vk::SharingMode::eExclusive)
                .setQueueFamilyIndexCount(0)
                .setPQueueFamilyIndices(nullptr)
                .setInitialLayout(vk::ImageLayout::ePreinitialized);

            VraAllocationCreateInfo allocationCreateInfo;
            pInitAllocationInfo(allocationCreateInfo);
            allocationCreateInfo.usage = utils::GET_VMAMEMORY_FROM_ACCESSQUALIFIER(dataDescription.getDataAccessQualifier());

            VraImageResource imageResource;
            vraCreateImage(allocator, reinterpret_cast<const VkImageCreateInfo*>(&imageCreateInfo), &allocationCreateInfo, &imageResource);

            p_imageResources[dataKEY]->init(imageResource);
        }

        return vkResult;
    }

    
    
} // end  namespace vulkan