<?php
/**
 * End-to-end GtkListBox C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkListBox",
    "headerRel" => "src/gtk-list-box.h",
    "implRel" => "src/gtk-list-box.c",
    "extraSource" => "src/gtk-list-box.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkListBox",
    "symbolPrefix" => "phpgtk_gtklistbox_",
    "tokenPrefix" => "GTKLISTBOX",
], $argv[1] ?? "surface");
