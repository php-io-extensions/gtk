---
type: Build
title: Committed ext/ notes
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

After Linux `scripts/prepare-ext.sh`, commit generated `ext/` C + `config.m4` + `kernel/` + `gtk/gtk/**/*.zep.c`. phpize junk (`Makefile`, `configure`, `modules/`, `*.lo`, `*.o`, `*.so`, `.libs/`) is gitignored and stripped by prepare-ext. Version **0.7.0** in composer.json / config.json. PIE `type: php-ext` `build-path: ext`. GTK4 ≥ **4.10.0** (`config.m4` / `config.json`). Do not compile on macOS.
