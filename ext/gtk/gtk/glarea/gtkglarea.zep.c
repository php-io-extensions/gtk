
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



/**
 * GtkGLArea — allocate a GPU view. Does not create a window.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_GLArea_GtkGLArea)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\GLArea, GtkGLArea, gtk, gtk_glarea_gtkglarea, gtk_gtk_glarea_gtkglarea_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaNew)
{
	zend_long handle = 0;
	
            GtkWidget *area;

            php_gtk_set_last_error(NULL);
            area = gtk_gl_area_new();
            if (area == NULL) {
                php_gtk_set_last_error("gtk_gl_area_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) area;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaMakeCurrent)
{
	zval *area_param = NULL;
	zend_long area;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(area)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &area_param);
	
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_make_current(gl_area);
            }
        
}

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaQueueRender)
{
	zval *area_param = NULL;
	zend_long area;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(area)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &area_param);
	
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_queue_render(gl_area);
            }
        
}

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaSetAutoRender)
{
	zend_bool autoRender;
	zval *area_param = NULL, *autoRender_param = NULL;
	zend_long area;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(area)
		Z_PARAM_BOOL(autoRender)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &area_param, &autoRender_param);
	
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_set_auto_render(gl_area, autoRender ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaGetError)
{
	zval result;
	zval *area_param = NULL;
	zend_long area;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(area)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &area_param);
	
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            GError *error = NULL;
            const char *message = "";
            if (gl_area != NULL) {
                error = gtk_gl_area_get_error(gl_area);
            }
            if (error != NULL && error->message != NULL) {
                message = error->message;
            }
            ZVAL_STRING(&result, message);
        
	RETURN_CTORW(&result);
}

