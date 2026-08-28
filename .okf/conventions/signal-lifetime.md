---
type: Convention
title: Signal connection lifetime
description: Who owns a PHP callable connected to a GObject signal, and why a caller owes no cleanup after destroying the object.
tags: [conventions, signals, lifetime, gobject, memory]
status: stable
generated: { by: claude-code/opus-5, at: 2026-08-25T00:00:00Z }
sources:
  - id: connect-impl
    resource: "../../src/gtk-glib-api.c"
    title: php_gtk_signal_connect
  - id: closure-impl
    resource: "../../src/gtk-support.c"
    title: php_gtk_closure_new / php_gtk_closure_finalize
---

# Ownership chain

```
GObject  ──owns──▶  GClosure  ──owns──▶  PHP callable (ZVAL_COPY)
```

`php_gtk_closure_new()` takes a strong zval ref on the callable.[^closure-impl] `g_signal_connect_closure_by_id()` hands the closure to the object.[^connect-impl]

Break the chain at the top and the whole thing unwinds: finalizing the object disconnects its handlers, drops the closures, the finalize notifier runs `zval_ptr_dtor`, the callable is released.

# What that buys the caller

`gtkWidgetUnparent()` finalizes the widget and its subtree, so it also releases every callable connected anywhere in that subtree. **No cleanup owed, nothing dangling.** Disconnect is only for silencing a handler on an object that lives on — never a teardown obligation.

Verified on hardware: callables held by connected handlers, released on unparent, released on subtree unparent, released on explicit disconnect. Object with `__destruct` used as the tracer.

No cycle exists to leak through, because handles are plain `int`. A PHP object captured by a handler can hold the widget's handle without keeping the widget alive.

The handler id is only valid while the object is. Disconnecting through a dead handle is the same mistake as any other use of one — see the removal contract in `php_gtk_widget_unparent`.

# Any GObject, any detail

Instance is `gpointer`, not `GtkWidget*`. Widgets, `GtkApplication`, `GSimpleAction`, `GMenu` all connect the same way. Confirmed for each.

Detailed names work: `"notify::sensitive"` fires only for that property, bare `"notify"` for every property.

# Bad names fail loudly

GLib's own path reports an unknown signal by writing a warning to stderr — invisible to a PHP caller. So the name is parsed first with `g_signal_parse_name()` and failures come back as `0` plus `gtkLastMessage()`.[^connect-impl]

A `notify` detail gets one further check, because GLib accepts a bogus one and the handler then simply never fires:

* property does not exist → rejected
* property exists but spelled with underscores → rejected, message gives the dashed name

The underscore case is the nasty one. `notify::use_markup` names a real property, and the detail quark is the pspec's dashed name, so it connects and stays silent forever.

[^connect-impl]: src/gtk-glib-api.c, php_gtk_signal_connect
[^closure-impl]: src/gtk-support.c, php_gtk_closure_new / php_gtk_closure_finalize
