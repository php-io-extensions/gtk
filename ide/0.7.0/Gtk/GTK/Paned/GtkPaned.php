<?php

namespace Gtk\GTK\Paned;

class GtkPaned
{
    public static function gtkPanedNew(int $orientation): int {}

    public static function gtkPanedSetStartChild(int $paned, int $child): void {}

    public static function gtkPanedSetEndChild(int $paned, int $child): void {}

    public static function gtkPanedGetStartChild(int $paned): int {}

    public static function gtkPanedGetEndChild(int $paned): int {}

    public static function gtkPanedSetPosition(int $paned, int $position): void {}

    public static function gtkPanedGetPosition(int $paned): int {}
}
