<?php

namespace Gtk\GTK\Stack;

class GtkStack
{
    public static function gtkStackNew(): int {}

    public static function gtkStackAddChild(int $stack, int $child): void {}

    public static function gtkStackAddTitled(int $stack, int $child, string $name, string $title): void {}

    public static function gtkStackRemove(int $stack, int $child): void {}

    public static function gtkStackSetVisibleChild(int $stack, int $child): void {}

    public static function gtkStackGetVisibleChild(int $stack): int {}

    public static function gtkStackSetVisibleChildName(int $stack, string $name): void {}

    public static function gtkStackGetVisibleChildName(int $stack): string {}
}
