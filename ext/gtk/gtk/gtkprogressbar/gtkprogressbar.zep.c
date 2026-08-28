
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
#include "src/gtk-progress-bar.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkProgressBar_GtkProgressBar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkProgressBar, GtkProgressBar, gtk_gtk, gtkprogressbar_gtkprogressbar, gtk_gtk_gtkprogressbar_gtkprogressbar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, new_)
{

	RETURN_LONG(phpgtk_gtkprogressbar_new());
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getEllipsize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkprogressbar_get_ellipsize(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getFraction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkprogressbar_get_fraction(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getInverted)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkprogressbar_get_inverted(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getPulseStep)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkprogressbar_get_pulse_step(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getShowText)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkprogressbar_get_show_text(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getText)
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
	phpgtk_gtkprogressbar_get_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, pulse)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkprogressbar_pulse(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setEllipsize)
{
	zval *handle_param = NULL, *mode_param = NULL, _0, _1;
	zend_long handle, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mode_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mode);
	phpgtk_gtkprogressbar_set_ellipsize(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setFraction)
{
	double fraction;
	zval *handle_param = NULL, *fraction_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(fraction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fraction_param);
	fraction = zephir_get_doubleval(fraction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, fraction);
	phpgtk_gtkprogressbar_set_fraction(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setInverted)
{
	zend_bool inverted;
	zval *handle_param = NULL, *inverted_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(inverted)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &inverted_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (inverted ? 1 : 0));
	phpgtk_gtkprogressbar_set_inverted(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setPulseStep)
{
	double fraction;
	zval *handle_param = NULL, *fraction_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(fraction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fraction_param);
	fraction = zephir_get_doubleval(fraction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, fraction);
	phpgtk_gtkprogressbar_set_pulse_step(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setShowText)
{
	zend_bool showText;
	zval *handle_param = NULL, *showText_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showText)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showText_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showText ? 1 : 0));
	phpgtk_gtkprogressbar_set_show_text(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setText)
{
	zval *handle_param = NULL, *text = NULL, text_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&text_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(text)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &text);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkprogressbar_set_text(&_0, text);
}

