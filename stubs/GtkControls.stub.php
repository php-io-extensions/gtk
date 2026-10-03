<?php

/** @generate-class-entries */

enum PangoEllipsizeMode: int
{
    case NONE = 0;
    case START = 1;
    case MIDDLE = 2;
    case END = 3;
}

enum GtkJustification: int
{
    case LEFT = 0;
    case RIGHT = 1;
    case CENTER = 2;
    case FILL = 3;
}

enum GtkWrapMode: int
{
    case NONE = 0;
    case CHAR = 1;
    case WORD = 2;
    case WORD_CHAR = 3;
}

enum GtkContentFit: int
{
    case FILL = 0;
    case CONTAIN = 1;
    case COVER = 2;
    case SCALE_DOWN = 3;
}

enum GtkPolicyType: int
{
    case ALWAYS = 0;
    case AUTOMATIC = 1;
    case NEVER = 2;
    case EXTERNAL = 3;
}

/**
 * @not-serializable
 */
class GtkLabel extends GtkWidget
{
    public static function new(?string $str): GtkLabel {}

    public function getText(): string {}

    public function setText(string $str): void {}

    public function getWrap(): bool {}

    public function setWrap(bool $wrap): void {}

    public function setEllipsize(PangoEllipsizeMode $mode): void {}

    public function getXalign(): float {}

    public function setXalign(float $xalign): void {}

    public function setJustify(GtkJustification $jtype): void {}
}

/**
 * @not-serializable
 */
class GtkButton extends GtkWidget
{
    /** gtk_button_new_with_label() */
    public static function newWithLabel(string $label): GtkButton {}

    public function getLabel(): ?string {}

    public function setLabel(string $label): void {}
}

/**
 * GtkCheckButton is not a GtkButton in GTK 4.
 *
 * @not-serializable
 */
class GtkCheckButton extends GtkWidget
{
    /** gtk_check_button_new_with_label() */
    public static function newWithLabel(string $label): GtkCheckButton {}

    public function getActive(): bool {}

    public function setActive(bool $setting): void {}

    public function getLabel(): ?string {}

    public function setLabel(?string $label): void {}
}

/**
 * @not-serializable
 */
class GtkSwitch extends GtkWidget
{
    public static function new(): GtkSwitch {}

    public function getActive(): bool {}

    public function setActive(bool $isActive): void {}
}

/**
 * @not-serializable
 */
class GtkToggleButton extends GtkButton
{
    /** gtk_toggle_button_new_with_label() */
    public static function newWithLabel(string $label): GtkToggleButton {}

    public function getActive(): bool {}

    public function setActive(bool $isActive): void {}
}

/**
 * @not-serializable
 */
class GtkEntryBuffer extends GObject
{
    public function getText(): string {}

    /** gtk_entry_buffer_set_text(); -1 = the whole string */
    public function setText(string $chars, int $nChars = -1): void {}
}

/**
 * @not-serializable
 */
class GtkEntry extends GtkWidget
{
    public static function new(): GtkEntry {}

    public function getBuffer(): GtkEntryBuffer {}

    public function getPlaceholderText(): ?string {}

    public function setPlaceholderText(?string $text): void {}

    public function getVisibility(): bool {}

    public function setVisibility(bool $visible): void {}
}

/**
 * @not-serializable
 */
class GtkTextBuffer extends GObject
{
    /** gtk_text_buffer_set_text(); -1 = the whole string */
    public function setText(string $text, int $len = -1): void {}

    /** Group what follows into one user action until the matching endUserAction(); calls nest. */
    public function beginUserAction(): void {}

    public function endUserAction(): void {}

    /** gtk_text_buffer_get_text() between gtk_text_buffer_get_iter_at_offset() iters; -1 = the end */
    public function getText(int $startOffset, int $endOffset, bool $includeHidden = false): string {}
}

/**
 * @not-serializable
 */
class GtkTextView extends GtkWidget
{
    public static function new(): GtkTextView {}

    public function getBuffer(): GtkTextBuffer {}

    public function getEditable(): bool {}

