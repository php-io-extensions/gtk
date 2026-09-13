---
type: Trap
title: A GtkGLArea on the Pi only gets a GLES context
description: Restricting GtkGLArea to GDK_GL_API_GL on the Pi 5 leaves getContext() at 0 and the render signal never fires — GDK can only create GLES there. Allow both APIs and branch the shader dialect on the API the context reports.
tags: [trap, gtkglarea, gdkglcontext, opengl, gles, pi]
status: draft
generated: { by: claude-fable-5.1/claude-code, at: 2026-09-13T17:40:00Z }
sources:
  - id: area
    resource: "../../src/gtk-gl-area.c"
    title: phpgtk_gtkglarea_set_allowed_apis
  - id: proof
    resource: "../../examples/proof_glarea.php"
    title: the render handler's dialect branch
---

Measured on the Pi 5 seat (Debian 13 trixie, GTK 4.18.6, Mesa 26.2.0, V3D
7.1.7.0), not inferred. Found while writing `examples/proof_glarea.php`:
the first version restricted the area to desktop GL and the proof failed
with "the render signal never fired".

# The behaviour

`gtk_gl_area_set_allowed_apis()` is a *constraint*, not a preference. If
GDK cannot create a context within it, GtkGLArea does not fall back — it
stores a `GError` and simply never emits `render`. Measured, with the area
realized and mapped at 320x240 in all three cases:

| allowed-apis | `GtkGLArea::getContext` | `GdkGLContext::getApi` | render fired |
|---|---|---|---|
| unrestricted | non-zero | 2 (GLES), version 3.1 | 80 frames / 1.5s |
| `GDK_GL_API_GL` (1) | **0** | — | **0** |
| `GDK_GL_API_GLES` (2) | non-zero | 2 (GLES), version 3.1 | 92 frames / 1.5s |

So on this box GDK can only back a GtkGLArea with **GLES 3.1**
(`OpenGL ES GLSL ES 3.10`), even though the same hardware gives a desktop
**GL 3.1** core context through surfaceless EGL — which is exactly what
ext-opengl's `examples/proof_headless.php` uses. The windowed path and the
headless path genuinely differ in API on the same driver; do not carry an
assumption from one into the other.

Note this is *not* the `use-es` property misfiring: `GdkGLContext::getUseEs`
reports true because the context really is ES, and `isLegacy` is false.

# Why the failure looks like a binding bug and is not

`GtkGLArea::getContext` returning 0, no `render`, and no PHP-visible error
together look like a broken signal connection. The actual diagnosis lives
in `gtk_gl_area_get_error`, which is **`@reserved`** in this extension
(`GError*` return — the translation table does not carry GErrors). There is
therefore no PHP-side way to read the reason. When a GLArea silently draws
nothing, check `getContext()` first: 0 means context creation failed, and
the allowed-apis constraint is the first thing to widen.

# What to do

Allow both APIs and let the *caller* branch on what it gets — the 1:1 layer
must not pick a dialect:

```php
GtkGLArea::setAllowedApis($area, GDK_GL_API_GL | GDK_GL_API_GLES); // 1 | 2

// …inside the render handler, where the context is current:
$es = GdkGLContext::getApi($contextHandle) === GDK_GL_API_GLES;
$directive = $es ? '#version 300 es' : '#version 140';
$precision = $es ? "precision mediump float;\n" : ''; // ES has no default
```

Only the **shader source** has to know. Every ext-opengl entry point this
proof uses — `glGenVertexArrays`, `glBindBuffer`, `glBufferData`,
`glCreateShader`, `glLinkProgram`, `glVertexAttribPointer`, `glClear`,
`glDrawArrays`, `glReadPixels`, `glGetString`, `glFinish` — is in the
common subset of desktop GL 3.x and GLES 3.x, and dispatches onto GDK's
GLES context unchanged through libglvnd. The byte-check comes back
identical on both paths (`255,128,64,255` centre, `0,0,0,255` corner).

Consequences for the layers above: **jovian/ogx must not assume desktop
GL** when the surface it is drawing into came from a GtkGLArea, and
anything that picks GLSL for a windowed surface has to read
`GdkGLContext::getApi` (or `GL_SHADING_LANGUAGE_VERSION`) first. GLSL ES
3.00 is the ES floor that still has `in`/`out` and VAOs, so it is the right
default there; `#version 310 es` is available on this box but buys nothing
for a triangle.
