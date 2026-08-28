#ifndef PHP_GTK_GTK_APPLICATION_WINDOW_H
#define PHP_GTK_GTK_APPLICATION_WINDOW_H

/*
 * GtkApplicationWindow — Wave B6. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkApplicationWindow new_(int application) -> int */
zend_long phpgtk_gtkapplicationwindow_new(zval *application);
/*@reserved Gtk\GtkApplicationWindow gtk_application_window_get_help_overlay(void) — deprecated */
/*@zep Gtk\GtkApplicationWindow getId(int handle) -> int */
zend_long phpgtk_gtkapplicationwindow_get_id(zval *handle);
/*@zep Gtk\GtkApplicationWindow getShowMenubar(int handle) -> bool */
zend_long phpgtk_gtkapplicationwindow_get_show_menubar(zval *handle);
/*@reserved Gtk\GtkApplicationWindow gtk_application_window_set_help_overlay(GtkShortcutsWindow* help_overlay) — deprecated */
/*@zep Gtk\GtkApplicationWindow setShowMenubar(int handle, bool showMenubar) -> void */
void phpgtk_gtkapplicationwindow_set_show_menubar(zval *handle, zval *showMenubar);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_APPLICATION_WINDOW_H */
