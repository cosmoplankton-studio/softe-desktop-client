/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			coreEngine.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef CORE_ENGINE
#define CORE_ENGINE

namespace core
{
	class ICoreEngine;
	using CoreEngineHandle = std::shared_ptr< ICoreEngine >;


	class ICoreEngine
	{
	public:
		ICoreEngine() {};
		virtual ~ICoreEngine() {};
	};

} // namespace core



#endif // CORE_ENGINE
