#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-header-bar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkheaderbar_new(void)
{
    return phpgtk_handle_register(gtk_header_bar_new());
}

void phpgtk_gtkheaderbar_get_decoration_layout(zval *return_value, zval *handle)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_header_bar_get_decoration_layout(self));
}

zend_long phpgtk_gtkheaderbar_get_show_title_buttons(zval *handle)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_header_bar_get_show_title_buttons(self) ? 1 : 0;
}

zend_long phpgtk_gtkheaderbar_get_title_widget(zval *handle)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_header_bar_get_title_widget(self));
}

zend_long phpgtk_gtkheaderbar_get_use_native_controls(zval *handle)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_header_bar_get_use_native_controls(self) ? 1 : 0;
}

void phpgtk_gtkheaderbar_pack_end(zval *handle, zval *child)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_pack_end(self, phpgtk_arg_object(child));
}

void phpgtk_gtkheaderbar_pack_start(zval *handle, zval *child)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_pack_start(self, phpgtk_arg_object(child));
}

void phpgtk_gtkheaderbar_remove(zval *handle, zval *child)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtkheaderbar_set_decoration_layout(zval *handle, zval *layout)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_set_decoration_layout(self, phpgtk_arg_string(layout));
}

void phpgtk_gtkheaderbar_set_show_title_buttons(zval *handle, zval *setting)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_set_show_title_buttons(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkheaderbar_set_title_widget(zval *handle, zval *titleWidget)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_set_title_widget(self, phpgtk_arg_object(titleWidget));
}

void phpgtk_gtkheaderbar_set_use_native_controls(zval *handle, zval *setting)
{
    GtkHeaderBar *self = PHPGTK_ARG_AS(GtkHeaderBar, GTK_TYPE_HEADER_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_header_bar_set_use_native_controls(self, phpgtk_arg_bool(setting));
}

