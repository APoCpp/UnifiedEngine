#ifndef _UNIFIED_GRAPHICS_DRAWABLE_VERTEX_ARRAY_HPP
#define _UNIFIED_GRAPHICS_DRAWABLE_VERTEX_ARRAY_HPP

# include <unified/defines.hpp>
# include <unified/graphics/buffer.hpp>
# include <unified/graphics/drawable.hpp>
# include <unified/graphics/primitive_type.hpp>
# include <unified/graphics/math/vertex_fwd.hpp>

UNIFIED_BEGIN_NAMESPACE

class RenderTarget;

class VertexArray : public Drawable
{
public:

    VertexArray(PrimitiveType type, u32 vertices_dimension, u32 vertices_count, Buffer::Usage usage = Buffer::Usage::Static);

    virtual void draw(const RenderTarget &target) const override;

    template <class _type, u32 _dimension>
    void write(Vertex<_type, _dimension> *data, u32 size) {
        _buffer.write(data, size);
    }

protected:

    Buffer _buffer;
    PrimitiveType _primitive_type;
    u32 _vertices_dimension, _vertices_count;

};

UNIFIED_END_NAMESPACE

#endif
