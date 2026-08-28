<?php
/**
 * End-to-end GtkPopover C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkPopover",
    "headerRel" => "src/gtk-popover.h",
    "implRel" => "src/gtk-popover.c",
    "extraSource" => "src/gtk-popover.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPopover",
    "symbolPrefix" => "phpgtk_gtkpopover_",
    "tokenPrefix" => "GTKPOPOVER",
], $argv[1] ?? "surface");
