<?php
/**
 * End-to-end GtkApplicationWindow C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkApplicationWindow",
    "headerRel" => "src/gtk-application-window.h",
    "implRel" => "src/gtk-application-window.c",
    "extraSource" => "src/gtk-application-window.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkApplicationWindow",
    "symbolPrefix" => "phpgtk_gtkapplicationwindow_",
    "tokenPrefix" => "GTKAPPLICATIONWINDOW",
], $argv[1] ?? "surface");
