#ifndef PHP_GTK_GTK_APPLICATION_H
#define PHP_GTK_GTK_APPLICATION_H

/*
 * GtkApplication — slice zero. GApplication members bind on
 * Gio\GApplication.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkApplication property "register-session" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkApplication property "screensaver-active" — no C accessor; use Bridge::getProperty */

/*@zep Gtk\GtkApplication new(var applicationId, int flags) -> int */
zend_long phpgtk_gtkapplication_new(zval *applicationId, zval *flags);
/*@zep Gtk\GtkApplication addWindow(int handle, int window) -> void */
void phpgtk_gtkapplication_add_window(zval *handle, zval *window);
/*@zep Gtk\GtkApplication getAccelsForAction(int handle, string detailedActionName) -> array */
void phpgtk_gtkapplication_get_accels_for_action(zval *return_value, zval *handle, zval *detailedActionName);
/*@zep Gtk\GtkApplication getActionsForAccel(int handle, string accel) -> array */
void phpgtk_gtkapplication_get_actions_for_accel(zval *return_value, zval *handle, zval *accel);
/*@zep Gtk\GtkApplication getActiveWindow(int handle) -> int */
zend_long phpgtk_gtkapplication_get_active_window(zval *handle);
/*@zep Gtk\GtkApplication getMenuById(int handle, string id) -> int */
zend_long phpgtk_gtkapplication_get_menu_by_id(zval *handle, zval *id);
/*@zep Gtk\GtkApplication getMenubar(int handle) -> int */
zend_long phpgtk_gtkapplication_get_menubar(zval *handle);
/*@zep Gtk\GtkApplication getWindowById(int handle, int id) -> int */
zend_long phpgtk_gtkapplication_get_window_by_id(zval *handle, zval *id);
/*@zep Gtk\GtkApplication getWindows(int handle) -> array */
void phpgtk_gtkapplication_get_windows(zval *return_value, zval *handle);
/*@zep Gtk\GtkApplication inhibit(int handle, int window, int flags, var reason) -> int */
zend_long phpgtk_gtkapplication_inhibit(zval *handle, zval *window, zval *flags, zval *reason);
/*@zep Gtk\GtkApplication listActionDescriptions(int handle) -> array */
void phpgtk_gtkapplication_list_action_descriptions(zval *return_value, zval *handle);
/*@zep Gtk\GtkApplication removeWindow(int handle, int window) -> void */
void phpgtk_gtkapplication_remove_window(zval *handle, zval *window);
/*@zep Gtk\GtkApplication setAccelsForAction(int handle, string detailedActionName, array accels) -> void */
void phpgtk_gtkapplication_set_accels_for_action(zval *handle, zval *detailedActionName, zval *accels);
/*@zep Gtk\GtkApplication setMenubar(int handle, int menubar) -> void */
void phpgtk_gtkapplication_set_menubar(zval *handle, zval *menubar);
/*@zep Gtk\GtkApplication uninhibit(int handle, int cookie) -> void */
void phpgtk_gtkapplication_uninhibit(zval *handle, zval *cookie);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_APPLICATION_H */
