#!/usr/bin/env php
<?php
/**
 * End-to-end GMenuModel C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GMenuModel",
    "headerRel" => "src/gio-gmenumodel.h",
    "implRel" => "src/gio-gmenumodel.c",
    "extraSource" => "src/gio-gmenumodel.c",
    "girName" => "Gio-2.0",
    "cType" => "GMenuModel",
    "symbolPrefix" => "phpgtk_gmenumodel_",
    "tokenPrefix" => "GMENUMODEL",
], $argv[1] ?? "surface");
