<?php
/**
 * End-to-end GtkStackPage C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkStackPage",
    "headerRel" => "src/gtk-stack-page.h",
    "implRel" => "src/gtk-stack-page.c",
    "extraSource" => "src/gtk-stack-page.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStackPage",
    "symbolPrefix" => "phpgtk_gtkstackpage_",
    "tokenPrefix" => "GTKSTACKPAGE",
], $argv[1] ?? "surface");
