#!/usr/bin/env php
<?php
/**
 * End-to-end GtkGrid C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkGrid",
    "headerRel" => "src/gtk-grid.h",
    "implRel" => "src/gtk-grid.c",
    "extraSource" => "src/gtk-grid.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkGrid",
    "symbolPrefix" => "phpgtk_gtkgrid_",
    "tokenPrefix" => "GTKGRID",
], $argv[1] ?? "surface");
