/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkUtils.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "vkDefines.h"


namespace vulkan
{

	namespace utils
	{

		vk::Format GET_VKFORMAT_FROM_DATAFORMAT(device::DataFormat dataFormat)
		{
			switch (dataFormat)
			{
			case device::DataFormat::eR32G32B32A32Float: return vk::Format::eR32G32B32A32Sfloat;
			case device::DataFormat::eR32G32Float: return vk::Format::eR32G32Sfloat;
			case device::DataFormat::eRGBA32: return vk::Format::eR8G8B8A8Unorm;
			case device::DataFormat::eA8: return vk::Format::eR8Uint;
			case device::DataFormat::eUint16: return vk::Format::eR16Uint;
			default: return vk::Format::eUndefined;
			}
		}

		uint32_t GET_SIZE_FROM_VKFORMAT(vk::Format dataFormat)
		{
			switch (dataFormat)
			{
			case vk::Format::eR32G32B32A32Sfloat: return 4 * sizeof(float);
			case vk::Format::eR32G32Sfloat: return 2 * sizeof(float);
			case vk::Format::eR8G8B8A8Uint: return 4 * sizeof(uint8_t);
			case vk::Format::eR8G8B8A8Unorm: return 4 * sizeof(uint8_t);
			case vk::Format::eR8Uint: return sizeof(uint8_t);
			case vk::Format::eR16Uint: return sizeof(uint16_t);
			case vk::Format::eR8Snorm: return sizeof(uint8_t);
			default: return 0;
			}
		}

		uint32_t GET_SIZE_FROM_DATAFORMAT(device::DataFormat dataFormat)
		{
			switch (dataFormat)
			{
			case device::DataFormat::eMAT4Float: return 16 * sizeof(float);
			default: return GET_SIZE_FROM_VKFORMAT(GET_VKFORMAT_FROM_DATAFORMAT(dataFormat));
			}
		}

		vk::DescriptorType GET_VKDESCRIPTOR_FROM_DATADESCRIPTOR(device::DataDescription dataDesc)
		{
			switch (dataDesc)
			{
			case device::DataDescription::eGeneral: return vk::DescriptorType::eUniformBuffer;
			case device::DataDescription::eVertex: return vk::DescriptorType::eUniformBuffer;
			case device::DataDescription::eIndex: return vk::DescriptorType::eUniformBuffer;
			case device::DataDescription::eUniform: return vk::DescriptorType::eUniformBuffer;
			case device::DataDescription::eTexture: return vk::DescriptorType::eCombinedImageSampler;
			case device::DataDescription::eRenderTarget: return vk::DescriptorType::eCombinedImageSampler;
			case device::DataDescription::eDraw:
			default: assert(0);
			}
			return vk::DescriptorType::eUniformBuffer;
		}


		vk::ShaderStageFlagBits GET_VKSTAGE_FROM_SHADERSTAGE(graphics::ShaderStage stage)
		{
			switch (stage)
			{
			case graphics::ShaderStage::eAllGraphics: return vk::ShaderStageFlagBits::eAllGraphics;
			case graphics::ShaderStage::eVertex: return vk::ShaderStageFlagBits::eVertex;
			case graphics::ShaderStage::eFragment: return vk::ShaderStageFlagBits::eFragment;
			default: return vk::ShaderStageFlagBits::eAll;
			}

		}

		VmaMemoryUsage GET_VMAMEMORY_FROM_ACCESSQUALIFIER(device::DataAccessQualifier accessQ)
		{
			switch (accessQ)
			{
			case device::DataAccessQualifier::eHostLocal: return VMA_MEMORY_USAGE_CPU_ONLY;
			case device::DataAccessQualifier::eDeviceLocal: return VMA_MEMORY_USAGE_GPU_ONLY;
			case device::DataAccessQualifier::eHostToDevice: return VMA_MEMORY_USAGE_CPU_TO_GPU;
			case device::DataAccessQualifier::eDeviceToHost: return VMA_MEMORY_USAGE_GPU_TO_CPU;
			case device::DataAccessQualifier::eUndefined:
			default:
				VERIFY(0);
				return VMA_MEMORY_USAGE_UNKNOWN;
			}
		}

	} // end namespace utils

} // end namespace vulkan