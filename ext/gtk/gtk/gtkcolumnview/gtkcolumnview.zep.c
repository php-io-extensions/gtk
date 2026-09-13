
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
#include "src/gtk-column-view.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkColumnView_GtkColumnView)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkColumnView, GtkColumnView, gtk_gtk, gtkcolumnview_gtkcolumnview, gtk_gtk_gtkcolumnview_gtkcolumnview_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, new_)
{
	zval *model_param = NULL, _0;
	zend_long model;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &model_param);
	ZVAL_LONG(&_0, model);
	RETURN_LONG(phpgtk_gtkcolumnview_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, appendColumn)
{
	zval *handle_param = NULL, *column_param = NULL, _0, _1;
	zend_long handle, column;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(column)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &column_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, column);
	phpgtk_gtkcolumnview_append_column(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getColumns)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnview_get_columns(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getEnableRubberband)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnview_get_enable_rubberband(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getHeaderFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnview_get_header_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getModel)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnview_get_model(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getReorderable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnview_get_reorderable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getRowFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnview_get_row_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowColumnSeparators)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnview_get_show_column_separators(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowRowSeparators)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnview_get_show_row_separators(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getSingleClickActivate)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnview_get_single_click_activate(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getTabBehavior)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnview_get_tab_behavior(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, insertColumn)
{
	zval *handle_param = NULL, *position_param = NULL, *column_param = NULL, _0, _1, _2;
	zend_long handle, position, column;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(column)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &column_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, column);
	phpgtk_gtkcolumnview_insert_column(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, removeColumn)
{
	zval *handle_param = NULL, *column_param = NULL, _0, _1;
	zend_long handle, column;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(column)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &column_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, column);
	phpgtk_gtkcolumnview_remove_column(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setEnableRubberband)
{
	zend_bool enableRubberband;
	zval *handle_param = NULL, *enableRubberband_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enableRubberband)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enableRubberband_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enableRubberband ? 1 : 0));
	phpgtk_gtkcolumnview_set_enable_rubberband(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setHeaderFactory)
{
	zval *handle_param = NULL, *factory_param = NULL, _0, _1;
	zend_long handle, factory;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(factory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &factory_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, factory);
	phpgtk_gtkcolumnview_set_header_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setModel)
{
	zval *handle_param = NULL, *model_param = NULL, _0, _1;
	zend_long handle, model;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &model_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, model);
	phpgtk_gtkcolumnview_set_model(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setReorderable)
{
	zend_bool reorderable;
	zval *handle_param = NULL, *reorderable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(reorderable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &reorderable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (reorderable ? 1 : 0));
	phpgtk_gtkcolumnview_set_reorderable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setRowFactory)
{
	zval *handle_param = NULL, *factory_param = NULL, _0, _1;
	zend_long handle, factory;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(factory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &factory_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, factory);
	phpgtk_gtkcolumnview_set_row_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowColumnSeparators)
{
	zend_bool showColumnSeparators;
	zval *handle_param = NULL, *showColumnSeparators_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showColumnSeparators)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showColumnSeparators_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showColumnSeparators ? 1 : 0));
	phpgtk_gtkcolumnview_set_show_column_separators(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowRowSeparators)
{
	zend_bool showRowSeparators;
	zval *handle_param = NULL, *showRowSeparators_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showRowSeparators)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showRowSeparators_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showRowSeparators ? 1 : 0));
	phpgtk_gtkcolumnview_set_show_row_separators(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setSingleClickActivate)
{
	zend_bool singleClickActivate;
	zval *handle_param = NULL, *singleClickActivate_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(singleClickActivate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &singleClickActivate_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (singleClickActivate ? 1 : 0));
	phpgtk_gtkcolumnview_set_single_click_activate(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setTabBehavior)
{
	zval *handle_param = NULL, *tabBehavior_param = NULL, _0, _1;
	zend_long handle, tabBehavior;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(tabBehavior)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &tabBehavior_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, tabBehavior);
	phpgtk_gtkcolumnview_set_tab_behavior(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, sortByColumn)
{
	zval *handle_param = NULL, *column_param = NULL, *direction_param = NULL, _0, _1, _2;
	zend_long handle, column, direction;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &column_param, &direction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, column);
	ZVAL_LONG(&_2, direction);
	phpgtk_gtkcolumnview_sort_by_column(&_0, &_1, &_2);
}

