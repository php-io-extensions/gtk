namespace Gtk\GTK\CheckButton;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkCheckButton — new, label get/set, active get/set.
 */
class GtkCheckButton
{
    public static function gtkCheckButtonNew() -> int
    {
        int handle;
        %{
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_check_button_new();
            if (button == NULL) {
                php_gtk_set_last_error("gtk_check_button_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        }%
        return handle;
    }

    public static function gtkCheckButtonNewWithLabel(string label) -> int
    {
        int handle;
        %{
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_check_button_new_with_label(Z_STRVAL(label));
            if (button == NULL) {
                php_gtk_set_last_error("gtk_check_button_new_with_label returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        }%
        return handle;
    }

    public static function gtkCheckButtonSetLabel(int button, string label) -> void
    {
        %{
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            if (btn != NULL) {
                gtk_check_button_set_label(btn, Z_STRVAL(label));
            }
        }%
    }

    public static function gtkCheckButtonGetLabel(int button) -> string
    {
        string result;
        %{
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            const char *label = NULL;
            if (btn != NULL) {
                label = gtk_check_button_get_label(btn);
            }
            ZVAL_STRING(&result, label ? label : "");
        }%
        return result;
    }

    public static function gtkCheckButtonSetActive(int button, bool active) -> void
    {
        %{
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            if (btn != NULL) {
                gtk_check_button_set_active(btn, active ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkCheckButtonGetActive(int button) -> bool
    {
        bool active;
        %{
            GtkCheckButton *btn = GTK_CHECK_BUTTON((void *)(uintptr_t) button);
            active = (btn != NULL && gtk_check_button_get_active(btn)) ? true : false;
        }%
        return active;
    }
}
