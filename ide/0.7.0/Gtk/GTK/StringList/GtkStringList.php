<?php

namespace Gtk\GTK\StringList;

class GtkStringList
{
    public static function gtkStringListNew(array $strings): int {}

    public static function gtkStringListAppend(int $list, string $value): void {}

    public static function gtkStringListRemove(int $list, int $position): void {}

    public static function gtkStringListGetString(int $list, int $position): string {}

    public static function gtkStringListGetNItems(int $list): int {}

    public static function gtkStringObjectGetString(int $item): string {}
}
