<?php
/**
 * End-to-end GtkHeaderBar C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkHeaderBar",
    "headerRel" => "src/gtk-header-bar.h",
    "implRel" => "src/gtk-header-bar.c",
    "extraSource" => "src/gtk-header-bar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkHeaderBar",
    "symbolPrefix" => "phpgtk_gtkheaderbar_",
    "tokenPrefix" => "GTKHEADERBAR",
], $argv[1] ?? "surface");
