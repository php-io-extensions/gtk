
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



ZEPHIR_INIT_CLASS(Gtk_GTK_FileDialog_GtkFileDialog)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\FileDialog, GtkFileDialog, gtk, gtk_filedialog_gtkfiledialog, gtk_gtk_filedialog_gtkfiledialog_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogNew)
{
	zend_long handle = 0;
	
            GtkFileDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_file_dialog_new();
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_file_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetTitle)
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
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_file_dialog_set_title(fd, Z_STRVAL(title));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogGetTitle)
{
	zval result;
	zval *dialog_param = NULL;
	zend_long dialog;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(dialog)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &dialog_param);
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            const char *title = NULL;
            if (fd != NULL) {
                title = gtk_file_dialog_get_title(fd);
            }
            ZVAL_STRING(&result, title ? title : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetInitialName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *dialog_param = NULL, *name_param = NULL;
	zend_long dialog;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(dialog)
		Z_PARAM_ZVAL(name_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &dialog_param, &name_param);
	zephir_get_strval(&name, name_param);
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_file_dialog_set_initial_name(fd, Z_STRVAL(name));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogOpen)
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
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (fd == NULL) {
                php_gtk_set_last_error("gtkFileDialogOpen: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkFileDialogOpen: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 2);
                gtk_file_dialog_open(fd, win, NULL, php_gtk_async_ready, job);
            }
        
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSave)
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
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (fd == NULL) {
                php_gtk_set_last_error("gtkFileDialogSave: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkFileDialogSave: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 3);
                gtk_file_dialog_save(fd, win, NULL, php_gtk_async_ready, job);
            }
        
}

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSelectFolder)
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
	
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (fd == NULL) {
                php_gtk_set_last_error("gtkFileDialogSelectFolder: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkFileDialogSelectFolder: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 4);
                gtk_file_dialog_select_folder(fd, win, NULL, php_gtk_async_ready, job);
            }
        
}

