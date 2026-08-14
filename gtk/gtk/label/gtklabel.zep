namespace Gtk\GTK\Label;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkLabel — new, text get/set.
 */
class GtkLabel
{
    public static function gtkLabelNew(string text) -> int
    {
        int handle;
        %{
            GtkWidget *label;

            php_gtk_set_last_error(NULL);
            label = gtk_label_new(Z_STRVAL(text));
            if (label == NULL) {
                php_gtk_set_last_error("gtk_label_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) label;
            }
        }%
        return handle;
    }

    public static function gtkLabelSetText(int label, string text) -> void
    {
        %{
            GtkLabel *lbl = GTK_LABEL((void *)(uintptr_t) label);
            if (lbl != NULL) {
                gtk_label_set_text(lbl, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkLabelGetText(int label) -> string
    {
        string result;
        %{
            GtkLabel *lbl = GTK_LABEL((void *)(uintptr_t) label);
            const char *text = NULL;
            if (lbl != NULL) {
                text = gtk_label_get_text(lbl);
            }
            ZVAL_STRING(&result, text ? text : "");
        }%
        return result;
    }
}
