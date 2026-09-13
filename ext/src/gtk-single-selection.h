#ifndef PHP_GTK_GTK_SINGLE_SELECTION_H
#define PHP_GTK_GTK_SINGLE_SELECTION_H

/*
 * GtkSingleSelection — Wave C. Every gir constructor/method/function is
 * bound or reserved. Constructor is transfer-full and takes a
 * transfer-full GListModel. item-type / n-items getters live on
 * GListModel.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkSingleSelection property "item-type" — getter lives on GListModel; use Bridge::getProperty */
/*@reserved Gtk\GtkSingleSelection property "n-items" — getter lives on GListModel; use Bridge::getProperty */

/*@zep Gtk\GtkSingleSelection new(int model) -> int */
zend_long phpgtk_gtksingleselection_new(zval *model);
/*@zep Gtk\GtkSingleSelection getAutoselect(int handle) -> bool */
zend_long phpgtk_gtksingleselection_get_autoselect(zval *handle);
/*@zep Gtk\GtkSingleSelection getCanUnselect(int handle) -> bool */
zend_long phpgtk_gtksingleselection_get_can_unselect(zval *handle);
/*@zep Gtk\GtkSingleSelection getModel(int handle) -> int */
zend_long phpgtk_gtksingleselection_get_model(zval *handle);
/*@zep Gtk\GtkSingleSelection getSelected(int handle) -> int */
zend_long phpgtk_gtksingleselection_get_selected(zval *handle);
/*@zep Gtk\GtkSingleSelection getSelectedItem(int handle) -> int */
zend_long phpgtk_gtksingleselection_get_selected_item(zval *handle);
/*@zep Gtk\GtkSingleSelection setAutoselect(int handle, bool autoselect) -> void */
void phpgtk_gtksingleselection_set_autoselect(zval *handle, zval *autoselect);
/*@zep Gtk\GtkSingleSelection setCanUnselect(int handle, bool canUnselect) -> void */
void phpgtk_gtksingleselection_set_can_unselect(zval *handle, zval *canUnselect);
/*@zep Gtk\GtkSingleSelection setModel(int handle, int model) -> void */
void phpgtk_gtksingleselection_set_model(zval *handle, zval *model);
/*@zep Gtk\GtkSingleSelection setSelected(int handle, int position) -> void */
void phpgtk_gtksingleselection_set_selected(zval *handle, zval *position);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SINGLE_SELECTION_H */
