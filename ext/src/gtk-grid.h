#ifndef PHP_GTK_GTK_GRID_H
#define PHP_GTK_GTK_GRID_H

/*
 * GtkGrid — Wave A7. Every gir constructor/method/function is bound
 * or reserved. query_child's out-params are {column, row, width, height}.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkGrid new() -> int */
zend_long phpgtk_gtkgrid_new(void);
/*@zep Gtk\GtkGrid attach(int handle, int child, int column, int row, int width, int height) -> void */
void phpgtk_gtkgrid_attach(zval *handle, zval *child, zval *column, zval *row, zval *width, zval *height);
/*@zep Gtk\GtkGrid attachNextTo(int handle, int child, int sibling, int side, int width, int height) -> void */
void phpgtk_gtkgrid_attach_next_to(zval *handle, zval *child, zval *sibling, zval *side, zval *width, zval *height);
/*@zep Gtk\GtkGrid getBaselineRow(int handle) -> int */
zend_long phpgtk_gtkgrid_get_baseline_row(zval *handle);
/*@zep Gtk\GtkGrid getChildAt(int handle, int column, int row) -> int */
zend_long phpgtk_gtkgrid_get_child_at(zval *handle, zval *column, zval *row);
/*@zep Gtk\GtkGrid getColumnHomogeneous(int handle) -> bool */
zend_long phpgtk_gtkgrid_get_column_homogeneous(zval *handle);
/*@zep Gtk\GtkGrid getColumnSpacing(int handle) -> int */
zend_long phpgtk_gtkgrid_get_column_spacing(zval *handle);
/*@zep Gtk\GtkGrid getRowBaselinePosition(int handle, int row) -> int */
zend_long phpgtk_gtkgrid_get_row_baseline_position(zval *handle, zval *row);
/*@zep Gtk\GtkGrid getRowHomogeneous(int handle) -> bool */
zend_long phpgtk_gtkgrid_get_row_homogeneous(zval *handle);
/*@zep Gtk\GtkGrid getRowSpacing(int handle) -> int */
zend_long phpgtk_gtkgrid_get_row_spacing(zval *handle);
/*@zep Gtk\GtkGrid insertColumn(int handle, int position) -> void */
void phpgtk_gtkgrid_insert_column(zval *handle, zval *position);
/*@zep Gtk\GtkGrid insertNextTo(int handle, int sibling, int side) -> void */
void phpgtk_gtkgrid_insert_next_to(zval *handle, zval *sibling, zval *side);
/*@zep Gtk\GtkGrid insertRow(int handle, int position) -> void */
void phpgtk_gtkgrid_insert_row(zval *handle, zval *position);
/*@zep Gtk\GtkGrid queryChild(int handle, int child) -> array */
void phpgtk_gtkgrid_query_child(zval *return_value, zval *handle, zval *child);
/*@zep Gtk\GtkGrid remove(int handle, int child) -> void */
void phpgtk_gtkgrid_remove(zval *handle, zval *child);
/*@zep Gtk\GtkGrid removeColumn(int handle, int position) -> void */
void phpgtk_gtkgrid_remove_column(zval *handle, zval *position);
/*@zep Gtk\GtkGrid removeRow(int handle, int position) -> void */
void phpgtk_gtkgrid_remove_row(zval *handle, zval *position);
/*@zep Gtk\GtkGrid setBaselineRow(int handle, int row) -> void */
void phpgtk_gtkgrid_set_baseline_row(zval *handle, zval *row);
/*@zep Gtk\GtkGrid setColumnHomogeneous(int handle, bool homogeneous) -> void */
void phpgtk_gtkgrid_set_column_homogeneous(zval *handle, zval *homogeneous);
/*@zep Gtk\GtkGrid setColumnSpacing(int handle, int spacing) -> void */
void phpgtk_gtkgrid_set_column_spacing(zval *handle, zval *spacing);
/*@zep Gtk\GtkGrid setRowBaselinePosition(int handle, int row, int pos) -> void */
void phpgtk_gtkgrid_set_row_baseline_position(zval *handle, zval *row, zval *pos);
/*@zep Gtk\GtkGrid setRowHomogeneous(int handle, bool homogeneous) -> void */
void phpgtk_gtkgrid_set_row_homogeneous(zval *handle, zval *homogeneous);
/*@zep Gtk\GtkGrid setRowSpacing(int handle, int spacing) -> void */
void phpgtk_gtkgrid_set_row_spacing(zval *handle, zval *spacing);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_GRID_H */
