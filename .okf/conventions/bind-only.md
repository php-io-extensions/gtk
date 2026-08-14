---
type: Convention
title: Bind only
description: Extension wraps C functions; no application orchestration
tags: [gtk, convention]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

Each public method maps to one (or a trivial pair of) C calls. No window policy, no scene tree, no “open a workshop.” `g_application_run` blocking is the library, not orchestration we invented.
