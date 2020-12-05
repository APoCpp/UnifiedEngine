#include <unified/graphics/buffer.hpp>
#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

namespace
{
    UNIFIED_CONSTEXPR GLenum usage_to_glenum(UNIFIED_NAMESPACE::Buffer::Usage usage) {
        switch (usage) {
            case UNIFIED_NAMESPACE::Buffer::Usage::Static:  return GL_STATIC_DRAW;
            case UNIFIED_NAMESPACE::Buffer::Usage::Dynamic: return GL_DYNAMIC_DRAW;
            default: return GL_STREAM_DRAW;
        }
    }
}

UNIFIED_BEGIN_NAMESPACE

Buffer::Buffer(Usage usage) : _usage(usage) {
    glGenBuffers(1, &_id);

    if (!_id)
        throw EXCEPTION_INITIALIZATION_FAILED("failed to initialize the graphics buffer");
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &_id);
}

void Buffer::allocate(u32 size) {
    bind(this);
    glBufferData(GL_ARRAY_BUFFER, size, (void*)0, usage_to_glenum(_usage));
    bind(0);
}

void Buffer::write(const void *data, u32 size) {
    bind(this);
    glBufferData(GL_ARRAY_BUFFER, size, data, usage_to_glenum(_usage));
    bind(0);
}

UNIFIED_NODISCARD Buffer::HandleType Buffer::get_handle() const{
    return _id;
}

void Buffer::set_usage(Usage usage) {
    _usage = usage;
}

UNIFIED_NODISCARD Buffer::Usage Buffer::get_usage() const {
    return _usage;
}

UNIFIED_NODISCARD u32 Buffer::get_size() const {
    bind(this);
    GLint result = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &result);
    bind(0);
    return (u32)result;
}

void Buffer::bind(const Buffer *buffer) {
    glBindBuffer(GL_ARRAY_BUFFER, buffer ? buffer->get_handle() : 0);
}

UNIFIED_END_NAMESPACE
