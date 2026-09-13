#ifndef PHP_GTK_GTK_SELECTION_MODEL_H
#define PHP_GTK_GTK_SELECTION_MODEL_H

/*
 * GtkSelectionModel — Wave C interface. Bound as its own class. Every gir
 * method/function is bound or reserved. GtkBitset* get/set members stay
 * reserved — no bitset binding, so selection masks stay on the concrete
 * models (GtkSingleSelection / GtkNoSelection).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkSelectionModel gtk_selection_model_get_selection() — GtkBitset* */
/*@reserved Gtk\GtkSelectionModel gtk_selection_model_get_selection_in_range(position, n_items) — GtkBitset* */
/*@zep Gtk\GtkSelectionModel isSelected(int handle, int position) -> bool */
zend_long phpgtk_gtkselectionmodel_is_selected(zval *handle, zval *position);
/*@zep Gtk\GtkSelectionModel selectAll(int handle) -> bool */
zend_long phpgtk_gtkselectionmodel_select_all(zval *handle);
/*@zep Gtk\GtkSelectionModel selectItem(int handle, int position, bool unselectRest) -> bool */
zend_long phpgtk_gtkselectionmodel_select_item(zval *handle, zval *position, zval *unselectRest);
/*@zep Gtk\GtkSelectionModel selectRange(int handle, int position, int nItems, bool unselectRest) -> bool */
zend_long phpgtk_gtkselectionmodel_select_range(zval *handle, zval *position, zval *nItems, zval *unselectRest);
/*@zep Gtk\GtkSelectionModel selectionChanged(int handle, int position, int nItems) -> void */
void phpgtk_gtkselectionmodel_selection_changed(zval *handle, zval *position, zval *nItems);
/*@reserved Gtk\GtkSelectionModel gtk_selection_model_set_selection(GtkBitset* selected, GtkBitset* mask) — GtkBitset* */
/*@zep Gtk\GtkSelectionModel unselectAll(int handle) -> bool */
zend_long phpgtk_gtkselectionmodel_unselect_all(zval *handle);
/*@zep Gtk\GtkSelectionModel unselectItem(int handle, int position) -> bool */
zend_long phpgtk_gtkselectionmodel_unselect_item(zval *handle, zval *position);
/*@zep Gtk\GtkSelectionModel unselectRange(int handle, int position, int nItems) -> bool */
zend_long phpgtk_gtkselectionmodel_unselect_range(zval *handle, zval *position, zval *nItems);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SELECTION_MODEL_H */
