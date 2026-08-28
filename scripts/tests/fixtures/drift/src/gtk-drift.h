#ifndef PHP_GTK_GTK_DRIFT_FIXTURE_H
#define PHP_GTK_GTK_DRIFT_FIXTURE_H

/*
 * Negative-control fixture for gen-zep.php: the annotation declares two
 * parameters but the C prototype only takes one. The generator must refuse
 * to generate and exit non-zero.
 */

#include "php.h"

/*@zep Gtk\GtkDrift setThing(int handle, int thing) -> void */
void phpgtk_gtkdrift_set_thing(zval *handle);

#endif
