#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text-tag-table.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktexttagtable_new(void)
{
    GtkTextTagTable *created = gtk_text_tag_table_new();
    return phpgtk_handle_register_take(created);
}

zend_long phpgtk_gtktexttagtable_add(zval *handle, zval *tag)
{
    GtkTextTagTable *self = PHPGTK_ARG_AS(GtkTextTagTable, GTK_TYPE_TEXT_TAG_TABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_tag_table_add(self, phpgtk_arg_object(tag)) ? 1 : 0;
}

zend_long phpgtk_gtktexttagtable_get_size(zval *handle)
{
    GtkTextTagTable *self = PHPGTK_ARG_AS(GtkTextTagTable, GTK_TYPE_TEXT_TAG_TABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_tag_table_get_size(self);
}

zend_long phpgtk_gtktexttagtable_lookup(zval *handle, zval *name)
{
    GtkTextTagTable *self = PHPGTK_ARG_AS(GtkTextTagTable, GTK_TYPE_TEXT_TAG_TABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_tag_table_lookup(self, phpgtk_arg_string(name)));
}

void phpgtk_gtktexttagtable_remove(zval *handle, zval *tag)
{
    GtkTextTagTable *self = PHPGTK_ARG_AS(GtkTextTagTable, GTK_TYPE_TEXT_TAG_TABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_tag_table_remove(self, phpgtk_arg_object(tag));
}

