<?php

namespace Gtk\GTK;

class GtkGLib
{
    public static function gObjectRef(int $instance): int {}

    public static function gObjectUnref(int $instance): void {}

    public static function gSignalConnect(int $instance, string $signal, callable $callback): int {}

    public static function gMainContextDefault(): int {}

    public static function gMainContextIteration(int $context, bool $mayBlock): bool {}
}
