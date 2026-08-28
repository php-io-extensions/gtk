
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
#include "src/gtk-drop-down.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkDropDown_GtkDropDown)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkDropDown, GtkDropDown, gtk_gtk, gtkdropdown_gtkdropdown, gtk_gtk_gtkdropdown_gtkdropdown_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, new_)
{
	zval *model_param = NULL, _0;
	zend_long model;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &model_param);
	ZVAL_LONG(&_0, model);
	RETURN_LONG(phpgtk_gtkdropdown_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, newFromStrings)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *strings_param = NULL;
	zval strings;

	ZVAL_UNDEF(&strings);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(strings)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &strings_param);
	zephir_get_arrval(&strings, strings_param);
	RETURN_MM_LONG(phpgtk_gtkdropdown_new_from_strings(&strings));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getEnableSearch)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkdropdown_get_enable_search(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getHeaderFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_header_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getListFactory)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_list_factory(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getModel)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_model(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSearchMatchMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_search_match_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelected)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_selected(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelectedItem)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkdropdown_get_selected_item(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getShowArrow)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkdropdown_get_show_arrow(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setEnableSearch)
{
	zend_bool enableSearch;
	zval *handle_param = NULL, *enableSearch_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enableSearch)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enableSearch_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enableSearch ? 1 : 0));
	phpgtk_gtkdropdown_set_enable_search(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setFactory)
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
	phpgtk_gtkdropdown_set_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setHeaderFactory)
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
	phpgtk_gtkdropdown_set_header_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setListFactory)
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
	phpgtk_gtkdropdown_set_list_factory(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setModel)
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
	phpgtk_gtkdropdown_set_model(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setSearchMatchMode)
{
	zval *handle_param = NULL, *searchMatchMode_param = NULL, _0, _1;
	zend_long handle, searchMatchMode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(searchMatchMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &searchMatchMode_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, searchMatchMode);
	phpgtk_gtkdropdown_set_search_match_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setSelected)
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
	phpgtk_gtkdropdown_set_selected(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setShowArrow)
{
	zend_bool showArrow;
	zval *handle_param = NULL, *showArrow_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showArrow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showArrow_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showArrow ? 1 : 0));
	phpgtk_gtkdropdown_set_show_arrow(&_0, &_1);
}

