
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
#include "src/gtk-separator.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSeparator_GtkSeparator)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSeparator, GtkSeparator, gtk_gtk, gtkseparator_gtkseparator, gtk_gtk_gtkseparator_gtkseparator_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSeparator_GtkSeparator, new_)
{
	zval *orientation_param = NULL, _0;
	zend_long orientation;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &orientation_param);
	ZVAL_LONG(&_0, orientation);
	RETURN_LONG(phpgtk_gtkseparator_new(&_0));
}

