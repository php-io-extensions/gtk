
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Notebook_GtkNotebook)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Notebook, GtkNotebook, gtk, gtk_notebook_gtknotebook, gtk_gtk_notebook_gtknotebook_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookNew)
{
	zend_long handle = 0;
	
            GtkWidget *nb;

            php_gtk_set_last_error(NULL);
            nb = gtk_notebook_new();
            if (nb == NULL) {
                php_gtk_set_last_error("gtk_notebook_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) nb;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookAppendPage)
{
	zval *notebook_param = NULL, *child_param = NULL, *tabLabel_param = NULL;
	zend_long notebook, child, tabLabel, page = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(notebook)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &notebook_param, &child_param, &tabLabel_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            GtkWidget *tab = GTK_WIDGET((void *)(uintptr_t) tabLabel);
            page = -1;
            if (nb != NULL && widget != NULL) {
                page = (zend_long) gtk_notebook_append_page(nb, widget, tab);
            }
        
	RETURN_LONG(page);
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookRemovePage)
{
	zval *notebook_param = NULL, *pageNum_param = NULL;
	zend_long notebook, pageNum;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(notebook)
		Z_PARAM_LONG(pageNum)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &notebook_param, &pageNum_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            if (nb != NULL) {
                gtk_notebook_remove_page(nb, (int) pageNum);
            }
        
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetNPages)
{
	zval *notebook_param = NULL;
	zend_long notebook, pages = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(notebook)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &notebook_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            pages = nb != NULL ? (zend_long) gtk_notebook_get_n_pages(nb) : 0;
        
	RETURN_LONG(pages);
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetCurrentPage)
{
	zval *notebook_param = NULL, *pageNum_param = NULL;
	zend_long notebook, pageNum;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(notebook)
		Z_PARAM_LONG(pageNum)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &notebook_param, &pageNum_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            if (nb != NULL) {
                gtk_notebook_set_current_page(nb, (int) pageNum);
            }
        
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetCurrentPage)
{
	zval *notebook_param = NULL;
	zend_long notebook, page = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(notebook)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &notebook_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            page = nb != NULL ? (zend_long) gtk_notebook_get_current_page(nb) : -1;
        
	RETURN_LONG(page);
}

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetTabLabelText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *notebook_param = NULL, *child_param = NULL, *text_param = NULL;
	zend_long notebook, child;

	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(notebook)
		Z_PARAM_LONG(child)
		Z_PARAM_ZVAL(text_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &notebook_param, &child_param, &text_param);
	zephir_get_strval(&text, text_param);
	
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (nb != NULL && widget != NULL) {
                gtk_notebook_set_tab_label_text(nb, widget, Z_STRVAL(text));
            }
        
	ZEPHIR_MM_RESTORE();
}

