
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Scale_GtkScale)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Scale, GtkScale, gtk, gtk_scale_gtkscale, gtk_gtk_scale_gtkscale_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleNewWithRange)
{
	double min, max, step;
	zval *orientation_param = NULL, *min_param = NULL, *max_param = NULL, *step_param = NULL;
	zend_long orientation, handle = 0;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(orientation)
		Z_PARAM_ZVAL(min_param)
		Z_PARAM_ZVAL(max_param)
		Z_PARAM_ZVAL(step_param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &orientation_param, &min_param, &max_param, &step_param);
	min = zephir_get_doubleval(min_param);
	max = zephir_get_doubleval(max_param);
	step = zephir_get_doubleval(step_param);
	
            GtkWidget *scale;

            php_gtk_set_last_error(NULL);
            scale = gtk_scale_new_with_range((GtkOrientation) orientation, (gdouble) min, (gdouble) max, (gdouble) step);
            if (scale == NULL) {
                php_gtk_set_last_error("gtk_scale_new_with_range returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) scale;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetValue)
{
	double value;
	zval *scale_param = NULL, *value_param = NULL;
	zend_long scale;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scale)
		Z_PARAM_ZVAL(value_param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scale_param, &value_param);
	value = zephir_get_doubleval(value_param);
	
            GtkRange *range = GTK_RANGE((void *)(uintptr_t) scale);
            if (range != NULL) {
                gtk_range_set_value(range, (gdouble) value);
            }
        
}

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleGetValue)
{
	double value = 0;
	zval *scale_param = NULL;
	zend_long scale;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(scale)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &scale_param);
	
            GtkRange *range = GTK_RANGE((void *)(uintptr_t) scale);
            value = range != NULL ? gtk_range_get_value(range) : 0.0;
        
	RETURN_DOUBLE(value);
}

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetDrawValue)
{
	zend_bool drawValue;
	zval *scale_param = NULL, *drawValue_param = NULL;
	zend_long scale;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scale)
		Z_PARAM_BOOL(drawValue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scale_param, &drawValue_param);
	
            GtkScale *sc = GTK_SCALE((void *)(uintptr_t) scale);
            if (sc != NULL) {
                gtk_scale_set_draw_value(sc, drawValue ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetDigits)
{
	zval *scale_param = NULL, *digits_param = NULL;
	zend_long scale, digits;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(scale)
		Z_PARAM_LONG(digits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &scale_param, &digits_param);
	
            GtkScale *sc = GTK_SCALE((void *)(uintptr_t) scale);
            if (sc != NULL) {
                gtk_scale_set_digits(sc, (int) digits);
            }
        
}

