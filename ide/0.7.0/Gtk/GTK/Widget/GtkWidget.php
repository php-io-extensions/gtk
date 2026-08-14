<?php

namespace Gtk\GTK\Widget;

class GtkWidget
{
    public static function gtkWidgetSetVisible(int $widget, bool $visible): void {}

    public static function gtkWidgetGetVisible(int $widget): bool {}

    public static function gtkWidgetSetHexpand(int $widget, bool $expand): void {}

    public static function gtkWidgetSetVexpand(int $widget, bool $expand): void {}

    public static function gtkWidgetSetHalign(int $widget, int $align): void {}

    public static function gtkWidgetSetValign(int $widget, int $align): void {}

    public static function gtkWidgetGetHalign(int $widget): int {}

    public static function gtkWidgetGetValign(int $widget): int {}

    public static function gtkWidgetSetSizeRequest(int $widget, int $width, int $height): void {}

    public static function gtkWidgetGetWidth(int $widget): int {}

    public static function gtkWidgetGetHeight(int $widget): int {}

    public static function gtkWidgetQueueDraw(int $widget): void {}

    public static function gtkWidgetAddTickCallback(int $widget, callable $callback): int {}
}
