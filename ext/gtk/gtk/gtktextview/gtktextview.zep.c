
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
#include "src/gtk-text-view.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextView_GtkTextView)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkTextView, GtkTextView, gtk_gtk, gtktextview_gtktextview, gtk_gtk_gtktextview_gtktextview_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, new_)
{

	RETURN_LONG(phpgtk_gtktextview_new());
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, newWithBuffer)
{
	zval *buffer_param = NULL, _0;
	zend_long buffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &buffer_param);
	ZVAL_LONG(&_0, buffer);
	RETURN_LONG(phpgtk_gtktextview_new_with_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, addChildAtAnchor)
{
	zval *handle_param = NULL, *child_param = NULL, *anchor_param = NULL, _0, _1, _2;
	zend_long handle, child, anchor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(anchor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &anchor_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, anchor);
	phpgtk_gtktextview_add_child_at_anchor(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, addOverlay)
{
	zval *handle_param = NULL, *child_param = NULL, *xpos_param = NULL, *ypos_param = NULL, _0, _1, _2, _3;
	zend_long handle, child, xpos, ypos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(xpos)
		Z_PARAM_LONG(ypos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &child_param, &xpos_param, &ypos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, xpos);
	ZVAL_LONG(&_3, ypos);
	phpgtk_gtktextview_add_overlay(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, bufferToWindowCoords)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *win_param = NULL, *bufferX_param = NULL, *bufferY_param = NULL, result, _0, _1, _2, _3;
	zend_long handle, win, bufferX, bufferY;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(win)
		Z_PARAM_LONG(bufferX)
		Z_PARAM_LONG(bufferY)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &win_param, &bufferX_param, &bufferY_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, win);
	ZVAL_LONG(&_2, bufferX);
	ZVAL_LONG(&_3, bufferY);
	phpgtk_gtktextview_buffer_to_window_coords(&result, &_0, &_1, &_2, &_3);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getAcceptsTab)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_get_accepts_tab(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getBottomMargin)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_bottom_margin(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getBuffer)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getCursorVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_get_cursor_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getEditable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_get_editable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getExtraMenu)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_extra_menu(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getGutter)
{
	zval *handle_param = NULL, *win_param = NULL, _0, _1;
	zend_long handle, win;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(win)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &win_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, win);
	RETURN_LONG(phpgtk_gtktextview_get_gutter(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getIndent)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_indent(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getInputHints)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_input_hints(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getInputPurpose)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_input_purpose(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getJustification)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_justification(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getLeftMargin)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_left_margin(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getLtrContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_ltr_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getMonospace)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_get_monospace(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getOverwrite)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_get_overwrite(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsAboveLines)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_pixels_above_lines(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsBelowLines)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_pixels_below_lines(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsInsideWrap)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_pixels_inside_wrap(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getRightMargin)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_right_margin(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getRtlContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_rtl_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getTopMargin)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_top_margin(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleOffset)
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
	phpgtk_gtktextview_get_visible_offset(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleRect)
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
	phpgtk_gtktextview_get_visible_rect(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getWrapMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextview_get_wrap_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, imContextFilterKeypress)
{
	zval *handle_param = NULL, *event_param = NULL, _0, _1;
	zend_long handle, event, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(event)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &event_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, event);
	r = phpgtk_gtktextview_im_context_filter_keypress(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, moveMarkOnscreen)
{
	zval *handle_param = NULL, *mark_param = NULL, _0, _1;
	zend_long handle, mark, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mark)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mark_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mark);
	r = phpgtk_gtktextview_move_mark_onscreen(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, moveOverlay)
{
	zval *handle_param = NULL, *child_param = NULL, *xpos_param = NULL, *ypos_param = NULL, _0, _1, _2, _3;
	zend_long handle, child, xpos, ypos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(xpos)
		Z_PARAM_LONG(ypos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &child_param, &xpos_param, &ypos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, xpos);
	ZVAL_LONG(&_3, ypos);
	phpgtk_gtktextview_move_overlay(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, placeCursorOnscreen)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextview_place_cursor_onscreen(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, remove)
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
	phpgtk_gtktextview_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, resetCursorBlink)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextview_reset_cursor_blink(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, resetImContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextview_reset_im_context(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, scrollMarkOnscreen)
{
	zval *handle_param = NULL, *mark_param = NULL, _0, _1;
	zend_long handle, mark;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mark)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mark_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mark);
	phpgtk_gtktextview_scroll_mark_onscreen(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, scrollToMark)
{
	zend_bool useAlign;
	double withinMargin, xalign, yalign;
	zval *handle_param = NULL, *mark_param = NULL, *withinMargin_param = NULL, *useAlign_param = NULL, *xalign_param = NULL, *yalign_param = NULL, _0, _1, _2, _3, _4, _5;
	zend_long handle, mark;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mark)
		Z_PARAM_ZVAL(withinMargin)
		Z_PARAM_BOOL(useAlign)
		Z_PARAM_ZVAL(xalign)
		Z_PARAM_ZVAL(yalign)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &handle_param, &mark_param, &withinMargin_param, &useAlign_param, &xalign_param, &yalign_param);
	withinMargin = zephir_get_doubleval(withinMargin_param);
	xalign = zephir_get_doubleval(xalign_param);
	yalign = zephir_get_doubleval(yalign_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mark);
	ZVAL_DOUBLE(&_2, withinMargin);
	ZVAL_BOOL(&_3, (useAlign ? 1 : 0));
	ZVAL_DOUBLE(&_4, xalign);
	ZVAL_DOUBLE(&_5, yalign);
	phpgtk_gtktextview_scroll_to_mark(&_0, &_1, &_2, &_3, &_4, &_5);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setAcceptsTab)
{
	zend_bool acceptsTab;
	zval *handle_param = NULL, *acceptsTab_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(acceptsTab)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &acceptsTab_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (acceptsTab ? 1 : 0));
	phpgtk_gtktextview_set_accepts_tab(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setBottomMargin)
{
	zval *handle_param = NULL, *bottomMargin_param = NULL, _0, _1;
	zend_long handle, bottomMargin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(bottomMargin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &bottomMargin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, bottomMargin);
	phpgtk_gtktextview_set_bottom_margin(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setBuffer)
{
	zval *handle_param = NULL, *buffer_param = NULL, _0, _1;
	zend_long handle, buffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &buffer_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, buffer);
	phpgtk_gtktextview_set_buffer(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setCursorVisible)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtktextview_set_cursor_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setEditable)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtktextview_set_editable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setExtraMenu)
{
	zval *handle_param = NULL, *model_param = NULL, _0, _1;
	zend_long handle, model;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &model_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, model);
	phpgtk_gtktextview_set_extra_menu(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setGutter)
{
	zval *handle_param = NULL, *win_param = NULL, *widget_param = NULL, _0, _1, _2;
	zend_long handle, win, widget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(win)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &win_param, &widget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, win);
	ZVAL_LONG(&_2, widget);
	phpgtk_gtktextview_set_gutter(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setIndent)
{
	zval *handle_param = NULL, *indent_param = NULL, _0, _1;
	zend_long handle, indent;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(indent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &indent_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, indent);
	phpgtk_gtktextview_set_indent(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setInputHints)
{
	zval *handle_param = NULL, *hints_param = NULL, _0, _1;
	zend_long handle, hints;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(hints)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hints_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, hints);
	phpgtk_gtktextview_set_input_hints(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setInputPurpose)
{
	zval *handle_param = NULL, *purpose_param = NULL, _0, _1;
	zend_long handle, purpose;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(purpose)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &purpose_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, purpose);
	phpgtk_gtktextview_set_input_purpose(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setJustification)
{
	zval *handle_param = NULL, *justification_param = NULL, _0, _1;
	zend_long handle, justification;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(justification)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &justification_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, justification);
	phpgtk_gtktextview_set_justification(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setLeftMargin)
{
	zval *handle_param = NULL, *leftMargin_param = NULL, _0, _1;
	zend_long handle, leftMargin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(leftMargin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &leftMargin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, leftMargin);
	phpgtk_gtktextview_set_left_margin(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setMonospace)
{
	zend_bool monospace;
	zval *handle_param = NULL, *monospace_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(monospace)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &monospace_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (monospace ? 1 : 0));
	phpgtk_gtktextview_set_monospace(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setOverwrite)
{
	zend_bool overwrite;
	zval *handle_param = NULL, *overwrite_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(overwrite)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &overwrite_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (overwrite ? 1 : 0));
	phpgtk_gtktextview_set_overwrite(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsAboveLines)
{
	zval *handle_param = NULL, *pixelsAboveLines_param = NULL, _0, _1;
	zend_long handle, pixelsAboveLines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pixelsAboveLines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pixelsAboveLines_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pixelsAboveLines);
	phpgtk_gtktextview_set_pixels_above_lines(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsBelowLines)
{
	zval *handle_param = NULL, *pixelsBelowLines_param = NULL, _0, _1;
	zend_long handle, pixelsBelowLines;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pixelsBelowLines)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pixelsBelowLines_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pixelsBelowLines);
	phpgtk_gtktextview_set_pixels_below_lines(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsInsideWrap)
{
	zval *handle_param = NULL, *pixelsInsideWrap_param = NULL, _0, _1;
	zend_long handle, pixelsInsideWrap;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pixelsInsideWrap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pixelsInsideWrap_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pixelsInsideWrap);
	phpgtk_gtktextview_set_pixels_inside_wrap(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setRightMargin)
{
	zval *handle_param = NULL, *rightMargin_param = NULL, _0, _1;
	zend_long handle, rightMargin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(rightMargin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &rightMargin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, rightMargin);
	phpgtk_gtktextview_set_right_margin(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setTopMargin)
{
	zval *handle_param = NULL, *topMargin_param = NULL, _0, _1;
	zend_long handle, topMargin;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(topMargin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &topMargin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, topMargin);
	phpgtk_gtktextview_set_top_margin(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setWrapMode)
{
	zval *handle_param = NULL, *wrapMode_param = NULL, _0, _1;
	zend_long handle, wrapMode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(wrapMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &wrapMode_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, wrapMode);
	phpgtk_gtktextview_set_wrap_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, windowToBufferCoords)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *win_param = NULL, *windowX_param = NULL, *windowY_param = NULL, result, _0, _1, _2, _3;
	zend_long handle, win, windowX, windowY;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(win)
		Z_PARAM_LONG(windowX)
		Z_PARAM_LONG(windowY)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &win_param, &windowX_param, &windowY_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, win);
	ZVAL_LONG(&_2, windowX);
	ZVAL_LONG(&_3, windowY);
	phpgtk_gtktextview_window_to_buffer_coords(&result, &_0, &_1, &_2, &_3);
	RETURN_CCTOR(&result);
}

