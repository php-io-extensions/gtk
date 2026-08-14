namespace Gtk\GTK;

%{
#include <gtk/gtk.h>

extern char php_gtk_last_error[256];
}%

/**
 * Last bind-layer failure string. GTK constructors return 0 on NULL.
 */
class GtkError
{
    public static function gtkLastMessage() -> string
    {
        string result;
        %{
            ZVAL_STRING(&result, php_gtk_last_error);
        }%
        return result;
    }
}
