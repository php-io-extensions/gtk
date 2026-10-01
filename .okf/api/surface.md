---
type: API
title: Binding surface
description: Functions, classes, enums and constants ext-gtk binds, each one GTK, GIO or GLib call.
resource: stubs/
tags: [gtk, glib, gio, api]
status: draft
generated: { by: claude-opus/5.5, at: 2026-10-01T18:07:32Z }
sources:
  - id: stubs
    resource: stubs/
    title: Stub files, one per type
  - id: headers
    resource: /usr/include/glib-2.0/gio/gioenums.h
    title: GIO enums (GApplicationFlags)
---

# Overview

Scope: calls that initialise GTK, register the app with the desktop, hold/release it, pump the default main context, sleep with a budget, wake a sleep, open/close windows, build menu bars from GMenu models and GSimpleAction groups. Stubs = source of truth; `tests/SurfaceTest.php` fails if a stub declaration is missing from the build.[^stubs]

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
| `GApplication` | `id_is_valid` (static), `get_application_id`, `get_flags`, `get_is_registered`, `get_is_remote`, `register`, `activate`, `hold`, `release`, `quit`, `run(array $argv)`; GActionMap add/remove/lookup (lookup `?GObject`: GTK may add non-simple actions); GActionGroup has/list/activate |
| `GtkApplication::new(?string, GApplicationFlags\|int)` | `gtk_application_new` |
| `GtkWidget` | show/hide/set_visible, get_visible, get_realized, get_mapped, hexpand/vexpand, get_parent, insert_action_group (any GActionGroup), activate_action (variant form) |
| `GtkWindow` | new (transfer none: GTK keeps the toplevel), title, default size (`[w, h]`), child, present, close, destroy, is_active, transient_for, application, modal, hide_on_close |
| `GtkApplicationWindow` | new(app) — the application is a declared-optional, runtime-required parameter because PHP holds static methods to the parent's signature; show_menubar; get_id |
| `GtkAboutDialog` | new; program name, version, copyright, comments, website |
| `GtkBox`, `GtkPopoverMenuBar` | new(orientation, spacing), append/prepend/remove; new_from_model, menu model |
| `GMenuModel`, `GMenu`, `GMenuItem` | n_items, is_mutable; append/append_item/append_section/append_submenu/prepend/insert/remove/remove_all/freeze; label, detailed action, action+target, attribute values (`accel` etc.), submenu, section |
| `GSimpleAction` | new(name, ?type), new_stateful(name, ?type, state), enabled, state, name, activate, change_state; signals `activate` (`?GVariant`), `change-state` (`GVariant`) |
| `GSimpleActionGroup` | new; GActionMap add/remove/lookup; GActionGroup has/list/activate |
| `GVariant` | new_boolean/string/int32/double, typed getters, type string, is_of_type, print |
| `GtkApplication` (windows) | add/remove_window, get_active_window, get_windows, menubar, accels for action |
| `GMainContext` | `default`, `get_thread_default`, `iteration`, `pending`, `wakeup`, `acquire`, `release`, `is_owner`; `pointer()` |

Validation: action names, detailed action names, GVariant type strings, parameter/state types and accelerators are checked before the call; GLib would otherwise log a critical and do nothing. Typed GVariant getters refuse a mismatched variant with GtkException.

Signal parameter marshalling: objects/interfaces boxed; GVariant boxed; bool, ints, floats, strings as PHP scalars; enums/flags as int; pointers and boxed types as addresses. Return values set back into the signal's typed return GValue.

Behaviour confirmed on both platforms: `register()` emits `startup`, which initialises GTK. `run()` ends with shutdown, after which the app is unregistered. macOS: GTK's backend makes the process a regular app on startup (Dock icon); GTK has no call to withdraw it. Linux: registration owns the app id on the session bus; the taskbar lists windows, not processes.

[^stubs]: Stub files, one per type
[^headers]: GIO enums (GApplicationFlags)
