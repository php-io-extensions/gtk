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
    $laidOut = iterateUntil(fn (): bool => $fixed->getChildPosition($b) === [30.0, 40.0]);
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

    expect($laidOut)->toBeTrue()
        ->and($grid->getChildAt(1, 0))->toBe($a)
        ->and($grid->getChildAt(0, 0))->toBeNull()
        ->and($grid->getRowSpacing())->toBe(2)
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
        ->and(method_exists(GtkLabel::class, 'getSurface'))->toBeFalse()
        ->and($window->getNative())->toBe($window)
        ->and($window->getRoot())->toBe($window)
        ->and(GtkLabel::new('loose')->getNative())->toBeNull()
        ->and(GtkLabel::new('loose')->getRoot())->toBeNull();

    // A padded box: get_width is the content box, compute_bounds the border box.
    $padded = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $padded->addCssClass('tk-bounds-probe');
    $provider = GtkCssProvider::new();
    $provider->loadFromString('.tk-bounds-probe { padding: 10px; }');
    gtk_style_context_add_provider_for_display(GdkDisplay::getDefault(), $provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    $window->setChild($padded);
    iterateFor(0.3);
    $computed = $padded->computeBounds($padded, $bounds);
    $strangers = $padded->computeBounds(GtkLabel::new('elsewhere'), $none);
    expect($computed)->toBeTrue()
        ->and($bounds)->toBeInstanceOf(GrapheneRect::class)
        ->and($padded->getWidth())->toBe((int) $bounds->size->width - 20)
        ->and($padded->getHeight())->toBe((int) $bounds->size->height - 20)
        // a widget's own coordinates start at its content box, so its border box starts one padding earlier
        ->and([$bounds->origin->x, $bounds->origin->y])->toBe([-10.0, -10.0])
        ->and($strangers)->toBeFalse()
        ->and($none)->toBeInstanceOf(GrapheneRect::class);
    gtk_style_context_remove_provider_for_display(GdkDisplay::getDefault(), $provider);
    $window->destroy();
});

it('holds two children in a paned and moves its position', function (): void {
    $paned = GtkPaned::new(GtkOrientation::HORIZONTAL);
    [$a, $b] = [GtkLabel::new('a'), GtkLabel::new('b')];
    $paned->setStartChild($a);
    $paned->setEndChild($b);
    $paned->setStartChild($a);
    $paned->setResizeStartChild(true);
    $paned->setResizeEndChild(false);
    $paned->setShrinkStartChild(false);
    $paned->setShrinkEndChild(false);
    $paned->setWideHandle(true);
    $paned->setPosition(80);
    $moved = 0;
    g_signal_connect($paned, 'notify::position', function () use (&$moved): void { $moved++; });
    $paned->setPosition(90);

    expect($paned->getStartChild())->toBe($a)->and($paned->getEndChild())->toBe($b)
        ->and($paned->getPosition())->toBe(90)->and($moved)->toBe(1)
        ->and($paned->getResizeStartChild())->toBeTrue()->and($paned->getResizeEndChild())->toBeFalse()
        ->and($paned->getShrinkStartChild())->toBeFalse()->and($paned->getShrinkEndChild())->toBeFalse()
        ->and($paned->getWideHandle())->toBeTrue();
    $paned->setEndChild(null);
    $paned->setPosition(-1);
    expect($paned->getEndChild())->toBeNull()->and($b->getParent())->toBeNull()->and(g_object_get_property($paned, 'position-set'))->toBeFalse();
});

it('appends notebook pages with tab labels and switches between them', function (): void {
    $notebook = GtkNotebook::new();
    [$one, $two] = [GtkLabel::new('1'), GtkLabel::new('2')];
    expect($notebook->getCurrentPage())->toBe(-1)
        ->and($notebook->appendPage($one, GtkLabel::new('One')))->toBe(0)
        ->and($notebook->appendPage($two, null))->toBe(1);
    $notebook->setTabLabelText($two, 'Two');
    $notebook->setScrollable(true);
    $switched = [];
    g_signal_connect($notebook, 'switch-page', function (GtkNotebook $nb, GtkWidget $page, int $num) use (&$switched, $two): void { $switched[] = [$num, $page === $two]; });
    $notebook->setCurrentPage(1);
    $stray = GtkLabel::new('x');

    expect($notebook->getNPages())->toBe(2)->and($notebook->getCurrentPage())->toBe(1)
        ->and($notebook->pageNum($two))->toBe(1)->and($notebook->pageNum($stray))->toBe(-1)
        ->and($notebook->getTabLabelText($one))->toBe('One')->and($notebook->getTabLabelText($two))->toBe('Two')
        ->and($notebook->getNthPage(0))->toBe($one)->and($notebook->getNthPage(5))->toBeNull()->and($notebook->getNthPage(-1))->toBe($two)
        ->and($switched)->toBe([[1, true]])
        ->and($notebook->getShowTabs())->toBeTrue()->and($notebook->getScrollable())->toBeTrue()
        ->and($notebook->getTabLabelText($stray))->toBeNull();
    $notebook->setCurrentPage(5);
    $notebook->removePage(5);
    expect($notebook->getCurrentPage())->toBe(1)->and($notebook->getNPages())->toBe(2);
    $notebook->removePage(0);
    expect($notebook->getNPages())->toBe(1)->and($one->getParent())->toBeNull()->and($notebook->getNthPage(0))->toBe($two);
});

