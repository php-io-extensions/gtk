---
type: Trap
title: GtkGLArea render must return true
description: PHP render handlers must return true so GTK does not overpaint glClear
tags: [gtk, trap, glarea, render, signal]
status: draft
generated: { by: cursor-agent/grok-4.6, at: "2026-08-14T01:50:00Z" }
---

# Rule

`GtkGLArea::render` is `gboolean`. If the handler returns `FALSE`, GTK paints the CSS background over whatever you `glClear`’d.

`gSignalConnect` uses a GClosure marshaler that copies the PHP return into GObject’s `return_value`. A void PHP function leaves the boolean at the GValue default (`FALSE`).

```php
g_signal_connect($area, 'render', static function (int $area, int $context): bool {
    // draw
    return true;
});
```
