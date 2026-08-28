#ifndef PHP_GTK_GIO_GACTIONMAP_H
#define PHP_GTK_GIO_GACTIONMAP_H

/*
 * Gio GActionMap — Wave B2 interface. Bound as its own class. Every gir
 * method/function is bound or reserved. GActionEntry arrays stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GActionMap addAction(int handle, int action) -> void */
void phpgtk_gactionmap_add_action(zval *handle, zval *action);
/*@reserved Gio\GActionMap g_action_map_add_action_entries(self, GActionEntry* entries, n_entries, user_data) — GActionEntry array */
/*@zep Gio\GActionMap lookupAction(int handle, string actionName) -> int */
zend_long phpgtk_gactionmap_lookup_action(zval *handle, zval *actionName);
/*@zep Gio\GActionMap removeAction(int handle, string actionName) -> void */
void phpgtk_gactionmap_remove_action(zval *handle, zval *actionName);
/*@reserved Gio\GActionMap g_action_map_remove_action_entries(self, GActionEntry* entries, n_entries) — GActionEntry array */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GACTIONMAP_H */
