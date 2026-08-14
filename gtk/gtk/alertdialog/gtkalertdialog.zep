namespace Gtk\GTK\AlertDialog;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);
}%

class GtkAlertDialog
{
    public static function gtkAlertDialogNew(string message) -> int
    {
        int handle;
        %{
            GtkAlertDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_alert_dialog_new("%s", Z_STRVAL(message));
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_alert_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        }%
        return handle;
    }

    public static function gtkAlertDialogSetDetail(int dialog, string detail) -> void
    {
        %{
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            if (ad != NULL) {
                gtk_alert_dialog_set_detail(ad, Z_STRVAL(detail));
            }
        }%
    }

    public static function gtkAlertDialogSetButtons(int dialog, array labels) -> void
    {
        %{
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            char **strv;
            if (ad != NULL) {
                strv = php_gtk_zval_to_strv(&labels);
                gtk_alert_dialog_set_buttons(ad, (const char * const *) strv);
                php_gtk_strv_free(strv);
            }
        }%
    }

    public static function gtkAlertDialogSetModal(int dialog, bool modal) -> void
    {
        %{
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            if (ad != NULL) {
                gtk_alert_dialog_set_modal(ad, modal ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkAlertDialogShow(int dialog, int parent) -> void
    {
        %{
            GtkAlertDialog *ad = GTK_ALERT_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            if (ad != NULL) {
                gtk_alert_dialog_show(ad, win);
            }
        }%
    }

    public static function gtkAlertDialogChoose(int dialog, int parent, var callback) -> void
    {
        %{
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
        }%
    }
}
