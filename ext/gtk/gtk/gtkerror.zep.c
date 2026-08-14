
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
#include "kernel/object.h"

#include <gtk/gtk.h>

extern char php_gtk_last_error[256];



/**
 * Last bind-layer failure string. GTK constructors return 0 on NULL.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_GtkError)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK, GtkError, gtk, gtk_gtkerror, gtk_gtk_gtkerror_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_GtkError, gtkLastMessage)
{
	zval result;

	ZVAL_UNDEF(&result);
	
            ZVAL_STRING(&result, php_gtk_last_error);
        
	RETURN_CTORW(&result);
}

