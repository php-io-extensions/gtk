#!/usr/bin/env php
<?php
/**
 * End-to-end GtkStringObject C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkStringObject",
    "headerRel" => "src/gtk-string-object.h",
    "implRel" => "src/gtk-string-object.c",
    "extraSource" => "src/gtk-string-object.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStringObject",
    "symbolPrefix" => "phpgtk_gtkstringobject_",
    "tokenPrefix" => "GTKSTRINGOBJECT",
], $argv[1] ?? "surface");
