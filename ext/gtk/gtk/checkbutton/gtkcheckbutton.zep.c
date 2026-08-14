
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
 * GtkCheckButton — new, label get/set, active get/set.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_CheckButton_GtkCheckButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\CheckButton, GtkCheckButton, gtk, gtk_checkbutton_gtkcheckbutton, gtk_gtk_checkbutton_gtkcheckbutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNew)
{
	zend_long handle = 0;
	
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_check_button_new();
            if (button == NULL) {
                php_gtk_set_last_error("gtk_check_button_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNewWithLabel)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *label_param = NULL;
	zval label;

	ZVAL_UNDEF(&label);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(label_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &label_param);
	zephir_get_strval(&label, label_param);
	
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_check_button_new_with_label(Z_STRVAL(label));
            if (button == NULL) {
                php_gtk_set_last_error("gtk_check_button_new_with_label returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetLabel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval label;
	zval *button_param = NULL, *label_param = NULL;
	zend_long button;

	ZVAL_UNDEF(&label);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(button)
		Z_PARAM_ZVAL(label_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &button_param, &label_param);
	zephir_get_strval(&label, label_param);
	
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            if (btn != NULL) {
                gtk_check_button_set_label(btn, Z_STRVAL(label));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetLabel)
{
	zval result;
	zval *button_param = NULL;
	zend_long button;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            const char *label = NULL;
            if (btn != NULL) {
                label = gtk_check_button_get_label(btn);
            }
            ZVAL_STRING(&result, label ? label : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetActive)
{
	zend_bool active;
	zval *button_param = NULL, *active_param = NULL;
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(button)
		Z_PARAM_BOOL(active)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &button_param, &active_param);
	
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            if (btn != NULL) {
                gtk_check_button_set_active(btn, active ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetActive)
{
	zend_bool active = 0;
	zval *button_param = NULL;
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            active = (btn != NULL && gtk_check_button_get_active(btn)) ? true : false;
        
	RETURN_BOOL(active);
}

