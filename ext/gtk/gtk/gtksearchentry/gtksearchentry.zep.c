
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
#include "src/gtk-search-entry.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSearchEntry, GtkSearchEntry, gtk_gtk, gtksearchentry_gtksearchentry, gtk_gtk_gtksearchentry_gtksearchentry_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, new_)
{

	RETURN_LONG(phpgtk_gtksearchentry_new());
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputHints)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtksearchentry_get_input_hints(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputPurpose)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtksearchentry_get_input_purpose(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getKeyCaptureWidget)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtksearchentry_get_key_capture_widget(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getPlaceholderText)
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
	phpgtk_gtksearchentry_get_placeholder_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getSearchDelay)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtksearchentry_get_search_delay(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputHints)
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
	phpgtk_gtksearchentry_set_input_hints(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputPurpose)
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
	phpgtk_gtksearchentry_set_input_purpose(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setKeyCaptureWidget)
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
	phpgtk_gtksearchentry_set_key_capture_widget(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setPlaceholderText)
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
	phpgtk_gtksearchentry_set_placeholder_text(&_0, text);
}

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setSearchDelay)
{
	zval *handle_param = NULL, *delay_param = NULL, _0, _1;
	zend_long handle, delay;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(delay)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &delay_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, delay);
	phpgtk_gtksearchentry_set_search_delay(&_0, &_1);
}

