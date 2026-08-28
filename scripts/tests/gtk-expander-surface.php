#!/usr/bin/env php
<?php
/**
 * End-to-end GtkExpander C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkExpander",
    "headerRel" => "src/gtk-expander.h",
    "implRel" => "src/gtk-expander.c",
    "extraSource" => "src/gtk-expander.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkExpander",
    "symbolPrefix" => "phpgtk_gtkexpander_",
    "tokenPrefix" => "GTKEXPANDER",
], $argv[1] ?? "surface");
