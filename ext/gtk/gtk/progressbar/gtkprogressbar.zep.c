
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



ZEPHIR_INIT_CLASS(Gtk_GTK_ProgressBar_GtkProgressBar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ProgressBar, GtkProgressBar, gtk, gtk_progressbar_gtkprogressbar, gtk_gtk_progressbar_gtkprogressbar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarNew)
{
	zend_long handle = 0;
	
            GtkWidget *bar;

            php_gtk_set_last_error(NULL);
            bar = gtk_progress_bar_new();
            if (bar == NULL) {
                php_gtk_set_last_error("gtk_progress_bar_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) bar;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetFraction)
{
	double fraction;
	zval *bar_param = NULL, *fraction_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_ZVAL(fraction_param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &fraction_param);
	fraction = zephir_get_doubleval(fraction_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_fraction(pb, (gdouble) fraction);
            }
        
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetFraction)
{
	double fraction = 0;
	zval *bar_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &bar_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            fraction = pb != NULL ? gtk_progress_bar_get_fraction(pb) : 0.0;
        
	RETURN_DOUBLE(fraction);
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *bar_param = NULL, *text_param = NULL;
	zend_long bar;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &bar_param, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_text(pb, Z_STRVAL(text));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetText)
{
	zval result;
	zval *bar_param = NULL;
	zend_long bar;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &bar_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            const char *text = NULL;
            if (pb != NULL) {
                text = gtk_progress_bar_get_text(pb);
            }
            ZVAL_STRING(&result, text ? text : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetShowText)
{
	zend_bool showText;
	zval *bar_param = NULL, *showText_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(bar)
		Z_PARAM_BOOL(showText)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &bar_param, &showText_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_show_text(pb, showText ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarPulse)
{
	zval *bar_param = NULL;
	zend_long bar;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(bar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &bar_param);
	
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_pulse(pb);
            }
        
}

