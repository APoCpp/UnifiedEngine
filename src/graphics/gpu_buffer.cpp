#include <unified/graphics/gpu_buffer.hpp>

#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

namespace
{
    _UNIFIED_CONSTEXPR GLenum usage_to_glenum(UNIFIED_NAMESPACE::GPUBuffer::Usage usage) {
        switch (usage) {
            case UNIFIED_NAMESPACE::GPUBuffer::Usage::Static: return GL_STATIC_DRAW;
            case UNIFIED_NAMESPACE::GPUBuffer::Usage::Dynamic: return GL_DYNAMIC_DRAW;
            default: return GL_STREAM_DRAW;
        }
    }
}

UNIFIED_BEGIN_NAMESPACE

GPUBuffer::GPUBuffer(Usage usage) : _usage(usage), _id(0), _size(0) {
    if (!_id)
        glGenBuffers(1, &_id);

    if (!_id)
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize GPU buffer");
}

GPUBuffer::~GPUBuffer() _UNIFIED_NOEXCEPT {
    glDeleteBuffers(1, &_id);
}

void GPUBuffer::write(void const *data, u32 size) _UNIFIED_NOEXCEPT {
    glBindBuffer(GL_ARRAY_BUFFER, _id);
    glBufferData(GL_ARRAY_BUFFER, _size = size, data, usage_to_glenum(_usage));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

_UNIFIED_NODISCARD GPUBuffer::HandleType GPUBuffer::get_handle() const _UNIFIED_NOEXCEPT {
    return _id;
}

void GPUBuffer::set_usage(Usage usage) _UNIFIED_NOEXCEPT {
    _usage = usage;
}

_UNIFIED_NODISCARD GPUBuffer::Usage GPUBuffer::get_usage() const _UNIFIED_NOEXCEPT {
    return _usage;
}

void GPUBuffer::bind(GPUBuffer const *buffer) _UNIFIED_NOEXCEPT {
    glBindBuffer(GL_ARRAY_BUFFER, buffer ? buffer->get_handle() : 0);
}

UNIFIED_END_NAMESPACE
