/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/


/**
* @file			IgraphicsAppManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


/*
********************************************************************************
* IGraphicsManager (file: graphicsManager.h)
* Abstract interface to the graphics backend.
* Concrete VULKAN(R) implementation (vkManager.h) is private and not visible to external applications.
*-------------------------------------------------------------------------------
* Any 3D application that intends to use this graphics backend should provide :
* [1] a concrete implementation of "IApplicationGraphicsPipeline" (file: IgraphicsAppManager.h)
* and use this object to setup the application graphics pipeline.
* [2] a concrete implementation of "I_GraphicsAppManager" (file: IgraphicsAppManager.h)
* so that the graphics backend could query for relevant runtime details from the application.
********************************************************************************
* Below provides details of components used to setup a graphics pipeline.
*-------------------------------------------------------------------------------
* [A] StageType -	The backend provides various stages which will get executed.
*					A stage could have multiple vertex buffers and draw descriptions.
* [B] DataAttribute - Provide details for the dataformat and datalayout of buffers and textures.
* [C] DataUpdateScheme - Details about update rate of data. Per-frame update or on-demand.
* [D] DataDescription - Available data descriptions.
* [E] StageBufferDataDescription - Provide uniform description (uniform, vertex, index, etc.) to be used in the stages.
* [F] StageImageDataDescription - Provide texture description.
* [G] StageRenderTargetDescription - Provide render-target description (present to screen or do offscreen rendering(batch/deffered))
* [H] StageDrawDescription - Provide stage draw description. A stage could have multiple draws.
* [I] StageLayoutBindingDescription - Pipeline data binding for the draw (shader bindings and input vertex bindings).
* [J] StageShaderDescription - Provide shader description for the draw.
* [K] StageDescription - Complete description of a stage.
* [L] StageIO - The object the application will use to transfer data to the backend.
*				Application could transfer data using multiple theads.
* [M] IApplicationGraphicsPipeline -	Object initialized with stage descriptions and StageIO slots
*										for communication between application and graphics-backend.
********************************************************************************
* 3D Applications could setup complex pipelines using the available stages 
* (eUI, eMultiMaterial, eWireframe, eOffScreen, and eOffScreenConsume). #improvement - add more stages.
********************************************************************************
*/



#ifndef I_GRAPHICS_APP_MANAGER
#define I_GRAPHICS_APP_MANAGER

#include <set>
#include <map>
#include <unordered_map>
#include <vector>
#include <memory>


namespace graphics_compute
{

	class IGraphicsManager;
	typedef std::shared_ptr< IGraphicsManager > GraphicsManagerHandle;

	/**
	* @class	I_GraphicsAppManager
	* @brief	Any application that intends to utilize the graphicsManager should
	*			provide a concrete implementation of this interface.
	*/
	class I_GraphicsAppManager
	{
	public:
		virtual void*	getAppConnection() = 0;
		virtual void*	getAppWindow() = 0;
		virtual int		getFrameWidth() = 0;
		virtual int		getFrameHeight() = 0;
		virtual int		setFrameWidth(unsigned int width) = 0;
		virtual int		setFrameHeight(unsigned int height) = 0;

		virtual void	GRAPHICS_LOGMESSAGE(std::string const&) = 0;
		virtual void	GRAPHICS_LOGERROR(std::string const&) = 0;
	};



	/**
	* @enum		StageType
	* @brief	Different stages available (a single stage could have multiple pipelines and draw descriptions).
	*/
	enum class StageType : uint32_t
	{
		eUndefined = 0x0,
		eUI = 0x1,
		eMultiMaterial = 0x2,
		eWireframe = 0x3,
		eOffScreen = 0x4,
		eOffScreenConsume = 0x5
	};



	/**
	* @enum		ShaderStage
	* @brief	Different shader stages of the pipeline.
	*/
	enum class ShaderStage : uint32_t
	{
		eUndefined = 0x0,
		eVertex = 0x1,
		eFragment = 0x2,
		eAllGraphics = 0x3
	};
	
	
	/**
	* @enum		DataUpdateScheme
	* @brief	How data is going to be updated (per frame, only on-demand).
	*/
	enum class DataUpdateScheme : uint32_t
	{
		eUndefined = 0x0,
		eFrameStatic = 0x1,
		eFrameDynamic = 0x2
	};


