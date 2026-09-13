#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-gl-area.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkglarea_new(void)
{
    return phpgtk_handle_register(gtk_gl_area_new());
}

void phpgtk_gtkglarea_attach_buffers(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_attach_buffers(self);
}

zend_long phpgtk_gtkglarea_get_allowed_apis(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_gl_area_get_allowed_apis(self);
}

zend_long phpgtk_gtkglarea_get_api(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_gl_area_get_api(self);
}

zend_long phpgtk_gtkglarea_get_auto_render(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gl_area_get_auto_render(self) ? 1 : 0;
}

zend_long phpgtk_gtkglarea_get_context(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_gl_area_get_context(self));
}

zend_long phpgtk_gtkglarea_get_has_depth_buffer(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gl_area_get_has_depth_buffer(self) ? 1 : 0;
}

zend_long phpgtk_gtkglarea_get_has_stencil_buffer(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_gl_area_get_has_stencil_buffer(self) ? 1 : 0;
}

void phpgtk_gtkglarea_get_required_version(zval *return_value, zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);
    int major = 0;
    int minor = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_gl_area_get_required_version(self, &major, &minor);
    array_init(return_value);
    add_assoc_long(return_value, "major", (zend_long) major);
    add_assoc_long(return_value, "minor", (zend_long) minor);
}

void phpgtk_gtkglarea_make_current(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_make_current(self);
}

void phpgtk_gtkglarea_queue_render(zval *handle)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_queue_render(self);
}

void phpgtk_gtkglarea_set_allowed_apis(zval *handle, zval *apis)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_set_allowed_apis(self, (GdkGLAPI) phpgtk_arg_long(apis));
}

void phpgtk_gtkglarea_set_auto_render(zval *handle, zval *autoRender)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_set_auto_render(self, phpgtk_arg_bool(autoRender));
}

void phpgtk_gtkglarea_set_has_depth_buffer(zval *handle, zval *hasDepthBuffer)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_set_has_depth_buffer(self, phpgtk_arg_bool(hasDepthBuffer));
}

void phpgtk_gtkglarea_set_has_stencil_buffer(zval *handle, zval *hasStencilBuffer)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_set_has_stencil_buffer(self, phpgtk_arg_bool(hasStencilBuffer));
}

void phpgtk_gtkglarea_set_required_version(zval *handle, zval *major, zval *minor)
{
    GtkGLArea *self = PHPGTK_ARG_AS(GtkGLArea, GTK_TYPE_GL_AREA, handle);

    if (self == NULL) {
        return;
    }

    gtk_gl_area_set_required_version(self, (int) phpgtk_arg_long(major), (int) phpgtk_arg_long(minor));
}
