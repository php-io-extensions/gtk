
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
#include "src/gtk-actionable.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkActionable_GtkActionable)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkActionable, GtkActionable, gtk_gtk, gtkactionable_gtkactionable, gtk_gtk_gtkactionable_gtkactionable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, getActionName)
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
	phpgtk_gtkactionable_get_action_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, setActionName)
{
	zval *handle_param = NULL, *actionName = NULL, actionName_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&actionName_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(actionName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &actionName);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkactionable_set_action_name(&_0, actionName);
}

PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, setDetailedActionName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval detailedActionName;
	zval *handle_param = NULL, *detailedActionName_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&detailedActionName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(detailedActionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &detailedActionName_param);
	zephir_get_strval(&detailedActionName, detailedActionName_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkactionable_set_detailed_action_name(&_0, &detailedActionName);
	ZEPHIR_MM_RESTORE();
}

