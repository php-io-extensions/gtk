#!/bin/bash

# Debian and Ubuntu installer for the gtk PHP extension (GTK4).
#
# Apt package names are the same on Debian and Ubuntu (libgtk-4-dev), so one
# script covers both. Builds on the Linux box — do not run this on macOS.
#
# If ext/ has not been generated yet, this script runs scripts/prepare-ext.sh
# (requires Zephir on PATH or ZEPHIR_BIN). After ext/ is committed, only
# phpize / configure / make are required.
#
# Usage:
#   bash build-linux.sh
#
# Optional env overrides:
#   PHP_BIN      — path to the php binary   (default: first php on PATH)
#   PHP_EXT_DIR  — override the install dir  (default: from php-config)
#   ZEPHIR_BIN   — zephir binary if ext/ must be generated

set -Eeuo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
EXTENSION_NAME="gtk"
EXT_SRC="${SCRIPT_DIR}/ext"
BUILD_SO="${EXT_SRC}/modules/${EXTENSION_NAME}.so"
LOG_FILE="${SCRIPT_DIR}/build.log"

if [ "$(uname -s)" = "Darwin" ]; then
    echo "build-linux.sh is for Debian/Ubuntu only. Do not compile gtk on macOS." >&2
    exit 1
fi

if [ "${EUID:-$(id -u)}" -ne 0 ]; then
    SUDO="sudo"
else
    SUDO=""
fi

die() {
    echo ""
    echo "❌  $*" >&2
    exit 1
}

require_cmd() {
    command -v "$1" >/dev/null 2>&1 || die "Required command not found: $1"
}

header() {
    echo "============================================"
    echo " GTK4 Extension Installer (Debian / Ubuntu) "
    echo "============================================"
    echo ""
}

step() { echo "$*"; }
ok()   { echo "   ✓ $*"; }

show_failure_logs() {
    local f
    for f in "$LOG_FILE" "${SCRIPT_DIR}/compile-errors.log"; do
        if [ -f "$f" ]; then
            echo ""
            echo "---- Last 100 lines of $(basename "$f") ----"
            tail -100 "$f" || true
        fi
    done
}

version_ge() {
    local IFS=.
    local a=($1) b=($2)
    local i
    for i in 0 1 2; do
        local av="${a[$i]:-0}" bv="${b[$i]:-0}"
        if   (( av > bv )); then return 0
        elif (( av < bv )); then return 1
        fi
    done
    return 0
}

MIN_GTK4_VERSION="4.18.0"

ensure_gtk4() {
    step "📚 Checking GTK4 dependency (minimum ${MIN_GTK4_VERSION})..."
    require_cmd apt-get
    $SUDO apt-get update -q

    $SUDO apt-get install -y --no-install-recommends pkg-config libgtk-4-dev \
        || die "Failed to install libgtk-4-dev. On Debian/Ubuntu: sudo apt-get install libgtk-4-dev"

    command -v pkg-config >/dev/null 2>&1 || die "pkg-config missing after apt install."

    if ! pkg-config --exists gtk4 2>/dev/null; then
        die "pkg-config gtk4 still missing after installing libgtk-4-dev."
    fi

    local installed_ver
    installed_ver="$(pkg-config --modversion gtk4)"
    if ! version_ge "$installed_ver" "$MIN_GTK4_VERSION"; then
        die "GTK4 ${installed_ver} is installed but < ${MIN_GTK4_VERSION}."
    fi

    ok "GTK4 ${installed_ver} detected via pkg-config"
}

ensure_php_dev() {
    step "🐘 Checking PHP dev headers..."

    if command -v phpize >/dev/null 2>&1; then
        ok "phpize found: $(command -v phpize)"
        return
    fi

    local ver
    ver="$(${PHP_BIN:-php} -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;' 2>/dev/null || true)"

    step "phpize not found — installing PHP dev headers..."
    require_cmd apt-get
    $SUDO apt-get update -q

    local installed=0
    for pkg in "php${ver}-dev" "php-dev"; do
        if $SUDO apt-get install -y --no-install-recommends "$pkg" 2>/dev/null; then
            installed=1
            ok "Installed $pkg"
            break
        fi
    done

    [ "$installed" -eq 1 ] || die "Could not install PHP dev headers. Try: sudo apt-get install php-dev"
    command -v phpize >/dev/null 2>&1 || die "phpize still not found after installing php-dev."
    ok "phpize ready: $(command -v phpize)"
}

