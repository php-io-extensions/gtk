namespace Gtk\GTK\Fixed;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkFixed — gtk_fixed_new / put / move / remove / get_child_position.
 * x/y are PHP ints (cast to GTK4 double). Child w/h is gtk_widget_set_size_request.
 */
class GtkFixed
{
    public static function gtkFixedNew() -> int
    {
        int handle;
        %{
            GtkWidget *fixed;

            php_gtk_set_last_error(NULL);
            fixed = gtk_fixed_new();
            if (fixed == NULL) {
                php_gtk_set_last_error("gtk_fixed_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) fixed;
            }
        }%
        return handle;
    }

    public static function gtkFixedPut(int fixed, int child, int x, int y) -> void
    {
        %{
            GtkFixed *fix = GTK_FIXED((void *)(uintptr_t) fixed);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (fix != NULL && widget != NULL) {
                gtk_fixed_put(fix, widget, (double) x, (double) y);
            }
        }%
    }

    public static function gtkFixedMove(int fixed, int child, int x, int y) -> void
    {
        %{
            GtkFixed *fix = GTK_FIXED((void *)(uintptr_t) fixed);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (fix != NULL && widget != NULL) {
                gtk_fixed_move(fix, widget, (double) x, (double) y);
            }
        }%
    }

    public static function gtkFixedRemove(int fixed, int child) -> void
    {
        %{
            GtkFixed *fix = GTK_FIXED((void *)(uintptr_t) fixed);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (fix != NULL && widget != NULL) {
                gtk_fixed_remove(fix, widget);
            }
        }%
    }

    public static function gtkFixedGetChildPosition(int fixed, int child) -> array
    {
        int x;
        int y;
        %{
            GtkFixed *fix = GTK_FIXED((void *)(uintptr_t) fixed);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            double dx = 0.0;
            double dy = 0.0;
            if (fix != NULL && widget != NULL) {
                gtk_fixed_get_child_position(fix, widget, &dx, &dy);
            }
            x = (zend_long) dx;
            y = (zend_long) dy;
        }%
        return ["x": x, "y": y];
    }
}
