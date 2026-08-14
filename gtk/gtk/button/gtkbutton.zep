namespace Gtk\GTK\Button;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkButton — new, label get/set.
 */
class GtkButton
{
    public static function gtkButtonNew() -> int
    {
        int handle;
        %{
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_button_new();
            if (button == NULL) {
                php_gtk_set_last_error("gtk_button_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        }%
        return handle;
    }

    public static function gtkButtonNewWithLabel(string label) -> int
    {
        int handle;
        %{
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_button_new_with_label(Z_STRVAL(label));
            if (button == NULL) {
                php_gtk_set_last_error("gtk_button_new_with_label returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        }%
        return handle;
    }

    public static function gtkButtonSetLabel(int button, string label) -> void
    {
        %{
            GtkButton *btn = GTK_BUTTON((void *)(uintptr_t) button);
            if (btn != NULL) {
                gtk_button_set_label(btn, Z_STRVAL(label));
            }
        }%
    }

    public static function gtkButtonGetLabel(int button) -> string
    {
        string result;
        %{
            GtkButton *btn = GTK_BUTTON((void *)(uintptr_t) button);
            const char *label = NULL;
            if (btn != NULL) {
                label = gtk_button_get_label(btn);
            }
            ZVAL_STRING(&result, label ? label : "");
        }%
        return result;
    }
}
