#ifndef PHP_GTK_GDK_GL_CONTEXT_H
#define PHP_GTK_GDK_GL_CONTEXT_H

/*
 * GdkGLContext — GL wave, and the first Gdk class in this extension.
 * Every gir method/function is bound or reserved. Abstract: GDK mints the
 * backend subclass, so there is no construction path; you obtain one from
 * GtkGLArea::getContext or the static getCurrent.
 *
 * getRequiredVersion and getVersion return their out-params as
 * {major, minor}. setUseEs takes GDK's tri-state int (-1 = decide, 0 = no,
 * 1 = yes), not a bool, which is why it is an int parameter here.
 *
 * getDisplay and getSurface hand back GdkDisplay / GdkSurface handles.
 * Those classes have no bindings yet; handles are untyped ints, so the
 * values are still usable wherever a later wave binds them.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gdk\GdkGLContext getAllowedApis(int handle) -> int */
zend_long phpgtk_gdkglcontext_get_allowed_apis(zval *handle);
/*@zep Gdk\GdkGLContext getApi(int handle) -> int */
zend_long phpgtk_gdkglcontext_get_api(zval *handle);
/*@zep Gdk\GdkGLContext getDebugEnabled(int handle) -> bool */
zend_long phpgtk_gdkglcontext_get_debug_enabled(zval *handle);
/*@zep Gdk\GdkGLContext getDisplay(int handle) -> int */
zend_long phpgtk_gdkglcontext_get_display(zval *handle);
/*@zep Gdk\GdkGLContext getForwardCompatible(int handle) -> bool */
zend_long phpgtk_gdkglcontext_get_forward_compatible(zval *handle);
/*@zep Gdk\GdkGLContext getRequiredVersion(int handle) -> array */
void phpgtk_gdkglcontext_get_required_version(zval *return_value, zval *handle);
/*@reserved Gdk\GdkGLContext gdk_gl_context_get_shared_context(GdkGLContext* self) — deprecated 4.4, always NULL */
/*@zep Gdk\GdkGLContext getSurface(int handle) -> int */
zend_long phpgtk_gdkglcontext_get_surface(zval *handle);
/*@zep Gdk\GdkGLContext getUseEs(int handle) -> bool */
zend_long phpgtk_gdkglcontext_get_use_es(zval *handle);
/*@zep Gdk\GdkGLContext getVersion(int handle) -> array */
void phpgtk_gdkglcontext_get_version(zval *return_value, zval *handle);
/*@zep Gdk\GdkGLContext isLegacy(int handle) -> bool */
zend_long phpgtk_gdkglcontext_is_legacy(zval *handle);
/*@zep Gdk\GdkGLContext isShared(int handle, int other) -> bool */
zend_long phpgtk_gdkglcontext_is_shared(zval *handle, zval *other);
/*@zep Gdk\GdkGLContext makeCurrent(int handle) -> void */
void phpgtk_gdkglcontext_make_current(zval *handle);
/*@reserved Gdk\GdkGLContext gdk_gl_context_realize(GdkGLContext* self, GError** error) — GError** out-parameter */
/*@zep Gdk\GdkGLContext setAllowedApis(int handle, int apis) -> void */
void phpgtk_gdkglcontext_set_allowed_apis(zval *handle, zval *apis);
/*@zep Gdk\GdkGLContext setDebugEnabled(int handle, bool enabled) -> void */
void phpgtk_gdkglcontext_set_debug_enabled(zval *handle, zval *enabled);
/*@zep Gdk\GdkGLContext setForwardCompatible(int handle, bool compatible) -> void */
void phpgtk_gdkglcontext_set_forward_compatible(zval *handle, zval *compatible);
/*@zep Gdk\GdkGLContext setRequiredVersion(int handle, int major, int minor) -> void */
void phpgtk_gdkglcontext_set_required_version(zval *handle, zval *major, zval *minor);
/*@zep Gdk\GdkGLContext setUseEs(int handle, int useEs) -> void */
void phpgtk_gdkglcontext_set_use_es(zval *handle, zval *useEs);
/*@zep Gdk\GdkGLContext clearCurrent() -> void */
void phpgtk_gdkglcontext_clear_current(void);
/*@zep Gdk\GdkGLContext getCurrent() -> int */
zend_long phpgtk_gdkglcontext_get_current(void);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GDK_GL_CONTEXT_H */
