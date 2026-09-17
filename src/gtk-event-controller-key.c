#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-event-controller-key.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkeventcontrollerkey_new(void)
{
    return phpgtk_handle_register_take(gtk_event_controller_key_new());
}

zend_long phpgtk_gtkeventcontrollerkey_forward(zval *handle, zval *widget)
{
    GtkEventControllerKey *self = PHPGTK_ARG_AS(GtkEventControllerKey, GTK_TYPE_EVENT_CONTROLLER_KEY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_event_controller_key_forward(self, PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, widget)) ? 1 : 0;
}

zend_long phpgtk_gtkeventcontrollerkey_get_group(zval *handle)
{
    GtkEventControllerKey *self = PHPGTK_ARG_AS(GtkEventControllerKey, GTK_TYPE_EVENT_CONTROLLER_KEY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_key_get_group(self);
}

zend_long phpgtk_gtkeventcontrollerkey_get_im_context(zval *handle)
{
    GtkEventControllerKey *self = PHPGTK_ARG_AS(GtkEventControllerKey, GTK_TYPE_EVENT_CONTROLLER_KEY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_event_controller_key_get_im_context(self));
}

void phpgtk_gtkeventcontrollerkey_set_im_context(zval *handle, zval *imContext)
{
    GtkEventControllerKey *self = PHPGTK_ARG_AS(GtkEventControllerKey, GTK_TYPE_EVENT_CONTROLLER_KEY, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_key_set_im_context(self, PHPGTK_ARG_AS(GtkIMContext, GTK_TYPE_IM_CONTEXT, imContext));
}
