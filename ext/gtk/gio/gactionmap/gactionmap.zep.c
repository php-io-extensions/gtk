
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
#include "src/gio-gactionmap.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GActionMap_GActionMap)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GActionMap, GActionMap, gtk, gio_gactionmap_gactionmap, gtk_gio_gactionmap_gactionmap_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, addAction)
{
	zval *handle_param = NULL, *action_param = NULL, _0, _1;
	zend_long handle, action;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(action)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &action_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, action);
	phpgtk_gactionmap_add_action(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, lookupAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval actionName;
	zval *handle_param = NULL, *actionName_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&actionName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_gactionmap_lookup_action(&_0, &actionName));
}

PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, removeAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval actionName;
	zval *handle_param = NULL, *actionName_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&actionName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(actionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &actionName_param);
	zephir_get_strval(&actionName, actionName_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gactionmap_remove_action(&_0, &actionName);
	ZEPHIR_MM_RESTORE();
}

