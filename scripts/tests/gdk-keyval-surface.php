#!/usr/bin/env php
<?php
/**
 * End-to-end GdkKeyval C-surface checks (input wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gdk\\GdkKeyval",
    "headerRel" => "src/gdk-keyval.h",
    "implRel" => "src/gdk-keyval.c",
    "extraSource" => "src/gdk-keyval.c",
    "girName" => "Gdk-4.0",
    "cType" => "GdkKeyval",
    "symbolPrefix" => "phpgtk_gdkkeyval_",
    "tokenPrefix" => "GDKKEYVAL",
    "functionPrefixes" => ["gdk_keyval_", "gdk_unicode_to_keyval"],
], $argv[1] ?? "surface");
