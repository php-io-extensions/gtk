# OKF log — php-io-extensions/gtk

## 2026-08-14 (ext/ PIE-ready)

- Mac `ext/` replaced with a clean Pi `prepare-ext.sh` generate: 45 `*.zep.c` = 45 `ZEPHIR_INIT`, no `*.lo`/`*.o`/`modules`/`.libs`. `config.m4` requires gtk4 ≥ 4.10.0.

## 2026-08-14 (full native widget list)

- Bound the remaining display/input/chrome/dialog widgets Angel listed. Dialogs are GTK 4.10+ (`choose`/`open`/`save`/`select_folder`/`choose_rgba`/`choose_font` finish into a PHP callable). ListView usable via StringList + SingleSelection + SignalListItemFactory + ListItem. `gtk_window_set_titlebar` added for HeaderBar. Minimum GTK documented as 4.10.

## 2026-08-14 (native widget family)

- `scripts/patch-config-m4.py` source list must include every `*.zep.c` or the `.so` loads with undefined `zim_*` symbols.
- Added `GtkLabel` (`new` / `set_text` / `get_text`), `GtkEntry` (`new` / editable text / placeholder / visibility), `GtkCheckButton` (`new` / label / active), `GtkSwitch` (`new` / active). Namespace `Gtk\\GTK\\GtkSwitch` — `switch` is reserved in PHP. Each method calls the matching libgtk-4 function.

## 2026-08-13 (gpu pane visible)

- X11 pane is override-redirect on the root, aligned to the widget — not a child of the redirected GdkSurface (that was the white screen). Size falls back to window default / 640×480. `gtk_gpu_pane_native` resyncs. Opacity 0 on the drawing area so GSK white does not cover WSI.

## 2026-08-13 (gpu pane visible)

- X11 child is parented to the GdkSurface XID after `XCompositeUnredirectWindow` (redirected children are invisible — that was the white window). `gtkWidgetAddTickCallback` so present can run every frame.

## 2026-08-14

- `GtkWidget`: `gtkWidgetSetHalign` / `SetValign` / `GetHalign` / `GetValign`. `GtkAlign` is an int (microscrap `Align` enum).

## 2026-08-13 (gpu pane)

- Added `Gtk\\GTK\\GpuPane\\GtkGpuPane`: `gtkGpuPaneNew` / `gtkGpuPaneNative`. X11 child window in the widget allocation after realize; resize/move on drawing-area resize; destroy on unrealize. No libvulkan. Wayland out of scope.

## 2026-08-13 (signal return)

- `gSignalConnect` is no longer a void(instance) C callback. It uses `g_signal_connect_closure` + `php_gtk_closure_marshal` so PHP returns write into GObject `return_value`. Required for `GtkGLArea::render` (`return true` or GTK overpaints `glClear`). Extra signal args (e.g. `GdkGLContext`) are passed as opaque `int`s.

## 2026-08-13

- Initial 0.7.0 bundle: Zephir GTK4 bind-only extension (Linux Debian/Ubuntu).
- Classes: Gtk, GtkError, GtkApplication, GtkWindow, GtkWidget, GtkButton, GtkBox, GtkGLArea, GtkGLib (not GtkGObject).
- One installer: `build-linux.sh` (Debian and Ubuntu share `libgtk-4-dev`).
- Explicitly not PECL php-gtk; not compiled on macOS; no FFI; no class constants.
- Compiled and loaded on fnk0107 (Pi 5, Debian, PHP 8.4.20 ZTS, GTK 4.18.6). `zephir generate` + `build-linux.sh` + `proof_of_work.php` pass.
- Zephir traps: no `object` param names; no `GObject` in `gtkglib.zep` file-level externs; `Z_STRVAL` not `Z_STRVAL_P`; fixup prepends `gtk_` on REGISTER_CLASS 4th arg.