	/**
	* @class	StageBufferDataDescription
	* @brief	Oject storing description of how a data(buffer) resource would get allocated in the pipeline.
	*/
	class StageBufferDataDescription
	{
		using _ThisRef = StageBufferDataDescription&;

	public:
		inline auto const& getTag() const { return m_dataTag; }
		inline auto getDataAccessQualifier() const { return m_dataAccessQ; }
		inline auto getMaxCount() const { return m_maxUnitCount; }
		inline auto getDataUpdateScheme() const { return m_dataUpdateScheme; }
		inline auto const& getDataAttributes() const { return m_dataAttributes; }

		inline _ThisRef setTag(std::string const& tag) { m_dataTag = tag; return *this; }
		inline _ThisRef setDataAccessQualifier(device::DataAccessQualifier aQ) { m_dataAccessQ = aQ; return *this; }
		inline _ThisRef setMaxCount(uint32_t count) { m_maxUnitCount = count; return *this; }
		inline _ThisRef setDataUpdateScheme(DataUpdateScheme scheme) { m_dataUpdateScheme = scheme; return *this; }
		inline _ThisRef setDataAttributes(device::DataAttributeList const& attributes) { m_dataAttributes = attributes; return *this; }

	protected:
		std::string		m_dataTag{ "" };
		uint32_t		m_maxUnitCount{ 0 };

		DataUpdateScheme m_dataUpdateScheme{ DataUpdateScheme::eFrameDynamic };
		device::DataAttributeList m_dataAttributes;
		device::DataAccessQualifier m_dataAccessQ{ device::DataAccessQualifier::eHostToDevice };
	};


	/**
	* @class	StageImageDataDescription
	* @brief	Oject storing description of how a data(image) resource would get allocated in the pipeline.
	*/
	class StageImageDataDescription
	{
		using _ThisRef = StageImageDataDescription&;

	public:
		inline auto & getTag() const { return m_textureTag; }
		inline auto getDataAccessQualifier() const { return m_dataAccessQ; }
		inline auto getWidth() const { return m_texWidth; }
		inline auto getHeight() const { return m_texHeight; }
		inline auto getDepth() const { return m_texDepth; }
		inline auto getDataFormat() const { return m_dataFormat; }
		inline auto getDataUpdateScheme() const { return m_dataUpdateScheme; }

		inline _ThisRef setTag(std::string const& tag) { m_textureTag = tag; return *this; }
		inline _ThisRef setDataAccessQualifier(device::DataAccessQualifier aQ) { m_dataAccessQ = aQ; return *this; }
		inline _ThisRef setWidth(uint32_t width) { m_texWidth = width; return *this; }
		inline _ThisRef setHeight(uint32_t height) { m_texHeight = height; return *this; }
		inline _ThisRef setDepth(uint32_t depth) { m_texDepth = depth; return *this; }
		inline _ThisRef setDataFormat(device::DataFormat format) { m_dataFormat = format; return *this; }

	protected:
		std::string			m_textureTag{ "" };
		DataUpdateScheme	m_dataUpdateScheme{ DataUpdateScheme::eFrameStatic };
		device::DataFormat	m_dataFormat{ device::DataFormat::eA8 };
		uint32_t			m_texWidth{ 1 };
		uint32_t			m_texHeight{ 1 };
		uint32_t			m_texDepth{ 1 };

		device::DataAccessQualifier m_dataAccessQ{ device::DataAccessQualifier::eHostToDevice };
	};


	enum class RenderTargetType : uint32_t
	{
		eUndefined = 0x0,
		ePresent = 0x1,
		eOffScreen = 0x2
	};


	/**
	* @class	StageRenderTargetDescription
	* @brief	Oject storing description of how a data(render attachment) resource would get allocated in the pipeline.
	*/
	class StageRenderTargetDescription
	{
		using _ThisRef = StageRenderTargetDescription&;

	public:
		inline _ThisRef setTag(std::string const& tag) { targetTag = tag; return *this; }
		inline _ThisRef setTargetType(RenderTargetType type) { targetType = type; return *this; }
		inline _ThisRef setBindingIdx(uint32_t idx) { bindingIdx = idx; return *this; }

		inline auto &getTag() const { return targetTag; }
		inline auto getTargetType() const { return targetType; }
		inline auto getBindingIdx() const { return bindingIdx; }

