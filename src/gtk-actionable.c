#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-actionable.h"
#include "phpgtk-support.h"

void phpgtk_gtkactionable_get_action_name(zval *return_value, zval *handle)
{
    GtkActionable *self = PHPGTK_ARG_AS(GtkActionable, GTK_TYPE_ACTIONABLE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_actionable_get_action_name(self));
}

void phpgtk_gtkactionable_set_action_name(zval *handle, zval *actionName)
{
    GtkActionable *self = PHPGTK_ARG_AS(GtkActionable, GTK_TYPE_ACTIONABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_actionable_set_action_name(self, phpgtk_arg_string(actionName));
}

void phpgtk_gtkactionable_set_detailed_action_name(zval *handle, zval *detailedActionName)
{
    GtkActionable *self = PHPGTK_ARG_AS(GtkActionable, GTK_TYPE_ACTIONABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_actionable_set_detailed_action_name(self, phpgtk_arg_string(detailedActionName));
}
