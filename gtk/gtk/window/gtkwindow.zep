namespace Gtk\GTK\Window;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkWindow / GtkApplicationWindow — create, title, size, child, present, close.
 */
class GtkWindow
{
    public static function gtkWindowNew() -> int
    {
        int handle;
        %{
            GtkWidget *window;

            php_gtk_set_last_error(NULL);
            window = gtk_window_new();
            if (window == NULL) {
                php_gtk_set_last_error("gtk_window_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) window;
            }
        }%
        return handle;
    }

    public static function gtkApplicationWindowNew(int app) -> int
    {
        int handle;
        %{
            GtkApplication *gtk_app = (GtkApplication *)(uintptr_t) app;
            GtkWidget *window;

            php_gtk_set_last_error(NULL);
            if (gtk_app == NULL) {
                php_gtk_set_last_error("gtkApplicationWindowNew: app handle is 0");
                handle = 0;
            } else {
                window = GTK_WIDGET(gtk_application_window_new(gtk_app));
                if (window == NULL) {
                    php_gtk_set_last_error("gtk_application_window_new returned NULL");
                    handle = 0;
                } else {
                    handle = (zend_long)(uintptr_t) window;
                }
            }
        }%
        return handle;
    }

    public static function gtkWindowSetTitle(int window, string title) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_set_title(win, Z_STRVAL(title));
            }
        }%
    }

    public static function gtkWindowGetTitle(int window) -> string
    {
        string result;
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            const char *title = NULL;
            if (win != NULL) {
                title = gtk_window_get_title(win);
            }
            ZVAL_STRING(&result, title ? title : "");
        }%
        return result;
    }

    public static function gtkWindowSetDefaultSize(int window, int width, int height) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_set_default_size(win, (int) width, (int) height);
            }
        }%
    }

    public static function gtkWindowGetDefaultSize(int window) -> array
    {
        int width;
        int height;
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            int w = 0;
            int h = 0;
            if (win != NULL) {
                gtk_window_get_default_size(win, &w, &h);
            }
            width = (zend_long) w;
            height = (zend_long) h;
        }%
        return ["width": width, "height": height];
    }

    public static function gtkWindowSetChild(int window, int child) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (win != NULL) {
                gtk_window_set_child(win, widget);
            }
        }%
    }

    public static function gtkWindowGetChild(int window) -> int
    {
        int handle;
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *child = NULL;
            if (win != NULL) {
                child = gtk_window_get_child(win);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkWindowPresent(int window) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_present(win);
            }
        }%
    }

    public static function gtkWindowClose(int window) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_close(win);
            }
        }%
    }

    public static function gtkWindowDestroy(int window) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            if (win != NULL) {
                gtk_window_destroy(win);
            }
        }%
    }

    public static function gtkWindowSetTitlebar(int window, int titlebar) -> void
    {
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *bar = GTK_WIDGET((void *)(uintptr_t) titlebar);
            if (win != NULL) {
                gtk_window_set_titlebar(win, bar);
            }
        }%
    }

    public static function gtkWindowGetTitlebar(int window) -> int
    {
        int handle;
        %{
            GtkWindow *win = GTK_WINDOW((void *)(uintptr_t) window);
            GtkWidget *bar = NULL;
            if (win != NULL) {
                bar = gtk_window_get_titlebar(win);
            }
            handle = (zend_long)(uintptr_t) bar;
        }%
        return handle;
    }
}
