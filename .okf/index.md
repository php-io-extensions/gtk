---
okf_version: "0.2"
---

# gtk — knowledge bundle

Faithful 1:1 Zephir binding of GTK4 into PHP. Read this index first, then
open only the concepts the task needs.

- [binding-rules.md](/binding-rules.md) — the spec every class binding follows
  (types, naming, reserved members, the one-call-one-native-call rule, the
  gir audit).
- [bridge.md](/bridge.md) — the only glue in the extension: handle registry,
  main-loop pump, signal connect/disconnect, property fallback.
- [toolchain.md](/toolchain.md) — the generate → parity → prepare → Pi build
  pipeline and its guards, including the Mac/Pi split.
- [traps/control-signal-surprises.md](/traps/control-signal-surprises.md) —
  measured GTK 4.18.6 behaviour that looks like binding bugs and is not
  (copied verbatim from dep-gtk; source paths reference that repo).
- [traps/fixed-child-position.md](/traps/fixed-child-position.md) —
  `gtk_fixed_get_child_position` answers in allocated coordinates: {0,0}
  before allocation, theme-offset after; assert move deltas only.
- [conventions/signal-lifetime.md](/conventions/signal-lifetime.md) — who owns
  a PHP callable connected to a signal (copied verbatim from dep-gtk; the
  `gtkLastMessage()` error channel it mentions was deliberately not carried
  over — failures now raise E_WARNING).
