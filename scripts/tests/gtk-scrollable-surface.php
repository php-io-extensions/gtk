#!/usr/bin/env php
<?php
/**
 * End-to-end GtkScrollable C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkScrollable",
    "headerRel" => "src/gtk-scrollable.h",
    "implRel" => "src/gtk-scrollable.c",
    "extraSource" => "src/gtk-scrollable.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkScrollable",
    "symbolPrefix" => "phpgtk_gtkscrollable_",
    "tokenPrefix" => "GTKSCROLLABLE",
], $argv[1] ?? "surface");
