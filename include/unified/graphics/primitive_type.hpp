#ifndef UNIFIED_GRAPHICS_PRIMITIVE_TYPE_HPP
#define UNIFIED_GRAPHICS_PRIMITIVE_TYPE_HPP

#include <unified/defines.hpp>

UNIFIED_BEGIN_NAMESPACE

enum class PrimitiveType
{
    Points,
    Lines,
    LineStrip,
    Triangles,
    TriangleStrip,
    TriangleFan,
    Quads
};

UNIFIED_END_NAMESPACE

#endif
