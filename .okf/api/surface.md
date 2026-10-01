---
type: API
title: Binding surface
description: Functions, classes, enums and constants ext-gtk binds, each one GTK, GIO or GLib call.
resource: stubs/
tags: [gtk, glib, gio, api]
status: draft
generated: { by: claude-opus/5.5, at: 2026-09-30T20:52:04Z }
sources:
  - id: stubs
    resource: stubs/
    title: Stub files, one per type
  - id: headers
    resource: /usr/include/glib-2.0/gio/gioenums.h
    title: GIO enums (GApplicationFlags)
---

# Overview

Scope: calls that initialise GTK, register the app with the desktop, hold/release it, pump the default main context, sleep with a budget, wake a sleep. Stubs = source of truth; `tests/SurfaceTest.php` fails if a stub declaration is missing from the build.[^stubs]

Naming, all fixed:

* Function on no type = global function, C name (`g_timeout_add`, `g_signal_connect`, `gtk_init`).
* `<prefix>_<type>_<verb>(Type *self, …)` = method on the class named after the type, verb camelCased: `g_application_get_is_registered(app)` → `$app->getIsRegistered()`, `g_main_context_default()` → `GMainContext::default()`.
* `*_new` = static `new()` (`GtkApplication::new()`); wrappers are never built with `new`.
* GEnum/GFlags = backed int enum, prefix dropped (`GApplicationFlags::NON_UNIQUE`). Flags params = `Enum|int` (OR ints).[^headers]
* `GError **` out-param = thrown `GError` exception; the function's own return stays.
* Callback + user_data + GDestroyNotify = one PHP callable param.

# Schema

| Binding | Native |
|---|---|
| `gtk_init()`, `gtk_init_check()`, `gtk_is_initialized()`, `gtk_get_{major,minor,micro}_version()` | same |
| `g_timeout_add(int $interval, callable $function): int` | `g_timeout_add_full` (default priority); callable returns bool = keep |
| `g_idle_add(callable): int` | `g_idle_add_full` (default idle priority) |
| `g_unix_fd_add(int\|resource\|Socket $fd, GIOCondition\|int, callable(int $fd, int $condition): bool): int` | `g_unix_fd_add_full` |
| `g_source_remove(int): bool` | same; false for an id no longer in the default context |
| `g_signal_connect(GObject, string, callable): int` | `g_signal_connect_closure_by_id`; handler gets the signal's params, instance first |
| `g_signal_handler_disconnect`, `g_signal_handler_is_connected` | same |
| `GObject::typeName()`, `pointer()` | `G_OBJECT_TYPE_NAME`, address |
| `GApplication` | `id_is_valid` (static), `get_application_id`, `get_flags`, `get_is_registered`, `get_is_remote`, `register`, `activate`, `hold`, `release`, `quit`, `run(array $argv)` |
| `GtkApplication::new(?string, GApplicationFlags\|int)` | `gtk_application_new` |
| `GMainContext` | `default`, `get_thread_default`, `iteration`, `pending`, `wakeup`, `acquire`, `release`, `is_owner`; `pointer()` |

Signal parameter marshalling: objects/interfaces boxed; bool, ints, floats, strings as PHP scalars; enums/flags as int; pointers and boxed types as addresses. Return values set back into the signal's typed return GValue.

Behaviour confirmed on both platforms: `register()` emits `startup`, which initialises GTK. `run()` ends with shutdown, after which the app is unregistered. macOS: GTK's backend makes the process a regular app on startup (Dock icon); GTK has no call to withdraw it. Linux: registration owns the app id on the session bus; the taskbar lists windows, not processes.

[^stubs]: Stub files, one per type
[^headers]: GIO enums (GApplicationFlags)
