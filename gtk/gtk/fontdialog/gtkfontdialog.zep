namespace Gtk\GTK\FontDialog;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern void *php_gtk_async_job_new(zval *callback, int kind);
extern void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data);
}%

class GtkFontDialog
{
    public static function gtkFontDialogNew() -> int
    {
        int handle;
        %{
            GtkFontDialog *dialog;

            php_gtk_set_last_error(NULL);
            dialog = gtk_font_dialog_new();
            if (dialog == NULL) {
                php_gtk_set_last_error("gtk_font_dialog_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) dialog;
            }
        }%
        return handle;
    }

    public static function gtkFontDialogSetTitle(int dialog, string title) -> void
    {
        %{
            GtkFontDialog *fd = GTK_FONT_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_font_dialog_set_title(fd, Z_STRVAL(title));
            }
        }%
    }

    public static function gtkFontDialogSetModal(int dialog, bool modal) -> void
    {
        %{
            GtkFontDialog *fd = GTK_FONT_DIALOG((void *)(uintptr_t) dialog);
            if (fd != NULL) {
                gtk_font_dialog_set_modal(fd, modal ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkFontDialogChooseFont(int dialog, int parent, var callback) -> void
    {
        %{
            GtkFontDialog *fd = GTK_FONT_DIALOG((void *)(uintptr_t) dialog);
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) parent);
            void *job;
            php_gtk_set_last_error(NULL);
            if (fd == NULL) {
                php_gtk_set_last_error("gtkFontDialogChooseFont: dialog handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkFontDialogChooseFont: callback is not callable");
            } else {
                job = php_gtk_async_job_new(callback, 6);
                gtk_font_dialog_choose_font(fd, win, NULL, NULL, php_gtk_async_ready, job);
            }
        }%
    }
}
