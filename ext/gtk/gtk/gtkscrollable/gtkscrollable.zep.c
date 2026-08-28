
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
#include "src/gtk-scrollable.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrollable_GtkScrollable)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkScrollable, GtkScrollable, gtk_gtk, gtkscrollable_gtkscrollable, gtk_gtk_gtkscrollable_gtkscrollable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getBorder)
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
	phpgtk_gtkscrollable_get_border(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getHadjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrollable_get_hadjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getHscrollPolicy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrollable_get_hscroll_policy(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getVadjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrollable_get_vadjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getVscrollPolicy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrollable_get_vscroll_policy(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setHadjustment)
{
	zval *handle_param = NULL, *hadjustment_param = NULL, _0, _1;
	zend_long handle, hadjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(hadjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hadjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, hadjustment);
	phpgtk_gtkscrollable_set_hadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setHscrollPolicy)
{
	zval *handle_param = NULL, *policy_param = NULL, _0, _1;
	zend_long handle, policy;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(policy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &policy_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, policy);
	phpgtk_gtkscrollable_set_hscroll_policy(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setVadjustment)
{
	zval *handle_param = NULL, *vadjustment_param = NULL, _0, _1;
	zend_long handle, vadjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(vadjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &vadjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, vadjustment);
	phpgtk_gtkscrollable_set_vadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setVscrollPolicy)
{
	zval *handle_param = NULL, *policy_param = NULL, _0, _1;
	zend_long handle, policy;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(policy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &policy_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, policy);
	phpgtk_gtkscrollable_set_vscroll_policy(&_0, &_1);
}

