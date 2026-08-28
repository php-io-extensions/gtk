#ifndef PHP_GTK_GTK_SCALE_H
#define PHP_GTK_GTK_SCALE_H

/*
 * GtkScale — Wave A4. Every gir constructor/method/function is bound
 * or reserved. The format-value callback stays reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkScale new(int orientation, int adjustment) -> int */
zend_long phpgtk_gtkscale_new(zval *orientation, zval *adjustment);
/*@zep Gtk\GtkScale newWithRange(int orientation, double min, double max, double step) -> int */
zend_long phpgtk_gtkscale_new_with_range(zval *orientation, zval *min, zval *max, zval *step);
/*@zep Gtk\GtkScale addMark(int handle, double value, int position, var markup) -> void */
void phpgtk_gtkscale_add_mark(zval *handle, zval *value, zval *position, zval *markup);
/*@zep Gtk\GtkScale clearMarks(int handle) -> void */
void phpgtk_gtkscale_clear_marks(zval *handle);
/*@zep Gtk\GtkScale getDigits(int handle) -> int */
zend_long phpgtk_gtkscale_get_digits(zval *handle);
/*@zep Gtk\GtkScale getDrawValue(int handle) -> bool */
zend_long phpgtk_gtkscale_get_draw_value(zval *handle);
/*@zep Gtk\GtkScale getHasOrigin(int handle) -> bool */
zend_long phpgtk_gtkscale_get_has_origin(zval *handle);
/*@zep Gtk\GtkScale getLayout(int handle) -> int */
zend_long phpgtk_gtkscale_get_layout(zval *handle);
/*@zep Gtk\GtkScale getLayoutOffsets(int handle) -> array */
void phpgtk_gtkscale_get_layout_offsets(zval *return_value, zval *handle);
/*@zep Gtk\GtkScale getValuePos(int handle) -> int */
zend_long phpgtk_gtkscale_get_value_pos(zval *handle);
/*@zep Gtk\GtkScale setDigits(int handle, int digits) -> void */
void phpgtk_gtkscale_set_digits(zval *handle, zval *digits);
/*@zep Gtk\GtkScale setDrawValue(int handle, bool drawValue) -> void */
void phpgtk_gtkscale_set_draw_value(zval *handle, zval *drawValue);
/*@reserved Gtk\GtkScale gtk_scale_set_format_value_func(GtkScale* scale, func, user_data, destroy_notify) — non-signal callback */
/*@zep Gtk\GtkScale setHasOrigin(int handle, bool hasOrigin) -> void */
void phpgtk_gtkscale_set_has_origin(zval *handle, zval *hasOrigin);
/*@zep Gtk\GtkScale setValuePos(int handle, int pos) -> void */
void phpgtk_gtkscale_set_value_pos(zval *handle, zval *pos);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SCALE_H */
