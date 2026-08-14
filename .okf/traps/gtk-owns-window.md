---
type: Trap
title: GTK owns the window
description: Do not call SDL/GLFW createWindow from a GTK app path
tags: [gtk, trap]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`gtk_application_window_new` / `gtk_window_new` create the WM surface. Hybrid GPU uses `gtk_gl_area_new` as a child. SDL/GLFW `createWindow` steals ownership.
