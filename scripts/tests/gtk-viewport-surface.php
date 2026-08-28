#!/usr/bin/env php
<?php
/**
 * End-to-end GtkViewport C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkViewport",
    "headerRel" => "src/gtk-viewport.h",
    "implRel" => "src/gtk-viewport.c",
    "extraSource" => "src/gtk-viewport.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkViewport",
    "symbolPrefix" => "phpgtk_gtkviewport_",
    "tokenPrefix" => "GTKVIEWPORT",
], $argv[1] ?? "surface");
