
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Stack_GtkStack)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Stack, GtkStack, gtk, gtk_stack_gtkstack, gtk_gtk_stack_gtkstack_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackNew)
{
	zend_long handle = 0;
	
            GtkWidget *stack;

            php_gtk_set_last_error(NULL);
            stack = gtk_stack_new();
            if (stack == NULL) {
                php_gtk_set_last_error("gtk_stack_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) stack;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackAddChild)
{
	zval *stack_param = NULL, *child_param = NULL;
	zend_long stack, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(stack)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &stack_param, &child_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_add_child(st, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackAddTitled)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name, title;
	zval *stack_param = NULL, *child_param = NULL, *name_param = NULL, *title_param = NULL;
	zend_long stack, child;

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&title);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(stack)
		Z_PARAM_LONG(child)
		Z_PARAM_ZVAL(name_param)
		Z_PARAM_ZVAL(title_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &stack_param, &child_param, &name_param, &title_param);
	zephir_get_strval(&name, name_param);
	zephir_get_strval(&title, title_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_add_titled(st, widget, Z_STRVAL(name), Z_STRVAL(title));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackRemove)
{
	zval *stack_param = NULL, *child_param = NULL;
	zend_long stack, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(stack)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &stack_param, &child_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_remove(st, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChild)
{
	zval *stack_param = NULL, *child_param = NULL;
	zend_long stack, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(stack)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &stack_param, &child_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_set_visible_child(st, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChild)
{
	zval *stack_param = NULL;
	zend_long stack, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(stack)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &stack_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *child = NULL;
            if (st != NULL) {
                child = gtk_stack_get_visible_child(st);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChildName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *stack_param = NULL, *name_param = NULL;
	zend_long stack;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(stack)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &stack_param, &name_param);
	zephir_get_strval(&name, name_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            if (st != NULL) {
                gtk_stack_set_visible_child_name(st, Z_STRVAL(name));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChildName)
{
	zval result;
	zval *stack_param = NULL;
	zend_long stack;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(stack)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &stack_param);
	
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            const char *name = NULL;
            if (st != NULL) {
                name = gtk_stack_get_visible_child_name(st);
            }
            ZVAL_STRING(&result, name ? name : "");
        
	RETURN_CTORW(&result);
}

