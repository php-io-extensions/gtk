
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
#include "src/gtk-list-box-row.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkListBoxRow, GtkListBoxRow, gtk_gtk, gtklistboxrow_gtklistboxrow, gtk_gtk_gtklistboxrow_gtklistboxrow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, new_)
{

	RETURN_LONG(phpgtk_gtklistboxrow_new());
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, changed)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklistboxrow_changed(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getActivatable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklistboxrow_get_activatable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistboxrow_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getHeader)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistboxrow_get_header(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getIndex)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklistboxrow_get_index(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getSelectable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklistboxrow_get_selectable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, isSelected)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklistboxrow_is_selected(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setActivatable)
{
	zend_bool activatable;
	zval *handle_param = NULL, *activatable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(activatable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &activatable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (activatable ? 1 : 0));
	phpgtk_gtklistboxrow_set_activatable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setChild)
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
	phpgtk_gtklistboxrow_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setHeader)
{
	zval *handle_param = NULL, *header_param = NULL, _0, _1;
	zend_long handle, header;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(header)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &header_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, header);
	phpgtk_gtklistboxrow_set_header(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setSelectable)
{
	zend_bool selectable;
	zval *handle_param = NULL, *selectable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(selectable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &selectable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (selectable ? 1 : 0));
	phpgtk_gtklistboxrow_set_selectable(&_0, &_1);
}

