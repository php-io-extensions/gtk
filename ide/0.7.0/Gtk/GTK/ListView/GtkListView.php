<?php

namespace Gtk\GTK\ListView;

class GtkListView
{
    public static function gtkListViewNew(int $model, int $factory): int {}

    public static function gtkListViewSetModel(int $view, int $model): void {}

    public static function gtkListViewGetModel(int $view): int {}

    public static function gtkListViewSetFactory(int $view, int $factory): void {}
}
