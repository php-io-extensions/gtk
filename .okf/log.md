# Log

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
