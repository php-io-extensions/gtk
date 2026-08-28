
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
#include "src/gtk-password-entry.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkPasswordEntry, GtkPasswordEntry, gtk_gtk, gtkpasswordentry_gtkpasswordentry, gtk_gtk_gtkpasswordentry_gtkpasswordentry_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, new_)
{

	RETURN_LONG(phpgtk_gtkpasswordentry_new());
}

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getExtraMenu)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpasswordentry_get_extra_menu(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getShowPeekIcon)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpasswordentry_get_show_peek_icon(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setExtraMenu)
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
	phpgtk_gtkpasswordentry_set_extra_menu(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setShowPeekIcon)
{
	zend_bool showPeekIcon;
	zval *handle_param = NULL, *showPeekIcon_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showPeekIcon)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showPeekIcon_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showPeekIcon ? 1 : 0));
	phpgtk_gtkpasswordentry_set_show_peek_icon(&_0, &_1);
}

