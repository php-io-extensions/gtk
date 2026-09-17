#!/usr/bin/env php
<?php
/**
 * End-to-end GtkGestureSingle C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkGestureSingle",
    "headerRel" => "src/gtk-gesture-single.h",
    "implRel" => "src/gtk-gesture-single.c",
    "extraSource" => "src/gtk-gesture-single.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkGestureSingle",
    "symbolPrefix" => "phpgtk_gtkgesturesingle_",
    "tokenPrefix" => "GTKGESTURESINGLE",
], $argv[1] ?? "surface");
