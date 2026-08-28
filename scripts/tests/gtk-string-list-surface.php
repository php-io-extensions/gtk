#!/usr/bin/env php
<?php
/**
 * End-to-end GtkStringList C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkStringList",
    "headerRel" => "src/gtk-string-list.h",
    "implRel" => "src/gtk-string-list.c",
    "extraSource" => "src/gtk-string-list.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStringList",
    "symbolPrefix" => "phpgtk_gtkstringlist_",
    "tokenPrefix" => "GTKSTRINGLIST",
], $argv[1] ?? "surface");
