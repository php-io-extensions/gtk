#ifndef PHP_GTK_GTK_FIXED_H
#define PHP_GTK_GTK_FIXED_H

/*
 * GtkFixed — Wave A7. Every gir constructor/method/function is bound
 * or reserved. GskTransform child-transform members stay reserved.
 * get_child_position's out-params are {x, y}.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkFixed new() -> int */
zend_long phpgtk_gtkfixed_new(void);
/*@zep Gtk\GtkFixed getChildPosition(int handle, int widget) -> array */
void phpgtk_gtkfixed_get_child_position(zval *return_value, zval *handle, zval *widget);
/*@reserved Gtk\GtkFixed gtk_fixed_get_child_transform(GtkFixed* self, GtkWidget* widget) — GskTransform* boxed */
/*@zep Gtk\GtkFixed move(int handle, int widget, double x, double y) -> void */
void phpgtk_gtkfixed_move(zval *handle, zval *widget, zval *x, zval *y);
/*@zep Gtk\GtkFixed put(int handle, int widget, double x, double y) -> void */
void phpgtk_gtkfixed_put(zval *handle, zval *widget, zval *x, zval *y);
/*@zep Gtk\GtkFixed remove(int handle, int widget) -> void */
void phpgtk_gtkfixed_remove(zval *handle, zval *widget);
/*@reserved Gtk\GtkFixed gtk_fixed_set_child_transform(GtkFixed* self, GtkWidget* widget, GskTransform* transform) — GskTransform* boxed */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_FIXED_H */
