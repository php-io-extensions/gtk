# Change log

## 2026-09-13 (GL wave — GtkGLArea and the first Gdk class)

* **Binding**: `GtkGLArea` (`src/gtk-gl-area.{h,c}`, gir=20 bound=16
  reserved=4 — `get_error`/`set_error` are `GError*`, the `use_es` pair is
  deprecated 4.12 in favour of the bound allowed-apis pair; all 7
  properties accessor-covered) and `GdkGLContext`
  (`src/gdk-gl-context.{h,c}`, gir=21 bound=19 reserved=2 —
  `get_shared_context` deprecated 4.4, `realize` is `throws=1` so it takes
  a `GError**`; all 3 properties accessor-covered). Version 0.8.0 → 0.8.1.
* **First Gdk class.** `GdkGLContext` is the first `Gdk\` annotation in
  this extension. Nothing in the pipeline needed changing: `audit-gir.php`
  already mapped `Gdk` → `Gdk-4.0`, `check-parity.php` already counted
  `gdk_` as a native prefix, and `gen-zep.php` emitted
  `Gtk\Gdk\GdkGLContext\GdkGLContext` into
  `gtk/gdk/gdkglcontext/gdkglcontext.zep` from the library segment alone.
  It is gir `abstract="1"`, so it needs no construction path — you obtain
  one from `GtkGLArea::getContext` or the static `getCurrent`.
  **Scope decision**: its parent `GdkDrawContext` (gir=6) was *not* bound.
  Inherited methods bind once on the declaring class and nothing in the
  GtkGLArea surface returns a bare `GdkDrawContext`, so binding it would
  have been scope the wave did not need. `getDisplay` / `getSurface`
  return `GdkDisplay` / `GdkSurface` handles whose classes are likewise
  unbound — handles are untyped ints, so those values stay usable when a
  later wave binds them.
* **Signal returns needed no Bridge change.** `render` must return TRUE to
  stop GTK's default handling. `phpgtk_closure_marshal` already writes a
  PHP handler's return into the signal's return GValue via
  `phpgtk_zval_to_gvalue`, whose first branch is `G_TYPE_BOOLEAN` — the
  same path `GtkWindow::close-request` uses. Returning `true` from PHP is
  all it takes; see [bridge.md](/bridge.md).
* **Proof**: `examples/proof_glarea.php` — a GtkWindow holding a
  GtkGLArea, with the render handler calling **ext-opengl** against the
  area's own framebuffer (VAO/VBO triangle, shader pair, `glReadPixels`
  centre+corner into an OpenGL Bridge buffer, byte-checked on the first
  rendered frame), then ~2s of real frames driven by `Bridge::pump`. On
  the Pi seat: 119 frames, centre RGBA `255,128,64,255`, corner
  `0,0,0,255`, PROOF_GLAREA_OK. GL constants are inline ints citing
  ext-opengl's vendored `scripts/khronos/glcorearb.h` by line, because
  constants live in jovian/ogx.
* **Trap found and recorded**: on the Pi, GDK can only give a GtkGLArea a
  **GLES** context — see
  [traps/glarea-is-gles-on-the-pi.md](/traps/glarea-is-gles-on-the-pi.md).
* Mac: GEN_OK, PARITY_OK, AUDIT_OK, TESTS_OK (surface checks added for
  both classes), PREPARE_EXT_OK. Pi (`/home/angel/gtk`): build,
  REFLECTION_OK (91 classes), PROOF_GLAREA_OK.

## 2026-09-12 (Wave C — calendar and column view)

* **Binding**: `GtkCalendar` (17 bound / 2 reserved: `GDateTime*`
  `get_date` / `select_day`) and the ColumnView family land in `src/`.
  `GtkColumnView` 24/2 (`GtkSorter*` / `GtkScrollInfo*`),
  `GtkColumnViewColumn` 18/2 (`GtkSorter*` get/set),
  `GtkSignalListItemFactory` 1/0 (transfer-full ctor; `setup`/`bind` via
  `Bridge::connect`), `GtkListItem` 15/0 obtain-only,
  `GtkSelectionModel` 8/3 (`GtkBitset*`), `GtkSingleSelection` 10/0,
  `GtkNoSelection` 3/0. `GtkListItemFactory` is gir=0 — no C surface.
  Calendar month is 0-based, as GTK reports it. `examples/wave_c.php`
  proves set/get y-m-d + `day-selected`, a 2-column ColumnView over a
  StringList with factory setup/bind, and `notify::selected` on a
  SingleSelection. Mac: GEN_OK, PARITY_OK, AUDIT_OK, TESTS_OK,
  PREPARE_EXT_OK. Pi (`/home/angel/gtk`): build, REFLECTION_OK (89
  classes), SMOKE_OK, WAVE_C_OK.

## 2026-09-04 (text-buffer read-back)
* **Binding**: `gtk_text_buffer_get_text` unreserved as
  `GtkTextBuffer::getText(handle, startOffset, endOffset, includeHiddenChars)`.
  New marshalling doctrine ([binding-rules](/binding-rules.md)): a
  `GtkTextIter*` parameter crosses as an int character offset;
  `phpgtk_arg_text_iter` in phpgtk-support.h mints the stack iter through
  `gtk_text_buffer_get_iter_at_offset` (pure read, -1 = end iterator), so
  the binding body still makes exactly one bound native call and
  check-parity's composite gate stays honest. Return is transfer-full →
  `phpgtk_ret_string_take`. Pipeline green end to end (GEN/PARITY/AUDIT/
  TESTS/PREPARE on the Mac; build + REFLECTION_OK + live read-back smoke
  on the Pi, gtk4 4.18.6). Consumed upstream: jovian/gtk regenerated,
  venusian-gtk's GTKTextArea now reads its buffer back on every edit —
  the "GTK text areas can't read back" gap is closed.

## 2026-08-31 (video wave)
* **Binding**: `GtkVideo` (17/17), `GtkMediaFile` (12/12) and `GtkMediaStream` (27 bound,
  7 reserved: deprecated 4.4 names, printf/GError raisers, `get_error`) land in `src/`.
  `GtkMediaStream` is abstract — added to the audit's OBTAIN_ONLY list (obtained from
  `GtkMediaFile` ctors or `GtkVideo::getMediaStream`). PARITY_OK, AUDIT_OK, TESTS_OK;
  built and reflected on the Pi. Runtime playback needs `libgtk-4-media-gstreamer`
  (now installed on the Pi) or the widget shows a broken-media icon.

## 2026-08-31
* **Packaging**: `ext/` re-scanned against the official
  `scripts/prepare-ext.sh` leftover list before deploy. Zero phpize /
  autoconf / libtool artifacts (`Makefile`, `configure`, `modules/`,
  `.libs/`, `*.lo`/`*.so`, `install`, `clean`). Ship-ready C intact:
  78 `.zep.c` / 78 `.zep.h`, 158 `src/*.{c,h}`, 40 kernel files,
  portable `config.m4`, `.gen-stamp`, `php_gtk.h` at 0.8.0. Did not
  regenerate.

## 2026-08-30 (css)
* **Binding**: `Gtk\GtkCssProvider` (new, loadFromString, loadFromPath, toString; GBytes/
  GFile/resource/named/deprecated-data reserved) and `Gtk\GtkStyleContext`'s two
  non-deprecated statics `addProviderForDisplay` / `removeProviderForDisplay` (the whole
  deprecated instance API reserved; class whitelisted OBTAIN_ONLY — nothing constructs
  it). AUDIT_OK, TESTS_OK, built + REFLECTION_OK on the Pi.

## 2026-08-30
* **Binding**: `Gio\GSimpleActionGroup` — Wave B2 pattern, `new()` bound, the four
  deprecated group methods reserved (supported surface is the generic `GActionMap`,
  already bound). One constructor completes the menu-activation chain:
  GSimpleAction + GSimpleActionGroup + GActionMap::addAction +
  GtkWidget::insertActionGroup. All gates green Mac-side; built, REFLECTION_OK (76
  classes) and smoke-tested on the Pi.

## 2026-08-28

- Wave B closed. `examples/wave_b.php` landed: every Wave B class proven
  live in one scene (28 constructed directly; GListModel via
  GtkStringList/GListStore, GAction via GSimpleAction, GActionMap via
  GtkApplicationWindow, GMenuModel via GMenu, GtkActionable via
  GtkButton, GtkNotebookPage/GtkStackPage obtained from their hosts),
  15 markers — INIT/CONSTRUCT/STRINGLIST (live `items-changed`)/
  LISTSTORE (`Bridge::typeFromName` GType constructor, `find` →
  `{position}`)/ACTIONS (add/lookup/remove on the window's action map)/
  MENUS (submenu link identity, freeze → immutable)/ACTIONABLE/DROPDOWN
  (selected item through the string model)/LISTBOX (synchronous
  `row-selected`)/FLOWBOX/TEXTMODEL (tag table + buffer + `insert` mark
  identity)/TEXTVIEW/PAGES (obtain-only NotebookPage/StackPage handles,
  paned position)/CHROME (headerbar + window controls + about-dialog
  GStrv round-trip)/POPOVER (parented onto a headerbar button, popped
  up through the pump) → `WAVE_B_OK` on the Pi seat. Two expected
  stderr notes documented in the demo: constructing GtkApplicationWindow
  on an unregistered GApplication prints a GTK CRITICAL (the Bridge
  never runs/registers apps) but works; empty GtkWindowControls may warn
  "min width -6". Menubar lesson: GtkPopoverMenuBar renders only
  submenus at its top level — plain items draw "Don't know how to
  handle this item". Close verified against the already-built Wave B
  extension (`REFLECTION_OK` 75 classes at B9); pipeline re-confirmed
  at close: `PARITY_OK` + `AUDIT_OK` (74 classes, 0 failures),
  `TESTS_OK`. Version stays 0.8.0.

- Wave B6–B9 sources landed against the vendored 4.18.6 gir. B6 window
  chrome: `GtkHeaderBar` 12/12/0, `GtkWindowControls` 8/8/0,
  `GtkApplicationWindow` 6/4/2 (deprecated help-overlay pair),
  `GtkAboutDialog` 34/34/0 (`GStrv` artists/authors/documenters). B7
  popovers: `GtkPopover` 21/21/0 + 1 property-only (`default-widget`),
  `GtkPopoverMenu` 8/8/0 + 1 property-only (`visible-submenu`),
  `GtkPopoverMenuBar` 5/5/0. `get_offset` → `{x_offset, y_offset}`;
  `set_pointing_to` takes component doubles. B8 text model:
  `GtkTextBuffer` 73/33/40 (`GtkTextIter*` / varargs / commit-notify /
  `GdkContentProvider*`) + 1 property-only (`cursor-position`),
  `GtkTextTag` 4/4/0 + 89 property-only, `GtkTextTagTable` 6/5/1
  (`foreach`), `GtkTextMark` 7/7/0. Buffer/tag/table/mark constructors
  are transfer-full. B9 text view: `GtkTextView` 74/59/15 (`GtkTextIter*`
  and `PangoTabArray*`) + 1 property-only (`im-module`). Per-class
  surface tests added; `scripts/verify-wave-b.php` measures b6/b7/b8/b9.
  Mac pipeline: `GEN_OK` (1274 methods, 75 classes), `PARITY_OK` +
  `AUDIT_OK` (74 classes, 0 failures), `TESTS_OK`, `PREPARE_EXT_OK`
  (65 registration sites fixed). Pi via `fnk` to `/home/angel/gtk`,
  `build-linux.sh` with `PHP_BIN=/usr/local/php84-zts/bin/php`:
  `REFLECTION_OK` (75 classes, 0 failures) including all twelve
  Wave B6–B9 types. Version stays 0.8.0.

## 2026-08-28

- Wave B3–B5 sources landed against the vendored 4.18.6 gir. B3 selection
  lists: `GtkDropDown` 21/19/2 (`GtkExpression*` get/set; `new(model)`
  passes NULL for the expression), `GtkListBox` 35/30/5 (bind/sort/filter/
  header/foreach callbacks) + 1 property-only (`accept-unpaired-release`),
  `GtkListBoxRow` 12/12/0. B4 flow and notebook: `GtkFlowBox` 35/31/4
  (bind/sort/filter/foreach) + 1 property-only, `GtkFlowBoxChild` 6/6/0,
  `GtkNotebook` 45/45/0 + 1 property-only (`enable-popup`; `get_pages`
  transfer-full), `GtkNotebookPage` 1/1/0 + 9 property-only, obtain-only.
  B5 stack and paned: `GtkStack` 24/24/0 (`get_pages` transfer-full),
  `GtkStackPage` 13/13/0 obtain-only, `GtkStackSwitcher` 3/3/0,
  `GtkStackSidebar` 3/3/0, `GtkPaned` 17/17/0 + 3 property-only
  (`max-position` / `min-position` / `position-set`). `OBTAIN_ONLY` now
  includes `Gtk\\GtkNotebookPage` and `Gtk\\GtkStackPage`. Per-class
  surface tests added; `scripts/verify-wave-b.php` measures b3/b4/b5.
  Mac pipeline: `GEN_OK` (1074 methods), `PARITY_OK` + `AUDIT_OK`
  (62 classes, 0 failures), `TESTS_OK`, `PREPARE_EXT_OK` (53
  registration sites fixed). Pi via `fnk` to `/home/angel/gtk`,
  `build-linux.sh` with `PHP_BIN=/usr/local/php84-zts/bin/php`:
  `REFLECTION_OK` (63 classes, 0 failures) including all twelve
  Wave B3–B5 types. Version stays 0.8.0.

## 2026-08-28

- Wave B1–B2 sources landed against the vendored 4.18.6 / Gio 2.84.4 gir.
  B1 Gio list foundation: `GListModel` interface 5/5/0 (transfer-full
  `get_item` / `get_object`), `GListStore` 11/7/4 (equal/sort callbacks
  reserved; `find` → `{position}`) + 2 property-only (`item-type` /
  `n-items`), `GtkStringObject` 2/2/0, `GtkStringList` 7/7/0 + 3
  property-only (`item-type` / `n-items` / `strings`; `take` via
  `phpgtk_arg_string_give`). `Bridge::typeFromName` added (1:1
  `g_type_from_name`) so `GListStore::new` can take a GType from PHP.
  B2 actions and menus: `GAction` interface 11/3/8 (`GVariant*` /
  `GVariantType*` / `GError**`), `GActionMap` interface 5/3/2
  (`GActionEntry*`), `GSimpleAction` 5/2/3 (`new_stateful` / state
  setters reserved; `new(name)` passes NULL for the `GVariantType*`)
  + 5 property-only, `GMenuModel` abstract 8/4/4 (varargs / `GVariant*`
  / attribute and link iterators), `GMenu` 16/16/0, `GMenuItem` 17/11/6
  (varargs / `GVariant*`), `GtkActionable` interface 6/3/3 + 1
  property-only (`action-target`). New reserved categories this wave:
  `GVariantType*`, `GActionEntry*`, `GMenuAttributeIter*` /
  `GMenuLinkIter*`, list equal/sort callbacks. Per-class surface tests
  added; `scripts/verify-wave-b.php` re-measures gir counts. Mac
  pipeline: `GEN_OK` (870 methods), `PARITY_OK` + `AUDIT_OK` (50
  classes, 0 failures), `TESTS_OK`, `PREPARE_EXT_OK` (41 registration
  sites fixed). Pi via `fnk` to `/home/angel/gtk`, `build-linux.sh`
  with `PHP_BIN=/usr/local/php84-zts/bin/php`: gtk 0.8.0 (Build Date
  Aug 28 2026 03:02:20), `REFLECTION_OK` (51 classes, 0 failures)
  including `Bridge` (12 methods — `typeFromName` present) and all
  eleven Wave B1–B2 types. Version stays 0.8.0.

## 2026-08-28

- Wave A closed. `examples/wave_a.php` landed: every Wave A class proven
  live in one scene (29 constructed directly; GtkEditable via
  GtkEntry/GtkSearchEntry, GtkRange via GtkScale, GtkScrollable via
  GtkViewport), 14 markers — INIT/CONSTRUCT/EDITABLE (getChars +
  `{start_pos, end_pos}` selection bounds)/BUFFER (one GtkEntryBuffer
  feeding GtkEntry and GtkText)/TOGGLES (synchronous `toggled` +
  `notify::active`)/RANGES (`value-changed` on a first-class
  GtkAdjustment shared by scale and scrollbar; GtkRange methods on the
  scale handle)/FEEDBACK/CONTAINERS (grid `queryChild`, centerbox, frame,
  overlay, aspect ratio)/SCROLL (viewport adjustments ==
  scrolledwindow's via the GtkScrollable interface)/PRESENT/FIXED/
  REVEALER (animated reveal through the pump)/SEARCH (`search-changed`
  riding the GLib search-delay timeout) → `WAVE_A_OK` on the Pi seat.
  One new trap measured on the way:
  `gtk_fixed_get_child_position` answers in allocated coordinates
  ({0,0} before allocation, scene-constant theme offset after; a visible
  window can still have unallocated deep descendants) — recorded in
  [traps/fixed-child-position.md](/traps/fixed-child-position.md)
  (`status: draft`), demo asserts move deltas only. Version demoted
  0.9.0 → 0.8.0 in `composer.json`, `config.json`, `ext/php_gtk.h`;
  fresh `pi-wave-verify.sh` run after the demote: `REFLECTION_OK`
  (40 classes, 0 failures), `php --ri gtk` → 0.8.0, `WAVE_A_OK` and
  `SMOKE_OK` re-confirmed on the seat. Per-class surface tests for all
  32 Wave A classes were already wired into `run-all.php` during A1–A8;
  `TESTS_OK` + `PARITY_OK` + `AUDIT_OK` (39 classes) re-verified at
  close.

- Wave A6–A8 sources landed against the vendored 4.18.6 gir. A6 feedback:
  `GtkSpinner` 5/5/0, `GtkProgressBar` 14/14/0 (`get_text` nullable),
  `GtkLevelBar` 15/15/0 (`get_offset_value` → `{value}`), `GtkSeparator`
  1/1/0. A7 layout containers: `GtkFrame` 9/9/0, `GtkAspectFrame` 11/11/0,
  `GtkCenterBox` 11/11/0, `GtkGrid` 23/23/0 (`query_child` →
  `{column, row, width, height}`), `GtkFixed` 7/5/2 (`GskTransform*`
  child-transform pair; `get_child_position` → `{x, y}`), `GtkOverlay`
  9/9/0. A8 scroll and reveal: `GtkScrollable` interface 9/9/0
  (`get_border` → `{left, right, top, bottom}`), `GtkViewport` 6/5/1
  (`GtkScrollInfo*` `scroll_to` reserved), `GtkScrolledWindow` 32/32/0 +
  2 property-only (`hscrollbar-policy` / `vscrollbar-policy`;
  `get_policy` → `{hscrollbar_policy, vscrollbar_policy}`), `GtkExpander`
  16/16/0, `GtkRevealer` 10/10/0. New reserved category this wave:
  `GtkScrollInfo*` boxed. Per-class surface tests added;
  `scripts/verify-wave-a.php` now measures a6/a7/a8. Mac pipeline:
  `GEN_OK` (806 methods), `PARITY_OK` + `AUDIT_OK` (39 classes, 0
  failures), `TESTS_OK`, `PREPARE_EXT_OK` (38 registration sites
  fixed). Pi via `fnk` to `/home/angel/gtk`, `build-linux.sh` with
  `PHP_BIN=/usr/local/php84-zts/bin/php`: `REFLECTION_OK` (40 classes,
  0 failures) including all fifteen Wave A6–A8 types. Manifests stay
  at 0.9.0 until Wave A close.

## 2026-08-28

- Wave A4–A5 sources landed against the vendored 4.18.6 gir. A4 ranges:
  `GtkRange` 22/22/0 (no gir constructor — added to `OBTAIN_ONLY`),
  `GtkScale` 15/14/1 (`set_format_value_func` callback reserved),
  `GtkScrollbar` 3/3/0, `GtkSpinButton` 28/28/0 (out-params `{step, page}`
  / `{min, max}`). A5 display media: `GtkLabel` 51/47/4 (`PangoAttrList*` /
  `PangoTabArray*`; `get_layout` is a `PangoLayout*` handle;
  `get_selection_bounds` → `{start, end}`), `GtkImage` 22/20/2 (deprecated
  pixbuf pair) + 3 property-only (`file` / `resource` / `use-fallback`),
  `GtkPicture` 21/17/4 (deprecated pixbuf + keep-aspect-ratio). Per-class
  surface tests added; `scripts/verify-wave-a.php` now measures a4/a5.
  Mac pipeline: `GEN_OK` (631 methods), `PARITY_OK` + `AUDIT_OK` (24 classes,
  0 failures), `TESTS_OK`, `PREPARE_EXT_OK` (23 registration sites fixed).
  Pi via `fnk` to `/home/angel/gtk`, `build-linux.sh` with
  `PHP_BIN=/usr/local/php84-zts/bin/php`: `REFLECTION_OK` (25 classes,
  0 failures) including all seven Wave A4–A5 types. Version stays 0.9.0
  until the rest of Wave A verifies.

## 2026-08-28

- Wave A1–A3 sources landed against the vendored 4.18.6 gir. A1 foundations:
  `GtkAdjustment` 16/16/0, `GtkEditable` 27/24/3 (implementor helpers that
  take `GValue*`/`GParamSpec*`/`GObjectClass*` reserved) + `selection-bound`
  property-only, `GtkEntryBuffer` 11/11/0 (constructor transfer-full →
  `phpgtk_handle_register_take`). A2 text entries: `GtkEntry` 60/53/7
  (`PangoAttrList*`, `PangoTabArray*`, `GdkContentProvider*`, deprecated
  completion) + 22 property-only, `GtkText` 36/32/4 + 3 property-only
  (`compute_cursor_extents` → `{strong, weak}` graphene rects). A3 toggles
  and specialty entries: `GtkPasswordEntry` 5/5/0 + 2 property-only,
  `GtkSearchEntry` 11/11/0 + 1 property-only, `GtkToggleButton` 7/6/1
  (`toggled` deprecated), `GtkCheckButton` 14/14/0, `GtkSwitch` 5/5/0.
  New reserved categories this wave: `PangoAttrList*`, `PangoTabArray*`,
  `GdkContentProvider*`, `GObjectClass*` install helpers. Per-class surface
  tests added to `scripts/tests/run-all.php`; `scripts/verify-wave-a.php`
  re-measures gir counts instead of copying the plan totals. Mac pipeline:
  `GEN_OK` (480 methods), `PARITY_OK` + `AUDIT_OK` (17 classes, 0 failures),
  `TESTS_OK`, `PREPARE_EXT_OK` (16 registration sites fixed). Pi via `fnk`
  to `/home/angel/gtk`, `build-linux.sh` with
  `PHP_BIN=/usr/local/php84-zts/bin/php`: gtk 0.9.0 (Build Date Aug 28 2026
  02:02:23), `REFLECTION_OK` (18 classes, 0 failures) including all ten
  Wave A types. Manifests stay at 0.9.0 until the rest of Wave A verifies.

## 2026-08-28

- Version demoted 0.9.0 → 0.8.0 in the committed manifests
  (`composer.json`, `config.json`, `ext/php_gtk.h`) after a fresh Pi
  verification: copy via `fnk` to `/home/angel/gtk`, `build-linux.sh`
  with `PHP_BIN=/usr/local/php84-zts/bin/php` (Build Date Aug 28 2026
  01:34:04 at 0.9.0), `REFLECTION_OK` (8 classes, 0 failures),
  `PROOF_OK`, `PROOF_WINDOW_OK`, `SMOKE_OK` (INIT/REGISTRY/ROUNDTRIP/
  PROPERTY/CONNECT/CLICKED/DISCONNECT/CLOSE_VETO/CLOSE/SURVIVES_CLOSE/
  CONNECT_GUARD/NOTIFY). Seat env:
  `XDG_RUNTIME_DIR=/run/user/1000 DISPLAY=:0 GTK_A11Y=none`. Rebuilt
  after the demote so `php --ri gtk` reports 0.8.0 (source edits alone
  leave a stale `.so` — same trap appkit hit).

- First full pipeline green end to end. Mac: `GEN_OK` (303 methods),
  `PARITY_OK` + `AUDIT_OK` (7 classes audited, 0 failures), `TESTS_OK`,
  `PREPARE_EXT_OK` (6 registration sites fixed, gen-stamp written), initial
  commit with `ext/` staged at 0.9.0. Pi (fnk box, Debian 13 / aarch64 /
  PHP 8.4.20 ZTS / GTK 4.18.6): `build-linux.sh` compiled the committed
  `ext/` clean on the first try, `php --ri gtk` reports 0.9.0,
  `REFLECTION_OK` (8 classes), `PROOF_OK`, `PROOF_WINDOW_OK`, and
  `SMOKE_OK` on the first run — 12 markers covering the registry (stale
  handles resolve invalid), setter/getter round-trips, the property
  fallback, a real `clicked` into a PHP callable via `activate` + pumping
  through the press animation, disconnect, `close-request` veto/allow
  writeback, registry ref surviving the close, the connect guard (unknown
  signal, underscore `notify::` detail pointing at the dashed name), and
  a live `notify::use-underline`. One build failure on the way: macOS tar
  shipped AppleDouble `._*` files that broke the gen-stamp and crashed
  Zephir — gotcha recorded on [toolchain.md](/toolchain.md) (use
  `COPYFILE_DISABLE=1`, exclude `._*`). Seat env for GUI proofs recorded
  there too (`XDG_RUNTIME_DIR=/run/user/1000 DISPLAY=:0 GTK_A11Y=none`).
  Examples landed: `proof_of_work.php` (headless), `proof_window.php`,
  `smoke.php`.

- Slice-zero sources landed: `src/gtk-widget.{h,c}` (gir=166 bound=151
  reserved=15 + 2 property-only), `src/gtk-window.{h,c}` (62/61/1 + 5
  property-only), `src/gtk-button.{h,c}` (16/16/0, the worked example),
  `src/gtk-box.{h,c}` (14/14/0), `src/gtk-orientable.{h,c}` (interface,
  2/2/0), `src/gtk-application.{h,c}` (15/15/0 + 2 property-only),
  `src/gio-gapplication.{h,c}` (39/33/6). 303 bindings total. Reserved
  categories seen so far: deprecated members, varargs, `GVariant*`,
  `GError**` (`g_application_register` — the remote-instance judgement
  belongs above the 1:1 layer), `GOptionEntry*`/`GOptionGroup*`,
  `gpointer` busy-property binds, `GtkTickCallback`, `GskTransform*`,
  `graphene_matrix_t`. `audit-gir.php` gained the property-only-reservation
  rule: an `@reserved … property "x"` line with no native symbol covers a
  gir `<property>` row and does not count toward the member sum.
- Negative controls ported (`scripts/tests/`): drift-guard, parity-guard,
  audit-guard, audit-parse, prepare-ext-guard (proves `fix_register_macro`
  fires), structure-check, plus per-class surface checks for all seven
  slice-zero classes and `run-all.php` (TESTS_OK).
- Bridge + toolchain landed. `src/phpgtk-bridge.{h,c}`: init, GHashTable
  registry (`ref_sink` on register, value-destroy unref, stale handles
  resolve NULL), pump (drain + `g_timeout_add` wake), connect with the
  salvaged dep-gtk guards reporting via `E_WARNING` instead of the deleted
  ZTS-unsafe last-error global, disconnect
  (`g_signal_handler_is_connected` first), get/setProperty. Scripts:
  `gen-zep.php` (root ns `Gtk\`, tree `gtk/`, prefix `phpgtk_`),
  `check-parity.php` (parses `.c`; composite guard = max one native call,
  registration structurally uncounted; chains the gir audit),
  `audit-gir.php` (DOMXPath over gzipped girs), `prepare-ext.sh`
  (`fix_register_macro` verbatim from dep-gtk + appkit leftover-strip +
  `ext/.gen-stamp`), `verify-reflection.php`. `build-linux.sh`: 4.18.0
  floor, gen-stamp staleness check, python3 check dropped. Manifests at
  0.9.0 for the build loop.
- Girs vendored from the Pi (`scripts/gir/`, gzipped, README with
  provenance): Gtk/Gdk/Gsk-4.0 4.18.6+ds-2, Gio/GObject/GLib-2.0
  2.84.4-3~deb13u2, Pango-1.0 1.56.3-1. Quirk: Debian ships `GLib-2.0.gir`
  in arch-specific `/usr/lib/aarch64-linux-gnu/gir-1.0/`, not
  `/usr/share/gir-1.0/`.
- Support salvaged from dep-gtk into `src/phpgtk-support.{h,c}`: 15-branch
  GValue→zval, zval→GValue writeback, `PhpGtkClosure`, strv helpers —
  renamed `phpgtk_`. Deleted: `php_gtk_last_error` global (ZTS bug), tick
  bridge, async-dialog machinery. Behaviour change vs donor:
  `phpgtk_gvalue_to_zval` registers GObject signal params so handlers get
  resolvable handles.
- Bundle seeded by claude-fable-5/cursor:
  `binding-rules.md`, `bridge.md`, `toolchain.md` (all `status: draft`
  pending human verification); `traps/control-signal-surprises.md` and
  `conventions/signal-lifetime.md` copied **verbatim** from dep-gtk
  (`status: stable` — measured GTK 4.18.6 behaviour; their source-path
  frontmatter references the dep-gtk tree, and signal-lifetime's
  `gtkLastMessage()` mention describes the donor's error channel, which
  this extension replaced with `E_WARNING`).
