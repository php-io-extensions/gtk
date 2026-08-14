
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
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);



ZEPHIR_INIT_CLASS(Gtk_GTK_ColorDialog_GtkColorDialog)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\ColorDialog, GtkColorDialog, gtk, gtk_colordialog_gtkcolordialog, gtk_gtk_colordialog_gtkcolordialog_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogNew)
{
	zend_long handle = 0;
	
            GtkColorDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_color_dialog_new();
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_color_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetTitle)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval title;
	zval *dialog_param = NULL, *title_param = NULL;
	zend_long dialog;

	ZVAL_UNDEF(&title);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_ZVAL(title_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &dialog_param, &title_param);
	zephir_get_strval(&title, title_param);
	
            GtkColorDialog *cd = GTK_COLOR_DIALOG((void *)(uintptr_t) dialog);
            if (cd != NULL) {
                gtk_color_dialog_set_title(cd, Z_STRVAL(title));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetModal)
{
	zend_bool modal;
	zval *dialog_param = NULL, *modal_param = NULL;
	zend_long dialog;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dialog_param, &modal_param);
	
            GtkColorDialog *cd = GTK_COLOR_DIALOG((void *)(uintptr_t) dialog);
            if (cd != NULL) {
                gtk_color_dialog_set_modal(cd, modal ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogChooseRgba)
{
	zval *dialog_param = NULL, *parent_param = NULL, *callback, callback_sub;
	zend_long dialog, parent;

	ZVAL_UNDEF(&callback_sub);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(dialog)
		Z_PARAM_LONG(parent)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &dialog_param, &parent_param, &callback);
	
            GtkColorDialog *cd = GTK_COLOR_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (cd == NULL) {
                php_gtk_set_last_error("gtkColorDialogChooseRgba: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkColorDialogChooseRgba: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 5);
                gtk_color_dialog_choose_rgba(cd, win, NULL, NULL, php_gtk_async_ready, job);
            }
        
}

