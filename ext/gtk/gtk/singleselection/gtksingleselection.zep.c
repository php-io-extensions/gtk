
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



ZEPHIR_INIT_CLASS(Gtk_GTK_SingleSelection_GtkSingleSelection)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\SingleSelection, GtkSingleSelection, gtk, gtk_singleselection_gtksingleselection, gtk_gtk_singleselection_gtksingleselection_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_SingleSelection_GtkSingleSelection, gtkSingleSelectionNew)
{
	zval *model_param = NULL;
	zend_long model, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &model_param);
	
            GtkSingleSelection *sel;
            GListModel *list = G_LIST_MODEL((void *)(uintptr_t) model);

            php_gtk_set_last_error(NULL);
            sel = gtk_single_selection_new(list);
            if (sel == NULL) {
                php_gtk_set_last_error("gtk_single_selection_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sel;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_SingleSelection_GtkSingleSelection, gtkSingleSelectionSetSelected)
{
	zval *selection_param = NULL, *position_param = NULL;
	zend_long selection, position;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(selection)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &selection_param, &position_param);
	
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            if (sel != NULL) {
                gtk_single_selection_set_selected(sel, (guint) position);
            }
        
}

PHP_METHOD(Gtk_GTK_SingleSelection_GtkSingleSelection, gtkSingleSelectionGetSelected)
{
	zval *selection_param = NULL;
	zend_long selection, position = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(selection)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &selection_param);
	
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            position = sel != NULL ? (zend_long) gtk_single_selection_get_selected(sel) : 0;
        
	RETURN_LONG(position);
}

PHP_METHOD(Gtk_GTK_SingleSelection_GtkSingleSelection, gtkSingleSelectionGetModel)
{
	zval *selection_param = NULL;
	zend_long selection, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(selection)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &selection_param);
	
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            GListModel *model = NULL;
            if (sel != NULL) {
                model = gtk_single_selection_get_model(sel);
            }
            handle = (zend_long)(uintptr_t) model;
        
	RETURN_LONG(handle);
}

