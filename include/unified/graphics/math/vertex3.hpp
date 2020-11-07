#ifndef UNIFIED_GRAPHICS_MATH_VERTEX3_HPP
#define UNIFIED_GRAPHICS_MATH_VERTEX3_HPP

#include <unified/graphics/math/vertex_fwd.hpp>

#include <unified/core/math/point3.hpp>
#include <unified/core/color.hpp>

UNIFIED_BEGIN_NAMESPACE

template <class _type>
class Vertex<_type, 3> : public Point<_type, 3>
{
public:

    _UNIFIED_CONSTEXPR Vertex() _UNIFIED_NOEXCEPT : Point<_type, 3>(), color() { }

    _UNIFIED_CONSTEXPR Vertex(Point<_type, 3> const &point) _UNIFIED_NOEXCEPT : color() {
        this->x = point.x, this->y = point.y, this->z = point.z;
    }

    _UNIFIED_CONSTEXPR operator Point<_type, 3>() const {
        return Point<_type, 3>(this->x, this->y, this->z);
    }

    Color color;

};

typedef Vertex<unsigned, 3> Vertex3u;
typedef Vertex<int,      3> Vertex3i;
typedef Vertex<float,    3> Vertex3f;
typedef Vertex<double,   3> Vertex3d;

UNIFIED_END_NAMESPACE

#endif
