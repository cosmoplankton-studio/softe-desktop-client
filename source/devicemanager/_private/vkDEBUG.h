/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkDEBUG.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef VULKAN_DEBUG
#define VULKAN_DEBUG


#define DEBUG_staticinit \
	PFN_vkDebugMarkerSetObjectTagEXT debug::MARKER::cmd_DebugMarkerSetObjectTag = nullptr; \
	PFN_vkDebugMarkerSetObjectNameEXT debug::MARKER::cmd_DebugMarkerSetObjectName = nullptr; \
	PFN_vkCmdDebugMarkerBeginEXT debug::MARKER::cmd_CmdDebugMarkerBegin = nullptr; \
	PFN_vkCmdDebugMarkerEndEXT debug::MARKER::cmd_CmdDebugMarkerEnd = nullptr; \
	PFN_vkCmdDebugMarkerInsertEXT debug::MARKER::cmd_CmdDebugMarkerInsert = nullptr;

namespace debug
{
// #define RENDER_DEBUG_OFF

#define DEBUG_markObject [](uint64_t objRef, char const *objName, vk::DebugReportObjectTypeEXT objType, VkDevice logicalDevice) { if(!::debug::MARKER::isOn()) return; ::debug::MARKER::markImage(objRef, objName, objType, logicalDevice); }
#define DEBUG_loadExtns [](vk::Device* logicalDevice) {if(!::debug::MARKER::isOn()) return; ::debug::MARKER::loadDeviceExtnProcAddr(logicalDevice); }

	
	template< typename SRCTYPE, typename TARGETTYPE >
	uint64_t getDebugRef(SRCTYPE srcRef)
	{
		TARGETTYPE targetRef = srcRef;
		return (uint64_t)targetRef;
	}
	#define getImageRef getDebugRef< vk::Image, VkImage >
	#define getImageViewRef getDebugRef< vk::ImageView, VkImageView >
	#define getShaderModuleRef getDebugRef< vk::ShaderModule, VkShaderModule >
	#define getFramebufferRef getDebugRef< vk::Framebuffer, VkFramebuffer >

	static VkDevice getDeviceRef(vk::Device device)
	{
		return device;
	}


	class MARKER
	{
	public:
		static bool isOn()
		{
			return false;
		}

		static void loadDeviceExtnProcAddr(vk::Device* logicalDevice)
		{
			cmd_DebugMarkerSetObjectTag = (PFN_vkDebugMarkerSetObjectTagEXT)vkGetDeviceProcAddr(*logicalDevice, "vkDebugMarkerSetObjectTagEXT");
			cmd_DebugMarkerSetObjectName = (PFN_vkDebugMarkerSetObjectNameEXT)vkGetDeviceProcAddr(*logicalDevice, "vkDebugMarkerSetObjectNameEXT");
			cmd_CmdDebugMarkerBegin = (PFN_vkCmdDebugMarkerBeginEXT)vkGetDeviceProcAddr(*logicalDevice, "vkCmdDebugMarkerBeginEXT");
			cmd_CmdDebugMarkerEnd = (PFN_vkCmdDebugMarkerEndEXT)vkGetDeviceProcAddr(*logicalDevice, "vkCmdDebugMarkerEndEXT");
			cmd_CmdDebugMarkerInsert = (PFN_vkCmdDebugMarkerInsertEXT)vkGetDeviceProcAddr(*logicalDevice, "vkCmdDebugMarkerInsertEXT");
		}

		static std::vector< std::string > getRequiredDeviceExtensions()
		{
			return { VK_KHR_SWAPCHAIN_EXTENSION_NAME , VK_EXT_DEBUG_MARKER_EXTENSION_NAME };
		}

		static void markImage(uint64_t objRef, char const *objName, vk::DebugReportObjectTypeEXT objType, VkDevice logicalDevice)
		{
			vk::DebugMarkerObjectNameInfoEXT nameInfo =
				vk::DebugMarkerObjectNameInfoEXT()
				.setObject(objRef)
				.setObjectType(objType)
				.setPObjectName(objName);

			VkDebugMarkerObjectNameInfoEXT objNameInfo = nameInfo;
			cmd_DebugMarkerSetObjectName(logicalDevice, &objNameInfo);
		}

	private:
		static PFN_vkDebugMarkerSetObjectTagEXT cmd_DebugMarkerSetObjectTag;
		static PFN_vkDebugMarkerSetObjectNameEXT cmd_DebugMarkerSetObjectName;
		static PFN_vkCmdDebugMarkerBeginEXT cmd_CmdDebugMarkerBegin;
		static PFN_vkCmdDebugMarkerEndEXT cmd_CmdDebugMarkerEnd;
		static PFN_vkCmdDebugMarkerInsertEXT cmd_CmdDebugMarkerInsert;

	};


} // end namespace debug

#endif //!VULKAN_DEBUG
