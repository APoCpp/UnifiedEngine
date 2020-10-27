#include <unified/graphics/render_target.hpp>
#include <unified/core/exceptions.hpp>

#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

RenderTarget::RenderTarget() {
    if (!gladLoadGL()) {
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize glad");
    }
}

void RenderTarget::clear(Color const &color) _OSL_NOEXCEPT {
    glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderTarget::push_gl_states() _OSL_NOEXCEPT {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glMatrixMode(GL_PROJECTION);
    glPushMatrix();
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
}

void RenderTarget::pop_gl_states() _OSL_NOEXCEPT {
    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_PROJECTION);
    glPopMatrix();
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();
}

void RenderTarget::reset_gl_states() _OSL_NOEXCEPT {
    glDisable(GL_CULL_FACE);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_BLEND);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
}

UNIFIED_END_NAMESPACE
