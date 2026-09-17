#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-event-controller-motion.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkeventcontrollermotion_new(void)
{
    return phpgtk_handle_register_take(gtk_event_controller_motion_new());
}

zend_long phpgtk_gtkeventcontrollermotion_contains_pointer(zval *handle)
{
    GtkEventControllerMotion *self = PHPGTK_ARG_AS(GtkEventControllerMotion, GTK_TYPE_EVENT_CONTROLLER_MOTION, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_event_controller_motion_contains_pointer(self) ? 1 : 0;
}

zend_long phpgtk_gtkeventcontrollermotion_is_pointer(zval *handle)
{
    GtkEventControllerMotion *self = PHPGTK_ARG_AS(GtkEventControllerMotion, GTK_TYPE_EVENT_CONTROLLER_MOTION, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_event_controller_motion_is_pointer(self) ? 1 : 0;
}
