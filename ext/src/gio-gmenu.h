#ifndef PHP_GTK_GIO_GMENU_H
#define PHP_GTK_GIO_GMENU_H

/*
 * Gio GMenu — Wave B2. Every gir constructor/method/function is bound
 * or reserved. Constructor is transfer-full. Nullable labels/actions
 * are var (null = NULL).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GMenu new() -> int */
zend_long phpgtk_gmenu_new(void);
/*@zep Gio\GMenu append(int handle, var label, var detailedAction) -> void */
void phpgtk_gmenu_append(zval *handle, zval *label, zval *detailedAction);
/*@zep Gio\GMenu appendItem(int handle, int item) -> void */
void phpgtk_gmenu_append_item(zval *handle, zval *item);
/*@zep Gio\GMenu appendSection(int handle, var label, int section) -> void */
void phpgtk_gmenu_append_section(zval *handle, zval *label, zval *section);
/*@zep Gio\GMenu appendSubmenu(int handle, var label, int submenu) -> void */
void phpgtk_gmenu_append_submenu(zval *handle, zval *label, zval *submenu);
/*@zep Gio\GMenu freeze(int handle) -> void */
void phpgtk_gmenu_freeze(zval *handle);
/*@zep Gio\GMenu insert(int handle, int position, var label, var detailedAction) -> void */
void phpgtk_gmenu_insert(zval *handle, zval *position, zval *label, zval *detailedAction);
/*@zep Gio\GMenu insertItem(int handle, int position, int item) -> void */
void phpgtk_gmenu_insert_item(zval *handle, zval *position, zval *item);
/*@zep Gio\GMenu insertSection(int handle, int position, var label, int section) -> void */
void phpgtk_gmenu_insert_section(zval *handle, zval *position, zval *label, zval *section);
/*@zep Gio\GMenu insertSubmenu(int handle, int position, var label, int submenu) -> void */
void phpgtk_gmenu_insert_submenu(zval *handle, zval *position, zval *label, zval *submenu);
/*@zep Gio\GMenu prepend(int handle, var label, var detailedAction) -> void */
void phpgtk_gmenu_prepend(zval *handle, zval *label, zval *detailedAction);
/*@zep Gio\GMenu prependItem(int handle, int item) -> void */
void phpgtk_gmenu_prepend_item(zval *handle, zval *item);
/*@zep Gio\GMenu prependSection(int handle, var label, int section) -> void */
void phpgtk_gmenu_prepend_section(zval *handle, zval *label, zval *section);
/*@zep Gio\GMenu prependSubmenu(int handle, var label, int submenu) -> void */
void phpgtk_gmenu_prepend_submenu(zval *handle, zval *label, zval *submenu);
/*@zep Gio\GMenu remove(int handle, int position) -> void */
void phpgtk_gmenu_remove(zval *handle, zval *position);
/*@zep Gio\GMenu removeAll(int handle) -> void */
void phpgtk_gmenu_remove_all(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GMENU_H */
