<?php

/** @generate-class-entries */

/** GtkSelectionModel: a GListModel with selected items, implemented by GtkSingleSelection. */
interface GtkSelectionModel extends GListModel
{
    public function isSelected(int $position): bool;

    public function selectItem(int $position, bool $unselectRest): bool;

    public function unselectItem(int $position): bool;

    public function selectRange(int $position, int $nItems, bool $unselectRest): bool;

    public function unselectRange(int $position, int $nItems): bool;

    public function selectAll(): bool;

    public function unselectAll(): bool;

    public function selectionChanged(int $position, int $nItems): void;
}

/**
 * The base of the factories that make a list's item widgets.
 *
 * @not-serializable
 */
class GtkListItemFactory extends GObject
{
}

/**
 * Signals setup, bind, unbind and teardown each carry the GtkListItem.
 *
 * @not-serializable
 */
class GtkSignalListItemFactory extends GtkListItemFactory
{
    public static function new(): GtkSignalListItemFactory {}
}

/**
 * @not-serializable
 */
class GtkListItem extends GObject
{
    public function getPosition(): int {}

    public function getItem(): ?GObject {}

    public function getChild(): ?GtkWidget {}

    public function setChild(?GtkWidget $child): void {}
}

/**
 * @not-serializable
 */
class GtkColumnViewColumn extends GObject
{
    public static function new(?string $title, ?GtkListItemFactory $factory): GtkColumnViewColumn {}

    public function getTitle(): ?string {}

    public function setTitle(?string $title): void {}

    public function setExpand(bool $expand): void {}

    public function setResizable(bool $resizable): void {}
}

/**
 * @not-serializable
 */
class GtkColumnView extends GtkWidget
{
    public static function new(?GtkSelectionModel $model): GtkColumnView {}

    public function appendColumn(GtkColumnViewColumn $column): void {}

    public function removeColumn(GtkColumnViewColumn $column): void {}

    public function getModel(): ?GtkSelectionModel {}

    public function setModel(?GtkSelectionModel $model): void {}

    public function setShowRowSeparators(bool $showRowSeparators): void {}

    public function setShowColumnSeparators(bool $showColumnSeparators): void {}
}

/**
 * A GtkSelectionModel over a GListModel.
 *
 * @not-serializable
 */
class GtkSingleSelection extends GObject implements GtkSelectionModel
{
    public static function new(?GListModel $model): GtkSingleSelection {}

    /** GTK_INVALID_LIST_POSITION when nothing is selected */
    public function getSelected(): int {}

    public function setSelected(int $position): void {}

    public function getSelectedItem(): ?GObject {}

    public function setAutoselect(bool $autoselect): void {}

    public function setCanUnselect(bool $canUnselect): void {}

    /** the underlying model */
    public function getModel(): ?GListModel {}
}
