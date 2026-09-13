#ifndef PHP_GTK_GTK_NO_SELECTION_H
#define PHP_GTK_GTK_NO_SELECTION_H

/*
 * GtkNoSelection — Wave C. Every gir constructor/method/function is
 * bound or reserved. Constructor is transfer-full and takes a
 * transfer-full GListModel. item-type / n-items getters live on
 * GListModel.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkNoSelection property "item-type" — getter lives on GListModel; use Bridge::getProperty */
/*@reserved Gtk\GtkNoSelection property "n-items" — getter lives on GListModel; use Bridge::getProperty */

/*@zep Gtk\GtkNoSelection new(int model) -> int */
zend_long phpgtk_gtknoselection_new(zval *model);
/*@zep Gtk\GtkNoSelection getModel(int handle) -> int */
zend_long phpgtk_gtknoselection_get_model(zval *handle);
/*@zep Gtk\GtkNoSelection setModel(int handle, int model) -> void */
void phpgtk_gtknoselection_set_model(zval *handle, zval *model);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_NO_SELECTION_H */
