<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('reports whether a media backend is present', function (): void {
    expect(gtk_media_backend_available())->toBeBool();
});

it('refuses the media probe and media files before GTK is initialised instead of trapping', function (string $call): void {
    $code = 'try { '.$call.'; echo "RAN"; } catch (GtkException $e) { echo $e->getMessage(); }';
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');

    expect($out)->toContain('needs GTK initialised');
})->with([
    'probe' => ['gtk_media_backend_available()'],
    'media file' => ["GtkMediaFile::newForFilename('/nope.mp4')"],
]);

it('plays a clip to the end and flags a missing file', function (): void {
    $media = GtkMediaFile::newForFilename(__DIR__.'/fixtures/clip.mp4');
    $video = GtkVideo::new();
    $video->setMediaStream($media);
    $video->setAutoplay(false);
    $window = GtkApplicationWindow::new(testApplication());
    $window->setChild($video);
    $window->present();
    $ended = 0;
    g_signal_connect($media, 'notify::ended', function () use (&$ended, $media): void { if ($media->getEnded()) { $ended++; } });
    $media->play();
    $until = microtime(true) + 5.0;
    while ($ended === 0 && microtime(true) < $until) { iterateFor(0.05); }

    expect($ended)->toBe(1)
        ->and($media->getDuration())->toBeGreaterThan(900_000)
        ->and($media->hasVideo())->toBeTrue()
        ->and($media->getError())->toBeNull()
        ->and($video->getMediaStream())->toBe($media)
        ->and($video->getAutoplay())->toBeFalse();

    $bad = GtkMediaFile::newForFilename('/nope/clip.mp4');
    iterateFor(0.3);
    expect($bad->getError())->toBeInstanceOf(GError::class)
        ->and($bad->getError()->domain)->not->toBe('');
    $window->destroy();
})->skip(function (): bool {
    testApplication();

    return ! gtk_media_backend_available();
}, 'no GTK media backend on this machine');

it('answers stream state without a backend', function (): void {
    $media = GtkMediaFile::newForFilename(__DIR__.'/fixtures/clip.mp4');
    $media->setMuted(true);
    $media->setLoop(true);

    expect($media)->toBeInstanceOf(GtkMediaStream::class)
        ->and($media->getMuted())->toBeTrue()
        ->and($media->getLoop())->toBeTrue()
        ->and($media->getPlaying())->toBeFalse()
        ->and($media->getTimestamp())->toBe(0);

    $media->clear();
    $media->setFilename(null);
    expect($media->getEnded())->toBeFalse();
});
