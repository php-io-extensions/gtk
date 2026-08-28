#ifndef PHP_GTK_GIO_GMENUMODEL_H
#define PHP_GTK_GIO_GMENUMODEL_H

/*
 * Gio GMenuModel — Wave B2 abstract. Every gir method/function is bound
 * or reserved. GVariant* / varargs / iterator types stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gio\GMenuModel g_menu_model_get_item_attribute(self, item_index, attribute, format_string, ...) — varargs */
/*@reserved Gio\GMenuModel g_menu_model_get_item_attribute_value(self, item_index, attribute, GVariantType* expected_type) — GVariant* */
/*@zep Gio\GMenuModel getItemLink(int handle, int itemIndex, string link) -> int */
zend_long phpgtk_gmenumodel_get_item_link(zval *handle, zval *itemIndex, zval *link);
/*@zep Gio\GMenuModel getNItems(int handle) -> int */
zend_long phpgtk_gmenumodel_get_n_items(zval *handle);
/*@zep Gio\GMenuModel isMutable(int handle) -> bool */
zend_long phpgtk_gmenumodel_is_mutable(zval *handle);
/*@zep Gio\GMenuModel itemsChanged(int handle, int position, int removed, int added) -> void */
void phpgtk_gmenumodel_items_changed(zval *handle, zval *position, zval *removed, zval *added);
/*@reserved Gio\GMenuModel g_menu_model_iterate_item_attributes(self, item_index) — GMenuAttributeIter* */
/*@reserved Gio\GMenuModel g_menu_model_iterate_item_links(self, item_index) — GMenuLinkIter* */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GMENUMODEL_H */
