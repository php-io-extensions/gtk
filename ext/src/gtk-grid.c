#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-grid.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkgrid_new(void)
{
    return phpgtk_handle_register(gtk_grid_new());
}

void phpgtk_gtkgrid_attach(zval *handle, zval *child, zval *column, zval *row, zval *width, zval *height)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_attach(self, phpgtk_arg_object(child), phpgtk_arg_long(column), phpgtk_arg_long(row), phpgtk_arg_long(width), phpgtk_arg_long(height));
}

void phpgtk_gtkgrid_attach_next_to(zval *handle, zval *child, zval *sibling, zval *side, zval *width, zval *height)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_attach_next_to(self, phpgtk_arg_object(child), phpgtk_arg_object(sibling), (GtkPositionType) phpgtk_arg_long(side), phpgtk_arg_long(width), phpgtk_arg_long(height));
}

zend_long phpgtk_gtkgrid_get_baseline_row(zval *handle)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_grid_get_baseline_row(self);
}

zend_long phpgtk_gtkgrid_get_child_at(zval *handle, zval *column, zval *row)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_grid_get_child_at(self, phpgtk_arg_long(column), phpgtk_arg_long(row)));
}

zend_long phpgtk_gtkgrid_get_column_homogeneous(zval *handle)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_grid_get_column_homogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkgrid_get_column_spacing(zval *handle)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_grid_get_column_spacing(self);
}

zend_long phpgtk_gtkgrid_get_row_baseline_position(zval *handle, zval *row)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_grid_get_row_baseline_position(self, phpgtk_arg_long(row));
}

zend_long phpgtk_gtkgrid_get_row_homogeneous(zval *handle)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_grid_get_row_homogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkgrid_get_row_spacing(zval *handle)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_grid_get_row_spacing(self);
}

void phpgtk_gtkgrid_insert_column(zval *handle, zval *position)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_insert_column(self, phpgtk_arg_long(position));
}

void phpgtk_gtkgrid_insert_next_to(zval *handle, zval *sibling, zval *side)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_insert_next_to(self, phpgtk_arg_object(sibling), (GtkPositionType) phpgtk_arg_long(side));
}

void phpgtk_gtkgrid_insert_row(zval *handle, zval *position)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_insert_row(self, phpgtk_arg_long(position));
}

void phpgtk_gtkgrid_query_child(zval *return_value, zval *handle, zval *child)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);
    int column = 0;
    int row = 0;
    int width = 0;
    int height = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_grid_query_child(self, phpgtk_arg_object(child), &column, &row, &width, &height);
    array_init(return_value);
    add_assoc_long(return_value, "column", column);
    add_assoc_long(return_value, "row", row);
    add_assoc_long(return_value, "width", width);
    add_assoc_long(return_value, "height", height);
}

void phpgtk_gtkgrid_remove(zval *handle, zval *child)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtkgrid_remove_column(zval *handle, zval *position)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_remove_column(self, phpgtk_arg_long(position));
}

void phpgtk_gtkgrid_remove_row(zval *handle, zval *position)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_remove_row(self, phpgtk_arg_long(position));
}

void phpgtk_gtkgrid_set_baseline_row(zval *handle, zval *row)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_baseline_row(self, phpgtk_arg_long(row));
}

void phpgtk_gtkgrid_set_column_homogeneous(zval *handle, zval *homogeneous)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_column_homogeneous(self, phpgtk_arg_bool(homogeneous));
}

void phpgtk_gtkgrid_set_column_spacing(zval *handle, zval *spacing)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_column_spacing(self, (guint) phpgtk_arg_long(spacing));
}

void phpgtk_gtkgrid_set_row_baseline_position(zval *handle, zval *row, zval *pos)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_row_baseline_position(self, phpgtk_arg_long(row), (GtkBaselinePosition) phpgtk_arg_long(pos));
}

void phpgtk_gtkgrid_set_row_homogeneous(zval *handle, zval *homogeneous)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_row_homogeneous(self, phpgtk_arg_bool(homogeneous));
}

void phpgtk_gtkgrid_set_row_spacing(zval *handle, zval *spacing)
{
    GtkGrid *self = PHPGTK_ARG_AS(GtkGrid, GTK_TYPE_GRID, handle);

    if (self == NULL) {
        return;
    }

    gtk_grid_set_row_spacing(self, (guint) phpgtk_arg_long(spacing));
}
