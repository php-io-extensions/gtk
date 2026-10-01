<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GtkApplication extends GApplication
{
    public static function new(?string $applicationId, GApplicationFlags|int $flags): GtkApplication {}

    public function addWindow(GtkWindow $window): void {}

    public function removeWindow(GtkWindow $window): void {}

    public function getActiveWindow(): ?GtkWindow {}

    /** @return array a list of GtkWindow */
    public function getWindows(): array {}

    public function getMenubar(): ?GMenuModel {}

    public function setMenubar(?GMenuModel $menubar): void {}

    /** @param array $accels accelerator strings, e.g. "<Control>q" */
    public function setAccelsForAction(string $detailedActionName, array $accels): void {}

    /** @return array accelerator strings */
    public function getAccelsForAction(string $detailedActionName): array {}
}
