/* Positive audit fixture: GtkWidget bound+reserved = 2 + 2 = 4 (matches
 * the fixture gir exactly); GtkGadget is sanctioned-partial 1 of 2. */

#include "php.h"

/*@zep Gtk\GtkWidget new() -> int */
zend_long phpgtk_gtkwidget_new(void);
/*@zep Gtk\GtkWidget getVisible(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_visible(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_set_visible(self, gboolean visible) */
/*@reserved Gtk\GtkWidget gtk_widget_extra_thing(self) */

/*@audit partial Gtk\GtkGadget only new is needed for the fixture */
/*@zep Gtk\GtkGadget new() -> int */
zend_long phpgtk_gtkgadget_new(void);
