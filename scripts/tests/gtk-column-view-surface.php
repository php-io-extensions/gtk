<?php
/**
 * End-to-end GtkColumnView C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkColumnView",
    "headerRel" => "src/gtk-column-view.h",
    "implRel" => "src/gtk-column-view.c",
    "extraSource" => "src/gtk-column-view.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkColumnView",
    "symbolPrefix" => "phpgtk_gtkcolumnview_",
    "tokenPrefix" => "GTKCOLUMNVIEW",
], $argv[1] ?? "surface");
