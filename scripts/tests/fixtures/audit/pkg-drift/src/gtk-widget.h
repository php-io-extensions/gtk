/* Negative audit fixture: GtkWidget bound+reserved = 1 + 2 = 3, one member
 * short of the fixture gir's 4. The audit must FAIL. */

#include "php.h"

/*@zep Gtk\GtkWidget new() -> int */
zend_long phpgtk_gtkwidget_new(void);
/*@reserved Gtk\GtkWidget gtk_widget_get_visible(self) */
/*@reserved Gtk\GtkWidget gtk_widget_set_visible(self, gboolean visible) */
