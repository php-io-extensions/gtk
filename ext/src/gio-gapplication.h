#ifndef PHP_GTK_GIO_GAPPLICATION_H
#define PHP_GTK_GIO_GAPPLICATION_H

/*
 * Gio GApplication — slice zero. PHP drives the loop via Bridge::pump; run()
 * is still bound 1:1.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GApplication new(var applicationId, int flags) -> int */
zend_long phpgtk_gapplication_new(zval *applicationId, zval *flags);
/*@zep Gio\GApplication getDefault() -> int */
zend_long phpgtk_gapplication_get_default(void);
/*@zep Gio\GApplication idIsValid(string applicationId) -> bool */
zend_long phpgtk_gapplication_id_is_valid(zval *applicationId);
/*@zep Gio\GApplication activate(int handle) -> void */
void phpgtk_gapplication_activate(zval *handle);
/*@zep Gio\GApplication addMainOption(int handle, string longName, int shortName, int flags, int arg, string description, var argDescription) -> void */
void phpgtk_gapplication_add_main_option(zval *handle, zval *longName, zval *shortName, zval *flags, zval *arg, zval *description, zval *argDescription);
/*@reserved Gio\GApplication g_application_add_main_option_entries(self, GOptionEntry* entries) — GOptionEntry array */
/*@reserved Gio\GApplication g_application_add_option_group(self, GOptionGroup* group) — GOptionGroup* */
/*@reserved Gio\GApplication g_application_bind_busy_property(self, gpointer object, gchar* property) — gpointer */
/*@zep Gio\GApplication getApplicationId(int handle) -> var */
void phpgtk_gapplication_get_application_id(zval *return_value, zval *handle);
/*@zep Gio\GApplication getDbusConnection(int handle) -> int */
zend_long phpgtk_gapplication_get_dbus_connection(zval *handle);
/*@zep Gio\GApplication getDbusObjectPath(int handle) -> var */
void phpgtk_gapplication_get_dbus_object_path(zval *return_value, zval *handle);
/*@zep Gio\GApplication getFlags(int handle) -> int */
zend_long phpgtk_gapplication_get_flags(zval *handle);
/*@zep Gio\GApplication getInactivityTimeout(int handle) -> int */
zend_long phpgtk_gapplication_get_inactivity_timeout(zval *handle);
/*@zep Gio\GApplication getIsBusy(int handle) -> bool */
zend_long phpgtk_gapplication_get_is_busy(zval *handle);
/*@zep Gio\GApplication getIsRegistered(int handle) -> bool */
zend_long phpgtk_gapplication_get_is_registered(zval *handle);
/*@zep Gio\GApplication getIsRemote(int handle) -> bool */
zend_long phpgtk_gapplication_get_is_remote(zval *handle);
/*@zep Gio\GApplication getResourceBasePath(int handle) -> var */
void phpgtk_gapplication_get_resource_base_path(zval *return_value, zval *handle);
/*@zep Gio\GApplication getVersion(int handle) -> var */
void phpgtk_gapplication_get_version(zval *return_value, zval *handle);
/*@zep Gio\GApplication hold(int handle) -> void */
void phpgtk_gapplication_hold(zval *handle);
/*@zep Gio\GApplication markBusy(int handle) -> void */
void phpgtk_gapplication_mark_busy(zval *handle);
/*@zep Gio\GApplication open(int handle, array files, int nFiles, string hint) -> void */
void phpgtk_gapplication_open(zval *handle, zval *files, zval *nFiles, zval *hint);
/*@zep Gio\GApplication quit(int handle) -> void */
void phpgtk_gapplication_quit(zval *handle);
/*@reserved Gio\GApplication g_application_register(self, GCancellable* cancellable) — GError** */
/*@zep Gio\GApplication release(int handle) -> void */
void phpgtk_gapplication_release(zval *handle);
/*@zep Gio\GApplication run(int handle, int argc, array argv) -> int */
zend_long phpgtk_gapplication_run(zval *handle, zval *argc, zval *argv);
/*@zep Gio\GApplication sendNotification(int handle, var id, int notification) -> void */
void phpgtk_gapplication_send_notification(zval *handle, zval *id, zval *notification);
/*@reserved Gio\GApplication g_application_set_action_group(self, GActionGroup* action_group) — deprecated */
/*@zep Gio\GApplication setApplicationId(int handle, var applicationId) -> void */
void phpgtk_gapplication_set_application_id(zval *handle, zval *applicationId);
/*@zep Gio\GApplication setDefault(int handle) -> void */
void phpgtk_gapplication_set_default(zval *handle);
/*@zep Gio\GApplication setFlags(int handle, int flags) -> void */
void phpgtk_gapplication_set_flags(zval *handle, zval *flags);
/*@zep Gio\GApplication setInactivityTimeout(int handle, int inactivityTimeout) -> void */
void phpgtk_gapplication_set_inactivity_timeout(zval *handle, zval *inactivityTimeout);
/*@zep Gio\GApplication setOptionContextDescription(int handle, var description) -> void */
void phpgtk_gapplication_set_option_context_description(zval *handle, zval *description);
/*@zep Gio\GApplication setOptionContextParameterString(int handle, var parameterString) -> void */
void phpgtk_gapplication_set_option_context_parameter_string(zval *handle, zval *parameterString);
/*@zep Gio\GApplication setOptionContextSummary(int handle, var summary) -> void */
void phpgtk_gapplication_set_option_context_summary(zval *handle, zval *summary);
/*@zep Gio\GApplication setResourceBasePath(int handle, var resourcePath) -> void */
void phpgtk_gapplication_set_resource_base_path(zval *handle, zval *resourcePath);
/*@zep Gio\GApplication setVersion(int handle, string version) -> void */
void phpgtk_gapplication_set_version(zval *handle, zval *version);
/*@reserved Gio\GApplication g_application_unbind_busy_property(self, gpointer object, gchar* property) — gpointer */
/*@zep Gio\GApplication unmarkBusy(int handle) -> void */
void phpgtk_gapplication_unmark_busy(zval *handle);
/*@zep Gio\GApplication withdrawNotification(int handle, string id) -> void */
void phpgtk_gapplication_withdraw_notification(zval *handle, zval *id);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GAPPLICATION_H */
