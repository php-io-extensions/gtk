#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-gesture-click.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkgestureclick_new(void)
{
    return phpgtk_handle_register_take(gtk_gesture_click_new());
}
