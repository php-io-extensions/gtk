#!/usr/bin/env php
<?php
/**
 * End-to-end GtkRevealer C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkRevealer",
    "headerRel" => "src/gtk-revealer.h",
    "implRel" => "src/gtk-revealer.c",
    "extraSource" => "src/gtk-revealer.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkRevealer",
    "symbolPrefix" => "phpgtk_gtkrevealer_",
    "tokenPrefix" => "GTKREVEALER",
], $argv[1] ?? "surface");
