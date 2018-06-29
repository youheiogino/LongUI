﻿#include <interface/ui_ctrlinfolist.h>
#include <control/ui_radiogroup.h>
#include <control/ui_box_layout.h>
#include <control/ui_scroll_bar.h>
#include <control/ui_listheader.h>
#include <control/ui_menupopup.h>
#include <control/ui_menulist.h>
#include <control/ui_menuitem.h>
#include <control/ui_groupbox.h>
#include <control/ui_checkbox.h>
#include <control/ui_listhead.h>
#include <control/ui_splitter.h>
#include <control/ui_listitem.h>
#include <control/ui_listcols.h>
#include <control/ui_progress.h>
#include <control/ui_caption.h>
#include <control/ui_listcol.h>
#include <control/ui_listbox.h>
#include <control/ui_textbox.h>
#include <control/ui_spacer.h>
#include <control/ui_button.h>
#include <control/ui_radio.h>
#include <control/ui_scale.h>
#include <control/ui_image.h>
#include <control/ui_label.h>
#include <control/ui_stack.h>
#include <control/ui_deck.h>
#include <control/ui_test.h>

#include <control/ui_tab.h>
#include <control/ui_tabs.h>
#include <control/ui_tabbox.h>
#include <control/ui_tabpanel.h>
#include <control/ui_tabpanels.h>

#include <control/ui_tree.h>
#include <control/ui_treerow.h>
#include <control/ui_treecol.h>
#include <control/ui_treecols.h>
#include <control/ui_treeitem.h>
#include <control/ui_treecell.h>
#include <control/ui_treechildren.h>

// ui namespace
namespace LongUI {
    /// <summary>
    /// The defualt control information
    /// </summary>
    const MetaControl* const DefualtControlInfo[] = {
        // V Box Layout - 垂直箱型布局
        &UIVBoxLayout::s_meta,
        // H Box Layout - 水平箱型布局
        &UIHBoxLayout::s_meta,
        // Radio Group - 单选框组
        &UIRadioGroup::s_meta,
        // List Header - 列表头项
        &UIListHeader::s_meta,
        // Box Layout - 箱型布局
        &UIBoxLayout::s_meta,
        // Scroll Bar - 滚动条
        &UIScrollBar::s_meta,
        // Menu Popup - 菜单弹窗
        &UIMenuPopup::s_meta,
        // Check Box - 多选框
        &UICheckBox::s_meta,
        // Group Box - 分组框
        &UIGroupBox::s_meta,
        // Menu Item - 菜单项
        &UIMenuItem::s_meta,
        // Menu List - 菜单表
        &UIMenuList::s_meta,
        // Progress - 进度条
        &UIProgress::s_meta,
        // Splitter - 分割线
        &UISplitter::s_meta,
        // Text Box - 文本框
        &UITextBox::s_meta,
        // Caption - 分组标题
        &UICaption::s_meta,
        // Spacer - 占位控件
        &UISpacer::s_meta,
        // Button - 按钮控件
        &UIButton::s_meta,
        // Scale - 滑动控件
        &UIScale::s_meta,
        // Image - 图像控件
        &UIImage::s_meta,
        // Label - 标签控件
        &UILabel::s_meta,
        // Radio - 单选框
        &UIRadio::s_meta,
        // Stack - 栈容器
        &UIStack::s_meta,
        // Deck - 甲板容器
        &UIDeck::s_meta,

        // Tab - 标签页
        &UITab::s_meta,
        // Tabs - 标签页组
        &UITabs::s_meta,
        // Tab Box - 标签页框
        &UITabBox::s_meta,
        // Tab Panel - 标签页容器(可选)
        &UITabPanel::s_meta,
        // Tab Panels - 标签页容器组
        &UITabPanels::s_meta,

        // List Head - 列表头组
        &UIListHead::s_meta,
        // List Item - 列表项
        &UIListItem::s_meta,
        // List Item - 列表列组
        &UIListCols::s_meta,
        // List Box - 列表列
        &UIListCol::s_meta,
        // List Box - 列表框
        &UIListBox::s_meta,

        // Tree - 树控件
        &UITree::s_meta,
        // Tree Row - 树行组
        &UITreeRow::s_meta,
        // Tree Col - 树列项
        &UITreeCol::s_meta,
        // Tree Cols - 树列组
        &UITreeCols::s_meta,
        // Tree Item - 树项目
        &UITreeItem::s_meta,
        // Tree Cell - 树单元
        &UITreeCell::s_meta,
        // Tree Children - 树子节点
        &UITreeChildren::s_meta,

#ifndef NDEBUG
        // Test - 测试控件
        &UITest::s_meta,
        // Test - 一般控件
        &UIControl::s_meta,
#endif
    };
    /// <summary>
    /// Adds the defualt control information.
    /// </summary>
    /// <param name="list">The list.</param>
    void AddDefualtControlInfo(ControlInfoList& list) noexcept {
        // 默认CC数量
        constexpr uint32_t CONTROL_CLASS_SIZE = 48;
        list.reserve(CONTROL_CLASS_SIZE);
        if (list) list.assign(
            std::begin(DefualtControlInfo),
            std::end(DefualtControlInfo)
        );
#ifndef NDEBUG
        // CONTROL_CLASS_SIZE要足够大
        assert(list.size() <= CONTROL_CLASS_SIZE && "set it to bigger");
        // 测试正确性
        for (auto x : DefualtControlInfo) {
            // 跳过这个
            if (x == &UIMenuPopup::s_meta) continue;
            // 测试这个
            if (auto ctrl = x->create_func(nullptr)) {
                assert(&ctrl->GetMetaInfo() == x);
                delete ctrl;
            }
        }
#endif
    }
}