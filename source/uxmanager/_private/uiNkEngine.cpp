/*
* ---------------------------------------------------------
* Copyright 2018 - present(c) Automatos Studios.All Rights Reserved.
* ---------------------------------------------------------
*/

/**
* @file			uiNkEngine.cpp
* @author		cosmoplankton < cosmoplankton@automatos.studio >
*/


#define NK_IMPLEMENTATION

#include <string>
#include "uiNkEngine.h"


namespace ui
{
	/*
	[ TEMPORARY ]
	*/
	struct uiVertex
	{
		float pos[2];
		float uv[2];
		float color[4];
	};


	/*
	**************************************
	class NkEngine
	**************************************
	*/

	NkEngine::NkEngine()
	{
		nk_font_atlas_init_default(&p_fontInfo.fontAtlas);
		nk_font_atlas_begin(&p_fontInfo.fontAtlas);
		p_fontInfo.font = nk_font_atlas_add_default(&p_fontInfo.fontAtlas, p_fontInfo.fontSize, NULL);

		void const *image = nk_font_atlas_bake(&p_fontInfo.fontAtlas, &p_fontInfo.texWidth, &p_fontInfo.texHeight, NK_FONT_ATLAS_ALPHA8 /* NK_FONT_ATLAS_RGBA32 */);
		pStoreFontAtlasOnHost(image, p_fontInfo.texWidth, p_fontInfo.texHeight);

		nk_font_atlas_end(&p_fontInfo.fontAtlas, nk_handle_id((int)p_fontInfo.fontTexPtr), &p_fontInfo.nullTex);

		nk_init_default(&p_ctx, &p_fontInfo.font->handle);

		p_ctx.style.button.rounding = 0.0;
		p_ctx.style.button.border = 1.0f;

		p_ctx.style.button.hover = p_ctx.style.button.normal;
		p_ctx.style.button.active = p_ctx.style.button.normal;
	}


	NkEngine::~NkEngine()
	{
		nk_font_atlas_clear(&p_fontInfo.fontAtlas);
		nk_free(&p_ctx);
		delete[] p_fontInfo.fontTexPtr;
	}


	void NkEngine::processEvents(::ux::UxEventInfo eventInfo)
	{
		nk_input_begin(&p_ctx);
		nk_input_motion(&p_ctx, eventInfo.mouseX, eventInfo.mouseY);
		nk_input_button(&p_ctx, NK_BUTTON_LEFT, eventInfo.mouseX, eventInfo.mouseY, eventInfo.event == ::ux::UxEventType::UX_EVENT_MOUSE_L_DOWN);
		nk_input_button(&p_ctx, NK_BUTTON_MIDDLE, eventInfo.mouseX, eventInfo.mouseY, eventInfo.event == ::ux::UxEventType::UX_EVENT_MOUSE_M_DOWN);
		nk_input_button(&p_ctx, NK_BUTTON_RIGHT, eventInfo.mouseX, eventInfo.mouseY, eventInfo.event == ::ux::UxEventType::UX_EVENT_MOUSE_R_DOWN);
		nk_input_end(&p_ctx);
	}

	
	void NkEngine::addToolBarToCanvas(ButtonBoxHandle const& btnHandle)
	{
		auto const& dim = btnHandle->getDimensions();

		WindowPadding _nopadding(this, 0, 0);
		if (nk_begin(&p_ctx, btnHandle->getLabel().c_str(), nk_rect(dim.x, dim.y, dim.width, dim.height), NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_MINIMIZABLE | NK_WINDOW_TITLE))
		{
			nk_layout_row_static(&p_ctx, dim.width, dim.width-1, 1);
			
			for (uint32_t idx = 0; idx < btnHandle->getButtonCount(); ++idx)
			{
				auto const& btnData = btnHandle->getButtonData(idx);

				ButtonHightlight _highlight(this, btnHandle->highlightOn(idx));
				if (nk_button_label(&p_ctx, btnData.getLabel().c_str()))
				{
					// event handling
					btnHandle->onClick(idx);
				}
			}
		}
		nk_end(&p_ctx);

	}



