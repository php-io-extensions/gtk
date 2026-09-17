#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-gesture-single.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkgesturesingle_get_button(zval *handle)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_gesture_single_get_button(self);
}

zend_long phpgtk_gtkgesturesingle_get_current_button(zval *handle)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_gesture_single_get_current_button(self);
}

zend_long phpgtk_gtkgesturesingle_get_exclusive(zval *handle)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_single_get_exclusive(self) ? 1 : 0;
}

zend_long phpgtk_gtkgesturesingle_get_touch_only(zval *handle)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_single_get_touch_only(self) ? 1 : 0;
}

void phpgtk_gtkgesturesingle_set_button(zval *handle, zval *button)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_gesture_single_set_button(self, (guint) phpgtk_arg_long(button));
}

void phpgtk_gtkgesturesingle_set_exclusive(zval *handle, zval *exclusive)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_gesture_single_set_exclusive(self, phpgtk_arg_bool(exclusive));
}

void phpgtk_gtkgesturesingle_set_touch_only(zval *handle, zval *touchOnly)
{
    GtkGestureSingle *self = PHPGTK_ARG_AS(GtkGestureSingle, GTK_TYPE_GESTURE_SINGLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_gesture_single_set_touch_only(self, phpgtk_arg_bool(touchOnly));
}
