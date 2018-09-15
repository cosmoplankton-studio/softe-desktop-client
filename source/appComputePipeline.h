/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appGraphicsPipeline.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef APPLICATION_COMPUTE_PIPELINE
#define APPLICATION_COMPUTE_PIPELINE


#include "devicemanager/IcomputeAppManager.h"


namespace app
{
	class IApplication;

	/*
	* Default Pipeline for this application.
	*/
	class AppComputePipeline final
		: public graphics_compute::T_AppComputePipeline
		<
		IApplication,
		graphics_compute::IComputeManager
		>
	{
	public:
		AppComputePipeline(IApplication *appMgr, graphics_compute::IComputeManager *cMgr)
			: T_AppComputePipeline
			<
			IApplication,
			graphics_compute::IComputeManager
			>
			(appMgr, cMgr)
		{}

		virtual ~AppComputePipeline()
		{}

		virtual int setupAppComputePipeline() override final;
	};

}


#endif // !APPLICATION_COMPUTE_PIPELINE