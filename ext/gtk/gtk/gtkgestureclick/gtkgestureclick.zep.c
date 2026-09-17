
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
#include "src/gtk-gesture-click.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGestureClick_GtkGestureClick)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkGestureClick, GtkGestureClick, gtk_gtk, gtkgestureclick_gtkgestureclick, gtk_gtk_gtkgestureclick_gtkgestureclick_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkGestureClick_GtkGestureClick, new_)
{

	RETURN_LONG(phpgtk_gtkgestureclick_new());
}

