<?php

namespace Gtk\GTK\Scale;

class GtkScale
{
    public static function gtkScaleNewWithRange(int $orientation, float $min, float $max, float $step): int {}

    public static function gtkScaleSetValue(int $scale, float $value): void {}

    public static function gtkScaleGetValue(int $scale): float {}

    public static function gtkScaleSetDrawValue(int $scale, bool $drawValue): void {}

    public static function gtkScaleSetDigits(int $scale, int $digits): void {}
}
