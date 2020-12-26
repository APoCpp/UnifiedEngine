#ifndef _UNIFIED_GRAPHICS_2D_DRAWABLE_VERTEX_ARRAY_HPP
#define _UNIFIED_GRAPHICS_2D_DRAWABLE_VERTEX_ARRAY_HPP

# include <unified/graphics/drawable.hpp>
# include <unified/graphics/primitive_type.hpp>

# include <unified/graphics/buffer.hpp>

# include <unified/graphics/2d/vertex.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

class VertexArray : public Graphics::Drawable
{
public:

    VertexArray(Graphics::PrimitiveType type, u32 vertices_count, Graphics::Buffer::Usage usage = Graphics::Buffer::Usage::Static);

    virtual ~VertexArray() { }

    virtual void draw(const Graphics::RenderTarget &target) const override;

    template <class _type>
    void write(Graphics::Vertex<_type, 2> vertex) {
        _buffer.allocate(sizeof(vertex)), _buffer.write((void*)&vertex, sizeof(vertex));
    }

    template <class _type>
    void write(Graphics::Vertex<_type, 2> *data, u32 size) {
        _buffer.allocate(size), _buffer.write((void*)data, size);
    }

    template <class _type>
    void read(Graphics::Vertex<_type, 2> *data, u32 size, u32 offset = 0) {
        _buffer.read(data, size, offset);
    }

    u32 size() const {
        return _buffer.size();
    }

protected:

    Graphics::Buffer _buffer;

    Graphics::PrimitiveType _primitive_type;
    u32 _vertices_count;

};

UNIFIED_GRAPHICS_2D_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
