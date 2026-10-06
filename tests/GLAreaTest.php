<?php

declare(strict_types=1);

/*
 * GtkGLArea and GdkGLContext: the GL view a canvas lends. The area is realized
 * in a window, its context read, made current and checked through ext-opengl.
 */

beforeEach(function (): void {
    testApplication();
    if (! extension_loaded('opengl')) {
        $this->markTestSkipped('needs ext-opengl to read the current context');
    }
});

it('has no context before it is realized, and one after', function (): void {
    $window = GtkWindow::new();
    $area = GtkGLArea::new();
    $area->setAutoRender(false);
    $window->setChild($area);

    expect($area->getContext())->toBeNull();

    $window->present();
    iterateUntil(fn (): bool => $area->getRealized(), 3000);
    $context = $area->getContext();

    expect($context)->toBeInstanceOf(GdkGLContext::class)
        ->and($area->getError())->toBeNull()
        ->and($area->getAutoRender())->toBeFalse();
    [$major, $minor] = $context->getVersion();
    expect($major)->toBeGreaterThanOrEqual(3)
        ->and($minor)->toBeInt()
        ->and($context->getApi())->toBeIn([GdkGLAPI::GL, GdkGLAPI::GLES])
        ->and($context->getUseEs())->toBe($context->getApi() === GdkGLAPI::GLES);
    $window->destroy();
});

it('takes its buffer, version and API settings', function (): void {
    $area = GtkGLArea::new();
    $area->setHasDepthBuffer(true);
    $area->setHasStencilBuffer(true);
    $area->setAllowedApis(GdkGLAPI::GL->value | GdkGLAPI::GLES->value);
    $area->setRequiredVersion(3, 2);

    expect($area->getHasDepthBuffer())->toBeTrue()
        ->and($area->getHasStencilBuffer())->toBeTrue()
        ->and($area->getAllowedApis())->toBe(3);
});

it('makes its context current and clears it', function (): void {
    $window = GtkWindow::new();
    $area = GtkGLArea::new();
    $window->setChild($area);
    $window->present();
    iterateUntil(fn (): bool => $area->getRealized(), 3000);

    $area->makeCurrent();
    $current = PHP_OS_FAMILY === 'Darwin' ? CGLGetCurrentContext() : eglGetCurrentContext();
    $gdk = GdkGLContext::getCurrent();

    expect($current)->not->toBeNull()
        ->and($gdk?->pointer())->toBe($area->getContext()->pointer())
        ->and(glGetString(GL_VERSION))->toBeString();

    $area->attachBuffers();
    glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, $bound);
    expect($bound[0])->toBeGreaterThan(0);

    GdkGLContext::clearCurrent();
    expect(GdkGLContext::getCurrent())->toBeNull();
    $window->destroy();
});

it('emits render with the area and its context, and takes the handler\'s answer', function (): void {
    $window = GtkWindow::new();
    $area = GtkGLArea::new();
    $window->setChild($area);
    $seen = [];
    g_signal_connect($area, 'render', function (GtkGLArea $rendered, GdkGLContext $context) use (&$seen, $area): bool {
        glGetIntegerv(GL_DRAW_FRAMEBUFFER_BINDING, $bound);
        $seen[] = [$rendered->pointer() === $area->pointer(), $context->pointer(), $bound[0]];
        glClearColor(1.0, 0.0, 0.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);

        return true;
    });
    $window->present();
    iterateUntil(function () use (&$seen): bool { return $seen !== []; }, 3000);
    $area->queueRender();
    $count = count($seen);
    iterateUntil(function () use (&$seen, $count): bool { return count($seen) > $count; }, 3000);

    expect(count($seen))->toBeGreaterThan($count)
        ->and($seen[0][0])->toBeTrue()
        ->and($seen[0][1])->toBe($area->getContext()->pointer())
        ->and($seen[0][2])->toBeGreaterThan(0);
    $window->destroy();
});
