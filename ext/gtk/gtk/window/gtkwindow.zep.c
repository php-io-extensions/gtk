
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
#include "kernel/array.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);



/**
 * GtkWindow / GtkApplicationWindow — create, title, size, child, present, close.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Window_GtkWindow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Window, GtkWindow, gtk, gtk_window_gtkwindow, gtk_gtk_window_gtkwindow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowNew)
{
	zend_long handle = 0;
	
            GtkWidget *window;

            php_gtk_set_last_error(NULL);
            window = gtk_window_new();
            if (window == NULL) {
                php_gtk_set_last_error("gtk_window_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) window;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkApplicationWindowNew)
{
	zval *app_param = NULL;
	zend_long app, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(app)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &app_param);
	
            GtkApplication *gtk_app = (GtkApplication *)(uintptr_t) app;
            GtkWidget *window;

            php_gtk_set_last_error(NULL);
            if (gtk_app == NULL) {
                php_gtk_set_last_error("gtkApplicationWindowNew: app handle is 0");
                handle = 0;
            } else {
                window = GTK_WIDGET(gtk_application_window_new(gtk_app));
                if (window == NULL) {
                    php_gtk_set_last_error("gtk_application_window_new returned NULL");
                    handle = 0;
                } else {
                    handle = (zend_long)(uintptr_t) window;
                }
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval title;
	zval *window_param = NULL, *title_param = NULL;
	zend_long window;

	ZVAL_UNDEF(&title);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(window)
		Z_PARAM_ZVAL(title_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &window_param, &title_param);
	zephir_get_strval(&title, title_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_set_title(win, Z_STRVAL(title));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitle)
{
	zval result;
	zval *window_param = NULL;
	zend_long window;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            const char *title = NULL;
            if (win != NULL) {
                title = gtk_window_get_title(win);
            }
            ZVAL_STRING(&result, title ? title : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetDefaultSize)
{
	zval *window_param = NULL, *width_param = NULL, *height_param = NULL;
	zend_long window, width, height;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &window_param, &width_param, &height_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_set_default_size(win, (int) width, (int) height);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetDefaultSize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *window_param = NULL, _0;
	zend_long window, width = 0, height = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            int w = 0;
            int h = 0;
            if (win != NULL) {
                gtk_window_get_default_size(win, &w, &h);
            }
            width = (zend_long) w;
            height = (zend_long) h;
        
	zephir_create_array(return_value, 2, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, width);
	zephir_array_update_string(return_value, SL("width"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, height);
	zephir_array_update_string(return_value, SL("height"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetChild)
{
	zval *window_param = NULL, *child_param = NULL;
	zend_long window, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &window_param, &child_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (win != NULL) {
                gtk_window_set_child(win, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetChild)
{
	zval *window_param = NULL;
	zend_long window, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *child = NULL;
            if (win != NULL) {
                child = gtk_window_get_child(win);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowPresent)
{
	zval *window_param = NULL;
	zend_long window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_present(win);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowClose)
{
	zval *window_param = NULL;
	zend_long window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_close(win);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowDestroy)
{
	zval *window_param = NULL;
	zend_long window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_destroy(win);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitlebar)
{
	zval *window_param = NULL, *titlebar_param = NULL;
	zend_long window, titlebar;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(titlebar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &window_param, &titlebar_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *bar = GTK_WIDGET((void *)(uintptr_t) titlebar);
            if (win != NULL) {
                gtk_window_set_titlebar(win, bar);
            }
        
}

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitlebar)
{
	zval *window_param = NULL;
	zend_long window, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &window_param);
	
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *bar = NULL;
            if (win != NULL) {
                bar = gtk_window_get_titlebar(win);
            }
            handle = (zend_long)(uintptr_t) bar;
        
	RETURN_LONG(handle);
}

