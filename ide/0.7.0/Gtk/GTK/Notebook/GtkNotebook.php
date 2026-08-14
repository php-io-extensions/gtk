<?php

namespace Gtk\GTK\Notebook;

class GtkNotebook
{
    public static function gtkNotebookNew(): int {}

    public static function gtkNotebookAppendPage(int $notebook, int $child, int $tabLabel): int {}

    public static function gtkNotebookRemovePage(int $notebook, int $pageNum): void {}

    public static function gtkNotebookGetNPages(int $notebook): int {}

    public static function gtkNotebookSetCurrentPage(int $notebook, int $pageNum): void {}

    public static function gtkNotebookGetCurrentPage(int $notebook): int {}

    public static function gtkNotebookSetTabLabelText(int $notebook, int $child, string $text): void {}
}
