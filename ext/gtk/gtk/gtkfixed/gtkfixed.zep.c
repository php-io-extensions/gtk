
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
#include "src/gtk-fixed.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFixed_GtkFixed)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkFixed, GtkFixed, gtk_gtk, gtkfixed_gtkfixed, gtk_gtk_gtkfixed_gtkfixed_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, new_)
{

	RETURN_LONG(phpgtk_gtkfixed_new());
}

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, getChildPosition)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *widget_param = NULL, result, _0, _1;
	zend_long handle, widget;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &widget_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	phpgtk_gtkfixed_get_child_position(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, move)
{
	double x, y;
	zval *handle_param = NULL, *widget_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2, _3;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &widget_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_DOUBLE(&_2, x);
	ZVAL_DOUBLE(&_3, y);
	phpgtk_gtkfixed_move(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, put)
{
	double x, y;
	zval *handle_param = NULL, *widget_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2, _3;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &widget_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_DOUBLE(&_2, x);
	ZVAL_DOUBLE(&_3, y);
	phpgtk_gtkfixed_put(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, remove)
{
	zval *handle_param = NULL, *widget_param = NULL, _0, _1;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &widget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	phpgtk_gtkfixed_remove(&_0, &_1);
}

