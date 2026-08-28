
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
#include "src/gtk-string-list.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStringList_GtkStringList)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkStringList, GtkStringList, gtk_gtk, gtkstringlist_gtkstringlist, gtk_gtk_gtkstringlist_gtkstringlist_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, new_)
{
	zval *strings = NULL, strings_sub;

	ZVAL_UNDEF(&strings_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(strings)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &strings);
	RETURN_LONG(phpgtk_gtkstringlist_new(strings));
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, append)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval string_;
	zval *handle_param = NULL, *string__param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&string_);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(string_)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &string__param);
	zephir_get_strval(&string_, string__param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkstringlist_append(&_0, &string_);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, find)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval string_;
	zval *handle_param = NULL, *string__param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&string_);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(string_)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &string__param);
	zephir_get_strval(&string_, string__param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_gtkstringlist_find(&_0, &string_));
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, getString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *position_param = NULL, result, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &position_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkstringlist_get_string(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, remove)
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
	phpgtk_gtkstringlist_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, splice)
{
	zval *handle_param = NULL, *position_param = NULL, *nRemovals_param = NULL, *additions = NULL, additions_sub, _0, _1, _2;
	zend_long handle, position, nRemovals;

	ZVAL_UNDEF(&additions_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nRemovals)
		Z_PARAM_ZVAL(additions)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &nRemovals_param, &additions);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nRemovals);
	phpgtk_gtkstringlist_splice(&_0, &_1, &_2, additions);
}

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, take)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval string_;
	zval *handle_param = NULL, *string__param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&string_);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(string_)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &string__param);
	zephir_get_strval(&string_, string__param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkstringlist_take(&_0, &string_);
	ZEPHIR_MM_RESTORE();
}

