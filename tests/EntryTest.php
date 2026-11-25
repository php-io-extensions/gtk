<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('sets a widget cursor by name and unsets it with null', function (): void {
    $widget = GtkLabel::new('pointer');

    $widget->setCursorFromName('pointer');
    $cursor = g_object_get_property($widget, 'cursor');

    expect($cursor)->toBeInstanceOf(GObject::class)
        ->and($cursor->typeName())->toBe('GdkCursor')
        ->and(g_object_get_property($cursor, 'name'))->toBe('pointer');

    $widget->setCursorFromName(null);
    expect(g_object_get_property($widget, 'cursor'))->toBeNull();
});

it('keeps the tooltip text a widget is given and unsets it with null', function (): void {
    $widget = GtkButton::newWithLabel('Save');

    expect($widget->getTooltipText())->toBeNull();

    $widget->setTooltipText('Save the file');
    expect($widget->getTooltipText())->toBe('Save the file');

    $widget->setTooltipText(null);
    expect($widget->getTooltipText())->toBeNull();
});

it('draws an entry with or without its frame', function (): void {
    $entry = GtkEntry::new();

    expect($entry->getHasFrame())->toBeTrue();
    $entry->setHasFrame(false);
    expect($entry->getHasFrame())->toBeFalse();
    $entry->setHasFrame(true);
    expect($entry->getHasFrame())->toBeTrue();
});

it('limits an entry to its max length, truncating longer text, and clamps the limit as GTK does', function (): void {
    $entry = GtkEntry::new();
    $entry->getBuffer()->setText('abcdef', -1);

    expect($entry->getMaxLength())->toBe(0);
    $entry->setMaxLength(3);

    expect($entry->getMaxLength())->toBe(3)
        ->and($entry->getBuffer()->getText())->toBe('abc');

    $entry->setMaxLength(70000);
    expect($entry->getMaxLength())->toBe(65535);

    $entry->setMaxLength(0);
    expect($entry->getMaxLength())->toBe(0)
        ->and(fn () => $entry->setMaxLength(PHP_INT_MAX))->toThrow(ValueError::class);
});

it('makes an entry editable or read-only through GtkEditable', function (): void {
    $entry = GtkEntry::new();

    expect($entry)->toBeInstanceOf(GtkEditable::class)
        ->and($entry->getEditable())->toBeTrue();

    $entry->setEditable(false);
    expect($entry->getEditable())->toBeFalse();
    $entry->setEditable(true);
    expect($entry->getEditable())->toBeTrue();
});

it('activates the default widget from an entry when asked to', function (): void {
    $entry = GtkEntry::new();

    expect($entry->getActivatesDefault())->toBeFalse();
    $entry->setActivatesDefault(true);
    expect($entry->getActivatesDefault())->toBeTrue();
    $entry->setActivatesDefault(false);
    expect($entry->getActivatesDefault())->toBeFalse();
});

it('sets an entry icon by name at either position and clears it with null', function (): void {
    $entry = GtkEntry::new();

    $entry->setIconFromIconName(GtkEntryIconPosition::PRIMARY, 'edit-find-symbolic');
    $entry->setIconFromIconName(GtkEntryIconPosition::SECONDARY, 'edit-clear-symbolic');

    expect(g_object_get_property($entry, 'primary-icon-name'))->toBe('edit-find-symbolic')
        ->and(g_object_get_property($entry, 'secondary-icon-name'))->toBe('edit-clear-symbolic');

    $entry->setIconFromIconName(GtkEntryIconPosition::PRIMARY, null);
    $entry->setIconFromIconName(GtkEntryIconPosition::SECONDARY, null);

    expect(g_object_get_property($entry, 'primary-icon-name'))->toBeNull()
        ->and(g_object_get_property($entry, 'secondary-icon-name'))->toBeNull()
        ->and(GtkEntryIconPosition::PRIMARY->value)->toBe(0)
        ->and(GtkEntryIconPosition::SECONDARY->value)->toBe(1);
});
