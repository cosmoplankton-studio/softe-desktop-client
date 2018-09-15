/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkResources.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/



/**
*-------------------------------------------------------------------------------------------------
*	This header defines the types of resources (buffers/images) available for the graphics and compute pipeline stages.
*-------------------------------------------------------------------------------------------------
*	The resource allocation management uses two layer of managed resources. 
*	(1) The lower-most layer manages the "device-memory" - using "VkDeviceMemory" and "memory-offsets".
*	(2) The next layer manages "vulkan-resources" - "VkBuffer/VkImage" and "resource-offsets/resource-sublayouts"
*-------------------------------------------------------------------------------------------------
*	There are two types of resource managements:
*	(1) "RESOURCE_DEDICATED" - Individual device-memory allocation and vulkan-resource allocation.
*	(2) "RESOURCE_MANAGED" - Device-memory and Vulkan-resource is allocated from managed blocks.
*-------------------------------------------------------------------------------------------------
*	(a) The device memeory allocation is managed by vma (Vulkan Memory Allocator - vk_mem_alloc.h).
*	(b) The resource allocation is managed by vra (Vulkan Resource Allocator - vk_resource_alloc.h).
*	(c) Resources are hierarchically derived based on "management-type"<-"resource-type"<-"usage-type".
*-------------------------------------------------------------------------------------------------
*******************************************************************
*	vra and vma together would allow for a resource allocation strategy mentioned here:
*	https://developer.nvidia.com/vulkan-memory-management
*******************************************************************
*/



#ifndef VULKAN_RESOURCES
#define VULKAN_RESOURCES

#include "vkDefines.h"


namespace vulkan
{
	
	/**
	* @brief Data Layout to store input information for the scene.
	* External engines should provide the layout and data format of the vertices, uniforms, structs
	* they are providing to the graphics engine for rendering.
	*/
	class DataLayout
	{
	public:
		DataLayout()
		{}

		explicit DataLayout(device::DataAttributeList const& attributes)
			: p_atrributes(attributes)
		{}

		explicit DataLayout(uint32_t stride)
			: p_isForcedLayout(true)
			, p_ForcedLayoutStride(stride)
		{}

		inline void setDataAttributes(device::DataAttributeList const&& attributes)
		{
			p_atrributes = attributes;
		}

		inline void setForcedLayoutStride(uint32_t stride)
		{
			p_isForcedLayout = true;
			p_ForcedLayoutStride = stride;
		}

		inline uint32_t getAttributesCount() const
		{
			return p_atrributes.size();
		}

		inline uint32_t getAttributeSize(uint32_t attrIdx) const
		{
			return utils::GET_SIZE_FROM_VKFORMAT(utils::GET_VKFORMAT_FROM_DATAFORMAT(p_atrributes[attrIdx].getFormat()));
		}

		inline device::DataFormat getAttributeDataFormat(uint32_t attrIdx) const
		{
			return p_atrributes[attrIdx].getFormat();
		}

		inline device::DataAttributeType getAttributeType(uint32_t attrIdx) const
		{
			return p_atrributes[attrIdx].getType();
		}
		
		inline vk::Format getAttributeVkFormat(uint32_t attrIdx) const
		{
			return utils::GET_VKFORMAT_FROM_DATAFORMAT(p_atrributes[attrIdx].getFormat());
		}

		inline uint32_t getAttributeOffset(uint32_t attrIdx) const
		{
			uint32_t _offset = 0;
			for (uint32_t i = 0; i < attrIdx; ++i)
			{
				_offset += utils::GET_SIZE_FROM_VKFORMAT(utils::GET_VKFORMAT_FROM_DATAFORMAT(p_atrributes[i].getFormat()));
			}
			return _offset;
		}

		inline uint32_t getDataStride() const
		{
			if (p_isForcedLayout) return p_ForcedLayoutStride;
			uint32_t _size = 0;
			for (auto &attribute : p_atrributes)
			{
				_size += utils::GET_SIZE_FROM_DATAFORMAT(attribute.getFormat());
			}
			return _size;
		}

	protected:
		device::DataAttributeList p_atrributes;
		bool p_isForcedLayout{ false };
		uint32_t p_ForcedLayoutStride{ 0 };
	};


	/**
	* @brief	DataScope
	*/
	enum class DataScope : uint32_t
	{
		eUndefined =			0x0,
		eSingleStage =			0x1,
		eMultiStage =			0x2
	};


