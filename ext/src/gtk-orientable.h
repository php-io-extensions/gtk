#ifndef PHP_GTK_GTK_ORIENTABLE_H
#define PHP_GTK_GTK_ORIENTABLE_H

/*
 * GtkOrientable — interface. Bound as its own class; first implementor in
 * slice zero is GtkBox.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkOrientable getOrientation(int handle) -> int */
zend_long phpgtk_gtkorientable_get_orientation(zval *handle);
/*@zep Gtk\GtkOrientable setOrientation(int handle, int orientation) -> void */
void phpgtk_gtkorientable_set_orientation(zval *handle, zval *orientation);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ORIENTABLE_H */
