#include <unified/graphics/drawable/vertex_array.hpp>
#include <unified/graphics/shader.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

VertexArray::VertexArray(PrimitiveType type, u32 vertices_dimension, u32 vertices_count, Buffer::Usage usage) :
    _buffer(usage), _primitive_type(type), _vertices_dimension(vertices_dimension), _vertices_count(vertices_count) { }

void VertexArray::draw(RenderTarget const&) const {
    Buffer::bind(&_buffer);

    static Shader shader(
        #include "vertex_array.vert"
            ,
        #include "vertex_array.frag"
    );

    GLint buffer_size = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &buffer_size);

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

    Buffer::bind(0);
}

UNIFIED_END_NAMESPACE
