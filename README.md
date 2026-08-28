# gtk

GTK4 bound 1:1 into PHP. One static method per GTK C function, no opinions:
this extension is GTK plus the glue PHP cannot provide for itself.
Composition belongs in `jovian/gtk` (a PHP function per ext call), venusian
(composition), and Surface (abstraction) — not here.

Requires Linux, GTK 4.18+, and PHP 8.4+. Build with `bash build-linux.sh`
on the target box (Debian/Ubuntu; installs apt dependencies itself).

## Binding rules

| GTK / GLib | PHP |
|---|---|
| `GtkButton` | `Gtk\Gtk\GtkButton\GtkButton`, all methods static; `Gio\GApplication` → `Gtk\Gio\GApplication\GApplication` |
| `gtk_button_set_label(button, label)` | `GtkButton::setLabel(int handle, string label): void` |
| `gtk_button_new()` | `GtkButton::new_(): int` — one call returning a handle (construction is the only sanctioned composite; `new` is a Zephir reserved word) |
| gboolean / int, guint, enum, flags / double | `bool` / `int` / `double` |
| `const char*` | `string`, or `var` when nullable (null = NULL) |
| any `GObject*`, widget, interface pointer | `int` handle, 0 = NULL; stale handles resolve to NULL, never a crash |
| `GdkRGBA` / `GdkRectangle` / graphene structs | component doubles in, assoc array out |
| scalar out-params (`int*`, …) | assoc array out, keys = C parameter names (`getDefaultSize` → `{width, height}`) |
| `char**` / `GStrv`, `GList*` of objects | array of strings / array of handles |
| `GError**`, varargs, `GVariant*`, non-signal callbacks, `GtkTextIter*`, deprecated | not bound; kept as a commented `@reserved` signature in `src/*.h` |
| properties without C accessors | `@reserved property "x"` + `Bridge::getProperty`/`setProperty` |
| signals | `Bridge::connect` only |
| inherited methods | bound once on the declaring class; handles are untyped, so `GtkWidget::setHexpand($button, ...)` works |

Enum values are deliberately absent — they live in `jovian/gtk` as PHP
enums. Pass the raw ints, as the example does.

All glue lives in `Gtk\Bridge\Bridge`: `init`, the handle registry
(`retain`/`release`/`isValid`/`typeName`/`isA`), `pump`,
`connect`/`disconnect` (with return-value writeback, so `close-request`
handlers work), and `getProperty`/`setProperty`.

## Example

```php
use Gtk\Bridge\Bridge;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkButton\GtkButton;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

Bridge::init();

$win = GtkWindow::new_();
GtkWindow::setTitle($win, 'hello from PHP');
GtkWindow::setDefaultSize($win, 420, 260);

$box = GtkBox::new_(1, 12);                          // GTK_ORIENTATION_VERTICAL
GtkWidget::setMarginTop($box, 20);                   // GtkWidget setter on a GtkBox handle
GtkWindow::setChild($win, $box);

$btn = GtkButton::newWithLabel('Click me');
GtkBox::append($box, $btn);

Bridge::connect($btn, 'clicked', function (int $button): void {
    echo "clicked\n";                                // a real GTK signal calls straight into PHP
});

$open = true;
Bridge::connect($win, 'close-request', function () use (&$open): bool {
    $open = false;
    return false;                                    // writeback: false lets GTK close the window
});

GtkWindow::present($win);
while ($open) {
    Bridge::pump(50);                                // PHP drives the main loop
}
```

See [`examples/smoke.php`](examples/smoke.php) for signals, the
close-request writeback, property fallback, and the failure paths.

## Working on this extension

`src/*.h` is the single source of truth: `gtk/**/*.zep` and `optimizers/`
are generated and must never be hand-edited. The audit truth is the
vendored GObject-Introspection XML in `scripts/gir/` (GTK 4.18.6). See
[`AGENTS.md`](AGENTS.md) for the rules and [`.okf/`](.okf/index.md) for the
full knowledge bundle.

```bash
# Mac (development)
php scripts/gen-zep.php            # annotations -> .zep + optimizers (GEN_OK)
php scripts/check-parity.php       # PARITY_OK + AUDIT_OK (chains the gir audit)
php scripts/tests/run-all.php      # negative controls (TESTS_OK)
bash scripts/prepare-ext.sh        # zephir generate + stage + .gen-stamp

# Linux box (build + proof)
bash build-linux.sh                # build and install
php scripts/verify-reflection.php  # REFLECTION_OK: installed .so matches annotations
php examples/proof_of_work.php     # headless proof
php examples/smoke.php             # SMOKE_OK (needs a logged-in seat)
```
