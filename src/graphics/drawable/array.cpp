#include <unified/graphics/drawable/array.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

Array::Array(PrimitiveType type, u32 vertices_dimension, u32 vertices_count, Buffer::Usage usage) :
    _buffer(usage), _primitive_type(type), _vertices_dimension(vertices_dimension), _vertices_count(vertices_count) { }

void Array::draw(RenderTarget const&) const {
    Buffer::ScopeBind bind(&_buffer);

    static Shader shader(
        #include "array.vert"
            ,
        #include "array.frag"
    );

    GLint buffer_size = _buffer.size();

    glVertexAttribPointer(0, _vertices_dimension, GL_DOUBLE, GL_FALSE,
        buffer_size / _vertices_count, (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE,
        buffer_size / _vertices_count, (void*)(sizeof(double) * _vertices_dimension));
    glEnableVertexAttribArray(1);

    Shader::bind(&shader);
    glDrawArrays((GLenum)_primitive_type, 0, _vertices_count);
    Shader::bind(0);

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
