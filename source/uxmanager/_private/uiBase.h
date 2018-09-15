/*
* ---------------------------------------------------------
* Copyright 2018-present (c) Automatos Studios. All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uiBase.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/

#ifndef UI_COMPONENTS
#define UI_COMPONENTS

#include <functional>
#include <string>
#include <vector>
#include <map>

#include "uxDefines.h"


namespace ui
{
	
	enum class Orientation : uint32_t
	{
		eHorizontal = 0x0,
		eVertical = 0x1
	};

	
	struct PixelDimensions
	{
		uint32_t x;
		uint32_t y;
		uint32_t width;
		uint32_t height;
	};


	class IBase
	{
	public:
		explicit IBase(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: p_uiTag(tag)
		{
			p_dimensions.x = x;
			p_dimensions.y = y;
			p_dimensions.width = w;
			p_dimensions.height = h;
		}

		explicit IBase(std::string const& tag, PixelDimensions const& dim)
			: p_uiTag(tag)
			, p_dimensions(dim)
		{}

		virtual ~IBase()
		{}


		inline PixelDimensions const& getDimensions()
		{
			return p_dimensions;
		}

		inline void setDimensions(uint32_t x, uint32_t y, uint32_t w = UINT32_MAX, uint32_t h = UINT32_MAX)
		{
			if (x != UINT32_MAX) p_dimensions.x = x;
			if (y != UINT32_MAX) p_dimensions.y = y;
			if (w != UINT32_MAX) p_dimensions.width = w;
			if (h != UINT32_MAX) p_dimensions.height = h;
		}
	
	protected:
		std::string p_uiTag;
		PixelDimensions p_dimensions;
	};

	
	class ButtonBoxBase
		: public IBase
	{
	public:
		explicit ButtonBoxBase(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: IBase(tag, x, y, w, h)
			, p_boxlabel(tag)
		{}

		virtual ~ButtonBoxBase()
		{}

		inline void setLabel(char const* label)
		{
			p_boxlabel = label;
		}

		inline std::string const& getLabel()
		{
			return p_boxlabel;
		}

		virtual uint32_t getButtonCount() = 0;
		virtual ux::EntryData const& getButtonData(uint32_t buttonIdx) = 0;
		virtual bool highlightOn(uint32_t buttonIdx) = 0;
		virtual void onClick(uint32_t buttonIdx) = 0;

	protected:
		std::string p_boxlabel{ "" };
	};

	using ButtonBoxHandle = std::shared_ptr< ButtonBoxBase >;



	template
		<
		typename button_identifier,
		typename callback_1arg
		>
		class ButtonBox
		: public ButtonBoxBase
	{
	public:
		explicit ButtonBox(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: ButtonBoxBase(tag, x, y, w, h)
		{}

		virtual ~ButtonBox()
		{}


		virtual uint32_t getButtonCount()
		{
			return (uint32_t)p_buttons.size(); // #todo #safecast
		}

		virtual ux::EntryData const& getButtonData(uint32_t buttonIdx)
		{
			return p_buttonData[buttonIdx];
		}


		virtual bool highlightOn(uint32_t buttonIdx)
		{
			if (p_buttons[buttonIdx] == p_activeBtn) return true;
			
			return false;
		}

		virtual void onClick(uint32_t buttonIdx)
		{
			p_activeBtn = p_buttons[buttonIdx];
			p_callback(p_buttons[buttonIdx]);
		}

		inline void setOnClick(std::function< callback_1arg > const& callback)
		{
			p_callback = callback;
		}

		inline void addButton(button_identifier const& identifier, ux::EntryData const& data)
		{
			p_buttons.push_back(identifier);
			p_buttonData.push_back(data);
		}

	protected:
		Orientation p_orient{ Orientation::eHorizontal };
		std::function< callback_1arg > p_callback;
		std::vector< button_identifier > p_buttons;
		std::vector< ux::EntryData > p_buttonData;
		button_identifier p_activeBtn;
	};



	template
		<
		typename tool_type,
		typename callback_1arg
		>
		class ToolBar
		: public ButtonBox< tool_type, callback_1arg >
	{
	public:
		explicit ToolBar(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: ButtonBox< tool_type, callback_1arg >(tag, x, y, w, h)
		{
			p_orient = Orientation::eVertical;
		}

		virtual ~ToolBar()
		{}

	protected:
		using ButtonBox< tool_type, callback_1arg >::p_orient;
	};
	


	template
		<
		typename mode_type,
		typename callback_1arg
		>
	class ModeBar
		: public ButtonBox< mode_type, callback_1arg >
	{
	public:
		explicit ModeBar(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: ButtonBox< mode_type, callback_1arg >(tag, x, y, w, h)
		{
			p_orient = Orientation::eHorizontal;
		}

		virtual ~ModeBar()
		{}

	protected:
		using ButtonBox< mode_type, callback_1arg >::p_orient;
	};

	
	
	class SecondaryViewport
		: public IBase
	{
	public:
		explicit SecondaryViewport(char const* tag, uint32_t x, uint32_t y, uint32_t w, uint32_t h)
			: IBase(tag, x, y, w, h)
		{}

		virtual ~SecondaryViewport()
		{}

		inline void setLabel(char const* label)
		{
			p_headerLabel = label;
		}

		inline std::string const& getLabel()
		{
			return p_headerLabel;
		}

	protected:
		std::string p_headerLabel{ "" };
	};

	using SecondaryViewportHandle = std::shared_ptr< SecondaryViewport >;


}



#endif // !UI_COMPONENTS