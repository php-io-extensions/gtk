#!/usr/bin/env php
<?php
/**
 * End-to-end GtkScale C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkScale",
    "headerRel" => "src/gtk-scale.h",
    "implRel" => "src/gtk-scale.c",
    "extraSource" => "src/gtk-scale.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkScale",
    "symbolPrefix" => "phpgtk_gtkscale_",
    "tokenPrefix" => "GTKSCALE",
], $argv[1] ?? "surface");
