<?php
/**
 * End-to-end GtkCalendar C-surface checks (Wave C).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkCalendar",
    "headerRel" => "src/gtk-calendar.h",
    "implRel" => "src/gtk-calendar.c",
    "extraSource" => "src/gtk-calendar.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkCalendar",
    "symbolPrefix" => "phpgtk_gtkcalendar_",
    "tokenPrefix" => "GTKCALENDAR",
], $argv[1] ?? "surface");
