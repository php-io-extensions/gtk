<?php

/** @generate-class-entries */

enum GApplicationFlags: int
{
    case DEFAULT_FLAGS = 0;
    case IS_SERVICE = 1;
    case IS_LAUNCHER = 2;
    case HANDLES_OPEN = 4;
    case HANDLES_COMMAND_LINE = 8;
    case SEND_ENVIRONMENT = 16;
    case NON_UNIQUE = 32;
    case CAN_OVERRIDE_APP_ID = 64;
    case ALLOW_REPLACEMENT = 128;
    case REPLACE = 256;
}

/**
 * @not-serializable
 */
class GApplication extends GObject
{
    public static function idIsValid(string $applicationId): bool {}

    public function getApplicationId(): ?string {}

    public function getFlags(): int {}

    public function getIsRegistered(): bool {}

    public function getIsRemote(): bool {}

    /** @throws GError */
    public function register(): bool {}

    public function activate(): void {}

    public function hold(): void {}

    public function release(): void {}

    public function quit(): void {}

    /** @param array $argv string arguments, argv[0] first */
    public function run(array $argv = []): int {}
}
