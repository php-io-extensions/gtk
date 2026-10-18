<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GCancellable extends GObject
{
    public static function new(): GCancellable {}

    public function cancel(): void {}

    public function isCancelled(): bool {}
}

/**
 * A finished asynchronous call's result, handed to its ready callback; read it with the call's
 * *Finish() method.
 *
 * @not-serializable
 */
class GAsyncResult extends GObject
{
}

/**
 * @not-serializable
 */
class GtkUriLauncher extends GObject
{
    public static function new(?string $uri): GtkUriLauncher {}

    public function getUri(): ?string {}

    public function setUri(?string $uri): void {}

    /**
     * gtk_uri_launcher_launch(): opens the URI in its handler (the browser for http and https).
     * @param callable|null $callback called once with (GtkUriLauncher, GAsyncResult); null launches with no callback
     */
    public function launch(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** True when the URI opened; the launch's GError is thrown as GError. GTK answers a result from any other call with a critical and false. */
    public function launchFinish(GAsyncResult $result): bool {}
}
