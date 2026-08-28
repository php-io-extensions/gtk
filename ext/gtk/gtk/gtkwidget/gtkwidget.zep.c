
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
#include "src/gtk-widget.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkWidget_GtkWidget)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkWidget, GtkWidget, gtk_gtk, gtkwidget_gtkwidget, gtk_gtk_gtkwidget_gtkwidget_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getDefaultDirection)
{

	RETURN_LONG(phpgtk_gtkwidget_get_default_direction());
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setDefaultDirection)
{
	zval *dir_param = NULL, _0;
	zend_long dir;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dir)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dir_param);
	ZVAL_LONG(&_0, dir);
	phpgtk_gtkwidget_set_default_direction(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, actionSetEnabled)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool enabled;
	zval actionName;
	zval *handle_param = NULL, *actionName_param = NULL, *enabled_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&actionName);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(actionName)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &actionName_param, &enabled_param);
	zephir_get_strval(&actionName, actionName_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enabled ? 1 : 0));
	phpgtk_gtkwidget_action_set_enabled(&_0, &actionName, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, activate)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_activate(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, activateDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_activate_default(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, addController)
{
	zval *handle_param = NULL, *controller_param = NULL, _0, _1;
	zend_long handle, controller;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(controller)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &controller_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, controller);
	phpgtk_gtkwidget_add_controller(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, addCssClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval cssClass;
	zval *handle_param = NULL, *cssClass_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&cssClass);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(cssClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &cssClass_param);
	zephir_get_strval(&cssClass, cssClass_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_add_css_class(&_0, &cssClass);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, addMnemonicLabel)
{
	zval *handle_param = NULL, *label_param = NULL, _0, _1;
	zend_long handle, label;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &label_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, label);
	phpgtk_gtkwidget_add_mnemonic_label(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, childFocus)
{
	zval *handle_param = NULL, *direction_param = NULL, _0, _1;
	zend_long handle, direction, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &direction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, direction);
	r = phpgtk_gtkwidget_child_focus(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, computeBounds)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *target_param = NULL, result, _0, _1;
	zend_long handle, target;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(target)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &target_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, target);
	phpgtk_gtkwidget_compute_bounds(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, computeExpand)
{
	zval *handle_param = NULL, *orientation_param = NULL, _0, _1;
	zend_long handle, orientation, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &orientation_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, orientation);
	r = phpgtk_gtkwidget_compute_expand(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, computePoint)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	double pointX, pointY;
	zval *handle_param = NULL, *target_param = NULL, *pointX_param = NULL, *pointY_param = NULL, result, _0, _1, _2, _3;
	zend_long handle, target;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(target)
		Z_PARAM_ZVAL(pointX)
		Z_PARAM_ZVAL(pointY)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &target_param, &pointX_param, &pointY_param);
	pointX = zephir_get_doubleval(pointX_param);
	pointY = zephir_get_doubleval(pointY_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, target);
	ZVAL_DOUBLE(&_2, pointX);
	ZVAL_DOUBLE(&_3, pointY);
	phpgtk_gtkwidget_compute_point(&result, &_0, &_1, &_2, &_3);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, contains)
{
	double x, y;
	zval *handle_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &x_param, &y_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	r = phpgtk_gtkwidget_contains(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, createPangoContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_create_pango_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, createPangoLayout)
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
	RETURN_LONG(phpgtk_gtkwidget_create_pango_layout(&_0, text));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, disposeTemplate)
{
	zval *handle_param = NULL, *widgetType_param = NULL, _0, _1;
	zend_long handle, widgetType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widgetType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &widgetType_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widgetType);
	phpgtk_gtkwidget_dispose_template(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, dragCheckThreshold)
{
	zval *handle_param = NULL, *startX_param = NULL, *startY_param = NULL, *currentX_param = NULL, *currentY_param = NULL, _0, _1, _2, _3, _4;
	zend_long handle, startX, startY, currentX, currentY, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(startX)
		Z_PARAM_LONG(startY)
		Z_PARAM_LONG(currentX)
		Z_PARAM_LONG(currentY)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &handle_param, &startX_param, &startY_param, &currentX_param, &currentY_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, startX);
	ZVAL_LONG(&_2, startY);
	ZVAL_LONG(&_3, currentX);
	ZVAL_LONG(&_4, currentY);
	r = phpgtk_gtkwidget_drag_check_threshold(&_0, &_1, &_2, &_3, &_4);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, errorBell)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_error_bell(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getAncestor)
{
	zval *handle_param = NULL, *widgetType_param = NULL, _0, _1;
	zend_long handle, widgetType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widgetType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &widgetType_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widgetType);
	RETURN_LONG(phpgtk_gtkwidget_get_ancestor(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getBaseline)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_baseline(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getCanFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_can_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getCanTarget)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_can_target(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getChildVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_child_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getClipboard)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_clipboard(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getColor)
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
	phpgtk_gtkwidget_get_color(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getCssClasses)
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
	phpgtk_gtkwidget_get_css_classes(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getCssName)
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
	phpgtk_gtkwidget_get_css_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getCursor)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_cursor(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getDirection)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_direction(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getDisplay)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_display(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFirstChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_first_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFocusChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_focus_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFocusOnClick)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_focus_on_click(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFocusable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_focusable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFontMap)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_font_map(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getFrameClock)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_frame_clock(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getHalign)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_halign(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getHasTooltip)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_has_tooltip(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getHeight)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_height(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getHexpand)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_hexpand(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getHexpandSet)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_hexpand_set(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getLastChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_last_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getLayoutManager)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_layout_manager(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getLimitEvents)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_limit_events(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getMapped)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_mapped(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getMarginBottom)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_margin_bottom(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getMarginEnd)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_margin_end(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getMarginStart)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_margin_start(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getMarginTop)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_margin_top(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getName)
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
	phpgtk_gtkwidget_get_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getNative)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_native(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getNextSibling)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_next_sibling(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getOpacity)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkwidget_get_opacity(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getOverflow)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_overflow(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getPangoContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_pango_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getParent)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_parent(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getPreferredSize)
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
	phpgtk_gtkwidget_get_preferred_size(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getPrevSibling)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_prev_sibling(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getPrimaryClipboard)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_primary_clipboard(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getRealized)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_realized(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getReceivesDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_receives_default(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getRequestMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_request_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getRoot)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_root(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getScaleFactor)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_scale_factor(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getSensitive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_sensitive(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getSettings)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_settings(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getSize)
{
	zval *handle_param = NULL, *orientation_param = NULL, _0, _1;
	zend_long handle, orientation;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &orientation_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, orientation);
	RETURN_LONG(phpgtk_gtkwidget_get_size(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getSizeRequest)
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
	phpgtk_gtkwidget_get_size_request(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getStateFlags)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_state_flags(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getTemplateChild)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *widgetType_param = NULL, *name_param = NULL, _0, _1;
	zend_long handle, widgetType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widgetType)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &widgetType_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widgetType);
	RETURN_MM_LONG(phpgtk_gtkwidget_get_template_child(&_0, &_1, &name));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getTooltipMarkup)
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
	phpgtk_gtkwidget_get_tooltip_markup(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getTooltipText)
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
	phpgtk_gtkwidget_get_tooltip_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getValign)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_valign(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getVexpand)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_vexpand(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getVexpandSet)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_vexpand_set(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_get_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, getWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_get_width(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, grabFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_grab_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, hasCssClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval cssClass;
	zval *handle_param = NULL, *cssClass_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&cssClass);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(cssClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &cssClass_param);
	zephir_get_strval(&cssClass, cssClass_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_has_css_class(&_0, &cssClass);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, hasDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_has_default(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, hasFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_has_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, hasVisibleFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_has_visible_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, inDestruction)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_in_destruction(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, initTemplate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_init_template(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, insertActionGroup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, *group_param = NULL, _0, _1;
	zend_long handle, group;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
		Z_PARAM_LONG(group)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &name_param, &group_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, group);
	phpgtk_gtkwidget_insert_action_group(&_0, &name, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, insertAfter)
{
	zval *handle_param = NULL, *parent_param = NULL, *previousSibling_param = NULL, _0, _1, _2;
	zend_long handle, parent, previousSibling;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(parent)
		Z_PARAM_LONG(previousSibling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &parent_param, &previousSibling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, parent);
	ZVAL_LONG(&_2, previousSibling);
	phpgtk_gtkwidget_insert_after(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, insertBefore)
{
	zval *handle_param = NULL, *parent_param = NULL, *nextSibling_param = NULL, _0, _1, _2;
	zend_long handle, parent, nextSibling;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(parent)
		Z_PARAM_LONG(nextSibling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &parent_param, &nextSibling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, parent);
	ZVAL_LONG(&_2, nextSibling);
	phpgtk_gtkwidget_insert_before(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, isAncestor)
{
	zval *handle_param = NULL, *ancestor_param = NULL, _0, _1;
	zend_long handle, ancestor, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(ancestor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &ancestor_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, ancestor);
	r = phpgtk_gtkwidget_is_ancestor(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, isDrawable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_is_drawable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, isFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_is_focus(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, isSensitive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_is_sensitive(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, isVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_is_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, keynavFailed)
{
	zval *handle_param = NULL, *direction_param = NULL, _0, _1;
	zend_long handle, direction, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(direction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &direction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, direction);
	r = phpgtk_gtkwidget_keynav_failed(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, listMnemonicLabels)
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
	phpgtk_gtkwidget_list_mnemonic_labels(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, map)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_map(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, measure)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *orientation_param = NULL, *forSize_param = NULL, result, _0, _1, _2;
	zend_long handle, orientation, forSize;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(orientation)
		Z_PARAM_LONG(forSize)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &orientation_param, &forSize_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, orientation);
	ZVAL_LONG(&_2, forSize);
	phpgtk_gtkwidget_measure(&result, &_0, &_1, &_2);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, mnemonicActivate)
{
	zend_bool groupCycling;
	zval *handle_param = NULL, *groupCycling_param = NULL, _0, _1;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(groupCycling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &groupCycling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (groupCycling ? 1 : 0));
	r = phpgtk_gtkwidget_mnemonic_activate(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, observeChildren)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_observe_children(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, observeControllers)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwidget_observe_controllers(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, pick)
{
	double x, y;
	zval *handle_param = NULL, *x_param = NULL, *y_param = NULL, *flags_param = NULL, _0, _1, _2, _3;
	zend_long handle, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(x)
		Z_PARAM_ZVAL(y)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &x_param, &y_param, &flags_param);
	x = zephir_get_doubleval(x_param);
	y = zephir_get_doubleval(y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, x);
	ZVAL_DOUBLE(&_2, y);
	ZVAL_LONG(&_3, flags);
	RETURN_LONG(phpgtk_gtkwidget_pick(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, queueAllocate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_queue_allocate(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, queueDraw)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_queue_draw(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, queueResize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_queue_resize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, realize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_realize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, removeController)
{
	zval *handle_param = NULL, *controller_param = NULL, _0, _1;
	zend_long handle, controller;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(controller)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &controller_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, controller);
	phpgtk_gtkwidget_remove_controller(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, removeCssClass)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval cssClass;
	zval *handle_param = NULL, *cssClass_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&cssClass);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(cssClass)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &cssClass_param);
	zephir_get_strval(&cssClass, cssClass_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_remove_css_class(&_0, &cssClass);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, removeMnemonicLabel)
{
	zval *handle_param = NULL, *label_param = NULL, _0, _1;
	zend_long handle, label;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &label_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, label);
	phpgtk_gtkwidget_remove_mnemonic_label(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, removeTickCallback)
{
	zval *handle_param = NULL, *id_param = NULL, _0, _1;
	zend_long handle, id;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &id_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, id);
	phpgtk_gtkwidget_remove_tick_callback(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setCanFocus)
{
	zend_bool canFocus;
	zval *handle_param = NULL, *canFocus_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(canFocus)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &canFocus_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (canFocus ? 1 : 0));
	phpgtk_gtkwidget_set_can_focus(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setCanTarget)
{
	zend_bool canTarget;
	zval *handle_param = NULL, *canTarget_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(canTarget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &canTarget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (canTarget ? 1 : 0));
	phpgtk_gtkwidget_set_can_target(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setChildVisible)
{
	zend_bool childVisible;
	zval *handle_param = NULL, *childVisible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(childVisible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &childVisible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (childVisible ? 1 : 0));
	phpgtk_gtkwidget_set_child_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setCssClasses)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval classes;
	zval *handle_param = NULL, *classes_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&classes);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ARRAY(classes)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &classes_param);
	zephir_get_arrval(&classes, classes_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_set_css_classes(&_0, &classes);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setCursor)
{
	zval *handle_param = NULL, *cursor_param = NULL, _0, _1;
	zend_long handle, cursor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(cursor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &cursor_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, cursor);
	phpgtk_gtkwidget_set_cursor(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setCursorFromName)
{
	zval *handle_param = NULL, *name = NULL, name_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &name);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_set_cursor_from_name(&_0, name);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setDirection)
{
	zval *handle_param = NULL, *dir_param = NULL, _0, _1;
	zend_long handle, dir;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(dir)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &dir_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, dir);
	phpgtk_gtkwidget_set_direction(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setFocusChild)
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
	phpgtk_gtkwidget_set_focus_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setFocusOnClick)
{
	zend_bool focusOnClick;
	zval *handle_param = NULL, *focusOnClick_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(focusOnClick)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &focusOnClick_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (focusOnClick ? 1 : 0));
	phpgtk_gtkwidget_set_focus_on_click(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setFocusable)
{
	zend_bool focusable;
	zval *handle_param = NULL, *focusable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(focusable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &focusable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (focusable ? 1 : 0));
	phpgtk_gtkwidget_set_focusable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setFontMap)
{
	zval *handle_param = NULL, *fontMap_param = NULL, _0, _1;
	zend_long handle, fontMap;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(fontMap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fontMap_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, fontMap);
	phpgtk_gtkwidget_set_font_map(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setHalign)
{
	zval *handle_param = NULL, *align_param = NULL, _0, _1;
	zend_long handle, align;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &align_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, align);
	phpgtk_gtkwidget_set_halign(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setHasTooltip)
{
	zend_bool hasTooltip;
	zval *handle_param = NULL, *hasTooltip_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasTooltip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasTooltip_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasTooltip ? 1 : 0));
	phpgtk_gtkwidget_set_has_tooltip(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setHexpand)
{
	zend_bool expand;
	zval *handle_param = NULL, *expand_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &expand_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (expand ? 1 : 0));
	phpgtk_gtkwidget_set_hexpand(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setHexpandSet)
{
	zend_bool set;
	zval *handle_param = NULL, *set_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(set)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &set_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (set ? 1 : 0));
	phpgtk_gtkwidget_set_hexpand_set(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setLayoutManager)
{
	zval *handle_param = NULL, *layoutManager_param = NULL, _0, _1;
	zend_long handle, layoutManager;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(layoutManager)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &layoutManager_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, layoutManager);
	phpgtk_gtkwidget_set_layout_manager(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setLimitEvents)
{
	zend_bool limitEvents;
	zval *handle_param = NULL, *limitEvents_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(limitEvents)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &limitEvents_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (limitEvents ? 1 : 0));
	phpgtk_gtkwidget_set_limit_events(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setMarginBottom)
{
	zval *handle_param = NULL, *margin_param = NULL, _0, _1;
	zend_long handle, margin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &margin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, margin);
	phpgtk_gtkwidget_set_margin_bottom(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setMarginEnd)
{
	zval *handle_param = NULL, *margin_param = NULL, _0, _1;
	zend_long handle, margin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &margin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, margin);
	phpgtk_gtkwidget_set_margin_end(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setMarginStart)
{
	zval *handle_param = NULL, *margin_param = NULL, _0, _1;
	zend_long handle, margin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &margin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, margin);
	phpgtk_gtkwidget_set_margin_start(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setMarginTop)
{
	zval *handle_param = NULL, *margin_param = NULL, _0, _1;
	zend_long handle, margin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(margin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &margin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, margin);
	phpgtk_gtkwidget_set_margin_top(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_set_name(&_0, &name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setOpacity)
{
	double opacity;
	zval *handle_param = NULL, *opacity_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(opacity)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &opacity_param);
	opacity = zephir_get_doubleval(opacity_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, opacity);
	phpgtk_gtkwidget_set_opacity(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setOverflow)
{
	zval *handle_param = NULL, *overflow_param = NULL, _0, _1;
	zend_long handle, overflow;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(overflow)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &overflow_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, overflow);
	phpgtk_gtkwidget_set_overflow(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setParent)
{
	zval *handle_param = NULL, *parent_param = NULL, _0, _1;
	zend_long handle, parent;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(parent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &parent_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, parent);
	phpgtk_gtkwidget_set_parent(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setReceivesDefault)
{
	zend_bool receivesDefault;
	zval *handle_param = NULL, *receivesDefault_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(receivesDefault)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &receivesDefault_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (receivesDefault ? 1 : 0));
	phpgtk_gtkwidget_set_receives_default(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setSensitive)
{
	zend_bool sensitive;
	zval *handle_param = NULL, *sensitive_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(sensitive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &sensitive_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (sensitive ? 1 : 0));
	phpgtk_gtkwidget_set_sensitive(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setSizeRequest)
{
	zval *handle_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2;
	zend_long handle, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &width_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	phpgtk_gtkwidget_set_size_request(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setStateFlags)
{
	zend_bool clear;
	zval *handle_param = NULL, *flags_param = NULL, *clear_param = NULL, _0, _1, _2;
	zend_long handle, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(flags)
		Z_PARAM_BOOL(clear)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &flags_param, &clear_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, flags);
	ZVAL_BOOL(&_2, (clear ? 1 : 0));
	phpgtk_gtkwidget_set_state_flags(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setTooltipMarkup)
{
	zval *handle_param = NULL, *markup = NULL, markup_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&markup_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(markup)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &markup);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_set_tooltip_markup(&_0, markup);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setTooltipText)
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
	phpgtk_gtkwidget_set_tooltip_text(&_0, text);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setValign)
{
	zval *handle_param = NULL, *align_param = NULL, _0, _1;
	zend_long handle, align;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &align_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, align);
	phpgtk_gtkwidget_set_valign(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setVexpand)
{
	zend_bool expand;
	zval *handle_param = NULL, *expand_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &expand_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (expand ? 1 : 0));
	phpgtk_gtkwidget_set_vexpand(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setVexpandSet)
{
	zend_bool set;
	zval *handle_param = NULL, *set_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(set)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &set_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (set ? 1 : 0));
	phpgtk_gtkwidget_set_vexpand_set(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, setVisible)
{
	zend_bool visible;
	zval *handle_param = NULL, *visible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &visible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (visible ? 1 : 0));
	phpgtk_gtkwidget_set_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, shouldLayout)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwidget_should_layout(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, sizeAllocate)
{
	zval *handle_param = NULL, *allocationX_param = NULL, *allocationY_param = NULL, *allocationWidth_param = NULL, *allocationHeight_param = NULL, *baseline_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long handle, allocationX, allocationY, allocationWidth, allocationHeight, baseline;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(allocationX)
		Z_PARAM_LONG(allocationY)
		Z_PARAM_LONG(allocationWidth)
		Z_PARAM_LONG(allocationHeight)
		Z_PARAM_LONG(baseline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &handle_param, &allocationX_param, &allocationY_param, &allocationWidth_param, &allocationHeight_param, &baseline_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, allocationX);
	ZVAL_LONG(&_2, allocationY);
	ZVAL_LONG(&_3, allocationWidth);
	ZVAL_LONG(&_4, allocationHeight);
	ZVAL_LONG(&_5, baseline);
	phpgtk_gtkwidget_size_allocate(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, snapshotChild)
{
	zval *handle_param = NULL, *child_param = NULL, *snapshot_param = NULL, _0, _1, _2;
	zend_long handle, child, snapshot;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(snapshot)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &snapshot_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, snapshot);
	phpgtk_gtkwidget_snapshot_child(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, triggerTooltipQuery)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_trigger_tooltip_query(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, unmap)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_unmap(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, unparent)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_unparent(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, unrealize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwidget_unrealize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWidget_GtkWidget, unsetStateFlags)
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
	phpgtk_gtkwidget_unset_state_flags(&_0, &_1);
}

