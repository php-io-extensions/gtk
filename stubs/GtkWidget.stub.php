<?php

/** @generate-class-entries */

enum GtkOrientation: int
{
    case HORIZONTAL = 0;
    case VERTICAL = 1;
}

enum GtkAlign: int
{
    case FILL = 0;
    case START = 1;
    case END = 2;
    case CENTER = 3;
    case BASELINE_FILL = 4;
    case BASELINE_CENTER = 5;
}

/**
 * @not-serializable
 */
class GtkWidget extends GObject
{
    public function show(): void {}

    public function hide(): void {}

    public function getVisible(): bool {}

    public function getRealized(): bool {}

    public function getMapped(): bool {}

    public function setVisible(bool $visible): void {}

    public function getHexpand(): bool {}

    public function setHexpand(bool $expand): void {}

    public function getVexpand(): bool {}

    public function setVexpand(bool $expand): void {}

    public function getParent(): ?GtkWidget {}

    /** @param GObject|null $group a GActionGroup, or null to remove the prefix */
    public function insertActionGroup(string $name, ?GObject $group): void {}

    /** gtk_widget_activate_action_variant() */
    public function activateAction(string $name, ?GVariant $args): bool {}

    /** gtk_widget_activate(): false when the widget is not activatable */
    public function activate(): bool {}

    public function getHalign(): GtkAlign {}

    public function setHalign(GtkAlign $align): void {}

    public function getValign(): GtkAlign {}

    public function setValign(GtkAlign $align): void {}

    public function setSizeRequest(int $width, int $height): void {}

    /** @return array{int, int} [width, height]; -1 = unset */
    public function getSizeRequest(): array {}

    public function getWidth(): int {}

    /** Device pixels per application pixel on the widget's surface: 2 on a HiDPI display. */
    public function getScaleFactor(): int {}

    public function getHeight(): int {}

    public function getSensitive(): bool {}

    public function setSensitive(bool $sensitive): void {}

    /**
     * gtk_widget_get_color(): the foreground colour CSS computed for this widget's node.
     *
     * @return array{float, float, float, float} [red, green, blue, alpha], 0..1
     */
    public function getColor(): array {}

    /** gtk_widget_is_sensitive(): sensitive itself and every ancestor sensitive too */
    public function isSensitive(): bool {}

    public function setMarginStart(int $margin): void {}

    public function setMarginEnd(int $margin): void {}

    public function setMarginTop(int $margin): void {}

    public function setMarginBottom(int $margin): void {}

    public function addCssClass(string $cssClass): void {}

    public function removeCssClass(string $cssClass): void {}

    /** gtk_widget_add_controller(): the widget holds the controller until removeController() or its own end. */
    public function addController(GtkEventController $controller): void {}

    public function removeController(GtkEventController $controller): void {}

    /**
     * gtk_widget_compute_point(): ($x, $y) in this widget's coordinates, in $target's.
     *
     * @return array{0: float, 1: float}|null null when the widgets share no common ancestor
     */
    public function computePoint(GtkWidget $target, float $x, float $y): ?array {}

    /** gtk_widget_pick(): the innermost descendant at ($x, $y) in this widget's coordinates; $flags GTK_PICK_* ORed. */
    public function pick(float $x, float $y, int $flags): ?GtkWidget {}

    public function hasCssClass(string $cssClass): bool {}

    /** @return array{minimum: int, natural: int, minimumBaseline: int, naturalBaseline: int} */
    public function measure(GtkOrientation $orientation, int $forSize): array {}

    /** gtk_widget_get_native(): the GtkNative ancestor (a window), boxed as its widget class */
    public function getNative(): ?GtkWidget {}

    /**
     * gtk_widget_compute_bounds(): this widget's border box in $target's coordinates.
     *
     * @return array{float, float, float, float}|null [x, y, width, height]; null when the two share no common ancestor
     */
    public function computeBounds(GtkWidget $target): ?array {}

    public function getFirstChild(): ?GtkWidget {}

    public function getNextSibling(): ?GtkWidget {}

    /** gtk_widget_get_display(): the display the widget is on. */
    public function getDisplay(): GdkDisplay {}

    /** gtk_widget_get_root(): the GtkRoot ancestor (a window), boxed as its widget class */
    public function getRoot(): ?GtkWidget {}

    /** gtk_native_get_surface() when this widget is a GtkNative (a window), else null */
    public function getSurface(): ?GdkSurface {}
}

/**
 * @not-serializable
 */
class GtkBox extends GtkWidget
{
    public static function new(GtkOrientation $orientation, int $spacing): GtkBox {}

    public function append(GtkWidget $child): void {}

    public function prepend(GtkWidget $child): void {}

    public function remove(GtkWidget $child): void {}

    public function insertChildAfter(GtkWidget $child, ?GtkWidget $sibling): void {}

    public function reorderChildAfter(GtkWidget $child, ?GtkWidget $sibling): void {}

    public function getSpacing(): int {}

    public function setSpacing(int $spacing): void {}

    public function getHomogeneous(): bool {}

    public function setHomogeneous(bool $homogeneous): void {}
}

/**
 * @not-serializable
 */
class GtkGrid extends GtkWidget
{
    public static function new(): GtkGrid {}

    public function attach(GtkWidget $child, int $column, int $row, int $width, int $height): void {}

    public function remove(GtkWidget $child): void {}

    public function getChildAt(int $column, int $row): ?GtkWidget {}

    public function getRowSpacing(): int {}

    public function setRowSpacing(int $spacing): void {}

    public function getColumnSpacing(): int {}

    public function setColumnSpacing(int $spacing): void {}
}

/**
 * @not-serializable
 */
class GtkFixed extends GtkWidget
{
    public static function new(): GtkFixed {}

    public function put(GtkWidget $child, float $x, float $y): void {}

    public function move(GtkWidget $child, float $x, float $y): void {}

    public function remove(GtkWidget $child): void {}

    /** @return array{float, float} */
    public function getChildPosition(GtkWidget $child): array {}
}

/**
 * @not-serializable
 */
class GtkPopoverMenuBar extends GtkWidget
{
    public static function newFromModel(?GMenuModel $model): GtkPopoverMenuBar {}

    public function getMenuModel(): ?GMenuModel {}

    public function setMenuModel(?GMenuModel $model): void {}
}
