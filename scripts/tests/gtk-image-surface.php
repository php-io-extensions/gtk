#!/usr/bin/env php
<?php
/**
 * End-to-end GtkImage C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkImage",
    "headerRel" => "src/gtk-image.h",
    "implRel" => "src/gtk-image.c",
    "extraSource" => "src/gtk-image.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkImage",
    "symbolPrefix" => "phpgtk_gtkimage_",
    "tokenPrefix" => "GTKIMAGE",
], $argv[1] ?? "surface");
