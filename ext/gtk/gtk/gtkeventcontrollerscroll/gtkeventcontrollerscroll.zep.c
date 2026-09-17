
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
#include "src/gtk-event-controller-scroll.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEventControllerScroll_GtkEventControllerScroll)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEventControllerScroll, GtkEventControllerScroll, gtk_gtk, gtkeventcontrollerscroll_gtkeventcontrollerscroll, gtk_gtk_gtkeventcontrollerscroll_gtkeventcontrollerscroll_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerScroll_GtkEventControllerScroll, new_)
{
	zval *flags_param = NULL, _0;
	zend_long flags;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &flags_param);
	ZVAL_LONG(&_0, flags);
	RETURN_LONG(phpgtk_gtkeventcontrollerscroll_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerScroll_GtkEventControllerScroll, getFlags)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeventcontrollerscroll_get_flags(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerScroll_GtkEventControllerScroll, getUnit)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeventcontrollerscroll_get_unit(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerScroll_GtkEventControllerScroll, setFlags)
{
	zval *handle_param = NULL, *flags_param = NULL, _0, _1;
	zend_long handle, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &flags_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, flags);
	phpgtk_gtkeventcontrollerscroll_set_flags(&_0, &_1);
}

