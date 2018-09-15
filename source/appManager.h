/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef APPLICATION_MANAGER
#define APPLICATION_MANAGER

#ifdef _WIN32

#include "../windowsapp/stdafx.h"
#define MAX_LOADSTRING 100

#endif

#include "appLogger.h"
#include "appState.h"
#include "appPublisher.h"
#include "appUserInterface.h"

#include "devicemanager/graphicsManager.h"
#include "devicemanager/computeManager.h"

#include "uxmanager/IuxAppManager.h"
#include "uxmanager/uxManager.h"

#include "services/service_core/coreEngine.h"
#include "services/service_core/vizEngine.h"
#include "services/service_core/modEngine.h"

#include "scripting/pyInstance.h"



namespace app
{

    /**
    * @class   APPLICATION
    * @brief   Creates the proper OS specific application singleton.
    */
    template < typename OSAPP >
    class APPLICATION
    {
    public:
        static OSAPP& get()
        {
            if (s_manager)
            {
                return *s_manager;
            }

            s_manager = new OSAPP();
            return *s_manager;
        }

        static void destroy()
        {
            delete s_manager;
            s_manager = nullptr;
        }

    private:
        static OSAPP *s_manager;
    };



    /**
    * @class   IApplication
    * @brief   Abstract application manager. Platform (win/unix/android) specific managers
               should provide the concrete implementation.
    */
    class IApplication 
        : public graphics_compute::I_GraphicsAppManager // we could separate these into different objects in future if needed.
        , public graphics_compute::I_ComputeAppManager
        , public ux::I_UxAppManager
    {
    public:

        IApplication()
            : p_hostPtr(nullptr)
        {}

        virtual ~IApplication()
        {
            delete p_hostPtr;
        }

        inline device::Host*								getHost() { return p_hostPtr; }
        inline core::CoreEngineHandle						&getCoreEngine() { return p_coreEngine; }
        inline viz::VizEngineHandle							&getVizEngine() { return p_vizEngine; }
        inline mod::ModelerHandle							&getModeler() { return p_modEngine; }
        inline ux::UxManagerHandle							&getUxManager() { return p_uxManager; }
        inline ux::AppUserInterfaceHandle					&getAppUserInterfaceHandle() { return p_uiHandle; }
        inline graphics_compute::ComputeManagerHandle		&getComputeManager() { return p_computeManager; }
        inline graphics_compute::AppComputePipelineHandle	&getAppComputePipelineHandle() { return p_appComputePipeline; }
        inline graphics_compute::GraphicsManagerHandle		&getGraphicsManagerHandle() { return p_graphicsManager; }
        inline graphics_compute::AppGraphicsPipelineHandle	&getAppGraphicsPipelineHandle() { return p_appGraphicsPipeline; }
        inline python::InstanceHandle						&getPython() { return p_pyInstance; }

        virtual int initializeApplication(void* appConnection) = 0;

        virtual int startEventLoop() = 0;
        virtual int frameDraw() = 0;
        virtual int handleUxEvents() = 0;

        virtual int setAppWidth(unsigned int width) = 0;
        virtual int setAppHeight(unsigned int height) = 0;
        virtual int appResize() = 0;

        AppStateHandle getAppState() const { return p_appState; }
        PublisherHandle getPublisher() const { return p_sigPublisher; }
        LOGHANDLER getLOGGER() const { return p_logHandler; }
        
        /*
        ************************************************************
        Interface for ::graphics_compute::I_GraphicsAppManager.
        ************************************************************
        */
        virtual void* getAppConnection() = 0;
        virtual void* getAppWindow() = 0;
        virtual int	getFrameWidth() = 0;
        virtual int	getFrameHeight() = 0;
        virtual int	setFrameWidth(unsigned int width) = 0;
        virtual int	setFrameHeight(unsigned int height) = 0;

        virtual void GRAPHICS_LOGMESSAGE(std::string const&) = 0;
        virtual void GRAPHICS_LOGERROR(std::string const&) = 0;

        /*
        ************************************************************
        Interface for ::graphics_compute::I_ComputeAppManager.
        ************************************************************
        */
        virtual void COMPUTE_LOGMESSAGE(std::string const&) = 0;
        virtual void COMPUTE_LOGERROR(std::string const&) = 0;

        /*
        ************************************************************
        Interface for ::ux::I_UxAppManager.
        ************************************************************
        */
        virtual graphics_compute::AppGraphicsPipelineHandle &getAppGraphicsPipeline() = 0;


    protected:
        virtual int pInitializeApp() = 0;
        virtual int pInitializeCore() = 0;
        virtual int pInitializeVizEngine() = 0;
        virtual int pInitializeUxManager() = 0;
        virtual int pInitializeComputeManager() = 0;
        virtual int pInitializeGraphicsManager() = 0;
        virtual int pInitializeModeler() = 0;
        virtual int pInitAppGraphicsPipeline() = 0;
        virtual int pInitAppComputePipeline() = 0;
        virtual int pInitAppUserInterface() = 0;
        virtual int pInitializePython() = 0;

    protected:
        core::CoreEngineHandle							p_coreEngine;
        viz::VizEngineHandle							p_vizEngine;
        mod::ModelerHandle								p_modEngine;

        ux::UxManagerHandle								p_uxManager;
        ux::AppUserInterfaceHandle						p_uiHandle;

        graphics_compute::ComputeManagerHandle			p_computeManager;
        graphics_compute::AppComputePipelineHandle		p_appComputePipeline;
        graphics_compute::GraphicsManagerHandle			p_graphicsManager;
        graphics_compute::AppGraphicsPipelineHandle		p_appGraphicsPipeline;
        device::HostPtr									p_hostPtr;

        python::InstanceHandle							p_pyInstance;

        AppStateHandle									p_appState;
        PublisherHandle									p_sigPublisher;
        LOGHANDLER										p_logHandler;

    };


