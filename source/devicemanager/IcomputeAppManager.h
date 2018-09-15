/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/


/**
* @file			IcomputeAppManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/



#ifndef I_COMPUTE_APP_MANAGER
#define I_COMPUTE_APP_MANAGER


#include <memory>

namespace graphics_compute
{
	
	class IComputeManager;
	using ComputeManagerHandle = std::shared_ptr< IComputeManager >;


	/**
	* @class	I_ComputeAppManager
	* @brief	Any application that intends to utilize the computeManager should
	*			provide a concrete implementation of this interface.
	*/
	class I_ComputeAppManager
	{
	public:
		virtual void COMPUTE_LOGMESSAGE(std::string const&) = 0;
		virtual void COMPUTE_LOGERROR(std::string const&) = 0;
	};


	enum class KernelFormat : uint32_t
	{
		eUndefined = 0x0,
		eSource = 0x1,
		eBinary = 0x2,
		eSPIRV = 0x3
	};


	/**
	* @class	BufferDescription
	* @brief	Description of buffer reaources.
	*/
	class BufferDescription final
	{
		using this_ref = BufferDescription & ;
	public:
		inline auto const& getTag() const { return m_tag; }
		inline auto getMaxUnitCount() const { return m_maxUnitCount; }
		inline auto const& getDataAttributes() const { return m_dataAttributes; }
		inline auto getDataAccessQualifier() const { return m_dataAccessQ; }

		inline this_ref setTag(std::string const& tag) { m_tag = tag; return *this; }
		inline this_ref setMaxUnitCount(uint32_t count) { m_maxUnitCount = count; return *this; }
		inline this_ref setDataAttributeList(device::DataAttributeList const& list) { m_dataAttributes = list; return *this; }
		inline this_ref setDataAccessQualifier(device::DataAccessQualifier accessQ) { m_dataAccessQ = accessQ; return *this; }

	protected:
		std::string m_tag;
		uint32_t m_maxUnitCount{ 0 };
		device::DataAttributeList m_dataAttributes;
		device::DataAccessQualifier m_dataAccessQ{ device::DataAccessQualifier::eHostToDevice };
	};


	enum ImageViewType : uint32_t
	{
		e1D = 0x0,
		e1DArray = 0x1,
		e2D = 0x2,
		e2DArray = 0x3,
		e3D = 0x4
	};


	/**
	* @class	ImageDescription
	* @brief	Description of Image and ImageArray reaources.
	*/
	class ImageDescription final
	{
		using this_ref = ImageDescription & ;
	public:

		inline auto const& getTag() const { return m_tag; }
		inline auto getWidth() const { return m_width; }
		inline auto getHeight() const { return m_height; }
		inline auto getDepth() const { return m_depth; }
		inline auto getArraySize() const { return m_arraySize; }
		inline auto getRowPitch() const { return m_rowPitch; }
		inline auto getSlicePitch() const { return m_slicePitch; }
		inline auto getDataFormat() const { return m_imageFormat; }
		inline auto getResourceType() const { return m_imageType; }
		inline auto getDataAccessQualifier() const { return m_dataAccessQ; }

		inline this_ref setTag(std::string const& tag) { m_tag = tag; return *this; }
		inline this_ref setWidth(uint32_t width) { m_width = width; return *this; }
		inline this_ref setHeight(uint32_t height) { m_height = height; return *this; }
		inline this_ref setDepth(uint32_t depth) { m_depth = depth; return *this; }
		inline this_ref setArraySize(uint32_t arraysize) { m_arraySize = arraysize; return *this; }
		inline this_ref setRowPitch(uint32_t rowpitch) { m_rowPitch = rowpitch; return *this; }
		inline this_ref setSlicePitch(uint32_t slicepitch) { m_slicePitch = slicepitch; return *this; }
		inline this_ref setDataFormat(device::DataFormat format) { m_imageFormat = format; return *this; }
		inline this_ref setResourceType(ImageViewType imgtype) { m_imageType = imgtype; return *this; }
		inline this_ref setDataAccessQualifier(device::DataAccessQualifier accessQ) { m_dataAccessQ = accessQ; return *this; }

	protected:
		std::string m_tag;
		uint32_t m_width{ 0 };
		uint32_t m_height{ 1 };
		uint32_t m_depth{ 1 };
		uint32_t m_arraySize{ 0 };
		uint32_t m_rowPitch{ 0 };
		uint32_t m_slicePitch{ 0 };
		device::DataFormat m_imageFormat{ device::DataFormat::eR32G32B32A32Float };
		ImageViewType m_imageType{ ImageViewType::e1D };
		device::DataAccessQualifier m_dataAccessQ{ device::DataAccessQualifier::eHostToDevice };
	};


	/**
	* @class	Dependency
	* @brief	Description of the synchronization primitives for dispatch/dataslots.
	*----------------------------------------
	* Currently supporting abstraction for below (opencl/vulkan):
	*----------------------------------------
	* 1. barriers/fences
	* 2. events/semaphores
	* 3. stage/executionnode dependency
	*----------------------------------------
	*/
	class Dependency
	{};
	class Synchronization
	{};


	/**
	* @class	DispatchDescription
	* @brief	Description of a compute kernel dispatch.
	*--------------------------------------------------------------------------
	* Currently a single dispatch supports only a single kernel at a time till the complete
	* implementation of the ExecutionGraph. So to execute multiple kernels we need multiple dispatch calls.
	*--------------------------------------------------------------------------
	*/
	class DispatchDescription final
	{
		using this_ref = DispatchDescription & ;
	public:
		inline auto const& getTag() const { return m_tag; }
		inline auto const& getKernelName() const { return m_kernalName; }
		inline auto const& getKernelNamespace() const { return m_kernalNamespace; }

		inline this_ref setTag(std::string const& tag) { m_tag = tag; return *this; }
		inline this_ref setKernelName(std::string const& name) { m_kernalName = name; return *this; }
		inline this_ref setKernelNamespace(std::string const& name) { m_kernalNamespace = name; return *this; }

	protected:
		std::string m_tag;
		std::string m_kernalName; // __kernel entrypoint
		std::string m_kernalNamespace;
	};

	
	struct DispatchPayload
	{
		std::string tag{ "" };
		size_t globalworksize{ 0 };
		/*
		*----------------------------------
		* for now single __kernel, see comment above for improvement details.
		*----------------------------------
		* The per dimension worksize is not exposed as the MAX_LIMITS to workgroups
		* are device specific and the application shouldn't handle these for multiple
		* device configurations.
		* The computemanager will distribute work among diemnsions 
		* from the global size. The __kernels should evaluate appropriate
		* data indexes using the "globalsize, localsize, globalid, and localid".
		*----------------------------------
		* __kernel could impose restriction on workgroup using __attribute__, and 
		* computemanager would use KernelWorkGroupInfo to fetch them while distributing work.
		*----------------------------------
		* size_t globalworksize[3] = { 0 };
		*----------------------------------
		*/
	};


	/**
	* @class	IResourceSlot
	* @brief	Data IO Slot Base.
	*/
	class IResourceSlot
	{
	public:
		virtual void setIsBlocking(bool isBlocking) = 0; // allows for both synchronous and asychronous update.
	};
	using ResourceSlotHandle = std::shared_ptr<IResourceSlot>;


	/**
	* @class	BufferSlot
	* @brief	IO slot interfaace for the buffer resources.
	*/
	class BufferSlot : public IResourceSlot
	{
	public:
		virtual int writeData(const void* srcPtr, size_t dataSize, size_t offset = 0) = 0;
		virtual int readData(void* dstPtr, size_t dataSize, size_t offset = 0) = 0;
		virtual int copyDataTo(const void* srcSlot, size_t dataSize, size_t srcOffset = 0, size_t dstOffset = 0) = 0;
		virtual int copyDataFrom(void* dstSlot, size_t dataSize, size_t srcOffset = 0, size_t dstOffset = 0) = 0;
	};

	/**
	* @class	ImageSlot
	* @brief	IO slot interface for the image resources.
	*/
	class ImageSlot : public IResourceSlot
	{
	public:
		virtual int writeData(const void* srcPtr, const size_t region[3], const size_t origin[3] = {0}) = 0;
		virtual int readData(void* dstPtr, const size_t region[3], const size_t origin[3] = { 0 }) = 0;
		virtual int copyDataTo(const void* srcSlot, const size_t region[3], const size_t srcOrigin[3] = { 0 }, const size_t dstOrigin[3] = { 0 }) = 0;
		virtual int copyDataFrom(void* dstSlot, const size_t region[3], const size_t srcOrigin[3] = { 0 }, const size_t dstOrigin[3] = { 0 }) = 0;
	};



	/**
	* @class	IDataIO
	* @brief	Interface to all data io slots.
	*/
	class IDataSlot
	{
	public:
		virtual BufferSlot* getBufferSlot(std::string const& tag) const = 0;
		virtual ImageSlot* getImageSlot(std::string const& tag) const = 0;
	};
	using DataSlotHandle = std::unique_ptr<IDataSlot>;

	
	/* slot return_trait */
	template< device::ResourceType RsrcT >
	struct return_trait { using rtype = void*; };
	template<>
	struct return_trait<device::ResourceType::eBuffer> { using rtype = BufferSlot * ; };
	template<>
	struct return_trait<device::ResourceType::eImage> { using rtype = ImageSlot * ; };

	
	/**
	* @class	DataIO
	* @brief	Object to access all the Data IO Slots for the pipeline.
	*/
	class DataIO
	{
	public:
		DataIO(IDataSlot* io)
			: m_dataIOslot(io)
		{}

		inline IDataSlot* getImpl()
		{
			return m_dataIOslot.get();
		}

		template<device::ResourceType RsrcT>
		inline typename return_trait<RsrcT>::rtype getSlot(std::string const& tag);

		template<>
		inline BufferSlot* getSlot<device::ResourceType::eBuffer>(std::string const& tag)
		{
			return m_dataIOslot->getBufferSlot(tag);
		}

		template<>
		inline ImageSlot* getSlot<device::ResourceType::eImage>(std::string const& tag)
		{
			return m_dataIOslot->getImageSlot(tag);
		}

	protected:
		DataSlotHandle m_dataIOslot;
	};

	using DataIOHandle = std::shared_ptr<DataIO>;



	struct ArgPayload
	{
		std::shared_ptr<void> data;
		size_t size;
		// std::type_info typeinfo;
	};

	/**
	* @class	IArgSlot
	* @brief	Kernel Argument IO slot interface.
	*/
	class IArgSlot
	{
	public:
		virtual int argSet(ArgPayload const& payload) = 0;
		virtual int argBindBuffer(std::string const& bufferTag) = 0;
		virtual int argBindImage(std::string const& imageTag) = 0;
	};
	using ArgSlotHandle = std::unique_ptr<IArgSlot>;

	/**
	* @class	ArgIO
	* @brief	Kernel Argument IO slot object.
	*/
	class ArgIO final
	{
	public:
		ArgIO(IArgSlot* slot)
			: m_argslot(slot)
		{}

		inline IArgSlot* getImpl()
		{
			return m_argslot.get();
		}

		template <typename ArgT>
		inline int argSet(ArgT const& arg)
		{
			ArgPayload _payload;
			_payload.data = std::make_shared<ArgT>(arg);
			_payload.size = sizeof(arg);
			return m_argslot->argSet(_payload);
		}

		inline int argBindBuffer(std::string const& bufferTag)
		{
			return m_argslot->argBindBuffer(std::move(bufferTag));
		}

		inline int argBindImage(std::string const& imageTag)
		{
			return m_argslot->argBindImage(std::move(imageTag));
		}

	protected:
		ArgSlotHandle m_argslot;
	};
	using ArgIOHandle = std::shared_ptr<ArgIO>;


	class IKernelSlot
	{
	public:
		virtual ArgIO* getArgSlot(size_t argIdx) const = 0;
		virtual ArgIO* getArgSlot(std::string const& argName) const = 0;
	};

	using KernelSlotHandle = std::unique_ptr<IKernelSlot>;


	/**
	* @class	KernelIO
	* @brief	Object to access all the Kernel Arg IO Slots for the kernel.
	*/
	class KernelIO final
	{
	public:
		KernelIO(IKernelSlot* slot)
			: m_kernelSlot(slot)
		{}

		inline IKernelSlot* getImpl()
		{
			return m_kernelSlot.get();
		}

		template<typename ArgT>
		inline void argSet(size_t argIdx, ArgT const& arg)
		{
			m_kernelSlot->getArgSlot(argIdx)->argSet<ArgT>(arg);
		}

		/* argName should be exactly same as in the _kernel source */
		template<typename ArgT>
		inline void argSet(std::string const& argName, ArgT const& arg)
		{
			m_kernelSlot->getArgSlot(argName)->argSet<ArgT>(arg);
		}

		inline void argBindBuffer(size_t argIdx, std::string const& bufferTag)
		{
			m_kernelSlot->getArgSlot(argIdx)->argBindBuffer(bufferTag);
		}

		inline void argBindBuffer(std::string const& argName, std::string const& bufferTag)
		{
			m_kernelSlot->getArgSlot(argName)->argBindBuffer(bufferTag);
		}

		inline void argBindImage(size_t argIdx, std::string const& imageTag)
		{
			m_kernelSlot->getArgSlot(argIdx)->argBindImage(imageTag);
		}

		inline void argBindImage(std::string const& argName, std::string const& imageTag)
		{
			m_kernelSlot->getArgSlot(argName)->argBindImage(imageTag);
		}

	protected:
		KernelSlotHandle m_kernelSlot;
	};
	using KernelIOHandle = std::shared_ptr<KernelIO>;



	class IDispatchSlot
	{
	public:
		virtual KernelIO* getKernelIO(std::string const& kernelName, std::string const& kernelNamespace = "global") const = 0;
	};
	using DispatchSlotHandle = std::unique_ptr<IDispatchSlot>;


	class DispatchIO final
	{
	public:
		DispatchIO(IDispatchSlot* slot)
			: m_dispatchSlot(slot)
		{}

		IDispatchSlot* getImpl() const
		{
			return m_dispatchSlot.get();
		}

		KernelIO* getKernelIO(std::string const& kernelName, std::string const& kernelNamespace = "global") const
		{
			return m_dispatchSlot->getKernelIO(kernelName, kernelNamespace);
		}

	protected:
		DispatchSlotHandle m_dispatchSlot;
	};

	using DispatchIOHandle = std::shared_ptr<DispatchIO>;


	/**
	* @class	IApplicationComputePipeline
	* @brief	This is the interface of the complete compute pipeline. Application holds one object of
	*			a implementation of this interface to communicate with and configure the compute pipeline.
	*
	* #improvement -	Keep on enhancing this interface. Exposing a builder for this object through a GUI/scripting
	*					will allow full configuration of the compute pipeline.
	*/
	class IApplicationComputePipeline
	{
	public:
		virtual DataIO* getDataIO() = 0;
		virtual DispatchIO* getDispatchIO() = 0;
		virtual KernelIO* getKernelIO(std::string const& kernelName, std::string const& kernelNamespace = "global") = 0;
		
		virtual std::vector< BufferDescription > const& getBufferDescriptions() = 0;
		virtual std::vector< ImageDescription > const& getImageDescriptions() = 0;
		virtual std::vector< DispatchDescription > const& getDispatchDescriptions() = 0;

		virtual void initDataIO(DataIOHandle const&& dataio) = 0;
		virtual void initDispatchIO(DispatchIOHandle const&& dataio) = 0;

		virtual int dispatch(DispatchPayload const& payload) = 0;

		/* The application will provide the concrete implementation */
		virtual int setupAppComputePipeline() = 0;
	};

	using AppComputePipelineHandle = std::shared_ptr<IApplicationComputePipeline>;


	template
		<
		typename app_manager,
		typename compute_manager
		>
	class T_AppComputePipeline
		: public IApplicationComputePipeline
	{
	public:
		T_AppComputePipeline(app_manager* appmgr, compute_manager * cmpmgr)
			: m_appManager(appmgr)
			, m_computeManager(cmpmgr)
		{}

		inline app_manager* getAppManager()
		{
			return m_appManager;
		}

		inline compute_manager* getComputeManager() 
		{
			return m_computeManager;
		}

		virtual DataIO* getDataIO() override final
		{
			return m_dataIO.get();
		}

		virtual DispatchIO* getDispatchIO() override final
		{
			return m_dispatchIO.get();
		}

		virtual KernelIO* getKernelIO(std::string const& kernelName, std::string const& kernelNamespace = "global") override final
		{
			return m_dispatchIO->getKernelIO(kernelName, kernelNamespace);
		}

		virtual std::vector< BufferDescription > const& getBufferDescriptions() override final
		{
			return m_bufferDescriptions;
		}

		virtual std::vector< ImageDescription > const& getImageDescriptions() override final
		{
			return m_imageDescriptions;
		}

		virtual std::vector< DispatchDescription > const& getDispatchDescriptions() override final
		{
			return m_dispatchDescriptions;
		}

		virtual void initDataIO(DataIOHandle const&& dataio) override final
		{
			m_dataIO = std::move(dataio);
		}
		 
		virtual void initDispatchIO(DispatchIOHandle const&& dispatchio) override final
		{
			m_dispatchIO = std::move(dispatchio);
		}

		virtual int dispatch(DispatchPayload const& payload) override final
		{
			return m_computeManager->dispatch(payload);
		}

		/* The application will provide the concrete implementation */
		virtual int setupAppComputePipeline() = 0;

	protected:
		app_manager * m_appManager;
		compute_manager * m_computeManager;

		/* These descriptions are retained after initialization so that pipeline could be re-initialized if required */
		/* #improvement - provide a layer to add and delete during runtime (just need to add two fuctions) */
		std::vector< BufferDescription > m_bufferDescriptions;
		std::vector< ImageDescription > m_imageDescriptions;
		std::vector< DispatchDescription > m_dispatchDescriptions;

	private:
		DataIOHandle			m_dataIO;
		DispatchIOHandle		m_dispatchIO;
	};

}


#endif // !I_COMPUTE_APP_MANAGER