---
type: Build
title: Zephir + Linux install
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

`scripts/prepare-ext.sh` → zephir generate + patch config.m4 + REGISTER fixup.

`build-linux.sh` on Debian/Ubuntu: apt `libgtk-4-dev`, generate ext if missing, phpize, `--enable-gtk`, make, install. Refuses Darwin.
