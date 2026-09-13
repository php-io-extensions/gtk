#!/usr/bin/env php
<?php
/**
 * End-to-end GdkGLContext C-surface checks (GL wave).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gdk\\GdkGLContext",
    "headerRel" => "src/gdk-gl-context.h",
    "implRel" => "src/gdk-gl-context.c",
    "extraSource" => "src/gdk-gl-context.c",
    "girName" => "Gdk-4.0",
    "cType" => "GdkGLContext",
    "symbolPrefix" => "phpgtk_gdkglcontext_",
    "tokenPrefix" => "GDKGLCONTEXT",
], $argv[1] ?? "surface");
