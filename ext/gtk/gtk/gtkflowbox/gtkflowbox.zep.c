
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
#include "src/gtk-flow-box.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFlowBox_GtkFlowBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkFlowBox, GtkFlowBox, gtk_gtk, gtkflowbox_gtkflowbox, gtk_gtk_gtkflowbox_gtkflowbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, new_)
{

	RETURN_LONG(phpgtk_gtkflowbox_new());
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, append)
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
	phpgtk_gtkflowbox_append(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getActivateOnSingleClick)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkflowbox_get_activate_on_single_click(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtIndex)
{
	zval *handle_param = NULL, *idx_param = NULL, _0, _1;
	zend_long handle, idx;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(idx)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &idx_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, idx);
	RETURN_LONG(phpgtk_gtkflowbox_get_child_at_index(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtPos)
{
	zval *handle_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long handle, x, y;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &x_param, &y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	RETURN_LONG(phpgtk_gtkflowbox_get_child_at_pos(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getColumnSpacing)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkflowbox_get_column_spacing(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getHomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkflowbox_get_homogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMaxChildrenPerLine)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkflowbox_get_max_children_per_line(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMinChildrenPerLine)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkflowbox_get_min_children_per_line(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getRowSpacing)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkflowbox_get_row_spacing(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectedChildren)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_get_selected_children(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectionMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkflowbox_get_selection_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, insert)
{
	zval *handle_param = NULL, *widget_param = NULL, *position_param = NULL, _0, _1, _2;
	zend_long handle, widget, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &widget_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_LONG(&_2, position);
	phpgtk_gtkflowbox_insert(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateFilter)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_invalidate_filter(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateSort)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_invalidate_sort(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, prepend)
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
	phpgtk_gtkflowbox_prepend(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, remove)
{
	zval *handle_param = NULL, *widget_param = NULL, _0, _1;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &widget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	phpgtk_gtkflowbox_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, removeAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_remove_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_select_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectChild)
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
	phpgtk_gtkflowbox_select_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setActivateOnSingleClick)
{
	zend_bool single;
	zval *handle_param = NULL, *single_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(single)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &single_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (single ? 1 : 0));
	phpgtk_gtkflowbox_set_activate_on_single_click(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setColumnSpacing)
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
	phpgtk_gtkflowbox_set_column_spacing(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHadjustment)
{
	zval *handle_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long handle, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &adjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, adjustment);
	phpgtk_gtkflowbox_set_hadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHomogeneous)
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
	phpgtk_gtkflowbox_set_homogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMaxChildrenPerLine)
{
	zval *handle_param = NULL, *nChildren_param = NULL, _0, _1;
	zend_long handle, nChildren;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(nChildren)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &nChildren_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nChildren);
	phpgtk_gtkflowbox_set_max_children_per_line(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMinChildrenPerLine)
{
	zval *handle_param = NULL, *nChildren_param = NULL, _0, _1;
	zend_long handle, nChildren;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(nChildren)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &nChildren_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nChildren);
	phpgtk_gtkflowbox_set_min_children_per_line(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setRowSpacing)
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
	phpgtk_gtkflowbox_set_row_spacing(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setSelectionMode)
{
	zval *handle_param = NULL, *mode_param = NULL, _0, _1;
	zend_long handle, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mode_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mode);
	phpgtk_gtkflowbox_set_selection_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setVadjustment)
{
	zval *handle_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long handle, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &adjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, adjustment);
	phpgtk_gtkflowbox_set_vadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkflowbox_unselect_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectChild)
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
	phpgtk_gtkflowbox_unselect_child(&_0, &_1);
}

