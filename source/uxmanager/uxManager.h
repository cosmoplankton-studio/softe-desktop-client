/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uxManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef UX_MANAGER
#define UX_MANAGER

#include "../devicemanager/Idevice.h"
#include "../devicemanager/IgraphicsAppManager.h"
#include "../devicemanager/graphicsManager.h"
#include "IuxAppManager.h"


namespace gc = graphics_compute;

namespace ux
{
	enum UxEventType
	{
		UX_EVENT_UNDEFINED,

		UX_EVENT_WINDOW_DRAW,
		UX_EVENT_WINDOW_RESIZE,

		UX_EVENT_MOUSE_L_DOWN,
		UX_EVENT_MOUSE_R_DOWN,
		UX_EVENT_MOUSE_M_DOWN,
		UX_EVENT_MOUSE_MOVE,
		UX_EVENT_MOUSE_L_DBLCLICK,
		UX_EVENT_MOUSE_R_DBLCLICK,

		UX_EVENT_KEY_CTRL,
		UX_EVENT_KEY_SHIFT
	};

	struct UxEventInfo
	{
		UxEventType		event{ UX_EVENT_UNDEFINED };
		uint32_t		mouseX{ 1 };
		uint32_t		mouseY{ 1 };


		uint32_t		appWidth{ 1 };
		uint32_t		appHeight{ 1 };

		std::string		userText;
	};



	/**
	* @class   IUxManager
	* @brief   Abstract Interface for a Ux Manager.
	*
	*/
	class IUxManager
	{

	public:
		IUxManager(I_UxAppManager* appMgr)
			: p_appMgr(appMgr)
		{}

		virtual ~IUxManager()
		{}

		/**
		* @brief	Create the appropriate Ux Manager e.g. 2DManager, vrManager, arManager.
		*
		* @param
		*
		* @return	Handle to the Graphics Manager.
		*/
		static UxManagerHandle CreateUxManager(I_UxAppManager* appManager, UxEnvironment uxEnv);

		inline I_UxAppManager* getAppManager() { return p_appMgr; }
		inline ::graphics_compute::AppGraphicsPipelineHandle &getAppGraphicsPipeline() { return getAppManager()->getAppGraphicsPipeline(); }

		virtual unsigned int getAppWidth() = 0;
		virtual unsigned int getAppHeight() = 0;
		virtual unsigned int getAppDepth() = 0;

		virtual void setAppWidth(unsigned int width) = 0;
		virtual void setAppHeight(unsigned int height) = 0;
		virtual void setAppDepth(unsigned int depth) = 0;

		virtual int getGraphicsStageDescription(gc::StageDescription &uiStageDescription) = 0;
		virtual int initUxEnvironment(AppUserInterfaceHandle& appUIHandle) = 0;
		virtual int handleUxEvents(UxEventInfo eventInfo) = 0;

		virtual int frameDraw() = 0;
		virtual int appResize() = 0;

	protected:
		I_UxAppManager * p_appMgr;

	};


} // namespace ux

#endif // !UX_MANAGER