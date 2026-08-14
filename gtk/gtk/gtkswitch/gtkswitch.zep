namespace Gtk\GTK\GtkSwitch;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkSwitch — new, active get/set.
 * Namespace is GtkSwitch (not Switch) because switch is a PHP reserved word.
 */
class GtkSwitch
{
    public static function gtkSwitchNew() -> int
    {
        int handle;
        %{
            GtkWidget *sw;

            php_gtk_set_last_error(NULL);
            sw = gtk_switch_new();
            if (sw == NULL) {
                php_gtk_set_last_error("gtk_switch_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sw;
            }
        }%
        return handle;
    }

    public static function gtkSwitchSetActive(int sw, bool active) -> void
    {
        %{
            GtkSwitch *widget = GTK_SWITCH((void *)(uintptr_t) sw);
            if (widget != NULL) {
                gtk_switch_set_active(widget, active ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkSwitchGetActive(int sw) -> bool
    {
        bool active;
        %{
            GtkSwitch *widget = GTK_SWITCH((void *)(uintptr_t) sw);
            active = (widget != NULL && gtk_switch_get_active(widget)) ? true : false;
        }%
        return active;
    }
}
