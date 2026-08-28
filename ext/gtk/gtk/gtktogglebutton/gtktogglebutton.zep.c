
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
#include "src/gtk-toggle-button.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkToggleButton_GtkToggleButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkToggleButton, GtkToggleButton, gtk_gtk, gtktogglebutton_gtktogglebutton, gtk_gtk_gtktogglebutton_gtktogglebutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, new_)
{

	RETURN_LONG(phpgtk_gtktogglebutton_new());
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL;
	zval label;

	ZVAL_UNDEF(&label);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(label)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &label_param);
	zephir_get_strval(&label, label_param);
	RETURN_MM_LONG(phpgtk_gtktogglebutton_new_with_label(&label));
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithMnemonic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL;
	zval label;

	ZVAL_UNDEF(&label);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(label)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &label_param);
	zephir_get_strval(&label, label_param);
	RETURN_MM_LONG(phpgtk_gtktogglebutton_new_with_mnemonic(&label));
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, getActive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktogglebutton_get_active(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setActive)
{
	zend_bool isActive;
	zval *handle_param = NULL, *isActive_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(isActive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &isActive_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (isActive ? 1 : 0));
	phpgtk_gtktogglebutton_set_active(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setGroup)
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
	phpgtk_gtktogglebutton_set_group(&_0, &_1);
}

