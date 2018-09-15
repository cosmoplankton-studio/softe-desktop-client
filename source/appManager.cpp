/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "../source/devicemanager/Idevice.h"
#include "../source/devicemanager/IgraphicsAppManager.h"
#include "../source/devicemanager/IcomputeAppManager.h"

#include "appManager.h"
#include "appGraphicsPipeline.h"
#include "appComputePipeline.h"

namespace app
{

    template <>
    WinApp* APPLICATION<WinApp>::s_manager = nullptr;


    WinApp::WinApp()
        : IApplication()
    {}

    WinApp::~WinApp()
    {}

    int WinApp::initializeApplication(void* appConnection)
    {
        p_appConnection = static_cast< HINSTANCE >(appConnection);

        WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
        LoadStringW(p_appConnection, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
        WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name
        LoadStringW(p_appConnection, IDC_WINDOWSAPP, szWindowClass, MAX_LOADSTRING);

        uint32_t appWidth = 1300;
        uint32_t appHeight = 700;
        uint32_t appX = 50;
        uint32_t appY = 10;

        p_appWindow = CreateWindowW(
            szWindowClass,
            szTitle,
            WS_OVERLAPPEDWINDOW,
            appX,
            appY,
            appWidth,
            appHeight,
            nullptr,
            nullptr,
            p_appConnection,
            nullptr
        );

        if (!p_appWindow)
        {
            return -1;
        }

        int nCmdShow = SW_MAXIMIZE; /* show window maximized*/
        ShowWindow(p_appWindow, nCmdShow);
        UpdateWindow(p_appWindow);

        /* initialize application modules */
        pInitializeApp();
        pInitializeCore();
        pInitializeModeler();
        pInitializeComputeManager();
        pInitializeGraphicsManager();
        pInitializeVizEngine();
        pInitializeUxManager();

        /* setup pipelines and assets */
        pInitAppGraphicsPipeline();

        /* setup pipelines and assets */
        pInitAppComputePipeline();

        /* setup user interface */
        pInitAppUserInterface();

        /* setup python */
        pInitializePython();

        return 0;
    }

    int WinApp::startEventLoop()
    {
        // HACCEL hAccelTable = LoadAccelerators(p_appConnection, MAKEINTRESOURCE(IDC_SOFTSTUDIO));
        HACCEL hAccelTable = LoadAccelerators(p_appConnection, MAKEINTRESOURCE(IDC_WINDOWSAPP));
        MSG msg;

        while (GetMessage(&msg, nullptr, 0, 0))
        {
            if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
            {
                TranslateMessage(&msg);
                DispatchMessage(&msg);
            }
            
            handleUxEvents();
            frameDraw();
        }

        return (int)msg.wParam;
    }

    int WinApp::pInitializeApp()
    {
        p_logHandler = std::make_shared<LOGGER>(this);
        p_appState = std::make_shared<AppState>();
        p_sigPublisher = std::make_shared<Publisher>();

        return 0;
    }

    int WinApp::pInitializeCore()
    {
        return 0;
    }

    int WinApp::pInitializeVizEngine()
    {
        return 0;
    }

    int WinApp::pInitializeUxManager()
    {
        p_uxManager = ux::IUxManager::CreateUxManager(this, ux::UxEnvironment::UX_2D);

        return 0;
    }

    int WinApp::pInitAppUserInterface()
    {
        p_uiHandle = std::make_shared<AppUserInterface>(this);
        p_uiHandle->setupAppUserInterface();

        return 0;
    }

    int WinApp::pInitializeComputeManager()
    {
        if (!p_hostPtr)
        {
            p_hostPtr = new device::Host(1, device::DeviceType::eCPU);
        }
        
        p_computeManager = graphics_compute::IComputeManager::createComputeManager(this, device::DeviceApiType::eOPENCL, p_hostPtr);

        if (p_computeManager)
        {
            return p_computeManager->initContextandDevices();
        }
        
        return 0;
    }

    int WinApp::pInitAppComputePipeline()
    {
        p_appComputePipeline = std::make_shared<AppComputePipeline>(this, p_computeManager.get());
        return p_appComputePipeline->setupAppComputePipeline();
    }

    int WinApp::pInitializeModeler()
    {
        return 0;
    }

    int WinApp::pInitializeGraphicsManager()
    {
        if (!p_hostPtr)
        {
            p_hostPtr = new device::Host(1, device::DeviceType::eCPU);
        }

        p_graphicsManager = graphics_compute::IGraphicsManager::createGraphicsManager(this, device::DeviceApiType::eVULKAN, p_hostPtr);
        
        if (p_graphicsManager)
        {
            return p_graphicsManager->initInstanceAndDevices();
        }

        return 0;
    }

    int WinApp::pInitAppGraphicsPipeline()
    {
        p_appGraphicsPipeline = std::make_shared<AppGraphicsPipeline>(this, p_graphicsManager.get());
        return p_appGraphicsPipeline->setupGraphicsPipelineStages();
    }

    int WinApp::pInitializePython()
    {
        p_pyInstance = std::make_shared<python::Instance>();
        char const* python = getenv("SOFT_STUDIO_PYTHON_SDK");
        std::string program("");
        if (python)
        {
            program = program + python + "/python" ;
        }
        else program = "python";

        p_pyInstance->initEmbeded(program.c_str());
        // p_pyInstance->evalSimpleString("import ctypes; ctypes.windll.user32.MessageBoxW(None, 'PYTHON INITIALIZED', 'Message', 0);");

        return 0;
    }

    int WinApp::getFrameWidth()
    {
        if (p_uxManager)
        {
            return p_uxManager->getAppWidth();
        }

        return 1;
    }

    int WinApp::getFrameHeight()
    {
        if (p_uxManager)
        {
            return p_uxManager->getAppHeight();
        }

        return 1;
    }

    int WinApp::setAppWidth(unsigned int width)
    {
        if (p_uxManager)
        {
            p_uxManager->setAppWidth(width);
        }

        return 0;
    }

    int WinApp::setAppHeight(unsigned int height)
    {
        if (p_uxManager)
        {
            p_uxManager->setAppHeight(height);
        }

        return 0;
    }

    int WinApp::appResize()
    {
        if (p_uxManager)
        {
            p_uxManager->appResize();
        }

        return 0;
    }

    int WinApp::frameDraw()
    {
        if (p_uxManager)
        {
            p_uxManager->frameDraw();
        }
    
        return 0;
    }

    int WinApp::handleUxEvents()
    {
        if (p_uxManager)
        {
            p_uxManager->handleUxEvents(p_uxEventInfo);
        }

        return 0;
    }



    /*
    ******************************************************************
    * class AppGraphicsPipeline - Application Graphics Pipeline (#improvement - refactor and move to a separate builder/ui)
    ******************************************************************
    */
    int AppGraphicsPipeline::setupGraphicsPipelineStages()
    {
        using namespace graphics_compute;

        ApplicationGraphicsPipelineStage &uiStage = p_pipelineStages[StageType::eUI];
        StageDescription &uiStageDescription = uiStage.stageDescription();

        // ui graphics stage
        getAppManager()->getUxManager()->getGraphicsStageDescription(uiStageDescription);

        // #todo - rest of the stages and viewport setup

        // init pipeline with all the stages
        getGraphicsManager()->initApplicationGraphicsPipeline(getAppManager()->getAppGraphicsPipelineHandle());

        return 0;
    }


    /*
    ******************************************************************
    * class AppGraphicsPipeline - Application Compute Pipeline (#improvement - refactor and move to a separate builder/ui)
    ******************************************************************
    */
    int AppComputePipeline::setupAppComputePipeline()
    {
        // core engine is the major user of the compute pipeline and will initialize it.

        return 0;
    }


    /*
    ******************************************************************
    * class AppUserInterface - Application User Interface (#improvement - refactor and move to a separate builder/stylesheet)
    ******************************************************************
    */

    void AppUserInterface::setupAppUserInterface()
    {
        ux::EntryData dataMode, modelMode, analyzeMode, tissueScale, microScale, cellularScale;

        /* application mode */
        dataMode.setLabel("Data").setHelp("Load Datasets");
        modelMode.setLabel("Model").setHelp("Modeling Mode");
        analyzeMode.setLabel("Analyse").setHelp("Visualize and Analyze Results, Predictions, and Prognosis");
        registerMode(static_cast<uint32_t>(AppMode::eData), dataMode);
        registerMode(static_cast<uint32_t>(AppMode::eModel), modelMode);
        registerMode(static_cast<uint32_t>(AppMode::eAnalyze), analyzeMode);

        /* multiscale mode */
        tissueScale.setLabel("Tissue").setHelp("Tissue/Macro Scale");
        microScale.setLabel("Micro").setHelp("Microstructure Scale");
        cellularScale.setLabel("Cellular").setHelp("Cellular Scale");
        registerSecondaryMode(static_cast<uint32_t>(AppMultiScaleMode::eTissue), tissueScale);
        registerSecondaryMode(static_cast<uint32_t>(AppMultiScaleMode::eMicro), microScale);
        registerSecondaryMode(static_cast<uint32_t>(AppMultiScaleMode::eCellular), cellularScale);

        /* primary toolset */
        ux::ToolSetDescription primaryTools;
        ux::EntryData superRes, demo1, demo2, demo3, demo4, demo5, demo6, demo7;
        superRes.setLabel("SR").setHelp("Super Resolution");
        demo1.setLabel("T1").setHelp("Demo 1");
        demo2.setLabel("T2").setHelp("Demo 2");
        demo3.setLabel("T3").setHelp("Demo 3");
        demo4.setLabel("T4").setHelp("Demo 4");
        demo5.setLabel("T5").setHelp("Demo 5");
        demo6.setLabel("T6").setHelp("Demo 6");
        demo7.setLabel("T7").setHelp("Demo 7");
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eSuperResolution), superRes);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eSegmentation), demo1);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eLocalization), demo2);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eDemo), demo3);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eDemo), demo4);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eDemo), demo5);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eDemo), demo6);
        primaryTools.addTool(static_cast<uint32_t>(ModelerTool::eLocalization), demo7);
        registerToolSet("T", primaryTools);
        setActiveToolset("T");

        getAppManager()->getUxManager()->initUxEnvironment(getAppManager()->getAppUserInterfaceHandle());
    }

    void AppUserInterface::onModeChanged(uint32_t activeMode)
    {
        getAppManager()->getAppState()->appMode = static_cast<AppMode>(activeMode);
        getAppManager()->getPublisher()->onAppModeChanged()(static_cast<AppMode>(activeMode));
    }

    void AppUserInterface::onSecondaryModeChanged(uint32_t activeMode)
    {
        getAppManager()->getAppState()->appScale = static_cast<AppMultiScaleMode>(activeMode);
        getAppManager()->getPublisher()->onAppScaleChanged()(static_cast<AppMultiScaleMode>(activeMode));
    }

    void AppUserInterface::onToolChanged(uint32_t activeTool)
    {
        // #todo pass info to Modeler
        getAppManager()->getPublisher()->onAppToolChanged()(static_cast<ModelerTool>(activeTool));
    }
    

} // namespace app