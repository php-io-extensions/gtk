<?php
/**
 * End-to-end GtkFlowBox C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkFlowBox",
    "headerRel" => "src/gtk-flow-box.h",
    "implRel" => "src/gtk-flow-box.c",
    "extraSource" => "src/gtk-flow-box.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkFlowBox",
    "symbolPrefix" => "phpgtk_gtkflowbox_",
    "tokenPrefix" => "GTKFLOWBOX",
], $argv[1] ?? "surface");
