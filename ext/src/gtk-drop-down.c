#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-drop-down.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkdropdown_new(zval *model)
{
    return phpgtk_handle_register(gtk_drop_down_new(phpgtk_arg_object_give(model), NULL));
}

zend_long phpgtk_gtkdropdown_new_from_strings(zval *strings)
{
    char **stringsStrv = phpgtk_zval_to_strv(strings);
    GtkDropDown *created = (GtkDropDown *) gtk_drop_down_new_from_strings((const char * const *) stringsStrv);
    phpgtk_strv_free(stringsStrv);
    return phpgtk_handle_register(created);
}

zend_long phpgtk_gtkdropdown_get_enable_search(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_drop_down_get_enable_search(self) ? 1 : 0;
}

zend_long phpgtk_gtkdropdown_get_factory(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_drop_down_get_factory(self));
}

zend_long phpgtk_gtkdropdown_get_header_factory(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_drop_down_get_header_factory(self));
}

zend_long phpgtk_gtkdropdown_get_list_factory(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_drop_down_get_list_factory(self));
}

zend_long phpgtk_gtkdropdown_get_model(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_drop_down_get_model(self));
}

zend_long phpgtk_gtkdropdown_get_search_match_mode(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_drop_down_get_search_match_mode(self);
}

zend_long phpgtk_gtkdropdown_get_selected(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_drop_down_get_selected(self);
}

zend_long phpgtk_gtkdropdown_get_selected_item(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_drop_down_get_selected_item(self));
}

zend_long phpgtk_gtkdropdown_get_show_arrow(zval *handle)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_drop_down_get_show_arrow(self) ? 1 : 0;
}

void phpgtk_gtkdropdown_set_enable_search(zval *handle, zval *enableSearch)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_enable_search(self, phpgtk_arg_bool(enableSearch));
}

void phpgtk_gtkdropdown_set_factory(zval *handle, zval *factory)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkdropdown_set_header_factory(zval *handle, zval *factory)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_header_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkdropdown_set_list_factory(zval *handle, zval *factory)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_list_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkdropdown_set_model(zval *handle, zval *model)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_model(self, phpgtk_arg_object(model));
}

void phpgtk_gtkdropdown_set_search_match_mode(zval *handle, zval *searchMatchMode)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_search_match_mode(self, (GtkStringFilterMatchMode) phpgtk_arg_long(searchMatchMode));
}

void phpgtk_gtkdropdown_set_selected(zval *handle, zval *position)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_selected(self, (guint) phpgtk_arg_long(position));
}

void phpgtk_gtkdropdown_set_show_arrow(zval *handle, zval *showArrow)
{
    GtkDropDown *self = PHPGTK_ARG_AS(GtkDropDown, GTK_TYPE_DROP_DOWN, handle);

    if (self == NULL) {
        return;
    }

    gtk_drop_down_set_show_arrow(self, phpgtk_arg_bool(showArrow));
}
