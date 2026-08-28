#ifndef PHP_GTK_GIO_GACTION_H
#define PHP_GTK_GIO_GACTION_H

/*
 * Gio GAction — Wave B2 interface. Bound as its own class. Every gir
 * method/function is bound or reserved. GVariant* / GVariantType* and
 * GError** members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GAction nameIsValid(string actionName) -> bool */
zend_long phpgtk_gaction_name_is_valid(zval *actionName);
/*@reserved Gio\GAction g_action_parse_detailed_name(detailed_name, action_name, target_value) — GError** / GVariant** */
/*@reserved Gio\GAction g_action_print_detailed_name(action_name, GVariant* target_value) — GVariant* */
/*@reserved Gio\GAction g_action_activate(self, GVariant* parameter) — GVariant* */
/*@reserved Gio\GAction g_action_change_state(self, GVariant* value) — GVariant* */
/*@zep Gio\GAction getEnabled(int handle) -> bool */
zend_long phpgtk_gaction_get_enabled(zval *handle);
/*@zep Gio\GAction getName(int handle) -> var */
void phpgtk_gaction_get_name(zval *return_value, zval *handle);
/*@reserved Gio\GAction g_action_get_parameter_type(self) — GVariantType* */
/*@reserved Gio\GAction g_action_get_state(self) — GVariant* */
/*@reserved Gio\GAction g_action_get_state_hint(self) — GVariant* */
/*@reserved Gio\GAction g_action_get_state_type(self) — GVariantType* */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GACTION_H */
