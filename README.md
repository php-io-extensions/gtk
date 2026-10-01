# ext-gtk

1:1 PHP bindings of GTK 4 and the GLib main loop GTK runs on, written directly
in C against the Zend API. C functions keep their names (`g_timeout_add`,
`g_signal_connect`); functions on a type are methods of the class named after it
(`g_application_register(app)` is `$app->register()`). No defaults, no
composites: behaviour is composed by the caller.

Linux first, macOS too. GTK 4.10+, GLib 2.74+, PHP 8.4+, NTS and ZTS.

## What is bound

The calls that initialise GTK, register the application with the desktop, hold
and release it, pump the main context, sleep with a budget, wake a sleep, open
and close windows, and build menu bars from menu models and actions:

| | Native |
|---|---|
| functions | `gtk_init`, `gtk_init_check`, `gtk_is_initialized`, `gtk_get_{major,minor,micro}_version`, `g_timeout_add`, `g_idle_add`, `g_unix_fd_add`, `g_source_remove`, `g_signal_connect`, `g_signal_handler_disconnect`, `g_signal_handler_is_connected` |
| `GObject` | `G_OBJECT_TYPE_NAME` |
| `GApplication` | `g_application_id_is_valid`, `get_application_id`, `get_flags`, `get_is_registered`, `get_is_remote`, `register`, `activate`, `hold`, `release`, `quit`, `run`, `g_action_map_add/remove/lookup_action`, `g_action_group_has/list/activate_action` |
| `GtkApplication` | `gtk_application_new`, `add_window`, `remove_window`, `get_active_window`, `get_windows`, `get_menubar`, `set_menubar`, `set_accels_for_action`, `get_accels_for_action` |
| `GtkWidget` | `set_visible` (as `show`/`hide`/`setVisible`), `get_visible`, `get_realized`, `get_mapped`, `get/set_hexpand`, `get/set_vexpand`, `get_parent`, `insert_action_group`, `activate_action_variant` |
| `GtkWindow` | `new`, `get/set_title`, `get/set_default_size`, `get/set_child`, `present`, `close`, `destroy`, `is_active`, `get/set_transient_for`, `get/set_application`, `get/set_modal`, `get/set_hide_on_close` |
| `GtkApplicationWindow` | `new`, `get/set_show_menubar`, `get_id` |
| `GtkAboutDialog` | `new`, `get/set_program_name`, `get/set_version`, `get/set_copyright`, `get/set_comments`, `get/set_website` |
| `GtkBox` | `new`, `append`, `prepend`, `remove` |
| `GtkPopoverMenuBar` | `new_from_model`, `get/set_menu_model` |
| `GMenuModel`, `GMenu`, `GMenuItem` | `get_n_items`, `is_mutable`; `new`, `append`, `append_item`, `append_section`, `append_submenu`, `prepend`, `insert`, `remove`, `remove_all`, `freeze`; `new`, `set_label`, `set_detailed_action`, `set_action_and_target_value`, `set/get_attribute_value`, `set_submenu`, `set_section` |
| `GSimpleAction`, `GSimpleActionGroup` | `new`, `new_stateful`, `set_enabled`, `set_state`, `g_action_get_name/enabled/state`, `g_action_activate`, `g_action_change_state`; `new`, `g_action_map_add/remove/lookup_action`, `g_action_group_has/list/activate_action` |
| `GVariant` | `new_boolean/string/int32/double`, `get_boolean/string/int32/double`, `get_type_string`, `is_of_type`, `print` |
| `GMainContext` | `default`, `get_thread_default`, `iteration`, `pending`, `wakeup`, `acquire`, `release`, `is_owner` |

Enums: `GApplicationFlags`, `GIOCondition`, `GtkOrientation`. Constants: `G_SOURCE_CONTINUE`,
`G_SOURCE_REMOVE`. Errors: `GError` (a GError, with its `domain`),
`GtkException` (a call refused before reaching GTK). The stubs in `stubs/` are
the full declaration.

## Example

```php
$app = GtkApplication::new('com.example.App', GApplicationFlags::DEFAULT_FLAGS);
g_signal_connect($app, 'activate', fn (GtkApplication $app) => null);
$app->register();   // startup: GTK initialises
$app->hold();

$ctx = GMainContext::default();

// Sleep up to 16 ms, or until a source is ready, dispatching what is.
$budget = g_timeout_add(16, fn (): bool => G_SOURCE_REMOVE);
$ctx->iteration(true);

// Wake on a descriptor (a kqueue or epoll fd works: it turns readable when its own events are pending).
g_unix_fd_add($fd, GIOCondition::IN, fn (int $fd, int $condition): bool => G_SOURCE_CONTINUE);

$app->release();
```

## Install

```bash
bash install-debian-trixie.sh   # Debian, Ubuntu, Raspberry Pi OS (needs libgtk-4-dev)
bash install-macos.sh           # Homebrew php@8.4 and php@8.4-zts (needs brew install gtk4)
```

Or with PIE: `pie install php-io-extensions/gtk`.

## Test

```bash
composer install
php vendor/bin/pest
php examples/smoke.php          # bridge: register, pump, sleep, wake; prints SMOKE_OK
php examples/window-smoke.php   # window, menu bar, actions, close-request; prints SMOKE_OK
```

On Linux over SSH, export the session's `WAYLAND_DISPLAY`, `XDG_RUNTIME_DIR` and
`DBUS_SESSION_BUS_ADDRESS` first. Design notes live in the OKF bundle under `.okf/`.

## License

MIT
