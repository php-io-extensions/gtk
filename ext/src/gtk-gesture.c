#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-gesture.h"
#include "phpgtk-support.h"

void phpgtk_gtkgesture_get_bounding_box(zval *return_value, zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);
    GdkRectangle rect = { 0, 0, 0, 0 };

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    if (!gtk_gesture_get_bounding_box(self, &rect)) {
        ZVAL_NULL(return_value);
        return;
    }
    phpgtk_ret_rectangle(return_value, &rect);
}

void phpgtk_gtkgesture_get_bounding_box_center(zval *return_value, zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);
    double x = 0.0;
    double y = 0.0;

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    if (!gtk_gesture_get_bounding_box_center(self, &x, &y)) {
        ZVAL_NULL(return_value);
        return;
    }
    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}

zend_long phpgtk_gtkgesture_get_device(zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_gesture_get_device(self));
}

void phpgtk_gtkgesture_get_group(zval *return_value, zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_object_glist(return_value, gtk_gesture_get_group(self), TRUE, FALSE);
}

void phpgtk_gtkgesture_group(zval *handle, zval *gesture)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_gesture_group(self, PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, gesture));
}

zend_long phpgtk_gtkgesture_is_active(zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_is_active(self) ? 1 : 0;
}

zend_long phpgtk_gtkgesture_is_grouped_with(zval *handle, zval *other)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_is_grouped_with(self, PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, other)) ? 1 : 0;
}

zend_long phpgtk_gtkgesture_is_recognized(zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_is_recognized(self) ? 1 : 0;
}

zend_long phpgtk_gtkgesture_set_state(zval *handle, zval *state)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gesture_set_state(self, (GtkEventSequenceState) phpgtk_arg_long(state)) ? 1 : 0;
}

void phpgtk_gtkgesture_ungroup(zval *handle)
{
    GtkGesture *self = PHPGTK_ARG_AS(GtkGesture, GTK_TYPE_GESTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_gesture_ungroup(self);
}
