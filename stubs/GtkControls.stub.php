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

    /** gtk_label_set_markup(): Pango markup; also sets use-markup. GTK answers malformed markup with a warning and a blank label. */
    public function setMarkup(string $str): void {}

    public function getUseMarkup(): bool {}

    public function setUseMarkup(bool $setting): void {}

    /** gtk_label_get_current_uri(): the link being activated by the pointer or keys, else null. Signal activate-link(uri). */
    public function getCurrentUri(): ?string {}
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
 * Signal activate-link: return true to handle it; otherwise GTK opens the URI.
 *
 * @not-serializable
 */
class GtkLinkButton extends GtkButton
{
    /** gtk_link_button_new(): the URI is the label too. */
    public static function new(string $uri): GtkLinkButton {}

    /** gtk_link_button_new_with_label(). The null default is PHP's: GtkButton::newWithLabel() takes one argument, so a second must be optional here. */
    public static function newWithLabel(string $uri, ?string $label = null): GtkLinkButton {}

    public function getUri(): string {}

    /** Resets the visited state. */
    public function setUri(string $uri): void {}

    public function getVisited(): bool {}

    public function setVisited(bool $visited): void {}
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

    /** gtk_entry_buffer_set_text(); $nChars -1 = the whole string */
    public function setText(string $chars, int $nChars): void {}
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
    /** gtk_text_buffer_set_text(); $len -1 = the whole string */
    public function setText(string $text, int $len): void {}

    /** Group what follows into one user action until the matching endUserAction(); calls nest. */
    public function beginUserAction(): void {}

    public function endUserAction(): void {}

    /** gtk_text_buffer_get_text(): null, with GTK's critical, for an iter taken before the buffer's text last changed or from another buffer. */
    public function getText(GtkTextIter $start, GtkTextIter $end, bool $includeHiddenChars): ?string {}

    public function getTagTable(): GtkTextTagTable {}

    /** gtk_text_buffer_get_iter_at_line(): the iter written to $iter; false past the last line, $iter then at the buffer's end. */
    public function getIterAtLine(?GtkTextIter &$iter, int $lineNumber): bool {}

    /** gtk_text_buffer_get_iter_at_line_offset(): the iter written to $iter; false past the last line or the line's end, $iter then at the end it reached. */
    public function getIterAtLineOffset(?GtkTextIter &$iter, int $lineNumber, int $charOffset): bool {}

    /** gtk_text_buffer_get_iter_at_offset(): -1 or past the end is the end iter */
    public function getIterAtOffset(int $charOffset): GtkTextIter {}

    public function getStartIter(): GtkTextIter {}

    public function getEndIter(): GtkTextIter {}

    /** GTK answers a tag outside this buffer's table, or another buffer's iter, with a critical. */
    public function applyTag(GtkTextTag $tag, GtkTextIter $start, GtkTextIter $end): void {}

    public function removeTag(GtkTextTag $tag, GtkTextIter $start, GtkTextIter $end): void {}

    /** gtk_text_buffer_get_selection_bounds(): the selection written to $start and $end; false with nothing selected, both then at the insert mark. */
    public function getSelectionBounds(?GtkTextIter &$start, ?GtkTextIter &$end): bool {}

    /** Moves the insert mark to $ins and the selection bound to $bound in one step. */
    public function selectRange(GtkTextIter $ins, GtkTextIter $bound): void {}

    public function getInsert(): GtkTextMark {}

    public function getIterAtMark(GtkTextMark $mark): GtkTextIter {}

    public function getLineCount(): int {}
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

    public function getMonospace(): bool {}

    public function setMonospace(bool $monospace): void {}

    public function getCursorVisible(): bool {}

    public function setCursorVisible(bool $setting): void {}

    /**
     * gtk_text_view_get_line_yrange(): the line's top y and height, in buffer coordinates, written to $y
     * and $height; GTK's estimate (0 and 0 before the view is laid out)
     */
    public function getLineYrange(GtkTextIter $iter, ?int &$y, ?int &$height): void {}
}

/**
 * @not-serializable
 */
class GtkScale extends GtkWidget
{
    /** gtk_scale_new_with_range() */
    public static function newWithRange(GtkOrientation $orientation, float $min, float $max, float $step): ?GtkScale {}

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
class GtkStringList extends GObject implements GListModel
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

    public function setModel(?GListModel $model): void {}
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

    /** null when nothing loaded */
    public function getPaintable(): ?GdkPaintable {}

    /** $paintable: a GdkTexture or GtkMediaStream, for example; null shows nothing */
    public function setPaintable(?GdkPaintable $paintable): void {}

    public function getCanShrink(): bool {}

    /** false keeps the picture at least as large as what it shows */
    public function setCanShrink(bool $canShrink): void {}
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

    public function getHadjustment(): GtkAdjustment {}

    public function getVadjustment(): GtkAdjustment {}
}

/**
 * @not-serializable
 */
class GtkPaned extends GtkWidget
{
    public static function new(GtkOrientation $orientation): GtkPaned {}

    public function getStartChild(): ?GtkWidget {}

    public function setStartChild(?GtkWidget $child): void {}

    public function getEndChild(): ?GtkWidget {}

    public function setEndChild(?GtkWidget $child): void {}

    /** The divider's offset from the start, in pixels of this paned's own allocation. */
    public function getPosition(): int {}

    /** Negative unsets it: GTK places the divider itself. */
    public function setPosition(int $position): void {}

    public function getResizeStartChild(): bool {}

    public function setResizeStartChild(bool $resize): void {}

    public function getResizeEndChild(): bool {}

    public function setResizeEndChild(bool $resize): void {}

    public function getShrinkStartChild(): bool {}

    public function setShrinkStartChild(bool $shrink): void {}

    public function getShrinkEndChild(): bool {}

    public function setShrinkEndChild(bool $shrink): void {}

    public function getWideHandle(): bool {}

    public function setWideHandle(bool $wide): void {}
}

/**
 * @not-serializable
 */
class GtkNotebook extends GtkWidget
{
    public static function new(): GtkNotebook {}

    /** gtk_notebook_append_page: the new page's index, or -1 (GTK's critical) when $child or $tabLabel already has a parent. */
    public function appendPage(GtkWidget $child, ?GtkWidget $tabLabel): int {}

    /** -1 removes the last page; an index past the end does nothing. */
    public function removePage(int $pageNum): void {}

    /** -1 when $child is not a page here */
    public function pageNum(GtkWidget $child): int {}

    public function getNPages(): int {}

    /** -1 with no pages */
    public function getCurrentPage(): int {}

    /** -1 selects the last page; an index past the end does nothing. */
    public function setCurrentPage(int $pageNum): void {}

    /** -1 is the last page; null past the end. */
    public function getNthPage(int $pageNum): ?GtkWidget {}

    public function setTabLabelText(GtkWidget $child, string $tabText): void {}

    /** null when the tab label is not a GtkLabel, or $child is not a page here */
    public function getTabLabelText(GtkWidget $child): ?string {}

    public function getShowTabs(): bool {}

    public function setShowTabs(bool $showTabs): void {}

    public function getScrollable(): bool {}

    public function setScrollable(bool $scrollable): void {}
}
