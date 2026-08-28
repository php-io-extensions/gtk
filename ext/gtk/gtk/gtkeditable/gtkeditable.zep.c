
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
#include "src/gtk-editable.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEditable_GtkEditable)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEditable, GtkEditable, gtk_gtk, gtkeditable_gtkeditable, gtk_gtk_gtkeditable_gtkeditable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, delegateGetAccessiblePlatformState)
{
	zval *handle_param = NULL, *state_param = NULL, _0, _1;
	zend_long handle, state, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(state)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &state_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, state);
	r = phpgtk_gtkeditable_delegate_get_accessible_platform_state(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, deleteSelection)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkeditable_delete_selection(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, deleteText)
{
	zval *handle_param = NULL, *startPos_param = NULL, *endPos_param = NULL, _0, _1, _2;
	zend_long handle, startPos, endPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(startPos)
		Z_PARAM_LONG(endPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &startPos_param, &endPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, startPos);
	ZVAL_LONG(&_2, endPos);
	phpgtk_gtkeditable_delete_text(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, finishDelegate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkeditable_finish_delegate(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getAlignment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkeditable_get_alignment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getChars)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *startPos_param = NULL, *endPos_param = NULL, result, _0, _1, _2;
	zend_long handle, startPos, endPos;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(startPos)
		Z_PARAM_LONG(endPos)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &startPos_param, &endPos_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, startPos);
	ZVAL_LONG(&_2, endPos);
	phpgtk_gtkeditable_get_chars(&result, &_0, &_1, &_2);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getDelegate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeditable_get_delegate(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getEditable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkeditable_get_editable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getEnableUndo)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkeditable_get_enable_undo(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getMaxWidthChars)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeditable_get_max_width_chars(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getPosition)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeditable_get_position(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getSelectionBounds)
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
	phpgtk_gtkeditable_get_selection_bounds(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getText)
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
	phpgtk_gtkeditable_get_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getWidthChars)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkeditable_get_width_chars(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, initDelegate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkeditable_init_delegate(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, insertText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *handle_param = NULL, *text_param = NULL, *length_param = NULL, *position_param = NULL, result, _0, _1, _2;
	zend_long handle, length, position;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(length)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &text_param, &length_param, &position_param);
	zephir_get_strval(&text, text_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, length);
	ZVAL_LONG(&_2, position);
	phpgtk_gtkeditable_insert_text(&result, &_0, &text, &_1, &_2);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, selectRegion)
{
	zval *handle_param = NULL, *startPos_param = NULL, *endPos_param = NULL, _0, _1, _2;
	zend_long handle, startPos, endPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(startPos)
		Z_PARAM_LONG(endPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &startPos_param, &endPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, startPos);
	ZVAL_LONG(&_2, endPos);
	phpgtk_gtkeditable_select_region(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setAlignment)
{
	double xalign;
	zval *handle_param = NULL, *xalign_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(xalign)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &xalign_param);
	xalign = zephir_get_doubleval(xalign_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, xalign);
	phpgtk_gtkeditable_set_alignment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setEditable)
{
	zend_bool isEditable;
	zval *handle_param = NULL, *isEditable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(isEditable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &isEditable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (isEditable ? 1 : 0));
	phpgtk_gtkeditable_set_editable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setEnableUndo)
{
	zend_bool enableUndo;
	zval *handle_param = NULL, *enableUndo_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enableUndo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enableUndo_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enableUndo ? 1 : 0));
	phpgtk_gtkeditable_set_enable_undo(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setMaxWidthChars)
{
	zval *handle_param = NULL, *nChars_param = NULL, _0, _1;
	zend_long handle, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &nChars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nChars);
	phpgtk_gtkeditable_set_max_width_chars(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setPosition)
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
	phpgtk_gtkeditable_set_position(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *handle_param = NULL, *text_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &text_param);
	zephir_get_strval(&text, text_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkeditable_set_text(&_0, &text);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setWidthChars)
{
	zval *handle_param = NULL, *nChars_param = NULL, _0, _1;
	zend_long handle, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &nChars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nChars);
	phpgtk_gtkeditable_set_width_chars(&_0, &_1);
}

