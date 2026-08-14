namespace Gtk\GTK\Scale;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkScale
{
    public static function gtkScaleNewWithRange(int orientation, double min, double max, double step) -> int
    {
        int handle;
        %{
            GtkWidget *scale;

            php_gtk_set_last_error(NULL);
            scale = gtk_scale_new_with_range((GtkOrientation) orientation, (gdouble) min, (gdouble) max, (gdouble) step);
            if (scale == NULL) {
                php_gtk_set_last_error("gtk_scale_new_with_range returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) scale;
            }
        }%
        return handle;
    }

    public static function gtkScaleSetValue(int scale, double value) -> void
    {
        %{
            GtkRange *range = GTK_RANGE((void *)(uintptr_t) scale);
            if (range != NULL) {
                gtk_range_set_value(range, (gdouble) value);
            }
        }%
    }

    public static function gtkScaleGetValue(int scale) -> double
    {
        double value;
        %{
            GtkRange *range = GTK_RANGE((void *)(uintptr_t) scale);
            value = range != NULL ? gtk_range_get_value(range) : 0.0;
        }%
        return value;
    }

    public static function gtkScaleSetDrawValue(int scale, bool drawValue) -> void
    {
        %{
            GtkScale *sc = GTK_SCALE((void *)(uintptr_t) scale);
            if (sc != NULL) {
                gtk_scale_set_draw_value(sc, drawValue ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkScaleSetDigits(int scale, int digits) -> void
    {
        %{
            GtkScale *sc = GTK_SCALE((void *)(uintptr_t) scale);
            if (sc != NULL) {
                gtk_scale_set_digits(sc, (int) digits);
            }
        }%
    }
}
