
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
#include "src/gtk-signal-list-item-factory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSignalListItemFactory_GtkSignalListItemFactory)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSignalListItemFactory, GtkSignalListItemFactory, gtk_gtk, gtksignallistitemfactory_gtksignallistitemfactory, gtk_gtk_gtksignallistitemfactory_gtksignallistitemfactory_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSignalListItemFactory_GtkSignalListItemFactory, new_)
{

	RETURN_LONG(phpgtk_gtksignallistitemfactory_new());
}

