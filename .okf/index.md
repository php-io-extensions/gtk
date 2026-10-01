---
okf_version: "0.2"
---

# ext-gtk

* [Binding surface](api/surface.md) - Functions, classes, enums and constants bound so far, each one GTK, GIO or GLib call.

# Architecture

* [Object model](architecture/object-model.md) - One PHP object per GObject or GMainContext, referenced while PHP holds it, boxed as its nearest bound GType.
* [Callouts](architecture/callouts.md) - Sources and signal handlers that call PHP; GLib owns the record, detached at request end.
* [Errors and threads](architecture/errors-and-threads.md) - GError becomes the GError exception; GTK entry points refuse other threads, widgets refuse an uninitialised GTK.

# Runbooks

* [Build, install, test](runbooks/build.md) - Debian installer on the Pi, Homebrew installer on the Mac, Pest, smoke, clean tree.
* [Adding a binding](runbooks/adding-a-binding.md) - Stub, gen_stub, one .c per stub, config.m4 source list, guards, ownership, surface test.
