<?php
/**
 * End-to-end GtkNotebook C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkNotebook",
    "headerRel" => "src/gtk-notebook.h",
    "implRel" => "src/gtk-notebook.c",
    "extraSource" => "src/gtk-notebook.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkNotebook",
    "symbolPrefix" => "phpgtk_gtknotebook_",
    "tokenPrefix" => "GTKNOTEBOOK",
], $argv[1] ?? "surface");
