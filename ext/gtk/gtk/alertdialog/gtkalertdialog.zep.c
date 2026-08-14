
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
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);



ZEPHIR_INIT_CLASS(Gtk_GTK_AlertDialog_GtkAlertDialog)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\AlertDialog, GtkAlertDialog, gtk, gtk_alertdialog_gtkalertdialog, gtk_gtk_alertdialog_gtkalertdialog_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogNew)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *message_param = NULL;
	zval message;

	ZVAL_UNDEF(&message);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(message_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &message_param);
	zephir_get_strval(&message, message_param);
	
            GtkAlertDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_alert_dialog_new("%s", Z_STRVAL(message));
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_alert_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetDetail)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval detail;
	zval *dialog_param = NULL, *detail_param = NULL;
	zend_long dialog;

	ZVAL_UNDEF(&detail);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_ZVAL(detail_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &dialog_param, &detail_param);
	zephir_get_strval(&detail, detail_param);
	
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            if (ad != NULL) {
                gtk_alert_dialog_set_detail(ad, Z_STRVAL(detail));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetButtons)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval labels;
	zval *dialog_param = NULL, *labels_param = NULL;
	zend_long dialog;

	ZVAL_UNDEF(&labels);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		ZEPHIR_Z_PARAM_ARRAY(labels, labels_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &dialog_param, &labels_param);
	zephir_get_arrval(&labels, labels_param);
	
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            char **strv;
            if (ad != NULL) {
                strv = php_gtk_zval_to_strv(&labels);
                gtk_alert_dialog_set_buttons(ad, (const char * const *) strv);
                php_gtk_strv_free(strv);
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetModal)
{
	zend_bool modal;
	zval *dialog_param = NULL, *modal_param = NULL;
	zend_long dialog;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dialog_param, &modal_param);
	
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            if (ad != NULL) {
                gtk_alert_dialog_set_modal(ad, modal ? TRUE : FALSE);
            }
        
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogShow)
{
	zval *dialog_param = NULL, *parent_param = NULL;
	zend_long dialog, parent;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_LONG(parent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &dialog_param, &parent_param);
	
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            if (ad != NULL) {
                gtk_alert_dialog_show(ad, win);
            }
        
}

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogChoose)
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
	
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (ad == NULL) {
                php_gtk_set_last_error("gtkAlertDialogChoose: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkAlertDialogChoose: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 1);
                gtk_alert_dialog_choose(ad, win, NULL, php_gtk_async_ready, job);
            }
        
}

