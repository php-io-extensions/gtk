---
type: Architecture
title: Zephir inline C
description: Opaque ints, last-error buffer, g_signal_connect bridge
tags: [gtk, architecture, zephir]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

Handles are `(zend_long)(uintptr_t)` GObject pointers. `0` is NULL.

`php_gtk_last_error` / `php_gtk_set_last_error` / `php_gtk_closure_new` / `php_gtk_closure_marshal` live in `gtk.zep` (not `static`) so other TUs can link. `GtkError` reads the buffer.

`gSignalConnect` lives on `Gtk\\GTK\\GtkGLib` (not `GtkGObject` / `Gtk\\GTK\\GObject` — Zephir 0.19 syntax-errors that). Do not mention `GObject` in `gtkglib.zep` file-level `%{ %}` externs. Do not name a Zephir parameter `object` (reserved type).

Zephir 0.20 string params are `zval name`, not `zval *`. Use `Z_STRVAL(name)` then `return result` after `ZVAL_STRING(&result, ...)`. CamelCase params stay camelCase in C (`autoRender`, `applicationId`).

`gSignalConnect` builds a `GClosure` (`php_gtk_closure_new`) and uses `g_signal_connect_closure`. The marshaler converts each `GValue` param to PHP (objects/pointers as `int` handles) and writes the PHP return into GObject’s `return_value` (`G_TYPE_BOOLEAN` via `zend_is_true`). That is what `GtkGLArea::render` needs: PHP `return true` becomes `TRUE` so GTK does not paint the CSS background over `glClear`. Void signals (`activate`, `clicked`) have a NULL `return_value` and stay unchanged. Not a full GObject IDL compiler — boxed types without a holder become `0`.
