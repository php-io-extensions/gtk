---
okf_version: "0.2"
---

# ext-gtk

* [Binding surface](api/surface.md) - Functions, classes, interfaces, enums and constants, each one GTK, GDK, GIO, GLib, cairo or graphene call, 1:1.

# Architecture

* [Object model](architecture/object-model.md) - One PHP object per GObject or GMainContext, referenced while PHP holds it, boxed as its nearest bound GType.
* [Callouts](architecture/callouts.md) - Sources, signal handlers, async callbacks and destroy notifies that call PHP; owner thread only; GValue marshalling both ways.
* [Errors and threads](architecture/errors-and-threads.md) - GTK's own answers pass through; GError after the call is thrown; the probe-backed refusal sites and the probe build.
* [Layout and styling](architecture/layout.md) - GtkBox, GtkGrid and GtkFixed; alignment, expansion, size requests and margins; CSS classes and providers per display; GdkSurface size and layout signal.
* [Video and the media backend](architecture/video.md) - GtkVideo over GtkMediaFile; GTK loads a media backend module (GStreamer on Debian, none in Homebrew gtk4); the probe, the installers, what runs where.

# Runbooks

* [Build, install, test](runbooks/build.md) - Debian installer on the Pi, Homebrew installer on the Mac, Pest, smoke, clean tree.
* [Adding a binding](runbooks/adding-a-binding.md) - Stub, gen_stub, one .c per stub, config.m4 source list, guards, ownership, surface test.
