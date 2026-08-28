
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
#include "src/gtk-text-tag-table.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkTextTagTable, GtkTextTagTable, gtk_gtk, gtktexttagtable_gtktexttagtable, gtk_gtk_gtktexttagtable_gtktexttagtable_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, new_)
{

	RETURN_LONG(phpgtk_gtktexttagtable_new());
}

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, add)
{
	zval *handle_param = NULL, *tag_param = NULL, _0, _1;
	zend_long handle, tag, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &tag_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, tag);
	r = phpgtk_gtktexttagtable_add(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, getSize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktexttagtable_get_size(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, lookup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_gtktexttagtable_lookup(&_0, &name));
}

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, remove)
{
	zval *handle_param = NULL, *tag_param = NULL, _0, _1;
	zend_long handle, tag;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &tag_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, tag);
	phpgtk_gtktexttagtable_remove(&_0, &_1);
}

