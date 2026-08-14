<?php
/**
 * GTK hosts Vulkan via gtk_gpu_pane X11 child — no GLFW, no GtkVulkanArea.
 *
 *   DISPLAY=:0 GDK_BACKEND=x11 php examples/proof_vulkan_x11.php
 *
 * Requires ext-gtk + ext-vulkan. php -m must not need glfw.
 */
declare(strict_types=1);

use Gtk\GTK\Application\GtkApplication;
use Gtk\GTK\GpuPane\GtkGpuPane;
use Gtk\GTK\Gtk;
use Gtk\GTK\GtkError;
use Gtk\GTK\GtkGLib;
use Gtk\GTK\Widget\GtkWidget;
use Gtk\GTK\Window\GtkWindow;
use Vulkan\Vk\Vk;

if (! extension_loaded('gtk')) {
    fwrite(STDERR, "gtk extension is not loaded\n");
    exit(1);
}
if (! extension_loaded('vulkan')) {
    fwrite(STDERR, "vulkan extension is not loaded\n");
    exit(1);
}
if (extension_loaded('glfw')) {
    fwrite(STDERR, "note: glfw is loaded but this path must not call it\n");
}

if (! Gtk::gtkInitCheck()) {
    fwrite(STDERR, "gtk_init_check failed: ".GtkError::gtkLastMessage()."\n");
    exit(1);
}

$app = GtkApplication::gtkApplicationNew('org.scrapyardio.gtk.vulkan-x11', 32);
if ($app === 0) {
    fwrite(STDERR, "gtk_application_new failed: ".GtkError::gtkLastMessage()."\n");
    exit(1);
}

GtkGLib::gSignalConnect($app, 'activate', static function (int $application): void {
    $window = GtkWindow::gtkApplicationWindowNew($application);
    GtkWindow::gtkWindowSetTitle($window, 'gtk gpu pane + vulkan x11');
    GtkWindow::gtkWindowSetDefaultSize($window, 640, 480);

    $pane = GtkGpuPane::gtkGpuPaneNew();
    if ($pane === 0) {
        fwrite(STDERR, "gtk_gpu_pane_new failed: ".GtkError::gtkLastMessage()."\n");
        GtkApplication::gtkApplicationQuit($application);

        return;
    }
    GtkWidget::gtkWidgetSetHexpand($pane, true);
    GtkWidget::gtkWidgetSetVexpand($pane, true);
    GtkWindow::gtkWindowSetChild($window, $pane);

    $boot = static function (int $widget) use ($application): void {
        static $booted = false;
        if ($booted) {
            return;
        }
        $native = GtkGpuPane::gtkGpuPaneNative($widget);
        if (($native['backend'] ?? '') !== 'x11' || (int) $native['display'] === 0 || (int) $native['window'] === 0) {
            return;
        }
        $booted = true;

        $instance = Vk::createInstance(
            ['VK_KHR_surface', 'VK_KHR_xlib_surface'],
            'php-io-extensions/gtk-vulkan-x11'
        );
        if ($instance->fd === 0) {
            fwrite(STDERR, "vkCreateInstance failed: ".Vk::lastError()."\n");
            GtkApplication::gtkApplicationQuit($application);

            return;
        }

        $surface = Vk::createXlibSurface($instance, (int) $native['display'], (int) $native['window']);
        if ($surface->fd === 0) {
            fwrite(STDERR, "vkCreateXlibSurface failed: ".Vk::lastError()."\n");
            Vk::destroyInstance($instance);
            GtkApplication::gtkApplicationQuit($application);

            return;
        }

        $devices = Vk::enumeratePhysicalDevices($instance);
        if ($devices === []) {
            fwrite(STDERR, "no Vulkan physical devices\n");
            Vk::destroySurface($instance, $surface);
            Vk::destroyInstance($instance);
            GtkApplication::gtkApplicationQuit($application);

            return;
        }

        $family = Vk::findGraphicsPresentQueue($devices[0], $surface);
        if ($family < 0) {
            fwrite(STDERR, "no graphics+present queue\n");
            Vk::destroySurface($instance, $surface);
            Vk::destroyInstance($instance);
            GtkApplication::gtkApplicationQuit($application);

            return;
        }

        $device = Vk::createDevice($devices[0], $family);
        $queue = Vk::getDeviceQueue($device, $family);
        $width = GtkWidget::gtkWidgetGetWidth($widget);
        $height = GtkWidget::gtkWidgetGetHeight($widget);
        if ($width < 1) {
            $width = 640;
        }
        if ($height < 1) {
            $height = 480;
        }

        $swapchain = Vk::createSwapchain($instance, $devices[0], $device, $queue, $surface, $width, $height);
        if ($swapchain->fd === 0) {
            fwrite(STDERR, "createSwapchain failed: ".Vk::lastError()."\n");
            Vk::destroyDevice($device);
            Vk::destroySurface($instance, $surface);
            Vk::destroyInstance($instance);
            GtkApplication::gtkApplicationQuit($application);

            return;
        }

        $status = Vk::presentFrame($swapchain, 32 / 255, 64 / 255, 128 / 255, 1.0);
        if ($status !== 0) {
            fwrite(STDERR, "presentFrame status {$status}: ".Vk::lastError()."\n");
        }

        GtkWidget::gtkWidgetAddTickCallback($widget, static function () use ($swapchain): bool {
            Vk::presentFrame($swapchain, 32 / 255, 64 / 255, 128 / 255, 1.0);

            return true;
        });
    };
    GtkGLib::gSignalConnect($pane, 'realize', $boot);
    GtkGLib::gSignalConnect($pane, 'map', $boot);

    GtkGLib::gSignalConnect($window, 'close-request', static function () use ($application): bool {
        GtkApplication::gtkApplicationQuit($application);

        return false;
    });

    GtkWindow::gtkWindowPresent($window);
});

$status = GtkApplication::gtkApplicationRun($app);
GtkGLib::gObjectUnref($app);
exit($status);
