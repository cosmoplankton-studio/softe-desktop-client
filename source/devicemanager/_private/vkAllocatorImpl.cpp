/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkAllocatorImpl.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

// vma and vra implmentation
#include "vkDefines.h"
#define VRA_IMPLEMENTATION
#define VMA_IMPLEMENTATION
#define VULKAN_HPP_NO_SMART_HANDLE
#define VULKAN_HPP_NO_EXCEPTIONS
#define VK_USE_PLATFORM_WIN32_KHR

#undef max
#undef min

#include "vma/vk_mem_alloc.h"
#include "vk_resource_alloc.h"
