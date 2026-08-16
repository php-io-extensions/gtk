---
okf_version: "0.2"
---

# php-io-extensions/gtk

Linux PHP extension: Zephir bindings for **libgtk-4 ≥ 4.6.0** — init, GtkApplication, windows, widgets, button, box, GtkGLArea, GObject ref/signal. This is **not** legacy PECL php-gtk.

**Prefer** `status: stable` when present; content is `draft` until Angel verifies.

This is the **native extension** (`ext-gtk`). Downstream PHP wrappers (future `microscrap/gtk`) are composition-only in this bundle.

# Orientation

* [Package overview](orientation/overview.md) - What gtk is and is not
* [Stack segmentation](orientation/stack-segmentation.md) - Boundaries vs sdl3, glfw, metal, tubes

# Architecture

* [Layered stack](architecture/stack.md) - Zephir → GTK4 C API → libgtk-4
* [Zephir inline C](architecture/zephir-inline-c.md) - `%{ … %}` bridges, opaque ints, signals

# Public PHP API

* [Gtk\\GTK\\Gtk](api/gtk.md) - init_check + version
* [Gtk\\GTK\\GtkError](api/gtkerror.md) - last bind failure string
* [Gtk\\GTK\\Application\\GtkApplication](api/application.md) - application new/run/quit
* [Gtk\\GTK\\Window\\GtkWindow](api/window.md) - window + application window
* [Gtk\\GTK\\Widget\\GtkWidget](api/widget.md) - visibility / expand / size
* [Gtk\\GTK\\Button\\GtkButton](api/button.md) - button + label
* [Gtk\\GTK\\Label\\GtkLabel](api/label.md) - label + text
* [Gtk\\GTK\\Entry\\GtkEntry](api/entry.md) - entry + text / placeholder / visibility
* [Gtk\\GTK\\CheckButton\\GtkCheckButton](api/checkbutton.md) - check button + label + active
* [Gtk\\GTK\\GtkSwitch\\GtkSwitch](api/gtkswitch.md) - switch + active
* [Native widget family](api/native-widgets.md) - display, input, chrome, dialogs
* [Gtk\\GTK\\Box\\GtkBox](api/box.md) - box append/remove
* [Gtk\\GTK\\Fixed\\GtkFixed](api/fixed.md) - x/y child placement
* [Gtk\\GTK\\GLArea\\GtkGLArea](api/glarea.md) - GPU view (no window create)
* [Gtk\\GTK\\GpuPane\\GtkGpuPane](api/gpupane.md) - X11 child pane for foreign WSI (not GtkVulkanArea)
* [Gtk\\GTK\\GtkGLib](api/gobject.md) - ref/unref/signal connect

# Build & packaging

* [Zephir + Linux install](build/zephir-and-linux.md) - prepare-ext + build-linux
* [Committed ext/ notes](build/packaging-ext.md) - generate on Linux, never compile on macOS

# Conventions

* [Sibling patterns](conventions/sibling-patterns.md)
* [Handle ownership](conventions/handle-ownership.md)
* [No FFI](conventions/no-ffi.md)
* [Constants outside the extension](conventions/constants-outside-ext.md)
* [Bind only](conventions/bind-only.md)

# Traps

* [Not php-gtk](traps/not-php-gtk.md)
* [Do not compile on macOS](traps/no-macos-compile.md)
* [GTK owns the window](traps/gtk-owns-window.md)
* [REGISTER_CLASS truncation](traps/register-class-truncation.md)
* [GCC 14 warning flags](traps/gcc14-warning-flags.md)
* [render must return true](traps/render-must-return-true.md)
* [Do not Vulkan on the GtkWindow XID](traps/no-vk-on-gtk-window.md)

# Playbooks

* [Regenerate ext/](playbooks/regenerate-ext.md)
* [Headless + window proofs](playbooks/proofs.md)

# Indexes

* [Orientation](orientation/)
* [Architecture](architecture/)
* [API](api/)
* [Build](build/)
* [Conventions](conventions/)
* [Traps](traps/)
* [Playbooks](playbooks/)
