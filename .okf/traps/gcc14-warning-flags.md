---
type: Trap
title: GCC 14 warning flags
description: config.m4 demotes Zephir C warnings
tags: [gtk, trap]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`patch-config-m4.py` writes `-Wno-error=incompatible-pointer-types` and related flags. Preserve them across regenerations.
