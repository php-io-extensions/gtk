<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GSimpleAction extends GObject
{
    /** @param string|null $parameterType a GVariant type string, e.g. "s"; null for no parameter */
    public static function new(string $name, ?string $parameterType): GSimpleAction {}

    public static function newStateful(string $name, ?string $parameterType, GVariant $state): GSimpleAction {}

    public function setEnabled(bool $enabled): void {}

    public function setState(GVariant $value): void {}

    /** g_action_get_name() */
    public function getName(): string {}

    /** g_action_get_enabled() */
    public function getEnabled(): bool {}

    /** g_action_get_state() */
    public function getState(): ?GVariant {}

    /** g_action_activate() */
    public function activate(?GVariant $parameter): void {}

    /** g_action_change_state() */
    public function changeState(GVariant $value): void {}
}

/**
 * @not-serializable
 */
class GSimpleActionGroup extends GObject
{
    public static function new(): GSimpleActionGroup {}

    /** g_action_map_add_action() */
    public function addAction(GSimpleAction $action): void {}

    /** g_action_map_remove_action() */
    public function removeAction(string $actionName): void {}

    /** g_action_map_lookup_action() */
    public function lookupAction(string $actionName): ?GSimpleAction {}

    /** g_action_group_has_action() */
    public function hasAction(string $actionName): bool {}

    /** g_action_group_list_actions() @return array list of action names */
    public function listActions(): array {}

    /** g_action_group_activate_action() */
    public function activateAction(string $actionName, ?GVariant $parameter): void {}
}
