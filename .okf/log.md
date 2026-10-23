# Log

## 2026-10-22

* `GtkWidget::childFocus(GtkDirectionType): bool` (`gtk_widget_child_focus`) and the `GtkDirectionType` enum. No new site. [surface](api/surface.md)
* Coverage: `scripts/support.php` writes `SUPPORT.md` (every live GTK, GDK and GSK member from the GIR files, bound or not; a stub method on a subclass counts for the ancestor's member) and the README API badge; `--check` compares without the date. 525 / 3798 on GTK 4.24.1.
* 0.10.3: `g_object_new_with_properties` (values converted as `g_object_set_property` converts them); `GtkAlertDialog` (made with it: `gtk_alert_dialog_new` is a printf and is not bound, Angel's ruling after ext-guard required its `...`), `GtkFileDialog`, `GtkFileLauncher`, `GFile` (`GLocalFile`, `GDaemonFile`, `GDummyFile` map to it), `GListStore`, `GdkClipboard`, `GdkDisplay::getClipboard`. Every async call shares `phpgtk_async_ready`. No new site. [surface](api/surface.md)

## 2026-10-20

* 0.10.3: `GtkWindowGroup` (`new`, `addWindow`, `removeWindow`), `GtkWindow` `getDefaultWidget` / `setDefaultWidget` / `getGroup`; `GtkShortcutController` (a `GListModel`), `GtkShortcut`, `GtkShortcutTrigger::parseString`, `GtkShortcutAction::activate`, `GtkCallbackAction` (a `GtkShortcutFunc` trampoline, released at finalize), `GtkShortcutScope`, `GtkShortcutActionFlags`. No new site. [surface](api/surface.md), [callouts](architecture/callouts.md)

## 2026-10-18

* 0.10.3: `GtkTreeListModel` (create-func trampoline, released at finalize), `GtkTreeListRow`, `GtkTreeExpander` (`gtk-initialized-tree-expander` site), `GtkScrollInfo` (boxed, `PHPGTK_SCROLL_INFO`), `GtkColumnView::scrollTo`, `GTK_LIST_SCROLL_*`. [surface](api/surface.md), [callouts](architecture/callouts.md)

## 2026-10-17

* 1:1 with GTK, 0.10.2. GTK's own answers pass through; refusals are only the probe-backed crash guards, each a `bindings.json` site with a `tests/Probes` test; `--enable-gtk-probes` builds the switch. [errors and threads](architecture/errors-and-threads.md), [build](runbooks/build.md)
* Native shapes: out-parameters by reference with the gboolean returned (`computePoint`, `computeBounds`, `getPosition`, `getSurfaceTransform`, `getSelectionBounds`, `getIterAtLine*`, `getLineYrange`, `getPointingTo`); GObject interfaces (`GAction`, `GActionMap`, `GActionGroup`, `GListModel`, `GtkSelectionModel`, `GdkPaintable`, `GtkStyleProvider`, `GtkNative`, `GtkRoot`), native-only; graphene and `GdkRectangle` structs; `GBytes`; `getText` over iters; native NULL as null. [surface](api/surface.md), [object model](architecture/object-model.md)
* Removed: `gtk_media_backend_available()` (`GtkMediaFile::new()->typeName()`), `GtkWidget::getSurface` (on `GtkNative`). [video](architecture/video.md), [layout](architecture/layout.md)
* Glue forwards only: one PHP → GValue converter for handler returns, emit and set_property; GtkTextIter, GBytes and GParamSpec signal arguments as objects; a callback dispatched off its owner thread is dropped; `GtkUriLauncher::launch` takes a null callback. [callouts](architecture/callouts.md)

## 2026-10-16

* `GtkPaned` and `GtkNotebook` (compare-app split and tabs, C2). 0.10.2. [surface](api/surface.md)
* Builds against a PHP whose ext/sockets is shared (Debian and Ubuntu packages leave HAVE_SOCKETS out of php_config.h). 0.10.2.

## 2026-10-14

* GtkTextIter (a copied boxed kind), GtkTextMark, GtkTextTag, GtkTextTagTable, GtkAdjustment; buffer tags, iters, selection and insert mark; text view monospace, cursor visibility and line y-range; scrolled-window adjustments; g_object_set_property (compare-app text panes, C1). 0.10.1. [surface](api/surface.md)
* g_signal_emit_by_name refuses an int that does not fit its parameter's C type, through the same check g_object_set_property uses (C1 final review). [surface](api/surface.md)

## 2026-10-10

* GtkLinkButton, GtkLabel markup and current URI, GCancellable, GAsyncResult, GtkUriLauncher (ext-gtk's first ready callback); GdkGLContext::realize frees its GError (toolkit links). [surface](api/surface.md)
* `GtkWindow::getFocus`, `GtkWidget::grabFocus`/`hasFocus` for the Edit menu and Mac text keys (HumanInput slice 29). [surface](api/surface.md)

## 2026-10-09

* [Surface](api/surface.md): GtkPopover and GtkPopoverMenu with their own setParent / unparent (popovers only; GtkWidget still has no unparent), GtkGesture::setState and GtkEventSequenceState. For context menus (HumanInput slice 27).
* `extra.venusian.system` in composer.json: the apt packages `venusian build` installs to compile the extension, the run-time packages a `.deb` carrying it depends on or recommends beyond what `dpkg-shlibdeps` sees, and the Homebrew packages for a dev install.
* [Surface](api/surface.md): g_set_prgname / g_get_prgname: GTK's X11 WM_CLASS follows the program name.
* [Surface](api/surface.md): event controllers for HumanInput's gtk engine. GtkEventController and its key, motion, scroll and focus controllers; GtkGesture, GtkGestureSingle, GtkGestureClick; GtkWidget add/removeController; gdk_keyval_to_unicode and gdk_keyval_to_lower; GtkPropagationPhase and GdkScrollUnit; the scroll-flag and modifier-mask constants. Signals hand keyvals, keycodes and modifier state over as ints.
* [Surface](api/surface.md): GtkEventController::getCurrentEvent(), GdkEvent and GdkScrollEvent; on GTK 4.20+ GdkScrollEvent::getRelativeDirection() and GdkScrollRelativeDirection, so a reader can undo natural scrolling. SurfaceTest skips stub blocks the running GTK is older than.
* [Surface](api/surface.md): GtkEventControllerLegacy; GdkEvent getEventType/getPosition/getPointerEmulated, GdkButtonEvent, GdkTouchEvent, GdkEventType; GtkIMContext and GtkIMMulticontext; GtkWidget::computePoint, GtkWindow::getSurfaceTransform. Signal GdkEvent arguments arrive as GdkEvent objects.
* [Surface](api/surface.md): GtkWidget::pick and GTK_PICK_*; GdkEvent::getModifierState; GtkGestureSingle touch_only; GtkGestureLongPress. For right-click mail (HumanInput slice 26).
* [Surface](api/surface.md): GtkSettings::getDefault and g_object_get_property, so a reader takes gtk-long-press-time and gtk-dnd-drag-threshold from GTK.
* [Surface](api/surface.md): GdkDisplay::sync. GTK 4.18's Wayland input method binds its text-input on a round trip after the display's first use of it; a context focused before then stays GTK's focus past its finalize and the next focused window crashes. The IM test focuses with no client widget. Suite 165 + 5 skipped on Homebrew PHP 8.4 NTS and ZTS, 167 + 1 on the Pi.

## 2026-10-06

* `GdkDmabufTextureBuilder::build()` takes a destroy callback (GTK's destroy notify); `GdkDmabufFormats` from `GdkDisplay::getDmabufFormats()`; `GtkWidget::getDisplay()`. Suite 145 + 5 skipped on Homebrew PHP 8.4 NTS and ZTS, 150 on the Pi. [surface](api/surface.md)
* `GdkDmabufTextureBuilder` (Linux, GTK 4.14+): a texture over a dmabuf, the fd borrowed. `SurfaceTest` skips Linux-only stub blocks elsewhere. Suite 142 + 4 skipped on Homebrew PHP 8.4 NTS and ZTS, 146 on the Pi. [surface](api/surface.md)
* GL views: `GtkGLArea` and `GdkGLContext` with `GdkGLAPI`; the `render` signal hands PHP the area and its context, the context current and the area's framebuffer bound. Suite 143 on Homebrew PHP 8.4 NTS and ZTS (1 skipped there) and on the Pi. [surface](api/surface.md)

## 2026-10-04

* Extension version is 0.10.1. Memory textures from an address: `GdkMemoryTexture::new()` takes `string|int` bytes, an address trusted to hold the rows the width, height and stride name. New `GdkMemoryTextureBuilder` (GTK 4.16+, compiled only when headers are 4.16+): fluent setters, `setBytes` from a string or an address with a byte count, `setUpdateRegion` of `[x, y, width, height]` rects, `build(): ?GdkTexture` (null when unset). [surface](api/surface.md)

## 2026-10-03

* Pixels from bytes: `GdkTexture`, `GdkMemoryTexture::new()`, `GdkMemoryFormat`; `GtkPicture` set_paintable and can_shrink; `GtkWidget::getScaleFactor()`. [surface](api/surface.md)

## 2026-10-02

* [Surface](api/surface.md): widget alignment, sizing, margins, CSS classes; GtkBox ordering; GtkGrid, GtkFixed; GtkCssProvider, GdkDisplay, style-context functions; GdkSurface. New concept [layout and styling](architecture/layout.md).
* [Surface](api/surface.md): GtkLabel, GtkButton, GtkCheckButton, GtkSwitch, GtkToggleButton, GtkEntry/GtkEntryBuffer, GtkTextView/GtkTextBuffer, GtkScale, GtkWidget activate.
* [Surface](api/surface.md): GtkDropDown, GtkStringList, GtkStringObject, GtkCalendar, GDateTime (new boxed kind, [object model](architecture/object-model.md)), GtkProgressBar, GtkSpinner, GtkPicture, GtkSeparator, GtkScrolledWindow.
* [Surface](api/surface.md): GtkColumnView, GtkColumnViewColumn, GtkSignalListItemFactory, GtkListItem, GtkSingleSelection; (transfer full) arguments in [object model](architecture/object-model.md).
* [Surface](api/surface.md): GtkMediaStream, GtkMediaFile, GtkVideo, `gtk_media_backend_available()`; installers check or warn about the media backend. New concept [video and the media backend](architecture/video.md).
* Review fixes: `gtk_widget_unparent` dropped; entry and text buffer lengths and UTF-8, scale ranges, list positions, native int ranges, child parents and column membership refused before GTK asserts; GTK floor raised to 4.12 for `gtk_css_provider_load_from_string`.

## 2026-10-01

* Runbook [adding a binding](runbooks/adding-a-binding.md).
* [Surface](api/surface.md): GtkWidget, GtkWindow, GtkApplicationWindow, GtkAboutDialog, GtkBox, GtkPopoverMenuBar, GMenuModel/GMenu/GMenuItem, GSimpleAction/GSimpleActionGroup, GVariant, GtkOrientation, GtkApplication window and menubar calls. [Object model](architecture/object-model.md): GVariant kind and constructor ownership.
* [Surface](api/surface.md): GtkWidget get_realized/get_mapped. [Errors and threads](architecture/errors-and-threads.md): widget constructors refuse an uninitialised GTK.
* [Surface](api/surface.md): GApplication GActionMap/GActionGroup calls (the "app" actions).

## 2026-09-30

* Bundle created with ext-gtk 0.10.0: [surface](api/surface.md), [object model](architecture/object-model.md), [callouts](architecture/callouts.md), [errors and threads](architecture/errors-and-threads.md), [build](runbooks/build.md).
