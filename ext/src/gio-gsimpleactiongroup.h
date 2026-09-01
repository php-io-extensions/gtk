#ifndef PHP_GTK_GIO_GSIMPLEACTIONGROUP_H
#define PHP_GTK_GIO_GSIMPLEACTIONGROUP_H

/*
 * Gio GSimpleActionGroup — Wave B2. Every gir constructor/method/function
 * is bound or reserved. The group's own insert/remove/lookup/add_entries
 * are deprecated in Gio; the supported surface is GActionMap, which this
 * extension already binds generically, so a group handle goes straight
 * through GActionMap::addAction / lookupAction / removeAction.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GSimpleActionGroup new() -> int */
zend_long phpgtk_gsimpleactiongroup_new(void);
/*@reserved Gio\GSimpleActionGroup g_simple_action_group_add_entries(self, entries, n_entries, user_data) — deprecated, use GActionMap */
/*@reserved Gio\GSimpleActionGroup g_simple_action_group_insert(self, action) — deprecated, use GActionMap::addAction */
/*@reserved Gio\GSimpleActionGroup g_simple_action_group_lookup(self, action_name) — deprecated, use GActionMap::lookupAction */
/*@reserved Gio\GSimpleActionGroup g_simple_action_group_remove(self, action_name) — deprecated, use GActionMap::removeAction */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GSIMPLEACTIONGROUP_H */
