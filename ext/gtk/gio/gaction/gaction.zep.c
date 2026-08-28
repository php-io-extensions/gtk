
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
#include "src/gio-gaction.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GAction_GAction)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GAction, GAction, gtk, gio_gaction_gaction, gtk_gio_gaction_gaction_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GAction_GAction, nameIsValid)
{
	zend_long r = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *actionName_param = NULL;
	zval actionName;

	ZVAL_UNDEF(&actionName);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);
	r = phpgtk_gaction_name_is_valid(&actionName);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GAction_GAction, getEnabled)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gaction_get_enabled(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GAction_GAction, getName)
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
	phpgtk_gaction_get_name(&result, &_0);
	RETURN_CCTOR(&result);
}

