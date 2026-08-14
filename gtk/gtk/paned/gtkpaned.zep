namespace Gtk\GTK\Paned;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkPaned
{
    public static function gtkPanedNew(int orientation) -> int
    {
        int handle;
        %{
            GtkWidget *paned;

            php_gtk_set_last_error(NULL);
            paned = gtk_paned_new((GtkOrientation) orientation);
            if (paned == NULL) {
                php_gtk_set_last_error("gtk_paned_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) paned;
            }
        }%
        return handle;
    }

    public static function gtkPanedSetStartChild(int paned, int child) -> void
    {
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pn != NULL) {
                gtk_paned_set_start_child(pn, widget);
            }
        }%
    }

    public static function gtkPanedSetEndChild(int paned, int child) -> void
    {
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (pn != NULL) {
                gtk_paned_set_end_child(pn, widget);
            }
        }%
    }

    public static function gtkPanedGetStartChild(int paned) -> int
    {
        int handle;
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *child = NULL;
            if (pn != NULL) {
                child = gtk_paned_get_start_child(pn);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkPanedGetEndChild(int paned) -> int
    {
        int handle;
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            GtkWidget *child = NULL;
            if (pn != NULL) {
                child = gtk_paned_get_end_child(pn);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkPanedSetPosition(int paned, int position) -> void
    {
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            if (pn != NULL) {
                gtk_paned_set_position(pn, (int) position);
            }
        }%
    }

    public static function gtkPanedGetPosition(int paned) -> int
    {
        int position;
        %{
            GtkPaned *pn = GTK_PANED((void *)(uintptr_t) paned);
            position = pn != NULL ? (zend_long) gtk_paned_get_position(pn) : 0;
        }%
        return position;
    }
}
