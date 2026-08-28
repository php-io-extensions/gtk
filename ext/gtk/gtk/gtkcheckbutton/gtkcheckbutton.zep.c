
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
#include "src/gtk-check-button.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCheckButton_GtkCheckButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkCheckButton, GtkCheckButton, gtk_gtk, gtkcheckbutton_gtkcheckbutton, gtk_gtk_gtkcheckbutton_gtkcheckbutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, new_)
{

	RETURN_LONG(phpgtk_gtkcheckbutton_new());
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithLabel)
{
	zval *label = NULL, label_sub;

	ZVAL_UNDEF(&label_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label);
	RETURN_LONG(phpgtk_gtkcheckbutton_new_with_label(label));
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithMnemonic)
{
	zval *label = NULL, label_sub;

	ZVAL_UNDEF(&label_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label);
	RETURN_LONG(phpgtk_gtkcheckbutton_new_with_mnemonic(label));
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getActive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcheckbutton_get_active(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcheckbutton_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getInconsistent)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcheckbutton_get_inconsistent(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getLabel)
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
	phpgtk_gtkcheckbutton_get_label(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getUseUnderline)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcheckbutton_get_use_underline(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setActive)
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
	phpgtk_gtkcheckbutton_set_active(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setChild)
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
	phpgtk_gtkcheckbutton_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setGroup)
{
	zval *handle_param = NULL, *group_param = NULL, _0, _1;
	zend_long handle, group;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(group)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &group_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, group);
	phpgtk_gtkcheckbutton_set_group(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setInconsistent)
{
	zend_bool inconsistent;
	zval *handle_param = NULL, *inconsistent_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(inconsistent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &inconsistent_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (inconsistent ? 1 : 0));
	phpgtk_gtkcheckbutton_set_inconsistent(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setLabel)
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
	phpgtk_gtkcheckbutton_set_label(&_0, label);
}

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setUseUnderline)
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
	phpgtk_gtkcheckbutton_set_use_underline(&_0, &_1);
}

