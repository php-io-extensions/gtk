#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-string-object.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstringobject_new(zval *string_)
{
    return phpgtk_handle_register_take(gtk_string_object_new(phpgtk_arg_string(string_)));
}

void phpgtk_gtkstringobject_get_string(zval *return_value, zval *handle)
{
    GtkStringObject *self = PHPGTK_ARG_AS(GtkStringObject, GTK_TYPE_STRING_OBJECT, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_string_object_get_string(self));
}
