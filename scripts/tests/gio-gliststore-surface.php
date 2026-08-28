#!/usr/bin/env php
<?php
/**
 * End-to-end GListStore C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GListStore",
    "headerRel" => "src/gio-gliststore.h",
    "implRel" => "src/gio-gliststore.c",
    "extraSource" => "src/gio-gliststore.c",
    "girName" => "Gio-2.0",
    "cType" => "GListStore",
    "symbolPrefix" => "phpgtk_gliststore_",
    "tokenPrefix" => "GLISTSTORE",
], $argv[1] ?? "surface");
