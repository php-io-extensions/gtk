<div align="center" id="header">

<h1>ext-gtk</h1>

<h3>GTK 4 and the GLib main loop bound 1:1 into PHP 8.4+</h3>


[![CI](https://img.shields.io/github/actions/workflow/status/php-io-extensions/gtk/ci.yml?style=flat-square&label=CI)](https://github.com/php-io-extensions/gtk/actions/workflows/ci.yml)
[![GTK API](https://img.shields.io/badge/GTK_API-17.3%25_%28657%2F3798%29-blue?style=flat-square)](SUPPORT.md)
[![Packagist](https://img.shields.io/packagist/v/php-io-extensions/gtk?style=flat-square)](https://packagist.org/packages/php-io-extensions/gtk)
[![PHP](https://img.shields.io/packagist/dependency-v/php-io-extensions/gtk/php?style=flat-square&label=PHP)](https://packagist.org/packages/php-io-extensions/gtk)
[![License](https://img.shields.io/github/license/php-io-extensions/gtk?style=flat-square)](LICENSE)
[![Platform](https://img.shields.io/badge/platform-linux_%7C_macos-blue?style=flat-square&logo=linux&logoColor=white)](#requirements)
[![OKF](https://img.shields.io/badge/OKF-0.2-6f42c1?style=flat-square&label=knowledge%20bundle)](.okf/index.md)
[![PIE](https://img.shields.io/badge/PIE-installable-4f5b93?style=flat-square&logo=php&logoColor=white)](https://github.com/php/pie)

</div>

A desktop app on Linux needs windows the compositor manages, a menu bar built from actions, controls that follow the system theme, keyboard focus and input methods, lists and trees that scroll, video, and a main loop that sleeps until a timer, a file descriptor or the display has something for it. Writing that against Wayland or X11 directly is a toolkit's worth of work before the first button.

<b>GTK</b> is that toolkit. GNOME and its applications are built on it: `GtkApplication` registers the app with the desktop, windows hold widget trees, layout managers place them, signals report what changed, and GLib's main context dispatches every source. It is written in C, and its documentation covers every call.

<b>The only problem?</b> PHP can't reach it. This extension binds GTK 4 and the GLib main loop it runs on one to one in C against the Zend API, linked against the system's GTK and GLib. C functions keep their names (`g_timeout_add`, `g_signal_connect`); functions on a type are methods of the class named after it (`g_application_register(app, cancellable, &error)` is `$app->register($cancellable)`). Signal handlers and sources are PHP callables that run on the PHP thread, and GTK's criticals, warnings, NULLs and clamping reach PHP as GTK gives them. No defaults, no composites, no opinions: what GTK documents is what you call.

## Basic usage

Register an application, wait up to 16 ms for a source and dispatch it, and wake on a file descriptor:

```php
$app = GtkApplication::new('com.example.App', GApplicationFlags::DEFAULT_FLAGS);
g_signal_connect($app, 'activate', fn (GtkApplication $app) => null);
$app->register(null);   // startup: GTK initialises
$app->hold();

$ctx = GMainContext::default();

// Sleep up to 16 ms, or until a source is ready, dispatching what is.
$budget = g_timeout_add(16, fn (): bool => G_SOURCE_REMOVE);
$ctx->iteration(true);

// Wake on a descriptor (a kqueue or epoll fd works: it turns readable when its own events are pending).
g_unix_fd_add($fd, GIOCondition::IN, fn (int $fd, int $condition): bool => G_SOURCE_CONTINUE);

$app->release();
```

## Requirements

- Linux or macOS. `composer.json` lists those two families.
- PHP 8.4 or newer, NTS or ZTS, with `phpize` and `php-config`.
- A C compiler and `pkg-config`.
- GTK 4.12 or newer and GLib 2.74 or newer, with their development files (`gtk4`, `glib-2.0`, `gio-unix-2.0` through `pkg-config`).
- For video, GTK's media backend module: `libgtk-4-media-gstreamer` on Debian (the Debian installer requires it). Homebrew's gtk4 ships none: the macOS installer warns, `GtkMediaFile::new()->typeName()` is `GtkNoMediaFile` and `GtkVideo` shows nothing.

```bash
# Debian, Ubuntu, Raspberry Pi OS
sudo apt install build-essential pkg-config libgtk-4-dev php8.4-dev \
    libgtk-4-media-gstreamer gstreamer1.0-plugins-good gstreamer1.0-plugins-bad

# macOS: Xcode Command Line Tools, and Homebrew's PHP ships phpize and php-config
xcode-select --install
brew install pkgconf gtk4 php@8.4
```

## Installation

### With PHP PIE (recommended)

```bash
pie install php-io-extensions/gtk
```

### Manually (install script)

```bash
git clone https://github.com/php-io-extensions/gtk.git
cd gtk

./install-debian-trixie.sh             # Debian Trixie, Ubuntu 24.04+, Raspberry Pi OS: the php on PATH
./install-macos.sh                     # Homebrew php@8.4 and php@8.4-zts
./install-macos.sh /path/to/bin/php    # the macOS script takes specific PHP binaries
```

### Manually (phpize)

```bash
git clone https://github.com/php-io-extensions/gtk.git
cd gtk
phpize
./configure --enable-gtk
make -j"$(nproc 2>/dev/null || sysctl -n hw.ncpu)"
sudo make install
```

Then add `extension=gtk.so` to your `php.ini`, or to a file in the scan directory `php --ini` reports.

### Verify

```console
$ php --ri gtk

gtk

gtk support => enabled
Version => 0.11.2
GTK => 4.24.1 (built 4.24.1)
GLib => 2.90.1 (built 2.90.1)
```

## API

The calls that initialise GTK, register the application with the desktop, hold
and release it, pump the main context, sleep with a budget, wake a sleep, open
and close windows, and build menu bars from menu models and actions:

| | Native |
|---|---|
| functions | `gtk_init`, `gtk_init_check`, `gtk_is_initialized`, `gtk_get_{major,minor,micro}_version`, `g_set_prgname`, `g_get_prgname`, `g_timeout_add`, `g_idle_add`, `g_unix_fd_add`, `g_source_remove`, `g_signal_connect`, `g_signal_emit_by_name`, `g_signal_handler_disconnect`, `g_signal_handler_is_connected` |
| `GObject` | `G_OBJECT_TYPE_NAME` |
| `GApplication` | `g_application_id_is_valid`, `get_application_id`, `get_flags`, `get_is_registered`, `get_is_remote`, `register`, `activate`, `hold`, `release`, `quit`, `run`, `g_action_map_add/remove/lookup_action`, `g_action_group_has/list/activate_action` |
| `GtkApplication` | `gtk_application_new`, `add_window`, `remove_window`, `get_active_window`, `get_windows`, `get_menubar`, `set_menubar`, `set_accels_for_action`, `get_accels_for_action` |
| `GtkWidget` | `show`, `hide`, `get/set_visible`, `get_realized`, `get_mapped`, `get/set_hexpand`, `get/set_vexpand`, `get_parent`, `insert_action_group`, `activate_action_variant`, `activate`, `get/set_halign`, `get/set_valign`, `get/set_size_request`, `get_width`, `get_height`, `get/set_sensitive`, `is_sensitive`, `get_color`, `set_margin_start/end/top/bottom`, `add/remove/has_css_class`, `measure`, `compute_bounds`, `get_first_child`, `get_next_sibling`, `get_native`, `get_root`, `grab_focus`, `child_focus` (`GtkDirectionType`), `has_focus`, `set_cursor_from_name`, `get/set_tooltip_text`, `get/set_overflow` (`GtkOverflow`), `get/set_can_target`, `get/set_layout_manager` |
| `GtkNative`, `GtkRoot` (windows, popovers) | `get_surface`, `get_surface_transform`, `get_for_surface`, `realize`, `unrealize`; `get_display`, `get/set_focus` |
| `GtkWindow` | `new`, `get/set_title`, `get/set_default_size`, `get/set_child`, `present`, `close`, `destroy`, `is_active`, `get/set_transient_for`, `get/set_application`, `get/set_modal`, `get/set_hide_on_close`, `get_focus`, `get/set_default_widget`, `get_group` |
| `GtkWindowGroup` | `new`, `add_window`, `remove_window` |
| `GtkApplicationWindow` | `new`, `get/set_show_menubar`, `get_id` |
| `GtkAboutDialog` | `new`, `get/set_program_name`, `get/set_version`, `get/set_copyright`, `get/set_comments`, `get/set_website` |
| `GtkConstraintLayout`, `GtkConstraint`, `GtkConstraintGuide` | `gtk_constraint_layout_new`, `add_constraint`, `add_guide`; `gtk_constraint_new`; `gtk_constraint_guide_new`, `set_nat_size`, `set_max_size` |
| `GtkBox` | `new`, `append`, `prepend`, `remove`, `insert_child_after`, `reorder_child_after`, `get/set_spacing`, `get/set_homogeneous` |
| `GtkGrid`, `GtkFixed` | `new`, `attach`, `remove`, `get_child_at`, `get/set_row_spacing`, `get/set_column_spacing`; `new`, `put`, `move`, `remove`, `get_child_position` |
| `GtkFlowBox`, `GtkFlowBoxChild`, `GtkSelectionMode` | `new`, `insert`, `append`, `prepend`, `remove`, `remove_all`, `get_child_at_index`, `get/set_homogeneous`, `get/set_row_spacing`, `get/set_column_spacing`, `get/set_min_children_per_line`, `get/set_max_children_per_line`, `get/set_selection_mode`; `new`, `get/set_child`, `is_selected`, `changed` |
| `GdkGLContext`, `GdkGLAPI`, `GtkGLArea` | `make_current`, `clear_current`, `get_current`, `realize`, `get_use_es`, `get_version`, `get_api`; `new`, `get_context`, `make_current`, `attach_buffers`, `queue_render`, `get/set_auto_render`, `get/set_has_depth_buffer`, `get/set_has_stencil_buffer`, `get/set_allowed_apis`, `set_required_version`, `get_error` (signal `render`) |
| `GtkCssProvider`, `GdkDisplay`, `GdkSurface` | `new`, `load_from_string`; `get_default`, `sync`, `get_clipboard`; `get_width`, `get_height` (signal `layout`); functions `gtk_style_context_add/remove_provider_for_display` |
| `GtkLabel` | `new`, `get/set_text`, `get/set_wrap`, `set_ellipsize`, `get/set_xalign`, `set_justify`, `set_markup`, `get/set_use_markup`, `get_current_uri` |
| `GtkButton`, `GtkToggleButton`, `GtkCheckButton`, `GtkSwitch` | `new_with_label`, `get/set_label`; `new_with_label`, `get/set_active`; `new_with_label`, `get/set_active`, `get/set_label`; `new`, `get/set_active` |
| `GtkLinkButton` | `new`, `new_with_label`, `get/set_uri`, `get/set_visited` |
| `GCancellable`, `GAsyncResult`, `GtkUriLauncher` | `new`, `cancel`, `is_cancelled`; —; `new`, `get/set_uri`, `launch`, `launch_finish` |
| `GtkAlertDialog`, `GtkFileDialog`, `GtkFileLauncher` (GTK 4.10) | made with `g_object_new_with_properties` (the printf constructor is not bound), `set_message`, `set_detail`, `set_buttons`, `set_default_button`, `set_cancel_button`, `set_modal`, `choose`, `choose_finish`; `new`, `set_title`, `set_initial_folder`, `set_initial_name`, `set_modal`, `open`, `open_multiple`, `select_folder`, `save` and their `_finish` (a dismissed or cancelled dialog throws `GError`); `new`, `launch`, `launch_finish` |
| `GFile`, `GListStore`, `GdkClipboard` | `new_for_path`, `get_path` (GLocalFile, GDaemonFile and GDummyFile box as `GFile`); a `GListModel`; `set_text` |
| `GtkEntry`, `GtkEditable`, `GtkEntryBuffer` | `new`, `get_buffer`, `get/set_placeholder_text`, `get/set_visibility`, `get/set_has_frame`, `get/set_max_length`, `get/set_activates_default`, `set_icon_from_icon_name` (`GtkEntryIconPosition`); `gtk_editable_get/set_editable` (an interface GtkEntry implements); `get/set_text` |
| `GtkTextView`, `GtkTextBuffer` | `new`, `get_buffer`, `get/set_editable`, `set_wrap_mode`, `get/set_monospace`, `get/set_cursor_visible`, `get_line_yrange`; `set_text`, `get_text` (between two iters), `begin/end_user_action`, `get_tag_table`, `get_iter_at_line`, `get_iter_at_line_offset`, `get_start/end_iter`, `apply/remove_tag`, `get_selection_bounds`, `select_range`, `get_insert`, `get_iter_at_mark`, `get_line_count` |
| `GtkTextIter`, `GtkTextMark`, `GtkTextTag`, `GtkTextTagTable`, `GtkAdjustment` | iter (a copy that keeps its buffer alive; stale once the text changes: `GtkException`) `get_line`, `get_line_offset`, `get_offset`, `has_tag`, `get_tags`; —; `new`; `add`, `remove`, `lookup`; `get/set_value`, `get_lower`, `get_upper`, `get_page_size` (signal `value-changed`) |
| `GtkScale` | `new_with_range`, `gtk_range_get/set_value`, `gtk_range_set_range`, `gtk_range_set_increments`, `get/set_draw_value` |
| `GtkDropDown`, `GtkStringList`, `GtkStringObject` | `new_from_strings`, `get/set_selected`, `get_selected_item`, `set_model`, `set_factory`, `set_list_factory`; `new`, `append`, `remove`, `splice`, `get_string`, `g_list_model_get_n_items`; `get_string` |
| `GtkCalendar`, `GDateTime` | `new`, `get_date`, `select_day`; `new_local`, `get_year`, `get_month`, `get_day_of_month`, `to_unix` |
| `GSettingsSchemaSource`, `GSettingsSchema`, `GSettings` | `g_settings_schema_source_get_default`, `g_settings_schema_source_lookup`; `g_settings_schema_has_key`; `g_settings_new`, `g_settings_get_boolean`, `get_int`, `get_uint`, `get_double`, `get_string` |
| `GtkProgressBar`, `GtkSpinner` | `new`, `get/set_fraction`, `pulse`, `set_pulse_step`; `new`, `get/set_spinning` |
| `GtkEventController` (`Key`, `Motion`, `Scroll`, `Focus`), `GtkGesture`, `GtkGestureSingle`, `GtkGestureClick` | `new` (scroll takes `GTK_EVENT_CONTROLLER_SCROLL_*` flags), `get/set_propagation_phase`, `get_widget`, `get_current_event` (`GdkEvent`, `GdkScrollEvent` with `get_relative_direction` on GTK 4.20+); scroll `get/set_flags`, `get_unit`; gesture `set_state` (`GtkEventSequenceState`); single `get/set_button`, `get_current_button`, `get/set_touch_only`; `GtkGestureLongPress` `new`; signals through `g_signal_connect` |
| `GtkEventControllerLegacy`, `GdkEvent` (`GdkButtonEvent`, `GdkTouchEvent`, `GdkScrollEvent`) | `new`; event `get_event_type`, `get_position`, `get_pointer_emulated`, `get_modifier_state`; button `get_button`; touch `get_emulating_pointer`; enum `GdkEventType` |
| `GtkShortcutController`, `GtkShortcut`, `GtkShortcutTrigger`, `GtkShortcutAction`, `GtkCallbackAction` | controller `new`, `add/remove_shortcut`, `get/set_scope` (and `GListModel`); shortcut `new`; trigger `parse_string`; action `activate`; callback action `new` (callable trampoline, released at finalize); enums `GtkShortcutScope`, `GtkShortcutActionFlags` |
| `GtkIMContext`, `GtkIMMulticontext` | multicontext `new`; `set_client_widget`, `filter_keypress`, `focus_in`, `focus_out`, `reset`; `commit` signal |
| `GtkWidget` controllers, coordinates | `add_controller`, `remove_controller`, `compute_point`, `pick` (`GTK_PICK_*`); `GtkWindow` `get_surface_transform` (`gtk_native_get_surface_transform`) |
| `GtkSettings`, properties | `get_default`; `g_object_get_property`, `g_object_set_property`, `g_object_new_with_properties` (any GObject property, as a signal argument converts) |
| Keyvals | `gdk_keyval_to_unicode`, `gdk_keyval_to_lower`; `GDK_*_MASK` constants, enums `GtkPropagationPhase`, `GdkScrollUnit`, `GdkScrollRelativeDirection` (4.20+) |
| `GtkImage` | `new_from_icon_name`, `get_icon_name`, `set_from_icon_name`, `set_from_file`, `get/set_pixel_size` |
| `GtkPicture`, `GtkSeparator`, `GtkScrolledWindow` | `new`, `new_for_filename`, `set_filename`, `get/set_content_fit`, `get/set_paintable`, `get/set_can_shrink`; `new`; `new`, `get/set_child`, `set_policy`, `get_hadjustment`, `get_vadjustment` |
| `GtkPaned`, `GtkNotebook` | `new(GtkOrientation)`, `get/set_start_child`, `get/set_end_child` (a child parented elsewhere → `ValueError`), `get/set_position` (negative unsets it), `get/set_resize_start_child`, `get/set_resize_end_child`, `get/set_shrink_start_child`, `get/set_shrink_end_child`, `get/set_wide_handle`; `new`, `append_page`, `remove_page`, `page_num`, `get_n_pages`, `get/set_current_page`, `get_nth_page`, `set/get_tab_label_text`, `get/set_show_tabs`, `get/set_scrollable` (GTK's own indexes: -1 the last page, past the end nothing; a tab label set on a child that is not a page, which GTK asserts on, → `ValueError`); signals `notify::position`, `switch-page` |
| `GBytes`, `GdkTexture`, `GdkMemoryTexture`, `GdkMemoryTextureBuilder` | `new` (a string's bytes, or an address and a size), `get_size`, `get_data`; `get_width`, `get_height`; `new` from a `GBytes` in a `GdkMemoryFormat` (null when the bytes cannot hold the image); GTK 4.16+ builder: setters returning nothing, `set_bytes(GBytes)`, an update texture and an update region (`CairoRegion`), `build` (null when unset) |
| `GdkDmabufTextureBuilder` | Linux, GTK 4.14+: `setDisplay`, `setWidth`, `setHeight`, `setFourcc`, `setModifier`, `setPremultiplied`, `setNPlanes`, per plane `setFd` (borrowed: keep it open while the textures live), `setStride`, `setOffset`, `setUpdateTexture`, `setUpdateRegion`, `build(?callable $destroy)` (`$destroy` runs once GTK has finalized the texture and is done with the fds; a failed import throws its `GError`) |
| `GdkDmabufFormats` | GTK 4.14+, from `GdkDisplay::getDmabufFormats()`: `getNFormats`, `getFormat` (`[fourcc, modifier]`), `contains(fourcc, modifier)`; empty off Linux |
| `GtkTreeListModel`, `GtkTreeListRow`, `GtkTreeExpander`, `GtkScrollInfo` | `new` (create func = PHP callable returning a `GListModel` or null, held until the model is finalized), `get_row`, `get_child_row`; `get_item`, `get/set_expanded`, `is_expandable`, `get_depth`, `get_position`, `get_parent`, `get_child_row`; `new`, `get/set_child`, `get/set_list_row`; `new`, `get/set_enable_horizontal`, `get/set_enable_vertical` |
| `GtkColumnView`, `GtkColumnViewColumn` | `new`, `append/remove_column`, `get/set_model`, `set_show_row/column_separators`, `scroll_to` (`GTK_LIST_SCROLL_*`); `new`, `get/set_title`, `set_expand`, `set_resizable` |
| `GtkSignalListItemFactory`, `GtkListItem`, `GtkSingleSelection` | `new` (signals `setup`, `bind`, `unbind`, `teardown`); `get_position`, `get_item`, `get/set_child`; `new`, `get/set_selected`, `get_selected_item`, `set_autoselect`, `set_can_unselect`, `get_model` |
| `GtkMediaStream`, `GtkMediaFile`, `GtkVideo` | `play`, `pause`, `get/set_playing`, `get_ended`, `get_error`, `seek`, `is_seekable`, `get_timestamp`, `get_duration`, `get/set_muted`, `get/set_loop`, `has_video`; `new`, `new_for_filename`, `set_filename`, `clear`; `new`, `get/set_media_stream`, `get/set_autoplay`, `set_loop` |
| `GtkPopoverMenuBar` | `new_from_model`, `get/set_menu_model` |
| `GtkMenuButton`, `GtkScrollbar`, `GtkListView` | `new`, `get/set_menu_model`, `get/set_popover`, `get/set_child`, `get/set_has_frame`, `popup`, `popdown`; `new(GtkOrientation, GtkAdjustment)`, `get_adjustment`; `new(model, factory)` (both transfer full), `get/set_single_click_activate`, signal `activate` |
| Button children, adjustments, notebook insert, surface scale | `GtkButton` `get/set_child`, `get/set_has_frame`; `GtkAdjustment` `new`, `configure`; `GtkNotebook` `insert_page`; `GdkSurface` `get_scale` |
| `GtkPopover`, `GtkPopoverMenu` | `new`, `set/get_child`, `set/get_autohide`, `set/get_position` (`GtkPositionType`), `set/get_pointing_to` (a `GdkRectangle`; get writes it by reference and returns GTK's gboolean), `set/get_has_arrow`, `popup`, `popdown`, signal `closed`; menu `new_from_model`, `get_menu_model`; attached with its own `setParent` / `unparent` (`gtk_widget_set_parent`, bound for popovers only) |
| `GMenuModel`, `GMenu`, `GMenuItem` | `get_n_items`, `get_item_attribute_value` (an index outside the items, which GMenu reads unchecked, → `ValueError`; a value not of the expected type → null), `is_mutable`; `new`, `append`, `append_item`, `append_section`, `append_submenu`, `prepend`, `insert`, `insert_item`, `remove`, `remove_all`, `freeze`; `new`, `set_label`, `set_detailed_action`, `set_action_and_target_value`, `set/get_attribute_value`, `set_submenu`, `set_section` |
| `GSimpleAction`, `GSimpleActionGroup` | `new`, `new_stateful`, `set_enabled`, `set_state`, `g_action_get_name/enabled/state`, `g_action_activate`, `g_action_change_state`; `new`, `g_action_map_add/remove/lookup_action`, `g_action_group_has/list/activate_action` |
| `GVariant` | `new_boolean/string/int32/double`, `get_boolean/string/int32/double`, `get_type_string`, `is_of_type`, `print` |
| `GMainContext` | `default`, `get_thread_default`, `iteration`, `pending`, `wakeup`, `acquire`, `release`, `is_owner` |

Enums: `GApplicationFlags`, `GIOCondition`, `GtkOrientation`, `GtkAlign`,
`PangoEllipsizeMode`, `GtkJustification`, `GtkWrapMode`, `GtkContentFit`,
`GtkPolicyType`, `GtkPositionType`. Constants: `G_SOURCE_CONTINUE`, `G_SOURCE_REMOVE`,
`GTK_STYLE_PROVIDER_PRIORITY_APPLICATION`, `GTK_INVALID_LIST_POSITION`. Errors:
`GError` (a GError, with its `domain`; also what `GtkMediaStream::getError()`
returns), `GtkException` (a call refused because making it crashes; see below). The stubs in
`stubs/` are the full declaration.

### Errors

GTK answers for itself: its criticals, warnings, NULLs and clamping reach PHP
as GTK gives them. The extension refuses a call only where making it was shown
to crash the process or read freed memory, each such site with a probe in
`tests/Probes`: a widget before GTK is initialised; on macOS, a GDK call or a
context iteration off the process main thread; a stale `GtkTextIter`; a text
mark that is not the buffer's; a detailed action name GIO or GTK cannot parse;
an index outside a region's rectangles; a string shorter than the size or
character count asked of it; a class compiled against newer GTK than the one
running. A source or signal handler dispatched on a thread other than the one
whose PHP made it is dropped, and a PHP class cannot implement the native
interfaces (`GAction`, `GListModel`, `GtkNative` and the rest) unless its parent
class's GType does. A PHP int with no form in the C parameter's type is a
`ValueError`. `./configure --enable-gtk-probes` builds the switch the probes use
(env `PHPGTK_PROBE_OFF=<site>` turns one site off); never for a release.

### Coverage

[SUPPORT.md](SUPPORT.md) lists every constructor, method and function of GTK 4, GDK and GSK that
the installed GIR files declare and do not mark deprecated, each marked bound or not; the API badge
is computed from it. Regenerate both after a binding change, and check them:

```bash
php84 scripts/support.php           # writes SUPPORT.md and the badge
php84 scripts/support.php --check   # exits 1 when either is stale
```

## Running the test suite

```bash
composer install
XDEBUG_MODE=off php -d memory_limit=128M vendor/bin/pest
php examples/smoke.php          # bridge: register, pump, sleep, wake; prints SMOKE_OK
php examples/window-smoke.php   # window, menu bar, actions, close-request; prints SMOKE_OK
```

Tests open windows: run them in a logged-in GUI session. On Linux over SSH, export the session's `WAYLAND_DISPLAY`, `XDG_RUNTIME_DIR` and
`DBUS_SESSION_BUS_ADDRESS` first. The video playback test runs where a media
backend is installed and is skipped elsewhere. Design notes live in the OKF bundle under `.okf/`.

## License

MIT. See [LICENSE](LICENSE). GTK and GLib are LGPL-2.1-or-later; they are linked, not shipped.
