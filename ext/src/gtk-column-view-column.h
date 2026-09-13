#ifndef PHP_GTK_GTK_COLUMN_VIEW_COLUMN_H
#define PHP_GTK_GTK_COLUMN_VIEW_COLUMN_H

/*
 * GtkColumnViewColumn — Wave C. Every gir constructor/method/function is
 * bound or reserved. get_sorter / set_sorter stay reserved (GtkSorter*).
 * Constructor is transfer-full and takes a transfer-full factory.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkColumnViewColumn new(var title, int factory) -> int */
zend_long phpgtk_gtkcolumnviewcolumn_new(zval *title, zval *factory);
/*@zep Gtk\GtkColumnViewColumn getColumnView(int handle) -> int */
zend_long phpgtk_gtkcolumnviewcolumn_get_column_view(zval *handle);
/*@zep Gtk\GtkColumnViewColumn getExpand(int handle) -> bool */
zend_long phpgtk_gtkcolumnviewcolumn_get_expand(zval *handle);
/*@zep Gtk\GtkColumnViewColumn getFactory(int handle) -> int */
zend_long phpgtk_gtkcolumnviewcolumn_get_factory(zval *handle);
/*@zep Gtk\GtkColumnViewColumn getFixedWidth(int handle) -> int */
zend_long phpgtk_gtkcolumnviewcolumn_get_fixed_width(zval *handle);
/*@zep Gtk\GtkColumnViewColumn getHeaderMenu(int handle) -> int */
zend_long phpgtk_gtkcolumnviewcolumn_get_header_menu(zval *handle);
/*@zep Gtk\GtkColumnViewColumn getId(int handle) -> var */
void phpgtk_gtkcolumnviewcolumn_get_id(zval *return_value, zval *handle);
/*@zep Gtk\GtkColumnViewColumn getResizable(int handle) -> bool */
zend_long phpgtk_gtkcolumnviewcolumn_get_resizable(zval *handle);
/*@reserved Gtk\GtkColumnViewColumn gtk_column_view_column_get_sorter() — GtkSorter* */
/*@zep Gtk\GtkColumnViewColumn getTitle(int handle) -> var */
void phpgtk_gtkcolumnviewcolumn_get_title(zval *return_value, zval *handle);
/*@zep Gtk\GtkColumnViewColumn getVisible(int handle) -> bool */
zend_long phpgtk_gtkcolumnviewcolumn_get_visible(zval *handle);
/*@zep Gtk\GtkColumnViewColumn setExpand(int handle, bool expand) -> void */
void phpgtk_gtkcolumnviewcolumn_set_expand(zval *handle, zval *expand);
/*@zep Gtk\GtkColumnViewColumn setFactory(int handle, int factory) -> void */
void phpgtk_gtkcolumnviewcolumn_set_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkColumnViewColumn setFixedWidth(int handle, int fixedWidth) -> void */
void phpgtk_gtkcolumnviewcolumn_set_fixed_width(zval *handle, zval *fixedWidth);
/*@zep Gtk\GtkColumnViewColumn setHeaderMenu(int handle, int menu) -> void */
void phpgtk_gtkcolumnviewcolumn_set_header_menu(zval *handle, zval *menu);
/*@zep Gtk\GtkColumnViewColumn setId(int handle, var id) -> void */
void phpgtk_gtkcolumnviewcolumn_set_id(zval *handle, zval *id);
/*@zep Gtk\GtkColumnViewColumn setResizable(int handle, bool resizable) -> void */
void phpgtk_gtkcolumnviewcolumn_set_resizable(zval *handle, zval *resizable);
/*@reserved Gtk\GtkColumnViewColumn gtk_column_view_column_set_sorter(GtkSorter* sorter) — GtkSorter* */
/*@zep Gtk\GtkColumnViewColumn setTitle(int handle, var title) -> void */
void phpgtk_gtkcolumnviewcolumn_set_title(zval *handle, zval *title);
/*@zep Gtk\GtkColumnViewColumn setVisible(int handle, bool visible) -> void */
void phpgtk_gtkcolumnviewcolumn_set_visible(zval *handle, zval *visible);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_COLUMN_VIEW_COLUMN_H */
