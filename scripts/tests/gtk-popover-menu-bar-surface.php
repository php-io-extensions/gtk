<?php
/**
 * End-to-end GtkPopoverMenuBar C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkPopoverMenuBar",
    "headerRel" => "src/gtk-popover-menu-bar.h",
    "implRel" => "src/gtk-popover-menu-bar.c",
    "extraSource" => "src/gtk-popover-menu-bar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPopoverMenuBar",
    "symbolPrefix" => "phpgtk_gtkpopovermenubar_",
    "tokenPrefix" => "GTKPOPOVERMENUBAR",
], $argv[1] ?? "surface");
