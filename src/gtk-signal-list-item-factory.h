#ifndef PHP_GTK_GTK_SIGNAL_LIST_ITEM_FACTORY_H
#define PHP_GTK_GTK_SIGNAL_LIST_ITEM_FACTORY_H

/*
 * GtkSignalListItemFactory — Wave C. Every gir constructor/method/function
 * is bound or reserved. The only C member is new(); setup/bind/unbind/
 * teardown arrive through Bridge::connect. Constructor is transfer-full.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkSignalListItemFactory new() -> int */
zend_long phpgtk_gtksignallistitemfactory_new(void);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SIGNAL_LIST_ITEM_FACTORY_H */
