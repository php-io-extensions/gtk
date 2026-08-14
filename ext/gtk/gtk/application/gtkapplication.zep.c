
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
 * GtkApplication — gtk_application_new / g_application_run / g_application_quit.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Application_GtkApplication)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Application, GtkApplication, gtk, gtk_application_gtkapplication, gtk_gtk_application_gtkapplication_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationNew)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long flags, handle = 0;
	zval *applicationId_param = NULL, *flags_param = NULL;
	zval applicationId;

	ZVAL_UNDEF(&applicationId);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(applicationId_param)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &applicationId_param, &flags_param);
	zephir_get_strval(&applicationId, applicationId_param);
	
            GtkApplication *app;
            const char *id = Z_STRVAL(applicationId);

            php_gtk_set_last_error(NULL);
            app = gtk_application_new(id, (GApplicationFlags) flags);
            if (app == NULL) {
                php_gtk_set_last_error("gtk_application_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) app;
            }
        
	RETURN_MM_LONG(handle);
}

/**
 * Blocks the calling thread. argc/argv are not forwarded (0 / NULL).
 */
PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationRun)
{
	zval *app_param = NULL;
	zend_long app, status = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(app)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &app_param);
	
            GApplication *gapp = (GApplication *)(uintptr_t) app;
            if (gapp == NULL) {
                php_gtk_set_last_error("gtkApplicationRun: app handle is 0");
                status = 1;
            } else {
                php_gtk_set_last_error(NULL);
                status = (zend_long) g_application_run(gapp, 0, NULL);
            }
        
	RETURN_LONG(status);
}

PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationQuit)
{
	zval *app_param = NULL;
	zend_long app;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(app)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &app_param);
	
            GApplication *gapp = (GApplication *)(uintptr_t) app;
            if (gapp != NULL) {
                g_application_quit(gapp);
            }
        
}

