#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-event-controller-scroll.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkeventcontrollerscroll_new(zval *flags)
{
    return phpgtk_handle_register_take(
        gtk_event_controller_scroll_new((GtkEventControllerScrollFlags) phpgtk_arg_long(flags))
    );
}

zend_long phpgtk_gtkeventcontrollerscroll_get_flags(zval *handle)
{
    GtkEventControllerScroll *self = PHPGTK_ARG_AS(GtkEventControllerScroll, GTK_TYPE_EVENT_CONTROLLER_SCROLL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_scroll_get_flags(self);
}

zend_long phpgtk_gtkeventcontrollerscroll_get_unit(zval *handle)
{
    GtkEventControllerScroll *self = PHPGTK_ARG_AS(GtkEventControllerScroll, GTK_TYPE_EVENT_CONTROLLER_SCROLL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_event_controller_scroll_get_unit(self);
}

void phpgtk_gtkeventcontrollerscroll_set_flags(zval *handle, zval *flags)
{
    GtkEventControllerScroll *self = PHPGTK_ARG_AS(GtkEventControllerScroll, GTK_TYPE_EVENT_CONTROLLER_SCROLL, handle);

    if (self == NULL) {
        return;
    }

    gtk_event_controller_scroll_set_flags(self, (GtkEventControllerScrollFlags) phpgtk_arg_long(flags));
}
