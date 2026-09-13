#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-column-view.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkcolumnview_new(zval *model)
{
    return phpgtk_handle_register(gtk_column_view_new(phpgtk_arg_object_give(model)));
}

void phpgtk_gtkcolumnview_append_column(zval *handle, zval *column)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_append_column(self, phpgtk_arg_object(column));
}

zend_long phpgtk_gtkcolumnview_get_columns(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_get_columns(self));
}

zend_long phpgtk_gtkcolumnview_get_enable_rubberband(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_get_enable_rubberband(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnview_get_header_factory(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_get_header_factory(self));
}

zend_long phpgtk_gtkcolumnview_get_model(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_get_model(self));
}

zend_long phpgtk_gtkcolumnview_get_reorderable(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_get_reorderable(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnview_get_row_factory(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_column_view_get_row_factory(self));
}

zend_long phpgtk_gtkcolumnview_get_show_column_separators(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_get_show_column_separators(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnview_get_show_row_separators(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_get_show_row_separators(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnview_get_single_click_activate(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_column_view_get_single_click_activate(self) ? 1 : 0;
}

zend_long phpgtk_gtkcolumnview_get_tab_behavior(zval *handle)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_column_view_get_tab_behavior(self);
}

void phpgtk_gtkcolumnview_insert_column(zval *handle, zval *position, zval *column)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_insert_column(self, (guint) phpgtk_arg_long(position), phpgtk_arg_object(column));
}

void phpgtk_gtkcolumnview_remove_column(zval *handle, zval *column)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_remove_column(self, phpgtk_arg_object(column));
}

void phpgtk_gtkcolumnview_set_enable_rubberband(zval *handle, zval *enableRubberband)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_enable_rubberband(self, phpgtk_arg_bool(enableRubberband));
}

void phpgtk_gtkcolumnview_set_header_factory(zval *handle, zval *factory)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_header_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkcolumnview_set_model(zval *handle, zval *model)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_model(self, phpgtk_arg_object(model));
}

void phpgtk_gtkcolumnview_set_reorderable(zval *handle, zval *reorderable)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_reorderable(self, phpgtk_arg_bool(reorderable));
}

void phpgtk_gtkcolumnview_set_row_factory(zval *handle, zval *factory)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_row_factory(self, phpgtk_arg_object(factory));
}

void phpgtk_gtkcolumnview_set_show_column_separators(zval *handle, zval *showColumnSeparators)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_show_column_separators(self, phpgtk_arg_bool(showColumnSeparators));
}

void phpgtk_gtkcolumnview_set_show_row_separators(zval *handle, zval *showRowSeparators)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_show_row_separators(self, phpgtk_arg_bool(showRowSeparators));
}

void phpgtk_gtkcolumnview_set_single_click_activate(zval *handle, zval *singleClickActivate)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_single_click_activate(self, phpgtk_arg_bool(singleClickActivate));
}

void phpgtk_gtkcolumnview_set_tab_behavior(zval *handle, zval *tabBehavior)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_set_tab_behavior(self, (GtkListTabBehavior) phpgtk_arg_long(tabBehavior));
}

void phpgtk_gtkcolumnview_sort_by_column(zval *handle, zval *column, zval *direction)
{
    GtkColumnView *self = PHPGTK_ARG_AS(GtkColumnView, GTK_TYPE_COLUMN_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_column_view_sort_by_column(self, phpgtk_arg_object(column), (GtkSortType) phpgtk_arg_long(direction));
}
