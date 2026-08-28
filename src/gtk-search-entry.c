#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-search-entry.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtksearchentry_new(void)
{
    return phpgtk_handle_register(gtk_search_entry_new());
}

zend_long phpgtk_gtksearchentry_get_input_hints(zval *handle)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_search_entry_get_input_hints(self);
}

zend_long phpgtk_gtksearchentry_get_input_purpose(zval *handle)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_search_entry_get_input_purpose(self);
}

zend_long phpgtk_gtksearchentry_get_key_capture_widget(zval *handle)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_search_entry_get_key_capture_widget(self));
}

void phpgtk_gtksearchentry_get_placeholder_text(zval *return_value, zval *handle)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_search_entry_get_placeholder_text(self));
}

zend_long phpgtk_gtksearchentry_get_search_delay(zval *handle)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_search_entry_get_search_delay(self);
}

void phpgtk_gtksearchentry_set_input_hints(zval *handle, zval *hints)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_search_entry_set_input_hints(self, (GtkInputHints) phpgtk_arg_long(hints));
}

void phpgtk_gtksearchentry_set_input_purpose(zval *handle, zval *purpose)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_search_entry_set_input_purpose(self, (GtkInputPurpose) phpgtk_arg_long(purpose));
}

void phpgtk_gtksearchentry_set_key_capture_widget(zval *handle, zval *widget)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_search_entry_set_key_capture_widget(self, phpgtk_arg_object(widget));
}

void phpgtk_gtksearchentry_set_placeholder_text(zval *handle, zval *text)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_search_entry_set_placeholder_text(self, phpgtk_arg_string(text));
}

void phpgtk_gtksearchentry_set_search_delay(zval *handle, zval *delay)
{
    GtkSearchEntry *self = PHPGTK_ARG_AS(GtkSearchEntry, GTK_TYPE_SEARCH_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_search_entry_set_search_delay(self, (guint) phpgtk_arg_long(delay));
}
