---
type: Convention
title: Constants outside the extension
description: No PHP class constants; GTK flags live in app or microscrap enums
tags: [gtk, convention]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

Examples may use `const G_APPLICATION_DEFAULT_FLAGS = 0` and `GTK_ORIENTATION_*`. Prefer int-backed PHP Enums with FULLY UPPERCASE cases in microscrap — not class constants in this extension.
