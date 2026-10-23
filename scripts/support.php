<?php

declare(strict_types=1);

/*
 * The support list: every member of GTK 4, GDK and GSK as the installed GIR files declare it,
 * marked bound when a stub declares the PHP method or function its naming rule gives.
 *
 *   php84 scripts/support.php           writes SUPPORT.md and the README badge
 *   php84 scripts/support.php --check   exits 1 when either differs (the date is not compared)
 *
 * A member is a constructor, method or function element that is not deprecated and not moved.
 * Virtual methods, signals and properties are not members: properties are reached through the
 * GObject functions g_object_get_property and g_object_set_property, outside these libraries.
 */

const SUPPORT_LABEL = 'GTK API';
const SUPPORT_CORE = 'http://www.gtk.org/introspection/core/1.0';
const SUPPORT_C = 'http://www.gtk.org/introspection/c/1.0';

/**
 * @param list<string> $girFiles
 * @return array<string, list<string>> owner (C type, 'functions' for free functions) => sorted C identifiers
 */
function support_counted(array $girFiles): array
{
    $counted = [];
    foreach ($girFiles as $file) {
        $xml = simplexml_load_file($file);
        if ($xml === false) {
            throw new RuntimeException("Cannot read {$file}.");
        }
        foreach ($xml->children(SUPPORT_CORE)->namespace->children(SUPPORT_CORE) as $owner) {
            if ($owner->getName() === 'function') {
                if (support_live($owner)) {
                    $counted['functions'][] = support_identifier($owner);
                }
                continue;
            }
            $type = (string) $owner->attributes(SUPPORT_C)->type;
            if ($type === '') {
                continue;
            }
            foreach ($owner->children(SUPPORT_CORE) as $member) {
                if (in_array($member->getName(), ['constructor', 'method', 'function'], true) && support_live($member)) {
                    $counted[$type][] = support_identifier($member);
                }
            }
        }
    }
    foreach ($counted as &$keys) {
        $keys = array_values(array_unique($keys));
        sort($keys, SORT_STRING);
    }
    unset($keys);
    ksort($counted, SORT_STRING);

    return $counted;
}

function support_live(SimpleXMLElement $element): bool
{
    // The GIR's own attributes are in no namespace; a namespaced child reads them through attributes('').
    $plain = $element->attributes('');

    return (string) $plain['deprecated'] !== '1' && (string) $plain['moved-to'] === '';
}

function support_identifier(SimpleXMLElement $element): string
{
    return (string) $element->attributes(SUPPORT_C)->identifier;
}

/**
 * The symbol prefix of each owner (C type => 'notebook'), for support_php_name().
 * @param list<string> $girFiles
 * @return array<string, string>
 */
function support_prefixes(array $girFiles): array
{
    $prefixes = [];
    foreach ($girFiles as $file) {
        $xml = simplexml_load_file($file);
        foreach ($xml->children(SUPPORT_CORE)->namespace->children(SUPPORT_CORE) as $owner) {
            $type = (string) $owner->attributes(SUPPORT_C)->type;
            if ($type !== '') {
                $prefixes[$type] = (string) $owner->attributes(SUPPORT_C)->{'symbol-prefix'};
            }
        }
    }

    return $prefixes;
}

/**
 * A member as its binding: gtk_notebook_insert_page on GtkNotebook => ['GtkNotebook', 'insertPage'];
 * a free function keeps its name, as a function ('').
 * @return array{string, string}
 */
function support_php_name(string $owner, string $key, string $prefix): array
{
    if ($owner === 'functions' || $prefix === '' || preg_match('/^[a-z0-9]+_' . preg_quote($prefix, '/') . '_(.+)$/', $key, $m) !== 1) {
        return ['', $key];
    }

    return [$owner, lcfirst(str_replace('_', '', ucwords($m[1], '_')))];
}

/**
 * The PHP classes and functions the stubs declare.
 * @return array<string, array<string, true>> PHP class ('' for functions) => method names
 */
