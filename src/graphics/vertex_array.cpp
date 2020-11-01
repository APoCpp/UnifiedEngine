#include <unified/graphics/vertex_array.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

void VertexArray::draw(RenderTarget const&) const {
    glEnableVertexAttribArray(0);

    GPUBuffer::bind((GPUBuffer*)this);
    glVertexAttribPointer(0, _vertices_dimension, GL_DOUBLE, GL_FALSE, 0, (void*)0);
    glDrawArrays((GLenum)_primitive_type, 0, _vertices_count);

    glDisableVertexAttribArray(0);
}

UNIFIED_END_NAMESPACE
