<?php

namespace Gtk\GTK\ListItem;

class GtkListItem
{
    public static function gtkSignalListItemFactoryNew(): int {}

    public static function gtkListItemSetChild(int $item, int $child): void {}

    public static function gtkListItemGetChild(int $item): int {}

    public static function gtkListItemGetItem(int $item): int {}

    public static function gtkListItemGetPosition(int $item): int {}
}
