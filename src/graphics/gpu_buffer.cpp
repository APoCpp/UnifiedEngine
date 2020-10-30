#include <unified/graphics/gpu_buffer.hpp>

#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

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

GPUBuffer::GPUBuffer(Usage usage) : _usage(usage), _buffer(0), _size(0) {
    if (!_buffer)
        glGenBuffers(1, &_buffer);

    if (!_buffer)
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize GPU buffer");
}

GPUBuffer::~GPUBuffer() _OSL_NOEXCEPT {
    glDeleteBuffers(1, &_buffer);
}

void GPUBuffer::write(void const *data, u32 size) {
    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ARRAY_BUFFER, _size = size, data, usage_to_glenum(_usage));
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

_OSL_NODISCARD GPUBuffer::HandleType GPUBuffer::get_handle() const _OSL_NOEXCEPT {
    return _buffer;
}

void GPUBuffer::set_usage(Usage usage) _OSL_NOEXCEPT {
    _usage = usage;
}

_OSL_NODISCARD GPUBuffer::Usage GPUBuffer::get_usage() const _OSL_NOEXCEPT {
    return _usage;
}

void GPUBuffer::bind(GPUBuffer const *buffer) _OSL_NOEXCEPT {
    glBindBuffer(GL_ARRAY_BUFFER, buffer ? buffer->get_handle() : 0);
}

UNIFIED_END_NAMESPACE
