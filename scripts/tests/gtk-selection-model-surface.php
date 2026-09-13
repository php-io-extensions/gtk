<?php
/**
 * End-to-end GtkSelectionModel C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSelectionModel",
    "headerRel" => "src/gtk-selection-model.h",
    "implRel" => "src/gtk-selection-model.c",
    "extraSource" => "src/gtk-selection-model.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSelectionModel",
    "symbolPrefix" => "phpgtk_gtkselectionmodel_",
    "tokenPrefix" => "GTKSELECTIONMODEL",
], $argv[1] ?? "surface");
