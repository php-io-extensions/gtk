<?php

namespace Gtk\GTK\Box;

class GtkBox
{
    public static function gtkBoxNew(int $orientation, int $spacing): int {}

    public static function gtkBoxAppend(int $box, int $child): void {}

    public static function gtkBoxRemove(int $box, int $child): void {}

    public static function gtkBoxSetSpacing(int $box, int $spacing): void {}
}
