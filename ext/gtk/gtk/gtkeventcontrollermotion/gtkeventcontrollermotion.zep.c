
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
#include "src/gtk-event-controller-motion.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEventControllerMotion_GtkEventControllerMotion)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEventControllerMotion, GtkEventControllerMotion, gtk_gtk, gtkeventcontrollermotion_gtkeventcontrollermotion, gtk_gtk_gtkeventcontrollermotion_gtkeventcontrollermotion_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerMotion_GtkEventControllerMotion, new_)
{

	RETURN_LONG(phpgtk_gtkeventcontrollermotion_new());
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerMotion_GtkEventControllerMotion, containsPointer)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkeventcontrollermotion_contains_pointer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerMotion_GtkEventControllerMotion, isPointer)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkeventcontrollermotion_is_pointer(&_0);
	RETURN_BOOL(r == 1);
}

