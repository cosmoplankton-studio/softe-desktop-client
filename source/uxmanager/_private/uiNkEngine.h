/*
* ---------------------------------------------------------
* Copyright 2018 - present(c) Automatos Studios.All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uiNkEngine.h
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#ifndef UI_ENGINE
#define UI_ENGINE


#define NK_INCLUDE_VERTEX_BUFFER_OUTPUT
#define NK_INCLUDE_DEFAULT_ALLOCATOR
#define NK_INCLUDE_FONT_BAKING
#define NK_INCLUDE_DEFAULT_FONT
#include <nuklear/nuklear.h>

#include "uxDefines.h"
#include "uiBase.h"


namespace ui
{

	/* Baked Font Info */
	struct FontInfo
	{
		nk_font* font{ nullptr };
		nk_size* fontTexPtr{ nullptr };
		nk_font_atlas fontAtlas;
		nk_draw_null_texture nullTex;

		int fontSize{ 13 };
		int texWidth{ INT_MAX };
		int texHeight{ INT_MAX };
		int texBindingIdx{ 0 };
	};
	using FontInfo = struct FontInfo;



	class NkEngine
	{
	public:

		NkEngine();
		virtual ~NkEngine();

		void processEvents(::ux::UxEventInfo eventInfo);

		void addToolBarToCanvas(ButtonBoxHandle const& btnHandle);
		void addModeBarToCanvas(ButtonBoxHandle const& btnHandle);
		void addViewportToCanvas(SecondaryViewportHandle const& vHandle);

		void getVertexData(void** vertData, uint32_t &vertSize, void** indexData, uint32_t &indexSize, uint32_t &indexCount);
		void freeVertexData();

		FontInfo const& getFontInfo()
		{
			return p_fontInfo;
		}

	protected:
		void pStoreFontAtlasOnHost(void const *image, int fontImageWidth, int fontImageHeight);

	protected:
		nk_context	p_ctx;
		nk_buffer	p_cmdBuffer;
		nk_buffer	p_vertBuffer;
		nk_buffer	p_idxBuffer;

		FontInfo	p_fontInfo;


		class ButtonHightlight
		{
		public:
			ButtonHightlight(NkEngine* engine, bool activate)
			{
				if (activate)
				{
					p_engine = engine;
					p_isActive = activate;
					p_borderColorPrevious = engine->p_ctx.style.button.border_color;
					p_normalBtnStylePrevious = engine->p_ctx.style.button.normal;

					nk_color border_color = { 1, 87, 155, 255 };
					nk_color button_color = { 25, 25, 25, 255 };

					engine->p_ctx.style.button.border_color = border_color;
					engine->p_ctx.style.button.normal = nk_style_item_color(button_color);

					engine->p_ctx.style.button.hover = engine->p_ctx.style.button.normal;
					engine->p_ctx.style.button.active = engine->p_ctx.style.button.normal;
				}
			}

			~ButtonHightlight()
			{
				if (p_isActive)
				{
					p_isActive = false;
					p_engine->p_ctx.style.button.border_color = p_borderColorPrevious;
					p_engine->p_ctx.style.button.normal = p_normalBtnStylePrevious;

					p_engine->p_ctx.style.button.hover = p_engine->p_ctx.style.button.normal;
					p_engine->p_ctx.style.button.active = p_engine->p_ctx.style.button.normal;
				}
			}

		protected:
			NkEngine * p_engine{ nullptr };
			bool p_isActive{ false };
			nk_color p_borderColorPrevious;
			struct nk_style_item p_normalBtnStylePrevious;
		};

		class WindowPadding
		{
		public:
			WindowPadding(NkEngine* engine, float x, float y)
			{
				p_engine = engine;
				p_paddingPrevious.x = engine->p_ctx.style.window.padding.x;
				p_paddingPrevious.y = engine->p_ctx.style.window.padding.y;

				engine->p_ctx.style.window.padding.x = x;
				engine->p_ctx.style.window.padding.y = y;
			}

			~WindowPadding()
			{
				p_engine->p_ctx.style.window.padding.x = p_paddingPrevious.x;
				p_engine->p_ctx.style.window.padding.y = p_paddingPrevious.y;
			}

		protected:
			NkEngine * p_engine{ nullptr };
			struct nk_vec2 p_paddingPrevious;
		};

		
		class WindowBackground
		{
		public:
			WindowBackground(NkEngine* engine, bool transparent)
			{
				if (transparent)
				{
					p_engine = engine;
					p_transparentOn = transparent;
					p_colorPrevious = engine->p_ctx.style.window.background;
					nk_color window_color = { 45, 45, 45, 0 };
					p_engine->p_ctx.style.window.background = window_color;
					p_engine->p_ctx.style.window.fixed_background = nk_style_item_color(window_color);
				}
			}

			~WindowBackground()
			{
				if (p_transparentOn)
				{
					p_engine->p_ctx.style.window.background = p_colorPrevious;
					p_engine->p_ctx.style.window.fixed_background = nk_style_item_color(p_colorPrevious);
				}
			}

		protected:
			NkEngine * p_engine{ nullptr };
			bool p_transparentOn{ false };
			nk_color p_colorPrevious;

		};

	};
}




#endif // !UI_ENGINE

