#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-stack-sidebar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstacksidebar_new(void)
{
    return phpgtk_handle_register(gtk_stack_sidebar_new());
}

zend_long phpgtk_gtkstacksidebar_get_stack(zval *handle)
{
    GtkStackSidebar *self = PHPGTK_ARG_AS(GtkStackSidebar, GTK_TYPE_STACK_SIDEBAR, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_sidebar_get_stack(self));
}

void phpgtk_gtkstacksidebar_set_stack(zval *handle, zval *stack)
{
    GtkStackSidebar *self = PHPGTK_ARG_AS(GtkStackSidebar, GTK_TYPE_STACK_SIDEBAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_sidebar_set_stack(self, phpgtk_arg_object(stack));
}
