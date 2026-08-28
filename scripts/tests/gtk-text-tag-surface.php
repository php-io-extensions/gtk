<?php
/**
 * End-to-end GtkTextTag C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkTextTag",
    "headerRel" => "src/gtk-text-tag.h",
    "implRel" => "src/gtk-text-tag.c",
    "extraSource" => "src/gtk-text-tag.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkTextTag",
    "symbolPrefix" => "phpgtk_gtktexttag_",
    "tokenPrefix" => "GTKTEXTTAG",
], $argv[1] ?? "surface");
