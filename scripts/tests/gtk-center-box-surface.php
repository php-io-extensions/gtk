#!/usr/bin/env php
<?php
/**
 * End-to-end GtkCenterBox C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkCenterBox",
    "headerRel" => "src/gtk-center-box.h",
    "implRel" => "src/gtk-center-box.c",
    "extraSource" => "src/gtk-center-box.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkCenterBox",
    "symbolPrefix" => "phpgtk_gtkcenterbox_",
    "tokenPrefix" => "GTKCENTERBOX",
], $argv[1] ?? "surface");
