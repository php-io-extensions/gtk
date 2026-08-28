---
type: Component
title: Gtk\Bridge\Bridge — the only glue
description: >-
  Everything PHP cannot do without native code, and nothing else: handle
  registry, main-loop pump, signal connect with return writeback, property
  fallback.
resource: src/phpgtk-bridge.c
tags: [bridge, glue, gtk4, signals]
status: draft
generated:
  by: cursor-grok-4.6/cursor
  at: 2026-08-28T07:15:00Z
---

# Gtk\Bridge\Bridge

Everything in `src/phpgtk-bridge.{h,c}` exists because PHP cannot be a
GObject: it cannot hold a reference, receive a signal, or drive the GLib
main loop. Nothing here decides anything about how GTK is used. **No other
`PhpGtk*` machinery may exist** outside `phpgtk-bridge.c` and
`phpgtk-support.c`.

## Surface

- `init(): bool` — `gtk_init_check()` exactly once; later calls return the
  first result. Bindings never auto-init.
- Handle registry: `retain(handle)`, `release(handle)`, `isValid(handle)`,
  `typeName(handle)`, `isA(handle, typeName)`, `typeFromName(typeName)`.
  `typeFromName` is 1:1 with `g_type_from_name` and returns 0 when the name
  is unknown or not yet registered — glue-adjacent like `isA`, used by
  `GListStore::new` to obtain a `GType`. A `GHashTable` keyed by
  pointer; registration `g_object_ref_sink`s (adopting the floating ref a
  `gtk_*_new()` returns, plain-reffing everything else), removal drops the
  registry's ref via the table's value-destroy. Handles are the object's
  pointer as int; 0 = NULL; **a stale or fabricated int resolves to NULL,
  never a dangling deref** — this fixes dep-gtk's worst bug, where handles
  were raw pointer casts. Every binding resolves through `PHPGTK_RESOLVE`.
- `pump(timeoutMs): int` — iterate the default `GMainContext` without
  blocking until empty; if nothing dispatched and `timeoutMs > 0`, plant a
  `g_timeout_add` wake source and block for the first real source, then
  drain. Returns dispatch count. PHP drives the loop — never
  `g_application_run()`, and `g_application_register` stays reserved
  (see the remote-instance segfault in
  [traps/control-signal-surprises.md](/traps/control-signal-surprises.md)).
- `connect(handle, signal, callable): int` / `disconnect(handle, handlerId)`
  — salvaged dep-gtk validation: the name is parsed first with
  `g_signal_parse_name` (GLib's own failure path only warns on stderr), and
  a `notify::` detail is checked against the object's properties, including
  the underscore-vs-dash case where GLib silently connects a handler that
  never fires. The closure (`PhpGtkClosure` in `phpgtk-support.c`) marshals
  GValues both ways **with return-value writeback**, so a
  `GtkWindow::close-request` handler can return true to veto the close.
  Signal parameters that are GObjects are registered on the way in, so a
  handler receives handles it can pass straight back into bindings.
  `disconnect` checks `g_signal_handler_is_connected` first so a bogus id
  cannot make GLib warn.
- `getProperty(handle, name)` / `setProperty(handle, name, value)` —
  `g_object_get/set_property` for properties reserved as
  `property "x"` (no C accessors). The setter refuses non-writable and
  construct-only properties, and converts by the pspec's fundamental type
  (bool/int/uint/int64/uint64/float/double/enum/flags/string/object-handle).

## Ownership (signals)

```
GObject ──owns──▶ GClosure ──owns──▶ PHP callable (ZVAL_COPY)
```

Finalizing the object disconnects its handlers and releases the callables —
a caller owes no cleanup. Full chain and hardware verification in
[conventions/signal-lifetime.md](/conventions/signal-lifetime.md). No cycle
can leak because handles are plain ints.

## Errors

No side channel. dep-gtk kept a process-global `php_gtk_last_error[256]`,
which is a data race under ZTS; it was deleted in the salvage. Fallible
Bridge calls raise `E_WARNING` with the diagnostic (catchable via a PHP
error handler) and return 0/null.

## ZTS note

PHP on the Pi build box is ZTS, and the extension declares
`support-zts: true`. The remaining process globals are the registry table
and the init flag — the binding assumes **one PHP thread talks to GTK**,
which is the CLI process model it targets (same stance as appkit). Do not
call into GTK from parallel threads.
