<?php
/**
 * End-to-end GtkTextBuffer C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkTextBuffer",
    "headerRel" => "src/gtk-text-buffer.h",
    "implRel" => "src/gtk-text-buffer.c",
    "extraSource" => "src/gtk-text-buffer.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkTextBuffer",
    "symbolPrefix" => "phpgtk_gtktextbuffer_",
    "tokenPrefix" => "GTKTEXTBUFFER",
], $argv[1] ?? "surface");
