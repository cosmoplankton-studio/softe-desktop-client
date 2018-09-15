/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uxManager.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#include "uxManager2D.h"


namespace ux
{

	UxManagerHandle IUxManager::CreateUxManager(I_UxAppManager* appManager, UxEnvironment uxEnv)
	{
		if (UxEnvironment::UX_2D == uxEnv)
		{
			return UxManagerHandle(new UxManager2D(appManager));
		}
		else
		{
			throw std::runtime_error("unsupported ux environment type.");
		}

		return UxManagerHandle(nullptr);
	}

}