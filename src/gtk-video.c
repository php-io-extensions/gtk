#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-video.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkvideo_new(void)
{
    return phpgtk_handle_register(gtk_video_new());
}

zend_long phpgtk_gtkvideo_new_for_file(zval *file)
{
    return phpgtk_handle_register(gtk_video_new_for_file(phpgtk_arg_object(file)));
}

zend_long phpgtk_gtkvideo_new_for_filename(zval *filename)
{
    return phpgtk_handle_register(gtk_video_new_for_filename(phpgtk_arg_string(filename)));
}

zend_long phpgtk_gtkvideo_new_for_media_stream(zval *stream)
{
    return phpgtk_handle_register(gtk_video_new_for_media_stream(phpgtk_arg_object(stream)));
}

zend_long phpgtk_gtkvideo_new_for_resource(zval *resourcePath)
{
    return phpgtk_handle_register(gtk_video_new_for_resource(phpgtk_arg_string(resourcePath)));
}

zend_long phpgtk_gtkvideo_get_autoplay(zval *handle)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_video_get_autoplay(self) ? 1 : 0;
}

zend_long phpgtk_gtkvideo_get_file(zval *handle)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_video_get_file(self));
}

zend_long phpgtk_gtkvideo_get_graphics_offload(zval *handle)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_video_get_graphics_offload(self);
}

zend_long phpgtk_gtkvideo_get_loop(zval *handle)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_video_get_loop(self) ? 1 : 0;
}

zend_long phpgtk_gtkvideo_get_media_stream(zval *handle)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_video_get_media_stream(self));
}

void phpgtk_gtkvideo_set_autoplay(zval *handle, zval *autoplay)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_autoplay(self, phpgtk_arg_bool(autoplay));
}

void phpgtk_gtkvideo_set_file(zval *handle, zval *file)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_file(self, phpgtk_arg_object(file));
}

void phpgtk_gtkvideo_set_filename(zval *handle, zval *filename)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_filename(self, phpgtk_arg_string(filename));
}

void phpgtk_gtkvideo_set_graphics_offload(zval *handle, zval *enabled)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_graphics_offload(self, (GtkGraphicsOffloadEnabled) phpgtk_arg_long(enabled));
}

void phpgtk_gtkvideo_set_loop(zval *handle, zval *loop)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_loop(self, phpgtk_arg_bool(loop));
}

void phpgtk_gtkvideo_set_media_stream(zval *handle, zval *stream)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_media_stream(self, phpgtk_arg_object(stream));
}

void phpgtk_gtkvideo_set_resource(zval *handle, zval *resourcePath)
{
    GtkVideo *self = PHPGTK_ARG_AS(GtkVideo, GTK_TYPE_VIDEO, handle);

    if (self == NULL) {
        return;
    }

    gtk_video_set_resource(self, phpgtk_arg_string(resourcePath));
}
