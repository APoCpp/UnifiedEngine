#include <unified/graphics/vertex_array.hpp>
#include <glad/glad.h>

UNIFIED_BEGIN_NAMESPACE

VertexArray::VertexArray(Usage usage, u32 vertex_dimension, u32 vertex_count) : GPUBuffer(usage), _vertex_dimension(vertex_dimension), _vertex_count(vertex_count) { }

void VertexArray::draw(RenderTarget const &) const {
    GPUBuffer::bind((GPUBuffer*)this);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, _vertex_dimension, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glDrawArrays(GL_TRIANGLES, 0, _vertex_count);
    glDisableVertexAttribArray(0);
}

UNIFIED_END_NAMESPACE
