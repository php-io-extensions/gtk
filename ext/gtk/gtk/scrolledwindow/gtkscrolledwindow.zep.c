
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



ZEPHIR_INIT_CLASS(Gtk_GTK_ScrolledWindow_GtkScrolledWindow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ScrolledWindow, GtkScrolledWindow, gtk, gtk_scrolledwindow_gtkscrolledwindow, gtk_gtk_scrolledwindow_gtkscrolledwindow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowNew)
{
	zend_long handle = 0;
	
            GtkWidget *sw;

            php_gtk_set_last_error(NULL);
            sw = gtk_scrolled_window_new();
            if (sw == NULL) {
                php_gtk_set_last_error("gtk_scrolled_window_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sw;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowSetChild)
{
	zval *scrolled_param = NULL, *child_param = NULL;
	zend_long scrolled, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scrolled)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scrolled_param, &child_param);
	
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (sw != NULL) {
                gtk_scrolled_window_set_child(sw, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowGetChild)
{
	zval *scrolled_param = NULL;
	zend_long scrolled, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(scrolled)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &scrolled_param);
	
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            GtkWidget *child = NULL;
            if (sw != NULL) {
                child = gtk_scrolled_window_get_child(sw);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowSetPolicy)
{
	zval *scrolled_param = NULL, *hscrollbar_param = NULL, *vscrollbar_param = NULL;
	zend_long scrolled, hscrollbar, vscrollbar;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(scrolled)
		Z_PARAM_LONG(hscrollbar)
		Z_PARAM_LONG(vscrollbar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &scrolled_param, &hscrollbar_param, &vscrollbar_param);
	
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_policy(sw, (GtkPolicyType) hscrollbar, (GtkPolicyType) vscrollbar);
            }
        
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowSetMinContentHeight)
{
	zval *scrolled_param = NULL, *height_param = NULL;
	zend_long scrolled, height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scrolled)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scrolled_param, &height_param);
	
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_min_content_height(sw, (int) height);
            }
        
}

PHP_METHOD(Gtk_GTK_ScrolledWindow_GtkScrolledWindow, gtkScrolledWindowSetMinContentWidth)
{
	zval *scrolled_param = NULL, *width_param = NULL;
	zend_long scrolled, width;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scrolled)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scrolled_param, &width_param);
	
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_min_content_width(sw, (int) width);
            }
        
}

