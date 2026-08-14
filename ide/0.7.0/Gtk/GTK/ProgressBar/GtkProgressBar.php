<?php

namespace Gtk\GTK\ProgressBar;

class GtkProgressBar
{
    public static function gtkProgressBarNew(): int {}

    public static function gtkProgressBarSetFraction(int $bar, float $fraction): void {}

    public static function gtkProgressBarGetFraction(int $bar): float {}

    public static function gtkProgressBarSetText(int $bar, string $text): void {}

    public static function gtkProgressBarGetText(int $bar): string {}

    public static function gtkProgressBarSetShowText(int $bar, bool $showText): void {}

    public static function gtkProgressBarPulse(int $bar): void {}
}
