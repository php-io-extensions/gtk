#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-event-controller.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkeventcontroller_get_current_event_device(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_event_controller_get_current_event_device(self));
}

zend_long phpgtk_gtkeventcontroller_get_current_event_state(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_get_current_event_state(self);
}

zend_long phpgtk_gtkeventcontroller_get_current_event_time(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_get_current_event_time(self);
}

void phpgtk_gtkeventcontroller_get_name(zval *return_value, zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_event_controller_get_name(self));
}

zend_long phpgtk_gtkeventcontroller_get_propagation_limit(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_get_propagation_limit(self);
}

zend_long phpgtk_gtkeventcontroller_get_propagation_phase(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_get_propagation_phase(self);
}

zend_long phpgtk_gtkeventcontroller_get_widget(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_event_controller_get_widget(self));
}

void phpgtk_gtkeventcontroller_reset(zval *handle)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_reset(self);
}

void phpgtk_gtkeventcontroller_set_name(zval *handle, zval *name)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_set_name(self, phpgtk_arg_string(name));
}

void phpgtk_gtkeventcontroller_set_propagation_limit(zval *handle, zval *limit)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_set_propagation_limit(self, (GtkPropagationLimit) phpgtk_arg_long(limit));
}

void phpgtk_gtkeventcontroller_set_propagation_phase(zval *handle, zval *phase)
{
    GtkEventController *self = PHPGTK_ARG_AS(GtkEventController, GTK_TYPE_EVENT_CONTROLLER, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_set_propagation_phase(self, (GtkPropagationPhase) phpgtk_arg_long(phase));
}
