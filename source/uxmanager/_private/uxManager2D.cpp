/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uxManager2D.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "uxManager2D.h"
#include "uiManager.h"


namespace ux
{

	UxManager2D::UxManager2D(I_UxAppManager* appMgr)
		: IUxManager(appMgr)
	{
		p_uiManager = std::make_unique< ::ui::UiManager >(this);
	}


	UxManager2D::~UxManager2D()
	{}


	int UxManager2D::initUxEnvironment(AppUserInterfaceHandle& appUIHandle)
	{
		p_appUIHandle = appUIHandle;
		
		/* ModeBar */
		auto &baseHandle = p_uiManager->createModeBar< uint32_t, void(uint32_t) >("modes", 10, 15, 300, 30);
		auto modeBarPtr = reinterpret_cast<ui::ModeBar< uint32_t, void(uint32_t)>*>(baseHandle.get());
		auto &modes = appUIHandle->getModes();
		for (auto &pMode : modes)
		{
			modeBarPtr->addButton(pMode, appUIHandle->getModeData(pMode));
		}
		modeBarPtr->setOnClick(std::bind(&IAppUserInterface::onModeChanged, appUIHandle.get(), std::placeholders::_1));

		/* SecondaryModeBar */
		uint32_t appWidth = getAppWidth();
		auto &baseSecHandle = p_uiManager->createModeBar< uint32_t, void(uint32_t) >("secondary_modes", appWidth - 300 - 10, 15, 300, 30);
		auto secModeBarPtr = reinterpret_cast<ui::ModeBar< uint32_t, void(uint32_t)>*>(baseSecHandle.get());
		auto &secmodes = appUIHandle->getSecondaryModes();
		for (auto &pSecMode : secmodes)
		{
			secModeBarPtr->addButton(pSecMode, appUIHandle->getSecondaryModeData(pSecMode));
		}
		secModeBarPtr->setOnClick(std::bind(&IAppUserInterface::onSecondaryModeChanged, appUIHandle.get(), std::placeholders::_1));

		/* ToolBar */
		auto &activeToolSet = appUIHandle->getActiveToolset();
		auto &toolset = appUIHandle->getToolSetDescription(activeToolSet);
		uint32_t toolbarWidth = 40;
		uint32_t toolbarHeight = 30 + (toolbarWidth+3) * toolset.getTools().size(); // 30 = titlebar height in pixel; +3 = borderWidths in pixel;

		auto &baseToolHandle = p_uiManager->createToolBar< uint32_t, void(uint32_t) >(activeToolSet.c_str(), appWidth - toolbarWidth - 10, 60, toolbarWidth, toolbarHeight);
		auto toolBarPtr = reinterpret_cast<ui::ToolBar< uint32_t, void(uint32_t)>*>(baseToolHandle.get());
		for (uint32_t pTool : toolset.getTools())
		{
			toolBarPtr->addButton(pTool, toolset.getToolData(pTool));
		}
		toolBarPtr->setOnClick(std::bind(&IAppUserInterface::onToolChanged, appUIHandle.get(), std::placeholders::_1));
		
		/* setup readonly textures and uniforms */
		p_uiManager->writeToDeviceInitData();

		return 0;
	}


	int UxManager2D::getGraphicsStageDescription(gc::StageDescription &uiStageDescription)
	{
		if (p_uiManager)
		{
			return p_uiManager->getGraphicsStageDescription(uiStageDescription);
		}

		return 0;
	}


	int UxManager2D::handleUxEvents(UxEventInfo eventInfo)
	{
		pProcessUiEvents(eventInfo);
		return 0;
	}


	int UxManager2D::frameDraw()
	{
		pPrepareFrame();
		
		return getAppGraphicsPipeline()->frameDraw();
	}


	int UxManager2D::appResize()
	{
		int errCode = 0;
		
		errCode = getAppGraphicsPipeline()->resizeGraphicsResources();
		errCode = initUxEnvironment(p_appUIHandle);

		return errCode;
	}


	int UxManager2D::pProcessUiEvents(UxEventInfo eventInfo)
	{
		if (p_uiManager)
		{
			p_uiManager->processEvents(eventInfo);
		}

		return 0;
	}


	int UxManager2D::pPrepareFrame()
	{
		pPrepareUi();
		pPrepareModelViz();

		return 0;
	}


	int UxManager2D::pPrepareUi()
	{
		if (p_uiManager)
		{
			p_uiManager->addComponentsToCanvas();
			p_uiManager->writeToDeviceFrameVertexData();
		}

		return 0;
	}


	int UxManager2D::pPrepareModelViz()
	{

		return 0;
	}

} // namespace ux