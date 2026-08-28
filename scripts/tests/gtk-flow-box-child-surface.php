<?php
/**
 * End-to-end GtkFlowBoxChild C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\GtkFlowBoxChild",
    "headerRel" => "src/gtk-flow-box-child.h",
    "implRel" => "src/gtk-flow-box-child.c",
    "extraSource" => "src/gtk-flow-box-child.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkFlowBoxChild",
    "symbolPrefix" => "phpgtk_gtkflowboxchild_",
    "tokenPrefix" => "GTKFLOWBOXCHILD",
], $argv[1] ?? "surface");
