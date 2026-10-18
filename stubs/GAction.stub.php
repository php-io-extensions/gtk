<?php

/** @generate-class-entries */

/** GAction: an action, implemented by GSimpleAction. */
interface GAction
{
    public static function nameIsValid(string $actionName): bool;

    public static function printDetailedName(string $actionName, ?GVariant $targetValue): string;

    public function getName(): string;

    /** the parameter's GVariant type string, or null for an action without a parameter */
    public function getParameterType(): ?string;

    /** the state's GVariant type string, or null for a stateless action */
    public function getStateType(): ?string;

    public function getStateHint(): ?GVariant;

    public function getEnabled(): bool;

    public function getState(): ?GVariant;

    public function changeState(GVariant $value): void;

    public function activate(?GVariant $parameter): void;
}

/** GActionMap: the actions a GSimpleActionGroup, a GApplication or a GtkApplicationWindow holds. */
interface GActionMap
{
    public function lookupAction(string $actionName): ?GAction;

    public function addAction(GAction $action): void;

    public function removeAction(string $actionName): void;
}

/** GActionGroup: actions activated and queried by name. */
interface GActionGroup
{
    public function hasAction(string $actionName): bool;

    /** @return array list of action names */
    public function listActions(): array;

    public function getActionEnabled(string $actionName): bool;

    /** the parameter's GVariant type string, or null for an action without a parameter */
    public function getActionParameterType(string $actionName): ?string;

    /** the state's GVariant type string, or null for a stateless action */
    public function getActionStateType(string $actionName): ?string;

    public function getActionStateHint(string $actionName): ?GVariant;

    public function getActionState(string $actionName): ?GVariant;

    public function changeActionState(string $actionName, GVariant $value): void;

    public function activateAction(string $actionName, ?GVariant $parameter): void;

    public function actionAdded(string $actionName): void;

    public function actionRemoved(string $actionName): void;

    public function actionEnabledChanged(string $actionName, bool $enabled): void;

    public function actionStateChanged(string $actionName, GVariant $state): void;
}

/** GListModel: a list of GObjects, implemented by GtkStringList and GtkSingleSelection. */
interface GListModel
{
    public function getNItems(): int;

    public function getItem(int $position): ?GObject;

    public function getObject(int $position): ?GObject;

    public function itemsChanged(int $position, int $removed, int $added): void;
}

/**
 * @not-serializable
 */
class GSimpleAction extends GObject implements GAction
{
    /** @param string|null $parameterType a GVariant type string, e.g. "s"; null for no parameter */
    public static function new(string $name, ?string $parameterType): GSimpleAction {}

    public static function newStateful(string $name, ?string $parameterType, GVariant $state): GSimpleAction {}

    public function setEnabled(bool $enabled): void {}

    public function setState(GVariant $value): void {}
}

/**
 * @not-serializable
 */
class GSimpleActionGroup extends GObject implements GActionGroup, GActionMap
{
    public static function new(): GSimpleActionGroup {}
}
