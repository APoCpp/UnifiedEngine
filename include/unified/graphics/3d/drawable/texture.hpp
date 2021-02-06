#ifndef _UNIFIED_GRAPHICS_3D_DRAWABLE_TEXTURE_HPP
#define _UNIFIED_GRAPHICS_3D_DRAWABLE_TEXTURE_HPP

# include <unified/graphics/drawable.hpp>
# include <unified/graphics/primitive_type.hpp>

# include <unified/graphics/buffer.hpp>
# include <unified/graphics/texture.hpp>
# include <unified/graphics/3d/vertex.hpp>

UNIFIED_BEGIN_NAMESPACE
UNIFIED_GRAPHICS_3D_BEGIN_NAMESPACE

class Texture : public Graphics::Texture, public Graphics::Drawable
{
public:

    Texture(string texture, bool flip = false, Graphics::Buffer::Usage usage = Graphics::Buffer::Usage::Static);

    virtual void draw(const Graphics::RenderTarget &target, const Graphics::Shader *shader = 0) const override;

    template <class _type>
    void write(Graphics::Vertex<_type, 3> vertex) {
        _buffer.allocate(sizeof(vertex)), _buffer.write((void*)&vertex, sizeof(vertex));
    }

    template <class _type>
    void write(Graphics::Vertex<_type, 3> *data, u32 size) {
        _buffer.allocate(size), _buffer.write((void*)data, size);
    }

    template <class _type>
    void read(Graphics::Vertex<_type, 3> *data, u32 size, u32 offset = 0) {
        _buffer.read(data, size, offset);
    }

    u32 size() const {
        return _buffer.size();
    }

protected:

    Graphics::Buffer _buffer;

};

UNIFIED_GRAPHICS_3D_END_NAMESPACE
UNIFIED_END_NAMESPACE

#endif
