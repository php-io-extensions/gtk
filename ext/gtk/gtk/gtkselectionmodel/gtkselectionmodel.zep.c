
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
#include "src/gtk-selection-model.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSelectionModel, GtkSelectionModel, gtk_gtk, gtkselectionmodel_gtkselectionmodel, gtk_gtk_gtkselectionmodel_gtkselectionmodel_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, isSelected)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	r = phpgtk_gtkselectionmodel_is_selected(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkselectionmodel_select_all(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectItem)
{
	zend_bool unselectRest;
	zval *handle_param = NULL, *position_param = NULL, *unselectRest_param = NULL, _0, _1, _2;
	zend_long handle, position, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_BOOL(unselectRest)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &unselectRest_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_BOOL(&_2, (unselectRest ? 1 : 0));
	r = phpgtk_gtkselectionmodel_select_item(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectRange)
{
	zend_bool unselectRest;
	zval *handle_param = NULL, *position_param = NULL, *nItems_param = NULL, *unselectRest_param = NULL, _0, _1, _2, _3;
	zend_long handle, position, nItems, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nItems)
		Z_PARAM_BOOL(unselectRest)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &position_param, &nItems_param, &unselectRest_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nItems);
	ZVAL_BOOL(&_3, (unselectRest ? 1 : 0));
	r = phpgtk_gtkselectionmodel_select_range(&_0, &_1, &_2, &_3);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectionChanged)
{
	zval *handle_param = NULL, *position_param = NULL, *nItems_param = NULL, _0, _1, _2;
	zend_long handle, position, nItems;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nItems)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &nItems_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nItems);
	phpgtk_gtkselectionmodel_selection_changed(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectAll)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkselectionmodel_unselect_all(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectItem)
{
	zval *handle_param = NULL, *position_param = NULL, _0, _1;
	zend_long handle, position, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	r = phpgtk_gtkselectionmodel_unselect_item(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectRange)
{
	zval *handle_param = NULL, *position_param = NULL, *nItems_param = NULL, _0, _1, _2;
	zend_long handle, position, nItems, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(nItems)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &position_param, &nItems_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, position);
	ZVAL_LONG(&_2, nItems);
	r = phpgtk_gtkselectionmodel_unselect_range(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

