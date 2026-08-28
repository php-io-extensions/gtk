<?php
/**
 * End-to-end GtkStackSwitcher C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkStackSwitcher",
    "headerRel" => "src/gtk-stack-switcher.h",
    "implRel" => "src/gtk-stack-switcher.c",
    "extraSource" => "src/gtk-stack-switcher.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStackSwitcher",
    "symbolPrefix" => "phpgtk_gtkstackswitcher_",
    "tokenPrefix" => "GTKSTACKSWITCHER",
], $argv[1] ?? "surface");
