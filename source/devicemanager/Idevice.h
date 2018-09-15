/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			Idevice.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef I_DEVICE
#define I_DEVICE

#include <set>
#include <map>
#include <vector>
#include <memory>

namespace device
{

	enum class DeviceType : uint32_t
	{
		eUndefined = 0x0,
		eCPU = 0x1,
		eGPU = 0x2
	};


	enum class DeviceApiType : uint32_t
	{
		eUndefined = 0x0,
		eOPENCL = 0x1,
		eCUDA = 0x2,
		eVULKAN = 0x3
	};


	/**
	* @enum		ResourceType
	* @brief	Description of a particular resource description fed to the pipeline.
	*/
	enum class ResourceType : uint32_t
	{
		eGeneral = 0x0,
		eBuffer = 0x1,
		eImage = 0x2
	};


	/**
	* @enum		DataDescription
	* @brief	Description of a particular data description fed to the pipeline.
	*/
	enum DataDescription : uint32_t
	{
		eGeneral = 0x0,
		eVertex = 0x1,
		eIndex = 0x2,
		eUniform = 0x3,
		eTexture = 0x4,
		eRenderTarget = 0x5,
		eDraw = 0x6,
		eDispatch = 0x7
	};


	/**
	* @enum		DataFormat
	* @brief	Data format of the data units. Used for memory management, descriptor definition, io, etc.
	*/
	enum class DataFormat : uint32_t
	{
		eUndefined = 0x0,

		eUint16 = 0x1,
		eUint32 = 0x2,

		eInt16 = 0x100,
		eInt32 = 0x101,

		eFloat16 = 0x200,
		eDouble32 = 0x201,

		eA8 = 0x300,
		eRGBA32 = 0x301,
		eR32G32Float = 0x302,
		eR32G32B32A32Float = 0x303,

		eMAT4Float = 0x400
	};


	/**
	* @enum		DataMemory
	* @brief	Data Memory Property.
	*/
	enum class DataAccessQualifier : uint32_t
	{
		eUndefined = 0x0,
		eHostLocal = 0x1,
		eDeviceLocal = 0x2,
		eHostToDevice = 0x3,
		eDeviceToHost = 0x4,
		eSharedVirtual = 0x5
	};


	/**
	* @enum		DataAttributeType
	* @brief	Type of data attribute.
	*/
	enum class DataAttributeType : uint32_t
	{
		eUndefined = 0x0,

		eVertexPosition = 0x1,
		eVertexUV = 0x2,
		eVertexColor = 0x3,
		eVertexNormal = 0x4,
		eVertexTangent = 0x5,
		eVertexBiTangent = 0x6,
		eVertexIndex = 0x7,

		eTransformMatrix = 0x100,

		eLightsColor = 0x200,

		eDrawIndexCount = 0x300,
		eDrawIndexFirst = 0x301,
		eDrawIndexVertexOffset = 0x302,
		eDrawVertexCount = 0x303,
		eDrawVertexOffset = 0x304
	};


	/**
	* @class	DataAttribute
	* @brief	Complete definition of a data unit (type and format).
	*/
	class DataAttribute
	{
		using this_ref = DataAttribute & ;

	public:
		inline this_ref setType(DataAttributeType type) { m_attrType = type; return *this; }
		inline this_ref setFormat(DataFormat format) { m_attrDataFormat = format; return *this; }

		inline auto getType() const { return m_attrType; }
		inline auto getFormat() const { return m_attrDataFormat; }

	protected:

		DataAttributeType	m_attrType;
		DataFormat			m_attrDataFormat;

	};
	using DataAttributeList = std::vector< DataAttribute >;



	/**
	* @class	IDevice
	* @brief	Abstract device interface. Different device types (CPUs, GPUs, TPUs)
	*			should provide concrete implementation, settings, and device state.
	*/
	class IDevice
	{
	public:
		/* constructor */
		IDevice(size_t id, DeviceType type)
			: p_Id(id)
			, p_deviceType(type)
		{}

		/* destructor */
		virtual ~IDevice()
		{}

		/* get methods */
		virtual size_t			GetId() const { return p_Id; }

		virtual DeviceType		GetType() const { return p_deviceType; }

	protected:
		size_t			p_Id;
		DeviceType		p_deviceType;
	};

	typedef std::vector< IDevice* > DevicePool;



	/**
	* @class	Host
	* @brief	Implementation for the host device.
	*/
	class Host : public IDevice
	{
	public:
		/* constructor */
		Host(size_t id, DeviceType type)
			: IDevice(id, type)
		{}

		/* destructor */
		virtual ~Host()
		{}
	};


	using HostPtr = Host * ;
	using PersistPtr = int32_t * ;


	//-------------------------------------------------------------------------
	// Application using the "graphics_compute" backend should handle the
	// below exceptions. Details regarding whether a exception is recovarable 
	// or not, and if yes how? is available for each specific exception.
	//-------------------------------------------------------------------------
	// Backend will first try to recover on its own. If exception is non recovarable
	// it will re-throw() it to the application to shutdown resources, logs, etc., and then exit gracefully.
	//-------------------------------------------------------------------------
	// #improvemnt - currently almost all the exceptions are non recovarable. Provide recovery routines.
	//-------------------------------------------------------------------------
	
	/**
	* @class	init_error
	* @brief	device/instance/context initialization fails
	*/
	class init_error
		: public std::exception
	{
	public:
		using _Mybase = std::exception;

		explicit init_error(std::string const& _Message)
			: _Mybase(_Message.c_str())
		{
		}

		explicit init_error(char const* _Message)
			: _Mybase(_Message)
		{
		}
	};

	/**
	* @class	outofresource_error
	* @brief	device out of resource
	*/
	class outofresource_error
		: public std::exception
	{
	public:
		using _Mybase = std::exception;

		explicit outofresource_error(std::string const& _Message)
			: _Mybase(_Message.c_str())
		{
		}

		explicit outofresource_error(char const* _Message)
			: _Mybase(_Message)
		{
		}
	};

	/**
	* @class	runtime_error
	* @brief	for now all uncategorized runtime error
	*/
	class runtime_error
		: public std::exception
	{
	public:
		using _Mybase = std::exception;

		explicit runtime_error(std::string const& _Message)
			: _Mybase(_Message.c_str())
		{
		}

		explicit runtime_error(char const* _Message)
			: _Mybase(_Message)
		{
		}
	};

} // end namespace device


#endif	// !I_DEVICE