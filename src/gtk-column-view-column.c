#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-column-view-column.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkcolumnviewcolumn_new(zval *title, zval *factory)
{
    return phpgtk_handle_register_take(gtk_column_view_column_new(phpgtk_arg_string(title), phpgtk_arg_object_give(factory)));
}

zend_long phpgtk_gtkcolumnviewcolumn_get_column_view(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_column_get_column_view(self));
}

zend_long phpgtk_gtkcolumnviewcolumn_get_expand(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_column_get_expand(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnviewcolumn_get_factory(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_column_get_factory(self));
}

zend_long phpgtk_gtkcolumnviewcolumn_get_fixed_width(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_column_view_column_get_fixed_width(self);
}

zend_long phpgtk_gtkcolumnviewcolumn_get_header_menu(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_column_get_header_menu(self));
}

void phpgtk_gtkcolumnviewcolumn_get_id(zval *return_value, zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_column_view_column_get_id(self));
}

zend_long phpgtk_gtkcolumnviewcolumn_get_resizable(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_column_get_resizable(self) ? 1 : 0;
}

void phpgtk_gtkcolumnviewcolumn_get_title(zval *return_value, zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_column_view_column_get_title(self));
}

zend_long phpgtk_gtkcolumnviewcolumn_get_visible(zval *handle)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_column_get_visible(self) ? 1 : 0;
}

void phpgtk_gtkcolumnviewcolumn_set_expand(zval *handle, zval *expand)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_expand(self, phpgtk_arg_bool(expand));
}

void phpgtk_gtkcolumnviewcolumn_set_factory(zval *handle, zval *factory)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkcolumnviewcolumn_set_fixed_width(zval *handle, zval *fixedWidth)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_fixed_width(self, (int) phpgtk_arg_long(fixedWidth));
}

void phpgtk_gtkcolumnviewcolumn_set_header_menu(zval *handle, zval *menu)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_header_menu(self, phpgtk_arg_object(menu));
}

void phpgtk_gtkcolumnviewcolumn_set_id(zval *handle, zval *id)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_id(self, phpgtk_arg_string(id));
}

void phpgtk_gtkcolumnviewcolumn_set_resizable(zval *handle, zval *resizable)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_resizable(self, phpgtk_arg_bool(resizable));
}

void phpgtk_gtkcolumnviewcolumn_set_title(zval *handle, zval *title)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_title(self, phpgtk_arg_string(title));
}

void phpgtk_gtkcolumnviewcolumn_set_visible(zval *handle, zval *visible)
{
    GtkColumnViewColumn *self = PHPGTK_ARG_AS(GtkColumnViewColumn, GTK_TYPE_COLUMN_VIEW_COLUMN, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_column_set_visible(self, phpgtk_arg_bool(visible));
}
