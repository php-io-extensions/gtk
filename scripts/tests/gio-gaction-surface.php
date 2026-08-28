#!/usr/bin/env php
<?php
/**
 * End-to-end GAction C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GAction",
    "headerRel" => "src/gio-gaction.h",
    "implRel" => "src/gio-gaction.c",
    "extraSource" => "src/gio-gaction.c",
    "girName" => "Gio-2.0",
    "cType" => "GAction",
    "symbolPrefix" => "phpgtk_gaction_",
    "tokenPrefix" => "GACTION",
], $argv[1] ?? "surface");
