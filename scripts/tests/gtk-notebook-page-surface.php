<?php
/**
 * End-to-end GtkNotebookPage C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkNotebookPage",
    "headerRel" => "src/gtk-notebook-page.h",
    "implRel" => "src/gtk-notebook-page.c",
    "extraSource" => "src/gtk-notebook-page.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkNotebookPage",
    "symbolPrefix" => "phpgtk_gtknotebookpage_",
    "tokenPrefix" => "GTKNOTEBOOKPAGE",
], $argv[1] ?? "surface");
