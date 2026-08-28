#!/usr/bin/env php
<?php
/**
 * End-to-end GtkProgressBar C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkProgressBar",
    "headerRel" => "src/gtk-progress-bar.h",
    "implRel" => "src/gtk-progress-bar.c",
    "extraSource" => "src/gtk-progress-bar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkProgressBar",
    "symbolPrefix" => "phpgtk_gtkprogressbar_",
    "tokenPrefix" => "GTKPROGRESSBAR",
], $argv[1] ?? "surface");
