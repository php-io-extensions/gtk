<?php

/** @generate-class-entries */

/**
 * Signals: notify::playing, notify::ended, notify::error, notify::timestamp.
 *
 * @not-serializable
 */
class GtkMediaStream extends GObject
{
    public function play(): void {}

    public function pause(): void {}

    public function getPlaying(): bool {}

    public function setPlaying(bool $playing): void {}

    public function getEnded(): bool {}

    /** gtk_media_stream_get_error(): the GError as an exception object, not thrown; null while the stream is fine */
    public function getError(): ?GError {}

    /** gtk_media_stream_seek(); timestamp in microseconds */
    public function seek(int $timestamp): void {}

    public function isSeekable(): bool {}

    /** microseconds */
    public function getTimestamp(): int {}

    /** microseconds; 0 until known */
    public function getDuration(): int {}

    public function getMuted(): bool {}

    public function setMuted(bool $muted): void {}

    public function getLoop(): bool {}

    public function setLoop(bool $loop): void {}

    public function hasVideo(): bool {}
}

/**
 * The media backend's GtkMediaFile subclass (GtkGstMediaFile with libgtk-4-media-gstreamer, GtkNoMediaFile without one).
 *
 * @not-serializable
 */
class GtkMediaFile extends GtkMediaStream
{
    /** gtk_media_file_new_for_filename(); needs GTK initialised (the backend lookup asserts otherwise) */
    public static function newForFilename(string $filename): GtkMediaFile {}

    public function setFilename(?string $filename): void {}

    public function clear(): void {}
}

/**
 * @not-serializable
 */
class GtkVideo extends GtkWidget
{
    public static function new(): GtkVideo {}

    public function getMediaStream(): ?GtkMediaStream {}

    public function setMediaStream(?GtkMediaStream $stream): void {}

    public function getAutoplay(): bool {}

    public function setAutoplay(bool $autoplay): void {}

    public function setLoop(bool $loop): void {}
}