	/**
	* @class	ResourceBase
	* @brief	Base class for the Buffer resources.
	*/
	template<typename T>
	class ResourceBase_T
	{
	public:
		ResourceBase_T(DevicePtr device)
			: p_device(device)
			, p_resource(NULL)
		{}

		~ResourceBase_T()
		{}

		inline static size_t GET_RESOURCEKEY(std::string const& tag, uint32_t swapchainIdx = UINT32_MAX)
		{
			if (swapchainIdx == UINT32_MAX)
			{
				return std::hash<std::string>{}(tag);
			}

			return std::hash<std::string>{}(tag + std::to_string(swapchainIdx));
		}

		inline void init(T resource)
		{
			p_resource = resource;
		}

		inline void reset()
		{
			p_resource = nullptr;
		}

		inline T resource()
		{
			return p_resource;
		}

		inline void release()
		{
			--p_aliasCount;
			VERIFY(p_aliasCount >= 0);
		}

		inline void acquire()
		{
			++p_aliasCount;
			VERIFY(p_aliasCount < INT32_MAX);
		}

		inline DevicePtr getDevice()
		{
			return p_device;
		}

		inline DevicePtr getDevice() const
		{
			return p_device;
		}

	protected:
		DevicePtr p_device;
		T p_resource;
		int32_t p_aliasCount{ 0 };
		device::DataAccessQualifier p_accessQualifier;
	};
	
	using ResourceBBase = ResourceBase_T<VraBufferResource>;
	using ResourceIBase = ResourceBase_T<VraImageResource>;


	/**
	* @class	ResourceBuffer
	* @brief	Buffer resources.
	*/
	class ResourceBuffer
		: public ResourceBase_T<VraBufferResource>
	{
		using _MyBase = ResourceBase_T<VraBufferResource>;
		using _ThisRef = ResourceBuffer & ;

	public:

		ResourceBuffer(DevicePtr device)
			: _MyBase(device)
		{}

		inline vk::Buffer getBuffer() const
		{
			return p_resource->getBuffer();
		}

		inline vk::DeviceSize getBufferOffset() const
		{
			return p_resource->getOffset();
		}

		inline uint32_t getUnitDataSize() const
		{
			return p_dataLayout.getDataStride();
		}

		inline uint32_t getDataSize() const
		{
			return p_maxUnitCount * getUnitDataSize();
		}

		inline DataLayout const& getLayout() const
		{
			return p_dataLayout;
		}

		inline _ThisRef setLayout(DataLayout const& layout)
		{
			p_dataLayout = layout;
			return *this;
		}

		inline uint32_t getMaxUnitCount() const
		{
			return p_maxUnitCount;
		}

		inline _ThisRef setMaxUnitCount(uint32_t count)
		{
			p_maxUnitCount = count;
			return *this;
		}

		inline vk::BufferUsageFlags getUsage() const
		{
			return p_usage;
		}

		inline _ThisRef setUsage(vk::BufferUsageFlags flags)
		{
			p_usage = flags;
			return *this;
		}

	protected:
		uint32_t p_maxUnitCount{ 0 };
		DataLayout p_dataLayout;
		vk::BufferUsageFlags p_usage { vk::BufferUsageFlagBits::eUniformBuffer };
	};


