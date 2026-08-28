
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
#include "src/gtk-text-tag.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextTag_GtkTextTag)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkTextTag, GtkTextTag, gtk_gtk, gtktexttag_gtktexttag, gtk_gtk_gtktexttag_gtktexttag_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, new_)
{
	zval *name = NULL, name_sub;

	ZVAL_UNDEF(&name_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &name);
	RETURN_LONG(phpgtk_gtktexttag_new(name));
}

PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, changed)
{
	zend_bool sizeChanged;
	zval *handle_param = NULL, *sizeChanged_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(sizeChanged)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &sizeChanged_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (sizeChanged ? 1 : 0));
	phpgtk_gtktexttag_changed(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, getPriority)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktexttag_get_priority(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, setPriority)
{
	zval *handle_param = NULL, *priority_param = NULL, _0, _1;
	zend_long handle, priority;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &priority_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, priority);
	phpgtk_gtktexttag_set_priority(&_0, &_1);
}

