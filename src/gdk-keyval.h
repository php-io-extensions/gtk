#ifndef PHP_GTK_GDK_KEYVAL_H
#define PHP_GTK_GDK_KEYVAL_H

/*
 * GdkKeyval — input wave. Static-only home for the Gdk keyval free
 * functions (gir namespace-level functions, no class). The audit joins
 * this class to the gir by c:identifier prefix, per the marker below.
 *
 * name returns null for an unknown keyval. fromName returns
 * GDK_KEY_VoidSymbol (0xffffff) for an unknown name. toUnicode returns 0
 * when the keyval has no Unicode equivalent. convertCase returns
 * {lower, upper}.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@audit functions Gdk\GdkKeyval gdk_keyval_ gdk_unicode_to_keyval */

/*@zep Gdk\GdkKeyval convertCase(int symbol) -> array */
void phpgtk_gdkkeyval_convert_case(zval *return_value, zval *symbol);
/*@zep Gdk\GdkKeyval fromName(string name) -> int */
zend_long phpgtk_gdkkeyval_from_name(zval *name);
/*@zep Gdk\GdkKeyval isLower(int keyval) -> bool */
zend_long phpgtk_gdkkeyval_is_lower(zval *keyval);
/*@zep Gdk\GdkKeyval isUpper(int keyval) -> bool */
zend_long phpgtk_gdkkeyval_is_upper(zval *keyval);
/*@zep Gdk\GdkKeyval name(int keyval) -> var */
void phpgtk_gdkkeyval_name(zval *return_value, zval *keyval);
/*@zep Gdk\GdkKeyval toLower(int keyval) -> int */
zend_long phpgtk_gdkkeyval_to_lower(zval *keyval);
/*@zep Gdk\GdkKeyval toUnicode(int keyval) -> int */
zend_long phpgtk_gdkkeyval_to_unicode(zval *keyval);
/*@zep Gdk\GdkKeyval toUpper(int keyval) -> int */
zend_long phpgtk_gdkkeyval_to_upper(zval *keyval);
/*@zep Gdk\GdkKeyval fromUnicode(int wc) -> int */
zend_long phpgtk_gdkkeyval_from_unicode(zval *wc);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GDK_KEYVAL_H */
