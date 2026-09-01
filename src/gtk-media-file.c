#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-media-file.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkmediafile_new(void)
{
    return phpgtk_handle_register(gtk_media_file_new());
}

zend_long phpgtk_gtkmediafile_new_for_file(zval *file)
{
    return phpgtk_handle_register(gtk_media_file_new_for_file(phpgtk_arg_object(file)));
}

zend_long phpgtk_gtkmediafile_new_for_filename(zval *filename)
{
    return phpgtk_handle_register(gtk_media_file_new_for_filename(phpgtk_arg_string(filename)));
}

zend_long phpgtk_gtkmediafile_new_for_input_stream(zval *stream)
{
    return phpgtk_handle_register(gtk_media_file_new_for_input_stream(phpgtk_arg_object(stream)));
}

zend_long phpgtk_gtkmediafile_new_for_resource(zval *resourcePath)
{
    return phpgtk_handle_register(gtk_media_file_new_for_resource(phpgtk_arg_string(resourcePath)));
}

void phpgtk_gtkmediafile_clear(zval *handle)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_file_clear(self);
}

zend_long phpgtk_gtkmediafile_get_file(zval *handle)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_media_file_get_file(self));
}

zend_long phpgtk_gtkmediafile_get_input_stream(zval *handle)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_media_file_get_input_stream(self));
}

void phpgtk_gtkmediafile_set_file(zval *handle, zval *file)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_file_set_file(self, phpgtk_arg_object(file));
}

void phpgtk_gtkmediafile_set_filename(zval *handle, zval *filename)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_file_set_filename(self, phpgtk_arg_string(filename));
}

void phpgtk_gtkmediafile_set_input_stream(zval *handle, zval *stream)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_file_set_input_stream(self, phpgtk_arg_object(stream));
}

void phpgtk_gtkmediafile_set_resource(zval *handle, zval *resourcePath)
{
    GtkMediaFile *self = PHPGTK_ARG_AS(GtkMediaFile, GTK_TYPE_MEDIA_FILE, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_file_set_resource(self, phpgtk_arg_string(resourcePath));
}
