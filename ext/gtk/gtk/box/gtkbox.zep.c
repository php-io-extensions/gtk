
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
 * GtkBox — gtk_box_new / append / remove / spacing.
 * orientation: 0 = GTK_ORIENTATION_HORIZONTAL, 1 = GTK_ORIENTATION_VERTICAL
 * (define those ints in the app or microscrap enum — not here).
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Box_GtkBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Box, GtkBox, gtk, gtk_box_gtkbox, gtk_gtk_box_gtkbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxNew)
{
	zval *orientation_param = NULL, *spacing_param = NULL;
	zend_long orientation, spacing, handle = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(orientation)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &orientation_param, &spacing_param);
	
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_box_new((GtkOrientation) orientation, (int) spacing);
            if (box == NULL) {
                php_gtk_set_last_error("gtk_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxAppend)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gtk_box != NULL && widget != NULL) {
                gtk_box_append(gtk_box, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxRemove)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gtk_box != NULL && widget != NULL) {
                gtk_box_remove(gtk_box, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxSetSpacing)
{
	zval *box_param = NULL, *spacing_param = NULL;
	zend_long box, spacing;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &spacing_param);
	
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            if (gtk_box != NULL) {
                gtk_box_set_spacing(gtk_box, (int) spacing);
            }
        
}

