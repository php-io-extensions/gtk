<?php

namespace Gtk\GTK\Entry;

class GtkEntry
{
    public static function gtkEntryNew(): int {}

    public static function gtkEntrySetText(int $entry, string $text): void {}

    public static function gtkEntryGetText(int $entry): string {}

    public static function gtkEntrySetPlaceholderText(int $entry, string $text): void {}

    public static function gtkEntryGetPlaceholderText(int $entry): string {}

    public static function gtkEntrySetVisibility(int $entry, bool $visible): void {}

    public static function gtkEntryGetVisibility(int $entry): bool {}
}
