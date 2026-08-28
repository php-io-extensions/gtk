
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
#include "src/gtk-switch.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSwitch_GtkSwitch)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSwitch, GtkSwitch, gtk_gtk, gtkswitch_gtkswitch, gtk_gtk_gtkswitch_gtkswitch_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, new_)
{

	RETURN_LONG(phpgtk_gtkswitch_new());
}

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, getActive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkswitch_get_active(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, getState)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkswitch_get_state(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, setActive)
{
	zend_bool isActive;
	zval *handle_param = NULL, *isActive_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(isActive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &isActive_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (isActive ? 1 : 0));
	phpgtk_gtkswitch_set_active(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, setState)
{
	zend_bool state;
	zval *handle_param = NULL, *state_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(state)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &state_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (state ? 1 : 0));
	phpgtk_gtkswitch_set_state(&_0, &_1);
}

