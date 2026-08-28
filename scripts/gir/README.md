# Vendored GObject-Introspection data

These `.gir.gz` files are the **audit truth** for this extension: `scripts/audit-gir.php`
verifies that every class's bound + `@reserved` surface exactly matches the members
declared here. Do not regenerate them casually — the bound surface is pinned to the
versions below.

## Provenance

Harvested 2026-08-28 from the Pi 5 build box (Debian GNU/Linux 13 "trixie", aarch64,
PHP 8.4.20 ZTS) — the same machine that compiles and runs the extension.

| File | Source path on Pi | Debian package | Version |
|---|---|---|---|
| `Gtk-4.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-gtk-4.0` | `4.18.6+ds-2` (GTK 4.18.6) |
| `Gdk-4.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-gtk-4.0` | `4.18.6+ds-2` |
| `Gsk-4.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-gtk-4.0` | `4.18.6+ds-2` |
| `Gio-2.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-glib-2.0-dev` | `2.84.4-3~deb13u2` (GLib 2.84.4) |
| `GObject-2.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-glib-2.0-dev` | `2.84.4-3~deb13u2` |
| `GLib-2.0.gir.gz` | `/usr/lib/aarch64-linux-gnu/gir-1.0/` | `gir1.2-glib-2.0-dev` | `2.84.4-3~deb13u2` |
| `Pango-1.0.gir.gz` | `/usr/share/gir-1.0/` | `gir1.2-pango-1.0` | `1.56.3-1` (Pango 1.56.3) |

Note: `GLib-2.0.gir` is the one file Debian ships under the arch-specific
`/usr/lib/aarch64-linux-gnu/gir-1.0/` instead of `/usr/share/gir-1.0/`.

`pkg-config --modversion` on the Pi at harvest time: `gtk4` 4.18.6, `glib-2.0` 2.84.4,
`pango` 1.56.3. Matching dev packages installed: `libgtk-4-dev 4.18.6+ds-2`,
`libglib2.0-dev 2.84.4-3~deb13u2`, `libpango1.0-dev 1.56.3-1`.

## Refreshing

Only refresh when the Pi's GTK stack is deliberately upgraded and the pinned floor in
`build-linux.sh` / `config.json` moves with it. Re-harvest all seven files together from
the paths above, re-gzip (`gzip -9`), and update this table with the new package versions.
