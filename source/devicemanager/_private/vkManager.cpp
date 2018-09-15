/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "vkDevice.h"
#include "vkManager.h"
#include "vkRenderPass.h"
#include "vkResourceManager.h"
#include "vkRenderManager.h"
#include "vkCmdBufferManager.h"


DEBUG_staticinit


namespace vulkan
{

    /*
    ---------------------------------------------------
    class VkManager
    ---------------------------------------------------
    */

    Manager::Manager(graphics::I_GraphicsAppManager* gAppManager, device::HostPtr hostPtr)
        : p_gAppManager(gAppManager)
        , p_cAppManager(nullptr)
        , p_hostPtr(hostPtr)
        , p_vkInstance(nullptr)
        , p_apiType(device::DeviceApiType::eVULKAN)
    { 
        pInitManagers();
    }

    Manager::Manager(compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr)
        : p_gAppManager(nullptr)
        , p_cAppManager(cAppManager)
        , p_hostPtr(hostPtr)
        , p_vkInstance(nullptr)
        , p_apiType(device::DeviceApiType::eVULKAN)
    {
        pInitManagers();
    }

    Manager::Manager(graphics::I_GraphicsAppManager* gAppManager, compute::I_ComputeAppManager* cAppManager, device::HostPtr hostPtr)
        : p_gAppManager(gAppManager)
        , p_cAppManager(cAppManager)
        , p_hostPtr(hostPtr)
        , p_vkInstance(nullptr)
        , p_apiType(device::DeviceApiType::eVULKAN)
    {
        pInitManagers();
    }

    Manager::~Manager()
    {
        delete p_bufferManager;
        delete p_renderManager;
        delete p_cmdBufferManager;
    }


    int Manager::initInstanceAndDevices()
    {
        auto vkResult = vk::Result::eSuccess;
    
        vkResult = pInitInstance();
        vkResult = pInitDevices();

        vkResult = getCommandManager().initGraphicsCmdPool();
        vkResult = getCommandManager().InitPresentCmdPool();
        vkResult = getCommandManager().InitPrimaryGraphicsCmdBuf();
        vkResult = getCommandManager().InitPrimaryPresentCmdBuf();
        vkResult = getCommandManager().AllocateSwapchainCmdBuffers();

        vkResult = getRenderManager().initRenderResources();
        vkResult = getResourceManager().createDescriptorPool();

        return (int)vkResult;
    }


    int Manager::initApplicationGraphicsPipeline(graphics::AppGraphicsPipelineHandle& appGraphicsPipeline)
    {
        auto vkResult = vk::Result::eSuccess;

        vkResult = getRenderManager().initRenderPipeline(appGraphicsPipeline);

        return (int)vkResult;
    }


    int Manager::frameDraw()
    {
        auto vkResult = vk::Result::eSuccess;

        vkResult = getRenderManager().frameDraw();

        return (int)vkResult;
    }

    
    int Manager::resizeGraphicsResources()
    {
        auto vkResult = vk::Result::eSuccess;

        vkResult = getRenderManager().resizeResources();

        return (int)vkResult;
    }

    vk::Result Manager::pInitManagers()
    {
        auto vkResult = vk::Result::eSuccess;

        p_bufferManager = new ResourceManager(this);
        p_renderManager = new RenderManager(this);
        p_cmdBufferManager = new CmdBufferManager(this);

        return vkResult;
    }


