#!/usr/bin/env php
<?php
/**
 * audit-gir.php — gir ↔ binding faithfulness audit.
 *
 * For every class annotated in src/*.h (@zep or @reserved), find the class
 * (or interface) in the vendored GObject-Introspection XML under
 * scripts/gir/ and count its declared members:
 *
 *   member count = <constructor> + <method> + <function>
 *
 * <virtual-method> elements are not C-callable and are never counted;
 * signals are Bridge territory (Bridge::connect) and are reported
 * informationally.
 *
 * The audit fails unless bound(@zep) + reserved(@reserved) equals the gir
 * member count. `@zep-construct` methods are synthesized construction
 * helpers — printed as construct=N, not part of that sum.
 *
 * Properties: every gir <property> must be covered — its C accessors
 * (resolved from the property's getter=/setter= attributes, with a
 * get_x/set_x/is_x/has_x name-mapping fallback because those attributes are
 * occasionally missing) exist among the counted members, or the property is
 * explicitly reserved with a line whose text contains: property "name".
 *
 * A non-exempt class must also have a construction path: a bound @zep
 * returning int with no handle parameter (gtk_*_new and friends), or an
 * @zep-construct. Exempt: gir abstract="1" classes, interfaces, and the
 * OBTAIN_ONLY whitelist (objects you obtain from the system, never
 * construct).
 *
 * A class may be declared intentionally partial with a visible marker in
 * its src header:
 *
 *   /*@audit partial Gtk\GtkTextBuffer iter members pending boxed handles * /
 *
 * A partial class must not exceed the gir count but may fall short; it is
 * reported as PARTIAL so review can see exactly what is sanctioned.
 *
 * Free functions (gir namespace-level <function>, no owning class) get a
 * static-only home class declared with a marker in its src header:
 *
 *   /*@audit functions Gdk\GdkKeyval gdk_keyval_ gdk_unicode_to_keyval * /
 *
 * The home's member set is every namespace-level function whose
 * c:identifier starts with one of the listed prefixes. The join is by
 * c:identifier: each bound method's src/*.c body must call exactly one
 * member of that set, each @reserved line must name one, and together they
 * must cover the set exactly once. No properties, no construction path.
 *
 * Bridge\* classes are PHP-side glue with no gir counterpart and are skipped.
 *
 * Usage:
 *   php scripts/audit-gir.php [root]
 *   php scripts/audit-gir.php --count <file.gir[.gz]> <CType>
 */

declare(strict_types=1);

const GIR_NS_CORE = 'http://www.gtk.org/introspection/core/1.0';
const GIR_NS_C = 'http://www.gtk.org/introspection/c/1.0';
const GIR_NS_GLIB = 'http://www.gtk.org/introspection/glib/1.0';

/** First class-path segment → vendored gir file (no extension). */
const GIR_MAP = [
    'Gtk' => 'Gtk-4.0',
    'Gdk' => 'Gdk-4.0',
    'Gsk' => 'Gsk-4.0',
    'Gio' => 'Gio-2.0',
    'GLib' => 'GLib-2.0',
    'GObject' => 'GObject-2.0',
    'Pango' => 'Pango-1.0',
];

/**
 * Classes you obtain from the system (default display, settings singleton)
 * rather than construct. Exempt from the construction-path check.
 */
const OBTAIN_ONLY = [
    'Gtk\\GtkStyleContext', // deprecated instance API; only its two statics are bound
    'Gtk\\GtkSettings',
    'Gdk\\GdkDisplay',
    'Gtk\\GtkRange',
    'Gtk\\GtkNotebookPage',
    'Gtk\\GtkStackPage',
    'Gtk\\GtkMediaStream', // abstract; obtained from GtkMediaFile or GtkVideo::getMediaStream
    'Gtk\\GtkListItem', // obtained from GtkSignalListItemFactory setup/bind
    'Gtk\\GtkGestureSingle', // no gir constructor; construct GtkGestureClick
];

