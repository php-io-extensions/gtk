#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-picture.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpicture_new(void)
{
    return phpgtk_handle_register(gtk_picture_new());
}

zend_long phpgtk_gtkpicture_new_for_file(zval *file)
{
    return phpgtk_handle_register(gtk_picture_new_for_file(phpgtk_arg_object(file)));
}

zend_long phpgtk_gtkpicture_new_for_filename(zval *filename)
{
    return phpgtk_handle_register(gtk_picture_new_for_filename(phpgtk_arg_string(filename)));
}

zend_long phpgtk_gtkpicture_new_for_paintable(zval *paintable)
{
    return phpgtk_handle_register(gtk_picture_new_for_paintable(phpgtk_arg_object(paintable)));
}

zend_long phpgtk_gtkpicture_new_for_resource(zval *resourcePath)
{
    return phpgtk_handle_register(gtk_picture_new_for_resource(phpgtk_arg_string(resourcePath)));
}

void phpgtk_gtkpicture_get_alternative_text(zval *return_value, zval *handle)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_picture_get_alternative_text(self));
}

zend_long phpgtk_gtkpicture_get_can_shrink(zval *handle)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_picture_get_can_shrink(self) ? 1 : 0;
}

zend_long phpgtk_gtkpicture_get_content_fit(zval *handle)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_picture_get_content_fit(self);
}

zend_long phpgtk_gtkpicture_get_file(zval *handle)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_picture_get_file(self));
}

zend_long phpgtk_gtkpicture_get_paintable(zval *handle)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_picture_get_paintable(self));
}

void phpgtk_gtkpicture_set_alternative_text(zval *handle, zval *alternativeText)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_alternative_text(self, phpgtk_arg_string(alternativeText));
}

void phpgtk_gtkpicture_set_can_shrink(zval *handle, zval *canShrink)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_can_shrink(self, phpgtk_arg_bool(canShrink));
}

void phpgtk_gtkpicture_set_content_fit(zval *handle, zval *contentFit)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_content_fit(self, (GtkContentFit) phpgtk_arg_long(contentFit));
}

void phpgtk_gtkpicture_set_file(zval *handle, zval *file)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_file(self, phpgtk_arg_object(file));
}

void phpgtk_gtkpicture_set_filename(zval *handle, zval *filename)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_filename(self, phpgtk_arg_string(filename));
}

void phpgtk_gtkpicture_set_paintable(zval *handle, zval *paintable)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_paintable(self, phpgtk_arg_object(paintable));
}

void phpgtk_gtkpicture_set_resource(zval *handle, zval *resourcePath)
{
    GtkPicture *self = PHPGTK_ARG_AS(GtkPicture, GTK_TYPE_PICTURE, handle);

    if (self == NULL) {
        return;
    }

    gtk_picture_set_resource(self, phpgtk_arg_string(resourcePath));
}