	protected:
		std::string			targetTag{ "" };
		RenderTargetType	targetType{ RenderTargetType::ePresent };
		uint32_t			bindingIdx{ 0 };
	};

	
	/**
	* @class	StageShaderDescription
	* @brief	Oject storing description of a pipeline shader.
	*/
	class StageShaderDescription
	{
		using _ThisRef = StageShaderDescription & ;

	public:
		inline _ThisRef setRawTextShadersFlag(bool flag) { m_rawTextShaders = flag; return *this; }
		inline _ThisRef setShader(ShaderStage stage, std::string const& shader) { m_shaders[stage] = shader; return *this; }

		inline auto getRawTextShadersFlag() const { return m_rawTextShaders; }
		inline auto &getShaders() const { return m_shaders; }

	protected:
		bool m_rawTextShaders{ false };
		std::map< ShaderStage, std::string > m_shaders;
	};



	/**
	* @class	StageLayoutBindingDescription
	* @brief	Oject storing description of a single pipeline data binding.
	*/
	class StageLayoutBindingDescription
	{
		using _ThisRef = StageLayoutBindingDescription & ;

	public:
		inline _ThisRef setDataTags(std::vector<std::string> const& tags) { m_dataTags = tags; return *this; }
		inline _ThisRef setShaderStage(ShaderStage stage) { m_shaderStage = stage; return *this; }
		inline _ThisRef setDataDescription(device::DataDescription desc) { m_dataDescription = desc; return *this; }

		inline device::DataDescription getDataDescription() const { return m_dataDescription; }
		inline ShaderStage getShaderStage() const { return m_shaderStage; }
		inline auto const& getDataTags() const { return m_dataTags; }

	protected:
		device::DataDescription		m_dataDescription;
		ShaderStage					m_shaderStage;
		std::vector< std::string >	m_dataTags;
	};



	/**
	* @class	StageDrawDescription
	* @brief	Oject storing description of a particular draw. Which pipeline layout to use,
	*			which data resources to bind as input/data, which shader to use, which target to render/ouput to, etc.
	*/
	class StageDrawDescription final
	{
		using _ThisRef = StageDrawDescription&;
		using _BindingMap = std::map< uint32_t, StageLayoutBindingDescription >;

	public:
		inline _ThisRef setTag(std::string const& tag) { m_tag = tag; return *this; }
		inline _ThisRef setVertexTag(std::string const& tag) { m_vertexDataTag = tag; return *this; }
		inline _ThisRef setIndexTag(std::string const& tag) { m_indexDataTag = tag; return *this; }
		inline _ThisRef setRenderTargetTags(std::vector< std::string > const& tags) { m_rendertargetTags = tags; return *this; }
		inline _ThisRef setShaderDescription(StageShaderDescription const& info) { m_shaderDescription = info; return *this; }
		inline _ThisRef setLayoutBindingDescription(uint32_t idx, StageLayoutBindingDescription const& info) { m_layoutBindings[idx] = info; return *this; }
		
		// This is not customizable for now //
		// inline this_ref setDrawAttributes(DataAttributeList const& attributes) { m_drawAttributeList = attributes; return *this; } //
		StageDrawDescription()
		{
			device::DataAttribute indexCount, indexFirst, vertexOffset;
			indexCount.setType(device::DataAttributeType::eDrawIndexCount).setFormat(device::DataFormat::eUint32);
			indexFirst.setType(device::DataAttributeType::eDrawIndexFirst).setFormat(device::DataFormat::eUint32);
			vertexOffset.setType(device::DataAttributeType::eDrawIndexVertexOffset).setFormat(device::DataFormat::eUint32);

			m_drawAttributeList = { indexCount , indexFirst , vertexOffset };
		}

		inline auto & getTag() const { return m_tag; }
		inline auto & getVertexTag() const { return m_vertexDataTag; }
		inline auto & getIndexTag() const { return m_indexDataTag; }
		inline auto & getRenderTargetTags() const { return m_rendertargetTags; }
		inline auto & getShaderDescription() const { return m_shaderDescription; }
		inline auto & getLayoutBindings() const { return m_layoutBindings; }
		inline auto & getDrawAttributes() const { return m_drawAttributeList; }
		inline auto getDataUpdateScheme() const { return m_dataUpdateScheme; }

	protected:
		std::string m_tag{ "draw_primary" };
		std::string m_vertexDataTag;
		std::string m_indexDataTag;
		std::vector< std::string > m_rendertargetTags;

		StageShaderDescription m_shaderDescription;
		_BindingMap m_layoutBindings;

