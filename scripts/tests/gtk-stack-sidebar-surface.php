<?php
/**
 * End-to-end GtkStackSidebar C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkStackSidebar",
    "headerRel" => "src/gtk-stack-sidebar.h",
    "implRel" => "src/gtk-stack-sidebar.c",
    "extraSource" => "src/gtk-stack-sidebar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStackSidebar",
    "symbolPrefix" => "phpgtk_gtkstacksidebar_",
    "tokenPrefix" => "GTKSTACKSIDEBAR",
], $argv[1] ?? "surface");
