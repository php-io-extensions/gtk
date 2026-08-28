---
type: Convention
title: GTK4 binding rules
description: >-
  The spec every bound class follows: one PHP static method per GTK C
  function, no opinions, nothing silently omitted, audited against the
  vendored GObject-Introspection XML.
tags: [binding, zephir, gtk4, gir]
status: draft
generated:
  by: cursor-grok-4.6/cursor
  at: 2026-08-28T10:00:00Z
---

# GTK4 binding rules

The extension exposes GTK 4.18 into PHP 1:1. The audit truth is the vendored
GObject-Introspection XML in `scripts/gir/` (harvested from the Pi 5 build
box — see the README there for provenance), not C headers. Layering:
**ext = GTK + unavoidable glue; jovian/gtk = PHP function per ext call;
venusian = composition; surface = abstraction.**

## The one rule

**One ext call = one native call** (`gtk_*` / `g_*` / `gdk_*` / `gsk_*` /
`pango_*`). Composition belongs in PHP-land, never below. The single
sanctioned composite is **constructor + registry sink**: a constructor
binding calls `gtk_button_new()` and hands the result to
`phpgtk_handle_register()`, which `g_object_ref_sink`s and returns the
handle. Registration is glue, not a native call, so the composite guard in
`check-parity.php` enforces the rule structurally — a binding body may
contain at most one native-prefixed call, with only the frees demanded by
the translation table whitelisted (`g_free`, `g_strfreev`, list frees,
`g_object_unref` for transfer-full object returns, `g_error_free`).

## Translation table

