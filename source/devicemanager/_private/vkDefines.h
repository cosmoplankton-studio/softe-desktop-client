/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkDefines.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef VULKAN_DEFINES
#define VULKAN_DEFINES


/* standard library */
#include <string>
#include <vector>
#include <fstream>
#include <locale>
#include <unordered_map>
#include <atomic>
#include <mutex>
#include <condition_variable>


/* vulkan sdk -  #todo - support unix */
#define VULKAN_HPP_NO_SMART_HANDLE
#define VULKAN_HPP_NO_EXCEPTIONS
#define VK_USE_PLATFORM_WIN32_KHR
#include "vk_resource_alloc.h"
#include <vulkan/vulkan.hpp>
#include <vulkan/vk_sdk_platform.h>

/* thirdparty library */
#include <math/linmath.h>


/* application */
#include "../Idevice.h"
#include "../IgraphicsAppManager.h"
#include "../IcomputeAppManager.h"
#include "../graphicsManager.h"
#include "../computeManager.h"
#include "vkDEBUG.h"


namespace compute = graphics_compute;
namespace graphics = graphics_compute;


/* common defines */
#define M_PI 3.14159265358979323846264338327950288
#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))
#define LOG_HEADER []() { std::string _header_("FILE: "); _header_ = _header_ +  __FILE__ + " LINE: " + std::to_string(__LINE__) + " FUNCTION: " + __FUNCTION__; return _header_; }
#define THROW_EXCEPTION(e)				\
	/*add internal handler call here */	\
	throw e;

#define _degreesToRadians [](float const &&degrees) { return degrees * M_PI / 180.0; }
#define _radiansToDegrees [](float const &&radians) { return radians * 180.0 / M_PI; }

#define VK_INLINE __forceinline

namespace vulkan
{
	
	/* vkDevice.h */
	struct DeviceResources;
	using DeviceResources = struct DeviceResources;

	struct DeviceProperties;
	using DeviceProperties = struct DeviceProperties;

	class Device;
	using DevicePtr = Device * ;
	using DeviceHandle = std::shared_ptr<Device>;
	using DevicePool = std::vector< Device* >;


	/* vkManager.h */
	class Manager;
	using ManagerHandle = std::shared_ptr<Manager>;
	struct InstanceProperties;


	/* vkCmdBufferManager.h */
	struct SwapChainCmdBuffers;
	using SwapChainCmdBuffers = struct SwapChainCmdBuffers;
	class CmdBufferManager;


	/* vkResources.h */
	using DataPtr = uint8_t * ;
	class DataLayout;
	enum class DataScope : uint32_t;

	class ResourceBuffer;
	class ResourceImage;
	using ResourceBufferHandle = std::shared_ptr<ResourceBuffer>;
	using ResourceImageHandle = std::shared_ptr<ResourceImage>;
	
	class UniformData;
	class VertexData;
	class IndexData;
	using UniformDataHandle = std::shared_ptr<UniformData>;
	using VertexDataHandle = std::shared_ptr<VertexData>;
	using IndexDataHandle = std::shared_ptr<IndexData>;

	class TextureData;
	class RenderTarget;
	class DepthData;
	class DrawCmdIndirectInfo;

	using TextureDataHandle = std::shared_ptr<TextureData>;
	using RenderTargetHandle = std::shared_ptr<RenderTarget>;
	using DepthDataHandle = std::shared_ptr<DepthData>;

	class FrameBufferData;
	using FrameBufferDataHandle = std::shared_ptr<FrameBufferData>;
	using DrawCmdIndirectInfoHandle = std::shared_ptr<DrawCmdIndirectInfo>;

	/* vkBufferManager.h */
	class ResourceManager;
	

	/* vkStageIO.h */
	struct InputSlotLock;
	class InputSlotWriteLock;


	/* vkRenderPass.h */
	struct SubpassData;
	class DataTable;
	class PassSwapchainData;
	using PassSwapchainDataHandle = std::shared_ptr<PassSwapchainData>;
	using DataTableHandle = std::shared_ptr<DataTable>;
	class RenderPassBase;
	class RenderPassUI;
	class RenderPassMultiMaterial;
	class RenderPassWireframe;
	class RenderPassOffscreen;
	class RenderPassOffscreenConsume;
	typedef std::shared_ptr< RenderPassBase > RenderPassHandle;


	/* vkRenderManager.h */
	using map_renderpass = std::unordered_map< graphics::StageType, std::shared_ptr < RenderPassBase > >;
	typedef std::vector< std::shared_ptr < RenderPassBase > > vec_renderpass;
	struct Camera2d;
	struct SwapchainData;
	struct SwapchainSynchronization;
	using SwapchainSynchronization = struct SwapchainSynchronization;
	class RenderManager;

	/* vkDrawDescription.h */
	struct DrawSwapchainData;
	struct DrawPipelineData;
	class DrawDescription;
	using DrawDescriptionHandle = std::shared_ptr<DrawDescription>;

	
	
	/* Common utilities */
	namespace utils
	{
		vk::Format GET_VKFORMAT_FROM_DATAFORMAT(device::DataFormat dataFormat);

		uint32_t GET_SIZE_FROM_VKFORMAT(vk::Format dataFormat);

		uint32_t GET_SIZE_FROM_DATAFORMAT(device::DataFormat dataFormat);

		vk::DescriptorType GET_VKDESCRIPTOR_FROM_DATADESCRIPTOR(device::DataDescription dataDesc);

		vk::ShaderStageFlagBits GET_VKSTAGE_FROM_SHADERSTAGE(graphics::ShaderStage stage);

		VmaMemoryUsage GET_VMAMEMORY_FROM_ACCESSQUALIFIER(device::DataAccessQualifier accessQ);
	}

#define VERIFY(e) \
	assert(e);

} // end namespace vulkan


#endif // !VULKAN_DEFINES
