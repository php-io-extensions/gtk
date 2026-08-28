
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
#include "src/gtk-revealer.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkRevealer_GtkRevealer)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkRevealer, GtkRevealer, gtk_gtk, gtkrevealer_gtkrevealer, gtk_gtk_gtkrevealer_gtkrevealer_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, new_)
{

	RETURN_LONG(phpgtk_gtkrevealer_new());
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkrevealer_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getChildRevealed)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrevealer_get_child_revealed(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getRevealChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrevealer_get_reveal_child(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionDuration)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkrevealer_get_transition_duration(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionType)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkrevealer_get_transition_type(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setChild)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtkrevealer_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setRevealChild)
{
	zend_bool revealChild;
	zval *handle_param = NULL, *revealChild_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(revealChild)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &revealChild_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (revealChild ? 1 : 0));
	phpgtk_gtkrevealer_set_reveal_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionDuration)
{
	zval *handle_param = NULL, *duration_param = NULL, _0, _1;
	zend_long handle, duration;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(duration)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &duration_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, duration);
	phpgtk_gtkrevealer_set_transition_duration(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionType)
{
	zval *handle_param = NULL, *transition_param = NULL, _0, _1;
	zend_long handle, transition;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(transition)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &transition_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, transition);
	phpgtk_gtkrevealer_set_transition_type(&_0, &_1);
}

