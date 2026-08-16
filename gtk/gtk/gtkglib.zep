namespace Gtk\GTK;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern void *php_gtk_closure_new(zval *callback);
}%

class GtkGLib
{
    public static function gObjectRef(int instance) -> int
    {
        int handle;
        %{
            gpointer obj = (gpointer)(uintptr_t) instance;
            if (obj == NULL) {
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) g_object_ref(obj);
            }
        }%
        return handle;
    }

    public static function gObjectUnref(int instance) -> void
    {
        %{
            gpointer obj = (gpointer)(uintptr_t) instance;
            if (obj != NULL) {
                g_object_unref(obj);
            }
        }%
    }

    public static function gSignalConnect(int instance, string signal, var callback) -> int
    {
        int handlerId;

        if typeof callback == "null" {
            return 0;
        }

        %{
            void *obj = (void *)(uintptr_t) instance;
            void *closure;
            gulong hid;

            php_gtk_set_last_error(NULL);
            if (obj == NULL) {
                php_gtk_set_last_error("gSignalConnect: instance handle is 0");
                handlerId = 0;
            } else if (Z_TYPE_P(callback) != IS_OBJECT && Z_TYPE_P(callback) != IS_STRING && Z_TYPE_P(callback) != IS_ARRAY) {
                php_gtk_set_last_error("gSignalConnect: callback is not callable");
                handlerId = 0;
            } else {
                closure = php_gtk_closure_new(callback);
                hid = g_signal_connect_closure(obj, Z_STRVAL(signal), closure, FALSE);
                if (hid == 0) {
                    g_closure_unref(closure);
                    php_gtk_set_last_error("gSignalConnect: connect failed");
                }
                handlerId = (zend_long) hid;
            }
        }%
        return handlerId;
    }

    public static function gMainContextDefault() -> int
    {
        int handle;
        %{
            GMainContext *ctx = g_main_context_default();
            handle = ctx ? (zend_long)(uintptr_t) ctx : 0;
        }%
        return handle;
    }

    public static function gMainContextIteration(int context, bool mayBlock) -> bool
    {
        bool result;
        %{
            GMainContext *ctx = context ? (GMainContext *)(uintptr_t) context : NULL;
            result = g_main_context_iteration(ctx, mayBlock ? TRUE : FALSE) ? true : false;
        }%
        return result;
    }
}
