<?php

namespace Gtk\GTK\CenterBox;

class GtkCenterBox
{
    public static function gtkCenterBoxNew(): int {}

    public static function gtkCenterBoxSetStartWidget(int $box, int $child): void {}

    public static function gtkCenterBoxSetCenterWidget(int $box, int $child): void {}

    public static function gtkCenterBoxSetEndWidget(int $box, int $child): void {}

    public static function gtkCenterBoxGetStartWidget(int $box): int {}

    public static function gtkCenterBoxGetCenterWidget(int $box): int {}

    public static function gtkCenterBoxGetEndWidget(int $box): int {}
}
