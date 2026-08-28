#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gmenu.h"
#include "phpgtk-support.h"

zend_long phpgtk_gmenu_new(void)
{
    return phpgtk_handle_register_take(g_menu_new());
}

void phpgtk_gmenu_append(zval *handle, zval *label, zval *detailedAction)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_append(self, phpgtk_arg_string(label), phpgtk_arg_string(detailedAction));
}

void phpgtk_gmenu_append_item(zval *handle, zval *item)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_append_item(self, phpgtk_arg_object(item));
}

void phpgtk_gmenu_append_section(zval *handle, zval *label, zval *section)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_append_section(self, phpgtk_arg_string(label), phpgtk_arg_object(section));
}

void phpgtk_gmenu_append_submenu(zval *handle, zval *label, zval *submenu)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_append_submenu(self, phpgtk_arg_string(label), phpgtk_arg_object(submenu));
}

void phpgtk_gmenu_freeze(zval *handle)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_freeze(self);
}

void phpgtk_gmenu_insert(zval *handle, zval *position, zval *label, zval *detailedAction)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_insert(self, (gint) phpgtk_arg_long(position), phpgtk_arg_string(label), phpgtk_arg_string(detailedAction));
}

void phpgtk_gmenu_insert_item(zval *handle, zval *position, zval *item)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_insert_item(self, (gint) phpgtk_arg_long(position), phpgtk_arg_object(item));
}

void phpgtk_gmenu_insert_section(zval *handle, zval *position, zval *label, zval *section)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_insert_section(self, (gint) phpgtk_arg_long(position), phpgtk_arg_string(label), phpgtk_arg_object(section));
}

void phpgtk_gmenu_insert_submenu(zval *handle, zval *position, zval *label, zval *submenu)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_insert_submenu(self, (gint) phpgtk_arg_long(position), phpgtk_arg_string(label), phpgtk_arg_object(submenu));
}

void phpgtk_gmenu_prepend(zval *handle, zval *label, zval *detailedAction)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_prepend(self, phpgtk_arg_string(label), phpgtk_arg_string(detailedAction));
}

void phpgtk_gmenu_prepend_item(zval *handle, zval *item)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_prepend_item(self, phpgtk_arg_object(item));
}

void phpgtk_gmenu_prepend_section(zval *handle, zval *label, zval *section)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_prepend_section(self, phpgtk_arg_string(label), phpgtk_arg_object(section));
}

void phpgtk_gmenu_prepend_submenu(zval *handle, zval *label, zval *submenu)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_prepend_submenu(self, phpgtk_arg_string(label), phpgtk_arg_object(submenu));
}

void phpgtk_gmenu_remove(zval *handle, zval *position)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_remove(self, (gint) phpgtk_arg_long(position));
}

void phpgtk_gmenu_remove_all(zval *handle)
{
    GMenu *self = PHPGTK_ARG_AS(GMenu, G_TYPE_MENU, handle);

    if (self == NULL) {
        return;
    }

    g_menu_remove_all(self);
}
