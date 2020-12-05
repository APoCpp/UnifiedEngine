#ifndef _UNIFIED_GRAPHICS_DRAWABLE_CONVEX_SHAPE_HPP
#define _UNIFIED_GRAPHICS_DRAWABLE_CONVEX_SHAPE_HPP

# include <unified/graphics/drawable/vertex_array.hpp>

UNIFIED_BEGIN_NAMESPACE

class RenderTarget;

class ConvexShape : public VertexArray
{
public:

    ConvexShape(u32 vertices_dimension, Buffer::Usage usage = Buffer::Usage::Static);

    virtual ~ConvexShape();

protected:

    Buffer _buffer;
    PrimitiveType _primitive_type;
    u32 _vertices_dimension, _vertices_count;

};

UNIFIED_END_NAMESPACE

#endif
