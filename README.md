# php-gtk (php-io-extensions)

[![PHP](https://img.shields.io/badge/php-%E2%89%A5%208.2-777bb4?logo=php&logoColor=white)](https://www.php.net)
[![GTK](https://img.shields.io/badge/GTK-%E2%89%A5%204.10-47848f)](https://www.gtk.org/)
[![Built with Zephir](https://img.shields.io/badge/built%20with-Zephir-ff6a00)](https://zephir-lang.com/)
[![Platform](https://img.shields.io/badge/platform-linux-lightgrey)](#requirements)
[![License: MIT](https://img.shields.io/badge/license-MIT-green)](#license)

> PHP extension for **GTK4** — built with [Zephir](https://zephir-lang.com/). This is **not** the legacy PECL `php-gtk` (PHP 5).

`gtk` exposes GTK4 C APIs to PHP 8.2+ as static methods under `Gtk\GTK\…`. It **binds the library**. It does not orchestrate applications, scenes, or tubes. Downstream PHP (a future `microscrap/gtk`) owns ergonomics and enums.

Linux only (Debian / Ubuntu). Darwin toolkit host is `php-io-extensions/metal`. Windows is excluded.

---

## Requirements

| Component | Minimum | Notes |
| --------- | ------- | ----- |
| PHP | 8.2 | ZTS and NTS |
| GTK4 | 4.10.0 | `pkg-config gtk4` — Debian/Ubuntu package `libgtk-4-dev` |
| OS | Linux | Debian and Ubuntu share the same apt names |
| Compiler | C11 | `gcc` on the Linux box |
| Zephir | 0.19.x | Only required to regenerate `ext/` (`scripts/prepare-ext.sh`) |

This repository does **not** compile on macOS. Use `build-linux.sh` on Debian or Ubuntu.

---

## Installation (Linux)

Debian and Ubuntu use the same packages, so there is one script:

```bash
bash build-linux.sh
```

That script:

1. Installs `libgtk-4-dev` + PHP headers if needed
2. Runs `scripts/prepare-ext.sh` if `ext/` has not been generated (needs Zephir)
3. `phpize` → `./configure --enable-gtk` → `make` → install `.so` + `30-gtk.ini`

PIE (after `ext/` is committed):

```bash
pie install php-io-extensions/gtk
```

---

## What this extension is

Opaque `int` handles are GObject pointers. `0` is NULL / failure. PHP GC does **not** free natives — pair create with `gObjectUnref` / `gtkWindowDestroy`.

No PHP class constants. Flag ints live in the app or a future microscrap enum (FULLY UPPERCASE backed cases).

| Class | C library |
| ----- | --------- |
| `Gtk\GTK\Gtk` | `gtk_init_check`, version getters |
| `Gtk\GTK\GtkError` | last bind-layer failure string |
| `Gtk\GTK\Application\GtkApplication` | `gtk_application_new`, `g_application_run`, `g_application_quit`, `gtk_application_set_menubar`, `gtk_application_set_accels_for_action` |
| `Gtk\GTK\GMenu\GMenu` | `g_menu_new`, append / section / submenu / freeze |
| `Gtk\GTK\GSimpleAction\GSimpleAction` | `g_simple_action_new`, `g_action_map_add_action`, enable |
| `Gtk\GTK\PopoverMenu\GtkPopoverMenu` | `gtk_popover_menu_new_from_model` |
| `Gtk\GTK\PopoverMenuBar\GtkPopoverMenuBar` | `gtk_popover_menu_bar_new_from_model` |
| `Gtk\GTK\Window\GtkWindow` | window / application-window, title, size, child, present, close |
| `Gtk\GTK\Widget\GtkWidget` | visible, expand, size request, queue draw |
| `Gtk\GTK\Button\GtkButton` | button + label |
| `Gtk\GTK\Label\GtkLabel` | label + text |
| `Gtk\GTK\Image\GtkImage` | image from file / icon |
| `Gtk\GTK\Picture\GtkPicture` | picture from filename |
| `Gtk\GTK\Spinner\GtkSpinner` | spinner start/stop |
| `Gtk\GTK\ProgressBar\GtkProgressBar` | fraction / text / pulse |
| `Gtk\GTK\Separator\GtkSeparator` | separator |
| `Gtk\GTK\Entry\GtkEntry` | entry + text / placeholder / visibility |
| `Gtk\GTK\PasswordEntry\GtkPasswordEntry` | password + peek |
| `Gtk\GTK\TextView\GtkTextView` | multiline text |
| `Gtk\GTK\CheckButton\GtkCheckButton` | check button + label + active |
| `Gtk\GTK\ToggleButton\GtkToggleButton` | toggle + label + active |
| `Gtk\GTK\GtkSwitch\GtkSwitch` | switch + active (`Switch` is a reserved PHP word) |
| `Gtk\GTK\SpinButton\GtkSpinButton` | numeric spin |
| `Gtk\GTK\Scale\GtkScale` | slider |
| `Gtk\GTK\DropDown\GtkDropDown` | string drop-down |
| `Gtk\GTK\SearchEntry\GtkSearchEntry` | search field |
| `Gtk\GTK\HeaderBar\GtkHeaderBar` | header bar (use `gtkWindowSetTitlebar`) |
| `Gtk\GTK\MenuButton\GtkMenuButton` | menu button + popover + `set_menu_model` |
| `Gtk\GTK\Popover\GtkPopover` | popover + child |
| `Gtk\GTK\ScrolledWindow\GtkScrolledWindow` | scroll child |
| `Gtk\GTK\Notebook\GtkNotebook` | tabs |
| `Gtk\GTK\Stack\GtkStack` | named pages |
| `Gtk\GTK\Paned\GtkPaned` | split pane |
| `Gtk\GTK\Grid\GtkGrid` | grid attach |
| `Gtk\GTK\CenterBox\GtkCenterBox` | start / center / end |
| `Gtk\GTK\Overlay\GtkOverlay` | overlay children |
| `Gtk\GTK\ListBox\GtkListBox` | list rows |
| `Gtk\GTK\ListView\GtkListView` | list view + StringList / SingleSelection / ListItem |
| `Gtk\GTK\AlertDialog\GtkAlertDialog` | alert show / choose |
| `Gtk\GTK\FileDialog\GtkFileDialog` | open / save / folder |
| `Gtk\GTK\ColorDialog\GtkColorDialog` | color choose |
| `Gtk\GTK\FontDialog\GtkFontDialog` | font choose |
| `Gtk\GTK\Box\GtkBox` | box + append/remove |
| `Gtk\GTK\GLArea\GtkGLArea` | GPU view widget (does not create a window) |
| `Gtk\GTK\GtkGLib` | `g_object_ref` / `unref`, `g_signal_connect`, `g_main_context_default`, `g_main_context_iteration` |

`g_application_run` **blocks** the PHP thread. That is the GTK Application run loop.

---

## Examples

Headless (no display):

```bash
php examples/proof_of_work.php
```

One window + button (needs `WAYLAND_DISPLAY` or `DISPLAY`):

```bash
php examples/proof_window.php
```

Orientation ints for `gtkBoxNew` (define in the app, not in this extension):

```php
const GTK_ORIENTATION_HORIZONTAL = 0;
const GTK_ORIENTATION_VERTICAL = 1;
```

---

## Regenerating `ext/`

On Linux, after changing `.zep` files:

```bash
bash scripts/prepare-ext.sh
```

Then commit the generated `ext/` C (phpize junk is gitignored). Do not run `make` on macOS.

---

## License

MIT. See [LICENSE](LICENSE).
