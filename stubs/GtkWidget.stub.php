<?php

/** @generate-class-entries */

enum GtkOrientation: int
{
    case HORIZONTAL = 0;
    case VERTICAL = 1;
}

/**
 * @not-serializable
 */
class GtkWidget extends GObject
{
    public function show(): void {}

    public function hide(): void {}

    public function getVisible(): bool {}

    public function getRealized(): bool {}

    public function getMapped(): bool {}

    public function setVisible(bool $visible): void {}

    public function getHexpand(): bool {}

    public function setHexpand(bool $expand): void {}

    public function getVexpand(): bool {}

    public function setVexpand(bool $expand): void {}

    public function getParent(): ?GtkWidget {}

    /** @param GObject|null $group a GActionGroup, or null to remove the prefix */
    public function insertActionGroup(string $name, ?GObject $group): void {}

    /** gtk_widget_activate_action_variant() */
    public function activateAction(string $name, ?GVariant $args): bool {}
}

/**
 * @not-serializable
 */
class GtkBox extends GtkWidget
{
    public static function new(GtkOrientation $orientation, int $spacing): GtkBox {}

    public function append(GtkWidget $child): void {}

    public function prepend(GtkWidget $child): void {}

    public function remove(GtkWidget $child): void {}
}

/**
 * @not-serializable
 */
class GtkPopoverMenuBar extends GtkWidget
{
    public static function newFromModel(?GMenuModel $model): GtkPopoverMenuBar {}

    public function getMenuModel(): ?GMenuModel {}

    public function setMenuModel(?GMenuModel $model): void {}
}
