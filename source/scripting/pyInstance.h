/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			pyInstance.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef PY_INSTANCE
#define PY_INSTANCE


#include <memory>
#include <Python.h>


// #define BOOST_PYTHON_ACTIVE


/*
************************************************************************************
* This Python Instance implementation provides the functionality to embed and extend 
* Python into a c++ application. This single instance would facilitate multiple 
* interpreters and thread/process access for the application.
* ----------------------------------------------------------------------------------
* This implementation uses the Python:C-API/SDK to provide "VERY HIGH LEVEL EMBEDDING"
* and functionalities needed for initializing and finalizing the interpreter(s).
* ----------------------------------------------------------------------------------
* For "LOW LEVEL EMBEDDING" and cross data transfer between the application and the 
* interpreter this implemenattion uses BOOST-PYTHON.
************************************************************************************
* #improvement : The "VERY HIGH LEVEL EMBEDDING" is sufficient for this application
* as the MODELER would mostly use Python to implement modeling-Tools (chainss/graphs) of Python 
* commands/files. Yet would keep on enhancing the "LOW LEVEL EMBEDDING".
************************************************************************************
*/



namespace python
{

	class Instance final
	{
	public:
		Instance()
		{}

		~Instance()
		{
			finalizeGlobalInterpreter();
		}

		int isInitialized();
		std::string getProgramName();
		std::string getPath();
		std::string getPYTHONHOME();
		std::string getVersion();
		std::string getPlatform();
		std::string getCompiler();
		std::string getBuildInfo();

		int initEmbeded(char const* program);
		int initGlobalInterpreter();
		int finalizeGlobalInterpreter();

		int evalFile(char const* file);
		int evalFileObj(FILE* fileObj, char const* filetag = nullptr);
		int evalSimpleString(char const* simpleString);

		// void setPath(char const* path);
		// void setPYTHONHOME(char const* path);

	protected:

		void pLogError(int errCode);

		void pPyInitialize();
		int  pPyFinalize();

	protected:
		std::string		p_program{ "" };
		bool			p_interpReady{ false };
	};


	using InstanceHandle = std::shared_ptr<Instance>;

}


#endif // !PY_INSTANCE
