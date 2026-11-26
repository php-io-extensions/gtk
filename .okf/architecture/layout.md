---
type: Module
title: Layout and styling
description: GtkBox, GtkGrid and GtkFixed containers; alignment, expansion, size requests and margins on every widget; CSS classes and providers per display; GdkSurface size and layout signal.
resource: src/GtkWidget.c
tags: [gtk, layout, css]
status: draft
generated: { by: claude-opus/5.5, at: 2026-11-26T05:00:00Z }
sources:
  - id: widget
    resource: src/GtkWidget.c
    title: GtkWidget, GtkBox, GtkGrid, GtkFixed bindings
  - id: css
    resource: src/GtkCss.c
    title: GtkCssProvider, GdkDisplay, style context functions
  - id: surface
    resource: src/GdkSurface.c
    title: GdkSurface
---

# Overview

GTK owns geometry; PHP only states intent. Three containers: `GtkBox` (one axis, `append`/`prepend`/`insert_child_after`/`reorder_child_after`, spacing, homogeneous), `GtkGrid` (`attach(child, column, row, width, height)`; GTK criticals a width or height below 1), `GtkFixed` (`put`/`move` at float coordinates; the position reads back once the fixed has been allocated, since GTK stores it as a layout-child transform applied at allocate).[^widget]

Per widget: `halign`/`valign` (`GtkAlign`), `hexpand`/`vexpand`, `set_size_request` (minimum; `get_size_request` returns `[w, h]`, -1 = unset), `get_width`/`get_height` (allocated), margins, `measure(orientation, for_size)` (minimum/natural plus baselines), `sensitive`. Removal goes through the container's own `remove` or `setChild(null)`; `gtk_widget_unparent` is not bound (widget-implementation API; a window's child pointer would dangle after it).

Constraint layout: `setLayoutManager(GtkConstraintLayout::new())` replaces a widget's own layout (a box's GtkBoxLayout; `getLayoutManager()` keeps it to put back). Constraints tie a child (or a `GtkConstraintGuide`) to the widget (null) or another target; a guide carries a natural and a maximum size the solver weighs. GTK solves a constraint layout only under a root: measured unrooted it answers 0, measured once the widget is in a window (shown or not) it answers the solved size. A size request stays a floor, and nothing else in GTK 4.24 sets a ceiling: a picture whose width and height equal a guide's, with the guide's maximum at a cap and its natural at the picture's own size, measures and lays out at the cap (`tests/ConstraintLayoutTest.php`: an 84 px picture under 22 is 22 by 22 in a window; under 96 it stays 84). The guide's maximum, not its natural, answers height-for-width there, so a maximum above the picture's own size enlarges it: keep the maximum at most the natural size.

Styling: `add/remove/has_css_class` on a widget; `GtkCssProvider::new()` + `load_from_string(css)`; `gtk_style_context_add_provider_for_display(GdkDisplay::getDefault(), provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION)` installs it for every window on that display, `remove_provider_for_display` takes it out.[^css]

Window size: `GtkNative::getSurface()` (windows and popovers) answers the `GdkSurface` once realized, null before. Plain widgets have no surface: `getNative()` walks up to theirs. `get_width`/`get_height` read the surface; signal `layout(int width, int height)` fires on each size change. `get_native`/`get_root` walk up to the window.[^surface]

[^widget]: GtkWidget, GtkBox, GtkGrid, GtkFixed bindings
[^css]: GtkCssProvider, GdkDisplay, style context functions
[^surface]: GdkSurface
