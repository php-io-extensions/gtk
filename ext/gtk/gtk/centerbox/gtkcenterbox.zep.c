
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



ZEPHIR_INIT_CLASS(Gtk_GTK_CenterBox_GtkCenterBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\CenterBox, GtkCenterBox, gtk, gtk_centerbox_gtkcenterbox, gtk_gtk_centerbox_gtkcenterbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxNew)
{
	zend_long handle = 0;
	
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_center_box_new();
            if (box == NULL) {
                php_gtk_set_last_error("gtk_center_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetStartWidget)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_start_widget(cb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetCenterWidget)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_center_widget(cb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetEndWidget)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_end_widget(cb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetStartWidget)
{
	zval *box_param = NULL;
	zend_long box, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(box)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &box_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_start_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetCenterWidget)
{
	zval *box_param = NULL;
	zend_long box, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(box)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &box_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_center_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetEndWidget)
{
	zval *box_param = NULL;
	zend_long box, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(box)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &box_param);
	
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_end_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

