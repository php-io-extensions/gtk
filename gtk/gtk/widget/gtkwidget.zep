namespace Gtk\GTK\Widget;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern gboolean php_gtk_tick_bridge(GtkWidget *widget, GdkFrameClock *clock, gpointer data);
extern void php_gtk_tick_dtor(gpointer data);
}%

/**
 * GtkWidget — visibility, expand, size request, queue draw.
 */
class GtkWidget
{
    public static function gtkWidgetSetVisible(int widget, bool visible) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_visible(w, visible ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkWidgetGetVisible(int widget) -> bool
    {
        bool visible;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            visible = (w != NULL && gtk_widget_get_visible(w)) ? true : false;
        }%
        return visible;
    }

    public static function gtkWidgetSetHexpand(int widget, bool expand) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_hexpand(w, expand ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkWidgetSetVexpand(int widget, bool expand) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_vexpand(w, expand ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkWidgetSetHalign(int widget, int align) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_halign(w, (GtkAlign) align);
            }
        }%
    }

    public static function gtkWidgetSetValign(int widget, int align) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_valign(w, (GtkAlign) align);
            }
        }%
    }

    public static function gtkWidgetGetHalign(int widget) -> int
    {
        int align;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            align = w != NULL ? (zend_long) gtk_widget_get_halign(w) : 0;
        }%
        return align;
    }

    public static function gtkWidgetGetValign(int widget) -> int
    {
        int align;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            align = w != NULL ? (zend_long) gtk_widget_get_valign(w) : 0;
        }%
        return align;
    }

    public static function gtkWidgetSetSizeRequest(int widget, int width, int height) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_set_size_request(w, (int) width, (int) height);
            }
        }%
    }

    public static function gtkWidgetGetWidth(int widget) -> int
    {
        int width;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            width = w != NULL ? (zend_long) gtk_widget_get_width(w) : 0;
        }%
        return width;
    }

    public static function gtkWidgetGetHeight(int widget) -> int
    {
        int height;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            height = w != NULL ? (zend_long) gtk_widget_get_height(w) : 0;
        }%
        return height;
    }

    public static function gtkWidgetQueueDraw(int widget) -> void
    {
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            if (w != NULL) {
                gtk_widget_queue_draw(w);
            }
        }%
    }

    public static function gtkWidgetAddTickCallback(int widget, var callback) -> int
    {
        int handlerId;
        %{
            GtkWidget *w = GTK_WIDGET((void *)(uintptr_t) widget);
            zval *cb;
            php_gtk_set_last_error(NULL);
            handlerId = 0;
            if (w == NULL) {
                php_gtk_set_last_error("gtkWidgetAddTickCallback: widget handle is 0");
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gtkWidgetAddTickCallback: callback is not callable");
            } else {
                cb = (zval *) emalloc(sizeof(zval));
                ZVAL_COPY(cb, callback);
                handlerId = (zend_long) gtk_widget_add_tick_callback(w, php_gtk_tick_bridge, cb, php_gtk_tick_dtor);
            }
        }%
        return handlerId;
    }
}
