<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
final class GVariant
{
    private function __construct() {}

    public static function newBoolean(bool $value): GVariant {}

    public static function newString(string $string): GVariant {}

    public static function newInt32(int $value): GVariant {}

    public static function newDouble(float $value): GVariant {}

    public function getBoolean(): bool {}

    public function getString(): string {}

    public function getInt32(): int {}

    public function getDouble(): float {}

    public function getTypeString(): string {}

    public function isOfType(string $type): bool {}

    public function print(bool $typeAnnotate): string {}
}
