#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-frame.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkframe_new(zval *label)
{
    return phpgtk_handle_register(gtk_frame_new(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkframe_get_child(zval *handle)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_frame_get_child(self));
}

void phpgtk_gtkframe_get_label(zval *return_value, zval *handle)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_frame_get_label(self));
}

double phpgtk_gtkframe_get_label_align(zval *handle)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_frame_get_label_align(self);
}

zend_long phpgtk_gtkframe_get_label_widget(zval *handle)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_frame_get_label_widget(self));
}

void phpgtk_gtkframe_set_child(zval *handle, zval *child)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_frame_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkframe_set_label(zval *handle, zval *label)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_frame_set_label(self, phpgtk_arg_string(label));
}

void phpgtk_gtkframe_set_label_align(zval *handle, zval *xalign)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_frame_set_label_align(self, (float) phpgtk_arg_double(xalign));
}

void phpgtk_gtkframe_set_label_widget(zval *handle, zval *labelWidget)
{
    GtkFrame *self = PHPGTK_ARG_AS(GtkFrame, GTK_TYPE_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_frame_set_label_widget(self, phpgtk_arg_object(labelWidget));
}
