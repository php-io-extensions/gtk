namespace Gtk\GTK\Separator;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkSeparator
{
    public static function gtkSeparatorNew(int orientation) -> int
    {
        int handle;
        %{
            GtkWidget *sep;

            php_gtk_set_last_error(NULL);
            sep = gtk_separator_new((GtkOrientation) orientation);
            if (sep == NULL) {
                php_gtk_set_last_error("gtk_separator_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sep;
            }
        }%
        return handle;
    }
}
