#!/usr/bin/env php
<?php
/**
 * End-to-end Gio\GApplication C-surface checks.
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gio\\GApplication',
    'headerRel' => 'src/gio-gapplication.h',
    'implRel' => 'src/gio-gapplication.c',
    'extraSource' => 'src/gio-gapplication.c',
    'girName' => 'Gio-2.0',
    'cType' => 'GApplication',
    'symbolPrefix' => 'phpgtk_gapplication_',
    'tokenPrefix' => 'GAPPLICATION',
], $argv[1] ?? 'surface');
