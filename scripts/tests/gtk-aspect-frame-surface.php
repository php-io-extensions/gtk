#!/usr/bin/env php
<?php
/**
 * End-to-end GtkAspectFrame C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkAspectFrame",
    "headerRel" => "src/gtk-aspect-frame.h",
    "implRel" => "src/gtk-aspect-frame.c",
    "extraSource" => "src/gtk-aspect-frame.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkAspectFrame",
    "symbolPrefix" => "phpgtk_gtkaspectframe_",
    "tokenPrefix" => "GTKASPECTFRAME",
], $argv[1] ?? "surface");
