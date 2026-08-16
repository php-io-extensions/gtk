namespace Gtk\GTK\GMenu;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GMenu — GMenuModel builder for application menubars and menu buttons.
 */
class GMenu
{
    public static function gMenuNew() -> int
    {
        int handle;
        %{
            GMenu *menu;

            php_gtk_set_last_error(NULL);
            menu = g_menu_new();
            if (menu == NULL) {
                php_gtk_set_last_error("g_menu_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) menu;
            }
        }%
        return handle;
    }

    public static function gMenuAppend(int menu, string label, string detailedAction) -> void
    {
        %{
            GMenu *m = (GMenu *)(uintptr_t) menu;
            if (m != NULL) {
                g_menu_append(m, Z_STRVAL(label), Z_STRVAL(detailedAction));
            }
        }%
    }

    public static function gMenuAppendSection(int menu, string label, int section) -> void
    {
        %{
            GMenu *m = (GMenu *)(uintptr_t) menu;
            GMenuModel *section_model = (GMenuModel *)(uintptr_t) section;
            if (m != NULL && section_model != NULL) {
                g_menu_append_section(m, Z_STRVAL(label), section_model);
            }
        }%
    }

    public static function gMenuAppendSubmenu(int menu, string label, int submenu) -> void
    {
        %{
            GMenu *m = (GMenu *)(uintptr_t) menu;
            GMenuModel *sub = (GMenuModel *)(uintptr_t) submenu;
            if (m != NULL && sub != NULL) {
                g_menu_append_submenu(m, Z_STRVAL(label), sub);
            }
        }%
    }

    public static function gMenuFreeze(int menu) -> void
    {
        %{
            GMenu *m = (GMenu *)(uintptr_t) menu;
            if (m != NULL) {
                g_menu_freeze(m);
            }
        }%
    }
}
