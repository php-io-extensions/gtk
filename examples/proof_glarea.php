<?php
/*
 * proof_glarea.php — a real window, a real GL context, PHP driving both.
 *
 * Puts a GtkGLArea in a GtkWindow and, in the area's render signal, calls
 * the *opengl* extension against the framebuffer GTK has already made
 * current: clear it, draw the triangle from ext-opengl's
 * examples/proof_headless.php, then glReadPixels the centre and a corner
 * back into a Bridge buffer and byte-check them on the first rendered
 * frame. The window then stays up for ~2s of real frames, pumped from PHP.
 *
 * Two extensions, one process, one seat: gtk owns the window and the
 * context, opengl owns the drawing. Neither knows about the other — the
 * composition is this file's job, which is the layering the binding rules
 * describe.
 *
 * ON THE API GDK HANDS YOU. GtkGLArea does not necessarily give desktop
 * GL. On the Pi 5 (Mesa V3D) GDK can only create a **GLES 3.1** context
 * for a GtkGLArea: asking for GDK_GL_API_GL alone leaves getContext() at
 * 0 and the render signal never fires. So this file allows both APIs and
 * picks the shader dialect from the API the context reports — the same
 * kind of capability branch on data GL just handed us that proof_headless
 * makes for its GLSL directive. ext-opengl's entry points are the common
 * subset here, and dispatch onto the GLES context unchanged; only the
 * shader source has to know which dialect it is written in.
 *
 * Needs the box's logged-in Wayland/X11 seat. Over ssh, export the seat
 * env first:
 *   XDG_RUNTIME_DIR=/run/user/1000 DISPLAY=:0 php examples/proof_glarea.php
 *
 * GL constants are inline ints with a header:line citation against
 * ext-opengl's vendored scripts/khronos/glcorearb.h, because constants
 * live in jovian/ogx and never in an extension.
 *
 * Exit codes: 0 = PROOF_GLAREA_OK, 1 = failure.
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge as GtkBridge;
use Gtk\Gdk\GdkGLContext\GdkGLContext;
use Gtk\Gtk\GtkGLArea\GtkGLArea;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

use OpenGL\Bridge\Bridge as GLBridge;
use OpenGL\GL\GL10\GL10;
use OpenGL\GL\GL11\GL11;
use OpenGL\GL\GL15\GL15;
use OpenGL\GL\GL20\GL20;
use OpenGL\GL\GL30\GL30;

/* ---- glcorearb.h (ext-opengl/scripts/khronos/glcorearb.h) ----------- */
const GL_COLOR_BUFFER_BIT = 0x00004000;          // glcorearb.h:74
const GL_TRIANGLES = 0x0004;                     // glcorearb.h:81
const GL_NO_ERROR = 0;                           // glcorearb.h:114
const GL_UNSIGNED_BYTE = 0x1401;                 // glcorearb.h:187
const GL_FLOAT = 0x1406;                         // glcorearb.h:192
const GL_RGBA = 0x1908;                          // glcorearb.h:222
const GL_RENDERER = 0x1F01;                      // glcorearb.h:231
const GL_VERSION = 0x1F02;                       // glcorearb.h:232
const GL_ARRAY_BUFFER = 0x8892;                  // glcorearb.h:606
const GL_STATIC_DRAW = 0x88E4;                   // glcorearb.h:620
const GL_FRAGMENT_SHADER = 0x8B30;               // glcorearb.h:709
const GL_VERTEX_SHADER = 0x8B31;                 // glcorearb.h:710
const GL_COMPILE_STATUS = 0x8B81;                // glcorearb.h:737
const GL_LINK_STATUS = 0x8B82;                   // glcorearb.h:738
const GL_INFO_LOG_LENGTH = 0x8B84;               // glcorearb.h:740
const GL_SHADING_LANGUAGE_VERSION = 0x8B8C;      // glcorearb.h:748

/* ---- Gdk-4.0.gir GdkGLAPI (a jovian/gtk enum; plain ints down here) - */
const GDK_GL_API_GL = 1;                         // Gdk-4.0.gir GdkGLAPI member "gl"
const GDK_GL_API_GLES = 2;                       // Gdk-4.0.gir GdkGLAPI member "gles"

const AREA_W = 320;
const AREA_H = 240;

$allocated = [];

function buffer(int $bytes): int
{
    global $allocated;

    $ptr = GLBridge::alloc($bytes);
    if ($ptr === 0) {
        fail("OpenGL Bridge::alloc({$bytes}) failed");
    }
    $allocated[] = $ptr;

    return $ptr;
}

