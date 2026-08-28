#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-revealer.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkrevealer_new(void)
{
    return phpgtk_handle_register(gtk_revealer_new());
}

zend_long phpgtk_gtkrevealer_get_child(zval *handle)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_revealer_get_child(self));
}

zend_long phpgtk_gtkrevealer_get_child_revealed(zval *handle)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_revealer_get_child_revealed(self) ? 1 : 0;
}

zend_long phpgtk_gtkrevealer_get_reveal_child(zval *handle)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_revealer_get_reveal_child(self) ? 1 : 0;
}

zend_long phpgtk_gtkrevealer_get_transition_duration(zval *handle)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_revealer_get_transition_duration(self);
}

zend_long phpgtk_gtkrevealer_get_transition_type(zval *handle)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_revealer_get_transition_type(self);
}

void phpgtk_gtkrevealer_set_child(zval *handle, zval *child)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return;
    }

    gtk_revealer_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkrevealer_set_reveal_child(zval *handle, zval *revealChild)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return;
    }

    gtk_revealer_set_reveal_child(self, phpgtk_arg_bool(revealChild));
}

void phpgtk_gtkrevealer_set_transition_duration(zval *handle, zval *duration)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return;
    }

    gtk_revealer_set_transition_duration(self, (guint) phpgtk_arg_long(duration));
}

void phpgtk_gtkrevealer_set_transition_type(zval *handle, zval *transition)
{
    GtkRevealer *self = PHPGTK_ARG_AS(GtkRevealer, GTK_TYPE_REVEALER, handle);

    if (self == NULL) {
        return;
    }

    gtk_revealer_set_transition_type(self, (GtkRevealerTransitionType) phpgtk_arg_long(transition));
}
