#ifndef PHP_GTK_GTK_NOTEBOOK_PAGE_H
#define PHP_GTK_GTK_NOTEBOOK_PAGE_H

/*
 * GtkNotebookPage — Wave B4. Every gir
 * constructor/method/function is bound or reserved. Obtain-only: no gir constructor; get via GtkNotebook::getPage. Accessor-less properties reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkNotebookPage property "detachable" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "menu" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "menu-label" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "position" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "reorderable" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "tab" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "tab-expand" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "tab-fill" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkNotebookPage property "tab-label" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkNotebookPage getChild(int handle) -> int */
zend_long phpgtk_gtknotebookpage_get_child(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_NOTEBOOK_PAGE_H */
