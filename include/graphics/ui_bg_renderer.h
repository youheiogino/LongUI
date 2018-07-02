﻿#pragma once

#include "ui_renderer_decl.h"
#include "../core/ui_color.h"
#include "../core/ui_object.h"
#include "../core/ui_basic_type.h"
#include "../style/ui_attribute.h"
#include "../graphics/ui_graphics_decl.h"

namespace LongUI {
    // box
    struct Box;
    // background renderer
    class CUIRendererBackground : public CUISmallObject {
    public:
        // ctor
        CUIRendererBackground() noexcept;
        // dtor
        ~CUIRendererBackground() noexcept;
        // move ctor
        CUIRendererBackground(CUIRendererBackground&&) = delete;
        // copy ctor
        CUIRendererBackground(const CUIRendererBackground&) = delete;
        // render color
        void RenderColor(const Box& box) const noexcept;
        // render image
        void RenderImage(const Box& box) const noexcept;
        // refresh image
        auto RefreshImage() noexcept->Result;
        // recreate
        auto Recreate() noexcept->Result;
    private:
        // release brush
        void release_brush() noexcept;
        // get render rect
        void get_render_rect(const Box&, RectF&) const noexcept;
        // ------------- GPU-RES ------------
        // image brush
        I::Brush*           m_pImageBrush = nullptr;
    public:
        // ------------- CPU-RES ------------
        // background-color
        ColorF              color;
        // background-image
        uint32_t            image_id = 0;
        // background-clip
        AttributeBox        clip = Box_BorderBox;
        // background-repeat
        AttributeRepeat     repeat = Repeat_Repeat;
        // background-origin 
        AttributeBox        origin = Box_PaddingBox;
        // background-attachment
        AttributeAttachment attachment = Attachment_Scroll;
    };
}