<?php
/**
 * End-to-end GtkTextTagTable C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkTextTagTable",
    "headerRel" => "src/gtk-text-tag-table.h",
    "implRel" => "src/gtk-text-tag-table.c",
    "extraSource" => "src/gtk-text-tag-table.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkTextTagTable",
    "symbolPrefix" => "phpgtk_gtktexttagtable_",
    "tokenPrefix" => "GTKTEXTTAGTABLE",
], $argv[1] ?? "surface");
