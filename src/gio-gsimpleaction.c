#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gsimpleaction.h"
#include "phpgtk-support.h"

zend_long phpgtk_gsimpleaction_new(zval *name)
{
    return phpgtk_handle_register_take(g_simple_action_new(phpgtk_arg_string(name), NULL));
}

void phpgtk_gsimpleaction_set_enabled(zval *handle, zval *enabled)
{
    GSimpleAction *self = PHPGTK_ARG_AS(GSimpleAction, G_TYPE_SIMPLE_ACTION, handle);

    if (self == NULL) {
        return;
    }

    g_simple_action_set_enabled(self, phpgtk_arg_bool(enabled));
}
