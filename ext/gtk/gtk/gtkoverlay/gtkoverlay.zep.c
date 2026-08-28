
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
#include "src/gtk-overlay.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkOverlay_GtkOverlay)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkOverlay, GtkOverlay, gtk_gtk, gtkoverlay_gtkoverlay, gtk_gtk_gtkoverlay_gtkoverlay_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, new_)
{

	RETURN_LONG(phpgtk_gtkoverlay_new());
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, addOverlay)
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
	phpgtk_gtkoverlay_add_overlay(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkoverlay_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getClipOverlay)
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
	r = phpgtk_gtkoverlay_get_clip_overlay(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getMeasureOverlay)
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
	r = phpgtk_gtkoverlay_get_measure_overlay(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, removeOverlay)
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
	phpgtk_gtkoverlay_remove_overlay(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setChild)
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
	phpgtk_gtkoverlay_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setClipOverlay)
{
	zend_bool clipOverlay;
	zval *handle_param = NULL, *widget_param = NULL, *clipOverlay_param = NULL, _0, _1, _2;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_BOOL(clipOverlay)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &widget_param, &clipOverlay_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_BOOL(&_2, (clipOverlay ? 1 : 0));
	phpgtk_gtkoverlay_set_clip_overlay(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setMeasureOverlay)
{
	zend_bool measure;
	zval *handle_param = NULL, *widget_param = NULL, *measure_param = NULL, _0, _1, _2;
	zend_long handle, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_BOOL(measure)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &widget_param, &measure_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_BOOL(&_2, (measure ? 1 : 0));
	phpgtk_gtkoverlay_set_measure_overlay(&_0, &_1, &_2);
}

