/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			IuxAppManager.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef I_UX_APP_MANAGER
#define I_UX_APP_MANAGER

/* #define NDEBUG */
#include <assert.h>

#include "../devicemanager/IgraphicsAppManager.h"
#include "../devicemanager/graphicsManager.h"

namespace ux
{
	
	enum UxEnvironment
	{
		UX_DEFAULT		= 0,
		UX_2D			= 1,
		UX_XR			= 2
	};

	class IUxManager;
	using UxManagerHandle = std::unique_ptr< IUxManager >;

	
	/**
	* @class	I_UxAppManager
	* @brief	Every appManager that intends to utilize the uxManager should
	*			provide a concrete implementation of this interface.
	*/
	class I_UxAppManager
	{
	public:
		virtual ~I_UxAppManager()
		{}
		virtual graphics_compute::AppGraphicsPipelineHandle &getAppGraphicsPipeline() = 0;
	};



	struct EntryData final
	{
	private:
		using this_ref = EntryData & ;

	public:
		std::string const& getLabel() const
		{
			return m_label;
		}

		std::string const& getImage() const
		{
			return m_image;
		}

		std::string const& getHelp() const
		{
			return m_help;
		}


		inline this_ref setLabel(char const* label)
		{
			m_label = label;
			return *this;
		}

		inline this_ref setImage(char const* img)
		{
			m_image = img;
			return *this;
		}

		inline this_ref setHelp(char const* help)
		{
			m_help = help;
			return *this;
		}

	private:
		std::string m_label{ "" };
		std::string m_image{ "" };
		std::string m_help{ "" };
	};

	
	struct ToolSetDescription final
	{
		std::vector<uint32_t> const& getTools() const
		{
			return m_identifiers;
		}

		EntryData const& getToolData(uint32_t tool) const
		{
			return m_descriptions.at(tool);
		}

		void addTool(uint32_t tool, EntryData const& data)
		{
			m_identifiers.push_back(tool);
			m_descriptions[tool] = data;
		}

	private:
		std::vector<uint32_t> m_identifiers;
		std::map<uint32_t, EntryData> m_descriptions;
	};


	/**
	* @class	IAppUserInterface
	* @brief	Application would use this object to initialize the user-interface
	*			and listen to user-interface callbacks.
	*/
	class IAppUserInterface
	{
	public:
		virtual std::vector< uint32_t > const& getModes() = 0;
		virtual EntryData const& getModeData(uint32_t mode) = 0;
		virtual void registerMode(uint32_t mode, EntryData const& data) = 0;

		virtual std::vector< uint32_t > const& getSecondaryModes() = 0;
		virtual EntryData const& getSecondaryModeData(uint32_t mode) = 0;
		virtual void registerSecondaryMode(uint32_t mode, EntryData const& data) = 0;

		virtual std::string const& getActiveToolset() = 0;
		virtual ToolSetDescription const& getToolSetDescription(std::string const& toolSetTag) = 0;
		virtual void setActiveToolset(std::string const& tag) = 0;
		virtual void registerToolSet(std::string const& tag, ToolSetDescription const& toolset) = 0;

		virtual void setupAppUserInterface() = 0;
		virtual void onModeChanged(uint32_t activeMode) = 0;
		virtual void onSecondaryModeChanged(uint32_t activeMode) = 0;
		virtual void onToolChanged(uint32_t activeTool) = 0;
	};

	using AppUserInterfaceHandle = std::shared_ptr<IAppUserInterface>;


	template
		<
		typename app_managerhandle
		>
	class T_AppUserInterface
		: public IAppUserInterface
	{
	public:
		T_AppUserInterface(app_managerhandle const& appmgr)
			: p_appmanager(appmgr)
		{}

		virtual ~T_AppUserInterface()
		{}

		inline app_managerhandle const& getAppManager()
		{
			return p_appmanager;
		}

		virtual std::vector< uint32_t > const& getModes() final
		{
			return p_modeIdentifiers;
		}

		virtual EntryData const& getModeData(uint32_t mode) final
		{
			return p_modesDescription[mode];
		}

		virtual void registerMode(uint32_t mode, EntryData const& data) final
		{
			p_modeIdentifiers.push_back(mode);
			p_modesDescription[mode] = data;
		}

		virtual std::vector< uint32_t > const& getSecondaryModes() final
		{
			return p_secondaryModeIdentifiers;
		}

		virtual EntryData const& getSecondaryModeData(uint32_t mode) final
		{
			return p_secondaryModesDescription[mode];
		}

		virtual void registerSecondaryMode(uint32_t mode, EntryData const& data) final
		{
			p_secondaryModeIdentifiers.push_back(mode);
			p_secondaryModesDescription[mode] = data;
		}

		virtual std::string const& getActiveToolset() final
		{
			return p_activeToolSet;
		}

		virtual ToolSetDescription const& getToolSetDescription(std::string const& toolSetTag) final
		{
			return p_toolsetsDescription[toolSetTag];
		}

		virtual void setActiveToolset(std::string const& tag) final
		{
			p_activeToolSet = tag;
		}

		virtual void registerToolSet(std::string const& tag, ToolSetDescription const& toolset) final
		{
			p_toolsetsDescription[tag] = toolset;
		}

		/*
		application will implement these to receive callbacks
		*/
		virtual void setupAppUserInterface() = 0;
		virtual void onModeChanged(uint32_t activeMode) = 0;
		virtual void onSecondaryModeChanged(uint32_t activeMode) = 0;
		virtual void onToolChanged(uint32_t activeTool) = 0;

	protected:
		app_managerhandle p_appmanager;

		std::vector< uint32_t > p_modeIdentifiers;
		std::map< uint32_t, EntryData > p_modesDescription;

		std::vector< uint32_t > p_secondaryModeIdentifiers;
		std::map< uint32_t, EntryData > p_secondaryModesDescription;

		std::string p_activeToolSet;
		std::map< std::string , ToolSetDescription > p_toolsetsDescription;
	};

}


#endif // !I_UX_APP_MANAGER