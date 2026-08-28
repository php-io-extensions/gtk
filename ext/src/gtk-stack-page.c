#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-stack-page.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstackpage_get_child(zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_stack_page_get_child(self));
}

void phpgtk_gtkstackpage_get_icon_name(zval *return_value, zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_stack_page_get_icon_name(self));
}

void phpgtk_gtkstackpage_get_name(zval *return_value, zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_stack_page_get_name(self));
}

zend_long phpgtk_gtkstackpage_get_needs_attention(zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_page_get_needs_attention(self) ? 1 : 0;
}

void phpgtk_gtkstackpage_get_title(zval *return_value, zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_stack_page_get_title(self));
}

zend_long phpgtk_gtkstackpage_get_use_underline(zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_page_get_use_underline(self) ? 1 : 0;
}

zend_long phpgtk_gtkstackpage_get_visible(zval *handle)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_stack_page_get_visible(self) ? 1 : 0;
}

void phpgtk_gtkstackpage_set_icon_name(zval *handle, zval *setting)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_icon_name(self, phpgtk_arg_string(setting));
}

void phpgtk_gtkstackpage_set_name(zval *handle, zval *setting)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_name(self, phpgtk_arg_string(setting));
}

void phpgtk_gtkstackpage_set_needs_attention(zval *handle, zval *setting)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_needs_attention(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkstackpage_set_title(zval *handle, zval *setting)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_title(self, phpgtk_arg_string(setting));
}

void phpgtk_gtkstackpage_set_use_underline(zval *handle, zval *setting)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_use_underline(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkstackpage_set_visible(zval *handle, zval *visible)
{
    GtkStackPage *self = PHPGTK_ARG_AS(GtkStackPage, GTK_TYPE_STACK_PAGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_stack_page_set_visible(self, phpgtk_arg_bool(visible));
}
