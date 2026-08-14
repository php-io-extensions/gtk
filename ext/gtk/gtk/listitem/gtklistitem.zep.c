
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



ZEPHIR_INIT_CLASS(Gtk_GTK_ListItem_GtkListItem)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ListItem, GtkListItem, gtk, gtk_listitem_gtklistitem, gtk_gtk_listitem_gtklistitem_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkSignalListItemFactoryNew)
{
	zend_long handle = 0;
	
            GtkListItemFactory *factory;

            php_gtk_set_last_error(NULL);
            factory = gtk_signal_list_item_factory_new();
            if (factory == NULL) {
                php_gtk_set_last_error("gtk_signal_list_item_factory_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) factory;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemSetChild)
{
	zval *item_param = NULL, *child_param = NULL;
	zend_long item, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(item)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &item_param, &child_param);
	
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (li != NULL) {
                gtk_list_item_set_child(li, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetChild)
{
	zval *item_param = NULL;
	zend_long item, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &item_param);
	
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            GtkWidget *child = NULL;
            if (li != NULL) {
                child = gtk_list_item_get_child(li);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetItem)
{
	zval *item_param = NULL;
	zend_long item, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &item_param);
	
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            gpointer obj = NULL;
            if (li != NULL) {
                obj = gtk_list_item_get_item(li);
            }
            handle = (zend_long)(uintptr_t) obj;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetPosition)
{
	zval *item_param = NULL;
	zend_long item, position = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &item_param);
	
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            position = li != NULL ? (zend_long) gtk_list_item_get_position(li) : 0;
        
	RETURN_LONG(position);
}