    vk::Result Manager::pInitInstance()
    {
        auto vkResult = vk::Result::eSuccess;

        p_instanceProps.enabledExtensionCount = 0;
        p_instanceProps.enabledLayerCount = 0;
        p_instanceProps.validationLayers = true;

        if (p_instanceProps.validationLayers)
        {
            pInitValidationLayers();
        }

        pInitInstanceExtensions();

        // Initialize the vulkan instance
        auto const appInfo = vk::ApplicationInfo()
            .setPApplicationName("softStudio")
            .setApplicationVersion(0)
            .setPEngineName("softStudio")
            .setEngineVersion(0)
            .setApiVersion(VK_API_VERSION_1_0);

        auto const instInfo = vk::InstanceCreateInfo()
            .setPApplicationInfo(&appInfo)
            .setEnabledLayerCount(p_instanceProps.enabledLayerCount)
            .setPpEnabledLayerNames(p_instanceProps.getEnabledValidationLayers())
            .setEnabledExtensionCount(p_instanceProps.enabledExtensionCount)
            .setPpEnabledExtensionNames(p_instanceProps.getEnabledExtensionNames());

        vkResult = vk::createInstance(&instInfo, nullptr, &p_vkInstance);

        if (vkResult != vk::Result::eSuccess)
        {
            std::string _logInfo_ = LOG_HEADER() + " Vulkan instance creation failed.";
            THROW_EXCEPTION(device::init_error("Vulkan instance creation failed."));
        }

    #if defined(VK_USE_PLATFORM_WIN32_KHR)
        /* #improvement - implement batch mode checks */
        {
            auto const createInfo = vk::Win32SurfaceCreateInfoKHR()
                .setHinstance(static_cast< HINSTANCE >(getAppManager()->getAppConnection()))
                .setHwnd(static_cast< HWND >(getAppManager()->getAppWindow()));

            vkResult = p_vkInstance.createWin32SurfaceKHR(&createInfo, nullptr, &p_vkSurface);
            assert(vkResult == vk::Result::eSuccess);
        }
    #endif

        return vkResult;
    }


    vk::Result Manager::pInitDevices()
    {
        auto vkResult = vk::Result::eSuccess;

        p_graphicsDeviceIdx = UINT32_MAX;
        uint32_t gpuCount = 0;
        vkResult = p_vkInstance.enumeratePhysicalDevices(&gpuCount, nullptr);
        assert(vkResult == vk::Result::eSuccess && gpuCount > 0);

        if (gpuCount < 1)
        {
            std::string _logInfo_ = LOG_HEADER() + " No Vulkan compatible accelerated device available.";
            THROW_EXCEPTION(device::init_error("No Vulkan compatible accelerated device available."));  /* #improvement - implement fallback cpu pipeline */
        }

        std::vector< vk::PhysicalDevice > physicalDevices;
        physicalDevices.resize(gpuCount);

        vkResult = p_vkInstance.enumeratePhysicalDevices(&gpuCount, physicalDevices.data());
        assert(vkResult == vk::Result::eSuccess);

        for (size_t gpuIdx = 0; gpuIdx < gpuCount; ++gpuIdx)
        {
            size_t poolSize = p_devicePool.size();
            std::unique_ptr< Device > vulkanDevice(new Device(poolSize, device::DeviceType::eGPU));
            vulkanDevice->setPhysicalDevice(physicalDevices[gpuIdx]);

            if (!pCheckDeviceMinRequirements(vulkanDevice.get())) continue;

            p_devicePool.push_back(vulkanDevice.release());

            p_graphicsDeviceIdx = poolSize;
            p_computeDeviceIdx = poolSize;
            break; // #critical #todo - support multiple devices
        }

        if (p_graphicsDeviceIdx != UINT32_MAX)
        {
            pInitDeviceQueueFamily(p_graphicsDeviceIdx);
            pInitSurfaceFormat(p_graphicsDeviceIdx);
            pCreateLogicalDevice(p_graphicsDeviceIdx);
            pCreateDeviceMemoryAllocator(p_graphicsDeviceIdx);
        }
        else
        {
            std::string _logInfo_ = LOG_HEADER() + " No Vulkan compatible accelerated device found.";
            THROW_EXCEPTION(device::init_error("No Vulkan compatible accelerated device found."));
        }

        return vkResult;
    }


    vk::Result Manager::pInitValidationLayers()
    {
        auto vkResult = vk::Result::eSuccess;

        uint32_t instanceLayerCount = 0;
        uint32_t validationLayerCount = 0;

        bool validationFound = true;
        char const *const *instanceValidationLayers = nullptr;
        std::vector< std::string > requiredInstanceValidationLayers = { "VK_LAYER_LUNARG_standard_validation" };

        vkResult = vk::enumerateInstanceLayerProperties(&instanceLayerCount, nullptr);
        assert(vkResult == vk::Result::eSuccess);

        if (instanceLayerCount > 0)
        {
            std::vector< vk::LayerProperties > instanceLayers;
            instanceLayers.resize(instanceLayerCount);
            vkResult = vk::enumerateInstanceLayerProperties(&instanceLayerCount, instanceLayers.data());
            assert(vkResult == vk::Result::eSuccess);

            for (auto &pReqLayer : requiredInstanceValidationLayers)
            {
                bool layerFound = false;
                for (auto &pInstLayer : instanceLayers)
                {
                    if (pReqLayer == pInstLayer.layerName)
                    {
                        layerFound = true;
                        break;
                    }
                }
                if (!layerFound)
                {
                    validationFound = false;
                    break;
                }
            }

            if (validationFound)
            {
                p_instanceProps.enabledLayerCount = requiredInstanceValidationLayers.size();
                p_instanceProps.enabledValidationLayers.insert(
                    p_instanceProps.enabledValidationLayers.end(),
                    requiredInstanceValidationLayers.begin(),
                    requiredInstanceValidationLayers.end()
                );
            }
        }

        if (!validationFound)
        {
            std::string _logInfo_ = LOG_HEADER() + " Validation layers not found.";
        }

        return vkResult;
    }


