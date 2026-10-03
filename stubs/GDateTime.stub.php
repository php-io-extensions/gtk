<?php

/** @generate-class-entries */

/**
 * A GDateTime (immutable, reference counted; not a GObject).
 *
 * @not-serializable
 */
final class GDateTime
{
    private function __construct() {}

    /** g_date_time_new_local(); a date the calendar cannot represent throws ValueError */
    public static function newLocal(int $year, int $month, int $day, int $hour, int $minute, float $seconds): GDateTime {}

    public function getYear(): int {}

    public function getMonth(): int {}

    public function getDayOfMonth(): int {}

    public function toUnix(): int {}
}
