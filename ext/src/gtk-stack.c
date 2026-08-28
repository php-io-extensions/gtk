#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-stack.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstack_new(void)
{
    return phpgtk_handle_register(gtk_stack_new());
}

zend_long phpgtk_gtkstack_add_child(zval *handle, zval *child)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_add_child(self, phpgtk_arg_object(child)));
}

zend_long phpgtk_gtkstack_add_named(zval *handle, zval *child, zval *name)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_add_named(self, phpgtk_arg_object(child), phpgtk_arg_string(name)));
}

zend_long phpgtk_gtkstack_add_titled(zval *handle, zval *child, zval *name, zval *title)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_add_titled(self, phpgtk_arg_object(child), phpgtk_arg_string(name), phpgtk_arg_string(title)));
}

zend_long phpgtk_gtkstack_get_child_by_name(zval *handle, zval *name)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_get_child_by_name(self, phpgtk_arg_string(name)));
}

zend_long phpgtk_gtkstack_get_hhomogeneous(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_get_hhomogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkstack_get_interpolate_size(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_get_interpolate_size(self) ? 1 : 0;
}

zend_long phpgtk_gtkstack_get_page(zval *handle, zval *child)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_get_page(self, phpgtk_arg_object(child)));
}

zend_long phpgtk_gtkstack_get_pages(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_stack_get_pages(self));
}

zend_long phpgtk_gtkstack_get_transition_duration(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_stack_get_transition_duration(self);
}

zend_long phpgtk_gtkstack_get_transition_running(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_get_transition_running(self) ? 1 : 0;
}

zend_long phpgtk_gtkstack_get_transition_type(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_stack_get_transition_type(self);
}

zend_long phpgtk_gtkstack_get_vhomogeneous(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_get_vhomogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkstack_get_visible_child(zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_get_visible_child(self));
}

void phpgtk_gtkstack_get_visible_child_name(zval *return_value, zval *handle)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_stack_get_visible_child_name(self));
}

void phpgtk_gtkstack_remove(zval *handle, zval *child)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtkstack_set_hhomogeneous(zval *handle, zval *hhomogeneous)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_hhomogeneous(self, phpgtk_arg_bool(hhomogeneous));
}

void phpgtk_gtkstack_set_interpolate_size(zval *handle, zval *interpolateSize)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_interpolate_size(self, phpgtk_arg_bool(interpolateSize));
}

void phpgtk_gtkstack_set_transition_duration(zval *handle, zval *duration)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_transition_duration(self, (guint) phpgtk_arg_long(duration));
}

void phpgtk_gtkstack_set_transition_type(zval *handle, zval *transition)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_transition_type(self, (GtkStackTransitionType) phpgtk_arg_long(transition));
}

void phpgtk_gtkstack_set_vhomogeneous(zval *handle, zval *vhomogeneous)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_vhomogeneous(self, phpgtk_arg_bool(vhomogeneous));
}

void phpgtk_gtkstack_set_visible_child(zval *handle, zval *child)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_visible_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkstack_set_visible_child_full(zval *handle, zval *name, zval *transition)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_visible_child_full(self, phpgtk_arg_string(name), (GtkStackTransitionType) phpgtk_arg_long(transition));
}

void phpgtk_gtkstack_set_visible_child_name(zval *handle, zval *name)
{
    GtkStack *self = PHPGTK_ARG_AS(GtkStack, GTK_TYPE_STACK, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_set_visible_child_name(self, phpgtk_arg_string(name));
}
