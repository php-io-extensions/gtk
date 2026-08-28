#!/usr/bin/env php
<?php
/**
 * End-to-end GtkCheckButton C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkCheckButton",
    "headerRel" => "src/gtk-check-button.h",
    "implRel" => "src/gtk-check-button.c",
    "extraSource" => "src/gtk-check-button.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkCheckButton",
    "symbolPrefix" => "phpgtk_gtkcheckbutton_",
    "tokenPrefix" => "GTKCHECKBUTTON",
], $argv[1] ?? "surface");
