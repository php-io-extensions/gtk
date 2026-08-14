namespace Gtk\GTK\ColorDialog;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);
}%

class GtkColorDialog
{
    public static function gtkColorDialogNew() -> int
    {
        int handle;
        %{
            GtkColorDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_color_dialog_new();
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_color_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        }%
        return handle;
    }

    public static function gtkColorDialogSetTitle(int dialog, string title) -> void
    {
        %{
            GtkColorDialog *cd = GTK_COLOR_DIALOG((void *)(uintptr_t) dialog);
            if (cd != NULL) {
                gtk_color_dialog_set_title(cd, Z_STRVAL(title));
            }
        }%
    }

    public static function gtkColorDialogSetModal(int dialog, bool modal) -> void
    {
        %{
            GtkColorDialog *cd = GTK_COLOR_DIALOG((void *)(uintptr_t) dialog);
            if (cd != NULL) {
                gtk_color_dialog_set_modal(cd, modal ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkColorDialogChooseRgba(int dialog, int parent, var callback) -> void
    {
        %{
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
        }%
    }
}
