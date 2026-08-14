<?php

namespace Gtk\GTK\ToggleButton;

class GtkToggleButton
{
    public static function gtkToggleButtonNew(): int {}

    public static function gtkToggleButtonNewWithLabel(string $label): int {}

    public static function gtkToggleButtonSetActive(int $button, bool $active): void {}

    public static function gtkToggleButtonGetActive(int $button): bool {}

    public static function gtkToggleButtonSetLabel(int $button, string $label): void {}

    public static function gtkToggleButtonGetLabel(int $button): string {}
}
