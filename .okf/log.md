# Log

## 2026-10-01

* Runbook [adding a binding](runbooks/adding-a-binding.md).
* [Surface](api/surface.md): GtkWidget, GtkWindow, GtkApplicationWindow, GtkAboutDialog, GtkBox, GtkPopoverMenuBar, GMenuModel/GMenu/GMenuItem, GSimpleAction/GSimpleActionGroup, GVariant, GtkOrientation, GtkApplication window and menubar calls. [Object model](architecture/object-model.md): GVariant kind and constructor ownership.
* [Surface](api/surface.md): GtkWidget get_realized/get_mapped. [Errors and threads](architecture/errors-and-threads.md): widget constructors refuse an uninitialised GTK.
* [Surface](api/surface.md): GApplication GActionMap/GActionGroup calls (the "app" actions).

## 2026-09-30

* Bundle created with ext-gtk 0.10.0: [surface](api/surface.md), [object model](architecture/object-model.md), [callouts](architecture/callouts.md), [errors and threads](architecture/errors-and-threads.md), [build](runbooks/build.md).
