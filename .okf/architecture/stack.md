---
type: Architecture
title: Layered stack
description: PHP → Zephir → GTK4 C → libgtk-4
tags: [gtk, architecture]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

```text
PHP app
  └─ Gtk\GTK\* static methods
       └─ Zephir inline C
            └─ libgtk-4 (GLib / GObject)
```

`g_application_run` is the in-process Application run loop. Same PHP PID.
