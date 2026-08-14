
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



ZEPHIR_INIT_CLASS(Gtk_GTK_HeaderBar_GtkHeaderBar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\HeaderBar, GtkHeaderBar, gtk, gtk_headerbar_gtkheaderbar, gtk_gtk_headerbar_gtkheaderbar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarNew)
{
	zend_long handle = 0;
	
            GtkWidget *bar;

            php_gtk_set_last_error(NULL);
            bar = gtk_header_bar_new();
            if (bar == NULL) {
                php_gtk_set_last_error("gtk_header_bar_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) bar;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetTitleWidget)
{
	zval *bar_param = NULL, *titleWidget_param = NULL;
	zend_long bar, titleWidget;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_LONG(titleWidget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &titleWidget_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) titleWidget);
            if (hb != NULL) {
                gtk_header_bar_set_title_widget(hb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetTitleWidget)
{
	zval *bar_param = NULL;
	zend_long bar, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &bar_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = NULL;
            if (hb != NULL) {
                widget = gtk_header_bar_get_title_widget(hb);
            }
            handle = (zend_long)(uintptr_t) widget;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackStart)
{
	zval *bar_param = NULL, *child_param = NULL;
	zend_long bar, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &child_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_pack_start(hb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackEnd)
{
	zval *bar_param = NULL, *child_param = NULL;
	zend_long bar, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &child_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_pack_end(hb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarRemove)
{
	zval *bar_param = NULL, *child_param = NULL;
	zend_long bar, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &child_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_remove(hb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetShowTitleButtons)
{
	zend_bool show;
	zval *bar_param = NULL, *show_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_BOOL(show)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &show_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            if (hb != NULL) {
                gtk_header_bar_set_show_title_buttons(hb, show ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetShowTitleButtons)
{
	zend_bool show = 0;
	zval *bar_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &bar_param);
	
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            show = (hb != NULL && gtk_header_bar_get_show_title_buttons(hb)) ? true : false;
        
	RETURN_BOOL(show);
}

