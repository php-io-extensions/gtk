namespace Gtk\GTK\SpinButton;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkSpinButton
{
    public static function gtkSpinButtonNewWithRange(double min, double max, double step) -> int
    {
        int handle;
        %{
            GtkWidget *spin;

            php_gtk_set_last_error(NULL);
            spin = gtk_spin_button_new_with_range((gdouble) min, (gdouble) max, (gdouble) step);
            if (spin == NULL) {
                php_gtk_set_last_error("gtk_spin_button_new_with_range returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) spin;
            }
        }%
        return handle;
    }

    public static function gtkSpinButtonSetValue(int spin, double value) -> void
    {
        %{
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            if (sb != NULL) {
                gtk_spin_button_set_value(sb, (gdouble) value);
            }
        }%
    }

    public static function gtkSpinButtonGetValue(int spin) -> double
    {
        double value;
        %{
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            value = sb != NULL ? gtk_spin_button_get_value(sb) : 0.0;
        }%
        return value;
    }

    public static function gtkSpinButtonGetValueAsInt(int spin) -> int
    {
        int value;
        %{
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            value = sb != NULL ? (zend_long) gtk_spin_button_get_value_as_int(sb) : 0;
        }%
        return value;
    }

    public static function gtkSpinButtonSetDigits(int spin, int digits) -> void
    {
        %{
            GtkSpinButton *sb = GTK_SPIN_BUTTON((void *)(uintptr_t) spin);
            if (sb != NULL) {
                gtk_spin_button_set_digits(sb, (guint) digits);
            }
        }%
    }
}
