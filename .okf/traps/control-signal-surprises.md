---
type: Trap
title: GTK4 control behaviour that is not what it looks like
description: GTK4 behaviours across the control, container and media bindings that look like binding bugs and are not, plus the two crashes they turned up.
tags: [trap, signals, gtk4, controls, entry, dropdown]
status: stable
generated: { by: claude-code/opus-5, at: 2026-08-25T00:00:00Z }
sources:
  - id: entry
    resource: "../../src/gtk-entry-api.c"
    title: php_gtk_entry_set_text
  - id: dropdown
    resource: "../../src/gtk-dropdown-api.c"
    title: php_gtk_drop_down_set_selected
---

All five measured on GTK 4.18.6, not inferred. Each one first showed up as a failing assertion that turned out to be right about GTK and wrong about the test.

# "changed" fires twice per set_text

`gtk_editable_set_text()` is a delete-all followed by an insert, and both halves emit.[^entry] A handler reading the entry sees `""` on the first of the pair:

```
set_text("one"); set_text("two")   ->   "", "one", "", "two"
```

Consequences: a `changed` handler that writes back into its own entry recurses; one that mirrors the entry elsewhere blanks the mirror on every keystroke-shaped write. Compare before writing.

An identical set still emits — the buffer is churned regardless of the value.

# A non-empty dropdown always keeps a selection

`GtkDropDown` wraps its model in a `GtkSingleSelection` with autoselect on. Asking for no selection puts the previous item straight back, so `set_selected(-1)` only clears an empty list.[^dropdown] The binding reports the refusal rather than letting the caller believe the selection cleared. `get_selected()` still returns -1 for a genuinely empty model.

# GtkProgressBar notifies "fraction" unconditionally

Every `set_fraction()` emits `notify::fraction`, same value or not. So notify counts prove the call landed and say nothing about what it landed on. There is no fraction getter in this surface; the clamp is verified by GTK raising no assertion, with a deliberate-warning control proving the detector works.

# A switch has no "toggled"

`GtkSwitch` carries no `toggled`. Watch `notify::active`. (`state-set` exists, but it is for vetoing a change, not observing one.) The connect guard refuses `toggled` on a switch outright, which is how this was pinned down.

# A radio group fires "toggled" twice per change

Selecting a different member of a group emits on the one going off as well as the one coming on. A three-button group therefore reports two events for one user action.

# GtkDropDown does not size to its content

Its width comes from the list-item factory, not the longest row, so swapping in longer strings does not widen it. Do not use `gtkWidgetMeasure()` to prove a model was installed — count rows through selectable indices instead.

[^entry]: src/gtk-entry-api.c, php_gtk_entry_set_text
[^dropdown]: src/gtk-dropdown-api.c, php_gtk_drop_down_set_selected

# gtk_widget_activate is not performClick:

Measured, GTK 4.18.6. Return value says only that the class has an activation, not that anything happened.

| widget | returns | what actually happens |
| --- | --- | --- |
| GtkCheckButton | true | toggles synchronously, realized or not |
| GtkButton | true | "clicked" comes from a ~250ms press animation: **needs realization**, arrives on a later main-loop turn |
| GtkSwitch | true | same as button |
| GtkEntry | **false** | no activation at the widget-class level -- editing lives in an internal GtkText child. "activate" is unreachable from PHP |
| label, box, fixed | false | nothing to activate |

Unrealized button reports `true` and then never fires. That combination is the trap: the call looks like it worked.

**Insensitivity does not gate it.** Activation emits the class signal directly and never reads the sensitive flag, so a greyed-out button still clicks. Real input does not, and neither does AppKit. Gate it in PHP.

# g_application_register true does not mean you own the id

Segfault, found while probing activation. Another process holding the application id -- a second copy, or an earlier one hung on the bus -- makes GLib register this one as a *remote* instance and return success. A remote instance has no window machinery, and `gtk_application_window_new()` dereferenced past it.

Fixed both ends: register now reports false for a remote instance, and window creation refuses one.[^register] Test at `tests/remote-instance.php` forks its own holder rather than depending on a stray process.

Practical consequence: **give every process a distinct application id, or expect the second one to fail.** Test harnesses that hardcode one break as soon as a run is left hanging.

[^register]: src/gtk-glib-api.c, php_gtk_application_register

# Wave 3: a popover's parent owns it

`gtk_widget_set_parent()` aborts on a widget that already has a parent, so moving a popover to another anchor has to detach first. A plain `gtk_widget_unparent()` there **finalizes it** -- the anchor holds the only reference -- and the `set_parent` that follows runs on freed memory:

```
GLib-GObject-CRITICAL: invalid unclassed pointer in cast to 'GtkWidget'
Gtk-CRITICAL: gtk_widget_set_parent: assertion 'GTK_IS_WIDGET (widget)' failed
```

Fixed by holding a reference across the swap.[^popover] The reference is balanced inside the call, so the removal contract is untouched: removal is still terminal and still owes the caller no unref. This is a move, not a removal.

# GtkPicture can-shrink is a trap in both directions

Turning `can-shrink` off pins the widget's *minimum* to the image size, which also makes `gtk_widget_set_size_request()` unable to size a picture **down**. Measured: a 600x400 image asked for 100x80 was still allocated 600x400.

Natural size is the image's pixel size either way, so leaving it at GTK's default costs nothing and keeps the driver's only framing tool working.

# GtkPicture's filename constructor cannot fail

`gtk_picture_new_for_filename()` returns a perfectly good widget for a path that does not exist. It just draws nothing. Loading through `gdk_texture_new_from_filename()` first is what makes a handle of `0` mean "this did not load".[^picture]

# content-fit "contain" is already the default

Which makes it useless as the first step of a distinctness check: setting it changes nothing and `notify::content-fit` stays quiet. Prime with a different value first, and keep a repeated-set control to prove the property does not notify unconditionally.

# GtkEntry is not the only widget with an inner one

A text area's handle is the `GtkScrolledWindow`; CSS and sensitivity applied to it do not reach the text. `gtk_text_inner()` exists for that, and returns 0 for a scrolled window that is not a text area, so a plain scroll cannot be mistaken for one.

[^popover]: src/gtk-popover-api.c, php_gtk_popover_attach
[^picture]: src/gtk-picture-api.c, php_gtk_texture_from_path
