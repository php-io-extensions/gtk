#!/usr/bin/env python3
"""Fix Zephir 0.19 ZEPHIR_REGISTER_CLASS truncation for Gtk\\GTK\\* classes."""

from __future__ import annotations

import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
EXT = ROOT / "ext"

# Zephir 0.19 drops the last char of nested segments (GTK → GT).
FIXES = {
    "Gtk\\GT\\Application\\GtkApplication": "Gtk\\GTK\\Application\\GtkApplication",
    "Gtk\\GT\\Window\\GtkWindow": "Gtk\\GTK\\Window\\GtkWindow",
    "Gtk\\GT\\Widget\\GtkWidget": "Gtk\\GTK\\Widget\\GtkWidget",
    "Gtk\\GT\\Button\\GtkButton": "Gtk\\GTK\\Button\\GtkButton",
    "Gtk\\GT\\Box\\GtkBox": "Gtk\\GTK\\Box\\GtkBox",
    "Gtk\\GT\\GLArea\\GtkGLArea": "Gtk\\GTK\\GLArea\\GtkGLArea",
    "Gtk\\GT\\GpuPane\\GtkGpuPane": "Gtk\\GTK\\GpuPane\\GtkGpuPane",
    "Gtk\\GT\\GtkGLib": "Gtk\\GTK\\GtkGLib",
    "Gtk\\GT\\GtkError": "Gtk\\GTK\\GtkError",
    "Gtk\\GT\\Gtk": "Gtk\\GTK\\Gtk",
    "Gtk\\GT": "Gtk\\GTK",
}


def fix_file(path: Path) -> int:
    text = path.read_text(encoding="utf-8")
    original = text
    for bad, good in sorted(FIXES.items(), key=lambda item: len(item[0]), reverse=True):
        text = text.replace(bad, good)
    text = re.sub(
        r"\bGtk_GT_(Application_GtkApplication|Window_GtkWindow|Widget_GtkWidget|"
        r"Button_GtkButton|Box_GtkBox|GLArea_GtkGLArea|GpuPane_GtkGpuPane|GtkGLib|GtkError|Gtk)\b",
        r"Gtk_GTK_\1",
        text,
    )
    # Zephir emits gtk, shortname; macro prefixes gtk_ so shortname must be gtk_*.
    text = re.sub(
        r"(ZEPHIR_REGISTER_CLASS\([^,]+,\s*[^,]+,\s*gtk,\s*)(?!gtk_)([a-z0-9_]+)(\s*,)",
        r"\1gtk_\2\3",
        text,
    )
    if text != original:
        path.write_text(text, encoding="utf-8")
        return 1
    return 0


def main() -> None:
    if not EXT.exists():
        raise SystemExit("ext/ missing — run zephir generate first")
    changed = 0
    for path in EXT.rglob("*.c"):
        changed += fix_file(path)
    for path in EXT.rglob("*.h"):
        changed += fix_file(path)
    print(f"fixup-zephir-register: touched {changed} files")


if __name__ == "__main__":
    main()