function fail(string $msg): never
{
    fwrite(STDERR, "audit-gir: {$msg}\n");
    exit(1);
}

/** @var array<string, DOMXPath> */
$girCache = [];

function loadGir(string $girDir, string $girName): DOMXPath
{
    global $girCache;
    if (isset($girCache[$girName])) {
        return $girCache[$girName];
    }

    $candidates = ["{$girDir}/{$girName}.gir.gz", "{$girDir}/{$girName}.gir"];
    $xml = null;
    foreach ($candidates as $path) {
        if (!is_file($path)) {
            continue;
        }
        $raw = file_get_contents($path);
        if ($raw === false) {
            fail("cannot read {$path}");
        }
        $xml = str_ends_with($path, '.gz') ? gzdecode($raw) : $raw;
        if ($xml === false) {
            fail("cannot gunzip {$path}");
        }
        break;
    }
    if (is_null($xml)) {
        fail("gir '{$girName}' not found in {$girDir} (expected {$girName}.gir.gz)");
    }

    $doc = new DOMDocument();
    if (!$doc->loadXML($xml, LIBXML_NONET | LIBXML_COMPACT)) {
        fail("cannot parse {$girName} XML");
    }
    $xp = new DOMXPath($doc);
    $xp->registerNamespace('gir', GIR_NS_CORE);
    $xp->registerNamespace('c', GIR_NS_C);
    $xp->registerNamespace('glib', GIR_NS_GLIB);

    return $girCache[$girName] = $xp;
}

/** Find the <class> or <interface> element whose C type is $cType. */
function findGirType(DOMXPath $xp, string $cType): ?DOMElement
{
    foreach (['class', 'interface'] as $kind) {
        $nodes = $xp->query("//gir:namespace/gir:{$kind}[@c:type=" . xpathString($cType) . ']');
        if ($nodes !== false && $nodes->length > 0) {
            return $nodes->item(0);
        }
        // Some types carry only glib:type-name (c:type occasionally absent).
        $nodes = $xp->query("//gir:namespace/gir:{$kind}[@glib:type-name=" . xpathString($cType) . ']');
        if ($nodes !== false && $nodes->length > 0) {
            return $nodes->item(0);
        }
    }

    return null;
}

function xpathString(string $s): string
{
    return "'" . str_replace("'", "''", $s) . "'";
}

/**
 * @return array{
 *   kind: string, abstract: bool,
 *   members: array<string, string>,   // member name → element kind
 *   constructors: int, methods: int, functions: int, expected: int,
 *   signals: int,
 *   properties: list<array{name: string, readable: bool, writable: bool, constructOnly: bool, getter: string, setter: string}>
 * }
 */
function describeGirType(DOMElement $el): array
{
    $members = [];
    $constructors = 0;
    $methods = 0;
    $functions = 0;
    $signals = 0;
    $properties = [];

    foreach ($el->childNodes as $child) {
        if (!$child instanceof DOMElement) {
            continue;
        }
        $isCore = $child->namespaceURI === GIR_NS_CORE;
        $local = $child->localName;
        $name = $child->getAttribute('name');

        if ($isCore && $local === 'constructor') {
            $constructors++;
            $members[$name] = 'constructor';
        } elseif ($isCore && $local === 'method') {
            $methods++;
            $members[$name] = 'method';
        } elseif ($isCore && $local === 'function') {
            $functions++;
            $members[$name] = 'function';
        } elseif ($child->namespaceURI === GIR_NS_GLIB && $local === 'signal') {
            $signals++;
        } elseif ($isCore && $local === 'property') {
            $properties[] = [
                'name' => $name,
                'readable' => $child->getAttribute('readable') !== '0',
                'writable' => $child->getAttribute('writable') === '1',
                'constructOnly' => $child->getAttribute('construct-only') === '1',
                'getter' => $child->getAttribute('getter'),
                'setter' => $child->getAttribute('setter'),
            ];
        }
    }

    return [
        'kind' => $el->localName,
        'abstract' => $el->getAttribute('abstract') === '1',
        'members' => $members,
        'constructors' => $constructors,
        'methods' => $methods,
        'functions' => $functions,
        'expected' => $constructors + $methods + $functions,
        'signals' => $signals,
        'properties' => $properties,
    ];
}

