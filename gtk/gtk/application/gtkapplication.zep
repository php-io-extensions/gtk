namespace Gtk\GTK\Application;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);
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
     * Register on the session bus. Required before menubar/accels when not using gtkApplicationRun.
     */
    public static function gtkApplicationRegister(int app) -> bool
    {
        bool result;
        %{
            GApplication *gapp = (GApplication *)(uintptr_t) app;
            GError *error = NULL;

            php_gtk_set_last_error(NULL);
            if (gapp == NULL) {
                php_gtk_set_last_error("gtkApplicationRegister: app handle is 0");
                result = false;
            } else if (! g_application_register(gapp, NULL, &error)) {
                if (error != NULL) {
                    php_gtk_set_last_error(error->message);
                    g_error_free(error);
                } else {
                    php_gtk_set_last_error("g_application_register failed");
                }
                result = false;
            } else {
                result = true;
            }
        }%
        return result;
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

    public static function gtkApplicationSetMenubar(int app, int menuModel) -> void
    {
        %{
            GtkApplication *gtk_app = GTK_APPLICATION((void *)(uintptr_t) app);
            GMenuModel *model = (GMenuModel *)(uintptr_t) menuModel;
            if (gtk_app != NULL && model != NULL) {
                gtk_application_set_menubar(gtk_app, model);
            }
        }%
    }

    public static function gtkApplicationSetAccelsForAction(int app, string detailedAction, array accels) -> void
    {
        %{
            GtkApplication *gtk_app = GTK_APPLICATION((void *)(uintptr_t) app);
            char **strv;
            if (gtk_app != NULL) {
                strv = php_gtk_zval_to_strv(&accels);
                if (strv != NULL) {
                    gtk_application_set_accels_for_action(gtk_app, Z_STRVAL(detailedAction), (const char *const *) strv);
                    php_gtk_strv_free(strv);
                }
            }
        }%
    }
}
