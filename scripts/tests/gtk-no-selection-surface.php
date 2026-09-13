<?php
/**
 * End-to-end GtkNoSelection C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkNoSelection",
    "headerRel" => "src/gtk-no-selection.h",
    "implRel" => "src/gtk-no-selection.c",
    "extraSource" => "src/gtk-no-selection.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkNoSelection",
    "symbolPrefix" => "phpgtk_gtknoselection_",
    "tokenPrefix" => "GTKNOSELECTION",
], $argv[1] ?? "surface");
