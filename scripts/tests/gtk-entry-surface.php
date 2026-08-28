#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEntry C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEntry",
    "headerRel" => "src/gtk-entry.h",
    "implRel" => "src/gtk-entry.c",
    "extraSource" => "src/gtk-entry.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEntry",
    "symbolPrefix" => "phpgtk_gtkentry_",
    "tokenPrefix" => "GTKENTRY",
], $argv[1] ?? "surface");
