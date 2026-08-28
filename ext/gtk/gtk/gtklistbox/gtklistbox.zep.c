
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
#include "src/gtk-list-box.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkListBox_GtkListBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkListBox, GtkListBox, gtk_gtk, gtklistbox_gtklistbox, gtk_gtk_gtklistbox_gtklistbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, new_)
{

	RETURN_LONG(phpgtk_gtklistbox_new());
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, append)
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
	phpgtk_gtklistbox_append(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, dragHighlightRow)
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
	phpgtk_gtklistbox_drag_highlight_row(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, dragUnhighlightRow)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_drag_unhighlight_row(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getActivateOnSingleClick)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklistbox_get_activate_on_single_click(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getAdjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistbox_get_adjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtIndex)
{
	zval *handle_param = NULL, *index_param = NULL, _0, _1;
	zend_long handle, index;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &index_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, index);
	RETURN_LONG(phpgtk_gtklistbox_get_row_at_index(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtY)
{
	zval *handle_param = NULL, *y_param = NULL, _0, _1;
	zend_long handle, y;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, y);
	RETURN_LONG(phpgtk_gtklistbox_get_row_at_y(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRow)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistbox_get_selected_row(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRows)
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
	phpgtk_gtklistbox_get_selected_rows(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectionMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistbox_get_selection_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getShowSeparators)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklistbox_get_show_separators(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getTabBehavior)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistbox_get_tab_behavior(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, insert)
{
	zval *handle_param = NULL, *child_param = NULL, *position_param = NULL, _0, _1, _2;
	zend_long handle, child, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, position);
	phpgtk_gtklistbox_insert(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateFilter)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_invalidate_filter(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateHeaders)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_invalidate_headers(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateSort)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_invalidate_sort(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, prepend)
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
	phpgtk_gtklistbox_prepend(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, remove)
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
	phpgtk_gtklistbox_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, removeAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_remove_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, selectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_select_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, selectRow)
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
	phpgtk_gtklistbox_select_row(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setActivateOnSingleClick)
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
	phpgtk_gtklistbox_set_activate_on_single_click(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setAdjustment)
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
	phpgtk_gtklistbox_set_adjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setPlaceholder)
{
	zval *handle_param = NULL, *placeholder_param = NULL, _0, _1;
	zend_long handle, placeholder;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(placeholder)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &placeholder_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, placeholder);
	phpgtk_gtklistbox_set_placeholder(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setSelectionMode)
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
	phpgtk_gtklistbox_set_selection_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setShowSeparators)
{
	zend_bool showSeparators;
	zval *handle_param = NULL, *showSeparators_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showSeparators)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showSeparators_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showSeparators ? 1 : 0));
	phpgtk_gtklistbox_set_show_separators(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setTabBehavior)
{
	zval *handle_param = NULL, *behavior_param = NULL, _0, _1;
	zend_long handle, behavior;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(behavior)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &behavior_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, behavior);
	phpgtk_gtklistbox_set_tab_behavior(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, unselectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistbox_unselect_all(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, unselectRow)
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
	phpgtk_gtklistbox_unselect_row(&_0, &_1);
}

