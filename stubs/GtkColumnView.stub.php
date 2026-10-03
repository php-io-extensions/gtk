<?php

/** @generate-class-entries */

/**
 * Signals setup, bind, unbind and teardown each carry the GtkListItem.
 *
 * @not-serializable
 */
class GtkSignalListItemFactory extends GObject
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
    public static function new(?string $title, ?GtkSignalListItemFactory $factory): GtkColumnViewColumn {}

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
    /** @param GObject|null $model a GtkSelectionModel */
    public static function new(?GObject $model): GtkColumnView {}

    public function appendColumn(GtkColumnViewColumn $column): void {}

    public function removeColumn(GtkColumnViewColumn $column): void {}

    /** the GtkSelectionModel */
    public function getModel(): ?GObject {}

    /** @param GObject|null $model a GtkSelectionModel */
    public function setModel(?GObject $model): void {}

    public function setShowRowSeparators(bool $showRowSeparators): void {}

    public function setShowColumnSeparators(bool $showColumnSeparators): void {}
}

/**
 * A GtkSelectionModel over a GListModel.
 *
 * @not-serializable
 */
class GtkSingleSelection extends GObject
{
    /** @param GObject|null $model a GListModel */
    public static function new(?GObject $model): GtkSingleSelection {}

    /** GTK_INVALID_LIST_POSITION when nothing is selected */
    public function getSelected(): int {}

    public function setSelected(int $position): void {}

    public function getSelectedItem(): ?GObject {}

    public function setAutoselect(bool $autoselect): void {}

    public function setCanUnselect(bool $canUnselect): void {}

    /** the underlying GListModel */
    public function getModel(): ?GObject {}
}