| GTK / GLib | PHP |
|---|---|
| `GtkButton` (gir class) | `Gtk\Gtk\GtkButton\GtkButton` static class, file `gtk/gtk/gtkbutton/gtkbutton.zep`; first annotation segment = library (`Gtk\`, `Gdk\`, `Gio\`, `GLib\`, `Pango\`) |
| `gtk_button_set_label(button, label)` | `GtkButton::setLabel(int handle, string label): void` — strip `<lib>_<class>_`, camelCase |
| `gtk_button_new()` | `GtkButton::new_(): int` (constructor + registry sink; `new` is a Zephir reserved word) |
| `gboolean` / int, guint, gint64, enum, flags / float, double | bool / int / double |
| `const char*` in; nullable string | `string`; `var` (null = NULL) |
| `char*` return transfer-full | string, `g_free` in the binding (gir `transfer-ownership` decides) |
| any `GObject*` / widget / interface pointer | int handle (0 = NULL), resolved only via the registry (`PHPGTK_RESOLVE`); stale ints resolve to NULL, never a dangling deref |
| `GdkRGBA`, `GdkRectangle`, `graphene_rect_t` / `point_t` | component doubles in, assoc array out |
| scalar out-params (`int*`, `gboolean*`, `double*`, …) | assoc array out, keys = C parameter names (`gtk_widget_get_size_request` → `{width, height}`) |
| `char**` / `GStrv` | array of strings (`phpgtk_zval_to_strv` / `phpgtk_ret_strv`) |
| `GList*` / `GSList*` of objects | array of handles, list freed per transfer mode |
| `GError**`, varargs, non-signal callbacks (`GtkTickCallback`, `GAsyncReadyCallback`, sort funcs), `GtkTextIter*` / stack boxed, `GVariant*`, deprecated | not bound; kept as a commented `@reserved` signature (nothing silently omitted) |
| property with C accessors | covered by the bound getter/setter (audit resolves gir `getter=`/`setter=` attributes, falling back to `get_x`/`is_x`/`has_x`/`set_x` name mapping) |
| property without C accessors | `/*@reserved <class> property "x" — …*/` + generic `Bridge::getProperty`/`setProperty`; property-only reservations do **not** count toward the member sum |
| signals | Bridge territory only (`Bridge::connect`) — GTK's analogue of appkit's delegates/notifications; gir `<glib:signal>` rows are informational in the audit |
| inherited methods | bound once on the declaring class; handles are untyped, so `GtkWidget::setHexpand($button, …)` works |
| interfaces (`GtkOrientable`, `GtkEditable`, …) | bound as classes of their own; exempt from the construction requirement |
| abstract classes (gir `abstract="1"`) | no construction requirement (e.g. `GtkWidget`); obtain-only classes (`GtkSettings`, `GdkDisplay`) live on the `OBTAIN_ONLY` audit whitelist |

## Worked examples (slice zero, GTK 4.18.6 gir counts)

- [`src/gtk-button.{h,c}`](src/gtk-button.h) — the worked example:
  `gir=16 bound=16 reserved=0` (4 constructors, 12 methods; every property
  accessor-covered).
- [`src/gtk-widget.{h,c}`](src/gtk-widget.h) — `gir=166 bound=151
  reserved=15` (10 deprecated members, varargs `activate_action`,
  `GVariant*`, `GtkTickCallback`, `GskTransform*`, `graphene_matrix_t`),
  plus 2 property-only reservations (`width-request` / `height-request`
  have no dedicated C accessors). Abstract — no construction path.
- [`src/gtk-window.{h,c}`](src/gtk-window.h) — `gir=62 bound=61 reserved=1`
  (`present_with_time` deprecated), plus 5 property-only reservations
  (`default-width` / `default-height` / `display` / `fullscreened` /
  `maximized`).
- [`src/gtk-box.{h,c}`](src/gtk-box.h) — `gir=14 bound=14 reserved=0`.
- [`src/gtk-orientable.{h,c}`](src/gtk-orientable.h) — interface,
  `gir=2 bound=2 reserved=0`.
- [`src/gtk-application.{h,c}`](src/gtk-application.h) — `gir=15 bound=15
  reserved=0`, plus 2 property-only reservations (`register-session` /
  `screensaver-active`).
- [`src/gio-gapplication.{h,c}`](src/gio-gapplication.h) — `gir=39 bound=33
  reserved=6` (`GError**` register, `GOptionEntry*`/`GOptionGroup*`,
  `gpointer` busy-property binds, deprecated `set_action_group`).
  `g_application_register` is reserved here because its usable form —
  refusing remote instances — is judgement the 1:1 layer must not make;
  see [traps/control-signal-surprises.md](/traps/control-signal-surprises.md)
  for why a remote instance segfaults window creation. PHP drives the loop
  via `Bridge::pump`, never `g_application_run`.

## Worked examples (Wave A1–A3, GTK 4.18.6 gir counts)

- [`src/gtk-adjustment.{h,c}`](src/gtk-adjustment.h) — `gir=16 bound=16 reserved=0`.
- [`src/gtk-editable.{h,c}`](src/gtk-editable.h) — interface, `gir=27 bound=24 reserved=3`
  (`delegate_get_property` / `delegate_set_property` / `install_properties`
  take `GValue*`/`GParamSpec*`/`GObjectClass*`), plus 1 property-only
  reservation (`selection-bound`).
- [`src/gtk-entry-buffer.{h,c}`](src/gtk-entry-buffer.h) — `gir=11 bound=11 reserved=0`.
  Constructor is transfer-full, so it uses `phpgtk_handle_register_take`.
- [`src/gtk-entry.{h,c}`](src/gtk-entry.h) — `gir=60 bound=53 reserved=7`
  (`PangoAttrList*`, `PangoTabArray*`, `GdkContentProvider*`, deprecated
  completion pair), plus 22 property-only reservations (icon-side properties
  and `im-module` / `enable-emoji-completion` / `truncate-multiline` / …).
- [`src/gtk-text.{h,c}`](src/gtk-text.h) — `gir=36 bound=32 reserved=4`
  (`PangoAttrList*` / `PangoTabArray*`), plus 3 property-only reservations.
  `compute_cursor_extents` returns `{strong, weak}` graphene rects.
- [`src/gtk-password-entry.{h,c}`](src/gtk-password-entry.h) — `gir=5 bound=5 reserved=0`,
  plus 2 property-only reservations (`activates-default` / `placeholder-text`).
- [`src/gtk-search-entry.{h,c}`](src/gtk-search-entry.h) — `gir=11 bound=11 reserved=0`,
  plus 1 property-only reservation (`activates-default`).
- [`src/gtk-toggle-button.{h,c}`](src/gtk-toggle-button.h) — `gir=7 bound=6 reserved=1`
  (`toggled` deprecated).
- [`src/gtk-check-button.{h,c}`](src/gtk-check-button.h) — `gir=14 bound=14 reserved=0`.
- [`src/gtk-switch.{h,c}`](src/gtk-switch.h) — `gir=5 bound=5 reserved=0`.

## Worked examples (Wave A4–A5, GTK 4.18.6 gir counts)

- [`src/gtk-range.{h,c}`](src/gtk-range.h) — `gir=22 bound=22 reserved=0`. No gir
  constructor; first customer of the `OBTAIN_ONLY` audit whitelist
  (`Gtk\\GtkRange`). Obtain via `GtkScale` / `GtkScrollbar`.
- [`src/gtk-scale.{h,c}`](src/gtk-scale.h) — `gir=15 bound=14 reserved=1`
  (`set_format_value_func` non-signal callback).
- [`src/gtk-scrollbar.{h,c}`](src/gtk-scrollbar.h) — `gir=3 bound=3 reserved=0`.
- [`src/gtk-spin-button.{h,c}`](src/gtk-spin-button.h) — `gir=28 bound=28 reserved=0`.
  Scalar out-params return `{step, page}` / `{min, max}`.
- [`src/gtk-label.{h,c}`](src/gtk-label.h) — `gir=51 bound=47 reserved=4`
  (`PangoAttrList*` / `PangoTabArray*`). `get_layout` is a `PangoLayout*`
  handle. `get_selection_bounds` returns `{start, end}`.
- [`src/gtk-image.{h,c}`](src/gtk-image.h) — `gir=22 bound=20 reserved=2`
  (deprecated pixbuf constructor/setter), plus 3 property-only reservations
  (`file` / `resource` / `use-fallback`).
- [`src/gtk-picture.{h,c}`](src/gtk-picture.h) — `gir=21 bound=17 reserved=4`
  (deprecated pixbuf constructor/setter and keep-aspect-ratio pair).

## Worked examples (Wave A6–A8, GTK 4.18.6 gir counts)

- [`src/gtk-spinner.{h,c}`](src/gtk-spinner.h) — `gir=5 bound=5 reserved=0`.
- [`src/gtk-progress-bar.{h,c}`](src/gtk-progress-bar.h) — `gir=14 bound=14 reserved=0`.
  `get_text` is nullable (`var`).
- [`src/gtk-level-bar.{h,c}`](src/gtk-level-bar.h) — `gir=15 bound=15 reserved=0`.
  `get_offset_value` returns `{value}`.
- [`src/gtk-separator.{h,c}`](src/gtk-separator.h) — `gir=1 bound=1 reserved=0`.
- [`src/gtk-frame.{h,c}`](src/gtk-frame.h) — `gir=9 bound=9 reserved=0`.
- [`src/gtk-aspect-frame.{h,c}`](src/gtk-aspect-frame.h) — `gir=11 bound=11 reserved=0`.
- [`src/gtk-center-box.{h,c}`](src/gtk-center-box.h) — `gir=11 bound=11 reserved=0`.
- [`src/gtk-grid.{h,c}`](src/gtk-grid.h) — `gir=23 bound=23 reserved=0`.
  `query_child` returns `{column, row, width, height}`.
- [`src/gtk-fixed.{h,c}`](src/gtk-fixed.h) — `gir=7 bound=5 reserved=2`
  (`GskTransform*` child-transform pair). `get_child_position` returns `{x, y}`.
- [`src/gtk-overlay.{h,c}`](src/gtk-overlay.h) — `gir=9 bound=9 reserved=0`.
- [`src/gtk-scrollable.{h,c}`](src/gtk-scrollable.h) — interface,
  `gir=9 bound=9 reserved=0`. `get_border` returns `{left, right, top, bottom}`.
- [`src/gtk-viewport.{h,c}`](src/gtk-viewport.h) — `gir=6 bound=5 reserved=1`
  (`GtkScrollInfo*` `scroll_to`).
- [`src/gtk-scrolled-window.{h,c}`](src/gtk-scrolled-window.h) — `gir=32 bound=32 reserved=0`,
  plus 2 property-only reservations (`hscrollbar-policy` / `vscrollbar-policy`
  have no dedicated C accessors; `get_policy`/`set_policy` cover the members).
  `get_policy` returns `{hscrollbar_policy, vscrollbar_policy}`.
- [`src/gtk-expander.{h,c}`](src/gtk-expander.h) — `gir=16 bound=16 reserved=0`.
- [`src/gtk-revealer.{h,c}`](src/gtk-revealer.h) — `gir=10 bound=10 reserved=0`.

## Worked examples (Wave B1–B2, GTK 4.18.6 / Gio 2.84.4 gir counts)

- [`src/gio-glistmodel.{h,c}`](src/gio-glistmodel.h) — interface,
  `gir=5 bound=5 reserved=0`. `get_item` / `get_object` are transfer-full.
- [`src/gio-gliststore.{h,c}`](src/gio-gliststore.h) — `gir=11 bound=7 reserved=4`
  (equal/sort callbacks). Constructor takes a `GType` from
  `Bridge::typeFromName`. `find` returns `{position}`. Plus 2 property-only
  reservations (`item-type` / `n-items`; getters live on GListModel).
- [`src/gtk-string-object.{h,c}`](src/gtk-string-object.h) — `gir=2 bound=2 reserved=0`.
  Constructor is transfer-full (`phpgtk_handle_register_take`).
- [`src/gtk-string-list.{h,c}`](src/gtk-string-list.h) — `gir=7 bound=7 reserved=0`,
  plus 3 property-only reservations (`item-type` / `n-items` / `strings`).
  `take` gives the string via `phpgtk_arg_string_give`.
- [`src/gio-gaction.{h,c}`](src/gio-gaction.h) — interface,
  `gir=11 bound=3 reserved=8` (`GVariant*` / `GVariantType*` / `GError**`).
- [`src/gio-gactionmap.{h,c}`](src/gio-gactionmap.h) — interface,
  `gir=5 bound=3 reserved=2` (`GActionEntry*` arrays).
- [`src/gio-gsimpleaction.{h,c}`](src/gio-gsimpleaction.h) — `gir=5 bound=2 reserved=3`
  (`new_stateful` / `set_state` / `set_state_hint` are `GVariant*`).
  `new(name)` passes NULL for the reserved `GVariantType*` parameter type.
  Plus 5 property-only reservations (getters live on GAction).
- [`src/gio-gmenumodel.{h,c}`](src/gio-gmenumodel.h) — abstract,
  `gir=8 bound=4 reserved=4` (varargs / `GVariant*` / `GMenuAttributeIter*` /
  `GMenuLinkIter*`).
- [`src/gio-gmenu.{h,c}`](src/gio-gmenu.h) — `gir=16 bound=16 reserved=0`.
- [`src/gio-gmenuitem.{h,c}`](src/gio-gmenuitem.h) — `gir=17 bound=11 reserved=6`
  (varargs / `GVariant*`).
- [`src/gtk-actionable.{h,c}`](src/gtk-actionable.h) — interface,
  `gir=6 bound=3 reserved=3` (`GVariant*` / varargs), plus 1 property-only
  reservation (`action-target`; getter is the reserved `GVariant*` member).

## Worked examples (Wave B3–B5, GTK 4.18.6 gir counts)

- [`src/gtk-drop-down.{h,c}`](src/gtk-drop-down.h) — `gir=21 bound=19 reserved=2`
  (`GtkExpression*` get/set). `new(model)` passes NULL for the reserved
  expression argument, same pattern as `GSimpleAction::new`. Factory
  getters/setters are int handles.
- [`src/gtk-list-box.{h,c}`](src/gtk-list-box.h) — `gir=35 bound=30 reserved=5`
  (`bind_model` / `selected_foreach` / filter / header / sort callbacks),
  plus 1 property-only reservation (`accept-unpaired-release`).
  `get_selected_rows` is a container-owned GList of handles.
- [`src/gtk-list-box-row.{h,c}`](src/gtk-list-box-row.h) — `gir=12 bound=12 reserved=0`.
- [`src/gtk-flow-box.{h,c}`](src/gtk-flow-box.h) — `gir=35 bound=31 reserved=4`
  (`bind_model` / `selected_foreach` / filter / sort callbacks), plus 1
  property-only reservation (`accept-unpaired-release`).
- [`src/gtk-flow-box-child.{h,c}`](src/gtk-flow-box-child.h) — `gir=6 bound=6 reserved=0`.
- [`src/gtk-notebook.{h,c}`](src/gtk-notebook.h) — `gir=45 bound=45 reserved=0`,
  plus 1 property-only reservation (`enable-popup`). `get_pages` is
  transfer-full; `get_page` returns an obtain-only GtkNotebookPage handle.
- [`src/gtk-notebook-page.{h,c}`](src/gtk-notebook-page.h) — `gir=1 bound=1 reserved=0`,
  plus 9 property-only reservations. Obtain-only (`OBTAIN_ONLY`).
- [`src/gtk-stack.{h,c}`](src/gtk-stack.h) — `gir=24 bound=24 reserved=0`.
  `get_pages` is transfer-full; `add_*` / `get_page` return obtain-only
  GtkStackPage handles.
- [`src/gtk-stack-page.{h,c}`](src/gtk-stack-page.h) — `gir=13 bound=13 reserved=0`.
  Obtain-only (`OBTAIN_ONLY`).
- [`src/gtk-stack-switcher.{h,c}`](src/gtk-stack-switcher.h) — `gir=3 bound=3 reserved=0`.
- [`src/gtk-stack-sidebar.{h,c}`](src/gtk-stack-sidebar.h) — `gir=3 bound=3 reserved=0`.
- [`src/gtk-paned.{h,c}`](src/gtk-paned.h) — `gir=17 bound=17 reserved=0`,
  plus 3 property-only reservations (`max-position` / `min-position` /
  `position-set`).

## Worked examples (Wave B6–B9, GTK 4.18.6 gir counts)

- [`src/gtk-header-bar.{h,c}`](src/gtk-header-bar.h) — `gir=12 bound=12 reserved=0`.
- [`src/gtk-window-controls.{h,c}`](src/gtk-window-controls.h) — `gir=8 bound=8 reserved=0`.
- [`src/gtk-application-window.{h,c}`](src/gtk-application-window.h) — `gir=6 bound=4 reserved=2`
  (deprecated `get_help_overlay` / `set_help_overlay`).
- [`src/gtk-about-dialog.{h,c}`](src/gtk-about-dialog.h) — `gir=34 bound=34 reserved=0`.
  Artists / authors / documenters are `GStrv`.
- [`src/gtk-popover.{h,c}`](src/gtk-popover.h) — `gir=21 bound=21 reserved=0`,
  plus 1 property-only reservation (`default-widget`; setter is bound).
  `get_offset` returns `{x_offset, y_offset}`; `get_pointing_to` returns a
  `GdkRectangle` assoc array; `set_pointing_to` takes component doubles.
- [`src/gtk-popover-menu.{h,c}`](src/gtk-popover-menu.h) — `gir=8 bound=8 reserved=0`,
  plus 1 property-only reservation (`visible-submenu`).
- [`src/gtk-popover-menu-bar.{h,c}`](src/gtk-popover-menu-bar.h) — `gir=5 bound=5 reserved=0`.
- [`src/gtk-text-buffer.{h,c}`](src/gtk-text-buffer.h) — `gir=73 bound=33 reserved=40`
  (`GtkTextIter*` members, `create_tag` / insert-with-tags varargs,
  `add_commit_notify` callback, `GdkContentProvider*`
  `get_selection_content`), plus 1 property-only reservation
  (`cursor-position`). Constructor is transfer-full
  (`phpgtk_handle_register_take`).
- [`src/gtk-text-tag.{h,c}`](src/gtk-text-tag.h) — `gir=4 bound=4 reserved=0`,
  plus 89 property-only reservations (almost all accessor-less; use
  `Bridge::getProperty` / `setProperty`). Constructor is transfer-full.
- [`src/gtk-text-tag-table.{h,c}`](src/gtk-text-tag-table.h) — `gir=6 bound=5 reserved=1`
  (`foreach` non-signal callback). Constructor is transfer-full.
- [`src/gtk-text-mark.{h,c}`](src/gtk-text-mark.h) — `gir=7 bound=7 reserved=0`.
  Constructor is transfer-full.
- [`src/gtk-text-view.{h,c}`](src/gtk-text-view.h) — `gir=74 bound=59 reserved=15`
  (`GtkTextIter*` members and `PangoTabArray*` get/set tabs), plus 1
  property-only reservation (`im-module`).
  `buffer_to_window_coords` / `window_to_buffer_coords` /
  `get_visible_offset` return assoc arrays of the C out-param names.

## Mechanics

- C symbol: `phpgtk_<classlower>_<function_snake>(zval *…)`; int/bool/double
  return by value, string/array/var written into a leading
  `zval *return_value`. The prefix never collides with real GTK symbols.
- Every C prototype carries a
  `/*@zep Gtk\GtkButton setLabel(int handle, string label) -> void */` line.
  `.zep` files and optimizers are **generated** from those lines by
  [`scripts/gen-zep.php`](/toolchain.md) — never hand-written.
- Zephir reserved words in method **and parameter** names get a trailing
  underscore (`new_`, `default_`); all-caps names are emitted mixed-case
  (Zephir lexes all-caps identifiers as constants; PHP method lookup is
  case-insensitive). Both rules are appkit inheritance kept as insurance.
- Marshalling only via `src/phpgtk-support.{h,c}`. All glue only in
  [`Gtk\Bridge\Bridge`](/bridge.md); no other `PhpGtk*` machinery may exist.
- No error side channel: constructors return 0 on failure, fallible Bridge
  calls raise `E_WARNING`, GTK CRITICALs stay on stderr. dep-gtk's
  process-global `php_gtk_last_error` was a ZTS bug and was deliberately
  not carried over.
- Constants live in `jovian/gtk` as PHP enums, never in the ext.
