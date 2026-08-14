
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
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);



ZEPHIR_INIT_CLASS(Gtk_GTK_DropDown_GtkDropDown)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\DropDown, GtkDropDown, gtk, gtk_dropdown_gtkdropdown, gtk_gtk_dropdown_gtkdropdown_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownNewFromStrings)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *labels_param = NULL;
	zval labels;

	ZVAL_UNDEF(&labels);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(labels, labels_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &labels_param);
	zephir_get_arrval(&labels, labels_param);
	
            GtkWidget *drop;
            char **strv;

            php_gtk_set_last_error(NULL);
            strv = php_gtk_zval_to_strv(&labels);
            drop = gtk_drop_down_new_from_strings((const char * const *) strv);
            php_gtk_strv_free(strv);
            if (drop == NULL) {
                php_gtk_set_last_error("gtk_drop_down_new_from_strings returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) drop;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownSetSelected)
{
	zval *drop_param = NULL, *selected_param = NULL;
	zend_long drop, selected;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(drop)
		Z_PARAM_LONG(selected)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &drop_param, &selected_param);
	
            GtkDropDown *dd = GTK_DROP_DOWN((void *)(uintptr_t) drop);
            if (dd != NULL) {
                gtk_drop_down_set_selected(dd, (guint) selected);
            }
        
}

PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownGetSelected)
{
	zval *drop_param = NULL;
	zend_long drop, selected = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(drop)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &drop_param);
	
            GtkDropDown *dd = GTK_DROP_DOWN((void *)(uintptr_t) drop);
            selected = dd != NULL ? (zend_long) gtk_drop_down_get_selected(dd) : 0;
        
	RETURN_LONG(selected);
}

