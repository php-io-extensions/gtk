#!/usr/bin/env php
<?php
/**
 * End-to-end GtkSwitch C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSwitch",
    "headerRel" => "src/gtk-switch.h",
    "implRel" => "src/gtk-switch.c",
    "extraSource" => "src/gtk-switch.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSwitch",
    "symbolPrefix" => "phpgtk_gtkswitch_",
    "tokenPrefix" => "GTKSWITCH",
], $argv[1] ?? "surface");
