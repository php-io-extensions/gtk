
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
#include "src/gio-glistmodel.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GListModel_GListModel)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GListModel, GListModel, gtk, gio_glistmodel_glistmodel, gtk_gio_glistmodel_glistmodel_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GListModel_GListModel, getItem)
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
	RETURN_LONG(phpgtk_glistmodel_get_item(&_0, &_1));
}

PHP_METHOD(Gtk_Gio_GListModel_GListModel, getItemType)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_glistmodel_get_item_type(&_0));
}

PHP_METHOD(Gtk_Gio_GListModel_GListModel, getNItems)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_glistmodel_get_n_items(&_0));
}

PHP_METHOD(Gtk_Gio_GListModel_GListModel, getObject)
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
	RETURN_LONG(phpgtk_glistmodel_get_object(&_0, &_1));
}

PHP_METHOD(Gtk_Gio_GListModel_GListModel, itemsChanged)
{
	zval *handle_param = NULL, *position_param = NULL, *removed_param = NULL, *added_param = NULL, _0, _1, _2, _3;
	zend_long handle, position, removed, added;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(removed)
		Z_PARAM_LONG(added)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &removed_param, &added_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, removed);
	ZVAL_LONG(&_3, added);
	phpgtk_glistmodel_items_changed(&_0, &_1, &_2, &_3);
}

