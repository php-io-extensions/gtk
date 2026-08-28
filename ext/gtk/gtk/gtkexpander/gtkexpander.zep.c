
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
#include "src/gtk-expander.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkExpander_GtkExpander)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkExpander, GtkExpander, gtk_gtk, gtkexpander_gtkexpander, gtk_gtk_gtkexpander_gtkexpander_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, new_)
{
	zval *label = NULL, label_sub;

	ZVAL_UNDEF(&label_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label);
	RETURN_LONG(phpgtk_gtkexpander_new(label));
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, newWithMnemonic)
{
	zval *label = NULL, label_sub;

	ZVAL_UNDEF(&label_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label);
	RETURN_LONG(phpgtk_gtkexpander_new_with_mnemonic(label));
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkexpander_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getExpanded)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkexpander_get_expanded(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getLabel)
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
	phpgtk_gtkexpander_get_label(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getLabelWidget)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkexpander_get_label_widget(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getResizeToplevel)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkexpander_get_resize_toplevel(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getUseMarkup)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkexpander_get_use_markup(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getUseUnderline)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkexpander_get_use_underline(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setChild)
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
	phpgtk_gtkexpander_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setExpanded)
{
	zend_bool expanded;
	zval *handle_param = NULL, *expanded_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(expanded)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &expanded_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (expanded ? 1 : 0));
	phpgtk_gtkexpander_set_expanded(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setLabel)
{
	zval *handle_param = NULL, *label = NULL, label_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &label);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkexpander_set_label(&_0, label);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setLabelWidget)
{
	zval *handle_param = NULL, *labelWidget_param = NULL, _0, _1;
	zend_long handle, labelWidget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(labelWidget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &labelWidget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, labelWidget);
	phpgtk_gtkexpander_set_label_widget(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setResizeToplevel)
{
	zend_bool resizeToplevel;
	zval *handle_param = NULL, *resizeToplevel_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(resizeToplevel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &resizeToplevel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (resizeToplevel ? 1 : 0));
	phpgtk_gtkexpander_set_resize_toplevel(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setUseMarkup)
{
	zend_bool useMarkup;
	zval *handle_param = NULL, *useMarkup_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(useMarkup)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &useMarkup_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (useMarkup ? 1 : 0));
	phpgtk_gtkexpander_set_use_markup(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setUseUnderline)
{
	zend_bool useUnderline;
	zval *handle_param = NULL, *useUnderline_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(useUnderline)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &useUnderline_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (useUnderline ? 1 : 0));
	phpgtk_gtkexpander_set_use_underline(&_0, &_1);
}