# SHA-256 over every generation input. Must stay in lockstep with
# compute_gen_stamp in scripts/prepare-ext.sh.
compute_gen_stamp() {
    local hasher
    if command -v sha256sum >/dev/null 2>&1; then
        hasher="sha256sum"
    else
        hasher="shasum -a 256"
    fi
    (
        cd "$SCRIPT_DIR"
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

ensure_generated_ext() {
    local want have
    if [ -f "${EXT_SRC}/gtk.c" ] && [ -f "${EXT_SRC}/config.m4" ]; then
        # Stale-build trap: a committed ext/ that no longer matches the
        # sources it was generated from must never be silently compiled.
        want="$(compute_gen_stamp)"
        have="$(cat "${EXT_SRC}/.gen-stamp" 2>/dev/null || echo missing)"
        if [ "$want" = "$have" ]; then
            ok "Committed/generated ext/ present and matches .gen-stamp"
            return
        fi
        step "⚠️  ext/ is stale (.gen-stamp ${have} != sources ${want}) — regenerating..."
    else
        step "⚙️  ext/ not generated — running scripts/prepare-ext.sh (needs Zephir)..."
    fi

    bash "${SCRIPT_DIR}/scripts/prepare-ext.sh" >>"$LOG_FILE" 2>&1 \
        || { show_failure_logs; die "zephir generate / prepare-ext.sh failed. ext/ is missing or stale; regenerate on the dev machine (scripts/prepare-ext.sh needs Zephir) and copy the repo over again."; }

    [ -f "${EXT_SRC}/gtk.c" ] || die "prepare-ext.sh finished but ext/gtk.c is missing."
    ok "ext/ generated"
}

header

step "🔎 Preflight checks..."

PHP_BIN="${PHP_BIN:-$(command -v php || true)}"
[ -x "$PHP_BIN" ] || die "PHP not found. Install PHP first (e.g. sudo apt-get install php)."
ok "PHP binary: $PHP_BIN"

require_cmd gcc
require_cmd make
ok "gcc / make present"

ensure_php_dev
ensure_gtk4
ensure_generated_ext

PHP_VER_MM="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.".".PHP_MINOR_VERSION;')"
PHP_VER_NN="$("$PHP_BIN" -r 'echo PHP_MAJOR_VERSION.PHP_MINOR_VERSION;')"

PHP_BIN_DIR="$(dirname "$(realpath "$PHP_BIN")")"
PHP_CONFIG="${PHP_BIN_DIR}/php-config"
[ -x "$PHP_CONFIG" ] || PHP_CONFIG="$(command -v php-config 2>/dev/null || true)"
[ -x "$PHP_CONFIG" ] || die "php-config not found. Try: sudo apt-get install php${PHP_VER_MM}-dev"

if [ -z "${PHP_EXT_DIR:-}" ]; then
    PHP_EXT_DIR="$("$PHP_CONFIG" --extension-dir)"
fi
[ -n "$PHP_EXT_DIR" ] || die "Could not determine PHP extension dir."

PHP_PHPIZE="${PHP_BIN_DIR}/phpize"
[ -x "$PHP_PHPIZE" ] || PHP_PHPIZE="$(command -v phpize)"

CLI_SCAN_DIR="$("$PHP_BIN" --ini 2>/dev/null \
    | awk -F': ' '/Scan for additional \.ini files in:/{print $2}' || true)"

ok "PHP version    : ${PHP_VER_MM}"
ok "Extension dir  : ${PHP_EXT_DIR}"
ok "phpize         : ${PHP_PHPIZE}"
[ -n "$CLI_SCAN_DIR" ] && ok "INI scan dir   : ${CLI_SCAN_DIR}"
echo ""

step "🧹 Cleaning previous build artifacts..."
cd "$EXT_SRC"

if [ -f Makefile ]; then
    make distclean >>"$LOG_FILE" 2>&1 || true
fi

"$PHP_PHPIZE" --clean >>"$LOG_FILE" 2>&1 || true
ok "ext/ cleaned"
echo ""

export CFLAGS="${CFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types -Wno-pointer-compare"
export CPPFLAGS="${CPPFLAGS:-} -Wno-error -Wno-error=incompatible-pointer-types"

step "⚙️  Running phpize..."
"$PHP_PHPIZE" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "phpize failed."; }
ok "phpize complete"

step "⚙️  Configuring (--enable-gtk)..."
./configure --with-php-config="$PHP_CONFIG" --enable-gtk \
    >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "./configure failed."; }
