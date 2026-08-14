# Agent guidance — php-io-extensions/gtk

1. **Read [`.okf/index.md`](.okf/index.md) first** before changing architecture, API, or packaging.
2. Open only the concept files you need; prefer `status: stable` when present (most are `draft` until Angel verifies).
3. This package is a **Linux GTK4** binding — Debian/Ubuntu. Not legacy PECL php-gtk. Darwin toolkit is `php-io-extensions/metal`. Windows excluded. Links **libgtk-4 ≥ 4.6.0** via `pkg-config gtk4`. No FFI.
4. Public PHP API: static methods under `Gtk\GTK\…`. Opaque GTK/GObject pointers are PHP `int` handles (`0` = NULL).
5. **Bind the library only.** Do not add application orchestration, scene graphs, tubes Canvas, or UX widgets here. Downstream PHP wrappers belong in a future `microscrap/gtk`.
6. No PHP class constants for `GTK_*` / `G_*` flags. Apps or microscrap backed enums (FULLY UPPERCASE cases).
7. Build: Zephir sources in `gtk/gtk/**/*.zep`. Generate C on **Linux** with `scripts/prepare-ext.sh`. Install/compile with `build-linux.sh` on Debian/Ubuntu only. **Do not compile this extension on macOS.**
8. Demos: `examples/proof_of_work.php` (headless version). `examples/proof_window.php` needs a GUI seat.
9. When you learn a durable package fact, update the matching `.okf` concept and append `.okf/log.md`.
10. Do not invent APIs not present in `.zep`. Keep `.okf` at the package root only.
