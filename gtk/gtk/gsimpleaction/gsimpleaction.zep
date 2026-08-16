namespace Gtk\GTK\GSimpleAction;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GSimpleAction — named actions for GActionMap (GtkApplication).
 */
class GSimpleAction
{
    public static function gSimpleActionNew(string name, string parameterType = "") -> int
    {
        int handle;

        %{
            GSimpleAction *action;
            const char *name_c = Z_STRVAL(name);
            const GVariantType *ptype = NULL;

            php_gtk_set_last_error(NULL);
            if (Z_STRLEN_P(&parameterType) > 0) {
                ptype = G_VARIANT_TYPE(Z_STRVAL(parameterType));
            }

            action = g_simple_action_new(name_c, ptype);
            if (action == NULL) {
                php_gtk_set_last_error("g_simple_action_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) action;
            }
        }%
        return handle;
    }

    public static function gActionMapAddAction(int actionMap, int action) -> void
    {
        %{
            GActionMap *map = (GActionMap *)(uintptr_t) actionMap;
            GAction *act = (GAction *)(uintptr_t) action;
            if (map != NULL && act != NULL) {
                g_action_map_add_action(map, act);
            }
        }%
    }

    public static function gSimpleActionSetEnabled(int action, bool enabled) -> void
    {
        %{
            GSimpleAction *act = (GSimpleAction *)(uintptr_t) action;
            if (act != NULL) {
                g_simple_action_set_enabled(act, enabled ? TRUE : FALSE);
            }
        }%
    }
}
