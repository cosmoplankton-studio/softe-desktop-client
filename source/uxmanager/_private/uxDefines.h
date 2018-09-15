/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uxDefines.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef UX_DEFINES
#define UX_DEFINES

#include "../uxManager.h"

namespace ux
{

}

namespace ui
{
	using DataHandle = std::shared_ptr< void >;
	
	class UiManager;
	using UiManagerHandle = std::unique_ptr<UiManager>;

	class NkEngine;
	using NkEngineHandle = std::unique_ptr<NkEngine>;
}


#endif // !UX_DEFINES