ok "configure complete"
echo ""

step "🔨 Building extension ($(nproc) cores)..."
make -j"$(nproc)" >>"$LOG_FILE" 2>&1 || { show_failure_logs; die "make failed. See ${LOG_FILE}."; }

[ -f "$BUILD_SO" ] || { show_failure_logs; die "Build succeeded but ${BUILD_SO} not found."; }
ok "Build complete → ${BUILD_SO}"
echo ""

step "📦 Installing binary..."
$SUDO mkdir -p "$PHP_EXT_DIR"
$SUDO cp -f "$BUILD_SO" "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
$SUDO chmod 755 "${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
ok "Installed → ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
echo ""

step "⚙️  Enabling extension..."

declare -a CONF_CANDIDATES=()
[ -n "$CLI_SCAN_DIR" ] && [ "$CLI_SCAN_DIR" != "(none)" ] && [ -d "$CLI_SCAN_DIR" ] \
    && CONF_CANDIDATES+=("$CLI_SCAN_DIR")

for d in \
    "/etc/php/${PHP_VER_MM}/cli/conf.d" \
    "/etc/php/${PHP_VER_MM}/fpm/conf.d" \
    "/etc/php/${PHP_VER_MM}/apache2/conf.d"; do
    [ -d "$d" ] && CONF_CANDIDATES+=("$d")
done

ALPINE_CONF="/etc/php${PHP_VER_NN}/conf.d"
[ -d "$ALPINE_CONF" ] && CONF_CANDIDATES+=("$ALPINE_CONF")

CONF_DIRS=()
while IFS= read -r _dir; do
    CONF_DIRS+=("$_dir")
done < <(printf "%s\n" "${CONF_CANDIDATES[@]}" | awk '!seen[$0]++')

INI_NAME="30-${EXTENSION_NAME}.ini"
INI_CONTENT="extension=${PHP_EXT_DIR}/${EXTENSION_NAME}.so"

if [ "${#CONF_DIRS[@]}" -eq 0 ]; then
    echo "   ⚠️  No conf.d directories found. Enabling for CLI context only."
fi

for confd in "${CONF_DIRS[@]:-}"; do
    echo "$INI_CONTENT" | $SUDO tee "${confd}/${INI_NAME}" >/dev/null
    ok "Written: ${confd}/${INI_NAME}"
done
echo ""

step "🔍 Verifying installation (CLI)..."
if "$PHP_BIN" -m 2>/dev/null | grep -q "^${EXTENSION_NAME}$"; then
    ok "Extension loaded successfully"
else
    die "Extension not detected by PHP. Check php --ini and ${INI_NAME} placement."
fi
echo ""

step "============================================"
step " Extension Information"
step "============================================"
"$PHP_BIN" --ri "${EXTENSION_NAME}" || true
echo ""

if command -v systemctl >/dev/null 2>&1; then
    for svc in "php${PHP_VER_MM}-fpm" "php-fpm"; do
        if systemctl is-active --quiet "${svc}.service" 2>/dev/null; then
            step "🔁 Reloading ${svc}..."
            $SUDO systemctl reload "${svc}" || true
            ok "${svc} reloaded"
            break
        fi
    done
fi

echo "✅  Installation complete!"
echo ""
echo "File locations:"
echo "  • Binary : ${PHP_EXT_DIR}/${EXTENSION_NAME}.so"
if [ "${#CONF_DIRS[@]}" -gt 0 ]; then
    for d in "${CONF_DIRS[@]}"; do
        echo "  • Config : ${d}/${INI_NAME}"
    done
else
    echo "  • Config : (check php --ini)"
fi
echo ""
echo "Headless version check:"
echo "  php ${SCRIPT_DIR}/examples/proof_of_work.php"
echo ""
echo "Window proof (needs a logged-in Wayland/X11 seat):"
echo "  php ${SCRIPT_DIR}/examples/proof_window.php"
echo ""
