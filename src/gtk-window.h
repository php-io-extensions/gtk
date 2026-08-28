#ifndef PHP_GTK_GTK_WINDOW_H
#define PHP_GTK_GTK_WINDOW_H

/*
 * GtkWindow — slice zero. Every gir constructor/method/function is bound or
 * reserved. GtkWidget members bind on GtkWidget.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkWindow property "default-height" — no dedicated C accessor; use getDefaultSize/setDefaultSize or Bridge::getProperty */
/*@reserved Gtk\GtkWindow property "default-width" — no dedicated C accessor; use getDefaultSize/setDefaultSize or Bridge::getProperty */
/*@reserved Gtk\GtkWindow property "display" — no getter on this class; setter is setDisplay; read via GtkWidget::getDisplay or Bridge::getProperty */
/*@reserved Gtk\GtkWindow property "fullscreened" — no setter; use fullscreen/unfullscreen/isFullscreen or Bridge::getProperty */
/*@reserved Gtk\GtkWindow property "maximized" — no setter; use maximize/unmaximize/isMaximized or Bridge::getProperty */

/*@zep Gtk\GtkWindow new() -> int */
zend_long phpgtk_gtkwindow_new(void);
/*@zep Gtk\GtkWindow getDefaultIconName() -> var */
void phpgtk_gtkwindow_get_default_icon_name(zval *return_value);
/*@zep Gtk\GtkWindow getToplevels() -> int */
zend_long phpgtk_gtkwindow_get_toplevels(void);
/*@zep Gtk\GtkWindow listToplevels() -> array */
void phpgtk_gtkwindow_list_toplevels(zval *return_value);
/*@zep Gtk\GtkWindow setAutoStartupNotification(bool setting) -> void */
void phpgtk_gtkwindow_set_auto_startup_notification(zval *setting);
/*@zep Gtk\GtkWindow setDefaultIconName(string name) -> void */
void phpgtk_gtkwindow_set_default_icon_name(zval *name);
/*@zep Gtk\GtkWindow setInteractiveDebugging(bool enable) -> void */
void phpgtk_gtkwindow_set_interactive_debugging(zval *enable);
/*@zep Gtk\GtkWindow close(int handle) -> void */
void phpgtk_gtkwindow_close(zval *handle);
/*@zep Gtk\GtkWindow destroy(int handle) -> void */
void phpgtk_gtkwindow_destroy(zval *handle);
/*@zep Gtk\GtkWindow fullscreen(int handle) -> void */
void phpgtk_gtkwindow_fullscreen(zval *handle);
/*@zep Gtk\GtkWindow fullscreenOnMonitor(int handle, int monitor) -> void */
void phpgtk_gtkwindow_fullscreen_on_monitor(zval *handle, zval *monitor);
/*@zep Gtk\GtkWindow getApplication(int handle) -> int */
zend_long phpgtk_gtkwindow_get_application(zval *handle);
/*@zep Gtk\GtkWindow getChild(int handle) -> int */
zend_long phpgtk_gtkwindow_get_child(zval *handle);
/*@zep Gtk\GtkWindow getDecorated(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_decorated(zval *handle);
/*@zep Gtk\GtkWindow getDefaultSize(int handle) -> array */
void phpgtk_gtkwindow_get_default_size(zval *return_value, zval *handle);
/*@zep Gtk\GtkWindow getDefaultWidget(int handle) -> int */
zend_long phpgtk_gtkwindow_get_default_widget(zval *handle);
/*@zep Gtk\GtkWindow getDeletable(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_deletable(zval *handle);
/*@zep Gtk\GtkWindow getDestroyWithParent(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_destroy_with_parent(zval *handle);
/*@zep Gtk\GtkWindow getFocus(int handle) -> int */
zend_long phpgtk_gtkwindow_get_focus(zval *handle);
/*@zep Gtk\GtkWindow getFocusVisible(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_focus_visible(zval *handle);
/*@zep Gtk\GtkWindow getGroup(int handle) -> int */
zend_long phpgtk_gtkwindow_get_group(zval *handle);
/*@zep Gtk\GtkWindow getHandleMenubarAccel(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_handle_menubar_accel(zval *handle);
/*@zep Gtk\GtkWindow getHideOnClose(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_hide_on_close(zval *handle);
/*@zep Gtk\GtkWindow getIconName(int handle) -> var */
void phpgtk_gtkwindow_get_icon_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkWindow getMnemonicsVisible(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_mnemonics_visible(zval *handle);
/*@zep Gtk\GtkWindow getModal(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_modal(zval *handle);
/*@zep Gtk\GtkWindow getResizable(int handle) -> bool */
zend_long phpgtk_gtkwindow_get_resizable(zval *handle);
/*@zep Gtk\GtkWindow getTitle(int handle) -> var */
void phpgtk_gtkwindow_get_title(zval *return_value, zval *handle);
/*@zep Gtk\GtkWindow getTitlebar(int handle) -> int */
zend_long phpgtk_gtkwindow_get_titlebar(zval *handle);
/*@zep Gtk\GtkWindow getTransientFor(int handle) -> int */
zend_long phpgtk_gtkwindow_get_transient_for(zval *handle);
/*@zep Gtk\GtkWindow hasGroup(int handle) -> bool */
zend_long phpgtk_gtkwindow_has_group(zval *handle);
/*@zep Gtk\GtkWindow isActive(int handle) -> bool */
zend_long phpgtk_gtkwindow_is_active(zval *handle);
/*@zep Gtk\GtkWindow isFullscreen(int handle) -> bool */
zend_long phpgtk_gtkwindow_is_fullscreen(zval *handle);
/*@zep Gtk\GtkWindow isMaximized(int handle) -> bool */
zend_long phpgtk_gtkwindow_is_maximized(zval *handle);
/*@zep Gtk\GtkWindow isSuspended(int handle) -> bool */
zend_long phpgtk_gtkwindow_is_suspended(zval *handle);
/*@zep Gtk\GtkWindow maximize(int handle) -> void */
void phpgtk_gtkwindow_maximize(zval *handle);
/*@zep Gtk\GtkWindow minimize(int handle) -> void */
void phpgtk_gtkwindow_minimize(zval *handle);
/*@zep Gtk\GtkWindow present(int handle) -> void */
void phpgtk_gtkwindow_present(zval *handle);
/*@reserved Gtk\GtkWindow gtk_window_present_with_time(self, guint32 timestamp) — deprecated */
/*@zep Gtk\GtkWindow setApplication(int handle, int application) -> void */
void phpgtk_gtkwindow_set_application(zval *handle, zval *application);
/*@zep Gtk\GtkWindow setChild(int handle, int child) -> void */
void phpgtk_gtkwindow_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkWindow setDecorated(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_decorated(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setDefaultSize(int handle, int width, int height) -> void */
void phpgtk_gtkwindow_set_default_size(zval *handle, zval *width, zval *height);
/*@zep Gtk\GtkWindow setDefaultWidget(int handle, int defaultWidget) -> void */
void phpgtk_gtkwindow_set_default_widget(zval *handle, zval *defaultWidget);
/*@zep Gtk\GtkWindow setDeletable(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_deletable(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setDestroyWithParent(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_destroy_with_parent(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setDisplay(int handle, int display) -> void */
void phpgtk_gtkwindow_set_display(zval *handle, zval *display);
/*@zep Gtk\GtkWindow setFocus(int handle, int focus) -> void */
void phpgtk_gtkwindow_set_focus(zval *handle, zval *focus);
/*@zep Gtk\GtkWindow setFocusVisible(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_focus_visible(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setHandleMenubarAccel(int handle, bool handleMenubarAccel) -> void */
void phpgtk_gtkwindow_set_handle_menubar_accel(zval *handle, zval *handleMenubarAccel);
/*@zep Gtk\GtkWindow setHideOnClose(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_hide_on_close(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setIconName(int handle, var name) -> void */
void phpgtk_gtkwindow_set_icon_name(zval *handle, zval *name);
/*@zep Gtk\GtkWindow setMnemonicsVisible(int handle, bool setting) -> void */
void phpgtk_gtkwindow_set_mnemonics_visible(zval *handle, zval *setting);
/*@zep Gtk\GtkWindow setModal(int handle, bool modal) -> void */
void phpgtk_gtkwindow_set_modal(zval *handle, zval *modal);
/*@zep Gtk\GtkWindow setResizable(int handle, bool resizable) -> void */
void phpgtk_gtkwindow_set_resizable(zval *handle, zval *resizable);
/*@zep Gtk\GtkWindow setStartupId(int handle, string startupId) -> void */
void phpgtk_gtkwindow_set_startup_id(zval *handle, zval *startupId);
/*@zep Gtk\GtkWindow setTitle(int handle, var title) -> void */
void phpgtk_gtkwindow_set_title(zval *handle, zval *title);
/*@zep Gtk\GtkWindow setTitlebar(int handle, int titlebar) -> void */
void phpgtk_gtkwindow_set_titlebar(zval *handle, zval *titlebar);
/*@zep Gtk\GtkWindow setTransientFor(int handle, int parent) -> void */
void phpgtk_gtkwindow_set_transient_for(zval *handle, zval *parent);
/*@zep Gtk\GtkWindow unfullscreen(int handle) -> void */
void phpgtk_gtkwindow_unfullscreen(zval *handle);
/*@zep Gtk\GtkWindow unmaximize(int handle) -> void */
void phpgtk_gtkwindow_unmaximize(zval *handle);
/*@zep Gtk\GtkWindow unminimize(int handle) -> void */
void phpgtk_gtkwindow_unminimize(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_WINDOW_H */
