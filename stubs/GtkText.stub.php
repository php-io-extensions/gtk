<?php

/** @generate-class-entries */

/**
 * A position in a text buffer (a copy PHP owns). It keeps its buffer alive for as long as the
 * object lives, and is valid until the buffer's text changes, as GTK's own iters are: every method
 * (and every buffer or view method taking it) then throws GtkException ("stale"). GTK answers an
 * iter of another buffer with a critical.
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
    /** gtk_text_tag_table_add(): false when a tag of the same name is in the table, or the tag is in a table already. */
    public function add(GtkTextTag $tag): bool {}

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
    public static function new(float $value, float $lower, float $upper, float $stepIncrement, float $pageIncrement, float $pageSize): GtkAdjustment {}

    /** Sets all six at once, value-changed and changed emitted once each. */
    public function configure(float $value, float $lower, float $upper, float $stepIncrement, float $pageIncrement, float $pageSize): void {}

    public function getValue(): float {}

    /** GTK clamps the value to lower .. upper - page size. */
    public function setValue(float $value): void {}

    public function getLower(): float {}

    public function getUpper(): float {}

    public function getPageSize(): float {}
}
