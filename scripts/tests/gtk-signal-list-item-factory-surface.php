<?php
/**
 * End-to-end GtkSignalListItemFactory C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSignalListItemFactory",
    "headerRel" => "src/gtk-signal-list-item-factory.h",
    "implRel" => "src/gtk-signal-list-item-factory.c",
    "extraSource" => "src/gtk-signal-list-item-factory.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSignalListItemFactory",
    "symbolPrefix" => "phpgtk_gtksignallistitemfactory_",
    "tokenPrefix" => "GTKSIGNALLISTITEMFACTORY",
], $argv[1] ?? "surface");
