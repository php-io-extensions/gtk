#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-switch.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkswitch_new(void)
{
    return phpgtk_handle_register(gtk_switch_new());
}

zend_long phpgtk_gtkswitch_get_active(zval *handle)
{
    GtkSwitch *self = PHPGTK_ARG_AS(GtkSwitch, GTK_TYPE_SWITCH, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_switch_get_active(self) ? 1 : 0;
}

zend_long phpgtk_gtkswitch_get_state(zval *handle)
{
    GtkSwitch *self = PHPGTK_ARG_AS(GtkSwitch, GTK_TYPE_SWITCH, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_switch_get_state(self) ? 1 : 0;
}

void phpgtk_gtkswitch_set_active(zval *handle, zval *isActive)
{
    GtkSwitch *self = PHPGTK_ARG_AS(GtkSwitch, GTK_TYPE_SWITCH, handle);

    if (self == NULL) {
        return;
    }

    gtk_switch_set_active(self, phpgtk_arg_bool(isActive));
}

void phpgtk_gtkswitch_set_state(zval *handle, zval *state)
{
    GtkSwitch *self = PHPGTK_ARG_AS(GtkSwitch, GTK_TYPE_SWITCH, handle);

    if (self == NULL) {
        return;
    }

    gtk_switch_set_state(self, phpgtk_arg_bool(state));
}
