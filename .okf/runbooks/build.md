---
type: Runbook
title: Build, install, test
description: Debian installer on the Pi, Homebrew installer on the Mac, Pest, smoke, clean tree.
resource: install-debian-trixie.sh
tags: [build, linux, macos, pest]
status: draft
generated: { by: claude-opus/5.5, at: 2026-09-30T20:52:04Z }
sources:
  - id: debian
    resource: install-debian-trixie.sh
    title: install-debian-trixie.sh
  - id: mac
    resource: install-macos.sh
    title: install-macos.sh
  - id: smoke
    resource: examples/smoke.php
    title: examples/smoke.php
---

# Overview

Linux (`install-debian-trixie.sh`): needs `libgtk-4-dev`, `pkg-config`, php-dev. Builds in place with phpize, installs `gtk.so`, writes `30-gtk.ini` to the CLI (and FPM/Apache) conf.d, removes build artifacts (incl. `src/.libs`, `src/*.lo`). ≈ 6 s on a Pi 5.[^debian]

macOS (`install-macos.sh`): needs `brew install gtk4`. Builds in a temp copy for php@8.4 (`php84`) and php@8.4-zts (`zhp`), ad-hoc signs, writes `30-gtk.ini`.[^mac]

Pi loop from the Mac: the Mac tree is authoritative; the Pi copy at `~/gtk` is disposable.

```bash
fnk 'rm -rf ~/gtk'
rsync -az --delete --exclude .git --exclude vendor --exclude composer.lock ./ angel@<pi>:/home/angel/gtk/
fnk 'cd ~/gtk && bash install-debian-trixie.sh'
```

Verify (Linux over SSH: export `WAYLAND_DISPLAY=wayland-0 XDG_RUNTIME_DIR=/run/user/1000 DBUS_SESSION_BUS_ADDRESS=unix:path=/run/user/1000/bus`):

```bash
php --ri gtk
composer install && php vendor/bin/pest
php examples/smoke.php     # SMOKE_OK
rm -rf vendor composer.lock build.log
```

Smoke steps: register (startup initialises GTK) + hold + activate; Dock icon (macOS, `lsappinfo`) or app id owned on the session bus (Linux); pump; 50 ms budget; `wakeup()`; idle; pipe-fd wake; kqueue (macOS) / epoll (Linux) fd nested in GLib's poll; `run()` ended by `quit()`; release.[^smoke]

[^debian]: install-debian-trixie.sh
[^mac]: install-macos.sh
[^smoke]: examples/smoke.php
