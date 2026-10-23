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

    /** GTK 4.12. $flags: GTK_LIST_SCROLL_* combined with |. */
    public function scrollTo(int $pos, ?GtkColumnViewColumn $column, int $flags, ?GtkScrollInfo $scroll): void {}
}

/**
 * A GListModel of GtkTreeListRow over a root model, each row's children coming from $createFunc.
 *
 * @not-serializable
 */
class GtkTreeListModel extends GObject implements GListModel
{
    /**
     * @param callable $createFunc called as $createFunc(GObject $item): ?GListModel when GTK needs a row's
     *                             children; anything but a GListModel makes the row a leaf. Held until the
     *                             model is finalized.
     */
    public static function new(GListModel $root, bool $passthrough, bool $autoexpand, callable $createFunc): GtkTreeListModel {}

    /** The row at a position of the flattened list; null past the end */
    public function getRow(int $position): ?GtkTreeListRow {}

    /** The row of the root model's item at $position; null past the end */
    public function getChildRow(int $position): ?GtkTreeListRow {}
}

/**
 * One row of a GtkTreeListModel.
 *
 * @not-serializable
 */
class GtkTreeListRow extends GObject
{
    public function getItem(): ?GObject {}

    public function getExpanded(): bool {}

    public function setExpanded(bool $expanded): void {}

    public function isExpandable(): bool {}

    public function getDepth(): int {}

    public function getPosition(): int {}

    public function getParent(): ?GtkTreeListRow {}

    /** null when the row is collapsed or has no such child */
    public function getChildRow(int $position): ?GtkTreeListRow {}
}

/**
 * A widget showing a GtkTreeListRow's expander and depth indentation before its child.
 *
 * @not-serializable
 */
class GtkTreeExpander extends GtkWidget
{
    public static function new(): GtkTreeExpander {}

    public function getChild(): ?GtkWidget {}

    public function setChild(?GtkWidget $child): void {}

    public function getListRow(): ?GtkTreeListRow {}

    public function setListRow(?GtkTreeListRow $listRow): void {}
}

/**
 * GTK 4.12. How a scrollTo() scrolls; a boxed, reference-counted struct.
 *
 * @not-serializable
 */
final class GtkScrollInfo
{
    private function __construct() {}

    public static function new(): GtkScrollInfo {}

    public function getEnableHorizontal(): bool {}

    public function setEnableHorizontal(bool $horizontal): void {}

    public function getEnableVertical(): bool {}

    public function setEnableVertical(bool $vertical): void {}
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
