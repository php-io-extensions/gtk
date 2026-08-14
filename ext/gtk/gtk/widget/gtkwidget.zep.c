
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
extern gboolean php_gtk_tick_bridge(GtkWidget *widget, GdkFrameClock *clock, gpointer data);
extern void php_gtk_tick_dtor(gpointer data);



/**
 * GtkWidget — visibility, expand, size request, queue draw.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Widget_GtkWidget)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Widget, GtkWidget, gtk, gtk_widget_gtkwidget, gtk_gtk_widget_gtkwidget_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVisible)
{
	zend_bool visible;
	zval *widget_param = NULL, *visible_param = NULL;
	zend_long widget;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &visible_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_visible(w, visible ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetVisible)
{
	zend_bool visible = 0;
	zval *widget_param = NULL;
	zend_long widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            visible = (w != NULL && gtk_widget_get_visible(w)) ? true : false;
        
	RETURN_BOOL(visible);
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHexpand)
{
	zend_bool expand;
	zval *widget_param = NULL, *expand_param = NULL;
	zend_long widget;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &expand_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_hexpand(w, expand ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVexpand)
{
	zend_bool expand;
	zval *widget_param = NULL, *expand_param = NULL;
	zend_long widget;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &expand_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_vexpand(w, expand ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHalign)
{
	zval *widget_param = NULL, *align_param = NULL;
	zend_long widget, align;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &align_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_halign(w, (GtkAlign) align);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetValign)
{
	zval *widget_param = NULL, *align_param = NULL;
	zend_long widget, align;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_LONG(align)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &align_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_valign(w, (GtkAlign) align);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHalign)
{
	zval *widget_param = NULL;
	zend_long widget, align = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            align = w != NULL ? (zend_long) gtk_widget_get_halign(w) : 0;
        
	RETURN_LONG(align);
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetValign)
{
	zval *widget_param = NULL;
	zend_long widget, align = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            align = w != NULL ? (zend_long) gtk_widget_get_valign(w) : 0;
        
	RETURN_LONG(align);
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetSizeRequest)
{
	zval *widget_param = NULL, *width_param = NULL, *height_param = NULL;
	zend_long widget, width, height;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(widget)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &widget_param, &width_param, &height_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_size_request(w, (int) width, (int) height);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetWidth)
{
	zval *widget_param = NULL;
	zend_long widget, width = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            width = w != NULL ? (zend_long) gtk_widget_get_width(w) : 0;
        
	RETURN_LONG(width);
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHeight)
{
	zval *widget_param = NULL;
	zend_long widget, height = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            height = w != NULL ? (zend_long) gtk_widget_get_height(w) : 0;
        
	RETURN_LONG(height);
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetQueueDraw)
{
	zval *widget_param = NULL;
	zend_long widget;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(widget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &widget_param);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_queue_draw(w);
            }
        
}

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetAddTickCallback)
{
	zval *widget_param = NULL, *callback, callback_sub;
	zend_long widget, handlerId = 0;

	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(widget)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &widget_param, &callback);
	
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            zval *cb;
            php_gtk_set_last_error(NULL);
            handlerId = 0;
            if (w == NULL) {
                php_gtk_set_last_error("gtkWidgetAddTickCallback: widget handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkWidgetAddTickCallback: callback is not callable");
            } else {
                cb = (zval *) emalloc(sizeof(zval));
                ZVAL_COPY(cb, callback);
                handlerId = (zend_long) gtk_widget_add_tick_callback(w, php_gtk_tick_bridge, cb, php_gtk_tick_dtor);
            }
        
	RETURN_LONG(handlerId);
}

