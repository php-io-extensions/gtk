
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



ZEPHIR_INIT_CLASS(Gtk_GTK_TextView_GtkTextView)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\TextView, GtkTextView, gtk, gtk_textview_gtktextview, gtk_gtk_textview_gtktextview_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewNew)
{
	zend_long handle = 0;
	
            GtkWidget *view;

            php_gtk_set_last_error(NULL);
            view = gtk_text_view_new();
            if (view == NULL) {
                php_gtk_set_last_error("gtk_text_view_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) view;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetBuffer)
{
	zval *view_param = NULL;
	zend_long view, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(view)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &view_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf = NULL;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
            }
            handle = (zend_long)(uintptr_t) buf;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *view_param = NULL, *text_param = NULL;
	zend_long view;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(view)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &view_param, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
                if (buf != NULL) {
                    gtk_text_buffer_set_text(buf, Z_STRVAL(text), -1);
                }
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetText)
{
	zval result;
	zval *view_param = NULL;
	zend_long view;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(view)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &view_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf = NULL;
            GtkTextIter start;
            GtkTextIter end;
            char *text = NULL;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
            }
            if (buf != NULL) {
                gtk_text_buffer_get_bounds(buf, &start, &end);
                text = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
            }
            ZVAL_STRING(&result, text ? text : "");
            if (text != NULL) {
                g_free(text);
            }
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetEditable)
{
	zend_bool editable;
	zval *view_param = NULL, *editable_param = NULL;
	zend_long view;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(view)
		Z_PARAM_BOOL(editable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &view_param, &editable_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            if (tv != NULL) {
                gtk_text_view_set_editable(tv, editable ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetEditable)
{
	zend_bool editable = 0;
	zval *view_param = NULL;
	zend_long view;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(view)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &view_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            editable = (tv != NULL && gtk_text_view_get_editable(tv)) ? true : false;
        
	RETURN_BOOL(editable);
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetWrapMode)
{
	zval *view_param = NULL, *wrapMode_param = NULL;
	zend_long view, wrapMode;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(view)
		Z_PARAM_LONG(wrapMode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &view_param, &wrapMode_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            if (tv != NULL) {
                gtk_text_view_set_wrap_mode(tv, (GtkWrapMode) wrapMode);
            }
        
}

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetWrapMode)
{
	zval *view_param = NULL;
	zend_long view, wrapMode = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(view)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &view_param);
	
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            wrapMode = tv != NULL ? (zend_long) gtk_text_view_get_wrap_mode(tv) : 0;
        
	RETURN_LONG(wrapMode);
}

