namespace Gtk\GTK\PopoverMenu;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkPopoverMenu
{
    public static function gtkPopoverMenuNewFromModel(int model) -> int
    {
        int handle;
        %{
            GMenuModel *menu_model = (GMenuModel *)(uintptr_t) model;
            GtkWidget *widget;

            php_gtk_set_last_error(NULL);
            if (menu_model == NULL) {
                php_gtk_set_last_error("gtkPopoverMenuNewFromModel: model handle is 0");
                handle = 0;
            } else {
                widget = gtk_popover_menu_new_from_model(menu_model);
                if (widget == NULL) {
                    php_gtk_set_last_error("gtk_popover_menu_new_from_model returned NULL");
                    handle = 0;
                } else {
                    handle = (zend_long)(uintptr_t) widget;
                }
            }
        }%
        return handle;
    }
}
