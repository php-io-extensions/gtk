<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('aligns, sizes and styles a widget', function (): void {
    $label = GtkLabel::new('x');
    $label->setHalign(GtkAlign::CENTER);
    $label->setValign(GtkAlign::END);
    $label->setSizeRequest(120, 30);
    $label->setMarginStart(4);
    $label->addCssClass('tk-probe');
    $provider = GtkCssProvider::new();
    $provider->loadFromString('.tk-probe { color: #ff0000; }');
    gtk_style_context_add_provider_for_display(GdkDisplay::getDefault(), $provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);

    expect($label->getColor())->toBe([1.0, 0.0, 0.0, 1.0])
        ->and($label->getHalign())->toBe(GtkAlign::CENTER)
        ->and($label->getValign())->toBe(GtkAlign::END)
        ->and($label->getSizeRequest())->toBe([120, 30])
        ->and($label->hasCssClass('tk-probe'))->toBeTrue()
        ->and($label->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBeGreaterThanOrEqual(120)
        ->and($label->getSensitive())->toBeTrue();

    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $box->append($label);
    $box->setSensitive(false);
    expect($label->getSensitive())->toBeTrue()->and($label->isSensitive())->toBeFalse();
    $box->setSensitive(true);
    $box->remove($label);

    $label->setSensitive(false);
    $label->removeCssClass('tk-probe');
    gtk_style_context_remove_provider_for_display(GdkDisplay::getDefault(), $provider);
    expect($label->getSensitive())->toBeFalse()->and($label->hasCssClass('tk-probe'))->toBeFalse();
});

it('places children in a grid, a fixed, and reorders a box', function (): void {
    $grid = GtkGrid::new();
    $grid->setRowSpacing(2);
    $a = GtkLabel::new('a');
    $grid->attach($a, 1, 0, 2, 1);
    $fixed = GtkFixed::new();
    $b = GtkLabel::new('b');
    $fixed->put($b, 10.0, 20.0);
    $fixed->move($b, 30.0, 40.0);
    // GTK applies a fixed child's transform at layout time: present the fixed before reading the position back.
    $window = GtkWindow::new();
    $window->setChild($fixed);
    $window->present();
    iterateFor(0.1);
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $c = GtkLabel::new('c');
    $d = GtkLabel::new('d');
    $box->append($c);
    $box->append($d);
    $box->reorderChildAfter($d, null);
    expect($box->getFirstChild())->toBe($d)
        ->and($d->getNextSibling())->toBe($c)
        ->and($c->getNextSibling())->toBeNull()
        ->and($c->getFirstChild())->toBeNull();

    expect($grid->getChildAt(1, 0))->toBe($a)
        ->and($grid->getChildAt(0, 0))->toBeNull()
        ->and($grid->getRowSpacing())->toBe(2)
        ->and(fn () => $grid->attach($a, 0, 0, 0, 1))->toThrow(ValueError::class)
        ->and($fixed->getChildPosition($b))->toBe([30.0, 40.0])
        ->and($c->getParent())->toBe($box)
        ->and($d->getParent())->toBe($box);

    $grid->remove($a);
    $fixed->remove($b);
    $box->remove($c);
    expect($a->getParent())->toBeNull()->and($b->getParent())->toBeNull();
    $window->destroy();
});

it('exposes a window surface that reports its size and layout', function (): void {
    $window = GtkApplicationWindow::new(testApplication());
    $window->setDefaultSize(200, 100);
    $layouts = [];
    $window->present();
    iterateFor(0.3);
    $surface = $window->getSurface();
    g_signal_connect($surface, 'layout', function (GdkSurface $s, int $w, int $h) use (&$layouts): void { $layouts[] = [$w, $h]; });
    $window->setDefaultSize(260, 120);
    iterateFor(0.3);

    expect($surface)->toBeInstanceOf(GdkSurface::class)
        ->and($surface->getWidth())->toBeGreaterThan(0)
        ->and($layouts)->not->toBe([])
        ->and(GtkLabel::new('plain')->getSurface())->toBeNull()
        ->and($window->getNative())->toBe($window)
        ->and($window->getRoot())->toBe($window);

    // A padded box: get_width is the content box, compute_bounds the border box.
    $padded = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $padded->addCssClass('tk-bounds-probe');
    $provider = GtkCssProvider::new();
    $provider->loadFromString('.tk-bounds-probe { padding: 10px; }');
    gtk_style_context_add_provider_for_display(GdkDisplay::getDefault(), $provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    $window->setChild($padded);
    iterateFor(0.3);
    [$x, $y, $width, $height] = $padded->computeBounds($padded);
    expect($padded->getWidth())->toBe((int) $width - 20)
        ->and($padded->getHeight())->toBe((int) $height - 20)
        // a widget's own coordinates start at its content box, so its border box starts one padding earlier
        ->and([$x, $y])->toBe([-10.0, -10.0])
        ->and($padded->computeBounds(GtkLabel::new('elsewhere')))->toBeNull();
    gtk_style_context_remove_provider_for_display(GdkDisplay::getDefault(), $provider);
    $window->destroy();
});
