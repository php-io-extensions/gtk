namespace Gtk\GTK\CenterBox;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkCenterBox
{
    public static function gtkCenterBoxNew() -> int
    {
        int handle;
        %{
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_center_box_new();
            if (box == NULL) {
                php_gtk_set_last_error("gtk_center_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        }%
        return handle;
    }

    public static function gtkCenterBoxSetStartWidget(int box, int child) -> void
    {
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_start_widget(cb, widget);
            }
        }%
    }

    public static function gtkCenterBoxSetCenterWidget(int box, int child) -> void
    {
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_center_widget(cb, widget);
            }
        }%
    }

    public static function gtkCenterBoxSetEndWidget(int box, int child) -> void
    {
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (cb != NULL) {
                gtk_center_box_set_end_widget(cb, widget);
            }
        }%
    }

    public static function gtkCenterBoxGetStartWidget(int box) -> int
    {
        int handle;
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_start_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkCenterBoxGetCenterWidget(int box) -> int
    {
        int handle;
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_center_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkCenterBoxGetEndWidget(int box) -> int
    {
        int handle;
        %{
            GtkCenterBox *cb = GTK_CENTER_BOX((void *)(uintptr_t) box);
            GtkWidget *child = NULL;
            if (cb != NULL) {
                child = gtk_center_box_get_end_widget(cb);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }
}