function support_bound(string $stubDir): array
{
    $bound = [];
    foreach (glob(rtrim($stubDir, '/') . '/*.stub.php') ?: [] as $file) {
        foreach (support_declared(file_get_contents($file)) as $class => $methods) {
            foreach ($methods as $method) {
                $bound[$class][$method] = true;
            }
        }
    }

    return $bound;
}

/**
 * The classes (with their namespace) and public methods, and the free functions, of one stub.
 * @return array<string, list<string>>
 */
function support_declared(string $source): array
{
    $tokens = token_get_all($source);
    $out = [];
    $namespace = '';
    $braced = false;
    $depth = 0;
    $class = null;
    $classDepth = -1;
    $next = static function (int $i) use ($tokens): int {
        for ($i++; $i < count($tokens); $i++) {
            if (! is_array($tokens[$i]) || ! in_array($tokens[$i][0], [T_WHITESPACE, T_COMMENT, T_DOC_COMMENT], true)) {
                return $i;
            }
        }

        return $i;
    };
    for ($i = 0, $n = count($tokens); $i < $n; $i++) {
        $token = $tokens[$i];
        if ($token === '{' || (is_array($token) && in_array($token[0], [T_CURLY_OPEN, T_DOLLAR_OPEN_CURLY_BRACES], true))) {
            $depth++;
            continue;
        }
        if ($token === '}') {
            if ($depth === 0 && $braced) {
                $braced = false;
                $namespace = '';
                continue;
            }
            $depth--;
            if ($class !== null && $depth === $classDepth) {
                $class = null;
            }
            continue;
        }
        if (! is_array($token)) {
            continue;
        }
        if ($token[0] === T_NAMESPACE) {
            $j = $next($i);
            $namespace = $tokens[$j] === '{' ? '' : $tokens[$j][1];
            $k = $tokens[$j] === '{' ? $j : $next($j);
            if ($tokens[$k] === '{') {
                $braced = true;
                $i = $k;
            }
            continue;
        }
        if (in_array($token[0], [T_CLASS, T_INTERFACE, T_TRAIT, T_ENUM], true)) {
            $j = $next($i);
            if (is_array($tokens[$j]) && $tokens[$j][0] === T_STRING) {
                $class = ltrim("{$namespace}\\{$tokens[$j][1]}", '\\');
                $classDepth = $depth;
                $out[$class] ??= [];
                for ($i = $j; $tokens[$i] !== '{'; $i++) {
                }
                $depth++;
            }
            continue;
        }
        if ($token[0] === T_FUNCTION) {
            $j = $next($i);
            // A method name may be a keyword (`new`); a closure has `(` here.
            if (! is_array($tokens[$j]) || preg_match('/^\w+$/', $tokens[$j][1]) !== 1) {
                continue;
            }
            if ($class === null) {
                $out[''][] = ltrim("{$namespace}\\{$tokens[$j][1]}", '\\');
            } elseif ($depth === $classDepth + 1 && ! support_hidden($tokens, $i)) {
                $out[$class][] = $tokens[$j][1];
            }
        }
    }

    return array_map(static fn (array $methods): array => array_values(array_unique($methods)), $out);
}

/** A private or protected method: the modifiers before `function`. */
function support_hidden(array $tokens, int $i): bool
{
    for ($k = $i - 1; $k >= 0; $k--) {
        $t = $tokens[$k];
        if (is_array($t) && in_array($t[0], [T_WHITESPACE, T_COMMENT, T_DOC_COMMENT, T_STATIC, T_ABSTRACT, T_FINAL, T_PUBLIC], true)) {
            continue;
        }

        return is_array($t) && in_array($t[0], [T_PRIVATE, T_PROTECTED], true);
    }

    return false;
}

/**
 * @param array<string, list<string>> $counted
 * @param array<string, array<string, true>> $bound
 * @param array<string, string> $prefixes
 * @param array<string, string> $parents C type => parent C type, for a method a stub declares on a subclass
 */
