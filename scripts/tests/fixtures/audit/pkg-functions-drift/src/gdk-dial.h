/* Negative free-function fixture: counts add up (2 bound + 1 reserved = 3)
 * but down's body calls a function outside the set, so gdk_dial_down is
 * uncovered. The join by c:identifier must catch it. */

#include "php.h"

/*@audit functions Gdk\GdkDial gdk_dial_ */
/*@zep Gdk\GdkDial up(int step) -> int */
zend_long phpgtk_gdkdial_up(zval *step);
/*@zep Gdk\GdkDial down(int step) -> int */
zend_long phpgtk_gdkdial_down(zval *step);
/*@reserved Gdk\GdkDial gdk_dial_reset(void) — fixture reservation */
