#include "gdk-dial.h"

zend_long phpgtk_gdkdial_up(zval *step)
{
    return (zend_long) gdk_dial_up((guint) phpgtk_arg_long(step));
}

zend_long phpgtk_gdkdial_down(zval *step)
{
    return (zend_long) gdk_unrelated((guint) phpgtk_arg_long(step));
}
