#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text-mark.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktextmark_new(zval *name, zval *leftGravity)
{
    GtkTextMark *created = gtk_text_mark_new(phpgtk_arg_string(name), phpgtk_arg_bool(leftGravity));
    return phpgtk_handle_register_take(created);
}

zend_long phpgtk_gtktextmark_get_buffer(zval *handle)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_mark_get_buffer(self));
}

zend_long phpgtk_gtktextmark_get_deleted(zval *handle)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_mark_get_deleted(self) ? 1 : 0;
}

zend_long phpgtk_gtktextmark_get_left_gravity(zval *handle)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_mark_get_left_gravity(self) ? 1 : 0;
}

void phpgtk_gtktextmark_get_name(zval *return_value, zval *handle)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_text_mark_get_name(self));
}

zend_long phpgtk_gtktextmark_get_visible(zval *handle)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_mark_get_visible(self) ? 1 : 0;
}

void phpgtk_gtktextmark_set_visible(zval *handle, zval *setting)
{
    GtkTextMark *self = PHPGTK_ARG_AS(GtkTextMark, GTK_TYPE_TEXT_MARK, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_mark_set_visible(self, phpgtk_arg_bool(setting));
}

