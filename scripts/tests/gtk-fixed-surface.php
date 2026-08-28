#!/usr/bin/env php
<?php
/**
 * End-to-end GtkFixed C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkFixed",
    "headerRel" => "src/gtk-fixed.h",
    "implRel" => "src/gtk-fixed.c",
    "extraSource" => "src/gtk-fixed.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkFixed",
    "symbolPrefix" => "phpgtk_gtkfixed_",
    "tokenPrefix" => "GTKFIXED",
], $argv[1] ?? "surface");
