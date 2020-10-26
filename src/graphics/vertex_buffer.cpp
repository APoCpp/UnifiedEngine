#include <unified/graphics/vertex_buffer.hpp>
#include <glad/glad.h>

#include <unified/core/exceptions.hpp>
#include <unified/core/debug/assert.hpp>

namespace
{
    _OSL_CONSTEXPR GLenum usage_to_glenum(UNIFIED_NAMESPACE::VertexBuffer::Usage usage) {
        switch (usage) {
        case UNIFIED_NAMESPACE::VertexBuffer::Usage::Static: return GL_STATIC_DRAW;
        case UNIFIED_NAMESPACE::VertexBuffer::Usage::Dynamic: return GL_DYNAMIC_DRAW;
        default: return GL_STREAM_DRAW;
        }
    }
}

UNIFIED_BEGIN_NAMESPACE

VertexBuffer::VertexBuffer() _OSL_NOEXCEPT : _buffer(0), _vertex_count(0), _primitive_type(PrimitiveType::Points), _usage(Usage::Stream) { }

VertexBuffer::VertexBuffer(Usage usage) _OSL_NOEXCEPT : _buffer(0), _vertex_count(0), _primitive_type(PrimitiveType::Points), _usage(usage) { }
VertexBuffer::VertexBuffer(PrimitiveType type) _OSL_NOEXCEPT : _buffer(0), _vertex_count(0), _primitive_type(type), _usage(Usage::Stream) { }
VertexBuffer::VertexBuffer(PrimitiveType type, Usage usage) _OSL_NOEXCEPT : _buffer(0), _vertex_count(0), _primitive_type(type), _usage(usage) { }

bool VertexBuffer::create(u32 vertex_count) {
    if (!_buffer)
        glGenBuffers(1, &_buffer);

    if (!_buffer) {
        throw EXCEPTION_INITIALIZATION_FAILED("vertex buffer");
    }

    glBindBuffer(GL_ARRAY_BUFFER, _buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * (_vertex_count = vertex_count), 0, usage_to_glenum(_usage));
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return true;
}

bool VertexBuffer::update(Vertex const *vertices) _OSL_NOEXCEPT {
    return update(vertices, _vertex_count, 0);
}

bool VertexBuffer::update(Vertex const *vertices, u32 vertex_count, ui32 offset) _OSL_NOEXCEPT {
    if (!_buffer)
        return false;

    if (!vertices)
        return false;

    if (offset && (offset + vertex_count > _vertex_count))
        return false;

    glBindBuffer(GL_ARRAY_BUFFER, _buffer);

    if (vertex_count >= _vertex_count) {
        glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertex_count, 0, usage_to_glenum(_usage));
        _vertex_count = vertex_count;
    }

    glBufferSubData(GL_ARRAY_BUFFER, sizeof(Vertex) * offset, sizeof(Vertex) * vertex_count, vertices);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    return true;
}

bool VertexBuffer::update(VertexBuffer const &vertex_buffer) _OSL_NOEXCEPT {
    if (!_buffer || !vertex_buffer.get_handle())
        return false;

    glBindBuffer(GL_COPY_READ_BUFFER, vertex_buffer.get_handle());
    glBindBuffer(GL_COPY_WRITE_BUFFER, _buffer);

    glCopyBufferSubData(GL_COPY_READ_BUFFER, GL_COPY_WRITE_BUFFER, 0, 0, sizeof(Vertex) * vertex_buffer.get_vertex_count());

    glBindBuffer(GL_COPY_WRITE_BUFFER, 0);
    glBindBuffer(GL_COPY_READ_BUFFER, 0);

    return true;
}

_OSL_NODISCARD VertexBuffer::HandleType VertexBuffer::get_handle() const _OSL_NOEXCEPT {
    return _buffer;
}

_OSL_NODISCARD u32 VertexBuffer::get_vertex_count() const _OSL_NOEXCEPT {
    return _vertex_count;
}

void VertexBuffer::set_primitive_type(PrimitiveType type) _OSL_NOEXCEPT {
    _primitive_type = type;
}

_OSL_NODISCARD PrimitiveType VertexBuffer::get_primitive_type() const _OSL_NOEXCEPT {
    return _primitive_type;
}

void VertexBuffer::set_usage(Usage usage) _OSL_NOEXCEPT {
    _usage = usage;
}

_OSL_NODISCARD VertexBuffer::Usage VertexBuffer::get_usage() const _OSL_NOEXCEPT {
    return _usage;
}

void VertexBuffer::bind(VertexBuffer const *vertex_buffer) _OSL_NOEXCEPT {
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer ? vertex_buffer->get_handle() : 0);
}

UNIFIED_END_NAMESPACE
