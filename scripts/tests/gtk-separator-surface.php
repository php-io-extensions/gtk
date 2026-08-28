#!/usr/bin/env php
<?php
/**
 * End-to-end GtkSeparator C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSeparator",
    "headerRel" => "src/gtk-separator.h",
    "implRel" => "src/gtk-separator.c",
    "extraSource" => "src/gtk-separator.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSeparator",
    "symbolPrefix" => "phpgtk_gtkseparator_",
    "tokenPrefix" => "GTKSEPARATOR",
], $argv[1] ?? "surface");
