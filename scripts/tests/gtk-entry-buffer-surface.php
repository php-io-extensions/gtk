#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEntryBuffer C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEntryBuffer",
    "headerRel" => "src/gtk-entry-buffer.h",
    "implRel" => "src/gtk-entry-buffer.c",
    "extraSource" => "src/gtk-entry-buffer.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEntryBuffer",
    "symbolPrefix" => "phpgtk_gtkentrybuffer_",
    "tokenPrefix" => "GTKENTRYBUFFER",
], $argv[1] ?? "surface");
