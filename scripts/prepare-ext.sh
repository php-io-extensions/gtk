#!/usr/bin/env bash
#
# Generate the Zephir C sources into ext/ and stage the hand-written C. Does
# not compile the .so itself — that happens on the Linux box via
# build-linux.sh.
#
# Zephir handles the GTK4 link itself: config.json's package-dependencies
# entry makes it emit a real "pkg-config gtk4" probe into ext/config.m4, and
# extra-sources puts src/*.c into the build. Neither needs patching here.
#
# What does need fixing is one Zephir codegen bug — see fix_register_macro().
#
# Also writes ext/.gen-stamp — a SHA-256 over src/, gtk/, and optimizers/ —
# so build-linux.sh can detect a stale committed ext/ and refuse to build it.
#
# GTK_ROOT    — package root (default: parent of this script)
# ZEPHIR_BIN  — zephir executable (otherwise searched on PATH / composer)

set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
ROOT_DIR="${GTK_ROOT:-$(cd "${SCRIPT_DIR}/.." && pwd)}"
SRC_DIR="${ROOT_DIR}/src"
EXT_DIR="${ROOT_DIR}/ext"

die() {
    echo "prepare-ext: $*" >&2
    exit 1
}

cd "$ROOT_DIR"

# ---------------------------------------------------------------- locate zephir
if [ -n "${ZEPHIR_BIN:-}" ]; then
    ZEPHIR="$ZEPHIR_BIN"
elif command -v zephir >/dev/null 2>&1; then
    ZEPHIR="$(command -v zephir)"
elif [ -x "$HOME/.config/composer/vendor/bin/zephir" ]; then
    ZEPHIR="$HOME/.config/composer/vendor/bin/zephir"
elif [ -x "$HOME/.composer/vendor/bin/zephir" ]; then
    ZEPHIR="$HOME/.composer/vendor/bin/zephir"
else
    die "Zephir not found. Install with: composer global require phalcon/zephir (or set ZEPHIR_BIN)"
fi

[ -d "$SRC_DIR" ] || die "Missing ${SRC_DIR}/"

echo "prepare-ext: using zephir at ${ZEPHIR}"

# -------------------------------------------- drive zephir with a clean PHP CLI
# A php.ini that loads a previously built extension can segfault
# `zephir generate`. php -n disables ini; re-add zephir_parser so the
# compiler can run.
find_zephir_parser() {
    local ext_dir candidate
    ext_dir="$(php -r 'echo defined("PHP_EXTENSION_DIR") ? PHP_EXTENSION_DIR : "";' 2>/dev/null || true)"
    for candidate in \
        ${ext_dir:+"${ext_dir}/zephir_parser.so"} \
        /opt/homebrew/lib/php/pecl/*/zephir_parser.so \
        "$HOME/Library/Application Support/Herd/config/php/"*/zephir_parser.so
    do
        if [ -f "$candidate" ]; then
            printf '%s' "$candidate"
            return 0
        fi
    done
    return 1
}

zephir_is_php_script() {
    local first
    [ -f "$1" ] || return 1
    first="$(head -n 1 "$1" 2>/dev/null || true)"
    case "$first" in
        *php*) return 0 ;;
    esac
    return 1
}

run_zephir_generate() {
    local parser=""
    # A test stub (plain bash) must be invoked as-is. The real Zephir
    # entrypoint is a PHP script and must run under php -n so a loaded
    # previous gtk.so cannot segfault generate.
    if ! zephir_is_php_script "$ZEPHIR"; then
        "$ZEPHIR" generate
        return
    fi
    parser="$(find_zephir_parser || true)"
    if [ -n "$parser" ]; then
        echo "prepare-ext: php -n -d extension=${parser}"
        php -n -d "extension=${parser}" "$ZEPHIR" generate
    else
        "$ZEPHIR" generate
    fi
}

echo "prepare-ext: zephir generate"
run_zephir_generate || die "zephir generate failed"

[ -f "${EXT_DIR}/config.m4" ] || die "zephir generate did not produce ${EXT_DIR}/config.m4"

