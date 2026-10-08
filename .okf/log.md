# Log

## 2026-10-06

* `GdkDmabufTextureBuilder::build()` takes a destroy callback (GTK's destroy notify); `GdkDmabufFormats` from `GdkDisplay::getDmabufFormats()`; `GtkWidget::getDisplay()`. Suite 145 + 5 skipped on Homebrew PHP 8.4 NTS and ZTS, 150 on the Pi. [surface](api/surface.md)
* `GdkDmabufTextureBuilder` (Linux, GTK 4.14+): a texture over a dmabuf, the fd borrowed. `SurfaceTest` skips Linux-only stub blocks elsewhere. Suite 142 + 4 skipped on Homebrew PHP 8.4 NTS and ZTS, 146 on the Pi. [surface](api/surface.md)
* GL views: `GtkGLArea` and `GdkGLContext` with `GdkGLAPI`; the `render` signal hands PHP the area and its context, the context current and the area's framebuffer bound. Suite 143 on Homebrew PHP 8.4 NTS and ZTS (1 skipped there) and on the Pi. [surface](api/surface.md)

## 2026-10-04

* Extension version is 0.10.1. Memory textures from an address: `GdkMemoryTexture::new()` takes `string|int` bytes, an address trusted to hold the rows the width, height and stride name. New `GdkMemoryTextureBuilder` (GTK 4.16+, compiled only when headers are 4.16+): fluent setters, `setBytes` from a string or an address with a byte count, `setUpdateRegion` of `[x, y, width, height]` rects, `build(): ?GdkTexture` (null when unset). [surface](api/surface.md)

## 2026-10-03

* Pixels from bytes: `GdkTexture`, `GdkMemoryTexture::new()`, `GdkMemoryFormat`; `GtkPicture` set_paintable and can_shrink; `GtkWidget::getScaleFactor()`. [surface](api/surface.md)

## 2026-10-02

* [Surface](api/surface.md): widget alignment, sizing, margins, CSS classes; GtkBox ordering; GtkGrid, GtkFixed; GtkCssProvider, GdkDisplay, style-context functions; GdkSurface. New concept [layout and styling](architecture/layout.md).
* [Surface](api/surface.md): GtkLabel, GtkButton, GtkCheckButton, GtkSwitch, GtkToggleButton, GtkEntry/GtkEntryBuffer, GtkTextView/GtkTextBuffer, GtkScale, GtkWidget activate.
* [Surface](api/surface.md): GtkDropDown, GtkStringList, GtkStringObject, GtkCalendar, GDateTime (new boxed kind, [object model](architecture/object-model.md)), GtkProgressBar, GtkSpinner, GtkPicture, GtkSeparator, GtkScrolledWindow.
* [Surface](api/surface.md): GtkColumnView, GtkColumnViewColumn, GtkSignalListItemFactory, GtkListItem, GtkSingleSelection; (transfer full) arguments in [object model](architecture/object-model.md).
* [Surface](api/surface.md): GtkMediaStream, GtkMediaFile, GtkVideo, `gtk_media_backend_available()`; installers check or warn about the media backend. New concept [video and the media backend](architecture/video.md).
* Review fixes: `gtk_widget_unparent` dropped; entry and text buffer lengths and UTF-8, scale ranges, list positions, native int ranges, child parents and column membership refused before GTK asserts; GTK floor raised to 4.12 for `gtk_css_provider_load_from_string`.

## 2026-10-01

* Runbook [adding a binding](runbooks/adding-a-binding.md).
* [Surface](api/surface.md): GtkWidget, GtkWindow, GtkApplicationWindow, GtkAboutDialog, GtkBox, GtkPopoverMenuBar, GMenuModel/GMenu/GMenuItem, GSimpleAction/GSimpleActionGroup, GVariant, GtkOrientation, GtkApplication window and menubar calls. [Object model](architecture/object-model.md): GVariant kind and constructor ownership.
* [Surface](api/surface.md): GtkWidget get_realized/get_mapped. [Errors and threads](architecture/errors-and-threads.md): widget constructors refuse an uninitialised GTK.
* [Surface](api/surface.md): GApplication GActionMap/GActionGroup calls (the "app" actions).

## 2026-09-30

* Bundle created with ext-gtk 0.10.0: [surface](api/surface.md), [object model](architecture/object-model.md), [callouts](architecture/callouts.md), [errors and threads](architecture/errors-and-threads.md), [build](runbooks/build.md).
