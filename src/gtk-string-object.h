#ifndef PHP_GTK_GTK_STRING_OBJECT_H
#define PHP_GTK_GTK_STRING_OBJECT_H

/*
 * GtkStringObject — Wave B1. Every gir constructor/method/function is
 * bound or reserved. Constructor is transfer-full.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkStringObject new(string string_) -> int */
zend_long phpgtk_gtkstringobject_new(zval *string_);
/*@zep Gtk\GtkStringObject getString(int handle) -> var */
void phpgtk_gtkstringobject_get_string(zval *return_value, zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STRING_OBJECT_H */
