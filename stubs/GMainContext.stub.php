<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class GMainContext
{
    private function __construct() {}

    public static function default(): GMainContext {}

    public static function getThreadDefault(): ?GMainContext {}

    public function iteration(bool $mayBlock): bool {}

    public function pending(): bool {}

    public function wakeup(): void {}

    public function acquire(): bool {}

    public function release(): void {}

    public function isOwner(): bool {}

    /** The context's address, for handing it to another extension. */
    public function pointer(): int {}
}