	void NkEngine::addModeBarToCanvas(ButtonBoxHandle const& btnHandle)
	{
		auto const& dim = btnHandle->getDimensions();
		
		WindowBackground _transparent(this, true);
		WindowPadding _nopadding(this, 0, 0);
		if (nk_begin(&p_ctx, btnHandle->getLabel().c_str(), nk_rect(dim.x, dim.y, dim.width, dim.height), NK_WINDOW_NO_SCROLLBAR))
		{
			nk_layout_row_dynamic(&p_ctx, dim.height, btnHandle->getButtonCount());
			
			for (uint32_t idx = 0; idx < btnHandle->getButtonCount(); ++idx)
			{
				auto const& btnData = btnHandle->getButtonData(idx);

				ButtonHightlight _highlight(this, btnHandle->highlightOn(idx));
				if (nk_button_label(&p_ctx, btnData.getLabel().c_str()))
				{
					// event handling
					btnHandle->onClick(idx);
				}
			}
		}
		nk_end(&p_ctx);
	}


	void NkEngine::addViewportToCanvas(SecondaryViewportHandle const& vHandle)
	{
		auto const& dim = vHandle->getDimensions();
		
		if (nk_begin(&p_ctx, vHandle->getLabel().c_str(), nk_rect(dim.x, dim.y, dim.width, dim.height), NK_WINDOW_NO_SCROLLBAR | NK_WINDOW_MINIMIZABLE | NK_WINDOW_TITLE))
		{
			// VizEngine will use this area to render datasets.
		}
		nk_end(&p_ctx);
	}
	

	void NkEngine::getVertexData(void** vertData, uint32_t &vertSize, void** indexData, uint32_t &indexSize, uint32_t &indexCount)
	{
		struct nk_convert_config convertCfg = {};

		static const struct nk_draw_vertex_layout_element vertex_layout[] = {
			{ NK_VERTEX_POSITION,	NK_FORMAT_FLOAT,				NK_OFFSETOF(uiVertex, pos) },
			{ NK_VERTEX_TEXCOORD,	NK_FORMAT_FLOAT,				NK_OFFSETOF(uiVertex, uv) },
			{ NK_VERTEX_COLOR,		NK_FORMAT_R32G32B32A32_FLOAT,	NK_OFFSETOF(uiVertex, color) },
			{ NK_VERTEX_LAYOUT_END }
		};

		convertCfg.shape_AA = NK_ANTI_ALIASING_ON;
		convertCfg.line_AA = NK_ANTI_ALIASING_ON;
		convertCfg.vertex_layout = vertex_layout;
		convertCfg.vertex_size = sizeof(uiVertex);
		convertCfg.vertex_alignment = NK_ALIGNOF(uiVertex);
		convertCfg.circle_segment_count = 22;
		convertCfg.curve_segment_count = 22;
		convertCfg.arc_segment_count = 22;
		convertCfg.global_alpha = 1.0f;
		convertCfg.null = p_fontInfo.nullTex;

		// setup buffers and convert
		nk_buffer_init_default(&p_cmdBuffer);
		nk_buffer_init_default(&p_vertBuffer);
		nk_buffer_init_default(&p_idxBuffer);
		nk_convert(&p_ctx, &p_cmdBuffer, &p_vertBuffer, &p_idxBuffer, &convertCfg);

		*vertData = p_vertBuffer.memory.ptr;
		vertSize = p_vertBuffer.needed;

		*indexData = p_idxBuffer.memory.ptr;
		indexSize = p_idxBuffer.needed;

		indexCount = indexSize/ sizeof(uint16_t);
	}

	void NkEngine::freeVertexData()
	{
		nk_buffer_free(&p_cmdBuffer);
		nk_buffer_free(&p_vertBuffer);
		nk_buffer_free(&p_idxBuffer);

		nk_clear(&p_ctx);
	}

	void NkEngine::pStoreFontAtlasOnHost(void const *image, int fontImageWidth, int fontImageHeight)
	{
		int memSize = 4 * fontImageWidth * fontImageHeight;
		p_fontInfo.fontTexPtr = (nk_size*)new char[memSize];
		memcpy(p_fontInfo.fontTexPtr, image, memSize);
	}

}