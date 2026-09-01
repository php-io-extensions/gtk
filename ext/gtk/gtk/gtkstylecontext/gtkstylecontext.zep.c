
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
#include "src/gtk-style-context.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStyleContext_GtkStyleContext)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkStyleContext, GtkStyleContext, gtk_gtk, gtkstylecontext_gtkstylecontext, gtk_gtk_gtkstylecontext_gtkstylecontext_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkStyleContext_GtkStyleContext, addProviderForDisplay)
{
	zval *display_param = NULL, *provider_param = NULL, *priority_param = NULL, _0, _1, _2;
	zend_long display, provider, priority;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(display)
		Z_PARAM_LONG(provider)
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &display_param, &provider_param, &priority_param);
	ZVAL_LONG(&_0, display);
	ZVAL_LONG(&_1, provider);
	ZVAL_LONG(&_2, priority);
	phpgtk_stylecontext_add_provider_for_display(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkStyleContext_GtkStyleContext, removeProviderForDisplay)
{
	zval *display_param = NULL, *provider_param = NULL, _0, _1;
	zend_long display, provider;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(display)
		Z_PARAM_LONG(provider)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &display_param, &provider_param);
	ZVAL_LONG(&_0, display);
	ZVAL_LONG(&_1, provider);
	phpgtk_stylecontext_remove_provider_for_display(&_0, &_1);
}

