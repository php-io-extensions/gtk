#!/usr/bin/env php
<?php
/**
 * End-to-end GtkActionable C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkActionable",
    "headerRel" => "src/gtk-actionable.h",
    "implRel" => "src/gtk-actionable.c",
    "extraSource" => "src/gtk-actionable.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkActionable",
    "symbolPrefix" => "phpgtk_gtkactionable_",
    "tokenPrefix" => "GTKACTIONABLE",
], $argv[1] ?? "surface");
