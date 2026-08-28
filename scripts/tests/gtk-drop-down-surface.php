<?php
/**
 * End-to-end GtkDropDown C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkDropDown",
    "headerRel" => "src/gtk-drop-down.h",
    "implRel" => "src/gtk-drop-down.c",
    "extraSource" => "src/gtk-drop-down.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkDropDown",
    "symbolPrefix" => "phpgtk_gtkdropdown_",
    "tokenPrefix" => "GTKDROPDOWN",
], $argv[1] ?? "surface");
