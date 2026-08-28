#!/usr/bin/env php
<?php
/**
 * End-to-end GtkSearchEntry C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSearchEntry",
    "headerRel" => "src/gtk-search-entry.h",
    "implRel" => "src/gtk-search-entry.c",
    "extraSource" => "src/gtk-search-entry.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSearchEntry",
    "symbolPrefix" => "phpgtk_gtksearchentry_",
    "tokenPrefix" => "GTKSEARCHENTRY",
], $argv[1] ?? "surface");
