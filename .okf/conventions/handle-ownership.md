---
type: Convention
title: Handle ownership
description: Create/destroy GObject ints; PHP GC does not free natives
tags: [gtk, convention]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

| Object | Create | Destroy |
| ------ | ------ | ------- |
| Application | `gtkApplicationNew` | `gObjectUnref` |
| Window | `gtkWindowNew` / `gtkApplicationWindowNew` | `gtkWindowDestroy` and/or unref |
| Button / Box / GLArea | `gtk*New*` | unref (or destroy with parent window) |

Do not destroy `0`. After failure, read `GtkError::gtkLastMessage()`.
