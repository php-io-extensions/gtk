
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



/**
 * GtkLabel — new, text get/set.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Label_GtkLabel)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Label, GtkLabel, gtk, gtk_label_gtklabel, gtk_gtk_label_gtklabel_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelNew)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *text_param = NULL;
	zval text;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkWidget *label;

            php_gtk_set_last_error(NULL);
            label = gtk_label_new(Z_STRVAL(text));
            if (label == NULL) {
                php_gtk_set_last_error("gtk_label_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) label;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelSetText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *label_param = NULL, *text_param = NULL;
	zend_long label;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(label)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &label_param, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkLabel *lbl = GTK_LABEL((void *)(uintptr_t) label);
            if (lbl != NULL) {
                gtk_label_set_text(lbl, Z_STRVAL(text));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelGetText)
{
	zval result;
	zval *label_param = NULL;
	zend_long label;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &label_param);
	
            GtkLabel *lbl = GTK_LABEL((void *)(uintptr_t) label);
            const char *text = NULL;
            if (lbl != NULL) {
                text = gtk_label_get_text(lbl);
            }
            ZVAL_STRING(&result, text ? text : "");
        
	RETURN_CTORW(&result);
}

