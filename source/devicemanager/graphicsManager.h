/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			graphicsManager.h
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
* [M] IApplicationGraphicsPipeline -	Interface for a implementations Object initialized with stage descriptions and StageIO slots
*										for communication between application and graphics-backend.
********************************************************************************
* 3D Applications could setup complex pipelines using the available stages
* (eUI, eMultiMaterial, eWireframe, eOffScreen, and eOffScreenConsume). #improvement - add more stages.
********************************************************************************
*/



#ifndef GRAPHICS_MANAGER
#define GRAPHICS_MANAGER



#ifdef SHAREDLIB_EXPORTS
#define GRAPHICS_API __declspec(dllexport)
#else
#define GRAPHICS_API __declspec(dllimport)
#endif
// IMPORTANT - Add GRAPHICS_API exports to private impl. Here these additions are for documenting purposes only.


namespace graphics_compute
{

	/**
	* @class   IGraphicsManager
	* @brief   Abstract Interface for a Graphics Manager.
	*
	*/
	class IGraphicsManager
	{
	public:

		/**
		* @brief	Create the appropriate Graphics manager e.g. VulkanManager or OpenglManager.
		*
		* @param
		*
		* @return	Handle to the Graphics Manager.
		*/
        GRAPHICS_API static GraphicsManagerHandle createGraphicsManager(I_GraphicsAppManager* appManager, device::DeviceApiType apiType, device::HostPtr hostPtr);


        GRAPHICS_API virtual int getDeviceCount(size_t& count) const = 0;

		/**
		* @brief Initialize the graphics instance and devices.
		*
		* @param 
		*
		* @return Error code, any non-zero value specifies an error.
		*/
        GRAPHICS_API virtual int initInstanceAndDevices() = 0;

		/**
		* @brief Initialize the graphics pipeline with the specified stages and buffers.
		*
		* @param AppGraphicsPipelineHandle	Object providing definitions for stages and data for
		*									the graphics pipeline. Object will also get initilized with
		*									IO and SYNC handles for data transfer and synchronization.
		*
		* @return Error code, any non-zero value specifies an error.
		*/
        GRAPHICS_API virtual int initApplicationGraphicsPipeline(AppGraphicsPipelineHandle& appGraphicsPipeline) = 0;

		/**
		* @brief	Draw the application frame.
		*
		* @param
		*
		* @return	Error code, any non-zero value specifies an error.
		*/
        GRAPHICS_API virtual int frameDraw() = 0;

		/**
		* @brief	resize graphics resources.
		*
		* @param
		*
		* @return	Error code, any non-zero value specifies an error.
		*/
        GRAPHICS_API virtual int resizeGraphicsResources() = 0;

	};

} // namespace graphics_compute


#endif // GRAPHICS_MANAGER