    vk::Result Manager::pInitInstanceExtensions()
    {
        auto vkResult = vk::Result::eSuccess;
    
        // Look for instance extensions (surface extension for the application window)
        uint32_t instanceExtensionCount = 0;
        bool surfaceExtFound = true;

        vkResult = vk::enumerateInstanceExtensionProperties(nullptr, &instanceExtensionCount, nullptr);
        assert(vkResult == vk::Result::eSuccess);

        /* #improvement - get VK_KHR_WIN32_SURFACE_EXTENSION_NAME from appManager to remove win32 dependency */
        std::vector< std::string > requiredExtensionNames = { VK_KHR_SURFACE_EXTENSION_NAME , VK_KHR_WIN32_SURFACE_EXTENSION_NAME };

        if (instanceExtensionCount > 0)
        {
            std::vector< vk::ExtensionProperties > instanceExtensions;
            instanceExtensions.resize(instanceExtensionCount);
            vkResult = vk::enumerateInstanceExtensionProperties(nullptr, &instanceExtensionCount, instanceExtensions.data());
            assert(vkResult == vk::Result::eSuccess);

            for (auto &pReqExtn : requiredExtensionNames)
            {
                bool extnFound = false;
                for (auto &pInstExtn : instanceExtensions)
                {
                    if (pReqExtn == pInstExtn.extensionName)
                    {
                        extnFound = true;
                        break;
                    }
                }
                if (!extnFound)
                {
                    surfaceExtFound = false;
                    break;
                }
            }

            if (surfaceExtFound)
            {
                p_instanceProps.enabledExtensionCount = requiredExtensionNames.size();
                p_instanceProps.enabledExtensionNames.insert(
                    p_instanceProps.enabledExtensionNames.end(),
                    requiredExtensionNames.begin(),
                    requiredExtensionNames.end()
                );
            }
        }

        if (!surfaceExtFound)
        {
            std::string _logInfo_ = LOG_HEADER() + " Vulkan instance extension(s) not found.";
            THROW_EXCEPTION(device::init_error("Vulkan instance extension(s) not found."));
        }

        return vkResult;
    }


    vk::Bool32 Manager::pCheckDeviceMinRequirements(Device* vkDevice)
    {
        uint32_t deviceExtensionCount = 0;
        bool swapchainExtFound = true;

        auto vkResult = vkDevice->getPhysicalDevice().enumerateDeviceExtensionProperties(nullptr, &deviceExtensionCount, nullptr);
        assert(vkResult == vk::Result::eSuccess);

        if (deviceExtensionCount > 0)
        {
            std::vector< vk::ExtensionProperties > deviceExtensions;
            deviceExtensions.resize(deviceExtensionCount);
            vkResult = vkDevice->getPhysicalDevice().enumerateDeviceExtensionProperties(nullptr, &deviceExtensionCount, deviceExtensions.data());
            assert(vkResult == vk::Result::eSuccess);

            std::vector< std::string > requiredDeviceExtensions;
            
            if (::debug::MARKER::isOn())
            {
                requiredDeviceExtensions = ::debug::MARKER::getRequiredDeviceExtensions();
            }
            else
            {
                requiredDeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
            }

            for (auto &pReqExtn : requiredDeviceExtensions)
            {
                bool extnFound = false;
                for (auto &pDeviceExtn : deviceExtensions)
                {
                    if (pReqExtn == pDeviceExtn.extensionName)
                    {
                        extnFound = true;
                        break;
                    }
                }
                if (!extnFound)
                {
                    swapchainExtFound = false;
                    break;
                }
            }

            if (swapchainExtFound)
            {
                vkDevice->getDeviceProps().enabledDeviceExtensionCount = requiredDeviceExtensions.size();
                vkDevice->getDeviceProps().enabledDeviceExtensionNames.insert(
                    vkDevice->getDeviceProps().enabledDeviceExtensionNames.end(),
                    requiredDeviceExtensions.begin(),
                    requiredDeviceExtensions.end()
                );
            }
        }

        if (!swapchainExtFound)
        {
            return VK_FALSE;
        }

        return VK_TRUE;
    }


