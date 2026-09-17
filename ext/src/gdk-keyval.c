#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gdk-keyval.h"
#include "phpgtk-support.h"

void phpgtk_gdkkeyval_convert_case(zval *return_value, zval *symbol)
{
    guint lower = 0;
    guint upper = 0;

    gdk_keyval_convert_case((guint) phpgtk_arg_long(symbol), &lower, &upper);
    array_init(return_value);
    add_assoc_long(return_value, "lower", (zend_long) lower);
    add_assoc_long(return_value, "upper", (zend_long) upper);
}

zend_long phpgtk_gdkkeyval_from_name(zval *name)
{
    const char *s = phpgtk_arg_string(name);

    if (s == NULL) {
        return 0;
    }

    return (zend_long) gdk_keyval_from_name(s);
}

zend_long phpgtk_gdkkeyval_is_lower(zval *keyval)
{
    return gdk_keyval_is_lower((guint) phpgtk_arg_long(keyval)) ? 1 : 0;
}

zend_long phpgtk_gdkkeyval_is_upper(zval *keyval)
{
    return gdk_keyval_is_upper((guint) phpgtk_arg_long(keyval)) ? 1 : 0;
}

void phpgtk_gdkkeyval_name(zval *return_value, zval *keyval)
{
    phpgtk_ret_string(return_value, gdk_keyval_name((guint) phpgtk_arg_long(keyval)));
}

zend_long phpgtk_gdkkeyval_to_lower(zval *keyval)
{
    return (zend_long) gdk_keyval_to_lower((guint) phpgtk_arg_long(keyval));
}

zend_long phpgtk_gdkkeyval_to_unicode(zval *keyval)
{
    return (zend_long) gdk_keyval_to_unicode((guint) phpgtk_arg_long(keyval));
}

zend_long phpgtk_gdkkeyval_to_upper(zval *keyval)
{
    return (zend_long) gdk_keyval_to_upper((guint) phpgtk_arg_long(keyval));
}

zend_long phpgtk_gdkkeyval_from_unicode(zval *wc)
{
    return (zend_long) gdk_unicode_to_keyval((guint32) phpgtk_arg_long(wc));
}
