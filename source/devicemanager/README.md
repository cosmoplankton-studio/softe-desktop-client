### Overview of the ```devicemanager``` library:
> * Section A - Provides an overview of graphics backend and how to setup a graphics pipeline.
> * Section B - Provides an overview of compute backend and how to setup a compute pipeline.

## ``` A. Graphics ```
#

#### ```IGraphicsManager```  ([graphicsManager.h](graphicsManager.h))

> Abstract interface to the graphics backend.
> Concrete Vulkan(R) implementation ```vkManager```([vkManager.h](_private/vkManager.h)) is private and not visible to external applications.
#
### Any 3D application that intends to use this graphics backend should provide :
* A concrete implementation of ```IApplicationGraphicsPipeline``` ([IgraphicsAppManager.h](IgraphicsAppManager.h)) and use this object to setup the application graphics pipeline and stageIO communications.
* A concrete implementation of ```I_GraphicsAppManager``` ([IgraphicsAppManager.h](IgraphicsAppManager.h)) so that the graphics backend could query for relevant runtime details from the application.

#
### Below provides details of structures/classes used to setup a graphics pipeline.

* ```StageType``` The backend provides various stages which will get executed. A stage could have multiple pipelines, vertex buffers, and draw descriptions.
* ```DataAttribute``` Provides details for the definition of a logical data unit - dataformat and datalayout of buffers and textures.
* ```DataUpdateScheme``` Details about update rate of data. Per-frame update or on-demand.
* ```DataDescription``` Description of a particular data resource fed to the pipeline.
* ```StageUniformDataDescription``` Provide uniform description (logical data resource for uniform, vertex, index, etc.) to be used in the stages. Oject storing description of how a data (buffer) resource would get allocated in the pipeline.
* ```StageTextureDataDescription``` Provide texture description (logical data resource for images, textures, animation encoded in texture, etc.) to be used in the stages. Oject storing description of how a data (texture) resource would get allocated in the pipeline.
* ```StageRenderTargetDescription``` Provide render-target description (present to screen or do offscreen rendering (batch/deffered)). Object storing description of how a data (render attachment) resource would get allocated in the pipeline.
* ```StageDrawDescription``` Provide stage draw description. A stage could have multiple draws. Oject storing description of a particular draw. Which pipeline layout to use, which data resources to bind as input/data, which shader to use, which target to render/ouput to, etc.
* ```StageLayoutBindingDescription``` Oject storing description of a single pipeline data binding.
* ```StageShaderDescription``` Provide shader description for the draw.
* ```StageDescription``` Oject storing the complete description (data descriptions, pipeline descriptions and draw descriptions) for a particular stage.
* ```IStageInputSlotBase``` Graphics Manager creates and provides objects of these types for each initialized stages. The ApplicationGraphicsPipeline object passed to the Graphics manager stores these objects for all data slots. Application will use this to transfer data to the Graphics Backend. A particular render stage could have multiple input slots. See decsription above. These slots facilitate multi-thread access and synchronization for data write/access during the application run.
* ```StageIO``` The object the application will use to transfer data to the backend. Application could compute and then transfer data using multiple threads.
* ```ApplicationGraphicsPipelineStage``` This objects represents a single Pipeline Stage. Holds both the stage description and IO object. Application could configure and communicate with a particular stage through this object.
* ```IApplicationGraphicsPipeline``` This is the interface of the complete graphics pipeline. Application holds one object of a implementation of this interface to communicate with and configure the graphics pipeline. Object initialized with stage descriptions and StageIO slots for communication between application and graphics-backend.

3D Applications could setup complex pipelines using the available stages - ```eUI```, ```eMultiMaterial```, ```eWireframe```, ```eOffScreen```, and ```eOffScreenConsume```.

#

## ``` B. Compute ```
#

#### ```IComputeManager```  ([computeManager.h](computeManager.h))

> Abstract interface to the compute backend.
> Concrete OpenCL(R) implementation ```oclManager```([oclManager.h](_private/oclManager.h)) is private and not visible to external applications.
#
### Any 3D application that intends to use this compute backend should provide :
* A concrete implementation of ```IApplicationComputePipeline``` ([IcomputeAppManager.h](IcomputeAppManager.h)) and use this object to setup the application compute pipeline, and kernelIO and Execution communications.
* A concrete implementation of ```I_ComputeAppManager``` ([IcomputeAppManager.h](IcomputeAppManager.h)).