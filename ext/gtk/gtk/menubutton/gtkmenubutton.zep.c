
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



ZEPHIR_INIT_CLASS(Gtk_GTK_MenuButton_GtkMenuButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\MenuButton, GtkMenuButton, gtk, gtk_menubutton_gtkmenubutton, gtk_gtk_menubutton_gtkmenubutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonNew)
{
	zend_long handle = 0;
	
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_menu_button_new();
            if (button == NULL) {
                php_gtk_set_last_error("gtk_menu_button_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetLabel)
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
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_set_label(mb, Z_STRVAL(label));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetLabel)
{
	zval result;
	zval *button_param = NULL;
	zend_long button;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            const char *label = NULL;
            if (mb != NULL) {
                label = gtk_menu_button_get_label(mb);
            }
            ZVAL_STRING(&result, label ? label : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetPopover)
{
	zval *button_param = NULL, *popover_param = NULL;
	zend_long button, popover;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(button)
		Z_PARAM_LONG(popover)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &button_param, &popover_param);
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            GtkWidget *pop = GTK_WIDGET((void *)(uintptr_t) popover);
            if (mb != NULL) {
                gtk_menu_button_set_popover(mb, pop);
            }
        
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetPopover)
{
	zval *button_param = NULL;
	zend_long button, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            GtkPopover *pop = NULL;
            if (mb != NULL) {
                pop = gtk_menu_button_get_popover(mb);
            }
            handle = (zend_long)(uintptr_t) pop;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopup)
{
	zval *button_param = NULL;
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_popup(mb);
            }
        
}

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopdown)
{
	zval *button_param = NULL;
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &button_param);
	
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_popdown(mb);
            }
        
}

