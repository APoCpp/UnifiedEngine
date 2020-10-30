#ifndef UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP
#define UNIFIED_GRAPHICS_VERTEX_ARRAY_HPP

#include <unified/graphics/drawable.hpp>
#include <unified/graphics/gpu_buffer.hpp>

UNIFIED_BEGIN_NAMESPACE

class VertexArray : public GPUBuffer, public Drawable
{
public:

    VertexArray(Usage usage, u32 vertex_dimension, u32 vertex_count);

    virtual void draw(RenderTarget const &target) const override;

protected:

    u32 _vertex_dimension, _vertex_count;

};

UNIFIED_END_NAMESPACE

#endif
