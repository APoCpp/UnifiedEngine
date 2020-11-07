#ifndef UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP
#define UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP

#include <unified/graphics/drawable.hpp>

#include <unified/graphics/gpu_buffer.hpp>
#include <unified/graphics/shader.hpp>

#include <unified/graphics/math/vertex_fwd.hpp>
#include <unified/graphics/primitive_type.hpp>

UNIFIED_BEGIN_NAMESPACE

class VertexArray : public Drawable
{
public:

    VertexArray(PrimitiveType type, u32 vertices_dimension, u32 vertices_count, GPUBuffer::Usage usage = GPUBuffer::Usage::Static);

    virtual ~VertexArray() _UNIFIED_NOEXCEPT = default;

    virtual void draw(RenderTarget const &target) const override;

    template <u32 _dimension>
    void write(Vertex<double, _dimension> const *data, u32 size) _UNIFIED_NOEXCEPT {
        buffer.write((void*)data, size);
    }

protected:

    GPUBuffer buffer;
    PrimitiveType _primitive_type;
    u32 _vertices_dimension, _vertices_count;

};

UNIFIED_END_NAMESPACE

#endif
