<?php

namespace Gtk\GTK\DropDown;

class GtkDropDown
{
    public static function gtkDropDownNewFromStrings(array $labels): int {}

    public static function gtkDropDownSetSelected(int $drop, int $selected): void {}

    public static function gtkDropDownGetSelected(int $drop): int {}
}
