#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-image.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkimage_new(void)
{
    return phpgtk_handle_register(gtk_image_new());
}

zend_long phpgtk_gtkimage_new_from_file(zval *filename)
{
    return phpgtk_handle_register(gtk_image_new_from_file(phpgtk_arg_string(filename)));
}

zend_long phpgtk_gtkimage_new_from_gicon(zval *icon)
{
    return phpgtk_handle_register(gtk_image_new_from_gicon(phpgtk_arg_object(icon)));
}

zend_long phpgtk_gtkimage_new_from_icon_name(zval *iconName)
{
    return phpgtk_handle_register(gtk_image_new_from_icon_name(phpgtk_arg_string(iconName)));
}

zend_long phpgtk_gtkimage_new_from_paintable(zval *paintable)
{
    return phpgtk_handle_register(gtk_image_new_from_paintable(phpgtk_arg_object(paintable)));
}

zend_long phpgtk_gtkimage_new_from_resource(zval *resourcePath)
{
    return phpgtk_handle_register(gtk_image_new_from_resource(phpgtk_arg_string(resourcePath)));
}

void phpgtk_gtkimage_clear(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_clear(self);
}

zend_long phpgtk_gtkimage_get_gicon(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_image_get_gicon(self));
}

void phpgtk_gtkimage_get_icon_name(zval *return_value, zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_image_get_icon_name(self));
}

zend_long phpgtk_gtkimage_get_icon_size(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_image_get_icon_size(self);
}

zend_long phpgtk_gtkimage_get_paintable(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_image_get_paintable(self));
}

zend_long phpgtk_gtkimage_get_pixel_size(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_image_get_pixel_size(self);
}

zend_long phpgtk_gtkimage_get_storage_type(zval *handle)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_image_get_storage_type(self);
}

void phpgtk_gtkimage_set_from_file(zval *handle, zval *filename)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_from_file(self, phpgtk_arg_string(filename));
}

void phpgtk_gtkimage_set_from_gicon(zval *handle, zval *icon)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_from_gicon(self, phpgtk_arg_object(icon));
}

void phpgtk_gtkimage_set_from_icon_name(zval *handle, zval *iconName)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_from_icon_name(self, phpgtk_arg_string(iconName));
}

void phpgtk_gtkimage_set_from_paintable(zval *handle, zval *paintable)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_from_paintable(self, phpgtk_arg_object(paintable));
}

void phpgtk_gtkimage_set_from_resource(zval *handle, zval *resourcePath)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_from_resource(self, phpgtk_arg_string(resourcePath));
}

void phpgtk_gtkimage_set_icon_size(zval *handle, zval *iconSize)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_icon_size(self, (GtkIconSize) phpgtk_arg_long(iconSize));
}

void phpgtk_gtkimage_set_pixel_size(zval *handle, zval *pixelSize)
{
    GtkImage *self = PHPGTK_ARG_AS(GtkImage, GTK_TYPE_IMAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_image_set_pixel_size(self, (int) phpgtk_arg_long(pixelSize));
}
