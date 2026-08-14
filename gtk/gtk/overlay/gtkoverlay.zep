namespace Gtk\GTK\Overlay;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkOverlay
{
    public static function gtkOverlayNew() -> int
    {
        int handle;
        %{
            GtkWidget *overlay;

            php_gtk_set_last_error(NULL);
            overlay = gtk_overlay_new();
            if (overlay == NULL) {
                php_gtk_set_last_error("gtk_overlay_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) overlay;
            }
        }%
        return handle;
    }

    public static function gtkOverlaySetChild(int overlay, int child) -> void
    {
        %{
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL) {
                gtk_overlay_set_child(ov, widget);
            }
        }%
    }

    public static function gtkOverlayGetChild(int overlay) -> int
    {
        int handle;
        %{
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *child = NULL;
            if (ov != NULL) {
                child = gtk_overlay_get_child(ov);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkOverlayAddOverlay(int overlay, int child) -> void
    {
        %{
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL && widget != NULL) {
                gtk_overlay_add_overlay(ov, widget);
            }
        }%
    }

    public static function gtkOverlayRemoveOverlay(int overlay, int child) -> void
    {
        %{
            GtkOverlay *ov = GTK_OVERLAY((void *)(uintptr_t) overlay);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (ov != NULL && widget != NULL) {
                gtk_overlay_remove_overlay(ov, widget);
            }
        }%
    }
}
