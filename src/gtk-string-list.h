#ifndef PHP_GTK_GTK_STRING_LIST_H
#define PHP_GTK_GTK_STRING_LIST_H

/*
 * GtkStringList — Wave B1. Every gir constructor/method/function is
 * bound or reserved. Constructor is transfer-full. take() gives the
 * string (g_strdup via phpgtk_arg_string_give).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkStringList property "item-type" — getter lives on GListModel; use Bridge::getProperty */
/*@reserved Gtk\GtkStringList property "n-items" — getter lives on GListModel; use Bridge::getProperty */
/*@reserved Gtk\GtkStringList property "strings" — no C accessor; construct-only; use Bridge::getProperty */

/*@zep Gtk\GtkStringList new(var strings) -> int */
zend_long phpgtk_gtkstringlist_new(zval *strings);
/*@zep Gtk\GtkStringList append(int handle, string string_) -> void */
void phpgtk_gtkstringlist_append(zval *handle, zval *string_);
/*@zep Gtk\GtkStringList find(int handle, string string_) -> int */
zend_long phpgtk_gtkstringlist_find(zval *handle, zval *string_);
/*@zep Gtk\GtkStringList getString(int handle, int position) -> var */
void phpgtk_gtkstringlist_get_string(zval *return_value, zval *handle, zval *position);
/*@zep Gtk\GtkStringList remove(int handle, int position) -> void */
void phpgtk_gtkstringlist_remove(zval *handle, zval *position);
/*@zep Gtk\GtkStringList splice(int handle, int position, int nRemovals, var additions) -> void */
void phpgtk_gtkstringlist_splice(zval *handle, zval *position, zval *nRemovals, zval *additions);
/*@zep Gtk\GtkStringList take(int handle, string string_) -> void */
void phpgtk_gtkstringlist_take(zval *handle, zval *string_);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STRING_LIST_H */
