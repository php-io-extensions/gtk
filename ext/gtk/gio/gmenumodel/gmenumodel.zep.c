
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
#include "src/gio-gmenumodel.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GMenuModel_GMenuModel)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GMenuModel, GMenuModel, gtk, gio_gmenumodel_gmenumodel, gtk_gio_gmenumodel_gmenumodel_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, getItemLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval link;
	zval *handle_param = NULL, *itemIndex_param = NULL, *link_param = NULL, _0, _1;
	zend_long handle, itemIndex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&link);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(itemIndex)
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &itemIndex_param, &link_param);
	zephir_get_strval(&link, link_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, itemIndex);
	RETURN_MM_LONG(phpgtk_gmenumodel_get_item_link(&_0, &_1, &link));
}

PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, getNItems)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gmenumodel_get_n_items(&_0));
}

PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, isMutable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gmenumodel_is_mutable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, itemsChanged)
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
	phpgtk_gmenumodel_items_changed(&_0, &_1, &_2, &_3);
}

