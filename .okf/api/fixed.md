---
type: API
title: Gtk\\GTK\\Fixed\\GtkFixed
status: draft
generated: { by: cursor-agent/grok-4.6, at: "2026-08-16T16:50:00Z" }
---

`gtkFixedNew()`, `gtkFixedPut(fixed, child, x, y)`, `gtkFixedMove`, `gtkFixedRemove`, `gtkFixedGetChildPosition` → `["x" => int, "y" => int]`.

GTK4 `put`/`move` take `double`; this bind takes PHP `int` and casts. Child width/height is `GtkWidget::gtkWidgetSetSizeRequest`, not on Fixed.

Multiple children. A child may be `GtkGLArea` / `GtkGpuPane`. Positions do not reflow on window resize.
