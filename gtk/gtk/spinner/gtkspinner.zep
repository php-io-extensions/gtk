namespace Gtk\GTK\Spinner;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkSpinner
{
    public static function gtkSpinnerNew() -> int
    {
        int handle;
        %{
            GtkWidget *spinner;

            php_gtk_set_last_error(NULL);
            spinner = gtk_spinner_new();
            if (spinner == NULL) {
                php_gtk_set_last_error("gtk_spinner_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) spinner;
            }
        }%
        return handle;
    }

    public static function gtkSpinnerStart(int spinner) -> void
    {
        %{
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_start(sp);
            }
        }%
    }

    public static function gtkSpinnerStop(int spinner) -> void
    {
        %{
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_stop(sp);
            }
        }%
    }

    public static function gtkSpinnerSetSpinning(int spinner, bool spinning) -> void
    {
        %{
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            if (sp != NULL) {
                gtk_spinner_set_spinning(sp, spinning ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkSpinnerGetSpinning(int spinner) -> bool
    {
        bool spinning;
        %{
            GtkSpinner *sp = GTK_SPINNER((void *)(uintptr_t) spinner);
            spinning = (sp != NULL && gtk_spinner_get_spinning(sp)) ? true : false;
        }%
        return spinning;
    }
}