    vk::Result Manager::pInitDeviceQueueFamily(uint32_t deviceId)
    {
        auto vkResult = vk::Result::eSuccess;
    
        vk::PhysicalDevice vkPhysicalDevice = getDevice(deviceId).getPhysicalDevice();
        DeviceProperties &vkDeviceProps = getDevice(deviceId).getDeviceProps();

        vkPhysicalDevice.getProperties(&(vkDeviceProps.physDevProps));
        vkPhysicalDevice.getQueueFamilyProperties(&(vkDeviceProps.queueFamilyCount), nullptr);
        assert(vkDeviceProps.queueFamilyCount >= 1);

        vkDeviceProps.queueProps.resize(vkDeviceProps.queueFamilyCount);
        vkPhysicalDevice.getQueueFamilyProperties(&(vkDeviceProps.queueFamilyCount), vkDeviceProps.queueProps.data());
        vkPhysicalDevice.getFeatures(&(vkDeviceProps.physDevFeatures));

        std::unique_ptr< vk::Bool32[] > queueFamilySupportsPresent(new vk::Bool32[vkDeviceProps.queueFamilyCount]);
        for (auto i = 0; i < vkDeviceProps.queueFamilyCount; ++i)
        {
            vkPhysicalDevice.getSurfaceSupportKHR(i, p_vkSurface, &queueFamilySupportsPresent[i]);
        }

        uint32_t graphicsQueueFamilyIndex = UINT32_MAX;
        uint32_t presentQueueFamilyIndex = UINT32_MAX;
        for (auto i = 0; i < vkDeviceProps.queueFamilyCount; ++i)
        {
            if (vkDeviceProps.queueProps[i].queueFlags & vk::QueueFlagBits::eGraphics)
            {
                if (graphicsQueueFamilyIndex == UINT32_MAX)
                {
                    graphicsQueueFamilyIndex = i;
                }

                if (queueFamilySupportsPresent[i] == VK_TRUE)
                {
                    graphicsQueueFamilyIndex = i;
                    presentQueueFamilyIndex = i;
                    break;
                }
            }
        }

        if (presentQueueFamilyIndex == UINT32_MAX)
        {
            for (auto i = 0; i < vkDeviceProps.queueFamilyCount; ++i)
            {
                if (queueFamilySupportsPresent[i] == VK_TRUE)
                {
                    presentQueueFamilyIndex = i;
                    break;
                }
            }
        }

        /* #todo - take care of batch mode */
        if (graphicsQueueFamilyIndex == UINT32_MAX || presentQueueFamilyIndex == UINT32_MAX)
        {
            std::string _logInfo_ = LOG_HEADER() + " Device Queue Initialization Failed.";
            THROW_EXCEPTION(device::init_error("Vulkan Device Queue Initialization Failed."));
        }

        vkDeviceProps.graphicsQueueFamilyIndex = graphicsQueueFamilyIndex;
        vkDeviceProps.presentQueueFamilyIndex = presentQueueFamilyIndex;
        vkDeviceProps.separatePresentQueue = graphicsQueueFamilyIndex != presentQueueFamilyIndex ? true : false;

        vkPhysicalDevice.getMemoryProperties(&(vkDeviceProps.memoryProps));

        return vkResult;
    }


