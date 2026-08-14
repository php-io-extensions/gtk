
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



ZEPHIR_INIT_CLASS(Gtk_GTK_ListView_GtkListView)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ListView, GtkListView, gtk, gtk_listview_gtklistview, gtk_gtk_listview_gtklistview_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewNew)
{
	zval *model_param = NULL, *factory_param = NULL;
	zend_long model, factory, handle = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(model)
		Z_PARAM_LONG(factory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &model_param, &factory_param);
	
            GtkWidget *view;
            GtkSelectionModel *sel = GTK_SELECTION_MODEL((void *)(uintptr_t) model);
            GtkListItemFactory *fac = GTK_LIST_ITEM_FACTORY((void *)(uintptr_t) factory);

            php_gtk_set_last_error(NULL);
            view = gtk_list_view_new(sel, fac);
            if (view == NULL) {
                php_gtk_set_last_error("gtk_list_view_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) view;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewSetModel)
{
	zval *view_param = NULL, *model_param = NULL;
	zend_long view, model;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(view)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &view_param, &model_param);
	
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkSelectionModel *sel = GTK_SELECTION_MODEL((void *)(uintptr_t) model);
            if (lv != NULL) {
                gtk_list_view_set_model(lv, sel);
            }
        
}

PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewGetModel)
{
	zval *view_param = NULL;
	zend_long view, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(view)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &view_param);
	
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkSelectionModel *sel = NULL;
            if (lv != NULL) {
                sel = gtk_list_view_get_model(lv);
            }
            handle = (zend_long)(uintptr_t) sel;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewSetFactory)
{
	zval *view_param = NULL, *factory_param = NULL;
	zend_long view, factory;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(view)
		Z_PARAM_LONG(factory)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &view_param, &factory_param);
	
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkListItemFactory *fac = GTK_LIST_ITEM_FACTORY((void *)(uintptr_t) factory);
            if (lv != NULL) {
                gtk_list_view_set_factory(lv, fac);
            }
        
}

