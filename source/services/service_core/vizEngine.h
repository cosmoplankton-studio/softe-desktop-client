/*
* ---------------------------------------------------------
* Copyright 2017-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			vizEngine.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef VIZ_ENGINE
#define VIZ_ENGINE

namespace viz
{
	class IVizEngine;
	using VizEngineHandle = std::shared_ptr< IVizEngine >;

	class IVizEngine
	{
		public:
			IVizEngine() {};
			virtual ~IVizEngine() {};
	};

} // namespace viz


#endif // VIZ_ENGINE
