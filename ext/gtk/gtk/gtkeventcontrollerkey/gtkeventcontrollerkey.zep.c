
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
#include "src/gtk-event-controller-key.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEventControllerKey, GtkEventControllerKey, gtk_gtk, gtkeventcontrollerkey_gtkeventcontrollerkey, gtk_gtk_gtkeventcontrollerkey_gtkeventcontrollerkey_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey, new_)
{

	RETURN_LONG(phpgtk_gtkeventcontrollerkey_new());
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey, forward)
{
	zval *handle_param = NULL, *widget_param = NULL, _0, _1;
	zend_long handle, widget, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &widget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	r = phpgtk_gtkeventcontrollerkey_forward(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey, getGroup)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeventcontrollerkey_get_group(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey, getImContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeventcontrollerkey_get_im_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEventControllerKey_GtkEventControllerKey, setImContext)
{
	zval *handle_param = NULL, *imContext_param = NULL, _0, _1;
	zend_long handle, imContext;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(imContext)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &imContext_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, imContext);
	phpgtk_gtkeventcontrollerkey_set_im_context(&_0, &_1);
}

