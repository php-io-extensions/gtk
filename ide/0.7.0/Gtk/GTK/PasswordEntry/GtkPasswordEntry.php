<?php

namespace Gtk\GTK\PasswordEntry;

class GtkPasswordEntry
{
    public static function gtkPasswordEntryNew(): int {}

    public static function gtkPasswordEntrySetText(int $entry, string $text): void {}

    public static function gtkPasswordEntryGetText(int $entry): string {}

    public static function gtkPasswordEntrySetShowPeekIcon(int $entry, bool $showPeek): void {}

    public static function gtkPasswordEntryGetShowPeekIcon(int $entry): bool {}
}
