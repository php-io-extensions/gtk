
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



ZEPHIR_INIT_CLASS(Gtk_GTK_ListBox_GtkListBox)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ListBox, GtkListBox, gtk, gtk_listbox_gtklistbox, gtk_gtk_listbox_gtklistbox_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxNew)
{
	zend_long handle = 0;
	
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_list_box_new();
            if (box == NULL) {
                php_gtk_set_last_error("gtk_list_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxAppend)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (lb != NULL && widget != NULL) {
                gtk_list_box_append(lb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRemove)
{
	zval *box_param = NULL, *child_param = NULL;
	zend_long box, child;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &child_param);
	
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (lb != NULL && widget != NULL) {
                gtk_list_box_remove(lb, widget);
            }
        
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetSelectedRow)
{
	zval *box_param = NULL;
	zend_long box, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(box)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &box_param);
	
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *row = NULL;
            if (lb != NULL) {
                row = gtk_list_box_get_selected_row(lb);
            }
            handle = (zend_long)(uintptr_t) row;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxSelectRow)
{
	zval *box_param = NULL, *row_param = NULL;
	zend_long box, row;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &row_param);
	
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            if (lb != NULL) {
                gtk_list_box_select_row(lb, r);
            }
        
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetRowAtIndex)
{
	zval *box_param = NULL, *index_param = NULL;
	zend_long box, index, handle = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(box)
		Z_PARAM_LONG(index)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &box_param, &index_param);
	
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *row = NULL;
            if (lb != NULL) {
                row = gtk_list_box_get_row_at_index(lb, (int) index);
            }
            handle = (zend_long)(uintptr_t) row;
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetIndex)
{
	zval *row_param = NULL;
	zend_long row, index = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &row_param);
	
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            index = r != NULL ? (zend_long) gtk_list_box_row_get_index(r) : -1;
        
	RETURN_LONG(index);
}

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetChild)
{
	zval *row_param = NULL;
	zend_long row, handle = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &row_param);
	
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            GtkWidget *child = NULL;
            if (r != NULL) {
                child = gtk_list_box_row_get_child(r);
            }
            handle = (zend_long)(uintptr_t) child;
        
	RETURN_LONG(handle);
}

