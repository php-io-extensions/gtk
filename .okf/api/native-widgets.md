---
type: API
title: Native widget family
status: draft
generated: { by: cursor-agent, at: "2026-08-14T17:20:00Z" }
---

Each method calls the matching libgtk-4 function (or a documented trivial pair). Dialogs need GTK 4.10+.

**Display:** `GtkLabel` text; `GtkImage` file/icon/clear/pixel size; `GtkPicture` filename; `GtkSpinner` start/stop/spinning; `GtkProgressBar` fraction/text/pulse; `GtkSeparator` orientation.

**Input:** `GtkEntry` text/placeholder/visibility; `GtkPasswordEntry` text/peek; `GtkTextView` buffer + set/get text (buffer get_bounds + get_text); `GtkCheckButton` label/active; `GtkToggleButton` label/active; `GtkSwitch` active; `GtkSpinButton` range/value; `GtkScale` range/value (`gtk_range_*`); `GtkDropDown` `new_from_strings`/selected; `GtkSearchEntry` text.

**Chrome:** `GtkHeaderBar` title widget/pack/show-title-buttons; `GtkWindow` `set_titlebar` / `get_titlebar`; `GtkMenuButton` label/popover/popup; `GtkPopover` child/popup/autohide; `GtkScrolledWindow` child/policy/min content; `GtkNotebook` pages; `GtkStack` add/visible child; `GtkPaned` start/end/position; `GtkGrid` attach/spacing; `GtkFixed` put/move/remove at x/y; `GtkCenterBox` start/center/end; `GtkOverlay` child/overlays; `GtkListBox` append/select/row; `GtkListView` + `GtkStringList` + `GtkSingleSelection` + `GtkListItem` factory/setup/bind.

**Dialogs:** `GtkAlertDialog` show + choose (callback gets button index); `GtkFileDialog` open/save/select_folder (callback gets path or `""`); `GtkColorDialog` choose_rgba (callback gets `r,g,b,a`); `GtkFontDialog` choose_font (callback gets Pango description string).
