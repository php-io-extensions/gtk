
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
#include "src/gtk-column-view-column.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkColumnViewColumn, GtkColumnViewColumn, gtk_gtk, gtkcolumnviewcolumn_gtkcolumnviewcolumn, gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, new_)
{
	zend_long factory;
	zval *title = NULL, title_sub, *factory_param = NULL, _0;

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(title)
		Z_PARAM_LONG(factory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &title, &factory_param);
	ZVAL_LONG(&_0, factory);
	RETURN_LONG(phpgtk_gtkcolumnviewcolumn_new(title, &_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getColumnView)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnviewcolumn_get_column_view(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getExpand)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnviewcolumn_get_expand(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnviewcolumn_get_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFixedWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnviewcolumn_get_fixed_width(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getHeaderMenu)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcolumnviewcolumn_get_header_menu(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getId)
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
	phpgtk_gtkcolumnviewcolumn_get_id(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getResizable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnviewcolumn_get_resizable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getTitle)
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
	phpgtk_gtkcolumnviewcolumn_get_title(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcolumnviewcolumn_get_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setExpand)
{
	zend_bool expand;
	zval *handle_param = NULL, *expand_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &expand_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (expand ? 1 : 0));
	phpgtk_gtkcolumnviewcolumn_set_expand(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFactory)
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
	phpgtk_gtkcolumnviewcolumn_set_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFixedWidth)
{
	zval *handle_param = NULL, *fixedWidth_param = NULL, _0, _1;
	zend_long handle, fixedWidth;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(fixedWidth)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fixedWidth_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, fixedWidth);
	phpgtk_gtkcolumnviewcolumn_set_fixed_width(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setHeaderMenu)
{
	zval *handle_param = NULL, *menu_param = NULL, _0, _1;
	zend_long handle, menu;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(menu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &menu_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, menu);
	phpgtk_gtkcolumnviewcolumn_set_header_menu(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setId)
{
	zval *handle_param = NULL, *id = NULL, id_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &id);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkcolumnviewcolumn_set_id(&_0, id);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setResizable)
{
	zend_bool resizable;
	zval *handle_param = NULL, *resizable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(resizable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &resizable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (resizable ? 1 : 0));
	phpgtk_gtkcolumnviewcolumn_set_resizable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setTitle)
{
	zval *handle_param = NULL, *title = NULL, title_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(title)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &title);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkcolumnviewcolumn_set_title(&_0, title);
}

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setVisible)
{
	zend_bool visible;
	zval *handle_param = NULL, *visible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &visible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (visible ? 1 : 0));
	phpgtk_gtkcolumnviewcolumn_set_visible(&_0, &_1);
}

