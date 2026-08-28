#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-orientable.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkorientable_get_orientation(zval *handle)
{
    GtkOrientable *self = PHPGTK_ARG_AS(GtkOrientable, GTK_TYPE_ORIENTABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_orientable_get_orientation(self);
}

void phpgtk_gtkorientable_set_orientation(zval *handle, zval *orientation)
{
    GtkOrientable *self = PHPGTK_ARG_AS(GtkOrientable, GTK_TYPE_ORIENTABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_orientable_set_orientation(self, (GtkOrientation) phpgtk_arg_long(orientation));
}
