
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
#include "src/gtk-scrolled-window.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkScrolledWindow, GtkScrolledWindow, gtk_gtk, gtkscrolledwindow_gtkscrolledwindow, gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, new_)
{

	RETURN_LONG(phpgtk_gtkscrolledwindow_new());
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHadjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_hadjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHasFrame)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscrolledwindow_get_has_frame(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHscrollbar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_hscrollbar(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getKineticScrolling)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscrolledwindow_get_kinetic_scrolling(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentHeight)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_max_content_height(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_max_content_width(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentHeight)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_min_content_height(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_min_content_width(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getOverlayScrolling)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscrolledwindow_get_overlay_scrolling(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPlacement)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_placement(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPolicy)
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
	phpgtk_gtkscrolledwindow_get_policy(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalHeight)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscrolledwindow_get_propagate_natural_height(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscrolledwindow_get_propagate_natural_width(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVadjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_vadjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVscrollbar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscrolledwindow_get_vscrollbar(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setChild)
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
	phpgtk_gtkscrolledwindow_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHadjustment)
{
	zval *handle_param = NULL, *hadjustment_param = NULL, _0, _1;
	zend_long handle, hadjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(hadjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hadjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, hadjustment);
	phpgtk_gtkscrolledwindow_set_hadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHasFrame)
{
	zend_bool hasFrame;
	zval *handle_param = NULL, *hasFrame_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasFrame)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasFrame_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasFrame ? 1 : 0));
	phpgtk_gtkscrolledwindow_set_has_frame(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setKineticScrolling)
{
	zend_bool kineticScrolling;
	zval *handle_param = NULL, *kineticScrolling_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(kineticScrolling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &kineticScrolling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (kineticScrolling ? 1 : 0));
	phpgtk_gtkscrolledwindow_set_kinetic_scrolling(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentHeight)
{
	zval *handle_param = NULL, *height_param = NULL, _0, _1;
	zend_long handle, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, height);
	phpgtk_gtkscrolledwindow_set_max_content_height(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentWidth)
{
	zval *handle_param = NULL, *width_param = NULL, _0, _1;
	zend_long handle, width;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &width_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, width);
	phpgtk_gtkscrolledwindow_set_max_content_width(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentHeight)
{
	zval *handle_param = NULL, *height_param = NULL, _0, _1;
	zend_long handle, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, height);
	phpgtk_gtkscrolledwindow_set_min_content_height(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentWidth)
{
	zval *handle_param = NULL, *width_param = NULL, _0, _1;
	zend_long handle, width;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &width_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, width);
	phpgtk_gtkscrolledwindow_set_min_content_width(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setOverlayScrolling)
{
	zend_bool overlayScrolling;
	zval *handle_param = NULL, *overlayScrolling_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(overlayScrolling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &overlayScrolling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (overlayScrolling ? 1 : 0));
	phpgtk_gtkscrolledwindow_set_overlay_scrolling(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPlacement)
{
	zval *handle_param = NULL, *windowPlacement_param = NULL, _0, _1;
	zend_long handle, windowPlacement;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(windowPlacement)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &windowPlacement_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, windowPlacement);
	phpgtk_gtkscrolledwindow_set_placement(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPolicy)
{
	zval *handle_param = NULL, *hscrollbarPolicy_param = NULL, *vscrollbarPolicy_param = NULL, _0, _1, _2;
	zend_long handle, hscrollbarPolicy, vscrollbarPolicy;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(hscrollbarPolicy)
		Z_PARAM_LONG(vscrollbarPolicy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &hscrollbarPolicy_param, &vscrollbarPolicy_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, hscrollbarPolicy);
	ZVAL_LONG(&_2, vscrollbarPolicy);
	phpgtk_gtkscrolledwindow_set_policy(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalHeight)
{
	zend_bool propagate;
	zval *handle_param = NULL, *propagate_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(propagate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &propagate_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (propagate ? 1 : 0));
	phpgtk_gtkscrolledwindow_set_propagate_natural_height(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalWidth)
{
	zend_bool propagate;
	zval *handle_param = NULL, *propagate_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(propagate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &propagate_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (propagate ? 1 : 0));
	phpgtk_gtkscrolledwindow_set_propagate_natural_width(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setVadjustment)
{
	zval *handle_param = NULL, *vadjustment_param = NULL, _0, _1;
	zend_long handle, vadjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(vadjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &vadjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, vadjustment);
	phpgtk_gtkscrolledwindow_set_vadjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, unsetPlacement)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkscrolledwindow_unset_placement(&_0);
}

