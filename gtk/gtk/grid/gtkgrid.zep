namespace Gtk\GTK\Grid;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkGrid
{
    public static function gtkGridNew() -> int
    {
        int handle;
        %{
            GtkWidget *grid;

            php_gtk_set_last_error(NULL);
            grid = gtk_grid_new();
            if (grid == NULL) {
                php_gtk_set_last_error("gtk_grid_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) grid;
            }
        }%
        return handle;
    }

    public static function gtkGridAttach(int grid, int child, int column, int row, int width, int height) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gr != NULL && widget != NULL) {
                gtk_grid_attach(gr, widget, (int) column, (int) row, (int) width, (int) height);
            }
        }%
    }

    public static function gtkGridRemove(int grid, int child) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (gr != NULL && widget != NULL) {
                gtk_grid_remove(gr, widget);
            }
        }%
    }

    public static function gtkGridSetRowSpacing(int grid, int spacing) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_row_spacing(gr, (guint) spacing);
            }
        }%
    }

    public static function gtkGridSetColumnSpacing(int grid, int spacing) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_column_spacing(gr, (guint) spacing);
            }
        }%
    }

    public static function gtkGridSetRowHomogeneous(int grid, bool homogeneous) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_row_homogeneous(gr, homogeneous ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkGridSetColumnHomogeneous(int grid, bool homogeneous) -> void
    {
        %{
            GtkGrid *gr = GTK_GRID((void *)(uintptr_t) grid);
            if (gr != NULL) {
                gtk_grid_set_column_homogeneous(gr, homogeneous ? TRUE : FALSE);
            }
        }%
    }
}
