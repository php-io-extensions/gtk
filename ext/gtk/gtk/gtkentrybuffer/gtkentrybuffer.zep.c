
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
#include "src/gtk-entry-buffer.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEntryBuffer, GtkEntryBuffer, gtk_gtk, gtkentrybuffer_gtkentrybuffer, gtk_gtk_gtkentrybuffer_gtkentrybuffer_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, new_)
{
	zend_long nInitialChars;
	zval *initialChars = NULL, initialChars_sub, *nInitialChars_param = NULL, _0;

	ZVAL_UNDEF(&initialChars_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(initialChars)
		Z_PARAM_LONG(nInitialChars)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &initialChars, &nInitialChars_param);
	ZVAL_LONG(&_0, nInitialChars);
	RETURN_LONG(phpgtk_gtkentrybuffer_new(initialChars, &_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, deleteText)
{
	zval *handle_param = NULL, *position_param = NULL, *nChars_param = NULL, _0, _1, _2;
	zend_long handle, position, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &nChars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nChars);
	RETURN_LONG(phpgtk_gtkentrybuffer_delete_text(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitDeletedText)
{
	zval *handle_param = NULL, *position_param = NULL, *nChars_param = NULL, _0, _1, _2;
	zend_long handle, position, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &nChars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nChars);
	phpgtk_gtkentrybuffer_emit_deleted_text(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitInsertedText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval chars;
	zval *handle_param = NULL, *position_param = NULL, *chars_param = NULL, *nChars_param = NULL, _0, _1, _2;
	zend_long handle, position, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&chars);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_STR(chars)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &position_param, &chars_param, &nChars_param);
	zephir_get_strval(&chars, chars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nChars);
	phpgtk_gtkentrybuffer_emit_inserted_text(&_0, &_1, &chars, &_2);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getBytes)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentrybuffer_get_bytes(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentrybuffer_get_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getMaxLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentrybuffer_get_max_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getText)
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
	phpgtk_gtkentrybuffer_get_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, insertText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval chars;
	zval *handle_param = NULL, *position_param = NULL, *chars_param = NULL, *nChars_param = NULL, _0, _1, _2;
	zend_long handle, position, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&chars);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_STR(chars)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &position_param, &chars_param, &nChars_param);
	zephir_get_strval(&chars, chars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nChars);
	RETURN_MM_LONG(phpgtk_gtkentrybuffer_insert_text(&_0, &_1, &chars, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setMaxLength)
{
	zval *handle_param = NULL, *maxLength_param = NULL, _0, _1;
	zend_long handle, maxLength;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(maxLength)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &maxLength_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, maxLength);
	phpgtk_gtkentrybuffer_set_max_length(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval chars;
	zval *handle_param = NULL, *chars_param = NULL, *nChars_param = NULL, _0, _1;
	zend_long handle, nChars;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&chars);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(chars)
		Z_PARAM_LONG(nChars)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &chars_param, &nChars_param);
	zephir_get_strval(&chars, chars_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nChars);
	phpgtk_gtkentrybuffer_set_text(&_0, &chars, &_1);
	ZEPHIR_MM_RESTORE();
}

