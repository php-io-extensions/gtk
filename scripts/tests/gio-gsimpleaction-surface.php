#!/usr/bin/env php
<?php
/**
 * End-to-end GSimpleAction C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GSimpleAction",
    "headerRel" => "src/gio-gsimpleaction.h",
    "implRel" => "src/gio-gsimpleaction.c",
    "extraSource" => "src/gio-gsimpleaction.c",
    "girName" => "Gio-2.0",
    "cType" => "GSimpleAction",
    "symbolPrefix" => "phpgtk_gsimpleaction_",
    "tokenPrefix" => "GSIMPLEACTION",
], $argv[1] ?? "surface");
