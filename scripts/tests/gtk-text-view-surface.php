<?php
/**
 * End-to-end GtkTextView C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkTextView",
    "headerRel" => "src/gtk-text-view.h",
    "implRel" => "src/gtk-text-view.c",
    "extraSource" => "src/gtk-text-view.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkTextView",
    "symbolPrefix" => "phpgtk_gtktextview_",
    "tokenPrefix" => "GTKTEXTVIEW",
], $argv[1] ?? "surface");