	/**
	* @class	ResourceImage
	* @brief	Image resources.
	*/
	class ResourceImage
		: public ResourceBase_T<VraImageResource>
	{
		using _MyBase = ResourceBase_T<VraImageResource>;
		using _ThisRef = ResourceImage & ;

	public:

		ResourceImage(DevicePtr device)
			: _MyBase(device)
		{}

		inline vk::Image getImage() const
		{
			return p_resource->getImage();
		}

		inline vk::Format getFormat() const
		{
			return p_format;
		}

		inline _ThisRef setFormat(vk::Format format)
		{
			p_format = format;
			return *this;
		}

		inline vk::Extent3D getExtent() const
		{
			return p_extent;
		}

		inline _ThisRef setExtent(vk::Extent3D extent)
		{
			p_extent = extent;
			return *this;
		}

		inline _ThisRef setWidth(uint32_t width)
		{
			p_extent.width = width;
			return *this;
		}

		inline _ThisRef setHeight(uint32_t height)
		{
			p_extent.height = height;
			return *this;
		}

		inline _ThisRef setDepth(uint32_t depth)
		{
			p_extent.depth = depth;
			return *this;
		}

		inline bool checkUsageFlag(vk::ImageUsageFlags flags) const
		{
			return (p_usage == flags);
		}

		inline _ThisRef setUsageFlag(vk::ImageUsageFlagBits flag)
		{
			p_usage |= flag;
			return *this;
		}

		inline vk::ImageUsageFlags getUsage() const
		{
			return p_usage;
		}

		inline _ThisRef setUsage(vk::ImageUsageFlags flags)
		{
			p_usage = flags;
			return *this;
		}

		inline vk::ImageLayout getLayout() const
		{
			return p_layout;
		}

		inline _ThisRef setLayout(vk::ImageLayout layout)
		{
			p_layout = layout;
			return *this;
		}

		inline vk::ImageTiling getTiling() const
		{
			return p_tiling;
		}

		inline _ThisRef setTiling(vk::ImageTiling tiling)
		{
			p_tiling = tiling;
			return *this;
		}

	protected:
		vk::Extent3D p_extent{1, 1, 1};
		vk::ImageType p_type{ vk::ImageType::e1D };
		vk::Format p_format;
		vk::ImageUsageFlags p_usage{ vk::ImageUsageFlagBits::eSampled };
		vk::ImageLayout p_layout{ vk::ImageLayout::eGeneral };
		vk::ImageTiling	p_tiling{ vk::ImageTiling::eLinear };
	};

	
	
	/*
	*----------------------------------------------------------------------------
	* data alias traits.
	*----------------------------------------------------------------------------
	*/
	template<device::DataDescription T>
	struct data_alias_traits
	{
		using datatype = void;
		using resourcetype = void;
		using descriptiontype = void;
		static const vk::BufferUsageFlagBits usage = NULL;
	};
	using data_alias_handle = std::shared_ptr<void>;;

	template<> struct data_alias_traits<device::DataDescription::eVertex>
	{
		using datatype = VertexData;
		using resourcetype = ResourceBuffer;
		using descriptiontype = graphics::StageBufferDataDescription;
		static const vk::BufferUsageFlagBits usage = vk::BufferUsageFlagBits::eVertexBuffer;
	};
	template<> struct data_alias_traits<device::DataDescription::eIndex>
	{
		using datatype = IndexData;
		using resourcetype = ResourceBuffer;
		using descriptiontype = graphics::StageBufferDataDescription;
		static const vk::BufferUsageFlagBits usage = vk::BufferUsageFlagBits::eIndexBuffer;
	};
	template<> struct data_alias_traits<device::DataDescription::eUniform>
	{
		using datatype = UniformData;
		using resourcetype = ResourceBuffer;
		using descriptiontype = graphics::StageBufferDataDescription;
		static const vk::BufferUsageFlagBits usage = vk::BufferUsageFlagBits::eUniformBuffer;
	};
	template<> struct data_alias_traits<device::DataDescription::eTexture>
	{
		using datatype = TextureData;
		using resourcetype = ResourceImage;
		using descriptiontype = graphics::StageImageDataDescription;
		static const vk::ImageUsageFlagBits usage = vk::ImageUsageFlagBits::eSampled;
	};
	template<> struct data_alias_traits<device::DataDescription::eRenderTarget>
	{
		using datatype = RenderTarget;
		using resourcetype = ResourceImage;
		using descriptiontype = graphics::StageImageDataDescription;
		static const vk::ImageUsageFlagBits usage = vk::ImageUsageFlagBits::eColorAttachment;
	};
	template<> struct data_alias_traits<device::DataDescription::eDraw>
	{
		using datatype = void;
		using resourcetype = ResourceBuffer;
		using descriptiontype = graphics::StageDrawDescription;
	};
	



	template<typename T>
	class DataAliasBase
	{
	public:
		DataAliasBase(std::string const& tag)
			: p_dataHANDLE(nullptr)
			, p_dataTAG(tag)
			, p_dataKEY(ResourceBBase::GET_RESOURCEKEY(tag))
		{}

		explicit DataAliasBase(std::string const& tag, uint32_t swapchainIdx)
			: p_dataHANDLE(nullptr)
			, p_dataTAG(tag)
			, p_dataKEY(ResourceBBase::GET_RESOURCEKEY(tag, swapchainIdx))
			, p_dataUpdateScheme(graphics::DataUpdateScheme::eFrameDynamic)
		{}

		virtual ~DataAliasBase()
		{
			if (p_dataHANDLE) p_dataHANDLE->release();
		}

