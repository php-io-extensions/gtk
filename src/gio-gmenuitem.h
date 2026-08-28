#ifndef PHP_GTK_GIO_GMENUITEM_H
#define PHP_GTK_GIO_GMENUITEM_H

/*
 * Gio GMenuItem — Wave B2. Every gir constructor/method/function is
 * bound or reserved. Constructors are transfer-full. GVariant* and
 * varargs members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gio\GMenuItem new(var label, var detailedAction) -> int */
zend_long phpgtk_gmenuitem_new(zval *label, zval *detailedAction);
/*@zep Gio\GMenuItem newFromModel(int model, int itemIndex) -> int */
zend_long phpgtk_gmenuitem_new_from_model(zval *model, zval *itemIndex);
/*@zep Gio\GMenuItem newSection(var label, int section) -> int */
zend_long phpgtk_gmenuitem_new_section(zval *label, zval *section);
/*@zep Gio\GMenuItem newSubmenu(var label, int submenu) -> int */
zend_long phpgtk_gmenuitem_new_submenu(zval *label, zval *submenu);
/*@reserved Gio\GMenuItem g_menu_item_get_attribute(self, attribute, format_string, ...) — varargs */
/*@reserved Gio\GMenuItem g_menu_item_get_attribute_value(self, attribute, GVariantType* expected_type) — GVariant* */
/*@zep Gio\GMenuItem getLink(int handle, string link) -> int */
zend_long phpgtk_gmenuitem_get_link(zval *handle, zval *link);
/*@reserved Gio\GMenuItem g_menu_item_set_action_and_target(self, action, format_string, ...) — varargs */
/*@reserved Gio\GMenuItem g_menu_item_set_action_and_target_value(self, action, GVariant* target_value) — GVariant* */
/*@reserved Gio\GMenuItem g_menu_item_set_attribute(self, attribute, format_string, ...) — varargs */
/*@reserved Gio\GMenuItem g_menu_item_set_attribute_value(self, attribute, GVariant* value) — GVariant* */
/*@zep Gio\GMenuItem setDetailedAction(int handle, string detailedAction) -> void */
void phpgtk_gmenuitem_set_detailed_action(zval *handle, zval *detailedAction);
/*@zep Gio\GMenuItem setIcon(int handle, int icon) -> void */
void phpgtk_gmenuitem_set_icon(zval *handle, zval *icon);
/*@zep Gio\GMenuItem setLabel(int handle, var label) -> void */
void phpgtk_gmenuitem_set_label(zval *handle, zval *label);
/*@zep Gio\GMenuItem setLink(int handle, string link, int model) -> void */
void phpgtk_gmenuitem_set_link(zval *handle, zval *link, zval *model);
/*@zep Gio\GMenuItem setSection(int handle, int section) -> void */
void phpgtk_gmenuitem_set_section(zval *handle, zval *section);
/*@zep Gio\GMenuItem setSubmenu(int handle, int submenu) -> void */
void phpgtk_gmenuitem_set_submenu(zval *handle, zval *submenu);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GIO_GMENUITEM_H */
