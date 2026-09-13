<?php
/**
 * End-to-end GtkListItem C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkListItem",
    "headerRel" => "src/gtk-list-item.h",
    "implRel" => "src/gtk-list-item.c",
    "extraSource" => "src/gtk-list-item.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkListItem",
    "symbolPrefix" => "phpgtk_gtklistitem_",
    "tokenPrefix" => "GTKLISTITEM",
], $argv[1] ?? "surface");
