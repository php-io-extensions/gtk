---
type: Trap
title: REGISTER_CLASS truncation
description: Zephir 0.19 may emit Gtk\\GT\\* — fixup script rewrites to Gtk\\GTK\\*. Zephir 0.20 may omit the inner gtk_ prefix on the CE name argument.
tags: [gtk, trap]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T21:10:00Z" }
---

Always run `scripts/fixup-zephir-register.py` via `prepare-ext.sh` after `zephir generate`.

Zephir 0.20 `ZEPHIR_REGISTER_CLASS` uses `lower_ns=gtk` (config.json namespace). Declared `zend_class_entry` symbols are `gtk_gtk_*_ce`. If the 4th argument is `button_gtkbutton` instead of `gtk_button_gtkbutton`, gcc reports `gtk_button_gtkbutton_ce` undeclared. The fixup prepends `gtk_` when missing.
