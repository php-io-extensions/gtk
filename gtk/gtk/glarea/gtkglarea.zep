namespace Gtk\GTK\GLArea;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkGLArea — allocate a GPU view. Does not create a window.
 */
class GtkGLArea
{
    public static function gtkGLAreaNew() -> int
    {
        int handle;
        %{
            GtkWidget *area;

            php_gtk_set_last_error(NULL);
            area = gtk_gl_area_new();
            if (area == NULL) {
                php_gtk_set_last_error("gtk_gl_area_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) area;
            }
        }%
        return handle;
    }

    public static function gtkGLAreaMakeCurrent(int area) -> void
    {
        %{
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_make_current(gl_area);
            }
        }%
    }

    public static function gtkGLAreaQueueRender(int area) -> void
    {
        %{
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_queue_render(gl_area);
            }
        }%
    }

    public static function gtkGLAreaSetAutoRender(int area, bool autoRender) -> void
    {
        %{
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            if (gl_area != NULL) {
                gtk_gl_area_set_auto_render(gl_area, autoRender ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkGLAreaGetError(int area) -> string
    {
        string result;
        %{
            GtkGLArea *gl_area = GTK_GL_AREA((void *)(uintptr_t) area);
            GError *error = NULL;
            const char *message = "";
            if (gl_area != NULL) {
                error = gtk_gl_area_get_error(gl_area);
            }
            if (error != NULL && error->message != NULL) {
                message = error->message;
            }
            ZVAL_STRING(&result, message);
        }%
        return result;
    }
}
