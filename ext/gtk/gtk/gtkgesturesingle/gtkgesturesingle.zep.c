
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
#include "src/gtk-gesture-single.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkGestureSingle, GtkGestureSingle, gtk_gtk, gtkgesturesingle_gtkgesturesingle, gtk_gtk_gtkgesturesingle_gtkgesturesingle_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getButton)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkgesturesingle_get_button(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getCurrentButton)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkgesturesingle_get_current_button(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getExclusive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkgesturesingle_get_exclusive(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getTouchOnly)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkgesturesingle_get_touch_only(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setButton)
{
	zval *handle_param = NULL, *button_param = NULL, _0, _1;
	zend_long handle, button;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &button_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, button);
	phpgtk_gtkgesturesingle_set_button(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setExclusive)
{
	zend_bool exclusive;
	zval *handle_param = NULL, *exclusive_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(exclusive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &exclusive_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (exclusive ? 1 : 0));
	phpgtk_gtkgesturesingle_set_exclusive(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setTouchOnly)
{
	zend_bool touchOnly;
	zval *handle_param = NULL, *touchOnly_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(touchOnly)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &touchOnly_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (touchOnly ? 1 : 0));
	phpgtk_gtkgesturesingle_set_touch_only(&_0, &_1);
}

