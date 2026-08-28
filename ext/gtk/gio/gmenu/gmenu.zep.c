
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
#include "src/gio-gmenu.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GMenu_GMenu)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GMenu, GMenu, gtk, gio_gmenu_gmenu, gtk_gio_gmenu_gmenu_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, new_)
{

	RETURN_LONG(phpgtk_gmenu_new());
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, append)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *detailedAction = NULL, detailedAction_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&detailedAction_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_ZVAL(detailedAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &detailedAction);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenu_append(&_0, label, detailedAction);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendItem)
{
	zval *handle_param = NULL, *item_param = NULL, _0, _1;
	zend_long handle, item;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &item_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, item);
	phpgtk_gmenu_append_item(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendSection)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *section_param = NULL, _0, _1;
	zend_long handle, section;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(section)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &section_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, section);
	phpgtk_gmenu_append_section(&_0, label, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendSubmenu)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *submenu_param = NULL, _0, _1;
	zend_long handle, submenu;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(submenu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &submenu_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, submenu);
	phpgtk_gmenu_append_submenu(&_0, label, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, freeze)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenu_freeze(&_0);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, insert)
{
	zval *handle_param = NULL, *position_param = NULL, *label = NULL, label_sub, *detailedAction = NULL, detailedAction_sub, _0, _1;
	zend_long handle, position;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&detailedAction_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_ZVAL(label)
		Z_PARAM_ZVAL(detailedAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &label, &detailedAction);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	phpgtk_gmenu_insert(&_0, &_1, label, detailedAction);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertItem)
{
	zval *handle_param = NULL, *position_param = NULL, *item_param = NULL, _0, _1, _2;
	zend_long handle, position, item;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &item_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, item);
	phpgtk_gmenu_insert_item(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertSection)
{
	zval *handle_param = NULL, *position_param = NULL, *label = NULL, label_sub, *section_param = NULL, _0, _1, _2;
	zend_long handle, position, section;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(section)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &label, &section_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, section);
	phpgtk_gmenu_insert_section(&_0, &_1, label, &_2);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertSubmenu)
{
	zval *handle_param = NULL, *position_param = NULL, *label = NULL, label_sub, *submenu_param = NULL, _0, _1, _2;
	zend_long handle, position, submenu;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(submenu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &label, &submenu_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, submenu);
	phpgtk_gmenu_insert_submenu(&_0, &_1, label, &_2);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, prepend)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *detailedAction = NULL, detailedAction_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&detailedAction_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_ZVAL(detailedAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &detailedAction);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenu_prepend(&_0, label, detailedAction);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependItem)
{
	zval *handle_param = NULL, *item_param = NULL, _0, _1;
	zend_long handle, item;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &item_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, item);
	phpgtk_gmenu_prepend_item(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependSection)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *section_param = NULL, _0, _1;
	zend_long handle, section;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(section)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &section_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, section);
	phpgtk_gmenu_prepend_section(&_0, label, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependSubmenu)
{
	zval *handle_param = NULL, *label = NULL, label_sub, *submenu_param = NULL, _0, _1;
	zend_long handle, submenu;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(submenu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &label, &submenu_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, submenu);
	phpgtk_gmenu_prepend_submenu(&_0, label, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, remove)
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
	phpgtk_gmenu_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GMenu_GMenu, removeAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenu_remove_all(&_0);
}

