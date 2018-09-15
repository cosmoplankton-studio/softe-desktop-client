/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			appLogger.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef APPLICATION_LOGGER
#define APPLICATION_LOGGER

#include <string>
#include <memory>
#include <sstream>
#include <fstream>
#include <ctime>
#include <iomanip>

namespace app
{
	
	class IApplication;
	
	/**
	* @class	LOGGER
	* @brief	Handles all the application logging requests. Logs messages, errors and traces 
	*			in module specific manner. Logs locally as well as remotely (or to logging services) if activated.
	*/
	class LOGGER
	{
	public:
		LOGGER(IApplication* mgr)
			: p_mrg(mgr)
			, p_remoteLoggerOn(false)
		{
			p_localLogFile = "softstudio_logger.log"; // for now in the working directory
			p_localLogFileObj.open(p_localLogFile, std::ofstream::out | std::ofstream::app);

			if (p_localLogFileObj.is_open())
			{
				p_localLogFileObj << "------------------------------------------------\n";				
				p_localLogFileObj << "- SOFT STUDIO APPLICATION STARTED              -\n";
				p_localLogFileObj << "------------------------------------------------\n";
				p_localLogFileObj << pGetCurrentDateAndTime();
				p_localLogFileObj << "------------------------------------------------\n";
			}
		}

		void logError(std::string const& appModule, std::string const& trace)
		{
			std::string str = "__ERROR__" + appModule + "__INFO__" + trace + "\n";
			pLogString(str);
		}

		void logMessage(std::string const& appModule, std::string const& trace)
		{
			std::string str = "__MESSAGE__" + appModule + "__INFO__" + trace + "\n";
			pLogString(str);
		}

		~LOGGER()
		{
			p_localLogFileObj << "------------------------------------------------\n";
			p_localLogFileObj << "- SOFT STUDIO APPLICATION CLOSED               -\n";
			p_localLogFileObj << "------------------------------------------------\n";
			
			p_localLogFileObj.close();
		}

	protected:
		void pLogString(std::string const& str)
		{
			pWriteToFile(str);

			if (p_remoteLoggerOn)
			{
				pWriteToRemote(str);
			}
		}

		void pWriteToFile(std::string const& str)
		{
			if (!p_localLogFileObj.is_open())
			{
				p_localLogFileObj.open(p_localLogFile, std::ofstream::app);
			}
			
			p_localLogFileObj << str;
		}

		void pWriteToRemote(std::string const& str)
		{
			// Cache locally and push in batches.
		}

		std::string pGetCurrentDateAndTime()
		{
			std::time_t tm = std::time(nullptr);
			std::stringstream ss;
			ss << std::put_time(std::gmtime(&tm), "%c %Z");
			return ("GMT:" + ss.str() + "\n");
		}

	protected:
		IApplication * p_mrg;
		bool p_remoteLoggerOn;
		std::string p_localLogFile;
		std::ofstream p_localLogFileObj;
	};

	using LOGHANDLER = std::shared_ptr<LOGGER>;
}


#endif // !APPLICATION_LOGGER