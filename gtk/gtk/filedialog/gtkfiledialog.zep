namespace Gtk\GTK\FileDialog;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);
}%

class GtkFileDialog
{
    public static function gtkFileDialogNew() -> int
    {
        int handle;
        %{
            GtkFileDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_file_dialog_new();
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_file_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        }%
        return handle;
    }

    public static function gtkFileDialogSetTitle(int dialog, string title) -> void
    {
        %{
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_file_dialog_set_title(fd, Z_STRVAL(title));
            }
        }%
    }

    public static function gtkFileDialogGetTitle(int dialog) -> string
    {
        string result;
        %{
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            const char *title = NULL;
            if (fd != NULL) {
                title = gtk_file_dialog_get_title(fd);
            }
            ZVAL_STRING(&result, title ? title : "");
        }%
        return result;
    }

    public static function gtkFileDialogSetInitialName(int dialog, string name) -> void
    {
        %{
            GtkFileDialog *fd = GTK_FILE_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_file_dialog_set_initial_name(fd, Z_STRVAL(name));
            }
        }%
    }

    public static function gtkFileDialogOpen(int dialog, int parent, var callback) -> void
    {
        %{
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
        }%
    }

    public static function gtkFileDialogSave(int dialog, int parent, var callback) -> void
    {
        %{
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
        }%
    }

    public static function gtkFileDialogSelectFolder(int dialog, int parent, var callback) -> void
    {
        %{
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
        }%
    }
}
