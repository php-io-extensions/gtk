
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
#include "src/gtk-aspect-frame.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkAspectFrame, GtkAspectFrame, gtk_gtk, gtkaspectframe_gtkaspectframe, gtk_gtk_gtkaspectframe_gtkaspectframe_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, new_)
{
	zend_bool obeyChild;
	zval *xalign_param = NULL, *yalign_param = NULL, *ratio_param = NULL, *obeyChild_param = NULL, _0, _1, _2, _3;
	double xalign, yalign, ratio;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_ZVAL(xalign)
		Z_PARAM_ZVAL(yalign)
		Z_PARAM_ZVAL(ratio)
		Z_PARAM_BOOL(obeyChild)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &xalign_param, &yalign_param, &ratio_param, &obeyChild_param);
	xalign = zephir_get_doubleval(xalign_param);
	yalign = zephir_get_doubleval(yalign_param);
	ratio = zephir_get_doubleval(ratio_param);
	ZVAL_DOUBLE(&_0, xalign);
	ZVAL_DOUBLE(&_1, yalign);
	ZVAL_DOUBLE(&_2, ratio);
	ZVAL_BOOL(&_3, (obeyChild ? 1 : 0));
	RETURN_LONG(phpgtk_gtkaspectframe_new(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkaspectframe_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getObeyChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkaspectframe_get_obey_child(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getRatio)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkaspectframe_get_ratio(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getXalign)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkaspectframe_get_xalign(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getYalign)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkaspectframe_get_yalign(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setChild)
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
	phpgtk_gtkaspectframe_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setObeyChild)
{
	zend_bool obeyChild;
	zval *handle_param = NULL, *obeyChild_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(obeyChild)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &obeyChild_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (obeyChild ? 1 : 0));
	phpgtk_gtkaspectframe_set_obey_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setRatio)
{
	double ratio;
	zval *handle_param = NULL, *ratio_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(ratio)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &ratio_param);
	ratio = zephir_get_doubleval(ratio_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, ratio);
	phpgtk_gtkaspectframe_set_ratio(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setXalign)
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
	phpgtk_gtkaspectframe_set_xalign(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setYalign)
{
	double yalign;
	zval *handle_param = NULL, *yalign_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(yalign)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &yalign_param);
	yalign = zephir_get_doubleval(yalign_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, yalign);
	phpgtk_gtkaspectframe_set_yalign(&_0, &_1);
}

