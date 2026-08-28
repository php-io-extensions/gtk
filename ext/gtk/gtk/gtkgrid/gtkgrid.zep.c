
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
#include "src/gtk-grid.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGrid_GtkGrid)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkGrid, GtkGrid, gtk_gtk, gtkgrid_gtkgrid, gtk_gtk_gtkgrid_gtkgrid_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, new_)
{

	RETURN_LONG(phpgtk_gtkgrid_new());
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, attach)
{
	zval *handle_param = NULL, *child_param = NULL, *column_param = NULL, *row_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long handle, child, column, row, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(row)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &handle_param, &child_param, &column_param, &row_param, &width_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, column);
	ZVAL_LONG(&_3, row);
	ZVAL_LONG(&_4, width);
	ZVAL_LONG(&_5, height);
	phpgtk_gtkgrid_attach(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, attachNextTo)
{
	zval *handle_param = NULL, *child_param = NULL, *sibling_param = NULL, *side_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long handle, child, sibling, side, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(sibling)
		Z_PARAM_LONG(side)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &handle_param, &child_param, &sibling_param, &side_param, &width_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, sibling);
	ZVAL_LONG(&_3, side);
	ZVAL_LONG(&_4, width);
	ZVAL_LONG(&_5, height);
	phpgtk_gtkgrid_attach_next_to(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getBaselineRow)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkgrid_get_baseline_row(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getChildAt)
{
	zval *handle_param = NULL, *column_param = NULL, *row_param = NULL, _0, _1, _2;
	zend_long handle, column, row;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &column_param, &row_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, column);
	ZVAL_LONG(&_2, row);
	RETURN_LONG(phpgtk_gtkgrid_get_child_at(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getColumnHomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkgrid_get_column_homogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getColumnSpacing)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkgrid_get_column_spacing(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowBaselinePosition)
{
	zval *handle_param = NULL, *row_param = NULL, _0, _1;
	zend_long handle, row;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &row_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, row);
	RETURN_LONG(phpgtk_gtkgrid_get_row_baseline_position(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowHomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkgrid_get_row_homogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowSpacing)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkgrid_get_row_spacing(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertColumn)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkgrid_insert_column(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertNextTo)
{
	zval *handle_param = NULL, *sibling_param = NULL, *side_param = NULL, _0, _1, _2;
	zend_long handle, sibling, side;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(sibling)
		Z_PARAM_LONG(side)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &sibling_param, &side_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, sibling);
	ZVAL_LONG(&_2, side);
	phpgtk_gtkgrid_insert_next_to(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertRow)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkgrid_insert_row(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, queryChild)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *child_param = NULL, result, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &child_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtkgrid_query_child(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, remove)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtkgrid_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, removeColumn)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkgrid_remove_column(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, removeRow)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkgrid_remove_row(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setBaselineRow)
{
	zval *handle_param = NULL, *row_param = NULL, _0, _1;
	zend_long handle, row;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &row_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, row);
	phpgtk_gtkgrid_set_baseline_row(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setColumnHomogeneous)
{
	zend_bool homogeneous;
	zval *handle_param = NULL, *homogeneous_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &homogeneous_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (homogeneous ? 1 : 0));
	phpgtk_gtkgrid_set_column_homogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setColumnSpacing)
{
	zval *handle_param = NULL, *spacing_param = NULL, _0, _1;
	zend_long handle, spacing;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &spacing_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, spacing);
	phpgtk_gtkgrid_set_column_spacing(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowBaselinePosition)
{
	zval *handle_param = NULL, *row_param = NULL, *pos_param = NULL, _0, _1, _2;
	zend_long handle, row, pos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(row)
		Z_PARAM_LONG(pos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &row_param, &pos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, row);
	ZVAL_LONG(&_2, pos);
	phpgtk_gtkgrid_set_row_baseline_position(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowHomogeneous)
{
	zend_bool homogeneous;
	zval *handle_param = NULL, *homogeneous_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &homogeneous_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (homogeneous ? 1 : 0));
	phpgtk_gtkgrid_set_row_homogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowSpacing)
{
	zval *handle_param = NULL, *spacing_param = NULL, _0, _1;
	zend_long handle, spacing;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &spacing_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, spacing);
	phpgtk_gtkgrid_set_row_spacing(&_0, &_1);
}

