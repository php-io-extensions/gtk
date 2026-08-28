#!/usr/bin/env php
<?php
/**
 * End-to-end GtkPasswordEntry C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkPasswordEntry",
    "headerRel" => "src/gtk-password-entry.h",
    "implRel" => "src/gtk-password-entry.c",
    "extraSource" => "src/gtk-password-entry.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPasswordEntry",
    "symbolPrefix" => "phpgtk_gtkpasswordentry_",
    "tokenPrefix" => "GTKPASSWORDENTRY",
], $argv[1] ?? "surface");
