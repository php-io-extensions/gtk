#!/usr/bin/env php
<?php
/**
 * End-to-end GMenuItem C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GMenuItem",
    "headerRel" => "src/gio-gmenuitem.h",
    "implRel" => "src/gio-gmenuitem.c",
    "extraSource" => "src/gio-gmenuitem.c",
    "girName" => "Gio-2.0",
    "cType" => "GMenuItem",
    "symbolPrefix" => "phpgtk_gmenuitem_",
    "tokenPrefix" => "GMENUITEM",
], $argv[1] ?? "surface");
