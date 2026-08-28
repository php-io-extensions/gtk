
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
#include "src/gtk-stack-sidebar.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStackSidebar_GtkStackSidebar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkStackSidebar, GtkStackSidebar, gtk_gtk, gtkstacksidebar_gtkstacksidebar, gtk_gtk_gtkstacksidebar_gtkstacksidebar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkStackSidebar_GtkStackSidebar, new_)
{

	RETURN_LONG(phpgtk_gtkstacksidebar_new());
}

PHP_METHOD(Gtk_Gtk_GtkStackSidebar_GtkStackSidebar, getStack)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkstacksidebar_get_stack(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkStackSidebar_GtkStackSidebar, setStack)
{
	zval *handle_param = NULL, *stack_param = NULL, _0, _1;
	zend_long handle, stack;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(stack)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &stack_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, stack);
	phpgtk_gtkstacksidebar_set_stack(&_0, &_1);
}

