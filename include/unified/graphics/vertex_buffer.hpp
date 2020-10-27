#ifndef UNIFIED_GRAPHICS_VERTEX_BUFFER_HPP
#define UNIFIED_GRAPHICS_VERTEX_BUFFER_HPP

#include <unified/defines.hpp>
#include <unified/core/int_types.hpp>
#include <unified/graphics/primitive_type.hpp>

#include <unified/graphics/vertex.hpp>

UNIFIED_BEGIN_NAMESPACE

class VertexBuffer
{
public:

    using HandleType = ui32;

    enum Usage
    {
        Stream,
        Dynamic,
        Static
    };

    VertexBuffer() _OSL_NOEXCEPT;

    VertexBuffer(Usage usage) _OSL_NOEXCEPT;
    VertexBuffer(PrimitiveType type) _OSL_NOEXCEPT;
    VertexBuffer(PrimitiveType type, Usage usage) _OSL_NOEXCEPT;

    virtual ~VertexBuffer() _OSL_NOEXCEPT = default;

    bool create(u32 vertex_count);

    bool update(Vertex const *vertices) _OSL_NOEXCEPT;
    bool update(Vertex const *vertices, u32 vertex_count, ui32 offset) _OSL_NOEXCEPT;
    bool update(VertexBuffer const &vertex_buffer) _OSL_NOEXCEPT;

    _OSL_NODISCARD HandleType get_handle() const _OSL_NOEXCEPT;
    _OSL_NODISCARD u32 get_vertex_count() const _OSL_NOEXCEPT;

    void set_primitive_type(PrimitiveType type) _OSL_NOEXCEPT;
    _OSL_NODISCARD PrimitiveType get_primitive_type() const _OSL_NOEXCEPT;

    void set_usage(Usage usage) _OSL_NOEXCEPT;
    _OSL_NODISCARD Usage get_usage() const _OSL_NOEXCEPT;

    static void bind(VertexBuffer const *vertex_buffer) _OSL_NOEXCEPT;

protected:

    HandleType _buffer;
    u32 _vertex_count;
    PrimitiveType _primitive_type;
    Usage _usage;

};

UNIFIED_END_NAMESPACE

#endif
