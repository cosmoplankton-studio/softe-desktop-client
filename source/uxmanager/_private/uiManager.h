/*
* ---------------------------------------------------------
* Copyright 2018 - present(c) Automatos Studios.All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uiManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef UI_MANAGER
#define UI_MANAGER


#include "uxDefines.h"
#include "uiBase.h"

namespace ui
{

	class UiManager
	{
	public:
		UiManager(::ux::IUxManager*	mgr);

		virtual ~UiManager();

		inline ux::IUxManager* getUxManager()
		{ 
			return p_mgr;
		}

		int getGraphicsStageDescription(gc::StageDescription &uiStageDescription);
		void getOrthoProjMatrix(DataHandle &projData, unsigned int &projSize);

		void writeToDeviceInitData();
		void writeToDeviceFrameVertexData();

		void processEvents(::ux::UxEventInfo eventInfo);
		void addComponentsToCanvas();

		template
			<
			typename mode_type,
			typename callback_arg1
			>
			ButtonBoxHandle& createModeBar(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
		{
			p_modeBars[tag] = std::make_shared< ModeBar< mode_type, callback_arg1 > >(tag, x, y, w, h);
			return p_modeBars[tag];
		}

		template
			<
			typename tool_type,
			typename callback_arg1
			>
			ButtonBoxHandle& createToolBar(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
		{
			p_toolBars[tag] = std::make_shared< ToolBar< tool_type, callback_arg1 > >(tag, x, y, w, h);
			return p_toolBars[tag];
		}

	protected:
		::ux::IUxManager*	p_mgr;

		std::map< std::string, ButtonBoxHandle > p_modeBars;
		std::map< std::string, ButtonBoxHandle > p_toolBars;
		NkEngineHandle		p_uiEngine; /* #improvement - create an abstract uiEngine */
	};

} // namespace ui



#endif //! UI_MANAGER