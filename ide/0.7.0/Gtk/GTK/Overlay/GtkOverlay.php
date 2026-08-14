<?php

namespace Gtk\GTK\Overlay;

class GtkOverlay
{
    public static function gtkOverlayNew(): int {}

    public static function gtkOverlaySetChild(int $overlay, int $child): void {}

    public static function gtkOverlayGetChild(int $overlay): int {}

    public static function gtkOverlayAddOverlay(int $overlay, int $child): void {}

    public static function gtkOverlayRemoveOverlay(int $overlay, int $child): void {}
}
