<?php

/** @generate-class-entries */

enum GtkPropagationPhase: int
{
    case NONE = 0;
    case CAPTURE = 1;
    case BUBBLE = 2;
    case TARGET = 3;
}

enum GdkScrollUnit: int
{
    case WHEEL = 0;
    case SURFACE = 1;
}

#if GTK_CHECK_VERSION(4, 20, 0)
enum GdkScrollRelativeDirection: int
{
    case IDENTICAL = 0;
    case INVERTED = 1;
    case UNKNOWN = 2;
}
#endif

/** GdkEventType. PAD_DIAL is sent by GTK 4.20+ only. */
enum GdkEventType: int
{
    case DELETE = 0;
    case MOTION_NOTIFY = 1;
    case BUTTON_PRESS = 2;
    case BUTTON_RELEASE = 3;
    case KEY_PRESS = 4;
    case KEY_RELEASE = 5;
    case ENTER_NOTIFY = 6;
    case LEAVE_NOTIFY = 7;
    case FOCUS_CHANGE = 8;
    case PROXIMITY_IN = 9;
    case PROXIMITY_OUT = 10;
    case DRAG_ENTER = 11;
    case DRAG_LEAVE = 12;
    case DRAG_MOTION = 13;
    case DROP_START = 14;
    case SCROLL = 15;
    case GRAB_BROKEN = 16;
    case TOUCH_BEGIN = 17;
    case TOUCH_UPDATE = 18;
    case TOUCH_END = 19;
    case TOUCH_CANCEL = 20;
    case TOUCHPAD_SWIPE = 21;
    case TOUCHPAD_PINCH = 22;
    case PAD_BUTTON_PRESS = 23;
    case PAD_BUTTON_RELEASE = 24;
    case PAD_RING = 25;
    case PAD_STRIP = 26;
    case PAD_GROUP_MODE = 27;
    case TOUCHPAD_HOLD = 28;
    case PAD_DIAL = 29;
}

/**
 * @not-serializable
 */
class GdkEvent
{
    public function getEventType(): GdkEventType {}

    /** @return array{0: float, 1: float}|null [x, y] in the event's surface coordinates; null for an event with none */
    public function getPosition(): ?array {}

    public function getPointerEmulated(): bool {}

    /** The modifier state (GDK_*_MASK) the event carries. */
    public function getModifierState(): int {}
}

/**
 * @not-serializable
 */
class GdkButtonEvent extends GdkEvent
{
    public function getButton(): int {}
}

/**
 * @not-serializable
 */
class GdkTouchEvent extends GdkEvent
{
    public function getEmulatingPointer(): bool {}
}

/**
 * @not-serializable
 */
class GdkScrollEvent extends GdkEvent
{
#if GTK_CHECK_VERSION(4, 20, 0)
    /** Whether the physical motion runs the same way as the event's, or inverted ("natural" scrolling). */
    public function getRelativeDirection(): GdkScrollRelativeDirection {}
#endif
}

/**
 * @not-serializable
 */
class GtkEventController extends GObject
{
    public function setPropagationPhase(GtkPropagationPhase $phase): void {}

    public function getPropagationPhase(): GtkPropagationPhase {}

    public function getWidget(): ?GtkWidget {}

    /** The event the controller is handling: inside a signal GTK delivered, null otherwise. */
    public function getCurrentEvent(): ?GdkEvent {}
}

/**
 * @not-serializable
 */
class GtkEventControllerKey extends GtkEventController
{
    public static function new(): GtkEventControllerKey {}
}

/**
 * @not-serializable
 */
class GtkEventControllerMotion extends GtkEventController
{
    public static function new(): GtkEventControllerMotion {}
}

/**
 * @not-serializable
 */
class GtkEventControllerScroll extends GtkEventController
{
    /** $flags: GTK_EVENT_CONTROLLER_SCROLL_* ORed. */
    public static function new(int $flags): GtkEventControllerScroll {}

    public function getFlags(): int {}

    public function setFlags(int $flags): void {}

    /** The unit of the last scroll signal: WHEEL before any. */
    public function getUnit(): GdkScrollUnit {}
}

/**
 * @not-serializable
 */
class GtkEventControllerLegacy extends GtkEventController
{
    public static function new(): GtkEventControllerLegacy {}
}

/**
 * The display's GTK settings (gtk-long-press-time, gtk-dnd-drag-threshold, ...): read them with g_object_get_property().
 *
 * @not-serializable
 */
class GtkSettings extends GObject
{
    public static function getDefault(): ?GtkSettings {}
}

/**
 * @not-serializable
 */
class GtkIMContext extends GObject
{
    public function setClientWidget(?GtkWidget $widget): void {}

    public function filterKeypress(GdkEvent $event): bool {}

    public function focusIn(): void {}

    public function focusOut(): void {}

    public function reset(): void {}
}

/**
 * @not-serializable
 */
class GtkIMMulticontext extends GtkIMContext
{
    public static function new(): GtkIMMulticontext {}
}

/**
 * @not-serializable
 */
class GtkEventControllerFocus extends GtkEventController
{
    public static function new(): GtkEventControllerFocus {}
}

/**
 * @not-serializable
 */
class GtkGesture extends GtkEventController
{
}

/**
 * @not-serializable
 */
class GtkGestureSingle extends GtkGesture
{
    /** 0 listens to every button. */
    public function setButton(int $button): void {}

    public function getButton(): int {}

    /** The button of the sequence in progress, 0 outside one. */
    public function getCurrentButton(): int {}

    public function setTouchOnly(bool $touchOnly): void {}

    public function getTouchOnly(): bool {}
}

/**
 * @not-serializable
 */
class GtkGestureLongPress extends GtkGestureSingle
{
    public static function new(): GtkGestureLongPress {}
}

/**
 * @not-serializable
 */
class GtkGestureClick extends GtkGestureSingle
{
    public static function new(): GtkGestureClick {}
}
