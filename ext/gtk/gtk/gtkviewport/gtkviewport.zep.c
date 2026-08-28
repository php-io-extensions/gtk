
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
#include "src/gtk-viewport.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkViewport_GtkViewport)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkViewport, GtkViewport, gtk_gtk, gtkviewport_gtkviewport, gtk_gtk_gtkviewport_gtkviewport_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, new_)
{
	zval *hadjustment_param = NULL, *vadjustment_param = NULL, _0, _1;
	zend_long hadjustment, vadjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(hadjustment)
		Z_PARAM_LONG(vadjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &hadjustment_param, &vadjustment_param);
	ZVAL_LONG(&_0, hadjustment);
	ZVAL_LONG(&_1, vadjustment);
	RETURN_LONG(phpgtk_gtkviewport_new(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkviewport_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, getScrollToFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkviewport_get_scroll_to_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, setChild)
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
	phpgtk_gtkviewport_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, setScrollToFocus)
{
	zend_bool scrollToFocus;
	zval *handle_param = NULL, *scrollToFocus_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(scrollToFocus)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &scrollToFocus_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (scrollToFocus ? 1 : 0));
	phpgtk_gtkviewport_set_scroll_to_focus(&_0, &_1);
}