/**
 * A property is accessor-covered when the members set contains the getter
 * (when readable) and the setter (when writable and not construct-only),
 * resolved by attribute first, then by name mapping.
 *
 * @param array<string, string> $members
 */
function propertyUncovered(array $prop, array $members): ?string
{
    $snake = str_replace('-', '_', $prop['name']);

    if ($prop['readable']) {
        $candidates = array_filter([
            $prop['getter'],
            "get_{$snake}",
            "is_{$snake}",
            "has_{$snake}",
            $snake,
        ]);
        $found = false;
        foreach ($candidates as $c) {
            if (isset($members[$c])) {
                $found = true;
                break;
            }
        }
        if (!$found) {
            return 'no getter';
        }
    }

    if ($prop['writable'] && !$prop['constructOnly']) {
        $candidates = array_filter([$prop['setter'], "set_{$snake}"]);
        $found = false;
        foreach ($candidates as $c) {
            if (isset($members[$c])) {
                $found = true;
                break;
            }
        }
        if (!$found) {
            return 'no setter';
        }
    }

    return null;
}

/**
 * Namespace-level <function> elements whose c:identifier starts with one of
 * $prefixes.
 *
 * @param list<string> $prefixes
 * @return list<string> c:identifiers, sorted
 */
function girFreeFunctions(DOMXPath $xp, array $prefixes): array
{
    $out = [];
    $nodes = $xp->query('/gir:repository/gir:namespace/gir:function');
    foreach ($nodes === false ? [] : $nodes as $fn) {
        if (!$fn instanceof DOMElement) {
            continue;
        }
        $id = $fn->getAttributeNS(GIR_NS_C, 'identifier');
        foreach ($prefixes as $prefix) {
            if ($id !== '' && str_starts_with($id, $prefix)) {
                $out[] = $id;
                break;
            }
        }
    }
    sort($out);

    return $out;
}

/**
 * Native gtk_/gdk_/gsk_/pango_/g_ calls in the body of each phpgtk_* symbol,
 * read from src/*.c (brace-matched; comments stripped).
 *
 * @return array<string, list<string>> symbol → native calls
 */
function nativeCallsBySymbol(string $root): array
{
    $out = [];
    foreach (glob("{$root}/src/*.c") ?: [] as $path) {
        $src = (string) file_get_contents($path);
        $src = (string) preg_replace('#/\*.*?\*/#s', '', $src);
        $src = (string) preg_replace('#//[^\n]*#', '', $src);
        if (!preg_match_all('/\b(phpgtk_[a-z0-9_]+)\s*\([^;{)]*\)\s*\{/', $src, $m, PREG_OFFSET_CAPTURE)) {
            continue;
        }
        foreach ($m[1] as $i => [$symbol]) {
            $open = $m[0][$i][1] + strlen($m[0][$i][0]) - 1;
            $depth = 0;
            $len = strlen($src);
            $close = $len - 1;
            for ($j = $open; $j < $len; $j++) {
                if ($src[$j] === '{') {
                    $depth++;
                } elseif ($src[$j] === '}' && --$depth === 0) {
                    $close = $j;
                    break;
                }
            }
            $body = substr($src, $open, $close - $open + 1);
            preg_match_all('/\b((?:gtk|gdk|gsk|pango|g)_[a-z0-9_]+)\s*\(/', $body, $cm);
            $out[$symbol] = $cm[1];
        }
    }

    return $out;
}

/**
 * Collect per-class annotation facts from src/*.h.
 *
 * @return array{
 *   classes: array<string, array{bound: int, reserved: int, construct: int, hasConstruction: bool, reservedTexts: list<string>, symbols: list<string>}>,
 *   partial: array<string, string>,
 *   functions: array<string, list<string>>
 * }
 */
