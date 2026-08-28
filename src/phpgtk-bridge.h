#ifndef PHP_GTK_PHPGTK_BRIDGE_H
#define PHP_GTK_PHPGTK_BRIDGE_H

/*
 * The only glue in the extension. Everything here exists because PHP cannot
 * be a GObject: it cannot hold a reference, receive a signal, or drive the
 * GLib main loop. Nothing here decides anything about how GTK is used.
 *
 * There is no error side channel (a process-global last-error is a ZTS
 * hazard). Fallible calls return 0/false/null and raise an E_WARNING with
 * the diagnostic; GTK CRITICALs stay on stderr.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ---- init ---- */

/*
 * gtk_init_check() exactly once; later calls return the first result.
 * Bindings never auto-init: constructing a widget before init() is the
 * caller's bug and GTK will say so on stderr.
 */
/*@zep Bridge\Bridge init() -> bool */
zend_long phpgtk_bridge_init(void);

/* ---- handles ---- */

/*
 * The registry (a GHashTable in phpgtk-bridge.c) holds one reference per
 * registered object; registration g_object_ref_sink()s, adopting the
 * floating ref a gtk_*_new() returns and plain-reffing everything else.
 * release() drops the registry's reference. A released or fabricated
 * handle resolves to NULL — never a dangling pointer.
 */
/*@zep Bridge\Bridge retain(int handle) -> bool */
zend_long phpgtk_bridge_retain(zval *handle);
/*@zep Bridge\Bridge release(int handle) -> void */
void phpgtk_bridge_release(zval *handle);
/*@zep Bridge\Bridge isValid(int handle) -> bool */
zend_long phpgtk_bridge_is_valid(zval *handle);
/*@zep Bridge\Bridge typeName(int handle) -> var */
void phpgtk_bridge_type_name(zval *return_value, zval *handle);
/*@zep Bridge\Bridge isA(int handle, string typeName) -> bool */
zend_long phpgtk_bridge_is_a(zval *handle, zval *typeName);
/* 1:1 with g_type_from_name. 0 when the name is unknown or not yet registered. */
/*@zep Bridge\Bridge typeFromName(string typeName) -> int */
zend_long phpgtk_bridge_type_from_name(zval *typeName);

/* ---- main loop ---- */

/*
 * Iterate the default GMainContext without blocking until it is empty;
 * if nothing dispatched and timeoutMs > 0, wait up to that long for the
 * first source, then drain again. Returns the number of iterations that
 * dispatched. PHP drives the loop — never g_application_run() (a remote
 * GApplication instance segfaults on window creation).
 */
/*@zep Bridge\Bridge pump(int timeoutMs) -> int */
zend_long phpgtk_bridge_pump(zval *timeoutMs);

/* ---- signals ---- */

/*
 * Connect a PHP callable to a signal on any registered GObject. The name
 * may carry a detail ("notify::sensitive"). The closure owns a reference
 * to the callable and the object owns the closure, so finalizing the
 * object drops the callable with it. Handler return values are written
 * back into the signal's return GValue (GtkWindow::close-request).
 * Returns the handler id, 0 on failure.
 */
/*@zep Bridge\Bridge connect(int handle, string signal, var callback) -> int */
zend_long phpgtk_bridge_connect(zval *handle, zval *signal, zval *callback);
/*@zep Bridge\Bridge disconnect(int handle, int handlerId) -> void */
void phpgtk_bridge_disconnect(zval *handle, zval *handlerId);

/* ---- properties ---- */

/*
 * g_object_get_property / g_object_set_property for properties whose C
 * accessors are not bound (@reserved ... property "x"). Values follow the
 * standard mapping: bool/int/double/string cross as themselves, enums and
 * flags as int, GObjects as registered handles (0 = NULL).
 */
/*@zep Bridge\Bridge getProperty(int handle, string name) -> var */
void phpgtk_bridge_get_property(zval *return_value, zval *handle, zval *name);
/*@zep Bridge\Bridge setProperty(int handle, string name, var value) -> void */
void phpgtk_bridge_set_property(zval *handle, zval *name, zval *value);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_PHPGTK_BRIDGE_H */
