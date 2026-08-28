#ifndef PHP_GTK_GTK_ACTIONABLE_H
#define PHP_GTK_GTK_ACTIONABLE_H

/*
 * GtkActionable — Wave B2 interface. Bound as its own class. Every gir
 * method/function is bound or reserved. GVariant* and varargs members
 * stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkActionable property "action-target" — getter is get_action_target_value (GVariant*); use Bridge::getProperty */

/*@zep Gtk\GtkActionable getActionName(int handle) -> var */
void phpgtk_gtkactionable_get_action_name(zval *return_value, zval *handle);
/*@reserved Gtk\GtkActionable gtk_actionable_get_action_target_value(self) — GVariant* */
/*@zep Gtk\GtkActionable setActionName(int handle, var actionName) -> void */
void phpgtk_gtkactionable_set_action_name(zval *handle, zval *actionName);
/*@reserved Gtk\GtkActionable gtk_actionable_set_action_target(self, format_string, ...) — varargs */
/*@reserved Gtk\GtkActionable gtk_actionable_set_action_target_value(self, GVariant* target_value) — GVariant* */
/*@zep Gtk\GtkActionable setDetailedActionName(int handle, string detailedActionName) -> void */
void phpgtk_gtkactionable_set_detailed_action_name(zval *handle, zval *detailedActionName);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ACTIONABLE_H */
