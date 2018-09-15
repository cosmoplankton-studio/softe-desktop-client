/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			pyInstance.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#include <stdexcept>

#include "pyInstance.h"


namespace python
{
    
    int Instance::isInitialized()
    {
        return Py_IsInitialized();
    }

    std::string Instance::getProgramName()
    {
        char* program = Py_EncodeLocale(Py_GetProgramName(), nullptr);
        std::string programStr(program);
        PyMem_Free(program);

        return programStr;
    }

    std::string Instance::getPath()
    {
        char* path = Py_EncodeLocale(Py_GetPath(), nullptr);
        std::string pathStr(path);
        PyMem_Free(path);

        return pathStr;
    }

    std::string Instance::getPYTHONHOME()
    {
        char* home = Py_EncodeLocale(Py_GetPythonHome(), nullptr);
        std::string homeStr(home);
        PyMem_Free(home);

        return homeStr;
    }

    std::string Instance::getVersion()
    {
        return Py_GetVersion();
    }

    std::string Instance::getPlatform()
    {
        return Py_GetPlatform();
    }

    std::string Instance::getCompiler()
    {
        return Py_GetCompiler();
    }

    std::string Instance::getBuildInfo()
    {
        return Py_GetBuildInfo();
    }

    int Instance::initEmbeded(char const* program)
    {
        int errCode = 0;

        if (program && strlen(program))
        {
            p_program = program;

            wchar_t *program_w = Py_DecodeLocale(program, nullptr);
            if (program_w == nullptr)
            {
                // #improvement - throw app specific errors(e.g. app::python_xxx_error) once appError is implemented for all the modules.
                throw std::runtime_error("Fatal Error: Py_DecodeLocale failed to decode program name");
            }
            Py_SetProgramName(program_w);
            PyMem_RawFree(program_w);
        }

        return errCode;
    }

    int Instance::initGlobalInterpreter()
    {
        int errCode = 0;

        if (!p_interpReady)
        {
            pPyInitialize();
            p_interpReady = Py_IsInitialized();
        }

        return errCode;
    }

    int Instance::finalizeGlobalInterpreter()
    {
        int errCode = 0;

        if (p_interpReady)
        {
            if (pPyFinalize() < 0)
            {
                // #improvement - throw app specific errors(e.g. app::python_xxx_error) once appError is implemented for all the modules.
                throw std::runtime_error("Fatal Error: Py_FinalizeEx failed to uninitialize interpreter");
            }
            p_interpReady = false;
        }

        return errCode;
    }

    int Instance::evalFile(char const* file)
    {
        int errCode = 0;

        if (file && strlen(file))
        {
            initGlobalInterpreter();
            FILE* fileObj = fopen(file, "r");

            if (fileObj)
            {
                errCode = PyRun_SimpleFile(fileObj, file);
                pLogError(errCode);
                fclose(fileObj);
            }
        }

        return errCode;
    }

    int Instance::evalFileObj(FILE* fileObj, char const* filetag /*= nullptr*/)
    {
        int errCode = 0;

        if (fileObj)
        {
            initGlobalInterpreter();
            errCode = PyRun_SimpleFile(fileObj, filetag);
            pLogError(errCode);
        }

        return errCode;
    }

    int Instance::evalSimpleString(char const* simpleString)
    {
        int errCode = 0;

        if (simpleString && strlen(simpleString))
        {
            initGlobalInterpreter();
            errCode = PyRun_SimpleString(simpleString);
            pLogError(errCode);
        }

        return errCode;
    }


    /*
    * protected methods
    */
    void Instance::pPyInitialize()
    {
        Py_Initialize();
    }

    int Instance::pPyFinalize()
    {
#ifdef BOOST_PYTHON_ACTIVE
        {
            return 0;
        }
#endif

        return Py_FinalizeEx();
    }

    void Instance::pLogError(int errCode)
    {
        if (errCode && PyErr_Occurred())
        {
            PyObject *errorType, *errorValue, *errorTraceback;
            PyErr_Fetch(&errorType, &errorValue, &errorTraceback);
            char const* pStrErrorMessage = PyBytes_AsString(errorValue);
            PyErr_Clear();
        }
    }


}