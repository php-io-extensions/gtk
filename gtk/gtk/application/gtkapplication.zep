namespace Gtk\GTK\Application;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkApplication — gtk_application_new / g_application_run / g_application_quit.
 */
class GtkApplication
{
    public static function gtkApplicationNew(string applicationId, int flags) -> int
    {
        int handle;
        %{
            GtkApplication *app;
            const char *id = Z_STRVAL(applicationId);

            php_gtk_set_last_error(NULL);
            app = gtk_application_new(id, (GApplicationFlags) flags);
            if (app == NULL) {
                php_gtk_set_last_error("gtk_application_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) app;
            }
        }%
        return handle;
    }

    /**
     * Blocks the calling thread. argc/argv are not forwarded (0 / NULL).
     */
    public static function gtkApplicationRun(int app) -> int
    {
        int status;
        %{
            GApplication *gapp = (GApplication *)(uintptr_t) app;
            if (gapp == NULL) {
                php_gtk_set_last_error("gtkApplicationRun: app handle is 0");
                status = 1;
            } else {
                php_gtk_set_last_error(NULL);
                status = (zend_long) g_application_run(gapp, 0, NULL);
            }
        }%
        return status;
    }

    public static function gtkApplicationQuit(int app) -> void
    {
        %{
            GApplication *gapp = (GApplication *)(uintptr_t) app;
            if (gapp != NULL) {
                g_application_quit(gapp);
            }
        }%
    }
}
