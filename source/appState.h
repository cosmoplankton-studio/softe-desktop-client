/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appState.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef APP_STATE
#define APP_STATE

#include <stdint.h>
#include <memory>

namespace app
{

    /*
    ***************************************
    * The appMode and the appMultiScaleMode decide
    * which tools are active and how interactions
    * affect the model and data.
    **************************************
    * #improvement - Keep on adding more modes as required.
    ***************************************
    */
    enum class AppMode : uint32_t
    {
        eGeneral = 0x0,
        eData = 0x1,
        eModel = 0x2,
        eAnalyze = 0x3
    };

    enum class AppMultiScaleMode : uint32_t
    {
        eAll = 0x0,
        eTissue = 0x1,
        eMicro = 0x2,
        eCellular = 0x3
    };

    struct AppState
    {
        AppMode appMode{ AppMode::eModel };
        AppMultiScaleMode appScale{ AppMultiScaleMode::eTissue };
    };
    using AppState = struct AppState;
    using AppStateHandle = std::shared_ptr<AppState>;

    
    
    /* for now keeping it here. Move to modeler once Modeller implementation is done */
    enum class ModelerTool : uint32_t
    {
        eNone = 0x0,
        eSuperResolution = 0x1,
        eSegmentation = 0x2,
        eLocalization = 0x3,

        eDemo = 0x11111
    };

}


#endif

