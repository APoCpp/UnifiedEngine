#include <unified/graphics/vertex_array.hpp>
#include <unified/core/color.hpp>
#include <glad/glad.h>

#include <unified/graphics/math/vertex2.hpp>
#include <unified/graphics/math/vertex3.hpp>


namespace
{
    _OSL_CONSTEXPR GLenum usage_to_glenum(UNIFIED_NAMESPACE::GPUBuffer::Usage usage) {
        switch (usage) {
            case UNIFIED_NAMESPACE::GPUBuffer::Usage::Static: return GL_STATIC_DRAW;
            case UNIFIED_NAMESPACE::GPUBuffer::Usage::Dynamic: return GL_DYNAMIC_DRAW;
            default: return GL_STREAM_DRAW;
        }
    }
}

UNIFIED_BEGIN_NAMESPACE

void VertexArray::draw(RenderTarget const&) const {
    GPUBuffer::bind((GPUBuffer*)this);

    int buffer_size = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &buffer_size);
    glVertexAttribPointer(0, _vertices_dimension, GL_DOUBLE, GL_FALSE,
        buffer_size / _vertices_count, (void*)0);

    glEnableVertexAttribArray(0);
    glDrawArrays((GLenum)_primitive_type, 0, _vertices_count);
    glDisableVertexAttribArray(0);
}

void VertexArray::write(void const *data, u32 size) _OSL_NOEXCEPT {
    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ARRAY_BUFFER, _size = size, data, usage_to_glenum(_usage));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

UNIFIED_END_NAMESPACE
