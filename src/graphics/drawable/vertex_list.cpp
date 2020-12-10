#include <unified/graphics/drawable/vertex_list.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

VertexList::VertexList(PrimitiveType type, u32 vertices_dimension, Buffer::Usage usage) :
    _buffer(usage), _primitive_type(type), _vertices_dimension(vertices_dimension), _vertices_count(0) { }

void VertexList::draw(RenderTarget const&) const {
    if (!_vertices_count)
        return;

    Buffer::ScopeBind bind(&_buffer);

    static Shader shader(
        #include "vertex_array.vert"
            ,
        #include "vertex_array.frag"
    );

    GLint buffer_size = static_cast<u32>(_buffer.size());

    glVertexAttribPointer(0, _vertices_dimension, GL_DOUBLE, GL_FALSE,
        buffer_size / _vertices_count, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
        buffer_size / _vertices_count, (void*)(sizeof(double) * _vertices_dimension));
    glEnableVertexAttribArray(1);

    Shader::bind(&shader);
    glDrawArrays((GLenum)_primitive_type, 0, _vertices_count);
    Shader::unbind();

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
