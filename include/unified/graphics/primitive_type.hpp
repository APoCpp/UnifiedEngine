#ifndef _UNIFIED_GRAPHICS_PRIMITIVE_TYPE_HPP
#define _UNIFIED_GRAPHICS_PRIMITIVE_TYPE_HPP

# include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE

enum class PrimitiveType
{
    Points,
    Lines,
    LineLoop,
    LineStrip,
    Triangles,
    TriangleStrip,
    TriangleFan,
    Quads,
    QuadStrip,
    Polygon
};

UNIFIED_END_NAMESPACE

#endif
