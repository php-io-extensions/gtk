
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Popover_GtkPopover)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Popover, GtkPopover, gtk, gtk_popover_gtkpopover, gtk_gtk_popover_gtkpopover_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverNew)
{
	zend_long handle = 0;
	
            GtkWidget *pop;

            php_gtk_set_last_error(NULL);
            pop = gtk_popover_new();
            if (pop == NULL) {
                php_gtk_set_last_error("gtk_popover_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) pop;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetChild)
{
	zval *popover_param = NULL, *child_param = NULL;
	zend_long popover, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(popover)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &popover_param, &child_param);
	
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pop != NULL) {
                gtk_popover_set_child(pop, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverGetChild)
{
	zval *popover_param = NULL;
	zend_long popover, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(popover)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &popover_param);
	
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            GtkWidget *child = NULL;
            if (pop != NULL) {
                child = gtk_popover_get_child(pop);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopup)
{
	zval *popover_param = NULL;
	zend_long popover;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(popover)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &popover_param);
	
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_popup(pop);
            }
        
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopdown)
{
	zval *popover_param = NULL;
	zend_long popover;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(popover)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &popover_param);
	
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_popdown(pop);
            }
        
}

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetAutohide)
{
	zend_bool autohide;
	zval *popover_param = NULL, *autohide_param = NULL;
	zend_long popover;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(popover)
		Z_PARAM_BOOL(autohide)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &popover_param, &autohide_param);
	
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_set_autohide(pop, autohide ? TRUE : FALSE);
            }
        
}

