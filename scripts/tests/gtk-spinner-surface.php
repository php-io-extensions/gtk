#!/usr/bin/env php
<?php
/**
 * End-to-end GtkSpinner C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSpinner",
    "headerRel" => "src/gtk-spinner.h",
    "implRel" => "src/gtk-spinner.c",
    "extraSource" => "src/gtk-spinner.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSpinner",
    "symbolPrefix" => "phpgtk_gtkspinner_",
    "tokenPrefix" => "GTKSPINNER",
], $argv[1] ?? "surface");