    vk::Result Manager::pInitSurfaceFormat(uint32_t deviceId)
    {
        auto vkResult = vk::Result::eSuccess;

        vk::PhysicalDevice vkPhysicalDevice = getDevice(deviceId).getPhysicalDevice();
        DeviceProperties &vkDeviceProps = getDevice(deviceId).getDeviceProps();
    
        uint32_t formatCount;
        vkResult = vkPhysicalDevice.getSurfaceFormatsKHR(p_vkSurface, &formatCount, nullptr);
        assert(vkResult == vk::Result::eSuccess);

        std::vector< vk::SurfaceFormatKHR > surfFormats;
        surfFormats.resize(formatCount);
        vkResult = vkPhysicalDevice.getSurfaceFormatsKHR(p_vkSurface, &formatCount, surfFormats.data());
        assert(vkResult == vk::Result::eSuccess);

        if (formatCount == 1 && surfFormats[0].format == vk::Format::eUndefined)
        {
            vkDeviceProps.surfaceFormat = vk::Format::eB8G8R8A8Unorm;
        }
        else
        {
            assert(formatCount >= 1);
            vkDeviceProps.surfaceFormat = surfFormats[0].format;
        }

        vkDeviceProps.surfaceColorSpace = surfFormats[0].colorSpace;

        return vkResult;
    }


    vk::Result Manager::pCreateLogicalDevice(uint32_t deviceId)
    {
        auto vkResult = vk::Result::eSuccess;
    
        float const queuePriorities[1] = { 0.0 };
        std::array< vk::DeviceQueueCreateInfo, 2 > deviceQueues;
        uint32_t queueCreateInfoCount = 1;

        deviceQueues[0].setQueueFamilyIndex(p_devicePool[deviceId]->getDeviceProps().graphicsQueueFamilyIndex);
        deviceQueues[0].setQueueCount(1);
        deviceQueues[0].setPQueuePriorities(queuePriorities);
        if (p_devicePool[deviceId]->getDeviceProps().separatePresentQueue)
        {
            deviceQueues[1].setQueueFamilyIndex(p_devicePool[deviceId]->getDeviceProps().presentQueueFamilyIndex);
            deviceQueues[1].setQueueCount(1);
            deviceQueues[1].setPQueuePriorities(queuePriorities);
            ++queueCreateInfoCount;
        }

        auto deviceInfo = vk::DeviceCreateInfo()
                            .setQueueCreateInfoCount(queueCreateInfoCount)
                            .setPQueueCreateInfos(deviceQueues.data())
                            .setEnabledLayerCount(0)
                            .setPpEnabledLayerNames(nullptr)
                            .setEnabledExtensionCount(p_devicePool[deviceId]->getDeviceProps().enabledDeviceExtensionCount)
                            .setPpEnabledExtensionNames(p_devicePool[deviceId]->getDeviceProps().getEnabledExtensionNames())
                            .setPEnabledFeatures(nullptr); /* #todo - enable NO_FILL feature */

        vk::Device logicalDevice;
        vkResult = p_devicePool[deviceId]->getPhysicalDevice().createDevice(&deviceInfo, nullptr, &logicalDevice);
        assert(vkResult == vk::Result::eSuccess);

        p_devicePool[deviceId]->setLogicalDevice(logicalDevice);

        DEBUG_loadExtns(&p_devicePool[deviceId]->getLogicalDevice());

        p_devicePool[deviceId]->getLogicalDevice().getQueue(p_devicePool[deviceId]->getDeviceProps().graphicsQueueFamilyIndex, 0, &(p_devicePool[deviceId]->getDeviceResources().graphicsQueue));
        if (!p_devicePool[deviceId]->getDeviceProps().separatePresentQueue)
        {
            p_devicePool[deviceId]->getDeviceResources().presentQueue = p_devicePool[deviceId]->getDeviceResources().graphicsQueue;
        }
        else
        {
            p_devicePool[deviceId]->getLogicalDevice().getQueue(p_devicePool[deviceId]->getDeviceProps().presentQueueFamilyIndex, 0, &(p_devicePool[deviceId]->getDeviceResources().presentQueue));
        }

        return vkResult;
    }

    vk::Result Manager::pCreateDeviceMemoryAllocator(uint32_t deviceId)
    {
        auto vkResult = vk::Result::eSuccess;

        VraAllocatorCreateInfo allocatorInfo = {};
        allocatorInfo.physicalDevice = getDevice(deviceId).getPhysicalDevice();
        allocatorInfo.device = getDevice(deviceId).getLogicalDevice();
        VraAllocator allocator;
        vraCreateAllocator(&allocatorInfo, &allocator);

        getDevice(deviceId).setAllocator(allocator);

        return vkResult;
    }



} // end namespace vulkan