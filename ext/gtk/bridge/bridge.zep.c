
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/phpgtk-bridge.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Bridge_Bridge)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Bridge, Bridge, gtk, bridge_bridge, gtk_bridge_bridge_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Bridge_Bridge, init)
{
	zend_long r = 0;
	r = phpgtk_bridge_init();
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Bridge_Bridge, retain)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_bridge_retain(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Bridge_Bridge, release)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_bridge_release(&_0);
}

PHP_METHOD(Gtk_Bridge_Bridge, isValid)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_bridge_is_valid(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Bridge_Bridge, typeName)
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
	phpgtk_bridge_type_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Bridge_Bridge, isA)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval typeName;
	zval *handle_param = NULL, *typeName_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&typeName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(typeName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &typeName_param);
	zephir_get_strval(&typeName, typeName_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_bridge_is_a(&_0, &typeName);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Bridge_Bridge, typeFromName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *typeName_param = NULL;
	zval typeName;

	ZVAL_UNDEF(&typeName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(typeName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &typeName_param);
	zephir_get_strval(&typeName, typeName_param);
	RETURN_MM_LONG(phpgtk_bridge_type_from_name(&typeName));
}

PHP_METHOD(Gtk_Bridge_Bridge, pump)
{
	zval *timeoutMs_param = NULL, _0;
	zend_long timeoutMs;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timeoutMs)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &timeoutMs_param);
	ZVAL_LONG(&_0, timeoutMs);
	RETURN_LONG(phpgtk_bridge_pump(&_0));
}

PHP_METHOD(Gtk_Bridge_Bridge, connect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval signal;
	zval *handle_param = NULL, *signal_param = NULL, *callback = NULL, callback_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&signal);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(signal)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &signal_param, &callback);
	zephir_get_strval(&signal, signal_param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_bridge_connect(&_0, &signal, callback));
}

PHP_METHOD(Gtk_Bridge_Bridge, disconnect)
{
	zval *handle_param = NULL, *handlerId_param = NULL, _0, _1;
	zend_long handle, handlerId;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(handlerId)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &handlerId_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, handlerId);
	phpgtk_bridge_disconnect(&_0, &_1);
}

PHP_METHOD(Gtk_Bridge_Bridge, getProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_bridge_get_property(&result, &_0, &name);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Bridge_Bridge, setProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, *value = NULL, value_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &name_param, &value);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_bridge_set_property(&_0, &name, value);
	ZEPHIR_MM_RESTORE();
}

