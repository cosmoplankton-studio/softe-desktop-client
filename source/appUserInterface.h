/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appUserInterface.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef APPLICATION_UI
#define APPLICATION_UI

#include <stdint.h>
#include "uxmanager/IuxAppManager.h"


namespace app
{
	class IApplication;

	
	class AppUserInterface final
		: public ux::T_AppUserInterface< IApplication* >
	{
	public:
		AppUserInterface(IApplication* appmgr)
			: T_AppUserInterface< IApplication* >(appmgr)
		{}

		virtual ~AppUserInterface()
		{}

		virtual void setupAppUserInterface();
		virtual void onModeChanged(uint32_t activeMode);
		virtual void onSecondaryModeChanged(uint32_t activeMode);
		virtual void onToolChanged(uint32_t activeTool);

	};

}

#endif // !APPLICATION_UI