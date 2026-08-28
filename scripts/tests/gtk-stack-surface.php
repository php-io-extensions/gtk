<?php
/**
 * End-to-end GtkStack C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkStack",
    "headerRel" => "src/gtk-stack.h",
    "implRel" => "src/gtk-stack.c",
    "extraSource" => "src/gtk-stack.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkStack",
    "symbolPrefix" => "phpgtk_gtkstack_",
    "tokenPrefix" => "GTKSTACK",
], $argv[1] ?? "surface");
