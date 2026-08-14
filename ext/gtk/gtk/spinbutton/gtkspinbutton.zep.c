
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



ZEPHIR_INIT_CLASS(Gtk_GTK_SpinButton_GtkSpinButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\SpinButton, GtkSpinButton, gtk, gtk_spinbutton_gtkspinbutton, gtk_gtk_spinbutton_gtkspinbutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonNewWithRange)
{
	zend_long handle = 0;
	zval *min_param = NULL, *max_param = NULL, *step_param = NULL;
	double min, max, step;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(min_param)
		Z_PARAM_ZVAL(max_param)
		Z_PARAM_ZVAL(step_param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &min_param, &max_param, &step_param);
	min = zephir_get_doubleval(min_param);
	max = zephir_get_doubleval(max_param);
	step = zephir_get_doubleval(step_param);
	
            GtkWidget *spin;

            php_gtk_set_last_error(NULL);
            spin = gtk_spin_button_new_with_range((gdouble) min, (gdouble) max, (gdouble) step);
            if (spin == NULL) {
                php_gtk_set_last_error("gtk_spin_button_new_with_range returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) spin;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetValue)
{
	double value;
	zval *spin_param = NULL, *value_param = NULL;
	zend_long spin;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(spin)
		Z_PARAM_ZVAL(value_param)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &spin_param, &value_param);
	value = zephir_get_doubleval(value_param);
	
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            if (sb != NULL) {
                gtk_spin_button_set_value(sb, (gdouble) value);
            }
        
}

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValue)
{
	double value = 0;
	zval *spin_param = NULL;
	zend_long spin;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &spin_param);
	
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            value = sb != NULL ? gtk_spin_button_get_value(sb) : 0.0;
        
	RETURN_DOUBLE(value);
}

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValueAsInt)
{
	zval *spin_param = NULL;
	zend_long spin, value = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &spin_param);
	
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            value = sb != NULL ? (zend_long) gtk_spin_button_get_value_as_int(sb) : 0;
        
	RETURN_LONG(value);
}

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetDigits)
{
	zval *spin_param = NULL, *digits_param = NULL;
	zend_long spin, digits;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(spin)
		Z_PARAM_LONG(digits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &spin_param, &digits_param);
	
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            if (sb != NULL) {
                gtk_spin_button_set_digits(sb, (guint) digits);
            }
        
}

