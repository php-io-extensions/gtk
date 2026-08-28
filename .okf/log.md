# Change log

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
