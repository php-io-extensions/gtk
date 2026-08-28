
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
#include "src/gtk-popover.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPopover_GtkPopover)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkPopover, GtkPopover, gtk_gtk, gtkpopover_gtkpopover, gtk_gtk_gtkpopover_gtkpopover_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, new_)
{

	RETURN_LONG(phpgtk_gtkpopover_new());
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getAutohide)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpopover_get_autohide(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getCascadePopdown)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpopover_get_cascade_popdown(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpopover_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getHasArrow)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpopover_get_has_arrow(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getMnemonicsVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpopover_get_mnemonics_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getOffset)
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
	phpgtk_gtkpopover_get_offset(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getPointingTo)
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
	phpgtk_gtkpopover_get_pointing_to(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getPosition)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpopover_get_position(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, popdown)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkpopover_popdown(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, popup)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkpopover_popup(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, present)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkpopover_present(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setAutohide)
{
	zend_bool autohide;
	zval *handle_param = NULL, *autohide_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(autohide)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &autohide_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (autohide ? 1 : 0));
	phpgtk_gtkpopover_set_autohide(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setCascadePopdown)
{
	zend_bool cascadePopdown;
	zval *handle_param = NULL, *cascadePopdown_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(cascadePopdown)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &cascadePopdown_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (cascadePopdown ? 1 : 0));
	phpgtk_gtkpopover_set_cascade_popdown(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setChild)
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
	phpgtk_gtkpopover_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setDefaultWidget)
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
	phpgtk_gtkpopover_set_default_widget(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setHasArrow)
{
	zend_bool hasArrow;
	zval *handle_param = NULL, *hasArrow_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasArrow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasArrow_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasArrow ? 1 : 0));
	phpgtk_gtkpopover_set_has_arrow(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setMnemonicsVisible)
{
	zend_bool mnemonicsVisible;
	zval *handle_param = NULL, *mnemonicsVisible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(mnemonicsVisible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mnemonicsVisible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (mnemonicsVisible ? 1 : 0));
	phpgtk_gtkpopover_set_mnemonics_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setOffset)
{
	zval *handle_param = NULL, *xOffset_param = NULL, *yOffset_param = NULL, _0, _1, _2;
	zend_long handle, xOffset, yOffset;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(xOffset)
		Z_PARAM_LONG(yOffset)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &xOffset_param, &yOffset_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, xOffset);
	ZVAL_LONG(&_2, yOffset);
	phpgtk_gtkpopover_set_offset(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setPointingTo)
{
	double x, y, width, height;
	zval *handle_param = NULL, *x_param = NULL, *y_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2, _3, _4;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_ZVAL(width)
		Z_PARAM_ZVAL(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &handle_param, &x_param, &y_param, &width_param, &height_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	width = zephir_get_doubleval(width_param);
	height = zephir_get_doubleval(height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_DOUBLE(&_3, width);
	ZVAL_DOUBLE(&_4, height);
	phpgtk_gtkpopover_set_pointing_to(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setPosition)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtkpopover_set_position(&_0, &_1);
}

