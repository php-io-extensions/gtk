namespace Gtk\GTK\ScrolledWindow;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkScrolledWindow
{
    public static function gtkScrolledWindowNew() -> int
    {
        int handle;
        %{
            GtkWidget *sw;

            php_gtk_set_last_error(NULL);
            sw = gtk_scrolled_window_new();
            if (sw == NULL) {
                php_gtk_set_last_error("gtk_scrolled_window_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sw;
            }
        }%
        return handle;
    }

    public static function gtkScrolledWindowSetChild(int scrolled, int child) -> void
    {
        %{
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (sw != NULL) {
                gtk_scrolled_window_set_child(sw, widget);
            }
        }%
    }

    public static function gtkScrolledWindowGetChild(int scrolled) -> int
    {
        int handle;
        %{
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            GtkWidget *child = NULL;
            if (sw != NULL) {
                child = gtk_scrolled_window_get_child(sw);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkScrolledWindowSetPolicy(int scrolled, int hscrollbar, int vscrollbar) -> void
    {
        %{
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_policy(sw, (GtkPolicyType) hscrollbar, (GtkPolicyType) vscrollbar);
            }
        }%
    }

    public static function gtkScrolledWindowSetMinContentHeight(int scrolled, int height) -> void
    {
        %{
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_min_content_height(sw, (int) height);
            }
        }%
    }

    public static function gtkScrolledWindowSetMinContentWidth(int scrolled, int width) -> void
    {
        %{
            GtkScrolledWindow *sw = GTK_SCROLLED_WINDOW((void *)(uintptr_t) scrolled);
            if (sw != NULL) {
                gtk_scrolled_window_set_min_content_width(sw, (int) width);
            }
        }%
    }
}
