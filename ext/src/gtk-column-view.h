#ifndef PHP_GTK_GTK_COLUMN_VIEW_H
#define PHP_GTK_GTK_COLUMN_VIEW_H

/*
 * GtkColumnView — Wave C. Every gir constructor/method/function is bound
 * or reserved. get_sorter stays reserved (GtkSorter*); scroll_to stays
 * reserved (GtkScrollInfo*). new(model) takes a transfer-full
 * GtkSelectionModel, same pattern as GtkDropDown::new.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkColumnView new(int model) -> int */
zend_long phpgtk_gtkcolumnview_new(zval *model);
/*@zep Gtk\GtkColumnView appendColumn(int handle, int column) -> void */
void phpgtk_gtkcolumnview_append_column(zval *handle, zval *column);
/*@zep Gtk\GtkColumnView getColumns(int handle) -> int */
zend_long phpgtk_gtkcolumnview_get_columns(zval *handle);
/*@zep Gtk\GtkColumnView getEnableRubberband(int handle) -> bool */
zend_long phpgtk_gtkcolumnview_get_enable_rubberband(zval *handle);
/*@zep Gtk\GtkColumnView getHeaderFactory(int handle) -> int */
zend_long phpgtk_gtkcolumnview_get_header_factory(zval *handle);
/*@zep Gtk\GtkColumnView getModel(int handle) -> int */
zend_long phpgtk_gtkcolumnview_get_model(zval *handle);
/*@zep Gtk\GtkColumnView getReorderable(int handle) -> bool */
zend_long phpgtk_gtkcolumnview_get_reorderable(zval *handle);
/*@zep Gtk\GtkColumnView getRowFactory(int handle) -> int */
zend_long phpgtk_gtkcolumnview_get_row_factory(zval *handle);
/*@zep Gtk\GtkColumnView getShowColumnSeparators(int handle) -> bool */
zend_long phpgtk_gtkcolumnview_get_show_column_separators(zval *handle);
/*@zep Gtk\GtkColumnView getShowRowSeparators(int handle) -> bool */
zend_long phpgtk_gtkcolumnview_get_show_row_separators(zval *handle);
/*@zep Gtk\GtkColumnView getSingleClickActivate(int handle) -> bool */
zend_long phpgtk_gtkcolumnview_get_single_click_activate(zval *handle);
/*@reserved Gtk\GtkColumnView gtk_column_view_get_sorter() — GtkSorter* */
/*@zep Gtk\GtkColumnView getTabBehavior(int handle) -> int */
zend_long phpgtk_gtkcolumnview_get_tab_behavior(zval *handle);
/*@zep Gtk\GtkColumnView insertColumn(int handle, int position, int column) -> void */
void phpgtk_gtkcolumnview_insert_column(zval *handle, zval *position, zval *column);
/*@zep Gtk\GtkColumnView removeColumn(int handle, int column) -> void */
void phpgtk_gtkcolumnview_remove_column(zval *handle, zval *column);
/*@reserved Gtk\GtkColumnView gtk_column_view_scroll_to(pos, column, flags, GtkScrollInfo* scroll) — GtkScrollInfo* boxed */
/*@zep Gtk\GtkColumnView setEnableRubberband(int handle, bool enableRubberband) -> void */
void phpgtk_gtkcolumnview_set_enable_rubberband(zval *handle, zval *enableRubberband);
/*@zep Gtk\GtkColumnView setHeaderFactory(int handle, int factory) -> void */
void phpgtk_gtkcolumnview_set_header_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkColumnView setModel(int handle, int model) -> void */
void phpgtk_gtkcolumnview_set_model(zval *handle, zval *model);
/*@zep Gtk\GtkColumnView setReorderable(int handle, bool reorderable) -> void */
void phpgtk_gtkcolumnview_set_reorderable(zval *handle, zval *reorderable);
/*@zep Gtk\GtkColumnView setRowFactory(int handle, int factory) -> void */
void phpgtk_gtkcolumnview_set_row_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkColumnView setShowColumnSeparators(int handle, bool showColumnSeparators) -> void */
void phpgtk_gtkcolumnview_set_show_column_separators(zval *handle, zval *showColumnSeparators);
/*@zep Gtk\GtkColumnView setShowRowSeparators(int handle, bool showRowSeparators) -> void */
void phpgtk_gtkcolumnview_set_show_row_separators(zval *handle, zval *showRowSeparators);
/*@zep Gtk\GtkColumnView setSingleClickActivate(int handle, bool singleClickActivate) -> void */
void phpgtk_gtkcolumnview_set_single_click_activate(zval *handle, zval *singleClickActivate);
/*@zep Gtk\GtkColumnView setTabBehavior(int handle, int tabBehavior) -> void */
void phpgtk_gtkcolumnview_set_tab_behavior(zval *handle, zval *tabBehavior);
/*@zep Gtk\GtkColumnView sortByColumn(int handle, int column, int direction) -> void */
void phpgtk_gtkcolumnview_sort_by_column(zval *handle, zval *column, zval *direction);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_COLUMN_VIEW_H */
