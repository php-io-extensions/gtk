
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);



ZEPHIR_INIT_CLASS(Gtk_GTK_Separator_GtkSeparator)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Separator, GtkSeparator, gtk, gtk_separator_gtkseparator, gtk_gtk_separator_gtkseparator_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Separator_GtkSeparator, gtkSeparatorNew)
{
	zval *orientation_param = NULL;
	zend_long orientation, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &orientation_param);
	
            GtkWidget *sep;

            php_gtk_set_last_error(NULL);
            sep = gtk_separator_new((GtkOrientation) orientation);
            if (sep == NULL) {
                php_gtk_set_last_error("gtk_separator_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sep;
            }
        
	RETURN_LONG(handle);
}

