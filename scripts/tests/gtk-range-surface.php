#!/usr/bin/env php
<?php
/**
 * End-to-end GtkRange C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkRange",
    "headerRel" => "src/gtk-range.h",
    "implRel" => "src/gtk-range.c",
    "extraSource" => "src/gtk-range.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkRange",
    "symbolPrefix" => "phpgtk_gtkrange_",
    "tokenPrefix" => "GTKRANGE",
], $argv[1] ?? "surface");
