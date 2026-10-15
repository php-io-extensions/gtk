<?php

/** @generate-class-entries */

/**
 * A position in a text buffer (a copy PHP owns). It keeps its buffer alive for as long as the
 * object lives, and is valid until the buffer's text changes, as GTK's own iters are: every method
 * (and every buffer or view method taking it) then throws GtkException ("stale"). An iter of
 * another buffer is a ValueError.
 *
 * @not-serializable
 */
final class GtkTextIter
{
    private function __construct() {}

    public function getLine(): int {}

    /** Characters (code points) from the line's start. */
    public function getLineOffset(): int {}

    /** Characters from the buffer's start. */
    public function getOffset(): int {}

    public function hasTag(GtkTextTag $tag): bool {}

    /** @return list<GtkTextTag> the tags at this position, lowest priority first */
    public function getTags(): array {}
}

/**
 * @not-serializable
 */
class GtkTextMark extends GObject
{
}

/**
 * Its look is set through properties (g_object_set_property): foreground, background,
 * paragraph-background, ….
 *
 * @not-serializable
 */
class GtkTextTag extends GObject
{
    public static function new(?string $name): GtkTextTag {}
}

/**
 * @not-serializable
 */
class GtkTextTagTable extends GObject
{
    /** False when a tag of the same name is in the table; a tag already in a table is a ValueError. */
    public function add(GtkTextTag $tag): bool {}

    /** A tag this table does not hold is a ValueError. */
    public function remove(GtkTextTag $tag): void {}

    public function lookup(string $name): ?GtkTextTag {}
}

/**
 * Signal value-changed.
 *
 * @not-serializable
 */
class GtkAdjustment extends GObject
{
    public function getValue(): float {}

    /** GTK clamps the value to lower .. upper - page size. */
    public function setValue(float $value): void {}

    public function getLower(): float {}

    public function getUpper(): float {}

    public function getPageSize(): float {}
}
