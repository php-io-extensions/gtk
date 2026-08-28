#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-aspect-frame.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkaspectframe_new(zval *xalign, zval *yalign, zval *ratio, zval *obeyChild)
{
    return phpgtk_handle_register(gtk_aspect_frame_new(
        (float) phpgtk_arg_double(xalign),
        (float) phpgtk_arg_double(yalign),
        (float) phpgtk_arg_double(ratio),
        phpgtk_arg_bool(obeyChild)
    ));
}

zend_long phpgtk_gtkaspectframe_get_child(zval *handle)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_aspect_frame_get_child(self));
}

zend_long phpgtk_gtkaspectframe_get_obey_child(zval *handle)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_aspect_frame_get_obey_child(self) ? 1 : 0;
}

double phpgtk_gtkaspectframe_get_ratio(zval *handle)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_aspect_frame_get_ratio(self);
}

double phpgtk_gtkaspectframe_get_xalign(zval *handle)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_aspect_frame_get_xalign(self);
}

double phpgtk_gtkaspectframe_get_yalign(zval *handle)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_aspect_frame_get_yalign(self);
}

void phpgtk_gtkaspectframe_set_child(zval *handle, zval *child)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_aspect_frame_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkaspectframe_set_obey_child(zval *handle, zval *obeyChild)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_aspect_frame_set_obey_child(self, phpgtk_arg_bool(obeyChild));
}

void phpgtk_gtkaspectframe_set_ratio(zval *handle, zval *ratio)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_aspect_frame_set_ratio(self, (float) phpgtk_arg_double(ratio));
}

void phpgtk_gtkaspectframe_set_xalign(zval *handle, zval *xalign)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_aspect_frame_set_xalign(self, (float) phpgtk_arg_double(xalign));
}

void phpgtk_gtkaspectframe_set_yalign(zval *handle, zval *yalign)
{
    GtkAspectFrame *self = PHPGTK_ARG_AS(GtkAspectFrame, GTK_TYPE_ASPECT_FRAME, handle);

    if (self == NULL) {
        return;
    }

    gtk_aspect_frame_set_yalign(self, (float) phpgtk_arg_double(yalign));
}
