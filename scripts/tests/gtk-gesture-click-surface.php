#!/usr/bin/env php
<?php
/**
 * End-to-end GtkGestureClick C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkGestureClick",
    "headerRel" => "src/gtk-gesture-click.h",
    "implRel" => "src/gtk-gesture-click.c",
    "extraSource" => "src/gtk-gesture-click.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkGestureClick",
    "symbolPrefix" => "phpgtk_gtkgestureclick_",
    "tokenPrefix" => "GTKGESTURECLICK",
], $argv[1] ?? "surface");
