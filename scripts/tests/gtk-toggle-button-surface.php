#!/usr/bin/env php
<?php
/**
 * End-to-end GtkToggleButton C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkToggleButton",
    "headerRel" => "src/gtk-toggle-button.h",
    "implRel" => "src/gtk-toggle-button.c",
    "extraSource" => "src/gtk-toggle-button.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkToggleButton",
    "symbolPrefix" => "phpgtk_gtktogglebutton_",
    "tokenPrefix" => "GTKTOGGLEBUTTON",
], $argv[1] ?? "surface");