function collectAnnotations(string $root): array
{
    $classes = [];
    $partial = [];
    $functions = [];
    foreach (glob("{$root}/src/*.h") ?: [] as $path) {
        $pendingClass = null;
        foreach (file($path, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
            if (!is_null($pendingClass) && preg_match('/^\s*(?:zend_long|double|void)\s+(phpgtk_[a-z0-9_]+)\s*\(/', $line, $pm)) {
                $classes[$pendingClass]['symbols'][] = $pm[1];
                $pendingClass = null;
                continue;
            }
            if (preg_match('#/\*\s*@zep-construct\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(([^)]*)\)\s*->\s*(\w+)\s*\*/#', $line, $m)) {
                $classPath = $m[1];
                $classes[$classPath]['construct'] = ($classes[$classPath]['construct'] ?? 0) + 1;
                $classes[$classPath]['hasConstruction'] = true;
            } elseif (preg_match('#/\*\s*@zep\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(([^)]*)\)\s*->\s*(\w+)\s*\*/#', $line, $m)) {
                $classPath = $m[1];
                $paramSrc = $m[3];
                $returnType = $m[4];
                $classes[$classPath]['bound'] = ($classes[$classPath]['bound'] ?? 0) + 1;
                $pendingClass = $classPath;
                $hasHandle = preg_match('/\bhandle\b/', $paramSrc) === 1;
                if ($returnType === 'int' && !$hasHandle) {
                    $classes[$classPath]['hasConstruction'] = true;
                }
            } elseif (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
                $text = $m[2];
                $classes[$m[1]]['reservedTexts'][] = $text;
                // Property-only reservations cover gir <property> rows that have
                // no dedicated C accessor. They are not constructors/methods/
                // functions and must not inflate bound+reserved.
                $propertyOnly = preg_match('/property\s+"/', $text) === 1
                    && preg_match('/\b(?:gtk|gdk|gsk|pango|g)_[a-z0-9_]+/', $text) !== 1;
                if (!$propertyOnly) {
                    $classes[$m[1]]['reserved'] = ($classes[$m[1]]['reserved'] ?? 0) + 1;
                }
            } elseif (preg_match('#/\*\s*@audit\s+partial\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
                if (trim($m[2]) === '') {
                    fail("@audit partial for {$m[1]} needs a reason");
                }
                $partial[$m[1]] = $m[2];
            } elseif (preg_match('#/\*\s*@audit\s+functions\s+([A-Za-z0-9_\\\\]+)\s+(.*?)\s*\*/#', $line, $m)) {
                $prefixes = preg_split('/\s+/', trim($m[2])) ?: [];
                $prefixes = array_values(array_filter($prefixes, static fn (string $p): bool => $p !== ''));
                if ($prefixes === []) {
                    fail("@audit functions for {$m[1]} needs at least one c:identifier prefix");
                }
                $functions[$m[1]] = $prefixes;
            }
        }
    }

    return ['classes' => $classes, 'partial' => $partial, 'functions' => $functions];
}

/**
 * Audit one free-function home class; prints its line and returns true on
 * failure.
 *
 * @param list<string> $prefixes
 * @param array<string, mixed> $counts
 */
function auditFunctionHome(string $classPath, array $prefixes, array $counts, DOMXPath $xp, string $root): bool
{
    static $calls = null;
    $calls ??= nativeCallsBySymbol($root);

    $expectedIds = girFreeFunctions($xp, $prefixes);
    $bound = $counts['bound'] ?? 0;
    $reserved = $counts['reserved'] ?? 0;
    $problems = [];

    if ($expectedIds === []) {
        $problems[] = 'no gir namespace function matches prefixes ' . implode(', ', $prefixes);
    }
    if (($counts['construct'] ?? 0) > 0) {
        $problems[] = 'a free-function home has no construction path to synthesize';
    }

    $joined = [];
    foreach ($counts['symbols'] ?? [] as $symbol) {
        $native = $calls[$symbol] ?? null;
        if (is_null($native)) {
            $problems[] = "{$symbol}: no function body in src/*.c";
            continue;
        }
        $members = array_values(array_intersect($native, $expectedIds));
        if (count($members) !== 1) {
            $problems[] = "{$symbol}: body must call exactly one member of the set, found ["
                . implode(', ', $native) . ']';
            continue;
        }
        $joined[] = $members[0];
    }
    foreach ($counts['reservedTexts'] ?? [] as $text) {
        if (!preg_match('/\b((?:gtk|gdk|gsk|pango|g)_[a-z0-9_]+)/', $text, $rm)) {
            $problems[] = "reserved line names no c:identifier: {$text}";
            continue;
        }
        if (!in_array($rm[1], $expectedIds, true)) {
            $problems[] = "reserved {$rm[1]} is not a member of the set";
            continue;
        }
        $joined[] = $rm[1];
    }

    foreach (array_count_values($joined) as $id => $n) {
        if ($n > 1) {
            $problems[] = "{$id} is covered {$n} times";
        }
    }
    foreach (array_diff($expectedIds, $joined) as $id) {
        $problems[] = "{$id} is neither bound nor reserved";
    }

    echo sprintf(
        "%-40s gir=%-4d bound=%-4d reserved=%-4d functions(%s) %s\n",
        $classPath,
        count($expectedIds),
        $bound,
        $reserved,
        implode(' ', $prefixes),
        $problems === [] ? 'OK' : 'FAIL'
    );
    foreach ($problems as $p) {
        echo "    - {$p}\n";
    }

    return $problems !== [];
}

// ---- main ----

$args = array_slice($argv, 1);

// --count <file.gir[.gz]> <CType>: standalone breakdown for one type.
if (($args[0] ?? '') === '--count') {
    $file = $args[1] ?? null;
    $cType = $args[2] ?? null;
    if (is_null($file) || is_null($cType)) {
        fail('usage: audit-gir.php --count <file.gir[.gz]> <CType>');
    }
    if (!is_file($file)) {
        fail("gir file '{$file}' does not exist");
    }
    $girName = preg_replace('/\.gir(\.gz)?$/', '', basename($file));
    $xp = loadGir(dirname($file), (string) $girName);
    $el = findGirType($xp, $cType);
    if (is_null($el)) {
        fail("type '{$cType}' not found in {$file}");
    }
    $d = describeGirType($el);
    echo "{$cType} kind={$d['kind']} abstract=" . ($d['abstract'] ? 'yes' : 'no')
        . " constructors={$d['constructors']} methods={$d['methods']} functions={$d['functions']}"
        . " expected={$d['expected']} signals={$d['signals']} properties=" . count($d['properties']) . "\n";
    foreach ($d['properties'] as $p) {
        $u = propertyUncovered($p, $d['members']);
        echo "  property {$p['name']}: " . (is_null($u) ? 'accessor-covered' : $u) . "\n";
    }
    exit(0);
}

// --functions <file.gir[.gz]> <prefix>...: namespace-level functions by c:identifier prefix.
if (($args[0] ?? '') === '--functions') {
    $file = $args[1] ?? null;
    $prefixes = array_slice($args, 2);
    if (is_null($file) || $prefixes === []) {
        fail('usage: audit-gir.php --functions <file.gir[.gz]> <prefix>...');
    }
    if (!is_file($file)) {
        fail("gir file '{$file}' does not exist");
    }
    $girName = preg_replace('/\.gir(\.gz)?$/', '', basename($file));
    $ids = girFreeFunctions(loadGir(dirname($file), (string) $girName), $prefixes);
    echo 'functions prefixes=' . implode(',', $prefixes) . ' expected=' . count($ids) . "\n";
    foreach ($ids as $id) {
        echo "  function {$id}\n";
    }
    exit(0);
}

$root = isset($args[0]) ? rtrim($args[0], '/') : dirname(__DIR__);
if (!is_dir($root)) {
    fail("root '{$root}' is not a directory");
}
$girDir = "{$root}/scripts/gir";
if (!is_dir($girDir)) {
    fail("vendored gir directory '{$girDir}' is missing");
}

$annotations = collectAnnotations($root);
$failures = 0;
$audited = 0;
$skipped = 0;

ksort($annotations['classes']);
foreach ($annotations['classes'] as $classPath => $counts) {
    $segments = explode('\\', $classPath);
    if ($segments[0] === 'Bridge') {
        $skipped++;
        echo sprintf("%-40s SKIP (glue, no gir counterpart)\n", $classPath);
        continue;
    }

    $girName = GIR_MAP[$segments[0]] ?? null;
    if (is_null($girName)) {
        echo sprintf("%-40s FAIL (no gir mapping for namespace '%s'; add it to GIR_MAP)\n", $classPath, $segments[0]);
        $failures++;
        continue;
    }

    $xp = loadGir($girDir, $girName);

    if (isset($annotations['functions'][$classPath])) {
        if (auditFunctionHome($classPath, $annotations['functions'][$classPath], $counts, $xp, $root)) {
            $failures++;
        }
        $audited++;
        continue;
    }

    $cType = (string) end($segments);
    $el = findGirType($xp, $cType);
    if (is_null($el)) {
        echo sprintf("%-40s FAIL (type '%s' not found in %s)\n", $classPath, $cType, $girName);
        $failures++;
        continue;
    }

    $d = describeGirType($el);
    $bound = $counts['bound'] ?? 0;
    $reserved = $counts['reserved'] ?? 0;
    $construct = $counts['construct'] ?? 0;
    $reservedTexts = $counts['reservedTexts'] ?? [];
    $total = $bound + $reserved;
    $expected = $d['expected'];
    $isPartial = isset($annotations['partial'][$classPath]);
    $audited++;

    $problems = [];

    if ($total === $expected) {
        $status = 'OK';
    } elseif ($isPartial && $total < $expected) {
        $status = 'PARTIAL (' . $annotations['partial'][$classPath] . ')';
    } else {
        $status = 'FAIL';
        $problems[] = "member count bound+reserved={$total} != gir={$expected}";
    }

    // Property coverage: accessors among members, else an explicit
    // @reserved line containing: property "name".
    foreach ($d['properties'] as $prop) {
        $uncovered = propertyUncovered($prop, $d['members']);
        if (is_null($uncovered)) {
            continue;
        }
        $needle = 'property "' . $prop['name'] . '"';
        $reservedForProp = false;
        foreach ($reservedTexts as $text) {
            if (str_contains($text, $needle)) {
                $reservedForProp = true;
                break;
            }
        }
        if (!$reservedForProp && !$isPartial) {
            $problems[] = "property \"{$prop['name']}\" ({$uncovered}) is neither accessor-covered nor reserved";
        }
    }

    // Construction path.
    $exempt = $d['kind'] === 'interface'
        || $d['abstract']
        || in_array($classPath, OBTAIN_ONLY, true);
    $hasConstruction = ($counts['hasConstruction'] ?? false) === true;
    if (!$exempt && !$hasConstruction && !$isPartial) {
        $problems[] = 'no construction path (bound int-returning method without a handle parameter)';
    }

    if ($problems !== [] && $status !== 'FAIL') {
        $status = 'FAIL';
    }
    if ($problems !== []) {
        $failures++;
    }

    echo sprintf(
        "%-40s gir=%-4d bound=%-4d reserved=%-4d construct=%-3d signals=%-3d props=%-3d %s\n",
        $classPath,
        $expected,
        $bound,
        $reserved,
        $construct,
        $d['signals'],
        count($d['properties']),
        $status
    );
    foreach ($problems as $p) {
        echo "    - {$p}\n";
    }
}

echo "audited={$audited} skipped={$skipped} failures={$failures}\n";
if ($failures > 0) {
    fwrite(STDERR, "audit-gir: {$failures} class(es) out of parity with the vendored gir\n");
    exit(1);
}
echo "AUDIT_OK\n";
