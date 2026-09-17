#!/usr/bin/env php
<?php
/**
 * End-to-end GtkGesture C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkGesture",
    "headerRel" => "src/gtk-gesture.h",
    "implRel" => "src/gtk-gesture.c",
    "extraSource" => "src/gtk-gesture.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkGesture",
    "symbolPrefix" => "phpgtk_gtkgesture_",
    "tokenPrefix" => "GTKGESTURE",
], $argv[1] ?? "surface");
