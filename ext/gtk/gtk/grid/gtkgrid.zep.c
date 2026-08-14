
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);



ZEPHIR_INIT_CLASS(Gtk_GTK_Grid_GtkGrid)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Grid, GtkGrid, gtk, gtk_grid_gtkgrid, gtk_gtk_grid_gtkgrid_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridNew)
{
	zend_long handle = 0;
	
            GtkWidget *grid;

            php_gtk_set_last_error(NULL);
            grid = gtk_grid_new();
            if (grid == NULL) {
                php_gtk_set_last_error("gtk_grid_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) grid;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridAttach)
{
	zval *grid_param = NULL, *child_param = NULL, *column_param = NULL, *row_param = NULL, *width_param = NULL, *height_param = NULL;
	zend_long grid, child, column, row, width, height;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(grid)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(row)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &grid_param, &child_param, &column_param, &row_param, &width_param, &height_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gr != NULL && widget != NULL) {
                gtk_grid_attach(gr, widget, (int) column, (int) row, (int) width, (int) height);
            }
        
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridRemove)
{
	zval *grid_param = NULL, *child_param = NULL;
	zend_long grid, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(grid)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &grid_param, &child_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gr != NULL && widget != NULL) {
                gtk_grid_remove(gr, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowSpacing)
{
	zval *grid_param = NULL, *spacing_param = NULL;
	zend_long grid, spacing;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(grid)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &grid_param, &spacing_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_row_spacing(gr, (guint) spacing);
            }
        
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnSpacing)
{
	zval *grid_param = NULL, *spacing_param = NULL;
	zend_long grid, spacing;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(grid)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &grid_param, &spacing_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_column_spacing(gr, (guint) spacing);
            }
        
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowHomogeneous)
{
	zend_bool homogeneous;
	zval *grid_param = NULL, *homogeneous_param = NULL;
	zend_long grid;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(grid)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &grid_param, &homogeneous_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_row_homogeneous(gr, homogeneous ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnHomogeneous)
{
	zend_bool homogeneous;
	zval *grid_param = NULL, *homogeneous_param = NULL;
	zend_long grid;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(grid)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &grid_param, &homogeneous_param);
	
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_column_homogeneous(gr, homogeneous ? TRUE : FALSE);
            }
        
}

