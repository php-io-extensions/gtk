# Agent guidelines — php-io-extensions/gtk

## Knowledge Bundle (OKF)

This package ships an Open Knowledge Format bundle at [`.okf/`](.okf/) (excluded from the Composer dist via `.gitattributes` `export-ignore`). Before changing code or advising on this package: read [`.okf/index.md`](.okf/index.md) first, open only the concepts the task needs, prefer `status: stable` over `draft`. When you learn something durable, update the affected concept(s) and append `.okf/log.md`; new or changed concepts stay `status: draft` until a human verifies them.

## Binding rules (the spec: [`.okf/binding-rules.md`](.okf/binding-rules.md))

1. One ext call = one native call (`gtk_*` / `g_*` / `gdk_*` / `gsk_*` / `pango_*`). The only sanctioned composite is constructor + registry sink (`gtk_button_new()` then `phpgtk_handle_register()`, which `g_object_ref_sink`s).
2. One static method per C function, no opinions: `GtkButton` → `Gtk\Gtk\GtkButton\GtkButton`, generated file `gtk/gtk/gtkbutton/gtkbutton.zep`. First annotation segment = library (`Gtk\`, `Gdk\`, `Gio\`, `GLib\`, `Pango\`).
3. Never hand-write `.zep` files or optimizers — they are generated from the `/*@zep ... */` lines in `src/*.h` by `php scripts/gen-zep.php`. C symbol prefix is `phpgtk_`, never colliding with real GTK symbols.
4. Every gir member (constructor + method + function from the vendored `scripts/gir/` XML) is either bound (`@zep`) or kept as a commented `@reserved` signature (`GError**`, varargs, `GVariant*`, non-signal callbacks, `GtkTextIter*`/stack boxed, deprecated). Nothing is silently omitted. Properties without C accessors are reserved as `property "x"` and served by `Bridge::getProperty`/`setProperty`.
5. Types: gboolean/int/enum/flags/double → bool/int/int/double; `const char*` → string (`var` when nullable, null = NULL); any `GObject*` → int handle (0 = NULL) resolved only via the registry; structs → doubles in, assoc arrays out; `GStrv` → array of strings.
6. Inherited methods bind once on the declaring class; handles are untyped, so `GtkWidget::setHexpand($button, ...)` works. Interfaces bind as classes of their own.
7. All glue lives in `Gtk\Bridge\Bridge` (`src/phpgtk-bridge.{h,c}`); marshalling only via `src/phpgtk-support.{h,c}`; no other `PhpGtk*` machinery may exist.
8. No constants in the ext — enum values become PHP enums in `jovian/gtk`. No error side channel — fallible calls return 0 and raise `E_WARNING`.
9. Pipeline: `php scripts/gen-zep.php` → `php scripts/check-parity.php` (must print `PARITY_OK` and `AUDIT_OK`) → `php scripts/tests/run-all.php` → `bash scripts/prepare-ext.sh` → copy to the Pi → `bash build-linux.sh` → `php scripts/verify-reflection.php` → `php examples/smoke.php`. Source guards pass on code Zephir cannot compile: nothing is done until the Pi build and smoke are green.
10. Zephir reserved words in method and parameter names get a trailing underscore (`new_`); all-caps names are emitted mixed-case. Build only on the Pi (via the `fnk` alias; never inline its credentials); fix on the Mac, re-copy, rebuild — never edit on the Pi.
