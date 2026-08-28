<?php
/**
 * End-to-end GtkListBoxRow C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkListBoxRow",
    "headerRel" => "src/gtk-list-box-row.h",
    "implRel" => "src/gtk-list-box-row.c",
    "extraSource" => "src/gtk-list-box-row.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkListBoxRow",
    "symbolPrefix" => "phpgtk_gtklistboxrow_",
    "tokenPrefix" => "GTKLISTBOXROW",
], $argv[1] ?? "surface");