function support_render(array $counted, array $bound, string $library, string $date, array $prefixes = [], array $parents = []): string
{
    // owner => PHP method => key, so a bound method finds its member up the parent chain.
    $byMethod = [];
    foreach ($counted as $owner => $keys) {
        foreach ($keys as $key) {
            [$class, $method] = support_php_name($owner, $key, $prefixes[$owner] ?? support_guess_prefix($owner));
            if ($class !== '') {
                $byMethod[$owner][$method] = $key;
            }
        }
    }
    $boundKeys = [];
    $outside = [];
    foreach ($bound as $class => $methods) {
        foreach (array_keys($methods) as $method) {
            if ($class === '') {
                $boundKeys[$method] = true;
                continue;
            }
            $found = null;
            for ($owner = $class, $seen = 0; $owner !== null && $seen < 32; $owner = $parents[$owner] ?? null, $seen++) {
                if (isset($byMethod[$owner][$method])) {
                    $found = $byMethod[$owner][$method];
                    break;
                }
            }
            if ($found === null) {
                $outside[] = "- `{$class}::{$method}`";
            } else {
                $boundKeys[$found] = true;
            }
        }
    }
    $countedKeys = array_fill_keys(array_merge(...array_values($counted ?: [[]])), true);
    foreach (array_keys($bound[''] ?? []) as $function) {
        if (! isset($countedKeys[$function])) {
            $outside[] = "- `{$function}`";
        }
    }
    sort($outside, SORT_STRING);

    $sections = [];
    $hits = 0;
    $total = 0;
    foreach ($counted as $owner => $keys) {
        $lines = [];
        $ownerHits = 0;
        foreach ($keys as $key) {
            $isBound = isset($boundKeys[$key]);
            $ownerHits += $isBound ? 1 : 0;
            $lines[] = '- [' . ($isBound ? 'x' : ' ') . "] `{$key}`";
        }
        $hits += $ownerHits;
        $total += count($keys);
        $sections[] = "## {$owner} ({$ownerHits} / " . count($keys) . ")\n\n" . implode("\n", $lines) . "\n";
    }

    return '# ' . SUPPORT_LABEL . " support\n\n"
        . support_summary($library, $hits, $total, $date) . "\n\n"
        . "Generated by `php84 scripts/support.php` from the installed GIR files and `stubs/`. One line per member: `[x]` bound, `[ ]` not bound.\n\n"
        . implode("\n", $sections)
        . "\n## Bound outside the measured library\n\n"
        . "Bindings of other libraries (GLib, GObject, GIO, cairo, graphene), of deprecated members, and the extension's own; none of them is counted.\n\n"
        . (count($outside) === 0 ? "None.\n" : implode("\n", $outside) . "\n");
}

/**
 * Each class's parent, as C types, from the GIR `parent` attribute ("Widget" or "Gtk.Widget").
 * @param list<string> $girFiles
 * @return array<string, string>
 */
function support_parents(array $girFiles): array
{
    $byName = [];
    $raw = [];
    foreach ($girFiles as $file) {
        $xml = simplexml_load_file($file);
        $namespace = $xml->children(SUPPORT_CORE)->namespace;
        $ns = (string) $namespace->attributes('')['name'];
        foreach ($namespace->children(SUPPORT_CORE) as $owner) {
            $type = (string) $owner->attributes(SUPPORT_C)->type;
            if ($type === '') {
                continue;
            }
            $name = (string) $owner->attributes('')['name'];
            $byName["{$ns}.{$name}"] = $type;
            $parent = (string) $owner->attributes('')['parent'];
            if ($parent !== '') {
                $raw[$type] = str_contains($parent, '.') ? $parent : "{$ns}.{$parent}";
            }
        }
    }
    $parents = [];
    foreach ($raw as $type => $parent) {
        if (isset($byName[$parent])) {
            $parents[$type] = $byName[$parent];
        }
    }
    ksort($parents, SORT_STRING);

    return $parents;
}

