<?php

declare(strict_types=1);

require_once __DIR__ . '/../scripts/support.php';

$fixtures = __DIR__ . '/fixtures/support';

it('counts the live constructors, methods and functions of the GIR files', function () use ($fixtures): void {
    expect(support_counted(["{$fixtures}/Mini-4.0.gir"]))->toBe([
        'GtkMini' => ['gtk_mini_get_value', 'gtk_mini_set_value'],
        'GtkMiniChild' => ['gtk_mini_child_new'],
        'GtkMiniPart' => ['gtk_mini_part_free'],
        'functions' => ['gtk_mini_init'],
    ]);
});

it('names a member as its binding: the type prefix dropped, the rest camel case', function (): void {
    expect(support_php_name('GtkMini', 'gtk_mini_set_value', 'mini'))->toBe(['GtkMini', 'setValue'])
        ->and(support_php_name('GtkMiniPart', 'gtk_mini_part_free', 'mini_part'))->toBe(['GtkMiniPart', 'free'])
        ->and(support_php_name('functions', 'gtk_mini_init', ''))->toBe(['', 'gtk_mini_init']);
});

it('reads the bound methods and functions of the stubs', function () use ($fixtures): void {
    expect(support_bound($fixtures))->toBe([
        'GtkMini' => ['getValue' => true, 'frobnicate' => true],
        'GtkMiniChild' => ['new' => true, 'setValue' => true],
        '' => ['gtk_mini_init' => true],
    ]);
});

it('renders one line per member and lists the bindings that match no member', function () use ($fixtures): void {
    $gir = ["{$fixtures}/Mini-4.0.gir"];
    $md = support_render(support_counted($gir), support_bound($fixtures), 'GTK 4.0.0, gdk, gsk', '2026-10-22', support_prefixes($gir), support_parents($gir));

    expect($md)->toContain('- [x] `gtk_mini_get_value`')
        ->toContain('- [x] `gtk_mini_child_new`')
        ->toContain('## GtkMiniPart (0 / 1)')
        ->toContain('4 / 5')
        ->toContain('- `GtkMini::frobnicate`')
        ->and(substr_count($md, '`GtkMini::frobnicate`'))->toBe(1)
        ->and($md)->not->toContain('getValue`');
});

it('counts a method declared on a subclass as the member of the ancestor that declares it', function () use ($fixtures): void {
    $gir = ["{$fixtures}/Mini-4.0.gir"];
    $md = support_render(support_counted($gir), support_bound($fixtures), 'GTK 4.0.0, gdk, gsk', '2026-10-22', support_prefixes($gir), support_parents($gir));

    expect($md)->toContain('- [x] `gtk_mini_set_value`')
        ->not->toContain('`GtkMiniChild::setValue`')
        ->and(support_parents($gir))->toBe(['GtkMiniChild' => 'GtkMini']);
});

it('computes the badge from the counts', function (): void {
    expect(support_badge('GTK API', 468, 3850))
        ->toBe('[![GTK API](https://img.shields.io/badge/GTK_API-12.2%25_%28468%2F3850%29-blue?style=flat-square)](SUPPORT.md)');
});

it('compares a support list without its date', function (): void {
    expect(support_same("# x\n\nGTK 1 — 2 / 4 members bound (50.0%) — 2026-10-22\n", "# x\n\nGTK 1 — 2 / 4 members bound (50.0%) — 2026-11-01\n"))->toBeTrue()
        ->and(support_same("# x\n\nGTK 1 — 2 / 4 — 2026-10-22\n", "# x\n\nGTK 1 — 3 / 4 — 2026-10-22\n"))->toBeFalse();
});
