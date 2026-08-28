/* Property-coverage fixture: member count matches, but property "orphan"
 * has no getter/setter among members and is not reserved. Must FAIL. */

#include "php.h"

/*@zep Gtk\GtkOrphan ping(int handle) -> void */
void phpgtk_gtkorphan_ping(zval *handle);
