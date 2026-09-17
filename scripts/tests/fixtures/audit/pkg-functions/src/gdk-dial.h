/* Positive free-function fixture: the gdk_dial_ set is {up, down, reset};
 * up and down are bound (joined through their .c bodies), reset reserved. */

#include "php.h"

/*@audit functions Gdk\GdkDial gdk_dial_ */
/*@zep Gdk\GdkDial up(int step) -> int */
zend_long phpgtk_gdkdial_up(zval *step);
/*@zep Gdk\GdkDial down(int step) -> int */
zend_long phpgtk_gdkdial_down(zval *step);
/*@reserved Gdk\GdkDial gdk_dial_reset(void) — fixture reservation */
