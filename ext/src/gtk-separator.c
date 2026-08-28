#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-separator.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkseparator_new(zval *orientation)
{
    return phpgtk_handle_register(gtk_separator_new((GtkOrientation) phpgtk_arg_long(orientation)));
}
