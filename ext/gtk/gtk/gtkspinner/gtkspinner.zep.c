
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
#include "src/gtk-spinner.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSpinner_GtkSpinner)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSpinner, GtkSpinner, gtk_gtk, gtkspinner_gtkspinner, gtk_gtk_gtkspinner_gtkspinner_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, new_)
{

	RETURN_LONG(phpgtk_gtkspinner_new());
}

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, getSpinning)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkspinner_get_spinning(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, setSpinning)
{
	zend_bool spinning;
	zval *handle_param = NULL, *spinning_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(spinning)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &spinning_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (spinning ? 1 : 0));
	phpgtk_gtkspinner_set_spinning(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, start)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkspinner_start(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, stop)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkspinner_stop(&_0);
}

