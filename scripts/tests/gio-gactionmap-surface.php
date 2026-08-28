#!/usr/bin/env php
<?php
/**
 * End-to-end GActionMap C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GActionMap",
    "headerRel" => "src/gio-gactionmap.h",
    "implRel" => "src/gio-gactionmap.c",
    "extraSource" => "src/gio-gactionmap.c",
    "girName" => "Gio-2.0",
    "cType" => "GActionMap",
    "symbolPrefix" => "phpgtk_gactionmap_",
    "tokenPrefix" => "GACTIONMAP",
], $argv[1] ?? "surface");
