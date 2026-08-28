#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gactionmap.h"
#include "phpgtk-support.h"

void phpgtk_gactionmap_add_action(zval *handle, zval *action)
{
    GActionMap *self = PHPGTK_ARG_AS(GActionMap, G_TYPE_ACTION_MAP, handle);

    if (self == NULL) {
        return;
    }

    g_action_map_add_action(self, phpgtk_arg_object(action));
}

zend_long phpgtk_gactionmap_lookup_action(zval *handle, zval *actionName)
{
    GActionMap *self = PHPGTK_ARG_AS(GActionMap, G_TYPE_ACTION_MAP, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(g_action_map_lookup_action(self, phpgtk_arg_string(actionName)));
}

void phpgtk_gactionmap_remove_action(zval *handle, zval *actionName)
{
    GActionMap *self = PHPGTK_ARG_AS(GActionMap, G_TYPE_ACTION_MAP, handle);

    if (self == NULL) {
        return;
    }

    g_action_map_remove_action(self, phpgtk_arg_string(actionName));
}
