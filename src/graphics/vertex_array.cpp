#include <unified/graphics/vertex_array.hpp>
#include <unified/core/color.hpp>
#include <glad/glad.h>

#include <unified/graphics/math/vertex2.hpp>
#include <unified/graphics/math/vertex3.hpp>

UNIFIED_BEGIN_NAMESPACE

VertexArray::VertexArray(PrimitiveType type, u32 vertices_dimension, u32 vertices_count, GPUBuffer::Usage usage) :
    buffer(usage), _primitive_type(type), _vertices_dimension(vertices_dimension), _vertices_count(vertices_count) { }

void VertexArray::draw(RenderTarget const&) const {

    // @note: it hurts me to look at this...
    static Shader shader(
        #include <unified/shaders/vertex_array/vertex_array.vert>
                ,
        #include <unified/shaders/vertex_array/vertex_array.frag>
    );

    GPUBuffer::bind(&this->buffer);

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

    GPUBuffer::bind(0);
}

UNIFIED_END_NAMESPACE
