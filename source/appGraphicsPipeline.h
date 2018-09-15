/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appGraphicsPipeline.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef APPLICATION_GRAPHICS_PIPELINE
#define APPLICATION_GRAPHICS_PIPELINE


#include "devicemanager/IgraphicsAppManager.h"

namespace app
{
	class IApplication;

	/*
	* Default Pipeline for this application.
	*/
	class AppGraphicsPipeline final
		: public graphics_compute::T_ApplicationGraphicsPipeline
		<
		IApplication,
		graphics_compute::IGraphicsManager
		>
	{
	public:
		AppGraphicsPipeline(IApplication *appMgr, graphics_compute::IGraphicsManager *gMgr)
			: T_ApplicationGraphicsPipeline
			<
			IApplication,
			graphics_compute::IGraphicsManager
			>
			(appMgr, gMgr)
		{}

		virtual ~AppGraphicsPipeline()
		{}

		virtual int setupGraphicsPipelineStages();
	};


} // namespace app


#endif // !APPLICATION_GRAPHICS_PIPELINE