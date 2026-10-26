<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GdkSurface extends GObject
{
    public function getWidth(): int {}

    public function getHeight(): int {}

    /** gdk_surface_get_scale (GTK 4.12): the fractional scale; getScaleFactor() rounds it up. */
    public function getScale(): float {}
}
