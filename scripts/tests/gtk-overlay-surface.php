#!/usr/bin/env php
<?php
/**
 * End-to-end GtkOverlay C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkOverlay",
    "headerRel" => "src/gtk-overlay.h",
    "implRel" => "src/gtk-overlay.c",
    "extraSource" => "src/gtk-overlay.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkOverlay",
    "symbolPrefix" => "phpgtk_gtkoverlay_",
    "tokenPrefix" => "GTKOVERLAY",
], $argv[1] ?? "surface");
