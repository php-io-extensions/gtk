<?php
/**
 * End-to-end GtkColumnViewColumn C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkColumnViewColumn",
    "headerRel" => "src/gtk-column-view-column.h",
    "implRel" => "src/gtk-column-view-column.c",
    "extraSource" => "src/gtk-column-view-column.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkColumnViewColumn",
    "symbolPrefix" => "phpgtk_gtkcolumnviewcolumn_",
    "tokenPrefix" => "GTKCOLUMNVIEWCOLUMN",
], $argv[1] ?? "surface");
