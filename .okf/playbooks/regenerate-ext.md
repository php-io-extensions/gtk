---
type: Playbook
title: Regenerate ext/
status: draft
generated: { by: cursor-agent, at: "2026-08-13T20:42:00Z" }
---

On Linux with Zephir + `libgtk-4-dev`:

```bash
bash scripts/prepare-ext.sh
```

Then `bash build-linux.sh` on that machine. Do not `make` on macOS.
