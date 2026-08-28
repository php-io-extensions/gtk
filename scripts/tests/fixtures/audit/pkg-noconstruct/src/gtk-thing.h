/* Construction-path fixture: GtkThing is a concrete class with no
 * constructor and no int-returning factory. Must FAIL. */

#include "php.h"

/*@zep Gtk\GtkThing ping(int handle) -> void */
void phpgtk_gtkthing_ping(zval *handle);
