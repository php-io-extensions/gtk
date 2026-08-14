---
type: Trap
title: Do not Vulkan on the GtkWindow XID
description: WSI attaches to gtk_gpu_pane native child, never the GdkSurface
tags: [gtk, trap, vulkan, x11]
status: draft
generated: { by: cursor-agent/grok-4.6, at: "2026-08-14T02:10:00Z" }
---

A GTK child widget has no `GdkSurface`. Creating `VkSurfaceKHR` on the window’s `wl_surface` / X11 window fights GSK.

Use `gtk_gpu_pane_new` as the window child. `gtk_gpu_pane_native` yields `Display*` + the pane’s X11 window (override-redirect, root-positioned over the allocation). Do not parent that window under the redirected `GdkSurface` XID — GSK wins and you see white.

`realize` can fire at 0×0. Do not `gtk_application_quit` when native is empty; wait for `map` / size. `GDK_BACKEND=x11` `DISPLAY=:0`. `G_APPLICATION_NON_UNIQUE` (32) if a previous GtkApplication with the same id is still alive.
