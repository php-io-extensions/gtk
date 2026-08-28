#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text-tag.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktexttag_new(zval *name)
{
    GtkTextTag *created = gtk_text_tag_new(phpgtk_arg_string(name));
    return phpgtk_handle_register_take(created);
}

void phpgtk_gtktexttag_changed(zval *handle, zval *sizeChanged)
{
    GtkTextTag *self = PHPGTK_ARG_AS(GtkTextTag, GTK_TYPE_TEXT_TAG, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_tag_changed(self, phpgtk_arg_bool(sizeChanged));
}

zend_long phpgtk_gtktexttag_get_priority(zval *handle)
{
    GtkTextTag *self = PHPGTK_ARG_AS(GtkTextTag, GTK_TYPE_TEXT_TAG, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_tag_get_priority(self);
}

void phpgtk_gtktexttag_set_priority(zval *handle, zval *priority)
{
    GtkTextTag *self = PHPGTK_ARG_AS(GtkTextTag, GTK_TYPE_TEXT_TAG, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_tag_set_priority(self, (int) phpgtk_arg_long(priority));
}

