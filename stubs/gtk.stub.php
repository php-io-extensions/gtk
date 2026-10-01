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

function g_signal_handler_disconnect(GObject $instance, int $handler_id): void {}

function g_signal_handler_is_connected(GObject $instance, int $handler_id): bool {}
