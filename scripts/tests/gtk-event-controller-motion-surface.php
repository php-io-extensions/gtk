#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEventControllerMotion C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEventControllerMotion",
    "headerRel" => "src/gtk-event-controller-motion.h",
    "implRel" => "src/gtk-event-controller-motion.c",
    "extraSource" => "src/gtk-event-controller-motion.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEventControllerMotion",
    "symbolPrefix" => "phpgtk_gtkeventcontrollermotion_",
    "tokenPrefix" => "GTKEVENTCONTROLLERMOTION",
], $argv[1] ?? "surface");
