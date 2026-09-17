#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEventControllerScroll C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEventControllerScroll",
    "headerRel" => "src/gtk-event-controller-scroll.h",
    "implRel" => "src/gtk-event-controller-scroll.c",
    "extraSource" => "src/gtk-event-controller-scroll.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEventControllerScroll",
    "symbolPrefix" => "phpgtk_gtkeventcontrollerscroll_",
    "tokenPrefix" => "GTKEVENTCONTROLLERSCROLL",
], $argv[1] ?? "surface");
