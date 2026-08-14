<?php

namespace Gtk\GTK\HeaderBar;

class GtkHeaderBar
{
    public static function gtkHeaderBarNew(): int {}

    public static function gtkHeaderBarSetTitleWidget(int $bar, int $titleWidget): void {}

    public static function gtkHeaderBarGetTitleWidget(int $bar): int {}

    public static function gtkHeaderBarPackStart(int $bar, int $child): void {}

    public static function gtkHeaderBarPackEnd(int $bar, int $child): void {}

    public static function gtkHeaderBarRemove(int $bar, int $child): void {}

    public static function gtkHeaderBarSetShowTitleButtons(int $bar, bool $show): void {}

    public static function gtkHeaderBarGetShowTitleButtons(int $bar): bool {}
}