		inline void initAlias(T* data)
		{
			if (p_dataHANDLE) p_dataHANDLE->release();
			p_dataHANDLE = data;
			p_dataHANDLE->acquire();
		}

		inline T const* data() const
		{
			return p_dataHANDLE;
		}

		inline T* datawrite()
		{
			return p_dataHANDLE;
		}

		inline size_t getDataKEY() const
		{
			return p_dataKEY;
		}

	private:
		std::string	p_dataTAG;
		size_t p_dataKEY;
		T* p_dataHANDLE;

		graphics::DataUpdateScheme p_dataUpdateScheme{ graphics::DataUpdateScheme::eFrameStatic };
		DataScope p_dataScope{ DataScope::eMultiStage };
	};


	class BufferDataAlias
		: public DataAliasBase<ResourceBuffer>
	{
		using _ThisRef = BufferDataAlias & ;
		using _MyBase = DataAliasBase<ResourceBuffer>;

	public:
		BufferDataAlias(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit BufferDataAlias(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~BufferDataAlias()
		{}

		inline vk::DescriptorBufferInfo getDescriptorBufferInfo() const
		{
			return vk::DescriptorBufferInfo()
				.setOffset(data()->getBufferOffset())
				.setBuffer(data()->getBuffer())
				.setRange(data()->getUnitDataSize());
		}

	};


	class ImageDataAlias
		: public DataAliasBase<ResourceImage>
	{
		using _ThisRef = ImageDataAlias & ;
		using _MyBase = DataAliasBase<ResourceImage>;

	public:
		ImageDataAlias(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit ImageDataAlias(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~ImageDataAlias()
		{}

		inline vk::ImageViewType getImageViewType() const
		{
			return p_imageViewType;
		}

		inline _ThisRef setImageViewType(vk::ImageViewType type)
		{
			p_imageViewType = type;
			return *this;
		}

		inline vk::ImageView getImageView() const
		{
			return p_imageView;
		}

		inline vk::ImageView* imageviewPTR()
		{
			return &p_imageView;
		}

		inline vk::Sampler getSampler() const
		{
			return p_sampler;
		}

		inline vk::Sampler* samplerPTR()
		{
			return &p_sampler;
		}

		inline vk::SubresourceLayout const& getSubresourceLayout() const
		{
			return p_subresourceLayout;
		}

		inline vk::SubresourceLayout* subresourcelayoutPTR()
		{
			return &p_subresourceLayout;
		}

		inline vk::DescriptorImageInfo getDescriptorImageInfo() const
		{
			return vk::DescriptorImageInfo()
				.setSampler(p_sampler)
				.setImageView(getImageView())
				.setImageLayout(data()->getLayout());
		}

		inline vk::ImageSubresourceRange const& getSubresourceRange() const
		{
			return p_subresourceRange;
		}

		inline _ThisRef setSubresourceRange(vk::ImageSubresourceRange const& range)
		{
			p_subresourceRange = range;
			return *this;
		}


	protected:
		vk::ImageViewType p_imageViewType{ vk::ImageViewType::e2D };
		vk::ImageView p_imageView;
		vk::Sampler p_sampler;
		vk::SubresourceLayout p_subresourceLayout;
		vk::ImageSubresourceRange p_subresourceRange;
	};


	/**
	@brief UniformData - Data alias to Stage Uniform Data.
	*/
	class UniformData
		: public BufferDataAlias
	{
		using _MyBase = BufferDataAlias;

	public:
		UniformData(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit UniformData(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~UniformData()
		{}

	};

	/**
	@brief VertexData - Data alias to Stage Vertex Data.
	*/
	class VertexData
		: public BufferDataAlias
	{
		using _MyBase = BufferDataAlias;

	public:
		VertexData(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit VertexData(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~VertexData()
		{}

		inline vk::VertexInputBindingDescription getVertexInputBindingDescription(uint32_t bindingIdx) const
		{
			return vk::VertexInputBindingDescription()
				.setBinding(bindingIdx)
				.setStride(data()->getLayout().getDataStride())
				.setInputRate(vk::VertexInputRate::eVertex);
		}

		inline void getVertexInputAttributeDescription(uint32_t bindingIdx, std::vector< vk::VertexInputAttributeDescription > &attrDesc) const
		{
			for (uint32_t attrIdx = 0; attrIdx < data()->getLayout().getAttributesCount(); ++attrIdx)
			{
				attrDesc.push_back(
					vk::VertexInputAttributeDescription()
					.setLocation(attrIdx)
					.setBinding(bindingIdx)
					.setFormat(data()->getLayout().getAttributeVkFormat(attrIdx))
					.setOffset(data()->getLayout().getAttributeOffset(attrIdx))
				);
			}
		}

	};

	
	/**
	@brief IndexData - Data alias to Stage Vertex Index Data.
	*/
	class IndexData
		: public BufferDataAlias
	{
		using _MyBase = BufferDataAlias;

	public:
		IndexData(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit IndexData(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~IndexData()
		{}

		inline vk::IndexType getIndexType() const
		{
			switch (data()->getLayout().getAttributeDataFormat(0))
			{
			case device::DataFormat::eUint16: return vk::IndexType::eUint16;
			case device::DataFormat::eUint32: return vk::IndexType::eUint32;
			default:assert(0);
			}
			return vk::IndexType::eUint16;
		}
		
		inline uint32_t getIndexSize() const
		{
			switch (getIndexType())
			{
			case vk::IndexType::eUint32: return sizeof(uint32_t);
			case vk::IndexType::eUint16: return sizeof(uint16_t);
			default:assert(0);
			}
			return 0;
		}

	};


	/**
	@brief Indirect draw information.
	#improvement - support for instances.
	*/
	class DrawCmdIndirectInfo
		: public BufferDataAlias
	{
		using _MyBase = BufferDataAlias;

	public:
		DrawCmdIndirectInfo(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit DrawCmdIndirectInfo(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~DrawCmdIndirectInfo()
		{}

		bool	isIndexed{ false };
	};


	/**
	@brief TextureData - Logical unit for textures.
	*/
	class TextureData
		: public ImageDataAlias
	{
		using _MyBase = ImageDataAlias;

	public:
		TextureData(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit TextureData(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~TextureData()
		{}

	};


	/**
	@brief RenderTarget - render target (renderpass color attachment)
	*/
	class RenderTarget
		: public ImageDataAlias
	{
		using _MyBase = ImageDataAlias;

	public:
		RenderTarget(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit RenderTarget(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~RenderTarget()
		{}

		inline void setBindingIdx(uint32_t idx) { p_bindingIdx = idx; }
		inline uint32_t getBindingIdx() const { return p_bindingIdx; }

		inline vk::Format getFormat()
		{
			if (p_targetType == graphics::RenderTargetType::ePresent || !data())
				return p_surfaceFormat;

			return data()->getFormat();
		}

		inline void setFormat(vk::Format format)
		{
			p_surfaceFormat = format;
		}

	protected:
		uint32_t p_bindingIdx{ UINT32_MAX };
		graphics::RenderTargetType p_targetType{ graphics::RenderTargetType::ePresent };
		vk::Format p_surfaceFormat;
	};

	
	/**
	@brief DepthData - render depth target (renderpass depth attachment)
	*/
	class DepthData
		: public ImageDataAlias
	{
		using _MyBase = ImageDataAlias;

	public:
		DepthData(std::string const& tag)
			: _MyBase(tag)
		{}

		explicit DepthData(std::string const& tag, uint32_t swapchainIdx)
			: _MyBase(tag, swapchainIdx)
		{}

		virtual ~DepthData()
		{}

		inline void setBindingIdx(uint32_t idx) { p_bindingIdx = idx; }
		inline uint32_t getBindingIdx() const { return p_bindingIdx; }

	protected:
		uint32_t p_bindingIdx{ UINT32_MAX };
	};
	
	

	/**
	@brief FrameBufferData - Framebuffer information
	*/
	class FrameBufferData
	{
	public:
		uint32_t getAttachmentCount() const
		{
			return (p_depth.get()) ? p_attachments.size() + 1 : p_attachments.size();
		}

		inline vk::Framebuffer getFramebuffer() const
		{
			return p_frameBuf;
		}

		inline vk::Framebuffer* framebufferPTR()
		{
			return &p_frameBuf;
		}

		inline DepthDataHandle& getDepthAttachment()
		{
			return p_depth;
		}

		inline auto& getColorAttachments()
		{
			return p_attachments;
		}

	protected:
		vk::Framebuffer	p_frameBuf;

		std::vector < RenderTargetHandle > p_attachments;
		DepthDataHandle p_depth;
	};




} // end namespace vulkan



#endif // !VULKAN_RESOURCES