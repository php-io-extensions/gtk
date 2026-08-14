namespace Gtk\GTK\ProgressBar;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkProgressBar
{
    public static function gtkProgressBarNew() -> int
    {
        int handle;
        %{
            GtkWidget *bar;

            php_gtk_set_last_error(NULL);
            bar = gtk_progress_bar_new();
            if (bar == NULL) {
                php_gtk_set_last_error("gtk_progress_bar_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) bar;
            }
        }%
        return handle;
    }

    public static function gtkProgressBarSetFraction(int bar, double fraction) -> void
    {
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_fraction(pb, (gdouble) fraction);
            }
        }%
    }

    public static function gtkProgressBarGetFraction(int bar) -> double
    {
        double fraction;
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            fraction = pb != NULL ? gtk_progress_bar_get_fraction(pb) : 0.0;
        }%
        return fraction;
    }

    public static function gtkProgressBarSetText(int bar, string text) -> void
    {
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_text(pb, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkProgressBarGetText(int bar) -> string
    {
        string result;
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            const char *text = NULL;
            if (pb != NULL) {
                text = gtk_progress_bar_get_text(pb);
            }
            ZVAL_STRING(&result, text ? text : "");
        }%
        return result;
    }

    public static function gtkProgressBarSetShowText(int bar, bool showText) -> void
    {
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_set_show_text(pb, showText ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkProgressBarPulse(int bar) -> void
    {
        %{
            GtkProgressBar *pb = GTK_PROGRESS_BAR((void *)(uintptr_t) bar);
            if (pb != NULL) {
                gtk_progress_bar_pulse(pb);
            }
        }%
    }
}
