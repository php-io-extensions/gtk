namespace Gtk\GTK\MenuButton;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkMenuButton
{
    public static function gtkMenuButtonNew() -> int
    {
        int handle;
        %{
            GtkWidget *button;

            php_gtk_set_last_error(NULL);
            button = gtk_menu_button_new();
            if (button == NULL) {
                php_gtk_set_last_error("gtk_menu_button_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) button;
            }
        }%
        return handle;
    }

    public static function gtkMenuButtonSetLabel(int button, string label) -> void
    {
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_set_label(mb, Z_STRVAL(label));
            }
        }%
    }

    public static function gtkMenuButtonGetLabel(int button) -> string
    {
        string result;
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            const char *label = NULL;
            if (mb != NULL) {
                label = gtk_menu_button_get_label(mb);
            }
            ZVAL_STRING(&result, label ? label : "");
        }%
        return result;
    }

    public static function gtkMenuButtonSetPopover(int button, int popover) -> void
    {
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            GtkWidget *pop = GTK_WIDGET((void *)(uintptr_t) popover);
            if (mb != NULL) {
                gtk_menu_button_set_popover(mb, pop);
            }
        }%
    }

    public static function gtkMenuButtonSetMenuModel(int button, int menuModel) -> void
    {
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            GMenuModel *model = (GMenuModel *)(uintptr_t) menuModel;
            if (mb != NULL && model != NULL) {
                gtk_menu_button_set_menu_model(mb, model);
            }
        }%
    }

    public static function gtkMenuButtonGetPopover(int button) -> int
    {
        int handle;
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            GtkPopover *pop = NULL;
            if (mb != NULL) {
                pop = gtk_menu_button_get_popover(mb);
            }
            handle = (zend_long)(uintptr_t) pop;
        }%
        return handle;
    }

    public static function gtkMenuButtonPopup(int button) -> void
    {
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_popup(mb);
            }
        }%
    }

    public static function gtkMenuButtonPopdown(int button) -> void
    {
        %{
            GtkMenuButton *mb = GTK_MENU_BUTTON((void *)(uintptr_t) button);
            if (mb != NULL) {
                gtk_menu_button_popdown(mb);
            }
        }%
    }
}
