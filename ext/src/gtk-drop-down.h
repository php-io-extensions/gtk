#ifndef PHP_GTK_GTK_DROP_DOWN_H
#define PHP_GTK_GTK_DROP_DOWN_H

/*
 * GtkDropDown — Wave B3. Every gir
 * constructor/method/function is bound or reserved. get_expression / set_expression reserved (GtkExpression*). new(model) passes NULL for the expression argument.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkDropDown new(int model) -> int */
zend_long phpgtk_gtkdropdown_new(zval *model);
/*@zep Gtk\GtkDropDown newFromStrings(array strings) -> int */
zend_long phpgtk_gtkdropdown_new_from_strings(zval *strings);
/*@zep Gtk\GtkDropDown getEnableSearch(int handle) -> bool */
zend_long phpgtk_gtkdropdown_get_enable_search(zval *handle);
/*@reserved Gtk\GtkDropDown gtk_drop_down_get_expression() — GtkExpression* */
/*@zep Gtk\GtkDropDown getFactory(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_factory(zval *handle);
/*@zep Gtk\GtkDropDown getHeaderFactory(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_header_factory(zval *handle);
/*@zep Gtk\GtkDropDown getListFactory(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_list_factory(zval *handle);
/*@zep Gtk\GtkDropDown getModel(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_model(zval *handle);
/*@zep Gtk\GtkDropDown getSearchMatchMode(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_search_match_mode(zval *handle);
/*@zep Gtk\GtkDropDown getSelected(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_selected(zval *handle);
/*@zep Gtk\GtkDropDown getSelectedItem(int handle) -> int */
zend_long phpgtk_gtkdropdown_get_selected_item(zval *handle);
/*@zep Gtk\GtkDropDown getShowArrow(int handle) -> bool */
zend_long phpgtk_gtkdropdown_get_show_arrow(zval *handle);
/*@zep Gtk\GtkDropDown setEnableSearch(int handle, bool enableSearch) -> void */
void phpgtk_gtkdropdown_set_enable_search(zval *handle, zval *enableSearch);
/*@reserved Gtk\GtkDropDown gtk_drop_down_set_expression(GtkExpression* expression) — GtkExpression* */
/*@zep Gtk\GtkDropDown setFactory(int handle, int factory) -> void */
void phpgtk_gtkdropdown_set_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkDropDown setHeaderFactory(int handle, int factory) -> void */
void phpgtk_gtkdropdown_set_header_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkDropDown setListFactory(int handle, int factory) -> void */
void phpgtk_gtkdropdown_set_list_factory(zval *handle, zval *factory);
/*@zep Gtk\GtkDropDown setModel(int handle, int model) -> void */
void phpgtk_gtkdropdown_set_model(zval *handle, zval *model);
/*@zep Gtk\GtkDropDown setSearchMatchMode(int handle, int searchMatchMode) -> void */
void phpgtk_gtkdropdown_set_search_match_mode(zval *handle, zval *searchMatchMode);
/*@zep Gtk\GtkDropDown setSelected(int handle, int position) -> void */
void phpgtk_gtkdropdown_set_selected(zval *handle, zval *position);
/*@zep Gtk\GtkDropDown setShowArrow(int handle, bool showArrow) -> void */
void phpgtk_gtkdropdown_set_show_arrow(zval *handle, zval *showArrow);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_DROP_DOWN_H */
