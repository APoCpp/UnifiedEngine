#ifndef UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP
#define UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP

#include <unified/graphics/drawable.hpp>
#include <unified/graphics/gpu_buffer.hpp>

#include <unified/graphics/primitive_type.hpp>

UNIFIED_BEGIN_NAMESPACE

class VertexArray : public GPUBuffer, public Drawable
{
public:

    VertexArray(Usage usage, PrimitiveType type, u32 vertices_dimension, u32 vertices_count) :
        GPUBuffer(usage), _primitive_type(type), _vertices_dimension(vertices_dimension), _vertices_count(vertices_count) { }

    virtual void draw(RenderTarget const &target) const override;

protected:

    PrimitiveType _primitive_type;
    u32 _vertices_dimension, _vertices_count;

};

UNIFIED_END_NAMESPACE

#endif
