/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			modEngine.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef MOD_ENGINE
#define MOD_ENGINE

namespace mod
{
	class IModEngine;
	using ModelerHandle = std::shared_ptr< IModEngine >;

	class IModEngine
	{
		public:
			IModEngine() {};
			virtual ~IModEngine() {};
	};

} // namespace mod


#endif // MOD_ENGINE
