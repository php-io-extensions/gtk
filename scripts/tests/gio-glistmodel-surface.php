#!/usr/bin/env php
<?php
/**
 * End-to-end GListModel C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gio\\GListModel",
    "headerRel" => "src/gio-glistmodel.h",
    "implRel" => "src/gio-glistmodel.c",
    "extraSource" => "src/gio-glistmodel.c",
    "girName" => "Gio-2.0",
    "cType" => "GListModel",
    "symbolPrefix" => "phpgtk_glistmodel_",
    "tokenPrefix" => "GLISTMODEL",
], $argv[1] ?? "surface");
