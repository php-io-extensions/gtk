#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gdk-gl-context.h"
#include "phpgtk-support.h"

zend_long phpgtk_gdkglcontext_get_allowed_apis(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gdk_gl_context_get_allowed_apis(self);
}

zend_long phpgtk_gdkglcontext_get_api(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gdk_gl_context_get_api(self);
}

zend_long phpgtk_gdkglcontext_get_debug_enabled(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gdk_gl_context_get_debug_enabled(self) ? 1 : 0;
}

zend_long phpgtk_gdkglcontext_get_display(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gdk_gl_context_get_display(self));
}

zend_long phpgtk_gdkglcontext_get_forward_compatible(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gdk_gl_context_get_forward_compatible(self) ? 1 : 0;
}

void phpgtk_gdkglcontext_get_required_version(zval *return_value, zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);
    int major = 0;
    int minor = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gdk_gl_context_get_required_version(self, &major, &minor);
    array_init(return_value);
    add_assoc_long(return_value, "major", (zend_long) major);
    add_assoc_long(return_value, "minor", (zend_long) minor);
}

zend_long phpgtk_gdkglcontext_get_surface(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gdk_gl_context_get_surface(self));
}

zend_long phpgtk_gdkglcontext_get_use_es(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gdk_gl_context_get_use_es(self) ? 1 : 0;
}

void phpgtk_gdkglcontext_get_version(zval *return_value, zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);
    int major = 0;
    int minor = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gdk_gl_context_get_version(self, &major, &minor);
    array_init(return_value);
    add_assoc_long(return_value, "major", (zend_long) major);
    add_assoc_long(return_value, "minor", (zend_long) minor);
}

zend_long phpgtk_gdkglcontext_is_legacy(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gdk_gl_context_is_legacy(self) ? 1 : 0;
}

zend_long phpgtk_gdkglcontext_is_shared(zval *handle, zval *other)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gdk_gl_context_is_shared(self, phpgtk_arg_object(other)) ? 1 : 0;
}

void phpgtk_gdkglcontext_make_current(zval *handle)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_make_current(self);
}

void phpgtk_gdkglcontext_set_allowed_apis(zval *handle, zval *apis)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_set_allowed_apis(self, (GdkGLAPI) phpgtk_arg_long(apis));
}

void phpgtk_gdkglcontext_set_debug_enabled(zval *handle, zval *enabled)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_set_debug_enabled(self, phpgtk_arg_bool(enabled));
}

void phpgtk_gdkglcontext_set_forward_compatible(zval *handle, zval *compatible)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_set_forward_compatible(self, phpgtk_arg_bool(compatible));
}

void phpgtk_gdkglcontext_set_required_version(zval *handle, zval *major, zval *minor)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_set_required_version(self, (int) phpgtk_arg_long(major), (int) phpgtk_arg_long(minor));
}

void phpgtk_gdkglcontext_set_use_es(zval *handle, zval *useEs)
{
    GdkGLContext *self = PHPGTK_ARG_AS(GdkGLContext, GDK_TYPE_GL_CONTEXT, handle);

    if (self == NULL) {
        return;
    }

    gdk_gl_context_set_use_es(self, (int) phpgtk_arg_long(useEs));
}

void phpgtk_gdkglcontext_clear_current(void)
{
    gdk_gl_context_clear_current();
}

zend_long phpgtk_gdkglcontext_get_current(void)
{
    return phpgtk_handle_register(gdk_gl_context_get_current());
}
