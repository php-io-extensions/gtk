#ifndef PHP_GTK_GTK_NOTEBOOK_H
#define PHP_GTK_GTK_NOTEBOOK_H

/*
 * GtkNotebook — Wave B4. Every gir
 * constructor/method/function is bound or reserved. get_pages is transfer-full. get_page returns an obtain-only GtkNotebookPage handle.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkNotebook property "enable-popup" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkNotebook new() -> int */
zend_long phpgtk_gtknotebook_new(void);
/*@zep Gtk\GtkNotebook appendPage(int handle, int child, int tabLabel) -> int */
zend_long phpgtk_gtknotebook_append_page(zval *handle, zval *child, zval *tabLabel);
/*@zep Gtk\GtkNotebook appendPageMenu(int handle, int child, int tabLabel, int menuLabel) -> int */
zend_long phpgtk_gtknotebook_append_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel);
/*@zep Gtk\GtkNotebook detachTab(int handle, int child) -> void */
void phpgtk_gtknotebook_detach_tab(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getActionWidget(int handle, int packType) -> int */
zend_long phpgtk_gtknotebook_get_action_widget(zval *handle, zval *packType);
/*@zep Gtk\GtkNotebook getCurrentPage(int handle) -> int */
zend_long phpgtk_gtknotebook_get_current_page(zval *handle);
/*@zep Gtk\GtkNotebook getGroupName(int handle) -> var */
void phpgtk_gtknotebook_get_group_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkNotebook getMenuLabel(int handle, int child) -> int */
zend_long phpgtk_gtknotebook_get_menu_label(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getMenuLabelText(int handle, int child) -> var */
void phpgtk_gtknotebook_get_menu_label_text(zval *return_value, zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getNPages(int handle) -> int */
zend_long phpgtk_gtknotebook_get_n_pages(zval *handle);
/*@zep Gtk\GtkNotebook getNthPage(int handle, int pageNum) -> int */
zend_long phpgtk_gtknotebook_get_nth_page(zval *handle, zval *pageNum);
/*@zep Gtk\GtkNotebook getPage(int handle, int child) -> int */
zend_long phpgtk_gtknotebook_get_page(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getPages(int handle) -> int */
zend_long phpgtk_gtknotebook_get_pages(zval *handle);
/*@zep Gtk\GtkNotebook getScrollable(int handle) -> bool */
zend_long phpgtk_gtknotebook_get_scrollable(zval *handle);
/*@zep Gtk\GtkNotebook getShowBorder(int handle) -> bool */
zend_long phpgtk_gtknotebook_get_show_border(zval *handle);
/*@zep Gtk\GtkNotebook getShowTabs(int handle) -> bool */
zend_long phpgtk_gtknotebook_get_show_tabs(zval *handle);
/*@zep Gtk\GtkNotebook getTabDetachable(int handle, int child) -> bool */
zend_long phpgtk_gtknotebook_get_tab_detachable(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getTabLabel(int handle, int child) -> int */
zend_long phpgtk_gtknotebook_get_tab_label(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getTabLabelText(int handle, int child) -> var */
void phpgtk_gtknotebook_get_tab_label_text(zval *return_value, zval *handle, zval *child);
/*@zep Gtk\GtkNotebook getTabPos(int handle) -> int */
zend_long phpgtk_gtknotebook_get_tab_pos(zval *handle);
/*@zep Gtk\GtkNotebook getTabReorderable(int handle, int child) -> bool */
zend_long phpgtk_gtknotebook_get_tab_reorderable(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook insertPage(int handle, int child, int tabLabel, int position) -> int */
zend_long phpgtk_gtknotebook_insert_page(zval *handle, zval *child, zval *tabLabel, zval *position);
/*@zep Gtk\GtkNotebook insertPageMenu(int handle, int child, int tabLabel, int menuLabel, int position) -> int */
zend_long phpgtk_gtknotebook_insert_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel, zval *position);
/*@zep Gtk\GtkNotebook nextPage(int handle) -> void */
void phpgtk_gtknotebook_next_page(zval *handle);
/*@zep Gtk\GtkNotebook pageNum(int handle, int child) -> int */
zend_long phpgtk_gtknotebook_page_num(zval *handle, zval *child);
/*@zep Gtk\GtkNotebook popupDisable(int handle) -> void */
void phpgtk_gtknotebook_popup_disable(zval *handle);
/*@zep Gtk\GtkNotebook popupEnable(int handle) -> void */
void phpgtk_gtknotebook_popup_enable(zval *handle);
/*@zep Gtk\GtkNotebook prependPage(int handle, int child, int tabLabel) -> int */
zend_long phpgtk_gtknotebook_prepend_page(zval *handle, zval *child, zval *tabLabel);
/*@zep Gtk\GtkNotebook prependPageMenu(int handle, int child, int tabLabel, int menuLabel) -> int */
zend_long phpgtk_gtknotebook_prepend_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel);
/*@zep Gtk\GtkNotebook prevPage(int handle) -> void */
void phpgtk_gtknotebook_prev_page(zval *handle);
/*@zep Gtk\GtkNotebook removePage(int handle, int pageNum) -> void */
void phpgtk_gtknotebook_remove_page(zval *handle, zval *pageNum);
/*@zep Gtk\GtkNotebook reorderChild(int handle, int child, int position) -> void */
void phpgtk_gtknotebook_reorder_child(zval *handle, zval *child, zval *position);
/*@zep Gtk\GtkNotebook setActionWidget(int handle, int widget, int packType) -> void */
void phpgtk_gtknotebook_set_action_widget(zval *handle, zval *widget, zval *packType);
/*@zep Gtk\GtkNotebook setCurrentPage(int handle, int pageNum) -> void */
void phpgtk_gtknotebook_set_current_page(zval *handle, zval *pageNum);
/*@zep Gtk\GtkNotebook setGroupName(int handle, var groupName) -> void */
void phpgtk_gtknotebook_set_group_name(zval *handle, zval *groupName);
/*@zep Gtk\GtkNotebook setMenuLabel(int handle, int child, int menuLabel) -> void */
void phpgtk_gtknotebook_set_menu_label(zval *handle, zval *child, zval *menuLabel);
/*@zep Gtk\GtkNotebook setMenuLabelText(int handle, int child, string menuText) -> void */
void phpgtk_gtknotebook_set_menu_label_text(zval *handle, zval *child, zval *menuText);
/*@zep Gtk\GtkNotebook setScrollable(int handle, bool scrollable) -> void */
void phpgtk_gtknotebook_set_scrollable(zval *handle, zval *scrollable);
/*@zep Gtk\GtkNotebook setShowBorder(int handle, bool showBorder) -> void */
void phpgtk_gtknotebook_set_show_border(zval *handle, zval *showBorder);
/*@zep Gtk\GtkNotebook setShowTabs(int handle, bool showTabs) -> void */
void phpgtk_gtknotebook_set_show_tabs(zval *handle, zval *showTabs);
/*@zep Gtk\GtkNotebook setTabDetachable(int handle, int child, bool detachable) -> void */
void phpgtk_gtknotebook_set_tab_detachable(zval *handle, zval *child, zval *detachable);
/*@zep Gtk\GtkNotebook setTabLabel(int handle, int child, int tabLabel) -> void */
void phpgtk_gtknotebook_set_tab_label(zval *handle, zval *child, zval *tabLabel);
/*@zep Gtk\GtkNotebook setTabLabelText(int handle, int child, string tabText) -> void */
void phpgtk_gtknotebook_set_tab_label_text(zval *handle, zval *child, zval *tabText);
/*@zep Gtk\GtkNotebook setTabPos(int handle, int pos) -> void */
void phpgtk_gtknotebook_set_tab_pos(zval *handle, zval *pos);
/*@zep Gtk\GtkNotebook setTabReorderable(int handle, int child, bool reorderable) -> void */
void phpgtk_gtknotebook_set_tab_reorderable(zval *handle, zval *child, zval *reorderable);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_NOTEBOOK_H */