    /**
    * @class   WinApp
    * @brief   Singleton Application Manager for Windows Platform. Responsible for intialization, destructions, and
               application state management.
    */
    class WinApp 
        : public IApplication
    {

    public:
        virtual ~WinApp();

        template < typename OSAPP >
        friend class APPLICATION;

        /**
        * @brief	Initialize the application.
        *
        * @param	
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int initializeApplication(void* appConnection);


        /**
        * @brief	Start application/game loop.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int startEventLoop();
        
        /**
        * @brief	Render application frame.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int frameDraw();

        /**
        * @brief	Handle UX Events.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int handleUxEvents();

        virtual int setAppWidth(unsigned int width);
        virtual int setAppHeight(unsigned int height);
        virtual int appResize();

        HINSTANCE getWinAppConnection() const { return p_appConnection; }
        HWND getWinAppWindow() const { return p_appWindow; }

        int getTitleBarHeight() const { return p_appTitleBarHeight; }

        void setUxEventInfo(::ux::UxEventInfo& info) { p_uxEventInfo = info; }
        void setTitleBarHeight(int height) { p_appTitleBarHeight = height; }

        
        /*
        ************************************************************
        Interface for ::graphics_compute::I_GraphicsAppManager.
        ************************************************************
        */
        virtual void* getAppConnection()
        {
            return static_cast< void* >(getWinAppConnection());
        }

        virtual void* getAppWindow()
        {
            return static_cast< void* >(getWinAppWindow());
        }

        virtual int	getFrameWidth();

        virtual int	getFrameHeight();

        virtual int	setFrameWidth(unsigned int width)
        {
            return setAppWidth(width);
        }

        virtual int	setFrameHeight(unsigned int height)
        {
            return setAppHeight(height);
        }

        virtual void GRAPHICS_LOGMESSAGE(std::string const& trace) override
        {
            getLOGGER()->logMessage("__GRAPHICS__", trace);
        }

        virtual void GRAPHICS_LOGERROR(std::string const& trace) override
        {
            getLOGGER()->logError("__GRAPHICS__", trace);
        }

        /*
        ************************************************************
        Interface for ::graphics_compute::I_ComputeAppManager.
        ************************************************************
        */
        virtual void COMPUTE_LOGMESSAGE(std::string const& trace) override
        {
            getLOGGER()->logMessage("__COMPUTE__", trace);
        }

        virtual void COMPUTE_LOGERROR(std::string const& trace) override
        {
            getLOGGER()->logError("__COMPUTE__", trace);
        }

        /*
        ************************************************************
        Interface for ::ux::I_AppManager.
        ************************************************************
        */
        virtual graphics_compute::AppGraphicsPipelineHandle &getAppGraphicsPipeline() { return getAppGraphicsPipelineHandle(); }


    protected:

        /**
        * @brief	Initialize the application states.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeApp();

        /**
        * @brief	Initialize the core engine.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeCore();

        /**
        * @brief	Initialize the Visualization engine.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeVizEngine();

        /**
        * @brief	Initialize the UX Manager.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeUxManager();

        /**
        * @brief	Initialize the compute manager.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeComputeManager();

        /**
        * @brief	Initialize the graphics manager.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeGraphicsManager();

        /**
        * @brief	Initialize the Modeler. This provides the set of design tools.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializeModeler();

        /**
        * @brief	Initialize the application graphics pipeline with required stages.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitAppGraphicsPipeline();

        /**
        * @brief	Initialize the application compute pipeline with required execution nodes.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitAppComputePipeline();

        /**
        * @brief	Initialize the application user interface.
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitAppUserInterface();

        /**
        * @brief	Initialize the python instance (the instance could have multiple ineterpreters).
        *
        * @param
        *
        * @return	Error code, any non-zero value specifies an error.
        */
        virtual int pInitializePython();

    protected:
        HINSTANCE							p_appConnection;
        HWND								p_appWindow;

        ux::UxEventInfo						p_uxEventInfo;
        int									p_appTitleBarHeight{ 0 };

    private:
        WinApp();
        WinApp(const WinApp&);
        WinApp& operator=(const WinApp&) {}

    };


} // namespace app

#endif // APPLICATION_MANAGER
