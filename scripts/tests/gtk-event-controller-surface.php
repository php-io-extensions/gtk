#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEventController C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEventController",
    "headerRel" => "src/gtk-event-controller.h",
    "implRel" => "src/gtk-event-controller.c",
    "extraSource" => "src/gtk-event-controller.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEventController",
    "symbolPrefix" => "phpgtk_gtkeventcontroller_",
    "tokenPrefix" => "GTKEVENTCONTROLLER",
], $argv[1] ?? "surface");
