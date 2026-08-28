#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEditable C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEditable",
    "headerRel" => "src/gtk-editable.h",
    "implRel" => "src/gtk-editable.c",
    "extraSource" => "src/gtk-editable.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEditable",
    "symbolPrefix" => "phpgtk_gtkeditable_",
    "tokenPrefix" => "GTKEDITABLE",
], $argv[1] ?? "surface");
