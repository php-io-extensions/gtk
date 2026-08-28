#!/usr/bin/env php
<?php
/**
 * End-to-end GtkText C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkText",
    "headerRel" => "src/gtk-text.h",
    "implRel" => "src/gtk-text.c",
    "extraSource" => "src/gtk-text.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkText",
    "symbolPrefix" => "phpgtk_gtktext_",
    "tokenPrefix" => "GTKTEXT",
], $argv[1] ?? "surface");
