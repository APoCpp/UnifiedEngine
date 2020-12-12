#ifndef _UNIFIED_GRAPHICS_2D_DRAWABLE_VERTEX_LIST_HPP
#define _UNIFIED_GRAPHICS_2D_DRAWABLE_VERTEX_LIST_HPP

# include <unified/graphics/drawable.hpp>
# include <unified/graphics/primitive_type.hpp>

# include <unified/graphics/shader.hpp>
# include <unified/graphics/buffer.hpp>

# include <unified/graphics/2d/vertex.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_2D_BEGIN_NAMESPACE

class VertexList : public Graphics::Drawable
{
public:

    VertexList(Graphics::PrimitiveType type, Graphics::Buffer::Usage usage = Graphics::Buffer::Usage::Static);

    virtual ~VertexList() = default;

    virtual void draw(const Graphics::RenderTarget &target) const override;

    template <class _type>
    void add(Graphics::Vertex<_type, 2> vertex) {
        u32 old_size = _buffer.size();

        if (old_size == 0)
            _buffer.allocate(sizeof(vertex));
        else
            _buffer.reallocate(old_size + sizeof(vertex));

        _buffer.write((void*)&vertex, sizeof(vertex), old_size);

        _vertices_count++;
    }

    template <class _type>
    void add(Graphics::Vertex<_type, 2> *data, u32 size) {
        u32 old_size = _buffer.size();

        if (old_size == 0)
            _buffer.allocate(size);
        else
            _buffer.reallocate(old_size + size);

        _buffer.write((void*)data, size, old_size);

        _vertices_count++;
    }

    template <class _type>
    void read(Graphics::Vertex<_type, 2> *data, u32 size, u32 offset = 0) {
        _buffer.read(data, size, offset);
    }

    u32 size() {
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