function readInt(int $ptr, int $offset = 0): int
{
    return unpack('l', GLBridge::read($ptr, $offset, 4))[1];
}

function fail(string $why): never
{
    fwrite(STDERR, "proof_glarea: {$why}\n");
    fwrite(STDERR, "PROOF_GLAREA_FAILED\n");
    exit(1);
}

function step(string $what): void
{
    echo "  {$what}\n";
}

function compileShader(int $stage, string $source, string $label): int
{
    $shader = GL20::glCreateShader($stage);
    if ($shader === 0) {
        throw new RuntimeException("glCreateShader({$label}) returned 0");
    }

    GL20::glShaderSource($shader, 1, [$source], 0);
    GL20::glCompileShader($shader);

    $status = buffer(4);
    GL20::glGetShaderiv($shader, GL_COMPILE_STATUS, $status);
    if (readInt($status) === 1) {
        return $shader;
    }

    GL20::glGetShaderiv($shader, GL_INFO_LOG_LENGTH, $status);
    $len = max(1, readInt($status));
    $log = buffer($len);
    GL20::glGetShaderInfoLog($shader, $len, 0, $log);

    throw new RuntimeException(
        "{$label} shader did not compile:\n" . rtrim(GLBridge::read($log, 0, $len), "\0")
    );
}

// ---------------------------------------------------------------- setup

echo "proof_glarea — " . PHP_OS_FAMILY . ' / ' . php_uname('m') . "\n\n";

foreach (['gtk', 'opengl'] as $ext) {
    if (!extension_loaded($ext)) {
        fail("the {$ext} extension is not loaded");
    }
}
step('gtk ' . phpversion('gtk') . ', opengl ' . phpversion('opengl'));

if (!GtkBridge::init()) {
    fail('gtk_init_check failed — no display? Run from the logged-in seat.');
}
step('Gtk\Bridge\Bridge::init() ok');

echo "\n1. window + GtkGLArea\n";

$win = GtkWindow::new_();
GtkWindow::setTitle($win, 'gtk ' . phpversion('gtk') . ' — GtkGLArea + ext-opengl');
GtkWindow::setDefaultSize($win, AREA_W, AREA_H);

$area = GtkGLArea::new_();
if ($area === 0) {
    fail('GtkGLArea::new_() returned 0');
}

/*
 * Both APIs are allowed: GDK picks what the driver can actually give a
 * GtkGLArea, and the render handler adapts. Narrowing this to
 * GDK_GL_API_GL is what makes the Pi hand back no context at all.
 */
GtkGLArea::setAllowedApis($area, GDK_GL_API_GL | GDK_GL_API_GLES);
GtkGLArea::setAutoRender($area, true);
GtkGLArea::setHasDepthBuffer($area, false);
GtkGLArea::setHasStencilBuffer($area, false);
// 3.0 is the floor both dialects below need (VAOs, in/out shaders).
GtkGLArea::setRequiredVersion($area, 3, 0);

$required = GtkGLArea::getRequiredVersion($area);
step("GtkGLArea {$area}: allowed-apis=" . GtkGLArea::getAllowedApis($area)
    . ", required {$required['major']}.{$required['minor']}"
    . ', auto-render=' . (GtkGLArea::getAutoRender($area) ? 'true' : 'false')
    . ', depth=' . (GtkGLArea::getHasDepthBuffer($area) ? 'true' : 'false')
    . ', stencil=' . (GtkGLArea::getHasStencilBuffer($area) ? 'true' : 'false'));

GtkWidget::setHexpand($area, true);
GtkWidget::setVexpand($area, true);
GtkWindow::setChild($win, $area);

echo "\n2. render handler (the GL work happens here)\n";

$state = [
    'frames' => 0,
    'checked' => false,
    'program' => 0,
    'error' => null,
    'context' => null,
];

/*
 * The render signal returns gboolean: true stops GTK's default handling,
 * which is what a handler that has drawn the frame itself must say. The
 * gtk Bridge's closure writes a PHP return straight into the signal's
 * return GValue (phpgtk-support.c, G_TYPE_BOOLEAN), so returning true
 * here is all it takes — no Bridge change was needed for this wave.
 *
 * GTK has already made the area's GdkGLContext current and bound the
 * area's own framebuffer before emitting this, so every GL call below
 * lands on the widget's framebuffer — no FBO of our own.
 */
