#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-stack-switcher.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstackswitcher_new(void)
{
    return phpgtk_handle_register(gtk_stack_switcher_new());
}

zend_long phpgtk_gtkstackswitcher_get_stack(zval *handle)
{
    GtkStackSwitcher *self = PHPGTK_ARG_AS(GtkStackSwitcher, GTK_TYPE_STACK_SWITCHER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_switcher_get_stack(self));
}

void phpgtk_gtkstackswitcher_set_stack(zval *handle, zval *stack)
{
    GtkStackSwitcher *self = PHPGTK_ARG_AS(GtkStackSwitcher, GTK_TYPE_STACK_SWITCHER, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_switcher_set_stack(self, phpgtk_arg_object(stack));
}
