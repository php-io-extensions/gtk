#ifndef PHP_GTK_GTK_LIST_BOX_H
#define PHP_GTK_GTK_LIST_BOX_H

/*
 * GtkListBox — Wave B3. Every gir
 * constructor/method/function is bound or reserved. bind_model / selected_foreach / set_filter_func / set_header_func / set_sort_func reserved (non-signal callbacks). get_selected_rows is a container-owned GList of handles.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkListBox property "accept-unpaired-release" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkListBox new() -> int */
zend_long phpgtk_gtklistbox_new(void);
/*@zep Gtk\GtkListBox append(int handle, int child) -> void */
void phpgtk_gtklistbox_append(zval *handle, zval *child);
/*@reserved Gtk\GtkListBox gtk_list_box_bind_model(GListModel* model, GtkListBoxCreateWidgetFunc create_widget_func, gpointer user_data, GDestroyNotify user_data_free_func) — non-signal callback */
/*@zep Gtk\GtkListBox dragHighlightRow(int handle, int row) -> void */
void phpgtk_gtklistbox_drag_highlight_row(zval *handle, zval *row);
/*@zep Gtk\GtkListBox dragUnhighlightRow(int handle) -> void */
void phpgtk_gtklistbox_drag_unhighlight_row(zval *handle);
/*@zep Gtk\GtkListBox getActivateOnSingleClick(int handle) -> bool */
zend_long phpgtk_gtklistbox_get_activate_on_single_click(zval *handle);
/*@zep Gtk\GtkListBox getAdjustment(int handle) -> int */
zend_long phpgtk_gtklistbox_get_adjustment(zval *handle);
/*@zep Gtk\GtkListBox getRowAtIndex(int handle, int index) -> int */
zend_long phpgtk_gtklistbox_get_row_at_index(zval *handle, zval *index);
/*@zep Gtk\GtkListBox getRowAtY(int handle, int y) -> int */
zend_long phpgtk_gtklistbox_get_row_at_y(zval *handle, zval *y);
/*@zep Gtk\GtkListBox getSelectedRow(int handle) -> int */
zend_long phpgtk_gtklistbox_get_selected_row(zval *handle);
/*@zep Gtk\GtkListBox getSelectedRows(int handle) -> array */
void phpgtk_gtklistbox_get_selected_rows(zval *return_value, zval *handle);
/*@zep Gtk\GtkListBox getSelectionMode(int handle) -> int */
zend_long phpgtk_gtklistbox_get_selection_mode(zval *handle);
/*@zep Gtk\GtkListBox getShowSeparators(int handle) -> bool */
zend_long phpgtk_gtklistbox_get_show_separators(zval *handle);
/*@zep Gtk\GtkListBox getTabBehavior(int handle) -> int */
zend_long phpgtk_gtklistbox_get_tab_behavior(zval *handle);
/*@zep Gtk\GtkListBox insert(int handle, int child, int position) -> void */
void phpgtk_gtklistbox_insert(zval *handle, zval *child, zval *position);
/*@zep Gtk\GtkListBox invalidateFilter(int handle) -> void */
void phpgtk_gtklistbox_invalidate_filter(zval *handle);
/*@zep Gtk\GtkListBox invalidateHeaders(int handle) -> void */
void phpgtk_gtklistbox_invalidate_headers(zval *handle);
/*@zep Gtk\GtkListBox invalidateSort(int handle) -> void */
void phpgtk_gtklistbox_invalidate_sort(zval *handle);
/*@zep Gtk\GtkListBox prepend(int handle, int child) -> void */
void phpgtk_gtklistbox_prepend(zval *handle, zval *child);
/*@zep Gtk\GtkListBox remove(int handle, int child) -> void */
void phpgtk_gtklistbox_remove(zval *handle, zval *child);
/*@zep Gtk\GtkListBox removeAll(int handle) -> void */
void phpgtk_gtklistbox_remove_all(zval *handle);
/*@zep Gtk\GtkListBox selectAll(int handle) -> void */
void phpgtk_gtklistbox_select_all(zval *handle);
/*@zep Gtk\GtkListBox selectRow(int handle, int row) -> void */
void phpgtk_gtklistbox_select_row(zval *handle, zval *row);
/*@reserved Gtk\GtkListBox gtk_list_box_selected_foreach(GtkListBoxForeachFunc func, gpointer data) — non-signal callback */
/*@zep Gtk\GtkListBox setActivateOnSingleClick(int handle, bool single) -> void */
void phpgtk_gtklistbox_set_activate_on_single_click(zval *handle, zval *single);
/*@zep Gtk\GtkListBox setAdjustment(int handle, int adjustment) -> void */
void phpgtk_gtklistbox_set_adjustment(zval *handle, zval *adjustment);
/*@reserved Gtk\GtkListBox gtk_list_box_set_filter_func(GtkListBoxFilterFunc filter_func, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@reserved Gtk\GtkListBox gtk_list_box_set_header_func(GtkListBoxUpdateHeaderFunc update_header, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@zep Gtk\GtkListBox setPlaceholder(int handle, int placeholder) -> void */
void phpgtk_gtklistbox_set_placeholder(zval *handle, zval *placeholder);
/*@zep Gtk\GtkListBox setSelectionMode(int handle, int mode) -> void */
void phpgtk_gtklistbox_set_selection_mode(zval *handle, zval *mode);
/*@zep Gtk\GtkListBox setShowSeparators(int handle, bool showSeparators) -> void */
void phpgtk_gtklistbox_set_show_separators(zval *handle, zval *showSeparators);
/*@reserved Gtk\GtkListBox gtk_list_box_set_sort_func(GtkListBoxSortFunc sort_func, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@zep Gtk\GtkListBox setTabBehavior(int handle, int behavior) -> void */
void phpgtk_gtklistbox_set_tab_behavior(zval *handle, zval *behavior);
/*@zep Gtk\GtkListBox unselectAll(int handle) -> void */
void phpgtk_gtklistbox_unselect_all(zval *handle);
/*@zep Gtk\GtkListBox unselectRow(int handle, int row) -> void */
void phpgtk_gtklistbox_unselect_row(zval *handle, zval *row);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_LIST_BOX_H */
