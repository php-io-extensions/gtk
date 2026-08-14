
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



ZEPHIR_INIT_CLASS(Gtk_GTK_PasswordEntry_GtkPasswordEntry)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\PasswordEntry, GtkPasswordEntry, gtk, gtk_passwordentry_gtkpasswordentry, gtk_gtk_passwordentry_gtkpasswordentry_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_PasswordEntry_GtkPasswordEntry, gtkPasswordEntryNew)
{
	zend_long handle = 0;
	
            GtkWidget *entry;

            php_gtk_set_last_error(NULL);
            entry = gtk_password_entry_new();
            if (entry == NULL) {
                php_gtk_set_last_error("gtk_password_entry_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) entry;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_PasswordEntry_GtkPasswordEntry, gtkPasswordEntrySetText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *entry_param = NULL, *text_param = NULL;
	zend_long entry;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(entry)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &entry_param, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            if (editable != NULL) {
                gtk_editable_set_text(editable, Z_STRVAL(text));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_PasswordEntry_GtkPasswordEntry, gtkPasswordEntryGetText)
{
	zval result;
	zval *entry_param = NULL;
	zend_long entry;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(entry)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &entry_param);
	
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            const char *text = NULL;
            if (editable != NULL) {
                text = gtk_editable_get_text(editable);
            }
            ZVAL_STRING(&result, text ? text : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_PasswordEntry_GtkPasswordEntry, gtkPasswordEntrySetShowPeekIcon)
{
	zend_bool showPeek;
	zval *entry_param = NULL, *showPeek_param = NULL;
	zend_long entry;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(entry)
		Z_PARAM_BOOL(showPeek)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &entry_param, &showPeek_param);
	
            GtkPasswordEntry *pe = GTK_PASSWORD_ENTRY((void *)(uintptr_t) entry);
            if (pe != NULL) {
                gtk_password_entry_set_show_peek_icon(pe, showPeek ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_PasswordEntry_GtkPasswordEntry, gtkPasswordEntryGetShowPeekIcon)
{
	zend_bool showPeek = 0;
	zval *entry_param = NULL;
	zend_long entry;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(entry)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &entry_param);
	
            GtkPasswordEntry *pe = GTK_PASSWORD_ENTRY((void *)(uintptr_t) entry);
            showPeek = (pe != NULL && gtk_password_entry_get_show_peek_icon(pe)) ? true : false;
        
	RETURN_BOOL(showPeek);
}

