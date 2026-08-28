#!/usr/bin/env php
<?php
/**
 * End-to-end GtkFrame C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkFrame",
    "headerRel" => "src/gtk-frame.h",
    "implRel" => "src/gtk-frame.c",
    "extraSource" => "src/gtk-frame.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkFrame",
    "symbolPrefix" => "phpgtk_gtkframe_",
    "tokenPrefix" => "GTKFRAME",
], $argv[1] ?? "surface");
