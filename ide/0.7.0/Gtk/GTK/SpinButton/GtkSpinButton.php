<?php

namespace Gtk\GTK\SpinButton;

class GtkSpinButton
{
    public static function gtkSpinButtonNewWithRange(float $min, float $max, float $step): int {}

    public static function gtkSpinButtonSetValue(int $spin, float $value): void {}

    public static function gtkSpinButtonGetValue(int $spin): float {}

    public static function gtkSpinButtonGetValueAsInt(int $spin): int {}

    public static function gtkSpinButtonSetDigits(int $spin, int $digits): void {}
}
