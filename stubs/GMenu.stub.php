<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GMenuModel extends GObject
{
    public function getNItems(): int {}

    public function isMutable(): bool {}
}

/**
 * @not-serializable
 */
class GMenu extends GMenuModel
{
    public static function new(): GMenu {}

    public function append(?string $label, ?string $detailedAction): void {}

    public function appendItem(GMenuItem $item): void {}

    public function appendSection(?string $label, GMenuModel $section): void {}

    public function appendSubmenu(?string $label, GMenuModel $submenu): void {}

    public function prepend(?string $label, ?string $detailedAction): void {}

    public function insert(int $position, ?string $label, ?string $detailedAction): void {}

    public function remove(int $position): void {}

    public function removeAll(): void {}

    public function freeze(): void {}
}

/**
 * @not-serializable
 */
class GMenuItem extends GObject
{
    public static function new(?string $label, ?string $detailedAction): GMenuItem {}

    public function setLabel(?string $label): void {}

    public function setDetailedAction(string $detailedAction): void {}

    public function setActionAndTargetValue(?string $action, ?GVariant $targetValue): void {}

    public function setAttributeValue(string $attribute, ?GVariant $value): void {}

    public function getAttributeValue(string $attribute, ?string $expectedType): ?GVariant {}

    public function setSubmenu(?GMenuModel $submenu): void {}

    public function setSection(?GMenuModel $section): void {}
}
