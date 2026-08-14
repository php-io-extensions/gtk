
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



/**
 * GtkSwitch — new, active get/set.
 * Namespace is GtkSwitch (not Switch) because switch is a PHP reserved word.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_GtkSwitch_GtkSwitch)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\GtkSwitch, GtkSwitch, gtk, gtk_gtkswitch_gtkswitch, gtk_gtk_gtkswitch_gtkswitch_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchNew)
{
	zend_long handle = 0;
	
            GtkWidget *sw;

            php_gtk_set_last_error(NULL);
            sw = gtk_switch_new();
            if (sw == NULL) {
                php_gtk_set_last_error("gtk_switch_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sw;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchSetActive)
{
	zend_bool active;
	zval *sw_param = NULL, *active_param = NULL;
	zend_long sw;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(sw)
		Z_PARAM_BOOL(active)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &sw_param, &active_param);
	
            GtkSwitch *widget = GTK_SWITCH((void *)(uintptr_t) sw);
            if (widget != NULL) {
                gtk_switch_set_active(widget, active ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchGetActive)
{
	zend_bool active = 0;
	zval *sw_param = NULL;
	zend_long sw;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(sw)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &sw_param);
	
            GtkSwitch *widget = GTK_SWITCH((void *)(uintptr_t) sw);
            active = (widget != NULL && gtk_switch_get_active(widget)) ? true : false;
        
	RETURN_BOOL(active);
}

