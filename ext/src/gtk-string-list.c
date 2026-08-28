#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-string-list.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkstringlist_new(zval *strings)
{
    char **strv = phpgtk_zval_to_strv(strings);
    GtkStringList *list = gtk_string_list_new((const char * const *) strv);

    phpgtk_strv_free(strv);

    return phpgtk_handle_register_take(list);
}

void phpgtk_gtkstringlist_append(zval *handle, zval *string_)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);

    if (self == NULL) {
        return;
    }

    gtk_string_list_append(self, phpgtk_arg_string(string_));
}

zend_long phpgtk_gtkstringlist_find(zval *handle, zval *string_)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_string_list_find(self, phpgtk_arg_string(string_));
}

void phpgtk_gtkstringlist_get_string(zval *return_value, zval *handle, zval *position)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_string_list_get_string(self, (guint) phpgtk_arg_long(position)));
}

void phpgtk_gtkstringlist_remove(zval *handle, zval *position)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);

    if (self == NULL) {
        return;
    }

    gtk_string_list_remove(self, (guint) phpgtk_arg_long(position));
}

void phpgtk_gtkstringlist_splice(zval *handle, zval *position, zval *nRemovals, zval *additions)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);
    char **strv;

    if (self == NULL) {
        return;
    }

    strv = phpgtk_zval_to_strv(additions);
    gtk_string_list_splice(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nRemovals), (const char * const *) strv);
    phpgtk_strv_free(strv);
}

void phpgtk_gtkstringlist_take(zval *handle, zval *string_)
{
    GtkStringList *self = PHPGTK_ARG_AS(GtkStringList, GTK_TYPE_STRING_LIST, handle);

    if (self == NULL) {
        return;
    }

    gtk_string_list_take(self, phpgtk_arg_string_give(string_));
}
