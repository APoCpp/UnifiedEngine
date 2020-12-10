#include <unified/graphics/buffer.hpp>
#include <unified/core/exceptions.hpp>
#include <glad/glad.h>

namespace
{
    UNIFIED_CONSTEXPR GLenum usage_to_glenum(UNIFIED_NAMESPACE::Graphics::Buffer::Usage usage) {
        switch (usage) {
            case UNIFIED_NAMESPACE::UNIFIED_GRAPHICS_NAMESPACE::Buffer::Usage::Static:  return GL_STATIC_DRAW;
            case UNIFIED_NAMESPACE::UNIFIED_GRAPHICS_NAMESPACE::Buffer::Usage::Dynamic: return GL_DYNAMIC_DRAW;
            default: return GL_STREAM_DRAW;
        }
    }
}

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_BEGIN_NAMESPACE

Buffer::Buffer(Usage usage) : _usage(usage) {
    glGenBuffers(1, &_id);
    if (!_id)
        throw Exceptions::initialization_failed("failed to initialize the graphics buffer");
}

Buffer::~Buffer() {
    glDeleteBuffers(1, &_id);
}

void Buffer::allocate(u32 size) {
    ScopeBind bind(this);
    glBufferData(GL_ARRAY_BUFFER, size, 0, usage_to_glenum(_usage));
}

void Buffer::reallocate(u32 size) {
    ScopeBind bind(this);

    u32 old_size = this->size();

    if (old_size == 0)
        throw Exceptions::misbehavior("impossible to reallocate memory. memory not allocated");

    if (old_size > size)
        throw Exceptions::misbehavior("impossible to reallocate less memory than already allocated. possible data loss");

    s8 *old_data = new s8[old_size];
    glGetBufferSubData(GL_ARRAY_BUFFER, 0, old_size, (void*)old_data);
    glBufferData(GL_ARRAY_BUFFER, size, (void*)old_data, usage_to_glenum(_usage));
    delete[] old_data;

    return;
}

void Buffer::write(const void *data, u32 size, u32 offset) {
    ScopeBind bind(this);
    glBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

void Buffer::read(void *data, u32 size, u32 offset) {
    ScopeBind bind(this);
    glGetBufferSubData(GL_ARRAY_BUFFER, offset, size, data);
}

UNIFIED_NODISCARD Buffer::HandleType Buffer::handle() const{
    return _id;
}

void Buffer::set_usage(Usage usage) {
    _usage = usage;
}

UNIFIED_NODISCARD Buffer::Usage Buffer::usage() const {
    return _usage;
}

UNIFIED_NODISCARD u32 Buffer::size() const {
    ScopeBind bind(this);

    GLint result = 0;
    glGetBufferParameteriv(GL_ARRAY_BUFFER, GL_BUFFER_SIZE, &result);

    return static_cast<u32>(result);
}

void Buffer::bind(const Buffer *buffer) {
    if (!buffer)
        throw Exceptions::misbehavior("bad " UNIFIED_GRAPHICS_NAMESPACE_STRING "::Buffer pointer");

    glBindBuffer(GL_ARRAY_BUFFER, buffer->handle());
}

void Buffer::unbind() {
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

Buffer::ScopeBind *Buffer::ScopeBind::current = 0;

Buffer::ScopeBind::ScopeBind(const Buffer *buffer) {
    if (current && current->binded() != buffer->handle()) {
        _binded = 0;
        return;
    }

    _prev = current;
    _binded = buffer->handle();
    glBindBuffer(GL_ARRAY_BUFFER, _binded), current = this;
}

Buffer::ScopeBind::~ScopeBind() {
    if (_binded) {
        if (_prev) {
            glBindBuffer(GL_ARRAY_BUFFER, _prev->_binded), current = _prev;
            return;
        }
        glBindBuffer(GL_ARRAY_BUFFER, 0), current = 0;
    }
}

Buffer::HandleType Buffer::ScopeBind::binded() const {
    return _binded;
}

UNIFIED_GRAPHICS_END_NAMESPACE
UNIFIED_END_NAMESPACE
