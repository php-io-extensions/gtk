<?php

/** @generate-class-entries */

/**
 * @var bool
 * @cvalue G_SOURCE_CONTINUE
 */
const G_SOURCE_CONTINUE = UNKNOWN;

/**
 * @var bool
 * @cvalue G_SOURCE_REMOVE
 */
const G_SOURCE_REMOVE = UNKNOWN;

enum GIOCondition: int
{
    case IN = 1;
    case PRI = 2;
    case OUT = 4;
    case ERR = 8;
    case HUP = 16;
    case NVAL = 32;
}

/** A binding refused before reaching GTK: a GTK call made off the thread that owns GTK. */
class GtkException extends RuntimeException
{
}

/** A GError a GLib, GIO or GTK call reported; code is the GError code. */
class GError extends RuntimeException
{
    public readonly string $domain;
}

function gtk_init(): void {}

function gtk_init_check(): bool {}

function gtk_is_initialized(): bool {}

function gtk_get_major_version(): int {}

function gtk_get_minor_version(): int {}

function gtk_get_micro_version(): int {}

/** g_set_prgname(): the program name; GTK names the X11 WM_CLASS after it. Call before GTK starts. */
function g_set_prgname(string $prgname): void {}

/** g_get_prgname(): null until set. */
function g_get_prgname(): ?string {}

/**
 * @var int
 * @cvalue GTK_STYLE_PROVIDER_PRIORITY_APPLICATION
 */
const GTK_STYLE_PROVIDER_PRIORITY_APPLICATION = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_INVALID_LIST_POSITION
 */
const GTK_INVALID_LIST_POSITION = UNKNOWN;

function gtk_style_context_add_provider_for_display(GdkDisplay $display, GtkCssProvider $provider, int $priority): void {}

function gtk_style_context_remove_provider_for_display(GdkDisplay $display, GtkCssProvider $provider): void {}

/** true when a media backend module is installed (the GtkMediaFile GTK builds is not GtkNoMediaFile); needs GTK initialised */
function gtk_media_backend_available(): bool {}

/**
 * @param callable $function called as $function(): bool; true keeps the source, false removes it
 */
function g_timeout_add(int $interval, callable $function): int {}

/**
 * @param callable $function called as $function(): bool; true keeps the source, false removes it
 */
function g_idle_add(callable $function): int {}

/**
 * @param int|resource|Socket $fd
 * @param callable $function called as $function(int $fd, int $condition): bool; true keeps the source
 */
function g_unix_fd_add(mixed $fd, GIOCondition|int $condition, callable $function): int {}

function g_source_remove(int $tag): bool {}

/**
 * @param callable $c_handler called with the signal's parameters, instance first
 */
function g_signal_connect(GObject $instance, string $detailed_signal, callable $c_handler): int {}

/**
 * g_signal_emitv(): emit $detailed_signal on $instance with $params, one per signal parameter.
 * Parameters are passed by the signal's own types: bool, int (also enums and flags; a backed
 * enum case passes its value), float, string, and GObjects of the declared type; null for a
 * string or object. Other parameter types are refused.
 *
 * @return mixed the signal's return value, null for a void signal
 */
function g_signal_emit_by_name(GObject $instance, string $detailed_signal, mixed ...$params): mixed {}

function g_signal_handler_disconnect(GObject $instance, int $handler_id): void {}

function g_signal_handler_is_connected(GObject $instance, int $handler_id): bool {}

/**
 * g_object_get_property(): the property's value as PHP sees a signal argument (objects boxed,
 * enums and flags as ints). A ValueError when $instance has no property $property.
 */
function g_object_get_property(GObject $instance, string $property): mixed {}

function gdk_keyval_to_unicode(int $keyval): int {}

function gdk_keyval_to_lower(int $keyval): int {}

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_NONE
 */
const GTK_EVENT_CONTROLLER_SCROLL_NONE = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_VERTICAL
 */
const GTK_EVENT_CONTROLLER_SCROLL_VERTICAL = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_HORIZONTAL
 */
const GTK_EVENT_CONTROLLER_SCROLL_HORIZONTAL = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_DISCRETE
 */
const GTK_EVENT_CONTROLLER_SCROLL_DISCRETE = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_KINETIC
 */
const GTK_EVENT_CONTROLLER_SCROLL_KINETIC = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES
 */
const GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_PICK_DEFAULT
 */
const GTK_PICK_DEFAULT = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_PICK_INSENSITIVE
 */
const GTK_PICK_INSENSITIVE = UNKNOWN;

/**
 * @var int
 * @cvalue GTK_PICK_NON_TARGETABLE
 */
const GTK_PICK_NON_TARGETABLE = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_SHIFT_MASK
 */
const GDK_SHIFT_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_LOCK_MASK
 */
const GDK_LOCK_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_CONTROL_MASK
 */
const GDK_CONTROL_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_ALT_MASK
 */
const GDK_ALT_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_BUTTON1_MASK
 */
const GDK_BUTTON1_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_BUTTON2_MASK
 */
const GDK_BUTTON2_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_BUTTON3_MASK
 */
const GDK_BUTTON3_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_BUTTON4_MASK
 */
const GDK_BUTTON4_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_BUTTON5_MASK
 */
const GDK_BUTTON5_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_SUPER_MASK
 */
const GDK_SUPER_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_HYPER_MASK
 */
const GDK_HYPER_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_META_MASK
 */
const GDK_META_MASK = UNKNOWN;

/**
 * @var int
 * @cvalue GDK_MODIFIER_MASK
 */
const GDK_MODIFIER_MASK = UNKNOWN;
