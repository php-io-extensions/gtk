---
type: API
title: Gtk\\GTK\\GtkGLib
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`gObjectRef(instance)`, `gObjectUnref(instance)`, `gSignalConnect(instance, signal, callable)`.

`gSignalConnect` is a GClosure marshaler: all signal `GValue` parameters are passed to PHP; the PHP return is written back into GObject’s `return_value`. `GtkGLArea` `render` handlers must `return true`. Parameter name is `instance` not `object` (Zephir reserved type).