$render = static function (int $areaHandle, int $contextHandle) use (&$state): bool {
    if ($state['error'] !== null) {
        return true;
    }

    try {
        $state['frames']++;

        if ($state['program'] === 0) {
            // First frame: the context is current, so resolve GL now.
            if (!GLBridge::load()) {
                throw new RuntimeException('OpenGL Bridge::load() could not open an OpenGL library');
            }

            $api = GdkGLContext::getApi($contextHandle);
            $version = GdkGLContext::getVersion($contextHandle);
            $state['context'] = [
                'handle' => $contextHandle,
                'api' => $api,
                'apiName' => $api === GDK_GL_API_GLES ? 'GDK_GL_API_GLES' : 'GDK_GL_API_GL',
                'version' => "{$version['major']}.{$version['minor']}",
                'legacy' => GdkGLContext::isLegacy($contextHandle),
                'useEs' => GdkGLContext::getUseEs($contextHandle),
            ];
            if ($api !== GDK_GL_API_GL && $api !== GDK_GL_API_GLES) {
                throw new RuntimeException("GdkGLContext::getApi() = {$api}, which is neither GL nor GLES");
            }
            if ($version['major'] < 3) {
                throw new RuntimeException("this proof needs a 3.0+ context; got {$state['context']['version']}");
            }

            $glsl = (string) GL10::glGetString(GL_SHADING_LANGUAGE_VERSION);
            $state['strings'] = [
                'version' => (string) GL10::glGetString(GL_VERSION),
                'renderer' => (string) GL10::glGetString(GL_RENDERER),
                'glsl' => $glsl,
            ];

            /*
             * The shader dialect follows the API GDK reports. GLSL ES 3.00
             * is the ES floor with in/out and VAOs; on desktop the
             * directive follows the reported GLSL version exactly as
             * ext-opengl's proof_headless does.
             */
            $es = $api === GDK_GL_API_GLES;
            $directive = $es
                ? '#version 300 es'
                : (version_compare($glsl, '1.50', '<') ? '#version 140' : '#version 150 core');
            // ES has no default float precision in a fragment shader.
            $precision = $es ? "precision mediump float;\n" : '';
            $state['directive'] = $directive;

            // VAO: a core/ES3 profile has no default vertex array object.
            $vaoOut = buffer(4);
            GL30::glGenVertexArrays(1, $vaoOut);
            $vao = readInt($vaoOut);
            GL30::glBindVertexArray($vao);

            // One triangle, big enough to cover the centre pixel.
            $vertices = pack('f*', 0.0, 0.8, -0.8, -0.8, 0.8, -0.8);
            $vboOut = buffer(4);
            GL15::glGenBuffers(1, $vboOut);
            $vbo = readInt($vboOut);
            GL15::glBindBuffer(GL_ARRAY_BUFFER, $vbo);
            $vertexData = buffer(strlen($vertices));
            GLBridge::write($vertexData, 0, $vertices);
            GL15::glBufferData(GL_ARRAY_BUFFER, strlen($vertices), $vertexData, GL_STATIC_DRAW);

            $vs = compileShader(
                GL_VERTEX_SHADER,
                "{$directive}\n"
                . "in vec2 aPos;\n"
                . "void main()\n"
                . "{\n"
                . "    gl_Position = vec4(aPos, 0.0, 1.0);\n"
                . "}\n",
                'vertex'
            );

            $fs = compileShader(
                GL_FRAGMENT_SHADER,
                "{$directive}\n"
                . $precision
                . "out vec4 fragColour;\n"
                . "void main()\n"
                . "{\n"
                . "    fragColour = vec4(1.0, 0.5, 0.25, 1.0);\n"
                . "}\n",
                'fragment'
            );

            $program = GL20::glCreateProgram();
            GL20::glAttachShader($program, $vs);
            GL20::glAttachShader($program, $fs);
            // Neither GLSL 1.40 nor GLSL ES 3.00 has layout(location = ...).
            GL20::glBindAttribLocation($program, 0, 'aPos');
            GL20::glLinkProgram($program);

            $status = buffer(4);
            GL20::glGetProgramiv($program, GL_LINK_STATUS, $status);
            if (readInt($status) !== 1) {
                GL20::glGetProgramiv($program, GL_INFO_LOG_LENGTH, $status);
                $len = max(1, readInt($status));
                $log = buffer($len);
                GL20::glGetProgramInfoLog($program, $len, 0, $log);
                throw new RuntimeException(
                    "program did not link:\n" . rtrim(GLBridge::read($log, 0, $len), "\0")
                );
            }

            GL20::glUseProgram($program);
            GL20::glEnableVertexAttribArray(0);
            GL20::glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, 0);
            $state['program'] = $program;
            $state['vao'] = $vao;
        }

        // ---- draw this frame into the GLArea's own framebuffer
        $w = max(1, GtkWidget::getWidth($areaHandle));
        $h = max(1, GtkWidget::getHeight($areaHandle));

        GL20::glUseProgram($state['program']);
        GL30::glBindVertexArray($state['vao']);
        GL10::glViewport(0, 0, $w, $h);
        GL10::glClearColor(0.0, 0.0, 0.0, 1.0);
        GL10::glClear(GL_COLOR_BUFFER_BIT);
        GL11::glDrawArrays(GL_TRIANGLES, 0, 3);

        $err = GL10::glGetError();
        if ($err !== GL_NO_ERROR) {
            throw new RuntimeException(sprintf('glGetError() = 0x%X after the draw', $err));
        }

        // ---- byte-check the first rendered frame
        if (!$state['checked']) {
            GL10::glFinish();

            $pixels = buffer($w * $h * 4);
            GL10::glReadPixels(0, 0, $w, $h, GL_RGBA, GL_UNSIGNED_BYTE, $pixels);

            $centre = GLBridge::read($pixels, (intdiv($h, 2) * $w + intdiv($w, 2)) * 4, 4);
            $corner = GLBridge::read($pixels, 0, 4);
            if ($centre === null || $corner === null) {
                throw new RuntimeException('OpenGL Bridge::read of the pixel buffer returned null');
            }

            $state['centre'] = array_values(unpack('C4', $centre));
            $state['corner'] = array_values(unpack('C4', $corner));
            $state['size'] = [$w, $h];
            $state['checked'] = true;
        }
    } catch (Throwable $e) {
        $state['error'] = $e->getMessage();
    }

    // true: this handler drew the frame, GTK must not run its default.
    return true;
};

