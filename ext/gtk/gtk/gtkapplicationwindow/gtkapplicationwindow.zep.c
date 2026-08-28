
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
#include "src/gtk-application-window.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkApplicationWindow, GtkApplicationWindow, gtk_gtk, gtkapplicationwindow_gtkapplicationwindow, gtk_gtk_gtkapplicationwindow_gtkapplicationwindow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow, new_)
{
	zval *application_param = NULL, _0;
	zend_long application;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(application)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &application_param);
	ZVAL_LONG(&_0, application);
	RETURN_LONG(phpgtk_gtkapplicationwindow_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow, getId)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkapplicationwindow_get_id(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow, getShowMenubar)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkapplicationwindow_get_show_menubar(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow, setShowMenubar)
{
	zend_bool showMenubar;
	zval *handle_param = NULL, *showMenubar_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showMenubar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showMenubar_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showMenubar ? 1 : 0));
	phpgtk_gtkapplicationwindow_set_show_menubar(&_0, &_1);
}

