---
type: Trap
title: GtkFixed child positions only exist in allocated coordinates
description: gtk_fixed_get_child_position rides gtk_widget_compute_point, so it returns {0,0} before allocation and a theme-offset position after — compare deltas, never absolutes.
tags: [trap, gtkfixed, layout, gtk4]
status: draft
generated: { by: claude-fable-5/cursor, at: 2026-08-28T07:00:00Z }
sources:
  - id: fixed
    resource: "../../src/gtk-fixed.c"
    title: phpgtk_gtkfixed_get_child_position
---

Measured on GTK 4.18.6 (Pi 5 seat, default theme), not inferred. Found while
writing `examples/wave_a.php`: an exact-value assertion on
`GtkFixed::getChildPosition` failed and turned out to be right about GTK and
wrong about the test — the binding is a clean 1:1 forward.

# The behaviour

`gtk_fixed_get_child_position()` does not read back the translate transform
that `gtk_fixed_put()`/`gtk_fixed_move()` stored. Since GTK 4.10 it computes
the child's origin in the fixed's coordinate space via
`gtk_widget_compute_point()`, which means:

1. **Before the fixed is allocated** (not yet mapped, or no layout pass has
   run) it answers `{0, 0}` regardless of what `put`/`move` set.
2. **After allocation** it answers the set position **plus a constant
   theme-dependent offset**. On the Pi seat with a `GtkToggleButton` child
   the offset measured `{+10, +5}` for every position tried:

   ```
   put(12, 6)                → {22, 11}
   put(100, 50); move(30,40) → {40, 45}
   move(3, 4) after map      → {13, 9}
   ```
3. A `move()` after mapping does not take effect until the next layout pass —
   pump the loop before reading.
4. The offset is not one universal constant: a deeply nested fixed (inside an
   overlay inside a grid) measured `{+17, +5}` where the bare-window probe
   measured `{+10, +5}`. It is only constant across readings of the same
   child in the same scene.
5. "Window is visible" does not mean deep descendants are allocated —
   `GtkWindow::present` plus a pump can still leave a nested fixed answering
   `{0, 0}`. Pump until the first reading is non-zero before taking a
   baseline.

# What to assert

The offset is constant per child, so **deltas between two readings of the
same child are exact**. Assert `pos_after - pos_before == move delta` after
mapping and pumping, never absolute coordinates and never before the widget
is allocated. `examples/wave_a.php` (`FIXED_OK`) is the worked example.
