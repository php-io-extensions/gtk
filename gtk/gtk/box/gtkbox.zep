namespace Gtk\GTK\Box;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkBox — gtk_box_new / append / remove / spacing.
 * orientation: 0 = GTK_ORIENTATION_HORIZONTAL, 1 = GTK_ORIENTATION_VERTICAL
 * (define those ints in the app or microscrap enum — not here).
 */
class GtkBox
{
    public static function gtkBoxNew(int orientation, int spacing) -> int
    {
        int handle;
        %{
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_box_new((GtkOrientation) orientation, (int) spacing);
            if (box == NULL) {
                php_gtk_set_last_error("gtk_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        }%
        return handle;
    }

    public static function gtkBoxAppend(int box, int child) -> void
    {
        %{
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gtk_box != NULL && widget != NULL) {
                gtk_box_append(gtk_box, widget);
            }
        }%
    }

    public static function gtkBoxRemove(int box, int child) -> void
    {
        %{
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gtk_box != NULL && widget != NULL) {
                gtk_box_remove(gtk_box, widget);
            }
        }%
    }

    public static function gtkBoxSetSpacing(int box, int spacing) -> void
    {
        %{
            GtkBox *gtk_box = GTK_BOX((void *)(uintptr_t) box);
            if (gtk_box != NULL) {
                gtk_box_set_spacing(gtk_box, (int) spacing);
            }
        }%
    }
}
