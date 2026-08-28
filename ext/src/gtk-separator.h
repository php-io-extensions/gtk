#ifndef PHP_GTK_GTK_SEPARATOR_H
#define PHP_GTK_GTK_SEPARATOR_H

/*
 * GtkSeparator — Wave A6. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkSeparator new(int orientation) -> int */
zend_long phpgtk_gtkseparator_new(zval *orientation);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SEPARATOR_H */