		/* 
		#improvement : multidraw support - we need to check device feature support.
		#improvement : instance support.
		*/
		DataUpdateScheme m_dataUpdateScheme{ DataUpdateScheme::eFrameDynamic };
		const uint32_t m_drawCount{ 1 };
		device::DataAttributeList m_drawAttributeList;
	};


	/**
	* @class	StageDescription
	* @brief	Oject storing all the descriptions (data descriptions, pipeline descriptions and draw descriptions) for a particular stage.
	*/
	template
		<
		typename description_vertex,
		typename description_index,
		typename decsription_uniform,
		typename description_texture,
		typename description_rendertarget,
		typename description_draw
		>
	class T_StageDescription
	{
	public:
		template<device::DataDescription _DesType>
		struct data_trait
		{
			using dtype = void;
		};

		using decsriptions_handle = std::shared_ptr<void>;

		template<> struct data_trait<device::DataDescription::eVertex> { using dtype = std::map< std::string, description_vertex>; };
		template<> struct data_trait<device::DataDescription::eIndex> { using dtype = std::map< std::string, description_index>; };
		template<> struct data_trait<device::DataDescription::eUniform> { using dtype = std::map< std::string, decsription_uniform>; };
		template<> struct data_trait<device::DataDescription::eTexture> { using dtype = std::map< std::string, description_texture>; };
		template<> struct data_trait<device::DataDescription::eRenderTarget> { using dtype = std::map< std::string, description_rendertarget>; };
		template<> struct data_trait<device::DataDescription::eDraw> { using dtype = std::map< std::string, description_draw >; };

	public:
		T_StageDescription()
		{}

		T_StageDescription(StageType type)
			: m_stageType(type)
		{}

		inline void setType(StageType type) { m_stageType = type; }

		inline StageType getType() { return m_stageType; }

		template<device::DataDescription _DesType>
		inline typename data_trait<_DesType>::dtype& getDescriptions()
		{
			if (!m_stageDescriptions[_DesType])
			{
				m_stageDescriptions[_DesType].reset(new typename data_trait<_DesType>::dtype());
			}
			
			return *reinterpret_cast< typename data_trait<_DesType>::dtype* >(m_stageDescriptions[_DesType].get());
		}

	protected:
		StageType m_stageType{ StageType::eUndefined };
		std::map<device::DataDescription, decsriptions_handle> m_stageDescriptions;
	};

	
	/*
	#improvement - enhance this customization.
	*/
	using StageDescription = T_StageDescription
		<
		StageBufferDataDescription,
		StageBufferDataDescription,
		StageBufferDataDescription,
		StageImageDataDescription,
		StageRenderTargetDescription,
		StageDrawDescription
		>;


	/**
	* @class	IStageInputSlotBase
	* @brief	Graphics Manager creates and provides objects of these types for each initialized stages.
	*			The ApplicationGraphicsPipeline object passed to the Graphics manager stores these objects for all data slots.
	*			Application will use this to transfer data to the Graphics Backend. A particular render stage could have
	*			multiple input slots. See decsription above.
	*			These slots facilitate multi-thread access and synchronization for data write/access during the application run.
	*
	*/
	class IStageInputSlotBase
	{
	public:

		IStageInputSlotBase();
		virtual ~IStageInputSlotBase();

		/* #improvement - add more synchronization primitives */
		virtual int putFence();
		virtual int removeFence();
		virtual int waitFence();

		virtual int writeData(void* inputData, uint32_t dataSize) = 0;
		virtual int appendData(void* inputData, uint32_t dataSize) = 0;

	protected:
		void*	m_lock;
	};

	using StageInputSlotBaseHandle = std::shared_ptr< IStageInputSlotBase  >;
	using StageInputSlotTable = std::map< std::string, StageInputSlotBaseHandle >;

	class StageInputSlots;
	using StageInputSlotsHandle = std::shared_ptr< StageInputSlots >;

	

	/**
	* @class	StageIO
	* @brief	This objects stores all the data slots a particular pipeline stage.
	* #improvement - hide the implementation, provide output sloy, and dependency slot.
	*/
	class StageIO
	{
	public:
		StageIO()
		{}

		~StageIO()
		{}

