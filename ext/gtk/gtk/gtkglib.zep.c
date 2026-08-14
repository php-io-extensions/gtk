
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

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
extern void *php_gtk_closure_new(zval *callback);



ZEPHIR_INIT_CLASS(Gtk_GTK_GtkGLib)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK, GtkGLib, gtk, gtk_gtkglib, gtk_gtk_gtkglib_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_GtkGLib, gObjectRef)
{
	zval *instance_param = NULL;
	zend_long instance, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(instance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &instance_param);
	
            gpointer obj = (gpointer)(uintptr_t) instance;
            if (obj == NULL) {
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) g_object_ref(obj);
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_GtkGLib, gObjectUnref)
{
	zval *instance_param = NULL;
	zend_long instance;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(instance)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &instance_param);
	
            gpointer obj = (gpointer)(uintptr_t) instance;
            if (obj != NULL) {
                g_object_unref(obj);
            }
        
}

PHP_METHOD(Gtk_GTK_GtkGLib, gSignalConnect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval signal;
	zval *instance_param = NULL, *signal_param = NULL, *callback, callback_sub;
	zend_long instance, handlerId = 0;

	ZVAL_UNDEF(&callback_sub);
	ZVAL_UNDEF(&signal);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(instance)
		Z_PARAM_ZVAL(signal_param)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &instance_param, &signal_param, &callback);
	zephir_get_strval(&signal, signal_param);
	if (Z_TYPE_P(callback) == IS_NULL) {
		RETURN_MM_LONG(0);
	}
	
            void *obj = (void *)(uintptr_t) instance;
            void *closure;
            gulong hid;

            php_gtk_set_last_error(NULL);
            if (obj == NULL) {
                php_gtk_set_last_error("gSignalConnect: instance handle is 0");
                handlerId = 0;
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gSignalConnect: callback is not callable");
                handlerId = 0;
            } else {
                closure = php_gtk_closure_new(callback);
                hid = g_signal_connect_closure(obj, Z_STRVAL(signal), closure, FALSE);
                if (hid == 0) {
                    g_closure_unref(closure);
                    php_gtk_set_last_error("gSignalConnect: connect failed");
                }
                handlerId = (zend_long) hid;
            }
        
	RETURN_MM_LONG(handlerId);
}

