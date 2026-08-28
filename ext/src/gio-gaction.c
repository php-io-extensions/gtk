#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gaction.h"
#include "phpgtk-support.h"

zend_long phpgtk_gaction_name_is_valid(zval *actionName)
{
    return g_action_name_is_valid(phpgtk_arg_string(actionName)) ? 1 : 0;
}

zend_long phpgtk_gaction_get_enabled(zval *handle)
{
    GAction *self = PHPGTK_ARG_AS(GAction, G_TYPE_ACTION, handle);

    if (self == NULL) {
        return 0;
    }

    return g_action_get_enabled(self) ? 1 : 0;
}

void phpgtk_gaction_get_name(zval *return_value, zval *handle)
{
    GAction *self = PHPGTK_ARG_AS(GAction, G_TYPE_ACTION, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, g_action_get_name(self));
}