		template< device::DataDescription > inline auto const& slotinput(std::string const& tag);
		template<> inline auto const& slotinput<device::DataDescription::eVertex>(std::string const& tag)
		{
			return m_inputSlots[device::DataDescription::eVertex][tag];
		}
		template<> inline auto const& slotinput<device::DataDescription::eIndex>(std::string const& tag)
		{
			return m_inputSlots[device::DataDescription::eIndex][tag];
		}
		template<> inline auto const& slotinput<device::DataDescription::eUniform>(std::string const& tag)
		{
			return m_inputSlots[device::DataDescription::eUniform][tag];
		}
		template<> inline auto const& slotinput<device::DataDescription::eTexture>(std::string const& tag)
		{
			return m_inputSlots[device::DataDescription::eTexture][tag];
		}
		template<> inline auto const& slotinput<device::DataDescription::eDraw>(std::string const& tag)
		{
			return m_inputSlots[device::DataDescription::eDraw][tag];
		}

		inline void createSlot(device::DataDescription descriptor, std::string const& dataTag, StageInputSlotBaseHandle const& slot)
		{
			m_inputSlots[descriptor][dataTag] = slot;
		}

		/* wait for all the slots before going ahead with the graphics pipeline draw dispatches */
		/* #improvement - add individual slots so that we could go ahead with one stage if a later stage slot is blocked */
		inline void waitForAll()
		{
			for (auto &dataSlots : m_inputSlots)
			{
				for (auto &dataSlot : dataSlots.second) dataSlot.second->waitFence();
			}
		}

	protected:

		std::map< device::DataDescription, StageInputSlotTable > m_inputSlots;
	};




	/**
	* @class	ApplicationGraphicsPipelineStage
	* @brief	This objects represents a single Pipeline Stage. Holds both the stage description and IO object.
	*			Application could configure and communicate with a particular stage through this object.
	*/
	class ApplicationGraphicsPipelineStage
	{
	public:
		StageDescription& stageDescription()
		{
			return p_stageDescription;
		}

		StageIO& stageIO()
		{
			return p_stageIO;
		}

	protected:
		StageDescription	p_stageDescription;
		StageIO				p_stageIO;
	};
	using stage_map = std::map < StageType, ApplicationGraphicsPipelineStage >;




	/**
	* @class	IApplicationGraphicsPipeline
	* @brief	This is the interface of the complete graphics pipeline. Application holds one object of 
	*			a implementation of this interface to communicate with and configure the graphics pipeline.
	*
	* #improvement -	Keep on enhancing this interface. Exposing a builder for this object through a GUI 
	*					will allow full configuration of the graphics pipeline.
	*/
	class IApplicationGraphicsPipeline
	{
	public:
		virtual ~IApplicationGraphicsPipeline()
		{}
		virtual int setupGraphicsPipelineStages() = 0;
		virtual StageDescription & getStageDescription(StageType stageType) = 0;
		virtual stage_map const& getStages() const = 0;
		virtual StageIO& stageIO(StageType stageType) = 0;
		virtual int frameDraw() = 0;
		virtual int resizeGraphicsResources() = 0;
	};

	using AppGraphicsPipelineHandle = std::shared_ptr<IApplicationGraphicsPipeline>;

	template
		<
		typename app_manager,
		typename graphics_manager
		>
	class T_ApplicationGraphicsPipeline
		: public IApplicationGraphicsPipeline
	{
	public:

		T_ApplicationGraphicsPipeline(app_manager *appMgr, graphics_manager *gMgr)
			: p_appManager(appMgr)
			, p_graphicsManager(gMgr)
		{}

		virtual ~T_ApplicationGraphicsPipeline()
		{}

		virtual int setupGraphicsPipelineStages() = 0;

		inline app_manager* getAppManager() { return p_appManager; }

		inline graphics_manager* getGraphicsManager() { return p_graphicsManager; }
		
		virtual StageDescription & getStageDescription(StageType stageType) final
		{
			return p_pipelineStages[stageType].stageDescription();
		}

		virtual stage_map const& getStages() const final
		{
			return p_pipelineStages;
		}

		virtual StageIO& stageIO(StageType stageType) final
		{
			return p_pipelineStages[stageType].stageIO();
		}

		virtual int frameDraw() final
		{
			return p_graphicsManager->frameDraw();
		}

		virtual int resizeGraphicsResources() final
		{
			return p_graphicsManager->resizeGraphicsResources();
		}

	protected:
		app_manager*		p_appManager;
		graphics_manager*	p_graphicsManager;

		stage_map			p_pipelineStages;
	};

	

}



#endif // !I_GRAPHICS_APP_MANAGER