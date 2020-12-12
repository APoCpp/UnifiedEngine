#include <unified/graphics/2d/drawable/vertex_array.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

using namespace Unified::Graphics;

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

VertexArray::VertexArray(PrimitiveType type, u32 vertices_count, Buffer::Usage usage) :
    _buffer(usage), _primitive_type(type), _vertices_count(vertices_count) {
}

void VertexArray::draw(const RenderTarget&) const {
    Buffer::ScopeBind buffer_bind(&_buffer);

    static Shader shader(
        #include "vertex_color.vert"
            ,
        #include "vertex_color.frag"
    );

    GLint buffer_size = _buffer.size();

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / _vertices_count, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
        buffer_size / _vertices_count, (void*)(sizeof(double) * 2));
    glEnableVertexAttribArray(1);

    Shader::ScopeBind shader_bind(&shader);
    glDrawArrays(static_cast<GLenum>(_primitive_type), 0, _vertices_count);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
