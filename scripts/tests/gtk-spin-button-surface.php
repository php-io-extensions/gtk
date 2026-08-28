#!/usr/bin/env php
<?php
/**
 * End-to-end GtkSpinButton C-surface checks (Wave A).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkSpinButton",
    "headerRel" => "src/gtk-spin-button.h",
    "implRel" => "src/gtk-spin-button.c",
    "extraSource" => "src/gtk-spin-button.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkSpinButton",
    "symbolPrefix" => "phpgtk_gtkspinbutton_",
    "tokenPrefix" => "GTKSPINBUTTON",
], $argv[1] ?? "surface");
