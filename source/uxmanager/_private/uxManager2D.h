/*
* ---------------------------------------------------------
* Copyright 2018 - present(c) Automatos Studios.All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uxManager2D.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef UX_MANAGER_2D
#define UX_MANAGER_2D


#include "uxDefines.h"



namespace ux
{
	
	class UxManager2D : public IUxManager
	{

	public:
		UxManager2D(I_UxAppManager* appMgr);

		virtual ~UxManager2D();

		virtual unsigned int getAppWidth() { return p_appWidth; }
		virtual unsigned int getAppHeight() { return p_appHeight; }
		virtual unsigned int getAppDepth() { assert(0); return 0; }

		virtual void setAppWidth(unsigned int width) { p_appWidth = width; }
		virtual void setAppHeight(unsigned int height) { p_appHeight = height; }
		virtual void setAppDepth(unsigned int depth) { assert(0); }

		virtual int handleUxEvents(UxEventInfo eventInfo);
		virtual int initUxEnvironment(AppUserInterfaceHandle& appUIHandle);
		virtual int getGraphicsStageDescription(gc::StageDescription &uiStageDescription);

		virtual int frameDraw();
		virtual int appResize();

	protected:
		virtual int pProcessUiEvents(UxEventInfo eventInfo);
		virtual int pPrepareFrame();
		virtual int pPrepareUi();
		virtual int pPrepareModelViz();

	protected:
		unsigned int	p_appWidth;
		unsigned int	p_appHeight;
		unsigned int	p_appDepth;

		ui::UiManagerHandle			p_uiManager;
		AppUserInterfaceHandle		p_appUIHandle;

	};

} // namespace ux



#endif // !UX_MANAGER_2D