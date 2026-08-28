<?php
/**
 * End-to-end GtkTextMark C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkTextMark",
    "headerRel" => "src/gtk-text-mark.h",
    "implRel" => "src/gtk-text-mark.c",
    "extraSource" => "src/gtk-text-mark.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkTextMark",
    "symbolPrefix" => "phpgtk_gtktextmark_",
    "tokenPrefix" => "GTKTEXTMARK",
], $argv[1] ?? "surface");
