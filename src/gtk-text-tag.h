#ifndef PHP_GTK_GTK_TEXT_TAG_H
#define PHP_GTK_GTK_TEXT_TAG_H

/*
 * GtkTextTag — Wave B8. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkTextTag property "accumulative-margin" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "allow-breaks" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "allow-breaks-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "background" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "background-full-height" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "background-full-height-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "background-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "background-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "direction" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "editable" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "editable-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "fallback" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "fallback-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "family" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "family-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "font" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "font-desc" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "font-features" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "font-features-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "foreground" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "foreground-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "foreground-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "indent" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "indent-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "insert-hyphens" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "insert-hyphens-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "invisible" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "invisible-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "justification" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "justification-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "language" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "language-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "left-margin" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "left-margin-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "letter-spacing" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "letter-spacing-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "line-height" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "line-height-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "name" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "overline" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "overline-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "overline-rgba-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "overline-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "paragraph-background" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "paragraph-background-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "paragraph-background-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-above-lines" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-above-lines-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-below-lines" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-below-lines-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-inside-wrap" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "pixels-inside-wrap-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "right-margin" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "right-margin-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "rise" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "rise-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "scale" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "scale-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "sentence" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "sentence-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "show-spaces" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "show-spaces-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "size" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "size-points" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "size-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "stretch" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "stretch-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "strikethrough" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "strikethrough-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "strikethrough-rgba-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "strikethrough-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "style" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "style-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "tabs" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "tabs-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "text-transform" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "text-transform-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "underline" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "underline-rgba" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "underline-rgba-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "underline-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "variant" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "variant-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "weight" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "weight-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "word" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "word-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "wrap-mode" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkTextTag property "wrap-mode-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkTextTag new_(var name) -> int */
zend_long phpgtk_gtktexttag_new(zval *name);
/*@zep Gtk\GtkTextTag changed(int handle, bool sizeChanged) -> void */
void phpgtk_gtktexttag_changed(zval *handle, zval *sizeChanged);
/*@zep Gtk\GtkTextTag getPriority(int handle) -> int */
zend_long phpgtk_gtktexttag_get_priority(zval *handle);
/*@zep Gtk\GtkTextTag setPriority(int handle, int priority) -> void */
void phpgtk_gtktexttag_set_priority(zval *handle, zval *priority);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_TAG_H */
