---
type: Runbook
title: Generate, verify, prepare on the Mac — build, verify, smoke on the Pi
description: >-
  The pipeline that turns @zep annotations in src/*.h into a loadable
  extension, the guards that keep it faithful, and the Mac/Pi split.
tags: [toolchain, zephir, build, gir, pi]
status: draft
generated:
  by: cursor-grok-4.6/cursor
  at: 2026-08-28T10:00:00Z
---

# Toolchain

The annotations in `src/*.h` are the single source of truth. Everything
under `gtk/` and `optimizers/` is generated and prunes itself; never
hand-edit. The vendored gir set in `scripts/gir/` is the audit truth
(GTK 4.18.6 / GLib 2.84.4 / Pango 1.56.3 from the Pi — see its README).

## Mac / Pi split

Development, generation, and all source-level guards run on the Mac. The
extension **only compiles and runs on the Pi 5 build box** (Debian 13
trixie, aarch64, PHP 8.4.20 ZTS, GTK 4.18.6), reached via Angel's `fnk`
zsh alias (`~/.zshrc`; sshpass-wrapped ssh — never inline its credentials
in files; expand it with `zsh -ic 'fnk "…"'`, and pipe tar over ssh stdout
for file transfer). Copy the repo to the Pi, build there, and **fix on the
Mac, re-copy, rebuild — never edit on the Pi.**

## Pipeline

```bash
# Mac
php scripts/gen-zep.php            # annotations -> .zep files + optimizers (GEN_OK)
php scripts/check-parity.php       # PARITY_OK, then chains audit-gir.php (AUDIT_OK)
php scripts/tests/run-all.php      # negative controls + per-class surface checks (TESTS_OK)
bash scripts/prepare-ext.sh        # zephir generate, stage src/, fix_register_macro,
                                   # strip leftovers, write ext/.gen-stamp (PREPARE_EXT_OK)
# Pi (copy repo over first)
bash build-linux.sh                # apt deps, stale-ext gen-stamp check, phpize/configure/make, install
php scripts/verify-reflection.php  # REFLECTION_OK: installed .so matches annotations
php examples/proof_of_work.php     # headless class/version proof
php examples/proof_window.php      # needs the Pi's logged-in seat
php examples/smoke.php             # SMOKE_OK
```

## Guards

- `check-parity.php` — zep bare calls ↔ optimizers ↔ C prototypes (names and
  arity), `config.json` extra-sources coverage, the composite guard (at most
  one native `gtk_*/g_*/gdk_*/gsk_*/pango_*` call per binding body;
  registration via `phpgtk_handle_register` is structurally uncounted, so
  constructor+sink passes; translation-table frees whitelisted;
  `phpgtk-bridge.c` is glue and exempt), then chains the gir audit.
- `audit-gir.php` — per class: bound + reserved must equal the gir
  constructor+method+function count (`<virtual-method>` never counts;
  signals informational). Every gir property must be accessor-covered
  (gir `getter=`/`setter=` attributes with a `get_x`/`is_x`/`has_x`/`set_x`
  name-mapping fallback, because those attributes are occasionally missing)
  or reserved as `property "x"` — property-only reservations do not count
  toward the member sum. Construction path required unless the type is
  abstract, an interface, or on `OBTAIN_ONLY`. `@audit partial <class>
  <reason>` sanctions a shortfall (never an excess). `--count <gir> <CType>`
  gives a standalone breakdown.
- `scripts/tests/run-all.php` — negative controls: each guard is proven able
  to fail against a bad fixture (drift, parity break, composite break, audit
  miss, prepare-ext `fix_register_macro` firing, structure) plus per-class
  surface checks for every slice-zero, Wave A, and Wave B class.
-   `scripts/verify-wave-a.php` — re-measures vendored gir counts for the
  Wave A1–A8 classes and asserts extra-sources + surface-test wiring.
  `scripts/verify-wave-b.php` does the same for Wave B1–B9 (Gio and Gtk
  girs) and asserts `Bridge::typeFromName`.
  `scripts/pi-wave-verify.sh` copies the tree over `fnk` and runs
  `build-linux.sh` + `verify-reflection.php`.
- `verify-reflection.php` — the only guard that inspects the **installed**
  `.so`: per class, reflected method count equals the `@zep` +
  `@zep-construct` count. Runs on the Pi only.
- `prepare-ext.sh` writes `ext/.gen-stamp` (SHA-256 over `src/`, `gtk/`,
  `optimizers/`) and `build-linux.sh` refuses a committed `ext/` whose stamp
  no longer matches the sources — the stale-ext trap that bit dep-gtk
  (see the dep-gtk `.okf/traps/stale-ext-directory.md` history) is now
  mechanical.

## Gotchas

- **Parity and the gir audit both pass on sources Zephir cannot compile.**
  A wave is not done until `build-linux.sh` succeeds and the smoke passes
  **on the Pi** (appkit learned this when a broken build hid behind green
  source guards for a full wave).
- Version dance: manifests carried **0.9.0 during the build loop** so
  `php --ri gtk` proved the deprecated dep-gtk 0.8.0 install was overridden.
  After the Pi smoke passed they were demoted to **0.8.0** in
  `composer.json`, `config.json`, and `ext/php_gtk.h`. Source edits alone
  leave a stale `.so` — rebuild on the Pi after the demote (appkit's
  install-gate lesson).
- Zephir emits a wrong `lower_ns` argument in `ZEPHIR_REGISTER_CLASS` for
  nested namespaces (`Gtk\Gtk\GtkButton`); `fix_register_macro()` in
  `prepare-ext.sh` (awk, carried verbatim from dep-gtk) recovers the right
  value from the method-entry symbol at any depth.
- `gen-zep.php` treats any source line containing the substring `@zep` as an
  annotation. File-header comments must not mention that token (write
  "bound or reserved" instead); a stray occurrence is a hard fail. The same
  applies to PHP docblocks in the scripts themselves: a comment containing
  `gtk_*/g_*` terminates the docblock at the `*/` inside it.
- `zephir generate` runs under `php -n` (plus `zephir_parser`) so an
  installed previous `gtk.so` cannot segfault the compiler. Herd's
  `PHP_BINARY` path contains spaces — anything shelling out to it must
  `escapeshellarg`.
- Zephir prerequisites on the Mac: `composer global require phalcon/zephir`
  and the `zephir_parser` extension. `Zephir version has changed, use
  "zephir fullclean"` aborts generation until you run it.
- Zephir's `package-dependencies` (`gtk4 >= 4.18.0` in `config.json`) emits
  a real pkg-config probe into `ext/config.m4` — no config.m4 patching, no
  Makefile.frag, and none of appkit's `.m`-file machinery is needed for C.
  Never add `-lX11` (dep-gtk cargo cult; GTK4 links what pkg-config says).
- The Pi's seat: `proof_window.php` / `smoke.php` need the logged-in
  Wayland/X11 session. Over ssh, export the seat env of the logged-in user
  first — on the build box `XDG_RUNTIME_DIR=/run/user/1000 DISPLAY=:0`
  works (both `wayland-0` and `X0` sockets exist; without `WAYLAND_DISPLAY`
  GTK takes X11). Add `GTK_A11Y=none` to silence the accessibility-bus
  warning over ssh.
- Copying Mac → Pi with plain `tar` ships AppleDouble `._*` files. They
  break the build twice: the extra `._*.zep`/`._*.php` files change the
  gen-stamp (so `build-linux.sh` declares `ext/` stale), and Zephir then
  crashes trying to parse `gtk/bridge/._bridge.zep`. Always
  `COPYFILE_DISABLE=1 tar czf … --exclude '._*'`.

See [binding-rules.md](/binding-rules.md) for what the generator emits.