/** GtkFileDialog => file_dialog: the GIR prefix when the owner is not in the prefix map. */
function support_guess_prefix(string $owner): string
{
    return strtolower(preg_replace('/(?<!^)[A-Z]/', '_$0', preg_replace('/^(Gtk|Gdk|Gsk)/', '', $owner)));
}

function support_summary(string $library, int $hits, int $total, string $date): string
{
    return sprintf('%s — %d / %d members bound (%.1f%%) — %s', $library, $hits, $total, $total === 0 ? 0 : 100 * $hits / $total, $date);
}

function support_badge(string $label, int $bound, int $total): string
{
    $percent = sprintf('%.1f', $total === 0 ? 0 : 100 * $bound / $total);
    $message = rawurlencode("{$percent}% ({$bound}/{$total})");
    $message = str_replace('%20', '_', $message);

    return "[![{$label}](https://img.shields.io/badge/" . str_replace(' ', '_', $label) . "-{$message}-blue?style=flat-square)](SUPPORT.md)";
}

/** Two support lists alike but for the date of their summary line. */
function support_same(string $a, string $b): bool
{
    $undated = static fn (string $s): string => preg_replace('/ — \d{4}-\d{2}-\d{2}$/m', '', $s);

    return $undated($a) === $undated($b);
}

/** The README with the badge line set: replaced where it is, else after the CI badge. */
function support_readme(string $readme, string $badge): string
{
    $lines = explode("\n", $readme);
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![' . SUPPORT_LABEL . ']')) {
            $lines[$i] = $badge;

            return implode("\n", $lines);
        }
    }
    foreach ($lines as $i => $line) {
        if (str_starts_with($line, '[![CI]')) {
            array_splice($lines, $i + 1, 0, [$badge]);

            return implode("\n", $lines);
        }
    }
    throw new RuntimeException('The README has no CI badge line to put the API badge after.');
}

/** @return array{int, int} bound and total, read back from a support list's summary line */
function support_totals(string $md): array
{
    preg_match('/ (\d+) \/ (\d+) members bound/', $md, $m);

    return [(int) $m[1], (int) $m[2]];
}

function support_main(array $argv): int
{
    $root = dirname(__DIR__);
    // GTK installs its GIR files under its own prefix (Homebrew: the gtk4 keg, symlinked into share/).
    $girDir = trim((string) shell_exec('pkg-config --variable=prefix gtk4')) . '/share/gir-1.0';
    $files = array_map(static fn (string $ns): string => "{$girDir}/{$ns}-4.0.gir", ['Gtk', 'Gdk', 'Gsk']);
    foreach ($files as $file) {
        if (! is_file($file)) {
            fwrite(STDERR, "Missing {$file}.\n");

            return 2;
        }
    }
    $version = trim((string) shell_exec('pkg-config --modversion gtk4'));
    $md = support_render(support_counted($files), support_bound("{$root}/stubs"), "GTK {$version}, gdk, gsk", date('Y-m-d'), support_prefixes($files), support_parents($files));
    [$hits, $total] = support_totals($md);
    $readme = support_readme(file_get_contents("{$root}/README.md"), support_badge(SUPPORT_LABEL, $hits, $total));

    if (in_array('--check', $argv, true)) {
        $current = is_file("{$root}/SUPPORT.md") ? file_get_contents("{$root}/SUPPORT.md") : '';
        $same = support_same($current, $md) && $readme === file_get_contents("{$root}/README.md");
        fwrite(STDOUT, $same ? "SUPPORT.md and the badge are current.\n" : "SUPPORT.md or the badge differs: run php84 scripts/support.php.\n");

        return $same ? 0 : 1;
    }
    file_put_contents("{$root}/SUPPORT.md", $md);
    file_put_contents("{$root}/README.md", $readme);
    fwrite(STDOUT, "{$hits} / {$total}\n");

    return 0;
}

if (PHP_SAPI === 'cli' && isset($argv[0]) && realpath($argv[0]) === __FILE__) {
    exit(support_main($argv));
}
