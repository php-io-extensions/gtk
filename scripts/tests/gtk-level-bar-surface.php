#!/usr/bin/env php
<?php
/**
 * End-to-end GtkLevelBar C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkLevelBar",
    "headerRel" => "src/gtk-level-bar.h",
    "implRel" => "src/gtk-level-bar.c",
    "extraSource" => "src/gtk-level-bar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkLevelBar",
    "symbolPrefix" => "phpgtk_gtklevelbar_",
    "tokenPrefix" => "GTKLEVELBAR",
], $argv[1] ?? "surface");
