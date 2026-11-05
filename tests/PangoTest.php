<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('reads a font description\'s metrics through a widget\'s Pango context', function (): void {
    $context = GtkLabel::new('x')->getPangoContext();
    $metrics = $context->getMetrics(PangoFontDescription::fromString('Monospace 12'), null);

    expect($context)->toBeInstanceOf(PangoContext::class)
        ->and($context)->toBeInstanceOf(GObject::class)
        ->and(PANGO_SCALE)->toBe(1024)
        ->and($metrics->getAscent())->toBeGreaterThan(0)
        ->and($metrics->getDescent())->toBeGreaterThan(0)
        ->and($metrics->getHeight())->toBeGreaterThan(0)
        ->and($metrics->getApproximateCharWidth())->toBeGreaterThan(0);
});

it('reads the context\'s own font and language when both are null', function (): void {
    $metrics = GtkLabel::new('x')->getPangoContext()->getMetrics(null, null);

    expect($metrics->getHeight())->toBeGreaterThan(0);
});

it('tells a monospace family from a proportional one through the loaded font', function (): void {
    $context = GtkLabel::new('x')->getPangoContext();
    $mono = $context->loadFont(PangoFontDescription::fromString('Monospace 12'));
    $sans = $context->loadFont(PangoFontDescription::fromString('Sans 12'));

    expect($mono)->toBeInstanceOf(PangoFont::class)
        ->and($mono->getFace())->toBeInstanceOf(PangoFontFace::class)
        ->and($mono->getFace()->getFamily())->toBeInstanceOf(PangoFontFamily::class)
        ->and($mono->getFace()->getFamily()->isMonospace())->toBeTrue()
        ->and($sans->getFace()->getFamily()->isMonospace())->toBeFalse();
});

it('keeps a tab stop in a tab array', function (): void {
    $tabs = PangoTabArray::new(1, true);
    $tabs->setTab(0, PangoTabAlign::LEFT, 32);

    $tabs->getTab(0, $alignment, $location);

    expect($alignment)->toBe(PangoTabAlign::LEFT)
        ->and($location)->toBe(32)
        ->and($tabs->getPositionsInPixels())->toBeTrue();
});
