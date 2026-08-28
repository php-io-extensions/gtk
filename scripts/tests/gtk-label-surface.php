#!/usr/bin/env php
<?php
/**
 * End-to-end GtkLabel C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkLabel",
    "headerRel" => "src/gtk-label.h",
    "implRel" => "src/gtk-label.c",
    "extraSource" => "src/gtk-label.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkLabel",
    "symbolPrefix" => "phpgtk_gtklabel_",
    "tokenPrefix" => "GTKLABEL",
], $argv[1] ?? "surface");
