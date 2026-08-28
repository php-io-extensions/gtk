
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
#include "src/gtk-box.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkBox_GtkBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkBox, GtkBox, gtk_gtk, gtkbox_gtkbox, gtk_gtk_gtkbox_gtkbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, new_)
{
	zval *orientation_param = NULL, *spacing_param = NULL, _0, _1;
	zend_long orientation, spacing;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(orientation)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &orientation_param, &spacing_param);
	ZVAL_LONG(&_0, orientation);
	ZVAL_LONG(&_1, spacing);
	RETURN_LONG(phpgtk_gtkbox_new(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, append)
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
	phpgtk_gtkbox_append(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getBaselineChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkbox_get_baseline_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getBaselinePosition)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkbox_get_baseline_position(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getHomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkbox_get_homogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getSpacing)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkbox_get_spacing(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, insertChildAfter)
{
	zval *handle_param = NULL, *child_param = NULL, *sibling_param = NULL, _0, _1, _2;
	zend_long handle, child, sibling;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(sibling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &sibling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, sibling);
	phpgtk_gtkbox_insert_child_after(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, prepend)
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
	phpgtk_gtkbox_prepend(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, remove)
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
	phpgtk_gtkbox_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, reorderChildAfter)
{
	zval *handle_param = NULL, *child_param = NULL, *sibling_param = NULL, _0, _1, _2;
	zend_long handle, child, sibling;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(sibling)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &sibling_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, sibling);
	phpgtk_gtkbox_reorder_child_after(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setBaselineChild)
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
	phpgtk_gtkbox_set_baseline_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setBaselinePosition)
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
	phpgtk_gtkbox_set_baseline_position(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setHomogeneous)
{
	zend_bool homogeneous;
	zval *handle_param = NULL, *homogeneous_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &homogeneous_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (homogeneous ? 1 : 0));
	phpgtk_gtkbox_set_homogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setSpacing)
{
	zval *handle_param = NULL, *spacing_param = NULL, _0, _1;
	zend_long handle, spacing;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &spacing_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, spacing);
	phpgtk_gtkbox_set_spacing(&_0, &_1);
}

