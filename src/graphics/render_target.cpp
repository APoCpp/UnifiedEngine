#include <unified/graphics/render_target.hpp>
#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

RenderTarget::RenderTarget() {
    if (!gladLoadGL())
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize glad");
}

void RenderTarget::clear(Color const &color) {
    glClearColor(color.r / 255.f, color.g / 255.f, color.b / 255.f, color.a / 255.f);
    glClear(GL_COLOR_BUFFER_BIT);
}

void RenderTarget::draw(const Drawable &object) const {
    object.draw(*this);
}

UNIFIED_END_NAMESPACE
