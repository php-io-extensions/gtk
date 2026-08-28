#!/usr/bin/env php
<?php
/**
 * End-to-end GtkScrollbar C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkScrollbar",
    "headerRel" => "src/gtk-scrollbar.h",
    "implRel" => "src/gtk-scrollbar.c",
    "extraSource" => "src/gtk-scrollbar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkScrollbar",
    "symbolPrefix" => "phpgtk_gtkscrollbar_",
    "tokenPrefix" => "GTKSCROLLBAR",
], $argv[1] ?? "surface");
