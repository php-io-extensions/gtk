<?php

namespace Gtk\GTK\SingleSelection;

class GtkSingleSelection
{
    public static function gtkSingleSelectionNew(int $model): int {}

    public static function gtkSingleSelectionSetSelected(int $selection, int $position): void {}

    public static function gtkSingleSelectionGetSelected(int $selection): int {}

    public static function gtkSingleSelectionGetModel(int $selection): int {}
}
