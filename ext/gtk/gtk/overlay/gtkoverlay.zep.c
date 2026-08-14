
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Overlay_GtkOverlay)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Overlay, GtkOverlay, gtk, gtk_overlay_gtkoverlay, gtk_gtk_overlay_gtkoverlay_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayNew)
{
	zend_long handle = 0;
	
            GtkWidget *overlay;

            php_gtk_set_last_error(NULL);
            overlay = gtk_overlay_new();
            if (overlay == NULL) {
                php_gtk_set_last_error("gtk_overlay_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) overlay;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlaySetChild)
{
	zval *overlay_param = NULL, *child_param = NULL;
	zend_long overlay, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(overlay)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &overlay_param, &child_param);
	
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL) {
                gtk_overlay_set_child(ov, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayGetChild)
{
	zval *overlay_param = NULL;
	zend_long overlay, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(overlay)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &overlay_param);
	
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *child = NULL;
            if (ov != NULL) {
                child = gtk_overlay_get_child(ov);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayAddOverlay)
{
	zval *overlay_param = NULL, *child_param = NULL;
	zend_long overlay, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(overlay)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &overlay_param, &child_param);
	
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL && widget != NULL) {
                gtk_overlay_add_overlay(ov, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayRemoveOverlay)
{
	zval *overlay_param = NULL, *child_param = NULL;
	zend_long overlay, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(overlay)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &overlay_param, &child_param);
	
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL && widget != NULL) {
                gtk_overlay_remove_overlay(ov, widget);
            }
        
}

