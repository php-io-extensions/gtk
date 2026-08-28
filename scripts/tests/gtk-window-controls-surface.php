<?php
/**
 * End-to-end GtkWindowControls C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkWindowControls",
    "headerRel" => "src/gtk-window-controls.h",
    "implRel" => "src/gtk-window-controls.c",
    "extraSource" => "src/gtk-window-controls.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkWindowControls",
    "symbolPrefix" => "phpgtk_gtkwindowcontrols_",
    "tokenPrefix" => "GTKWINDOWCONTROLS",
], $argv[1] ?? "surface");