# ------------------------------------------------- copy hand-written C into ext/
# The optimizers emit #include "src/phpgtk-*.h", resolved relative to ext/.
echo "prepare-ext: copy src/ -> ext/src/"
mkdir -p "${EXT_DIR}/src"
shopt -s nullglob
headers=("${SRC_DIR}"/*.h)
impls=("${SRC_DIR}"/*.c)
shopt -u nullglob
[ ${#headers[@]} -gt 0 ] || die "no src/*.h to stage"
cp -f "${headers[@]}" "${EXT_DIR}/src/"
if [ ${#impls[@]} -gt 0 ]; then
    cp -f "${impls[@]}" "${EXT_DIR}/src/"
fi

# ------------------------------------------------------ fix ZEPHIR_REGISTER_CLASS
#
# For a nested namespace like Gtk\Gtk\GtkButton, Zephir emits
#
#     ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkButton, GtkButton, gtk, gtkbutton, gtk_gtk_gtkbutton_gtkbutton_method_entry, 0);
#
# The macro builds the class-entry symbol as lower_ns##_##name##_ce, which
# gives the wrong identifier — the header declares the fully nested one, so
# the compile fails with "undeclared identifier". Only the lower_ns argument
# is wrong; the method-entry symbol on the same line is correct, so the right
# value is recovered from it by stripping the trailing _<name>. That
# derivation holds at any namespace depth, so nothing here needs updating
# when a class is added.
fix_register_macro() {
    local file="$1"
    local tmp="${file}.fixed"

    awk '
        /ZEPHIR_REGISTER_CLASS/ && /_method_entry/ {
            line = $0

            if (!match(line, /[A-Za-z0-9_]+_method_entry/)) { print line; next }
            base = substr(line, RSTART, RLENGTH)
            sub(/_method_entry$/, "", base)

            paren = index(line, "(")
            head  = substr(line, 1, paren)
            n     = split(substr(line, paren + 1), arg, ",")
            if (n < 4) { print line; next }

            name = arg[4]
            gsub(/^[ \t]+|[ \t]+$/, "", name)

            correct = base
            sub("_" name "$", "", correct)

            current = arg[3]
            gsub(/^[ \t]+|[ \t]+$/, "", current)
            if (current == correct) { print line; next }

            arg[3] = " " correct

            out = head arg[1]
            for (i = 2; i <= n; i++) { out = out "," arg[i] }
            print out
            next
        }
        { print }
    ' "$file" > "$tmp" && mv "$tmp" "$file"
}

echo "prepare-ext: fixing ZEPHIR_REGISTER_CLASS namespace prefixes"
register_fixed=0
if [ -d "$EXT_DIR" ]; then
    while IFS= read -r generated; do
        before="${generated}.before-register"
        cp "$generated" "$before"
        fix_register_macro "$generated"
        if ! cmp -s "$generated" "$before"; then
            register_fixed=$((register_fixed + 1))
        fi
        rm -f "$before"
    done < <(find "${EXT_DIR}" -name '*.zep.c' 2>/dev/null || true)
fi
echo "prepare-ext: rewrote ${register_fixed} registration site(s)"

# ------------------------------------------------------- clear phpize leftovers
# Generated .zep.c and the staged src/ tree are deliberately kept. Nothing
# host-absolute may remain: PIE ships this directory.
#
# `install` and `clean` are zephir's own phpize wrappers, rewritten on every
# generate. They hardcode a toolchain (gcc, -flto, sudo make install) that has
# nothing to do with how this extension is built — build-linux.sh is the only
# supported path — so they are stripped rather than shipped.
cd "$EXT_DIR"
rm -rf Makefile Makefile.fragments Makefile.objects Makefile.global modules .libs \
    autom4te.cache build configure configure.ac 'configure~' config.h config.h.in \
    'config.h.in~' config.log config.status config.nice libtool run-tests.php \
    install-sh missing mkinstalldirs config.guess config.sub ltmain.sh aclocal.m4 \
    acinclude.m4 install clean 2>/dev/null || true
find . \( -name '*.lo' -o -name '*.o' -o -name '*.dep' -o -name '*.la' -o -name '*.so' \) \
    -delete 2>/dev/null || true
find . \( -name '.libs' -o -name '*.dSYM' \) -type d -exec rm -rf {} + 2>/dev/null || true
cd "$ROOT_DIR"

# --------------------------------------------------------------- generation stamp
# SHA-256 over every generation input, so build-linux.sh can detect a stale
# committed ext/. Must stay in lockstep with compute_gen_stamp in
# build-linux.sh.
compute_gen_stamp() {
    local hasher
    if command -v sha256sum >/dev/null 2>&1; then
        hasher="sha256sum"
    else
        hasher="shasum -a 256"
    fi
    (
        cd "$ROOT_DIR"
        find src gtk optimizers -type f \
            \( -name '*.h' -o -name '*.c' -o -name '*.zep' -o -name '*.php' \) 2>/dev/null \
            | LC_ALL=C sort \
            | while IFS= read -r f; do
                  $hasher "$f"
              done \
            | $hasher \
            | awk '{print $1}'
    )
}

compute_gen_stamp > "${EXT_DIR}/.gen-stamp"
echo "prepare-ext: wrote ext/.gen-stamp ($(cat "${EXT_DIR}/.gen-stamp"))"

echo "prepare-ext: PREPARE_EXT_OK"