    public function setEditable(bool $setting): void {}

    public function setWrapMode(GtkWrapMode $wrapMode): void {}
}

/**
 * @not-serializable
 */
class GtkScale extends GtkWidget
{
    /** gtk_scale_new_with_range() */
    public static function newWithRange(GtkOrientation $orientation, float $min, float $max, float $step): GtkScale {}

    /** gtk_range_get_value() */
    public function getValue(): float {}

    /** gtk_range_set_value() */
    public function setValue(float $value): void {}

    /** gtk_range_set_range() */
    public function setRange(float $min, float $max): void {}

    /** gtk_range_set_increments(): what an arrow key ($step) and Page Up/Down ($page) move by */
    public function setIncrements(float $step, float $page): void {}

    public function setDrawValue(bool $drawValue): void {}

    public function getDrawValue(): bool {}
}

/**
 * A GListModel of GtkStringObject.
 *
 * @not-serializable
 */
class GtkStringList extends GObject
{
    /** @param string[] $strings */
    public static function new(array $strings): GtkStringList {}

    public function append(string $string): void {}

    public function remove(int $position): void {}

    /**
     * gtk_string_list_splice(): remove $nRemovals items at $position and insert $additions there,
     * as one items-changed.
     *
     * @param string[] $additions
     */
    public function splice(int $position, int $nRemovals, array $additions): void {}

    public function getString(int $position): ?string {}

    /** g_list_model_get_n_items() */
    public function getNItems(): int {}
}

/**
 * @not-serializable
 */
class GtkStringObject extends GObject
{
    public function getString(): string {}
}

/**
 * @not-serializable
 */
class GtkDropDown extends GtkWidget
{
    /**
     * gtk_drop_down_new_from_strings()
     *
     * @param string[] $strings
     */
    public static function newFromStrings(array $strings): GtkDropDown {}

    /** GTK_INVALID_LIST_POSITION when nothing is selected */
    public function getSelected(): int {}

    public function setSelected(int $position): void {}

    public function getSelectedItem(): ?GObject {}

    /** @param GObject|null $model a GListModel */
    public function setModel(?GObject $model): void {}
}

/**
 * @not-serializable
 */
class GtkCalendar extends GtkWidget
{
    public static function new(): GtkCalendar {}

    public function getDate(): GDateTime {}

    /** gtk_calendar_select_day(); the one call GTK 4.18 and 4.20+ share */
    public function selectDay(GDateTime $date): void {}
}

/**
 * @not-serializable
 */
class GtkProgressBar extends GtkWidget
{
    public static function new(): GtkProgressBar {}

    public function getFraction(): float {}

    public function setFraction(float $fraction): void {}

    public function pulse(): void {}

    public function setPulseStep(float $fraction): void {}
}

/**
 * @not-serializable
 */
class GtkSpinner extends GtkWidget
{
    public static function new(): GtkSpinner {}

    public function getSpinning(): bool {}

    public function setSpinning(bool $spinning): void {}
}

/**
 * @not-serializable
 */
class GtkPicture extends GtkWidget
{
    public static function new(): GtkPicture {}

    /** gtk_picture_new_for_filename() */
    public static function newForFilename(string $filename): GtkPicture {}

    public function setFilename(?string $filename): void {}

    public function getContentFit(): GtkContentFit {}

    public function setContentFit(GtkContentFit $contentFit): void {}

    /** the GdkPaintable, null when nothing loaded */
    public function getPaintable(): ?GObject {}
}

/**
 * @not-serializable
 */
class GtkSeparator extends GtkWidget
{
    public static function new(GtkOrientation $orientation): GtkSeparator {}
}

/**
 * @not-serializable
 */
class GtkScrolledWindow extends GtkWidget
{
    public static function new(): GtkScrolledWindow {}

    public function getChild(): ?GtkWidget {}

    public function setChild(?GtkWidget $child): void {}

    public function setPolicy(GtkPolicyType $hscrollbarPolicy, GtkPolicyType $vscrollbarPolicy): void {}
}
