<?php

namespace Gtk\GTK\SearchEntry;

class GtkSearchEntry
{
    public static function gtkSearchEntryNew(): int {}

    public static function gtkSearchEntrySetText(int $entry, string $text): void {}

    public static function gtkSearchEntryGetText(int $entry): string {}
}
