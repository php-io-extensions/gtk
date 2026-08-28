#ifndef PHP_GTK_GIO_GSIMPLEACTION_H
#define PHP_GTK_GIO_GSIMPLEACTION_H

/*
 * Gio GSimpleAction — Wave B2. Every gir constructor/method/function is
 * bound or reserved. new() passes NULL for the GVariantType* parameter
 * type (GVariant* / GVariantType* stay reserved). Query surface lives
 * on GAction.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gio\GSimpleAction property "enabled" — getter lives on GAction; setter is setEnabled */
/*@reserved Gio\GSimpleAction property "name" — getter lives on GAction; construct-only */
/*@reserved Gio\GSimpleAction property "parameter-type" — getter lives on GAction; construct-only */
/*@reserved Gio\GSimpleAction property "state" — getter lives on GAction; setter reserved (GVariant*) */
/*@reserved Gio\GSimpleAction property "state-type" — getter lives on GAction */

/*@zep Gio\GSimpleAction new(string name) -> int */
zend_long phpgtk_gsimpleaction_new(zval *name);
/*@reserved Gio\GSimpleAction g_simple_action_new_stateful(name, GVariantType* parameter_type, GVariant* state) — GVariant* */
/*@zep Gio\GSimpleAction setEnabled(int handle, bool enabled) -> void */
void phpgtk_gsimpleaction_set_enabled(zval *handle, zval *enabled);
/*@reserved Gio\GSimpleAction g_simple_action_set_state(self, GVariant* value) — GVariant* */
/*@reserved Gio\GSimpleAction g_simple_action_set_state_hint(self, GVariant* state_hint) — GVariant* */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GSIMPLEACTION_H */
