---
type: API
title: Gtk\\GTK\\GpuPane\\GtkGpuPane
status: draft
generated: { by: cursor-agent/grok-4.6, at: "2026-08-14T02:10:00Z" }
---

Not a GTK-shipped `GtkVulkanArea`. Hosts a **dedicated X11 window** aligned to the widget allocation (override-redirect on the root). A child of the `GdkSurface` XID is invisible: GTK4 redirects that surface and GSK paints the CSS background (white) over it. Does **not** link libvulkan.

| Method | C ABI | Notes |
|--------|-------|--------|
| `gtkGpuPaneNew()` | `gtk_gpu_pane_new` | Drawing area + X11 child after realize |
| `gtkGpuPaneNative($pane)` | `gtk_gpu_pane_native` | `array{backend, display, window}` — X11: `Display*` and `Window` as ints |

`backend` is `"x11"` when the child exists; otherwise `""` and both ints are `0`. Wayland subsurface is out of scope.

Do not `vkCreate*` on the `GtkWindow` / `GdkSurface` XID — that fights GSK.
