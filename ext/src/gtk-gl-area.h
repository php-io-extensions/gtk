#ifndef PHP_GTK_GTK_GL_AREA_H
#define PHP_GTK_GTK_GL_AREA_H

/*
 * GtkGLArea — GL wave. Every gir constructor/method/function is bound
 * or reserved. The GError accessors stay reserved (no error side channel
 * below PHP); the use-es pair is deprecated since 4.12 in favour of the
 * allowed-apis pair, which is bound.
 *
 * getRequiredVersion's out-params are {major, minor}.
 *
 * The render / create-context / resize signals are Bridge territory
 * (Bridge::connect). A render handler returns true to stop GTK's default
 * handling — the closure in phpgtk-support.c already writes a PHP return
 * back into the signal's gboolean return GValue.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkGLArea new() -> int */
zend_long phpgtk_gtkglarea_new(void);
/*@zep Gtk\GtkGLArea attachBuffers(int handle) -> void */
void phpgtk_gtkglarea_attach_buffers(zval *handle);
/*@zep Gtk\GtkGLArea getAllowedApis(int handle) -> int */
zend_long phpgtk_gtkglarea_get_allowed_apis(zval *handle);
/*@zep Gtk\GtkGLArea getApi(int handle) -> int */
zend_long phpgtk_gtkglarea_get_api(zval *handle);
/*@zep Gtk\GtkGLArea getAutoRender(int handle) -> bool */
zend_long phpgtk_gtkglarea_get_auto_render(zval *handle);
/*@zep Gtk\GtkGLArea getContext(int handle) -> int */
zend_long phpgtk_gtkglarea_get_context(zval *handle);
/*@reserved Gtk\GtkGLArea gtk_gl_area_get_error(GtkGLArea* self) — GError* return */
/*@zep Gtk\GtkGLArea getHasDepthBuffer(int handle) -> bool */
zend_long phpgtk_gtkglarea_get_has_depth_buffer(zval *handle);
/*@zep Gtk\GtkGLArea getHasStencilBuffer(int handle) -> bool */
zend_long phpgtk_gtkglarea_get_has_stencil_buffer(zval *handle);
/*@zep Gtk\GtkGLArea getRequiredVersion(int handle) -> array */
void phpgtk_gtkglarea_get_required_version(zval *return_value, zval *handle);
/*@reserved Gtk\GtkGLArea gtk_gl_area_get_use_es(GtkGLArea* self) — deprecated 4.12, use getApi */
/*@zep Gtk\GtkGLArea makeCurrent(int handle) -> void */
void phpgtk_gtkglarea_make_current(zval *handle);
/*@zep Gtk\GtkGLArea queueRender(int handle) -> void */
void phpgtk_gtkglarea_queue_render(zval *handle);
/*@zep Gtk\GtkGLArea setAllowedApis(int handle, int apis) -> void */
void phpgtk_gtkglarea_set_allowed_apis(zval *handle, zval *apis);
/*@zep Gtk\GtkGLArea setAutoRender(int handle, bool autoRender) -> void */
void phpgtk_gtkglarea_set_auto_render(zval *handle, zval *autoRender);
/*@reserved Gtk\GtkGLArea gtk_gl_area_set_error(GtkGLArea* self, const GError* error) — GError* parameter */
/*@zep Gtk\GtkGLArea setHasDepthBuffer(int handle, bool hasDepthBuffer) -> void */
void phpgtk_gtkglarea_set_has_depth_buffer(zval *handle, zval *hasDepthBuffer);
/*@zep Gtk\GtkGLArea setHasStencilBuffer(int handle, bool hasStencilBuffer) -> void */
void phpgtk_gtkglarea_set_has_stencil_buffer(zval *handle, zval *hasStencilBuffer);
/*@zep Gtk\GtkGLArea setRequiredVersion(int handle, int major, int minor) -> void */
void phpgtk_gtkglarea_set_required_version(zval *handle, zval *major, zval *minor);
/*@reserved Gtk\GtkGLArea gtk_gl_area_set_use_es(GtkGLArea* self, gboolean use_es) — deprecated 4.12, use setAllowedApis */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_GL_AREA_H */
