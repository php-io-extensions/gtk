<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/** Whether GTK found a media backend: gtk_media_file_new() builds GtkNoMediaFile without one. */
function mediaBackendMissing(): bool
{
    testApplication();

    return GtkMediaFile::new()->typeName() === 'GtkNoMediaFile';
}

it('builds the media backend\'s default media file with gtk_media_file_new', function (): void {
    $media = GtkMediaFile::new();

    expect($media)->toBeInstanceOf(GtkMediaFile::class)
        ->and($media->typeName())->toStartWith('Gtk')
        ->and($media->typeName())->toEndWith('MediaFile')
        ->and($media->getPlaying())->toBeFalse();
});

it('refuses media files before GTK is initialised instead of trapping', function (string $call): void {
    $code = 'try { '.$call.'; echo "RAN"; } catch (GtkException $e) { echo $e->getMessage(); }';
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');

    expect($out)->toContain('needs GTK initialised');
})->with([
    'media file' => ["GtkMediaFile::newForFilename('/nope.mp4')"],
]);

it('declares GdkPaintable on media streams', function (): void {
    expect(GtkMediaFile::new())->toBeInstanceOf(GdkPaintable::class);
});

it('emits invalidate-contents on a media stream with gdk_paintable_invalidate_contents', function (): void {
    $media = GtkMediaFile::new();
    $seen = 0;
    g_signal_connect($media, 'invalidate-contents', function () use (&$seen): void { $seen++; });

    $media->invalidateContents();

    expect($seen)->toBe(1);
});

it('emits invalidate-size on a media stream with gdk_paintable_invalidate_size', function (): void {
    $media = GtkMediaFile::new();
    $seen = 0;
    g_signal_connect($media, 'invalidate-size', function () use (&$seen): void { $seen++; });

    $media->invalidateSize();

    expect($seen)->toBe(1);
});

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
})->skip(fn (): bool => mediaBackendMissing(), 'no GTK media backend on this machine');

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
