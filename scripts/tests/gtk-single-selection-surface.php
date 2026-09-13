<?php
/**
 * End-to-end GtkSingleSelection C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSingleSelection",
    "headerRel" => "src/gtk-single-selection.h",
    "implRel" => "src/gtk-single-selection.c",
    "extraSource" => "src/gtk-single-selection.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSingleSelection",
    "symbolPrefix" => "phpgtk_gtksingleselection_",
    "tokenPrefix" => "GTKSINGLESELECTION",
], $argv[1] ?? "surface");
