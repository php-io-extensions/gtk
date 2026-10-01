---
type: Module
title: Object model
description: One PHP object per GObject or GMainContext, referenced while PHP holds it, boxed as its nearest bound GType.
resource: src/runtime.c
tags: [gtk, zend, lifetime]
status: draft
generated: { by: claude-opus/5.5, at: 2026-09-30T20:52:04Z }
sources:
  - id: runtime
    resource: src/runtime.c
    title: Boxing, handlers
---

# Overview

One struct: `phpgtk_object { void *ptr; phpgtk_kind kind; zend_object std; }`. Kind picks the reference functions: GObject → `g_object_ref_sink` on box (sinks a floating ref, so widgets later box the same way), `g_object_unref` on free; GMainContext → `g_main_context_ref/unref`.[^runtime]

Identity: module global `boxes` maps native address → `zend_object*` (no refcount); the same native object always yields the same PHP object. Persistent per thread (GINIT/GSHUTDOWN).

Class choice: walk `G_OBJECT_TYPE` → `g_type_parent`; first GType name registered with `phpgtk_map_gtype()` wins; fallback `GObject`.

Constructors (`GtkApplication::new`) box the new object, then drop the creation reference: PHP's own reference is the only one left.

Wrappers are not constructible, not cloneable, not serializable; identity is `===`.

[^runtime]: Boxing, handlers
