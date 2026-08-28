#!/usr/bin/env php
<?php
/**
 * End-to-end GtkAdjustment C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkAdjustment",
    "headerRel" => "src/gtk-adjustment.h",
    "implRel" => "src/gtk-adjustment.c",
    "extraSource" => "src/gtk-adjustment.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkAdjustment",
    "symbolPrefix" => "phpgtk_gtkadjustment_",
    "tokenPrefix" => "GTKADJUSTMENT",
], $argv[1] ?? "surface");
