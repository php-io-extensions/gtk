
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);



ZEPHIR_INIT_CLASS(Gtk_GTK_Spinner_GtkSpinner)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Spinner, GtkSpinner, gtk, gtk_spinner_gtkspinner, gtk_gtk_spinner_gtkspinner_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerNew)
{
	zend_long handle = 0;
	
            GtkWidget *spinner;

            php_gtk_set_last_error(NULL);
            spinner = gtk_spinner_new();
            if (spinner == NULL) {
                php_gtk_set_last_error("gtk_spinner_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) spinner;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStart)
{
	zval *spinner_param = NULL;
	zend_long spinner;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spinner)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &spinner_param);
	
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_start(sp);
            }
        
}

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStop)
{
	zval *spinner_param = NULL;
	zend_long spinner;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spinner)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &spinner_param);
	
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_stop(sp);
            }
        
}

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerSetSpinning)
{
	zend_bool spinning;
	zval *spinner_param = NULL, *spinning_param = NULL;
	zend_long spinner;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(spinner)
		Z_PARAM_BOOL(spinning)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &spinner_param, &spinning_param);
	
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_set_spinning(sp, spinning ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerGetSpinning)
{
	zend_bool spinning = 0;
	zval *spinner_param = NULL;
	zend_long spinner;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spinner)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &spinner_param);
	
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            spinning = (sp != NULL && gtk_spinner_get_spinning(sp)) ? true : false;
        
	RETURN_BOOL(spinning);
}

