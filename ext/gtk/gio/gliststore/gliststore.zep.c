
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
#include "src/gio-gliststore.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GListStore_GListStore)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GListStore, GListStore, gtk, gio_gliststore_gliststore, gtk_gio_gliststore_gliststore_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, new_)
{
	zval *itemType_param = NULL, _0;
	zend_long itemType;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(itemType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &itemType_param);
	ZVAL_LONG(&_0, itemType);
	RETURN_LONG(phpgtk_gliststore_new(&_0));
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, append)
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
	phpgtk_gliststore_append(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, find)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *item_param = NULL, result, _0, _1;
	zend_long handle, item;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &item_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, item);
	phpgtk_gliststore_find(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, insert)
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
	phpgtk_gliststore_insert(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, remove)
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
	phpgtk_gliststore_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, removeAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gliststore_remove_all(&_0);
}

PHP_METHOD(Gtk_Gio_GListStore_GListStore, splice)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval additions;
	zval *handle_param = NULL, *position_param = NULL, *nRemovals_param = NULL, *additions_param = NULL, *nAdditions_param = NULL, _0, _1, _2, _3;
	zend_long handle, position, nRemovals, nAdditions;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&additions);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nRemovals)
		Z_PARAM_ARRAY(additions)
		Z_PARAM_LONG(nAdditions)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 5, 0, &handle_param, &position_param, &nRemovals_param, &additions_param, &nAdditions_param);
	zephir_get_arrval(&additions, additions_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nRemovals);
	ZVAL_LONG(&_3, nAdditions);
	phpgtk_gliststore_splice(&_0, &_1, &_2, &additions, &_3);
	ZEPHIR_MM_RESTORE();
}

