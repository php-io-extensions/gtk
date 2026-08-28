<?php
/*
 * Headless proof: the extension is loaded, reports its version, and exposes
 * every slice-zero class. No display needed — nothing here calls into GTK.
 *
 * Run on the Linux box: php examples/proof_of_work.php
 */

declare(strict_types=1);

if (!extension_loaded('gtk')) {
    fwrite(STDERR, "proof_of_work: the gtk extension is not loaded\n");
    exit(1);
}

echo 'extension : gtk ' . phpversion('gtk') . "\n";
echo 'php       : ' . PHP_VERSION . (ZEND_THREAD_SAFE ? ' (ZTS)' : ' (NTS)') . "\n";

$classes = [
    'Gtk\\Bridge\\Bridge',
    'Gtk\\Gtk\\GtkWidget\\GtkWidget',
    'Gtk\\Gtk\\GtkWindow\\GtkWindow',
    'Gtk\\Gtk\\GtkButton\\GtkButton',
    'Gtk\\Gtk\\GtkBox\\GtkBox',
    'Gtk\\Gtk\\GtkOrientable\\GtkOrientable',
    'Gtk\\Gtk\\GtkApplication\\GtkApplication',
    'Gtk\\Gio\\GApplication\\GApplication',
];

$failures = 0;
foreach ($classes as $fqn) {
    if (!class_exists($fqn)) {
        printf("%-44s MISSING\n", $fqn);
        $failures++;
        continue;
    }
    printf("%-44s methods=%d\n", $fqn, count((new ReflectionClass($fqn))->getMethods()));
}

if ($failures > 0) {
    fwrite(STDERR, "proof_of_work: {$failures} class(es) missing\n");
    exit(1);
}

echo "PROOF_OK\n";
