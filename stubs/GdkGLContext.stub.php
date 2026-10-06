<?php

/** @generate-class-entries */

/** GdkGLAPI flags (gdk/gdkenums.h). */
enum GdkGLAPI: int
{
    case GL = 1;
    case GLES = 2;
}

/**
 * @not-serializable
 */
class GdkGLContext extends GObject
{
    /** gdk_gl_context_make_current() */
    public function makeCurrent(): void {}

    /** gdk_gl_context_clear_current() */
    public static function clearCurrent(): void {}

    /** gdk_gl_context_get_current(); null when none is current */
    public static function getCurrent(): ?GdkGLContext {}

    /** gdk_gl_context_realize(); its GError is thrown as GtkException */
    public function realize(): void {}

    public function getUseEs(): bool {}

    /**
     * gdk_gl_context_get_version(): major, minor
     *
     * @return array{int, int}
     */
    public function getVersion(): array {}

    public function getApi(): GdkGLAPI {}
}
