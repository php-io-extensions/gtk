#ifndef PHP_GTK_GIO_GLISTSTORE_H
#define PHP_GTK_GIO_GLISTSTORE_H

/*
 * Gio GListStore — Wave B1. Every gir constructor/method/function is
 * bound or reserved. new() takes a GType from Bridge::typeFromName.
 * find's out-param is {position}. Equal/sort callbacks are reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gio\GListStore property "item-type" — getter lives on GListModel; construct-only; use Bridge::getProperty */
/*@reserved Gio\GListStore property "n-items" — getter lives on GListModel; use Bridge::getProperty */

/*@zep Gio\GListStore new(int itemType) -> int */
zend_long phpgtk_gliststore_new(zval *itemType);
/*@zep Gio\GListStore append(int handle, int item) -> void */
void phpgtk_gliststore_append(zval *handle, zval *item);
/*@zep Gio\GListStore find(int handle, int item) -> array */
void phpgtk_gliststore_find(zval *return_value, zval *handle, zval *item);
/*@reserved Gio\GListStore g_list_store_find_with_equal_func(self, item, GEqualFunc equal_func, position) — non-signal callback */
/*@reserved Gio\GListStore g_list_store_find_with_equal_func_full(self, item, GEqualFuncFull equal_func, user_data, position) — non-signal callback */
/*@zep Gio\GListStore insert(int handle, int position, int item) -> void */
void phpgtk_gliststore_insert(zval *handle, zval *position, zval *item);
/*@reserved Gio\GListStore g_list_store_insert_sorted(self, item, GCompareDataFunc compare_func, user_data) — non-signal callback */
/*@zep Gio\GListStore remove(int handle, int position) -> void */
void phpgtk_gliststore_remove(zval *handle, zval *position);
/*@zep Gio\GListStore removeAll(int handle) -> void */
void phpgtk_gliststore_remove_all(zval *handle);
/*@reserved Gio\GListStore g_list_store_sort(self, GCompareDataFunc compare_func, user_data) — non-signal callback */
/*@zep Gio\GListStore splice(int handle, int position, int nRemovals, array additions, int nAdditions) -> void */
void phpgtk_gliststore_splice(zval *handle, zval *position, zval *nRemovals, zval *additions, zval *nAdditions);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GLISTSTORE_H */
