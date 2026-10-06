<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GtkGLArea extends GtkWidget
{
    public static function new(): GtkGLArea {}

    /** gtk_gl_area_get_context(); null before the widget is realized */
    public function getContext(): ?GdkGLContext {}

    /** gtk_gl_area_make_current() */
    public function makeCurrent(): void {}

    /** gtk_gl_area_attach_buffers(): the area's framebuffer bound for drawing */
    public function attachBuffers(): void {}

    public function queueRender(): void {}

    public function getAutoRender(): bool {}

    public function setAutoRender(bool $autoRender): void {}

    public function getHasDepthBuffer(): bool {}

    public function setHasDepthBuffer(bool $hasDepthBuffer): void {}

    public function getHasStencilBuffer(): bool {}

    public function setHasStencilBuffer(bool $hasStencilBuffer): void {}

    /** GdkGLAPI flags, as an int */
    public function setAllowedApis(int $apis): void {}

    /** GdkGLAPI flags, as an int */
    public function getAllowedApis(): int {}

    /** gtk_gl_area_set_required_version() */
    public function setRequiredVersion(int $major, int $minor): void {}

    /** gtk_gl_area_get_error(); the GError's message, or null */
    public function getError(): ?string {}
}
