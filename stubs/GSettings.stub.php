<?php

/** @generate-class-entries */

/**
 * A GSettingsSchemaSource (reference counted; not a GObject).
 *
 * @not-serializable
 */
final class GSettingsSchemaSource
{
    /** Made by getDefault() only. */
    private function __construct() {}

    /** g_settings_schema_source_get_default(): null when the process has none. */
    public static function getDefault(): ?GSettingsSchemaSource {}

    /** g_settings_schema_source_lookup(): null when no schema has the id. */
    public function lookup(string $schemaId, bool $recursive): ?GSettingsSchema {}
}

/**
 * A GSettingsSchema (reference counted; not a GObject).
 *
 * @not-serializable
 */
final class GSettingsSchema
{
    /** Made by GSettingsSchemaSource::lookup() only. */
    private function __construct() {}

    public function hasKey(string $name): bool {}
}

/**
 * Refuses (ValueError) what GIO answers with g_error(): a schema that is not installed or has no path
 * (new()), and a key the schema lacks (every get). A key of another type passes through: GLib's critical, then 0 or null.
 *
 * @not-serializable
 */
class GSettings extends GObject
{
    public static function new(string $schemaId): GSettings {}

    public function getBoolean(string $key): bool {}

    public function getInt(string $key): int {}

    public function getUint(string $key): int {}

    public function getDouble(string $key): float {}

    public function getString(string $key): ?string {}
}
