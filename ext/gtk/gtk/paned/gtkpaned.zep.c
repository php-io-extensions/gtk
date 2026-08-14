
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Paned_GtkPaned)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Paned, GtkPaned, gtk, gtk_paned_gtkpaned, gtk_gtk_paned_gtkpaned_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedNew)
{
	zval *orientation_param = NULL;
	zend_long orientation, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(orientation)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &orientation_param);
	
            GtkWidget *paned;

            php_gtk_set_last_error(NULL);
            paned = gtk_paned_new((GtkOrientation) orientation);
            if (paned == NULL) {
                php_gtk_set_last_error("gtk_paned_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) paned;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetStartChild)
{
	zval *paned_param = NULL, *child_param = NULL;
	zend_long paned, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(paned)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &paned_param, &child_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pn != NULL) {
                gtk_paned_set_start_child(pn, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetEndChild)
{
	zval *paned_param = NULL, *child_param = NULL;
	zend_long paned, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(paned)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &paned_param, &child_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pn != NULL) {
                gtk_paned_set_end_child(pn, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetStartChild)
{
	zval *paned_param = NULL;
	zend_long paned, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paned)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paned_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *child = NULL;
            if (pn != NULL) {
                child = gtk_paned_get_start_child(pn);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetEndChild)
{
	zval *paned_param = NULL;
	zend_long paned, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paned)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paned_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *child = NULL;
            if (pn != NULL) {
                child = gtk_paned_get_end_child(pn);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetPosition)
{
	zval *paned_param = NULL, *position_param = NULL;
	zend_long paned, position;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(paned)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &paned_param, &position_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            if (pn != NULL) {
                gtk_paned_set_position(pn, (int) position);
            }
        
}

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetPosition)
{
	zval *paned_param = NULL;
	zend_long paned, position = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paned)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paned_param);
	
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            position = pn != NULL ? (zend_long) gtk_paned_get_position(pn) : 0;
        
	RETURN_LONG(position);
}

