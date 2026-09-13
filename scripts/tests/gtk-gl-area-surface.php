#!/usr/bin/env php
<?php
/**
 * End-to-end GtkGLArea C-surface checks (GL wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkGLArea",
    "headerRel" => "src/gtk-gl-area.h",
    "implRel" => "src/gtk-gl-area.c",
    "extraSource" => "src/gtk-gl-area.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkGLArea",
    "symbolPrefix" => "phpgtk_gtkglarea_",
    "tokenPrefix" => "GTKGLAREA",
], $argv[1] ?? "surface");
