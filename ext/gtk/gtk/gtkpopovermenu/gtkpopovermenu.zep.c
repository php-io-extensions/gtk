
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
#include "src/gtk-popover-menu.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkPopoverMenu, GtkPopoverMenu, gtk_gtk, gtkpopovermenu_gtkpopovermenu, gtk_gtk_gtkpopovermenu_gtkpopovermenu_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModel)
{
	zval *model_param = NULL, _0;
	zend_long model;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &model_param);
	ZVAL_LONG(&_0, model);
	RETURN_LONG(phpgtk_gtkpopovermenu_new_from_model(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModelFull)
{
	zval *model_param = NULL, *flags_param = NULL, _0, _1;
	zend_long model, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(model)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &model_param, &flags_param);
	ZVAL_LONG(&_0, model);
	ZVAL_LONG(&_1, flags);
	RETURN_LONG(phpgtk_gtkpopovermenu_new_from_model_full(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, addChild)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval id;
	zval *handle_param = NULL, *child_param = NULL, *id_param = NULL, _0, _1;
	zend_long handle, child, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&id);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &child_param, &id_param);
	zephir_get_strval(&id, id_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	r = phpgtk_gtkpopovermenu_add_child(&_0, &_1, &id);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getFlags)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpopovermenu_get_flags(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getMenuModel)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpopovermenu_get_menu_model(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, removeChild)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	r = phpgtk_gtkpopovermenu_remove_child(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setFlags)
{
	zval *handle_param = NULL, *flags_param = NULL, _0, _1;
	zend_long handle, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &flags_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, flags);
	phpgtk_gtkpopovermenu_set_flags(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setMenuModel)
{
	zval *handle_param = NULL, *model_param = NULL, _0, _1;
	zend_long handle, model;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &model_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, model);
	phpgtk_gtkpopovermenu_set_menu_model(&_0, &_1);
}

