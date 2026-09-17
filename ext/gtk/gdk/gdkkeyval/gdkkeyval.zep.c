
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
#include "src/gdk-keyval.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gdk_GdkKeyval_GdkKeyval)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gdk\\GdkKeyval, GdkKeyval, gtk, gdk_gdkkeyval_gdkkeyval, gtk_gdk_gdkkeyval_gdkkeyval_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, convertCase)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *symbol_param = NULL, result, _0;
	zend_long symbol;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(symbol)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &symbol_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, symbol);
	phpgtk_gdkkeyval_convert_case(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, fromName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	RETURN_MM_LONG(phpgtk_gdkkeyval_from_name(&name));
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, isLower)
{
	zval *keyval_param = NULL, _0;
	zend_long keyval, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &keyval_param);
	ZVAL_LONG(&_0, keyval);
	r = phpgtk_gdkkeyval_is_lower(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, isUpper)
{
	zval *keyval_param = NULL, _0;
	zend_long keyval, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &keyval_param);
	ZVAL_LONG(&_0, keyval);
	r = phpgtk_gdkkeyval_is_upper(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, name)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *keyval_param = NULL, result, _0;
	zend_long keyval;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &keyval_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, keyval);
	phpgtk_gdkkeyval_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toLower)
{
	zval *keyval_param = NULL, _0;
	zend_long keyval;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &keyval_param);
	ZVAL_LONG(&_0, keyval);
	RETURN_LONG(phpgtk_gdkkeyval_to_lower(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toUnicode)
{
	zval *keyval_param = NULL, _0;
	zend_long keyval;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &keyval_param);
	ZVAL_LONG(&_0, keyval);
	RETURN_LONG(phpgtk_gdkkeyval_to_unicode(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toUpper)
{
	zval *keyval_param = NULL, _0;
	zend_long keyval;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &keyval_param);
	ZVAL_LONG(&_0, keyval);
	RETURN_LONG(phpgtk_gdkkeyval_to_upper(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, fromUnicode)
{
	zval *wc_param = NULL, _0;
	zend_long wc;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(wc)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &wc_param);
	ZVAL_LONG(&_0, wc);
	RETURN_LONG(phpgtk_gdkkeyval_from_unicode(&_0));
}

