<?php

/** @generate-class-entries */

/**
 * @var int
 * @cvalue PANGO_SCALE
 */
const PANGO_SCALE = UNKNOWN;

enum PangoTabAlign: int
{
    case LEFT = 0;
    case RIGHT = 1;
    case CENTER = 2;
    case DECIMAL = 3;
}

/**
 * A language tag Pango owns for the life of the process; the PHP object frees nothing.
 *
 * @not-serializable
 */
final class PangoLanguage
{
    /** Made by fromString() only. */
    private function __construct() {}

    /** pango_language_from_string(): null for a null tag. */
    public static function fromString(?string $language): ?PangoLanguage {}

    public function toString(): string {}
}

/**
 * A font request: family, style, weight, size. Freed (pango_font_description_free) with the PHP object.
 *
 * @not-serializable
 */
final class PangoFontDescription
{
    /** Made by fromString() only. */
    private function __construct() {}

    /** pango_font_description_from_string(): "[FAMILY-LIST] [STYLE-OPTIONS] [SIZE]", e.g. "Monospace Italic 12". */
    public static function fromString(string $str): PangoFontDescription {}
}

/**
 * @not-serializable
 */
class PangoContext extends GObject
{
    /** pango_context_get_metrics(): null $desc = the context's font; null $language = the context's language. */
    public function getMetrics(?PangoFontDescription $desc, ?PangoLanguage $language): PangoFontMetrics {}

    /** pango_context_load_font(): null when no font matches. */
    public function loadFont(PangoFontDescription $desc): ?PangoFont {}
}

/**
 * Sizes in Pango units (PANGO_SCALE per device unit). Unreffed (pango_font_metrics_unref) with the PHP object.
 *
 * @not-serializable
 */
final class PangoFontMetrics
{
    /** Made by PangoContext::getMetrics() only. */
    private function __construct() {}

    public function getAscent(): int {}

    public function getDescent(): int {}

    public function getHeight(): int {}

    public function getApproximateCharWidth(): int {}
}

/**
 * @not-serializable
 */
class PangoFont extends GObject
{
    public function getFace(): ?PangoFontFace {}
}

/**
 * @not-serializable
 */
class PangoFontFace extends GObject
{
    public function getFamily(): PangoFontFamily {}
}

/**
 * @not-serializable
 */
class PangoFontFamily extends GObject
{
    public function isMonospace(): bool {}
}

/**
 * Tab stops. Freed (pango_tab_array_free) with the PHP object.
 *
 * @not-serializable
 */
final class PangoTabArray
{
    /** Made by new() or GtkTextView::getTabs() only. */
    private function __construct() {}

    public static function new(int $initialSize, bool $positionsInPixels): PangoTabArray {}

    public function setTab(int $tabIndex, PangoTabAlign $alignment, int $location): void {}

    /** pango_tab_array_get_tab(): the stop's alignment and location, written to $alignment and $location. */
    public function getTab(int $tabIndex, ?PangoTabAlign &$alignment, ?int &$location): void {}

    public function getPositionsInPixels(): bool {}
}
