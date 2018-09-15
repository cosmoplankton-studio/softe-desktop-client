/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appPublisher.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef APPLICATION_PUBLISHER
#define APPLICATION_PUBLISHER


#include "appState.h"


/* disable warning */
// #define BOOST_CONFIG_SUPPRESS_OUTDATED_MESSAGE
#include <boost/signals2.hpp>




namespace app
{

	using app_mode_signal_type			= boost::signals2::signal<void (AppMode)>;
	using app_scale_signal_type			= boost::signals2::signal<void (AppMultiScaleMode)>;
	using app_tool_signal_type			= boost::signals2::signal<void (ModelerTool)>;


	class Publisher final
	{
	public:
		Publisher()
		{}

		/* signals */
		inline app_mode_signal_type		const& onAppModeChanged()
		{
			return m_appModeChanged;
		}

		inline app_scale_signal_type	const& onAppScaleChanged()
		{
			return m_appScaleModeChanged;
		}

		inline app_tool_signal_type		const& onAppToolChanged()
		{
			return m_appToolChanged;
		}

		~Publisher()
		{}

	private:
		app_mode_signal_type	m_appModeChanged;
		app_scale_signal_type	m_appScaleModeChanged;
		app_tool_signal_type	m_appToolChanged;
	};

	using PublisherHandle = std::shared_ptr< Publisher >;
}



#endif // !APPLICATION_PUBLISHER