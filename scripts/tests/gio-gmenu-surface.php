#!/usr/bin/env php
<?php
/**
 * End-to-end GMenu C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GMenu",
    "headerRel" => "src/gio-gmenu.h",
    "implRel" => "src/gio-gmenu.c",
    "extraSource" => "src/gio-gmenu.c",
    "girName" => "Gio-2.0",
    "cType" => "GMenu",
    "symbolPrefix" => "phpgtk_gmenu_",
    "tokenPrefix" => "GMENU",
], $argv[1] ?? "surface");
