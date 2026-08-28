#ifndef PHP_GTK_GTK_FLOW_BOX_H
#define PHP_GTK_GTK_FLOW_BOX_H

/*
 * GtkFlowBox — Wave B4. Every gir
 * constructor/method/function is bound or reserved. bind_model / selected_foreach / set_filter_func / set_sort_func reserved (non-signal callbacks). get_selected_children is a container-owned GList of handles.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkFlowBox property "accept-unpaired-release" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkFlowBox new() -> int */
zend_long phpgtk_gtkflowbox_new(void);
/*@zep Gtk\GtkFlowBox append(int handle, int child) -> void */
void phpgtk_gtkflowbox_append(zval *handle, zval *child);
/*@reserved Gtk\GtkFlowBox gtk_flow_box_bind_model(GListModel* model, GtkFlowBoxCreateWidgetFunc create_widget_func, gpointer user_data, GDestroyNotify user_data_free_func) — non-signal callback */
/*@zep Gtk\GtkFlowBox getActivateOnSingleClick(int handle) -> bool */
zend_long phpgtk_gtkflowbox_get_activate_on_single_click(zval *handle);
/*@zep Gtk\GtkFlowBox getChildAtIndex(int handle, int idx) -> int */
zend_long phpgtk_gtkflowbox_get_child_at_index(zval *handle, zval *idx);
/*@zep Gtk\GtkFlowBox getChildAtPos(int handle, int x, int y) -> int */
zend_long phpgtk_gtkflowbox_get_child_at_pos(zval *handle, zval *x, zval *y);
/*@zep Gtk\GtkFlowBox getColumnSpacing(int handle) -> int */
zend_long phpgtk_gtkflowbox_get_column_spacing(zval *handle);
/*@zep Gtk\GtkFlowBox getHomogeneous(int handle) -> bool */
zend_long phpgtk_gtkflowbox_get_homogeneous(zval *handle);
/*@zep Gtk\GtkFlowBox getMaxChildrenPerLine(int handle) -> int */
zend_long phpgtk_gtkflowbox_get_max_children_per_line(zval *handle);
/*@zep Gtk\GtkFlowBox getMinChildrenPerLine(int handle) -> int */
zend_long phpgtk_gtkflowbox_get_min_children_per_line(zval *handle);
/*@zep Gtk\GtkFlowBox getRowSpacing(int handle) -> int */
zend_long phpgtk_gtkflowbox_get_row_spacing(zval *handle);
/*@zep Gtk\GtkFlowBox getSelectedChildren(int handle) -> array */
void phpgtk_gtkflowbox_get_selected_children(zval *return_value, zval *handle);
/*@zep Gtk\GtkFlowBox getSelectionMode(int handle) -> int */
zend_long phpgtk_gtkflowbox_get_selection_mode(zval *handle);
/*@zep Gtk\GtkFlowBox insert(int handle, int widget, int position) -> void */
void phpgtk_gtkflowbox_insert(zval *handle, zval *widget, zval *position);
/*@zep Gtk\GtkFlowBox invalidateFilter(int handle) -> void */
void phpgtk_gtkflowbox_invalidate_filter(zval *handle);
/*@zep Gtk\GtkFlowBox invalidateSort(int handle) -> void */
void phpgtk_gtkflowbox_invalidate_sort(zval *handle);
/*@zep Gtk\GtkFlowBox prepend(int handle, int child) -> void */
void phpgtk_gtkflowbox_prepend(zval *handle, zval *child);
/*@zep Gtk\GtkFlowBox remove(int handle, int widget) -> void */
void phpgtk_gtkflowbox_remove(zval *handle, zval *widget);
/*@zep Gtk\GtkFlowBox removeAll(int handle) -> void */
void phpgtk_gtkflowbox_remove_all(zval *handle);
/*@zep Gtk\GtkFlowBox selectAll(int handle) -> void */
void phpgtk_gtkflowbox_select_all(zval *handle);
/*@zep Gtk\GtkFlowBox selectChild(int handle, int child) -> void */
void phpgtk_gtkflowbox_select_child(zval *handle, zval *child);
/*@reserved Gtk\GtkFlowBox gtk_flow_box_selected_foreach(GtkFlowBoxForeachFunc func, gpointer data) — non-signal callback */
/*@zep Gtk\GtkFlowBox setActivateOnSingleClick(int handle, bool single) -> void */
void phpgtk_gtkflowbox_set_activate_on_single_click(zval *handle, zval *single);
/*@zep Gtk\GtkFlowBox setColumnSpacing(int handle, int spacing) -> void */
void phpgtk_gtkflowbox_set_column_spacing(zval *handle, zval *spacing);
/*@reserved Gtk\GtkFlowBox gtk_flow_box_set_filter_func(GtkFlowBoxFilterFunc filter_func, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@zep Gtk\GtkFlowBox setHadjustment(int handle, int adjustment) -> void */
void phpgtk_gtkflowbox_set_hadjustment(zval *handle, zval *adjustment);
/*@zep Gtk\GtkFlowBox setHomogeneous(int handle, bool homogeneous) -> void */
void phpgtk_gtkflowbox_set_homogeneous(zval *handle, zval *homogeneous);
/*@zep Gtk\GtkFlowBox setMaxChildrenPerLine(int handle, int nChildren) -> void */
void phpgtk_gtkflowbox_set_max_children_per_line(zval *handle, zval *nChildren);
/*@zep Gtk\GtkFlowBox setMinChildrenPerLine(int handle, int nChildren) -> void */
void phpgtk_gtkflowbox_set_min_children_per_line(zval *handle, zval *nChildren);
/*@zep Gtk\GtkFlowBox setRowSpacing(int handle, int spacing) -> void */
void phpgtk_gtkflowbox_set_row_spacing(zval *handle, zval *spacing);
/*@zep Gtk\GtkFlowBox setSelectionMode(int handle, int mode) -> void */
void phpgtk_gtkflowbox_set_selection_mode(zval *handle, zval *mode);
/*@reserved Gtk\GtkFlowBox gtk_flow_box_set_sort_func(GtkFlowBoxSortFunc sort_func, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@zep Gtk\GtkFlowBox setVadjustment(int handle, int adjustment) -> void */
void phpgtk_gtkflowbox_set_vadjustment(zval *handle, zval *adjustment);
/*@zep Gtk\GtkFlowBox unselectAll(int handle) -> void */
void phpgtk_gtkflowbox_unselect_all(zval *handle);
/*@zep Gtk\GtkFlowBox unselectChild(int handle, int child) -> void */
void phpgtk_gtkflowbox_unselect_child(zval *handle, zval *child);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_FLOW_BOX_H */
