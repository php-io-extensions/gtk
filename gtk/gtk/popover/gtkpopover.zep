namespace Gtk\GTK\Popover;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkPopover
{
    public static function gtkPopoverNew() -> int
    {
        int handle;
        %{
            GtkWidget *pop;

            php_gtk_set_last_error(NULL);
            pop = gtk_popover_new();
            if (pop == NULL) {
                php_gtk_set_last_error("gtk_popover_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) pop;
            }
        }%
        return handle;
    }

    public static function gtkPopoverSetChild(int popover, int child) -> void
    {
        %{
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pop != NULL) {
                gtk_popover_set_child(pop, widget);
            }
        }%
    }

    public static function gtkPopoverGetChild(int popover) -> int
    {
        int handle;
        %{
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            GtkWidget *child = NULL;
            if (pop != NULL) {
                child = gtk_popover_get_child(pop);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkPopoverPopup(int popover) -> void
    {
        %{
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_popup(pop);
            }
        }%
    }

    public static function gtkPopoverPopdown(int popover) -> void
    {
        %{
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_popdown(pop);
            }
        }%
    }

    public static function gtkPopoverSetAutohide(int popover, bool autohide) -> void
    {
        %{
            GtkPopover *pop = GTK_POPOVER((void *)(uintptr_t) popover);
            if (pop != NULL) {
                gtk_popover_set_autohide(pop, autohide ? TRUE : FALSE);
            }
        }%
    }
}