$renderId = GtkBridge::connect($area, 'render', $render);
if ($renderId === 0) {
    fail("Gtk\\Bridge\\Bridge::connect(area, 'render') returned 0");
}
step("connected render (handler {$renderId})");

$resizes = 0;
$resizeId = GtkBridge::connect($area, 'resize', static function (int $a, int $w, int $h) use (&$resizes): void {
    $resizes++;
});
step("connected resize (handler {$resizeId})");

echo "\n3. present and pump ~2s of real frames\n";

GtkWindow::present($win);

$deadline = microtime(true) + 2.0;
while (microtime(true) < $deadline) {
    GtkBridge::pump(50);
    if ($state['error'] !== null) {
        break;
    }
    GtkGLArea::queueRender($area);
}

$visible = GtkWidget::getVisible($win);
GtkWindow::close($win);
GtkBridge::pump(200);

foreach ($allocated as $ptr) {
    GLBridge::free($ptr);
}

// ---------------------------------------------------------------- verdict

echo "\n4. what happened\n";

if ($state['error'] !== null) {
    fail($state['error']);
}
if (!$visible) {
    fail('the window never became visible');
}
if ($state['frames'] === 0) {
    fail('the render signal never fired — no frames were drawn '
        . '(GtkGLArea::getContext = ' . GtkGLArea::getContext($area) . ')');
}
if (!$state['checked']) {
    fail('no frame was read back');
}

$ctx = $state['context'];
step("GdkGLContext {$ctx['handle']}: api={$ctx['api']} ({$ctx['apiName']}), version {$ctx['version']}"
    . ', legacy=' . ($ctx['legacy'] ? 'true' : 'false')
    . ', use-es=' . ($ctx['useEs'] ? 'true' : 'false'));
step("GL_VERSION                  = {$state['strings']['version']}");
step("GL_RENDERER                 = {$state['strings']['renderer']}");
step("GL_SHADING_LANGUAGE_VERSION = {$state['strings']['glsl']}");
step("shader directive            = {$state['directive']}");
step("frames rendered             = {$state['frames']} (resize fired {$resizes}x)");
step("framebuffer                 = {$state['size'][0]}x{$state['size'][1]}");

$c = $state['centre'];
$k = $state['corner'];
step(sprintf('centre RGBA = %d,%d,%d,%d', $c[0], $c[1], $c[2], $c[3]));
step(sprintf('corner RGBA = %d,%d,%d,%d', $k[0], $k[1], $k[2], $k[3]));

// The shader writes (1.0, 0.5, 0.25, 1.0); the clear is opaque black.
if ($c[0] < 240 || $c[1] < 100 || $c[1] > 155 || $c[2] < 48 || $c[2] > 80 || $c[3] !== 255) {
    fail('the centre pixel is not the shader colour');
}
if ($k[0] !== 0 || $k[1] !== 0 || $k[2] !== 0 || $k[3] !== 255) {
    fail('the corner pixel is not the clear colour');
}
step('centre is the shader colour and the corner is the clear colour');

echo "\nPROOF_GLAREA_OK\n";
exit(0);
