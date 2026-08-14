---
type: API
title: Gtk\\GTK\\GLArea\\GtkGLArea
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`gtkGLAreaNew`, `MakeCurrent`, `QueueRender`, `SetAutoRender`, `GetError`. Does not create a top-level window.

Connect `render` with `gSignalConnect`. The handler receives `(int $area, int $context)` and **must `return true`**. A missing/false return lets GTK paint the CSS background over `glClear`.
