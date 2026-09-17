#!/usr/bin/env php
<?php
/**
 * End-to-end GtkEventControllerKey C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkEventControllerKey",
    "headerRel" => "src/gtk-event-controller-key.h",
    "implRel" => "src/gtk-event-controller-key.c",
    "extraSource" => "src/gtk-event-controller-key.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkEventControllerKey",
    "symbolPrefix" => "phpgtk_gtkeventcontrollerkey_",
    "tokenPrefix" => "GTKEVENTCONTROLLERKEY",
], $argv[1] ?? "surface");
