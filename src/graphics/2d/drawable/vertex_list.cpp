#include <unified/graphics/2d/drawable/vertex_list.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

using namespace Unified::Graphics;

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

VertexList::VertexList(PrimitiveType type, Buffer::Usage usage) :
    _buffer(usage), _primitive_type(type), _vertices_count(0) {
}

void VertexList::draw(const RenderTarget&) const {
    if (!_vertices_count)
        return;

    GLint buffer_size = static_cast<u32>(_buffer.size());

    glVertexAttribPointer(0, 2, GL_DOUBLE, GL_FALSE,
        buffer_size / _vertices_count, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
        buffer_size / _vertices_count, (void*)(sizeof(Point2d)));
    glEnableVertexAttribArray(1);

    static Shader shader(
        #include "vertex_color.vert"
            ,
        #include "vertex_color.frag"
    );

    Shader::ScopeBind shader_bind(&shader);

    glDrawArrays(static_cast<GLenum>(_primitive_type), 0, _vertices_count);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE
