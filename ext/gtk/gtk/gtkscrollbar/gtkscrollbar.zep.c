
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
#include "src/gtk-scrollbar.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrollbar_GtkScrollbar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkScrollbar, GtkScrollbar, gtk_gtk, gtkscrollbar_gtkscrollbar, gtk_gtk_gtkscrollbar_gtkscrollbar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, new_)
{
	zval *orientation_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long orientation, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(orientation)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &orientation_param, &adjustment_param);
	ZVAL_LONG(&_0, orientation);
	ZVAL_LONG(&_1, adjustment);
	RETURN_LONG(phpgtk_gtkscrollbar_new(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, getAdjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrollbar_get_adjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, setAdjustment)
{
	zval *handle_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long handle, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &adjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, adjustment);
	phpgtk_gtkscrollbar_set_adjustment(&_0, &_1);
}

