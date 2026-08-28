#!/usr/bin/env php
<?php
/**
 * End-to-end GtkPicture C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkPicture",
    "headerRel" => "src/gtk-picture.h",
    "implRel" => "src/gtk-picture.c",
    "extraSource" => "src/gtk-picture.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPicture",
    "symbolPrefix" => "phpgtk_gtkpicture_",
    "tokenPrefix" => "GTKPICTURE",
], $argv[1] ?? "surface");
