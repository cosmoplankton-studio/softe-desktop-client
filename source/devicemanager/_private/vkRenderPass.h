/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vkRenderPass.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef VULKAN_RENDERPASS
#define VULKAN_RENDERPASS


#include "vkDefines.h"
#include "vkResources.h"



namespace vulkan
{

	struct SubpassData
	{
		vk::SubpassDescription					description;
		std::vector< vk::AttachmentReference >	attachmentRefs;
		vk::AttachmentReference					depthRef;
	};


	class DataTable
	{
	public:

		template<device::DataDescription T>
		inline typename data_alias_traits<T>::datatype* getData(std::string const& tag)
		{
			size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(tag);
			data_alias_handle& _handle = p_dataAliases[T][dataKEY];
			if (!_handle)
			{
				_handle.reset(new typename data_alias_traits<T>::datatype(tag));
			}

			return reinterpret_cast<typename data_alias_traits<T>::datatype*>(_handle.get());
		}

		template<device::DataDescription T>
		inline typename data_alias_traits<T>::datatype* getData(std::string const& tag, uint32_t idx)
		{
			size_t dataKEY = ResourceBBase::GET_RESOURCEKEY(tag, idx);
			data_alias_handle& _handle = p_dataAliases[T][dataKEY];
			if (!_handle)
			{
				_handle.reset(new typename data_alias_traits<T>::datatype(tag, idx));
			}

			return reinterpret_cast<typename data_alias_traits<T>::datatype*>(_handle.get());
		}

	protected:
		std::map<device::DataDescription, std::map< size_t, data_alias_handle> > p_dataAliases;
	};
	
	
	class PassSwapchainData
	{
	public:
		inline FrameBufferDataHandle& getFramebufferData() { return p_framebuffer; }

	protected:
		FrameBufferDataHandle p_framebuffer;
	};


	/*
	Base class for pipeline stages
	*/
	class RenderPassBase
	{

	public:
		RenderPassBase(Manager* mgr, graphics::StageType type);

		RenderPassBase(Manager* mgr, graphics::StageType type, RenderPassBase *prev);

		virtual ~RenderPassBase();

		inline void SetNext(RenderPassBase *next)
		{
			p_nextPass = next;
		}

		static RenderPassHandle createRenderPass(Manager *mgr, RenderPassBase *prev, graphics::StageType passType);

		Manager &getManager();

		inline graphics::StageType getType()
		{
			return p_stageType;
		}
		
		inline vk::RenderPass getRenderPass()
		{
			return p_renderpass;
		}

		inline vk::Framebuffer getFramebuffer(size_t swapchainIdx)
		{
			return p_swapchainData[swapchainIdx]->getFramebufferData()->getFramebuffer();
		}

		inline std::map< std::string, DrawDescriptionHandle > const& getDrawDescriptions() const
		{
			return p_drawDescriptions;
		}

		template<device::DataDescription T>
		inline typename data_alias_traits<T>::datatype* getData(std::string const& tag)
		{
			return p_staticData->getData<T>(tag);
		}

		template<device::DataDescription T>
		inline typename data_alias_traits<T>::datatype* getData(std::string const& tag, uint32_t swapchainIdx)
		{
			return p_dynamicData->getData<T>(tag, swapchainIdx);
		}

		virtual vk::Result initialize();

		virtual vk::Result inputSlotWait();

		virtual vk::Result resizeResources();

	protected:
		/* initializers */
		virtual vk::Result pInitSwapchainData();

		virtual vk::Result pInitFrameBufferAttachments();

		virtual vk::Result pInitSubpass();

		virtual vk::Result pInitRenderPass();

		virtual vk::Result pInitFrameBuffer();

		/* helpers */
		template<device::DataDescription T>
		vk::Result pInitData();

		template<device::DataDescription T>
		vk::Result pCreateDataAlias(typename data_alias_traits<T>::descriptiontype const& dataDescription);

		template<typename T>
		vk::Result pinitDataAlias(DataAliasBase<T>* pData);

		template<device::DataDescription T>
		vk::Result pCreateDataSlot(typename data_alias_traits<T>::descriptiontype const& dataDescription);

		virtual vk::Result pCreatePresentFramebufferAttachments();
		
	protected:
		Manager* p_manager;

		graphics::StageType  p_stageType;
		RenderPassBase* p_prevPass;
		RenderPassBase* p_nextPass;

		std::vector< SubpassData > p_subpassData;
		std::vector< PassSwapchainDataHandle > p_swapchainData;
		DataTableHandle p_staticData;
		DataTableHandle p_dynamicData;
		std::map< std::string, DrawDescriptionHandle > p_drawDescriptions;

		vk::RenderPass p_renderpass;
	};


	class RenderPassUI final : public RenderPassBase
	{
	public:
		RenderPassUI(Manager* mgr, graphics::StageType passType)
			: RenderPassBase(mgr, passType)
		{}
		RenderPassUI(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
			: RenderPassBase(mgr, passType, prev)
		{}
		virtual ~RenderPassUI() {}
	};


	class RenderPassMultiMaterial final : public RenderPassBase
	{
	public:
		RenderPassMultiMaterial(Manager* mgr, graphics::StageType passType)
			: RenderPassBase(mgr, passType)
		{}
		RenderPassMultiMaterial(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
			: RenderPassBase(mgr, passType, prev)
		{}
		virtual ~RenderPassMultiMaterial() {}
	};


	class RenderPassWireframe final : public RenderPassBase
	{
	public:
		RenderPassWireframe(Manager* mgr, graphics::StageType passType)
			: RenderPassBase(mgr, passType)
		{}
		RenderPassWireframe(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
			: RenderPassBase(mgr, passType, prev)
		{}
		virtual ~RenderPassWireframe() {}
	};


	class RenderPassOffscreen final : public RenderPassBase
	{
	public:
		RenderPassOffscreen(Manager* mgr, graphics::StageType passType)
			: RenderPassBase(mgr, passType)
		{}
		RenderPassOffscreen(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
			: RenderPassBase(mgr, passType, prev)
		{}
		virtual ~RenderPassOffscreen() {}

	};


	class RenderPassOffscreenConsume final : public RenderPassBase
	{
	public:
		RenderPassOffscreenConsume(Manager* mgr, graphics::StageType passType)
			: RenderPassBase(mgr, passType)
		{}
		RenderPassOffscreenConsume(Manager* mgr, graphics::StageType passType, RenderPassBase *prev)
			: RenderPassBase(mgr, passType, prev)
		{}
		virtual ~RenderPassOffscreenConsume() {}

	};


} // end namespace vulkan


#endif // !VULKAN_RENDERPASS