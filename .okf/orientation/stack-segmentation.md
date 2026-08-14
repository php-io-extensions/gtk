---
type: Orientation
title: Stack segmentation
description: ext-gtk vs sdl3, glfw, metal, tubes, future microscrap/gtk
tags: [gtk, orientation, boundaries]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

# Who owns what

| Concern | Package |
| -------- | ------- |
| Native GTK4 C API in PHP | **php-io-extensions/gtk** (this package) |
| Typed PHP / enums | future `microscrap/gtk` |
| Toolkit host / app chrome | future Scrapyard companion — not this ext |
| GPU in a GTK hole | `GtkGLArea` handle here; `-gfx` attaches later |
| Exclusive GPU window | `php-io-extensions/sdl3` or `glfw` |
| Darwin toolkit | `php-io-extensions/metal` |

# Hard rules

1. Do not document microscrap or tubes APIs in this OKF.
2. Do not add sdl3/glfw/metal as Composer deps.
3. Do not nest `.okf` under `gtk/gtk/`.
4. Keep Windows out of PIE.
