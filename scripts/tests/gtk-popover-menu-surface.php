<?php
/**
 * End-to-end GtkPopoverMenu C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkPopoverMenu",
    "headerRel" => "src/gtk-popover-menu.h",
    "implRel" => "src/gtk-popover-menu.c",
    "extraSource" => "src/gtk-popover-menu.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkPopoverMenu",
    "symbolPrefix" => "phpgtk_gtkpopovermenu_",
    "tokenPrefix" => "GTKPOPOVERMENU",
], $argv[1] ?? "surface");
