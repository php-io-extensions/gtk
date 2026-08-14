---
type: Playbook
title: Headless + window proofs
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`php examples/proof_of_work.php` — version only.

`php examples/proof_window.php` — needs `WAYLAND_DISPLAY` or `DISPLAY`. Same unix user as the desktop seat.

`DISPLAY=:0 GDK_BACKEND=x11 php examples/proof_vulkan_x11.php` — GTK gpu pane + ext-vulkan Xlib surface. glfw must not be loaded.
