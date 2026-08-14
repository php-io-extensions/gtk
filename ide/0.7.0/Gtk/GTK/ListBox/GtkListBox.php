<?php

namespace Gtk\GTK\ListBox;

class GtkListBox
{
    public static function gtkListBoxNew(): int {}

    public static function gtkListBoxAppend(int $box, int $child): void {}

    public static function gtkListBoxRemove(int $box, int $child): void {}

    public static function gtkListBoxGetSelectedRow(int $box): int {}

    public static function gtkListBoxSelectRow(int $box, int $row): void {}

    public static function gtkListBoxGetRowAtIndex(int $box, int $index): int {}

    public static function gtkListBoxRowGetIndex(int $row): int {}

    public static function gtkListBoxRowGetChild(int $row): int {}
}
