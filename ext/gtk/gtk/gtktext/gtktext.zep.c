
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
#include "src/gtk-text.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkText_GtkText)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkText, GtkText, gtk_gtk, gtktext_gtktext, gtk_gtk_gtktext_gtktext_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, new_)
{

	RETURN_LONG(phpgtk_gtktext_new());
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, newWithBuffer)
{
	zval *buffer_param = NULL, _0;
	zend_long buffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &buffer_param);
	ZVAL_LONG(&_0, buffer);
	RETURN_LONG(phpgtk_gtktext_new_with_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, computeCursorExtents)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *position_param = NULL, result, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &position_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gtktext_compute_cursor_extents(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getActivatesDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_activates_default(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getBuffer)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getEnableEmojiCompletion)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_enable_emoji_completion(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getExtraMenu)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_extra_menu(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInputHints)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_input_hints(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInputPurpose)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_input_purpose(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInvisibleChar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_invisible_char(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getMaxLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_max_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getOverwriteMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_overwrite_mode(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getPlaceholderText)
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
	phpgtk_gtktext_get_placeholder_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getPropagateTextWidth)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_propagate_text_width(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getTextLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktext_get_text_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getTruncateMultiline)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_truncate_multiline(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getVisibility)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_get_visibility(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, grabFocusWithoutSelecting)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktext_grab_focus_without_selecting(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setActivatesDefault)
{
	zend_bool activates;
	zval *handle_param = NULL, *activates_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(activates)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &activates_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (activates ? 1 : 0));
	phpgtk_gtktext_set_activates_default(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setBuffer)
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
	phpgtk_gtktext_set_buffer(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setEnableEmojiCompletion)
{
	zend_bool enableEmojiCompletion;
	zval *handle_param = NULL, *enableEmojiCompletion_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enableEmojiCompletion)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enableEmojiCompletion_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enableEmojiCompletion ? 1 : 0));
	phpgtk_gtktext_set_enable_emoji_completion(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setExtraMenu)
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
	phpgtk_gtktext_set_extra_menu(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInputHints)
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
	phpgtk_gtktext_set_input_hints(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInputPurpose)
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
	phpgtk_gtktext_set_input_purpose(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInvisibleChar)
{
	zval *handle_param = NULL, *ch_param = NULL, _0, _1;
	zend_long handle, ch;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(ch)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &ch_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, ch);
	phpgtk_gtktext_set_invisible_char(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setMaxLength)
{
	zval *handle_param = NULL, *length_param = NULL, _0, _1;
	zend_long handle, length;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(length)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &length_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, length);
	phpgtk_gtktext_set_max_length(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setOverwriteMode)
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
	phpgtk_gtktext_set_overwrite_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setPlaceholderText)
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
	phpgtk_gtktext_set_placeholder_text(&_0, text);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setPropagateTextWidth)
{
	zend_bool propagateTextWidth;
	zval *handle_param = NULL, *propagateTextWidth_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(propagateTextWidth)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &propagateTextWidth_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (propagateTextWidth ? 1 : 0));
	phpgtk_gtktext_set_propagate_text_width(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setTruncateMultiline)
{
	zend_bool truncateMultiline;
	zval *handle_param = NULL, *truncateMultiline_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(truncateMultiline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &truncateMultiline_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (truncateMultiline ? 1 : 0));
	phpgtk_gtktext_set_truncate_multiline(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setVisibility)
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
	phpgtk_gtktext_set_visibility(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, unsetInvisibleChar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktext_unset_invisible_char(&_0);
}

