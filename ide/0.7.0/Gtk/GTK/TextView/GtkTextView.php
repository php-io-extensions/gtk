<?php

namespace Gtk\GTK\TextView;

class GtkTextView
{
    public static function gtkTextViewNew(): int {}

    public static function gtkTextViewGetBuffer(int $view): int {}

    public static function gtkTextViewSetText(int $view, string $text): void {}

    public static function gtkTextViewGetText(int $view): string {}

    public static function gtkTextViewSetEditable(int $view, bool $editable): void {}

    public static function gtkTextViewGetEditable(int $view): bool {}

    public static function gtkTextViewSetWrapMode(int $view, int $wrapMode): void {}

    public static function gtkTextViewGetWrapMode(int $view): int {}
}
