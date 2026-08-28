<?php
/**
 * End-to-end GtkPaned C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkPaned",
    "headerRel" => "src/gtk-paned.h",
    "implRel" => "src/gtk-paned.c",
    "extraSource" => "src/gtk-paned.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPaned",
    "symbolPrefix" => "phpgtk_gtkpaned_",
    "tokenPrefix" => "GTKPANED",
], $argv[1] ?? "surface");
