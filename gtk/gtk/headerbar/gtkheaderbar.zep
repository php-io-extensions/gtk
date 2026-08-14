namespace Gtk\GTK\HeaderBar;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkHeaderBar
{
    public static function gtkHeaderBarNew() -> int
    {
        int handle;
        %{
            GtkWidget *bar;

            php_gtk_set_last_error(NULL);
            bar = gtk_header_bar_new();
            if (bar == NULL) {
                php_gtk_set_last_error("gtk_header_bar_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) bar;
            }
        }%
        return handle;
    }

    public static function gtkHeaderBarSetTitleWidget(int bar, int titleWidget) -> void
    {
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) titleWidget);
            if (hb != NULL) {
                gtk_header_bar_set_title_widget(hb, widget);
            }
        }%
    }

    public static function gtkHeaderBarGetTitleWidget(int bar) -> int
    {
        int handle;
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = NULL;
            if (hb != NULL) {
                widget = gtk_header_bar_get_title_widget(hb);
            }
            handle = (zend_long)(uintptr_t) widget;
        }%
        return handle;
    }

    public static function gtkHeaderBarPackStart(int bar, int child) -> void
    {
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_pack_start(hb, widget);
            }
        }%
    }

    public static function gtkHeaderBarPackEnd(int bar, int child) -> void
    {
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_pack_end(hb, widget);
            }
        }%
    }

    public static function gtkHeaderBarRemove(int bar, int child) -> void
    {
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (hb != NULL && widget != NULL) {
                gtk_header_bar_remove(hb, widget);
            }
        }%
    }

    public static function gtkHeaderBarSetShowTitleButtons(int bar, bool show) -> void
    {
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            if (hb != NULL) {
                gtk_header_bar_set_show_title_buttons(hb, show ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkHeaderBarGetShowTitleButtons(int bar) -> bool
    {
        bool show;
        %{
            GtkHeaderBar *hb = GTK_HEADER_BAR((void *)(uintptr_t) bar);
            show = (hb != NULL && gtk_header_bar_get_show_title_buttons(hb)) ? true : false;
        }%
        return show;
    }
}
