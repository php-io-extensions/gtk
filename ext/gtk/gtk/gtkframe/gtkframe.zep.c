
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
#include "src/gtk-frame.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFrame_GtkFrame)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkFrame, GtkFrame, gtk_gtk, gtkframe_gtkframe, gtk_gtk_gtkframe_gtkframe_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, new_)
{
	zval *label = NULL, label_sub;

	ZVAL_UNDEF(&label_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label);
	RETURN_LONG(phpgtk_gtkframe_new(label));
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkframe_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabel)
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
	phpgtk_gtkframe_get_label(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabelAlign)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkframe_get_label_align(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabelWidget)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkframe_get_label_widget(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setChild)
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
	phpgtk_gtkframe_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabel)
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
	phpgtk_gtkframe_set_label(&_0, label);
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabelAlign)
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
	phpgtk_gtkframe_set_label_align(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabelWidget)
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
	phpgtk_gtkframe_set_label_widget(&_0, &_1);
}