it('builds a GraphenePoint from both fields', function (): void {
    $point = new GraphenePoint(1.5, -2.0);

    expect([$point->x, $point->y])->toBe([1.5, -2.0])
        ->and(fn () => $point->x = 'a')->toThrow(TypeError::class);
});

it('hands a paned a child that has a parent, which GTK answers with a critical, keeping both slots', function (): void {
    $run = gtkChild(<<<'PHP'
        $paned = GtkPaned::new(GtkOrientation::HORIZONTAL);
        [$a, $b] = [GtkLabel::new('a'), GtkLabel::new('b')];
        $paned->setStartChild($a);
        $paned->setEndChild($b);
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $boxed = GtkLabel::new('c');
        $box->append($boxed);

        $paned->setEndChild($a);
        $paned->setStartChild($boxed);
        $kept = [$paned->getStartChild() === $a, $paned->getEndChild() === $b, $boxed->getParent() === $box];
        // Disposing the paned leaves the box's child alone.
        $paned = null;
        gc_collect_cycles();
        drainContext();

        return [...$kept, $boxed->getParent() === $box];
    PHP);

    expect($run['result'])->toBe([true, true, true, true])
        ->and($run['stderr'])->toContain("gtk_paned_set_end_child: assertion 'child == NULL || paned->end_child == child || gtk_widget_get_parent (child) == NULL' failed")
        ->and($run['stderr'])->toContain("gtk_paned_set_start_child: assertion 'child == NULL || paned->start_child == child || gtk_widget_get_parent (child) == NULL' failed");
});

it('hands a notebook a page that has a parent and a tab text for a stranger, as GTK takes them', function (): void {
    $run = gtkChild(<<<'PHP'
        $notebook = GtkNotebook::new();
        [$one, $two] = [GtkLabel::new('1'), GtkLabel::new('2')];
        $notebook->appendPage($one, GtkLabel::new('One'));
        $notebook->appendPage($two, null);
        $stray = GtkLabel::new('x');

        // GTK logs that $one has a parent, then adds a page anyway and answers the index of $one's first page.
        $again = $notebook->appendPage($one, null);
        $notebook->setTabLabelText($stray, 'y');

        return [$again, $notebook->getNPages(), $notebook->getTabLabelText($stray)];
    PHP);

    expect($run['result'])->toBe([0, 3, null])
        ->and($run['stderr'])->toContain("gtk_widget_set_parent: assertion '_gtk_widget_get_parent (widget) == NULL' failed")
        ->and($run['stderr'])->toContain("gtk_notebook_set_tab_label: assertion 'list != NULL' failed");
});

it('activates a widget\'s action with gtk_widget_activate_action_variant', function (): void {
    $window = GtkWindow::new();
    $group = GSimpleActionGroup::new();
    $action = GSimpleAction::new('go', 'i');
    $received = [];
    g_signal_connect($action, 'activate', function (GSimpleAction $a, GVariant $p) use (&$received): void { $received[] = $p->getInt32(); });
    $group->addAction($action);
    $window->insertActionGroup('nav', $group);

    expect($window->activateActionVariant('nav.go', GVariant::newInt32(7)))->toBeTrue()
        ->and($window->activateActionVariant('nav.none', null))->toBeFalse()
        ->and($received)->toBe([7]);

    $window->destroy();
});

it('hides and shows a widget with gtk_widget_hide and gtk_widget_show', function (): void {
    gtk_init();
    $label = GtkLabel::new('x');

    $label->hide();
    $hidden = $label->getVisible();
    $label->show();

    expect($hidden)->toBeFalse()
        ->and($label->getVisible())->toBeTrue();
});
