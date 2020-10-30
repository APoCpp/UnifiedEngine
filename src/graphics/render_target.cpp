#include <unified/graphics/render_target.hpp>
#include <unified/core/exceptions.hpp>

#include <unified/graphics/gpu_buffer.hpp>
#include <unified/graphics/drawable.hpp>

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

void RenderTarget::push_gl_states() _OSL_NOEXCEPT { }

void RenderTarget::pop_gl_states() _OSL_NOEXCEPT { }

void RenderTarget::reset_gl_states() _OSL_NOEXCEPT { }

void RenderTarget::draw(Drawable const &drawable) const {
    drawable.draw(*this);
}

UNIFIED_END_NAMESPACE
