#!/bin/bash
# Copy this repo to the Pi via Angel's fnk alias, build, and run
# verify-reflection.php. Never inline fnk credentials; expand the alias
# through an interactive zsh. Prints REFLECTION_OK only when the remote
# reflection script does.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
REMOTE_DIR="${PI_GTK_DIR:-/home/angel/gtk}"
PHP_BIN="${PI_PHP_BIN:-/usr/local/php84-zts/bin/php}"

fnk_run() {
    zsh -ic "fnk $(printf '%q' "$1")"
}

echo "pi-wave-verify: packing ${ROOT}"
tmp="$(mktemp -t gtk-wave.XXXXXX.tgz)"
trap 'rm -f "${tmp}"' EXIT

(
    cd "${ROOT}"
    COPYFILE_DISABLE=1 tar czf "${tmp}" \
        --exclude '._*' \
        --exclude '.git' \
        --exclude 'ext/.libs' \
        --exclude 'ext/modules' \
        --exclude 'ext/autom4te.cache' \
        --exclude 'ext/build' \
        .
)

echo "pi-wave-verify: copying to ${REMOTE_DIR}"
# Stream the archive over fnk stdin; extract on the Pi.
# fnk is sshpass-wrapped ssh — credentials stay in ~/.zshrc.
fnk_run "mkdir -p '${REMOTE_DIR}' && rm -rf '${REMOTE_DIR:?}/'* '${REMOTE_DIR}'/.[!.]* 2>/dev/null || true"
cat "${tmp}" | fnk_run "tar xzf - -C '${REMOTE_DIR}' --exclude '._*'"

echo "pi-wave-verify: building on the Pi"
fnk_run "cd '${REMOTE_DIR}' && PHP_BIN='${PHP_BIN}' bash build-linux.sh"

echo "pi-wave-verify: reflecting"
out="$(fnk_run "cd '${REMOTE_DIR}' && '${PHP_BIN}' scripts/verify-reflection.php")"
printf '%s\n' "${out}"
if ! printf '%s\n' "${out}" | grep -q 'REFLECTION_OK'; then
    echo "pi-wave-verify: remote reflection did not print REFLECTION_OK" >&2
    exit 1
fi
