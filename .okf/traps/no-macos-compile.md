---
type: Trap
title: Do not compile on macOS
description: build-linux.sh refuses Darwin
tags: [gtk, trap]
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

Generate and compile `ext/` on Debian/Ubuntu. macOS toolkit host is metal/AppKit. `build-linux.sh` exits if `uname` is Darwin.
