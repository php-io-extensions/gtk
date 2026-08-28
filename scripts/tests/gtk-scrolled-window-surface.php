#!/usr/bin/env php
<?php
/**
 * End-to-end GtkScrolledWindow C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkScrolledWindow",
    "headerRel" => "src/gtk-scrolled-window.h",
    "implRel" => "src/gtk-scrolled-window.c",
    "extraSource" => "src/gtk-scrolled-window.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkScrolledWindow",
    "symbolPrefix" => "phpgtk_gtkscrolledwindow_",
    "tokenPrefix" => "GTKSCROLLEDWINDOW",
], $argv[1] ?? "surface");
