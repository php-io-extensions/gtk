#ifndef PHP_GTK_GIO_GLISTMODEL_H
#define PHP_GTK_GIO_GLISTMODEL_H

/*
 * Gio GListModel — Wave B1 interface. Bound as its own class. Every gir
 * method/function is bound or reserved. get_item / get_object are
 * transfer-full and use phpgtk_handle_register_take.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GListModel getItem(int handle, int position) -> int */
zend_long phpgtk_glistmodel_get_item(zval *handle, zval *position);
/*@zep Gio\GListModel getItemType(int handle) -> int */
zend_long phpgtk_glistmodel_get_item_type(zval *handle);
/*@zep Gio\GListModel getNItems(int handle) -> int */
zend_long phpgtk_glistmodel_get_n_items(zval *handle);
/*@zep Gio\GListModel getObject(int handle, int position) -> int */
zend_long phpgtk_glistmodel_get_object(zval *handle, zval *position);
/*@zep Gio\GListModel itemsChanged(int handle, int position, int removed, int added) -> void */
void phpgtk_glistmodel_items_changed(zval *handle, zval *position, zval *removed, zval *added);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GLISTMODEL_H */
